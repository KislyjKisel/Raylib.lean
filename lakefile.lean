import Lake
open Lake DSL

require Pod from git "https://github.com/KislyjKisel/lean-pod" @ "main"

package raylib {
  srcDir := "src/lean"
}

lean_lib Raylib
lean_lib Raymath {
  precompileModules := true
}

inductive RaylibSrc
  | System
  | Submodule
  | Custom
  | Unknown (name : String)

def raylibSrc : RaylibSrc := match get_config? raylib with
  | none => .Submodule
  | some "system" => .System
  | some "submodule" => .Submodule
  | some "custom" => .Custom
  | some name => .Unknown name

@[default_target]
lean_exe test {
  root := `Main
  moreLinkArgs := (
    match raylibSrc with
      | .System => #["-L/usr/local/lib", "-lraylib"]
      | .Submodule => #["-Lraylib/build/raylib", "-lraylib"]
      | .Custom => #[]
      | .Unknown _ => #[]
  ).append $ Array.mk $ ((get_config? lflags).getD "").splitOn
}

def buildBindingsO (pkg : Package) (flags : Array String) (stem : String) : IndexBuildM (BuildJob FilePath) := do
  let oFile := pkg.irDir / "native" / (stem ++ ".o")
  let srcJob ← inputFile <| pkg.dir / "src" / "native" / (stem ++ ".c")
  buildO (stem ++ ".c") oFile srcJob flags ((get_config? cc).getD "cc")

def tryRunProcess {m} [Monad m] [MonadError m] [MonadLiftT IO m] (sa : IO.Process.SpawnArgs) : m String := do
  let output ← IO.Process.output sa
  if output.exitCode ≠ 0 then
    error s!"'{sa.cmd}' returned {output.exitCode}: {output.stderr}"
  else
    return output.stdout

def buildRaylibSubmodule (pkgDir : FilePath) (printCmdOutput : Bool) : IO Unit := do
  let gitOutput ← tryRunProcess {
    cmd := "git"
    args := #["submodule", "update", "--init", "--force", "--recursive"]
    cwd := pkgDir
  }
  if printCmdOutput then IO.println gitOutput

  let mkdirOutput ← tryRunProcess {
    cmd := "mkdir"
    args := #["-p", "raylib/build"]
    cwd := pkgDir
  }
  if printCmdOutput then IO.println mkdirOutput

  let cmakeOutput ← tryRunProcess {
    cmd := "cmake"
    args := #["-DCUSTOMIZE_BUILD=ON", "-DBUILD_EXAMPLES=OFF", "-DWITH_PIC=ON", ".."]
    cwd := pkgDir / "raylib" / "build"
  }
  if printCmdOutput then IO.println cmakeOutput

  let cmakeBuildOutput ← tryRunProcess {
    cmd := "cmake"
    args := #["--build", "."]
    cwd := pkgDir / "raylib" / "build"
  }
  if printCmdOutput then IO.println cmakeBuildOutput

def bindingsCFlags (pkg : Package) : IndexBuildM (Array String) := do
  let mut flags :=
    #["-I", (← getLeanIncludeDir).toString, "-fPIC"].append $
      Array.mk $ ((get_config? cflags).getD "").splitOn.filter $ not ∘ String.isEmpty

  match pkg.deps.find? λ dep ↦ dep.name == `pod with
    | none => error "Missing dependency 'Pod'"
    | some pod =>
      flags := flags ++ #[
        "-I",
        (pod.dir / "src" / "native" / "include").toString
      ]

  let printCmdOutput := (get_config? cmdout).isSome

  match raylibSrc with
    | .System =>
      flags := flags.push $ ← tryRunProcess {
        cmd := "pkg-config"
        args := #["--cflags", "raylib"]
      }

    | .Submodule => do
      buildRaylibSubmodule pkg.dir printCmdOutput
      flags := flags.append #[
        "-I",
        (pkg.dir / "raylib" / "build" / "raylib" / "include").toString
      ]

    | .Custom => pure ()

    | .Unknown name =>
      error s!"Unknown 'raylib' source: {name}"

  pure flags

extern_lib «raymath-lean» (pkg : Package) := do
  let name := nameToStaticLib "raymath-lean"
  let flags ← bindingsCFlags pkg
  let bindingsOFile ← buildBindingsO pkg flags "raymath"
  buildStaticLib (pkg.libDir / name) #[
    bindingsOFile
  ]

extern_lib «raylib-lean» (pkg : Package) := do
  let name := nameToStaticLib "raylib-lean"
  let flags ← bindingsCFlags pkg
  let bindingsEnumerationsOFile ← buildBindingsO pkg flags "enumerations"
  let bindingsStructuresOFile ← buildBindingsO pkg flags "structures"
  let bindingsFunctionsOFile ← buildBindingsO pkg flags "functions"
  buildStaticLib (pkg.libDir / name) #[
    bindingsEnumerationsOFile,
    bindingsStructuresOFile,
    bindingsFunctionsOFile
  ]

script buildRL do
  buildRaylibSubmodule ⟨"."⟩ true
  return 0
