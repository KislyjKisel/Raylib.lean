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

extern_lib «raylib-lean» (pkg : Package) := do
  let name := nameToStaticLib "raylib-lean"
  let raylib_inc := (← IO.Process.output {
    cmd := "pkg-config"
    args := #["--cflags", "raylib"]
    cwd := pkg.dir
  }).stdout
  let mut flags := #[raylib_inc, "-I", (← getLeanIncludeDir).toString, "-fPIC"]
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
