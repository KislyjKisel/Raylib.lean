import Lake
open Lake DSL

def libffiConfig : NameMap String := Id.run $ do
  let mut cfg := NameMap.empty
  if (get_config? libffi).isNone then
    cfg := cfg.insert `disable ""
  cfg

def podConfig : NameMap String := Id.run $ do
  let mut cfg := NameMap.empty
  if let some cc := get_config? cc then
    cfg := cfg.insert `cc cc
  if let some alloc := get_config? alloc then
    cfg := cfg.insert `alloc alloc
  cfg

require libffi from git "https://github.com/KislyjKisel/libffi-lake" @ "master" with libffiConfig
require pod from git "https://github.com/KislyjKisel/lean-pod" @ "main" with podConfig

def packagesDir := defaultPackagesDir

package raylib {
  srcDir := "src/lean"
  packagesDir := packagesDir
  moreLeanArgs := #["-DautoImplicit=false"] ++
    if (get_config? libffi).isSome
      then #[s!"--load-dynlib=./{packagesDir}/Libffi/lib/libffi.so"] -- why not automatic?
      else #[]
  moreServerArgs := #["-DautoImplicit=false"]
}

lean_lib Raylib
lean_lib Raymath {
  precompileModules := true
}
lean_lib Raygui

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

def splitArgStr (s : String) : Array String := Array.mk $ s.splitOn.filter $ not ∘ String.isEmpty

@[default_target]
lean_exe test {
  root := `Main
  moreLinkArgs := Id.run $ do
    let mut args := splitArgStr $ (get_config? lflags).getD ""
    args := args.append $ match raylibSrc with
      | .System => #["-L/usr/local/lib", "-lraylib"]
      | .Submodule => #[s!"-L{__dir__}/raylib/build/raylib", "-lraylib"]
      | .Custom => #[]
      | .Unknown _ => #[]
    pure args
}

def buildBindingsO (pkg : Package) (weakArgs traceArgs : Array String) (stem : String) : IndexBuildM (BuildJob FilePath) := do
  let oFile := pkg.irDir / "native" / (stem ++ ".o")
  let srcJob ← inputFile <| pkg.dir / "src" / "native" / (stem ++ ".c")
  buildO (stem ++ ".c") oFile srcJob weakArgs traceArgs ((get_config? cc).getD (← getLeanCc).toString)

def tryRunProcess {m} [Monad m] [MonadError m] [MonadLiftT IO m] (sa : IO.Process.SpawnArgs) : m String := do
  let output ← IO.Process.output sa
  if output.exitCode ≠ 0 then
    error s!"'{sa.cmd}' returned {output.exitCode}: {output.stderr}"
  else
    return output.stdout

def buildRaylibSubmodule (printCmdOutput : Bool) : IO Unit := do
  let gitOutput ← tryRunProcess {
    cmd := "git"
    args := #["submodule", "update", "--init", "--force", "--recursive"]
    cwd := __dir__
  }
  if printCmdOutput then IO.println gitOutput

  let mkdirOutput ← tryRunProcess {
    cmd := "mkdir"
    args := #["-p", "raylib/build"]
    cwd := __dir__
  }
  if printCmdOutput then IO.println mkdirOutput

  let cmakeOutput ← tryRunProcess {
    cmd := "cmake"
    args := #["-DCUSTOMIZE_BUILD=ON", "-DBUILD_EXAMPLES=OFF", "-DWITH_PIC=ON", ".."]
    cwd := __dir__ / "raylib" / "build"
  }
  if printCmdOutput then IO.println cmakeOutput

  let cmakeBuildOutput ← tryRunProcess {
    cmd := "cmake"
    args := #["--build", "."]
    cwd := __dir__ / "raylib" / "build"
  }
  if printCmdOutput then IO.println cmakeBuildOutput

def bindingsCFlags (pkg : NPackage _package.name) : IndexBuildM (Array String × Array String) := do
  let mut weakArgs := #["-I", (← getLeanIncludeDir).toString]
  let mut traceArgs := #["-fPIC"].append $ splitArgStr $ (get_config? cflags).getD ""

  match pkg.deps.find? λ dep ↦ dep.name == `pod with
    | none => error "Missing dependency 'Pod'"
    | some pod =>
      weakArgs := weakArgs ++ #[
        "-I",
        (pod.dir / "src" / "native" / "include").toString
      ]

  let printCmdOutput := (get_config? cmdout).isSome

  match raylibSrc with
    | .System =>
      traceArgs := traceArgs.push $ ← tryRunProcess {
        cmd := "pkg-config"
        args := #["--cflags", "raylib"]
      }

    | .Submodule => do
      buildRaylibSubmodule printCmdOutput
      traceArgs := traceArgs.append #[
        "-I",
        (pkg.dir / "raylib" / "build" / "raylib" / "include").toString
      ]

    | .Custom => pure ()

    | .Unknown name =>
      error s!"Unknown 'raylib' source: {name}"

  if (get_config? libffi).isSome then
    traceArgs := traceArgs.push "-DLEAN_RAYLIB_LIBFFI"
    match pkg.deps.find? λ dep ↦ dep.name == `libffi with
    | none => error "Missing dependency 'Libffi'"
    | some dep =>
      weakArgs := weakArgs ++ #[
        "-I",
        (dep.dir / "include").toString
      ]

  match get_config? alloc with
  | .none | .some "lean" => pure ()
  | .some "native" => traceArgs := traceArgs.push "-DLEAN_RAYLIB_ALLOC_NATIVE"
  | .some _ => error "Unknown `alloc` option value"

  if (get_config? cc).isNone then
    weakArgs := weakArgs ++ #["-I", ((← getLeanIncludeDir) / "clang").toString]

  pure (weakArgs, traceArgs)

extern_lib «raylib-lean» (pkg : NPackage _package.name) := do
  let name := nameToStaticLib "raylib-lean"
  let (weakArgs, traceArgs) ← bindingsCFlags pkg
  let bindingsEnumerationsOFile ← buildBindingsO pkg weakArgs traceArgs "enumerations"
  let bindingsStructuresOFile ← buildBindingsO pkg weakArgs traceArgs "structures"
  let bindingsFunctionsOFile ← buildBindingsO pkg weakArgs traceArgs "functions"
  let bindingsCallbacksOFile ← buildBindingsO pkg weakArgs traceArgs "callbacks"
  buildStaticLib (pkg.nativeLibDir / name) #[
    bindingsEnumerationsOFile,
    bindingsStructuresOFile,
    bindingsFunctionsOFile,
    bindingsCallbacksOFile
  ]

extern_lib «raymath-lean» (pkg : NPackage _package.name) := do
  let name := nameToStaticLib "raymath-lean"
  let (weakArgs, traceArgs) ← bindingsCFlags pkg
  let bindingsOFile ← buildBindingsO pkg weakArgs traceArgs "raymath"
  buildStaticLib (pkg.nativeLibDir / name) #[
    bindingsOFile
  ]

extern_lib «raygui-lean» (pkg : NPackage _package.name) := do
  let name := nameToStaticLib "raygui-lean"
  let (weakArgs, traceArgs) ← bindingsCFlags pkg
  let weakArgs := weakArgs.append #[
    "-I",
    (pkg.dir / "raygui" / "src").toString
  ]
  let bindingsOFile ← buildBindingsO pkg weakArgs traceArgs "raygui"
  buildStaticLib (pkg.nativeLibDir / name) #[
    bindingsOFile
  ]

script buildRL do
  buildRaylibSubmodule true
  return 0
