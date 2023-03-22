import Lake
open Lake DSL

package raylib {
  srcDir := "src/lean"
}

lean_lib Raylib

inductive RaylibSrc
  | System
  | Submodule
  | Custom
  | Unknown (name : String)

def raylibSrc : RaylibSrc := match get_config? raylib with
  | none => .System
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

def tryRunProcess (sa : IO.Process.SpawnArgs) : IndexBuildM String := do
  let output ← IO.Process.output sa
  if output.exitCode ≠ 0 then
    error s!"'{sa.cmd}' returned {output.exitCode}: {output.stderr}"
  else
    return output.stdout

def tryRunProcess_ (sa : IO.Process.SpawnArgs) :=
  Functor.discard $ tryRunProcess sa

extern_lib «raylib-lean» (pkg : Package) := do
  let name := nameToStaticLib "raylib-lean"
  let mut flags :=
    #["-I", (← getLeanIncludeDir).toString, "-fPIC"].append $
      Array.mk $ ((get_config? cflags).getD "").splitOn.filter $ not ∘ String.isEmpty

  match raylibSrc with
    | .System =>
      flags := flags.push $ ← tryRunProcess {
        cmd := "pkg-config"
        args := #["--cflags", "raylib"]
      }

    | .Submodule => do
      IO.println $ ← tryRunProcess {
        cmd := "git"
        args := #["submodule", "update", "--init", "--force", "--recursive"]
        cwd := pkg.dir
      }
      IO.println $ ← tryRunProcess {
        cmd := "mkdir"
        args := #["-p", "raylib/build"]
        cwd := pkg.dir
      }
      IO.println $ ← tryRunProcess {
        cmd := "cmake"
        args := #["-DCUSTOMIZE_BUILD=ON", "-DBUILD_EXAMPLES=OFF", "-DWITH_PIC=ON", ".."]
        cwd := pkg.dir / "raylib" / "build"
      }
      IO.println $ ← tryRunProcess {
        cmd := "cmake"
        args := #["--build", "."]
        cwd := pkg.dir / "raylib" / "build"
      }
      flags := flags.append #[
        "-I",
        (pkg.dir / "raylib" / "build" / "raylib" / "include").toString
      ]

    | .Custom => pure ()

    | .Unknown name =>
      error s!"Unknown 'raylib' source: {name}"

  if (get_config? unsafe_opts).isSome then {
    flags := flags.push "-DRAYLIB_LEAN_UNSAFE_OPTS"
  }

  let bindingsEnumerationsOFile ← buildBindingsO pkg flags "enumerations"
  let bindingsStructuresOFile ← buildBindingsO pkg flags "structures"
  let bindingsFunctionsOFile ← buildBindingsO pkg flags "functions"
  buildStaticLib (pkg.libDir / name) #[
    bindingsEnumerationsOFile,
    bindingsStructuresOFile,
    bindingsFunctionsOFile
  ]
