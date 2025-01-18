import Lake
open Lake DSL

def splitArgStr (s : String) : Array String :=
  Array.mk $ s.splitOn.filter $ not ∘ String.isEmpty

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

def optionFork := (get_config? fork).isSome
def submoduleDir := cond optionFork "raylibFork" "raylib"

def podConfig : Lean.NameMap String := Id.run $ do
  let mut cfg := NameMap.empty
  if let some cc := get_config? cc then
    cfg := cfg.insert `cc cc
  if let some alloc := get_config? alloc then
    cfg := cfg.insert `alloc alloc
  cfg

require pod from git "https://github.com/KislyjKisel/lean-pod" @ "450d61b" with podConfig

def packagesDir := defaultPackagesDir

package raylib {
  packagesDir := packagesDir
  leanOptions := #[⟨`autoImplicit, false⟩]
}

@[default_target]
lean_lib Raylib {
  srcDir := "src/lean"
}

lean_lib Raymath {
  srcDir := "src/lean"
  precompileModules := true
}

lean_lib Raygui {
  srcDir := "src/lean"
}

def examplesLinkArgs :=
  (splitArgStr <| (get_config? lflags).getD "").append <|
    match raylibSrc with
      | .System => #["-L/usr/local/lib64", "-lraylib"]
      | .Submodule => #[s!"-L{submoduleDir}/build/raylib", "-lraylib"]
      | .Custom => #[]
      | .Unknown _ => #[]

lean_exe examples.Minimal { moreLinkArgs := examplesLinkArgs }
lean_exe examples.Gui { moreLinkArgs := examplesLinkArgs }
lean_exe examples.Audio { moreLinkArgs := examplesLinkArgs }
lean_exe examples.VideoMode { moreLinkArgs := examplesLinkArgs }

def tryRunProcess {m} [Monad m] [MonadError m] [MonadLiftT IO m] (sa : IO.Process.SpawnArgs) : m String := do
  let output ← IO.Process.output sa
  if output.exitCode ≠ 0 then
    error s!"'{sa.cmd}' returned {output.exitCode}: {output.stderr}"
  else
    return output.stdout

def updateRayguiSubmodule {m} [Monad m] [MonadError m] [MonadLiftT IO m] (printCmdOutput : Bool) : m Unit := do
  let gitCmd := (get_config? git).getD "git"
  if gitCmd != "" then
    let gitOutput ← tryRunProcess {
      cmd := gitCmd
      args := #["submodule", "update", "--init", "--force", "--recursive", "raygui"]
      cwd := __dir__
    }
    if printCmdOutput then IO.println gitOutput

