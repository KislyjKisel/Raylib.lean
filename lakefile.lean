import Lake
open Lake DSL

/- CONFIGURATION
* unsafe_opts("") -- enable some optimizations that may be erroneous.
-- TODO: Type assertions (ex. lean_obj_arg tag check) for ffi api testing
-/

package raylib {
  srcDir := "src/lean"
}

lean_lib Raylib

@[default_target]
lean_exe test {
  root := `Main
  moreLinkArgs := #["-L/usr/local/lib", "-lraylib"]
}

def buildBindingsO (pkg : Package) (flags : Array String) (stem : String) : IndexBuildM (BuildJob FilePath) := do
  let oFile := pkg.buildDir / "native" / (stem ++ ".o")
  let srcJob ← inputFile <| pkg.dir / "src" / "native" / (stem ++ ".c")
  buildO (stem ++ ".c") oFile srcJob flags "cc"

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
  let mut flags := #["-I", (← getLeanIncludeDir).toString, "-fPIC"]

  let raylib_src := (get_config? raylib).getD "system"
  match raylib_src with
    | "system" =>
      flags := flags.push $ ← tryRunProcess {
        cmd := "pkg-config"
        args := #["--cflags", "raylib"]
      }

    | "submodule" => do
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
        args := #["-DCUSTOMIZE_BUILD=ON", "-DBUILD_EXAMPLES=OFF", ".."]
        cwd := pkg.dir / "raylib" / "build"
      }
      IO.println $ ← tryRunProcess {
        cmd := "cmake"
        args := #["--build", "."]
        cwd := pkg.dir / "raylib" / "build"
      }
      flags := flags.append #[
        "-I",
        (pkg.dir / "raylib" / "build" / "raylib" / "include").toString,
        "-L",
        (pkg.dir / "raylib" / "build" / "raylib").toString,
        "-lraylib"
      ]

    | unknown =>
      error s!"Unknown 'raylib' source: {unknown}"

  if get_config? unsafe_opts = some "" then {
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
