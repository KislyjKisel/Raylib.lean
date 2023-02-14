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

def buildBindingsO (pkg : Package) (stem : String) : IndexBuildM (BuildJob FilePath) := do
  let oFile := pkg.buildDir / "native" / (stem ++ ".o")
  let srcJob ← inputFile <| pkg.dir / "src" / "native" / (stem ++ ".c")
  let mut flags := #["-I/usr/local/include", "-I", (← getLeanIncludeDir).toString, "-fPIC"]
  if get_config? unsafe_opts = some "" then {
    flags := flags.push "-DRAYLIB_LEAN_UNSAFE_OPTS"
  }
  buildO (stem ++ ".c") oFile srcJob flags "cc"

target bindingsUtilO (pkg : Package) : FilePath := do
  buildBindingsO pkg "util"
target bindingsEnumerationsO (pkg : Package) : FilePath := do
  buildBindingsO pkg "enumerations"
target bindingsStructuresO (pkg : Package) : FilePath := do
  buildBindingsO pkg "structures"
target bindingsFunctionsO (pkg : Package) : FilePath := do
  buildBindingsO pkg "functions"

extern_lib «raylib-lean» (pkg : Package) := do
  let name := nameToStaticLib "raylib-lean"
  let bindingsUtilOFile ← fetch <| pkg.target ``bindingsUtilO
  let bindingsEnumerationsOFile ← fetch <| pkg.target ``bindingsEnumerationsO
  let bindingsStructuresOFile ← fetch <| pkg.target ``bindingsStructuresO
  let bindingsFunctionsOFile ← fetch <| pkg.target ``bindingsFunctionsO
  buildStaticLib (pkg.libDir / name) #[
    bindingsUtilOFile,
    bindingsEnumerationsOFile,
    bindingsStructuresOFile,
    bindingsFunctionsOFile
  ]