def buildRaylibSubmodule {m} [Monad m] [MonadError m] [MonadLiftT IO m] (printCmdOutput : Bool) : m Unit := do
  let gitCmd := (get_config? git).getD "git"
  if gitCmd != "" then
    let gitOutput ← tryRunProcess {
      cmd := gitCmd
      args := #["submodule", "update", "--init", "--force", "--recursive", submoduleDir]
      cwd := __dir__
    }
    if printCmdOutput then IO.println gitOutput

  IO.FS.createDirAll s!"{__dir__}/{submoduleDir}/build"

  let mut cmakeBuildArgs : Array String := #[
    "-DCUSTOMIZE_BUILD=ON",
    "-DWITH_PIC=ON",
    "-DBUILD_EXAMPLES=OFF"
  ]
  if let some extGlfw := get_config? externalGlfw then
    let values := #["OFF", "ON", "IF_POSSIBLE"]
    if values.contains extGlfw
      then cmakeBuildArgs := cmakeBuildArgs.push s!"-DUSE_EXTERNAL_GLFW={extGlfw}"
      else error s!"Invalid config option value: externalGlfw={extGlfw}; expected one of {values}"
  if let some platform := get_config? platform then
    let platforms := #["Desktop", "Web", "Android", "Rapberry Pi"]
    if platforms.contains platform
      then cmakeBuildArgs := cmakeBuildArgs.push s!"\"-DPLATFORM={platform}\""
      else error s!"Invalid config option value: platform={platform}; expected one of {platforms}"
  if let some oglVer := get_config? opengl then
    let mut oglVers := #["OFF", "4.3", "3.3", "2.1", "1.1", "ES 2.0", "ES 3.0"]
    if optionFork then
      oglVers := oglVers.push "4.6"
    if oglVers.contains oglVer
      then cmakeBuildArgs := cmakeBuildArgs.push s!"\"-DOPENGL_VERSION={oglVer}\""
      else error s!"Invalid config option value: opengl={oglVer}; expected one of {oglVers}"
  let binCfgToOpt (opts : Array String) (cfgKey : String) (optPref : String) : Option String → IO (Array String)
  | some cfg => if cfg == "ON" || cfg == "OFF"
      then pure $ opts.push $ optPref ++ cfg
      else error s!"Invalid config option value: {cfgKey}={cfg}; expected ON or OFF"
  | none => pure opts
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "wayland" "-DGLFW_BUILD_WAYLAND=" (get_config? wayland)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "macosFatlib" "-DMACOS_FATLIB=" (get_config? macosFatlib)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "audio" "-DUSE_AUDIO=" (get_config? audio)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "busyWaitLoop" "-DSUPPORT_BUSY_WAIT_LOOP=" (get_config? busyWaitLoop)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "cameraSystem" "-DSUPPORT_CAMERA_SYSTEM=" (get_config? cameraSystem)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "defaultFont" "-DSUPPORT_DEFAULT_FONT=" (get_config? defaultFont)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "screenCapture" "-DSUPPORT_SCREEN_CAPTURE=" (get_config? screenCapture)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "gifRecording" "-DSUPPORT_GIF_RECORDING=" (get_config? gifRecording)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "gestures" "-DSUPPORT_GESTURES_SYSTEM=" (get_config? gestures)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "mouseGestures" "-DSUPPORT_MOUSE_GESTURES=" (get_config? mouseGestures)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "vrSimulator" "-DSUPPORT_VR_SIMULATOR=" (get_config? vrSimulator)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "distortionShader" "-DSUPPORT_DISTORTION_SHADER=" (get_config? distortionShader)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "fontTexture" "-DSUPPORT_FONT_TEXTURE=" (get_config? fontTexture)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "quadsDrawMode" "-DSUPPORT_QUAD_DRAW_MODE=" (get_config? quadsDrawMode)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "imageGen" "-DSUPPORT_IMAGE_GENERATION=" (get_config? imageGen)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "meshGen" "-DSUPPORT_MESH_GENERATION=" (get_config? meshGen)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "imageManip" "-DSUPPORT_IMAGE_MANIPULATION=" (get_config? imageManip)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "tracelog" "-DSUPPORT_TRACELOG=" (get_config? tracelog)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "savePng" "-DSUPPORT_SAVE_PNG=" (get_config? savePng)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "saveBmp" "-DSUPPORT_SAVE_BMP=" (get_config? saveBmp)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatPng" "-DSUPPORT_FILEFORMAT_PNG=" (get_config? formatPng)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatGif" "-DSUPPORT_FILEFORMAT_GIF=" (get_config? formatGif)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatQoi" "-DSUPPORT_FILEFORMAT_QOI=" (get_config? formatQoi)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatDds" "-DSUPPORT_FILEFORMAT_DDS=" (get_config? formatDds)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatBmp" "-DSUPPORT_FILEFORMAT_BMP=" (get_config? formatBmp)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatTga" "-DSUPPORT_FILEFORMAT_TGA=" (get_config? formatTga)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatJpg" "-DSUPPORT_FILEFORMAT_JPG=" (get_config? formatJpg)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatPsd" "-DSUPPORT_FILEFORMAT_PSD=" (get_config? formatPsd)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatHdr" "-DSUPPORT_FILEFORMAT_HDR=" (get_config? formatHdr)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatPic" "-DSUPPORT_FILEFORMAT_PIC=" (get_config? formatPic)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatKtx" "-DSUPPORT_FILEFORMAT_KTX=" (get_config? formatKtx)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatAstc" "-DSUPPORT_FILEFORMAT_ASTC=" (get_config? formatAstc)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatPkm" "-DSUPPORT_FILEFORMAT_PKM=" (get_config? formatPkm)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatPvr" "-DSUPPORT_FILEFORMAT_PVR=" (get_config? formatPvr)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatSvg" "-DSUPPORT_FILEFORMAT_SVG=" (get_config? formatSvg)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatObj" "-DSUPPORT_FILEFORMAT_OBJ=" (get_config? formatObj)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatMtl" "-DSUPPORT_FILEFORMAT_MTL=" (get_config? formatMtl)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatIqm" "-DSUPPORT_FILEFORMAT_IQM=" (get_config? formatIqm)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatGltf" "-DSUPPORT_FILEFORMAT_GLTF=" (get_config? formatGltf)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatVox" "-DSUPPORT_FILEFORMAT_VOX=" (get_config? formatVox)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatM3d" "-DSUPPORT_FILEFORMAT_M3D=" (get_config? formatM3d)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatWav" "-DSUPPORT_FILEFORMAT_WAV=" (get_config? formatWav)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatOgg" "-DSUPPORT_FILEFORMAT_OGG=" (get_config? formatOgg)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatXm" "-DSUPPORT_FILEFORMAT_XM=" (get_config? formatXm)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatMod" "-DSUPPORT_FILEFORMAT_MOD=" (get_config? formatMod)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatFlac" "-DSUPPORT_FILEFORMAT_FLAC=" (get_config? formatFlac)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatFnt" "-DSUPPORT_FILEFORMAT_FNT=" (get_config? formatFnt)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatTtf" "-DSUPPORT_FILEFORMAT_TTF=" (get_config? formatTtf)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "formatBdf" "-DSUPPORT_FILEFORMAT_BDF=" (get_config? formatBdf)
  cmakeBuildArgs := cmakeBuildArgs.push ".."

  let cmakeCmd := (get_config? cmake).getD "cmake"
  if cmakeCmd != "" then
    let cmakeOutput ← tryRunProcess {
      cmd := cmakeCmd
      args := cmakeBuildArgs
      cwd := __dir__ / submoduleDir / "build"
    }
    if printCmdOutput then IO.println cmakeOutput
    let cmakeBuildOutput ← tryRunProcess {
      cmd := cmakeCmd
      args := #["--build", "."]
      cwd := __dir__ / submoduleDir / "build"
    }
    if printCmdOutput then IO.println cmakeBuildOutput

