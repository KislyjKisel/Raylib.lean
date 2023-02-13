import Lake
open Lake DSL

package raylib {
  srcDir := "src/lean"
}

lean_lib Raylib

@[default_target]
lean_exe test {
  root := `Main
  moreLinkArgs := #["-I/usr/local/include", "-L/usr/local/lib", "-lraylib"]
}

def buildBindingsO (pkg : Package) (stem : String) : IndexBuildM (BuildJob FilePath) := do
  let oFile := pkg.buildDir / "native" / (stem ++ ".o")
  let srcJob ← inputFile <| pkg.dir / "src" / "native" / (stem ++ ".c")
  let flags := #["-I", (← getLeanIncludeDir).toString, "-fPIC"]
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