def bindingsCFlags (pkg : NPackage _package.name) : FetchM (Array String × Array String) := do
  let mut weakArgs := #["-I", (← getLeanIncludeDir).toString]
  let mut traceArgs := #["-fPIC"].append $ splitArgStr $ (get_config? cflags).getD ""

  match ← findPackage? `pod with
    | none => error "Missing dependency 'Pod'"
    | some pod =>
      weakArgs := weakArgs ++ #[
        "-I",
        (pod.dir / "src" / "native" / "include").toString
      ]

  let printCmdOutput := (get_config? cmdout).isSome

  match raylibSrc with
    | .System =>
      let pkgConfigOutput ← tryRunProcess {
        cmd := "pkg-config"
        args := #["--cflags", "raylib", "glfw3"]
      }
      weakArgs := weakArgs.append $ splitArgStr $ pkgConfigOutput.replace "\n" " "

    | .Submodule => do
      buildRaylibSubmodule printCmdOutput
      weakArgs := weakArgs.append #[
        "-I",
        (pkg.dir / submoduleDir / "build" / "raylib" / "include").toString,
        "-I",
        (pkg.dir / submoduleDir / "src" / "external" / "glfw" / "include").toString
      ]

    | .Custom => pure ()

    | .Unknown name =>
      error s!"Unknown 'raylib' source: {name}"

  if (get_config? raygui).isSome then
    updateRayguiSubmodule printCmdOutput
    weakArgs := weakArgs.append #[
      "-I",
      (pkg.dir / "raygui" / "src").toString
    ]

  if optionFork then
    traceArgs := traceArgs.push "-DLEAN_RAYLIB_FORK"

  match get_config? alloc with
  | .none | .some "lean" => pure ()
  | .some "native" => traceArgs := traceArgs.push "-DLEAN_RAYLIB_ALLOC_NATIVE"
  | .some _ => error "Unknown `alloc` option value"

  if (get_config? cc).isNone then
    weakArgs := weakArgs ++ #["-I", ((← getLeanIncludeDir) / "clang").toString]

  pure (weakArgs, traceArgs)

extern_lib «raylib-lean» pkg := do
  let name := nameToStaticLib "raylib-lean"
  let (weakArgs, traceArgs) ← bindingsCFlags pkg
  let mut bindingsSources := #[
    "structures", "functions", "callbacks",
    "raymath", "glfw"
  ]
  if (get_config? raygui).isSome then
    bindingsSources := bindingsSources.push "raygui"
  let bindingsHeaders := #[
    "include/raylib_lean", "include/raymath_lean"
  ]
  let nativeSrcDir := pkg.dir / "src" / "native"
  let objectFileDir := pkg.irDir / "native"
  let headerFile (h : String) : System.FilePath := nativeSrcDir / (h ++ ".h")
  let extraTrace ← mixTraceArray <$> (bindingsHeaders.mapM $ computeTrace ∘ headerFile)
  buildStaticLib (pkg.nativeLibDir / name)
    (← bindingsSources.mapM λ stem ↦ do
      buildO
        (objectFileDir / (stem ++ ".o"))
        (← inputTextFile $ nativeSrcDir / (stem ++ ".c"))
        weakArgs traceArgs
        ((get_config? cc).getD (← getLeanCc).toString)
        (pure extraTrace)
    )

script buildSubmodule do
  buildRaylibSubmodule true
  return 0

script cleanCmakeCache do
  let path := s!"{__dir__}/{submoduleDir}/build"
  if ← System.FilePath.pathExists path then
    IO.println s!"Removing: {path}"
    IO.FS.removeDirAll path
  return 0

script options do
  IO.println s!"raylib={get_config? raylib}"
  IO.println s!"raygui? {(get_config? raygui).isSome}"
  IO.println s!"cc={get_config? cc}"
  IO.println s!"cflags={get_config? cflags}"
  IO.println s!"lflags={get_config? lflags}"
  IO.println s!"fork? {optionFork}"
  IO.println s!"alloc={get_config? alloc}"
  IO.println s!"git={get_config? git}"
  IO.println s!"cmake={get_config? cmake}"
  return 0
