import Lake
open Lake DSL

set_option autoImplicit false

def splitArgStr (s : String) : Array String :=
  Id.run <| do
    let mut quoted := false
    let mut escaped := false
    let mut cur := ""
    let mut acc := #[]
    for c in s.toList do
      match c with
      | ' ' =>
        if quoted || escaped
          then
            cur := cur.push ' '
            escaped := false
          else
            if cur.isEmpty.not then
              acc := acc.push cur
              cur := ""
      | '\\' =>
        if escaped
          then
            cur := cur.push '\\'
            escaped := false
          else
            escaped := true
      | '\"' =>
        if escaped
          then
            cur := cur.push '\"'
            escaped := false
          else
            quoted := quoted.not
            if cur.isEmpty.not then
              acc := acc.push cur
              cur := ""
      | 'n' =>
        if escaped
          then
            cur := cur.push '\n'
            escaped := false
          else
            cur := cur.push 'n'
      | c =>
        escaped := false
        cur := cur.push c
    if cur.isEmpty.not then
      acc := acc.push cur
    return acc

inductive FilePathPartPatternPart where
| literal (s : Substring)
| wildcard
deriving BEq, Inhabited, Repr

abbrev FilePathPartPattern := Array FilePathPartPatternPart

def FilePathPartPattern.getLiteral (pat : FilePathPartPattern) : Option String :=
  flip pat.foldlM "" λ acc x ↦
    match x with
    | .wildcard => none
    | .literal s => some (s.foldl String.push acc)

def FilePathPartPattern.matches (pat : FilePathPartPattern) (s : String) : Bool := Id.run <| do
  let mut leads : Array (Subarray FilePathPartPatternPart × Substring) := #[(pat.toSubarray, s.toSubstring)]
  while h: leads.size > 0 do
    let (pat, s) := leads[0]
    leads := leads.pop
    if h: pat.size > 0
      then
        match pat[0] with
        | .literal s' =>
          match s.dropPrefix? s' with
          | some sSuffix =>
            leads := leads.push (pat.drop 1, sSuffix)
          | none =>
            return false
        | .wildcard =>
          if pat.size < 2 then
            -- ends with wildcard
            return true
          let nextPart := pat[1]!
          match nextPart with
          | .wildcard => return false -- can't contain two consecutive wildcards
          | .literal nextPart =>
            let restParts := pat.drop 2
            let mut sSuffix := s
            repeat do
              match sSuffix.dropPrefix? nextPart with
              | none =>
                if sSuffix.isEmpty then break
              | some sSuffix' =>
                leads := leads.push (restParts, sSuffix')
              sSuffix := sSuffix.drop 1
      else
        if s.isEmpty && pat.size == 0 then
          return true
  return false

def FilePathPartPattern.validate (pat : FilePathPartPattern) : Except String FilePathPartPattern := do
  for i in [0:pat.size - 1] do
    if pat[i]! == .wildcard && pat[i + 1]! == .wildcard then
      throw s!"File pattern has invalid part pattern: wildcards can't be consecutive {repr pat}"
  return pat

inductive FilePathPatternPart where
| pattern (p : FilePathPartPattern)
| doubleWildcard
deriving BEq, Repr, Inhabited

structure FilePathPattern where
  «package» : Option String
  parts : Array FilePathPatternPart
deriving Repr

def FilePathPattern.parse (pattern : String) : Except String FilePathPattern := do
  let isSep := λ c ↦ c == '/' || c == '\\'
  let mut «package» := none
  let mut parts := #[]
  let mut s := pattern.toSubstring
  let mut partParts : FilePathPartPattern := #[]
  if s.front == '@' then
    let packageName := s.drop 1 |>.takeWhile (not ∘ isSep)
    s := { s with startPos := packageName.stopPos }
    «package» := some packageName.toString
    if isSep s.front then
      s := s.drop 1
  else if isSep s.front then
    partParts := partParts.push (.literal <| s.take 1)
    s := s.drop 1
  while s.startPos < s.stopPos do
    if s.front = '*' then
      s := s.drop 1
      partParts := partParts.push .wildcard
      continue
    if isSep s.front then
      if partParts.size == 2 && partParts[0]! == .wildcard && partParts[1]! == .wildcard
        then parts := parts.push .doubleWildcard
        else if partParts.size > 0 then
          parts ←
            FilePathPartPattern.validate partParts
              |> Except.mapError (· ++ s!"(in pattern {pattern})")
              |>.map (parts.push ∘ .pattern)
      partParts := #[]
      s := s.drop 1
      continue
    if h: partParts.size > 0
      then
        let lastPartPart := partParts[partParts.size - 1]
        match lastPartPart with
        | .literal lit =>
          partParts := partParts.set (partParts.size - 1) (.literal { lit with stopPos := lit.str.next lit.stopPos })
        | .wildcard =>
          partParts := partParts.push (.literal <| s.take 1)
      else
        partParts := partParts.push (.literal <| s.take 1)
    s := s.drop 1
  if partParts.size > 0 then
    parts ←
      FilePathPartPattern.validate partParts
        |> Except.mapError (· ++ s!"(in pattern {pattern})")
        |>.map (parts.push ∘ .pattern)
  if parts.size = 0 then
    throw s!"File pattern can't have zero parts: {pattern}"
  for h: i in [0:parts.size] do
    if h: i < parts.size - 1 then
      if parts[i] == .doubleWildcard && parts[i + 1] == .doubleWildcard then
        throw s!"File pattern can't contain two consecutive double-wildcards: {pattern}"
    else
      if parts[i] == .doubleWildcard then
        throw s!"File pattern can't end with double-wildcard: {pattern}"
  return { «package», parts }

private partial
def doubleWildcardLeads
  (curPath : System.FilePath)
  (nextPart : FilePathPartPattern)
  (restParts : Subarray FilePathPatternPart)
  : StateT (Array (System.FilePath × Subarray FilePathPatternPart)) IO Unit := do
    for entry in ← curPath.readDir do
      if nextPart.matches entry.fileName then
        modify (·.push (entry.path, restParts))
      let entryPath := entry.path
      if (← entryPath.isDir).not then
        continue
      doubleWildcardLeads entryPath nextPart restParts

def FilePathPattern.find {m} [Monad m] [MonadWorkspace m] [MonadLiftT IO m] (files : Array System.FilePath) (pattern : FilePathPattern) : m (Array System.FilePath) := do
  let mut files : Array System.FilePath := files
  let mut leads : Array (System.FilePath × Subarray FilePathPatternPart) := #[]
  match pattern.package with
  | none =>
    let part0 := pattern.parts[0]!
    match part0 with
    | .doubleWildcard =>
      leads := leads.push (".", pattern.parts.toSubarray)
    | .pattern part0Pat =>
      match part0Pat.getLiteral with
      | none => leads := leads.push (".", pattern.parts.toSubarray)
      | some s => leads := leads.push (s, pattern.parts.toSubarray.drop 1)
  | some dep =>
    match ← findPackage? (Lean.Name.mkStr1 dep) with
    | none =>
      IO.eprintln s!"File pattern referenced package not found: {dep}"
      return #[]
    | some p =>
      leads := leads.push (p.dir, pattern.parts.toSubarray)
  while h: leads.size > 0 do
    let (path, parts) := leads[leads.size - 1]
    leads := leads.pop
    if h: parts.size > 0
      then
        let part := parts[0]
        let restParts := parts.drop 1
        match part with
        | .pattern partPat =>
          if (← path.isDir.toIO) then
            for subPath in ← path.readDir do
              if partPat.matches subPath.fileName then
                leads := leads.push (subPath.path, restParts)
        | .doubleWildcard =>
          let nextPart := restParts[0]!
          match nextPart with
          | .doubleWildcard => continue
          | .pattern nextPartPat =>
            leads ← Prod.snd <$> StateT.run (doubleWildcardLeads path nextPartPat (restParts.drop 1)) leads
      else
        if (← path.metadata).type == .file then
          files := files.push path
  pure files

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

def optionFork := get_config? fork |>.isSome
def submoduleDir := cond optionFork "raylibFork" "raylib"

def optionExtraCmakeArgs := get_config? extraCmakeArgs |>.map splitArgStr |>.getD #[]
def optionPrecompileRaymath := get_config? precompileRaymath |>.isSome
def optionEmcmake := get_config? emcmake |>.getD "emcmake"
def optionEmcc := get_config? emcc |>.getD "emcc"
def optionExtraEmccArgs := get_config? extraEmccArgs |>.map splitArgStr |>.getD #[]
def optionWebShell := get_config? webShell |>.getD s!"{submoduleDir}/src/minshell.html"
def optionWasmToolchain := get_config? wasmToolchain
def optionExtraEmccSources : Array String := get_config? extraEmccSources |>.map splitArgStr |>.getD #[]
def optionDisableMacosLinkArgs := get_config? disableMacosLinkArgs |>.isSome

inductive RaylibPlatform where
| desktop
| web
| android
| raspberryPi
| drm
| sdl
deriving BEq

def RaylibPlatform.toString : RaylibPlatform → String
| .desktop => "Desktop"
| .web => "Web"
| .android => "Android"
| .raspberryPi => "Raspberry Pi"
| .drm => "DRM"
| .sdl => "SDL"

def platform : RaylibPlatform :=
  match (get_config? platform).map String.toLower with
  | none
  | some "desktop" => .desktop
  | some "web" => .web
  | some "android" => .android
  | some "raspberry pi" => .raspberryPi
  | some "drm" => .drm
  | some "sdl" => .sdl
  | some unknown =>
    dbg_trace s!"Unknown `platform`: {unknown}"
    .desktop

def podConfig : Lean.NameMap String := Id.run $ do
  let mut cfg := NameMap.empty
  if let some cc := get_config? cc then
    cfg := cfg.insert `cc cc
  if let some alloc := get_config? alloc then
    cfg := cfg.insert `alloc alloc
  cfg

require pod from git "https://github.com/KislyjKisel/lean-pod" @ "cb4734e" with podConfig

def packagesDir := defaultPackagesDir

package raylib {
  packagesDir := packagesDir
  leanOptions := #[⟨`autoImplicit, false⟩]
}

@[default_target]
lean_lib Raylib {
  srcDir := "src"
}

lean_lib Raymath {
  srcDir := "src"
  precompileModules := optionPrecompileRaymath
}

lean_lib Raygui {
  srcDir := "src"
}

def leanSystemLibDir := run_io
  (Option.map (·.systemLibDir)) <$> Lake.findLeanInstall?

def leanSystemLibDirLinkArgs :=
  match leanSystemLibDir with
  | none => #[]
  | some libDir => #[s!"-L{libDir}"]

def examplesLinkArgs :=
  (splitArgStr <| (get_config? lflags).getD "")
  ++ (if optionDisableMacosLinkArgs || System.Platform.isOSX.not
      then #[]
      else leanSystemLibDirLinkArgs ++ #[
        "-framework", "CoreVideo",
        "-framework", "IOKit",
        "-framework", "Cocoa",
        "-framework", "GLUT",
        "-framework", "OpenGL"
      ])
  ++ (match raylibSrc with
      | .System => #["-L/usr/local/lib64", "-lraylib"]
      | .Submodule => #[s!"-L{submoduleDir}/build/raylib", "-lraylib"]
      | .Custom => #[]
      | .Unknown _ => #[])

lean_exe "raylib-examples-minimal" { moreLinkArgs := examplesLinkArgs, srcDir := "examples", root := `Minimal }
lean_exe "raylib-examples-gui" { moreLinkArgs := examplesLinkArgs, srcDir := "examples", root := `Gui }
lean_exe "raylib-examples-audio" { moreLinkArgs := examplesLinkArgs, srcDir := "examples", root := `Audio }
lean_exe "raylib-examples-videoMode" { moreLinkArgs := examplesLinkArgs, srcDir := "examples", root := `VideoMode }
lean_exe "raylib-examples-extras" { moreLinkArgs := examplesLinkArgs, srcDir := "examples", root := `Extras }

def tryRunProcess {m} [Monad m] [MonadError m] [MonadLiftT IO m] (sa : IO.Process.SpawnArgs) : m IO.Process.Output := do
  let output ← IO.Process.output sa
  if output.exitCode ≠ 0 then
    error s!"'{sa.cmd}  {sa.args}' returned {output.exitCode}: {output.stderr}"
  else
    pure output

def tryRunProcessStreaming {m} [Monad m] [MonadError m] [MonadLiftT IO m] (printCmdOutput : Bool) (sa : IO.Process.SpawnArgs) : m Unit := do
  let process ← IO.Process.spawn { sa with
    toStdioConfig :=
      if printCmdOutput
        then { stdout := .inherit, stderr := .inherit, stdin := .null }
        else { stdout := .null, stderr := .null, stdin := .null }
  }
  let exit ← process.wait
  if exit != 0 then
    error s!"'{sa.cmd}  {sa.args}' returned {exit}"

def updateRayguiSubmodule {m} [Monad m] [MonadError m] [MonadLiftT IO m] (printCmdOutput : Bool) : m Unit := do
  let gitCmd := (get_config? git).getD "git"
  if gitCmd != "" then
    tryRunProcessStreaming printCmdOutput {
      cmd := gitCmd
      args := #["submodule", "update", "--init", "--force", "--recursive", "raygui"]
      cwd := __dir__
    }

def buildRaylibSubmodule {m} [Monad m] [MonadError m] [MonadLiftT IO m] (printCmdOutput : Bool) : m Unit := do
  let gitCmd := (get_config? git).getD "git"
  if gitCmd != "" then
    tryRunProcessStreaming printCmdOutput {
      cmd := gitCmd
      args := #["submodule", "update", "--init", "--force", "--recursive", submoduleDir]
      cwd := __dir__
    }

  IO.FS.createDirAll s!"{__dir__}/{submoduleDir}/build"

  let cmakeCmd := (get_config? cmake).getD "cmake"
  let mut cmakeBuildArgs : Array String :=
    if platform == .web
      then #[cmakeCmd, "-DCMAKE_C_FLAGS=-pthread"]
      else #[]
  cmakeBuildArgs := cmakeBuildArgs ++ #[
    "-DCUSTOMIZE_BUILD=ON",
    "-DWITH_PIC=ON",
    "-DCMAKE_BUILD_TYPE=Release",
    "-DBUILD_EXAMPLES=OFF"
  ]
  if let some extGlfw := get_config? externalGlfw then
    let values := #["OFF", "ON", "IF_POSSIBLE"]
    if values.contains extGlfw
      then cmakeBuildArgs := cmakeBuildArgs.push s!"-DUSE_EXTERNAL_GLFW={extGlfw}"
      else error s!"Invalid config option value: externalGlfw={extGlfw}; expected one of {values}"
  cmakeBuildArgs := cmakeBuildArgs.push s!"-DPLATFORM={platform.toString}"
  if let some oglVer := get_config? opengl then
    let mut oglVers := #["OFF", "4.3", "3.3", "2.1", "1.1", "ES 2.0", "ES 3.0"]
    if optionFork then
      oglVers := oglVers.push "4.6"
    if oglVers.contains oglVer
      then cmakeBuildArgs := cmakeBuildArgs.push s!"-DOPENGL_VERSION={oglVer}"
      else error s!"Invalid config option value: opengl={oglVer}; expected one of {oglVers}"
  let binCfgToOpt (opts : Array String) (cfgKey : String) (optPref : String) : Option String → IO (Array String)
  | some cfg => if cfg == "ON" || cfg == "OFF"
      then pure $ opts.push $ optPref ++ cfg
      else error s!"Invalid config option value: {cfgKey}={cfg}; expected ON or OFF"
  | none => pure opts
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "wayland" "-DGLFW_BUILD_WAYLAND=" (get_config? wayland)
  cmakeBuildArgs ← binCfgToOpt cmakeBuildArgs "x11" "-DGLFW_BUILD_X11=" (get_config? x11)
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
  if platform == .web then
    cmakeBuildArgs := cmakeBuildArgs.push "-S"
  cmakeBuildArgs := cmakeBuildArgs.push ".." ++ optionExtraCmakeArgs

  let cmakeCmd := (get_config? cmake).getD "cmake"
  if cmakeCmd != "" then
    tryRunProcessStreaming printCmdOutput {
      cmd := if platform == .web then optionEmcmake else cmakeCmd
      args := cmakeBuildArgs
      cwd := __dir__ / submoduleDir / "build"
    }
    tryRunProcessStreaming printCmdOutput {
      cmd := cmakeCmd
      args := #["--build", ".", "--config", "Release"]
      cwd := __dir__ / submoduleDir / "build"
    }

def bindingsCFlags (pkg : NPackage _package.name) : FetchM (Array String × Array String) := do
  let mut weakArgs := #["-I", (← getLeanIncludeDir).toString]
  let mut traceArgs := #["-fPIC"].append $ splitArgStr $ (get_config? cflags).getD ""

  match ← findPackage? `pod with
    | none => error "Missing dependency 'Pod'"
    | some pod =>
      weakArgs := weakArgs ++ #[
        "-I",
        (pod.dir / "ffi" / "include").toString
      ]

  let printCmdOutput := (get_config? cmdout).isSome

  match raylibSrc with
    | .System =>
      let pkgConfigOutput ← tryRunProcess {
        cmd := "pkg-config"
        args := #["--cflags", "raylib", "glfw3"]
      }
      weakArgs := weakArgs.append $ splitArgStr $ pkgConfigOutput.stdout.replace "\n" " "

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

  if (get_config? cc).isNone && (← getLeanCc?).isNone && (← IO.getEnv "CC").isNone then
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
  let nativeSrcDir := pkg.dir / "ffi"
  let objectFileDir := pkg.irDir / "__ffi__"
  let headerFile (h : String) : System.FilePath := nativeSrcDir / (h ++ ".h")
  let extraTrace : BuildTrace ← mixTraceArray <$> (bindingsHeaders.mapM $ computeTrace ∘ headerFile)
  let extraTrace : BuildTrace := mixTrace extraTrace (← getLeanTrace)
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
  IO.println s!"platform={platform.toString}"
  IO.println s!"raylib={get_config? raylib}"
  IO.println s!"raygui? {(get_config? raygui).isSome}"
  IO.println s!"cc={get_config? cc}"
  IO.println s!"cflags={get_config? cflags}"
  IO.println s!"lflags={get_config? lflags}"
  IO.println s!"fork? {optionFork}"
  IO.println s!"alloc={get_config? alloc}"
  IO.println s!"git={get_config? git}"
  IO.println s!"cmake={get_config? cmake}"
  IO.println s!"extraCmakeArgs: {optionExtraCmakeArgs}"
  IO.println s!"precompileRaymath? {optionPrecompileRaymath}"
  IO.println s!"emcmake={optionEmcmake}"
  IO.println s!"emcc={optionEmcc}"
  IO.println s!"extraEmccArgs: {optionExtraEmccArgs}"
  IO.println s!"webShell={optionWebShell}"
  IO.println s!"wasmToolchain={optionWasmToolchain}"
  IO.println s!"extraEmccSources: {optionExtraEmccSources}"
  return 0

/--
`LeanExe.recBuildExe` changed to exclude linking.
Used when building for wasm as linking is not needed here and will also fail.
-/
def buildExeWithoutLinking (self : LeanExe) : FetchM (Job Unit) :=
  withRegisterJob s!"{self.name}" do
  let mut linkJobs := #[]
  for facet in self.root.nativeFacets self.supportInterpreter do
    linkJobs := linkJobs.push <| ← fetch <| self.root.facet facet.name
  let imports ← (← self.root.transImports.fetch).await
  for mod in imports do
    for facet in mod.nativeFacets self.supportInterpreter do
      linkJobs := linkJobs.push <| ← fetch <| mod.facet facet.name
  let deps := (← (← self.pkg.transDeps.fetch).await).push self.pkg
  for dep in deps do for lib in dep.externLibs do
    linkJobs := linkJobs.push <| ← lib.static.fetch
  (Job.collectArray linkJobs).mapM λ _ ↦ pure ()

script buildWeb (args) do
  let targetName ← if h: args.length = 1
    then pure args[0]
    else error "invalid command line arguments, expected executable target name"
  let ws ← getWorkspace
  let some exe := ws.findLeanExe? targetName.toName
    | error s!"unknown executable `{targetName}`"
  IO.println "Building exe..."
  runBuild <| buildExeWithoutLinking exe
  if platform != .web then
    IO.eprintln s!"Config option platform has unexpected value: {platform.toString}"
    return 1
  if optionWasmToolchain.isNone then
    -- TODO: Try downloading using Lake.download
    IO.eprintln s!"Config option wasmToolchain is missing"
    return 1
  let podDir ← match ← findPackage? `pod with
    | none => error "Missing dependency 'Pod'"
    | some pod => pure pod.dir
  let wasmToolchain := optionWasmToolchain.get!
  IO.FS.createDirAll ".lake/build/web" -- TODO: configure?
  let emccArgs := #[
    "-o", ".lake/build/web/main.html",
    "-I", s!"{wasmToolchain}/include",
    "-L", s!"{wasmToolchain}/lib/lean",
    "-I", s!"{podDir}/ffi/include",
    "-lInit", "-lLean", "-lleancpp", "-lleanrt", "-lStd",
    s!"-L{__dir__}/{submoduleDir}/build/raylib", "-lraylib",
    "-sMAIN_MODULE=1",
    "-pthread",
    "-sUSE_WEBGL2=1",
    "-sUSE_GLFW=3",
    "-sASYNCIFY", -- TODO: configure?
    "-sALLOW_MEMORY_GROWTH=1",
    "-O1", "-flto", "-sASSERTIONS=1", -- TODO: remove/configure
    "--shell-file", optionWebShell
    -- TODO: see also:
    -- -sMODULARIZE, -sEXIT_RUNTIME=0, -fwasm-exceptions, -sEXPORT_ALL=0,
    -- -sLINKABLE=0, -sMAIN_MODULE=2, -sFORCE_FILESYSTEM
  ]
  let cSourcesPatterns := optionExtraEmccSources ++ #[
    ".lake/packages/*/.lake/build/ir/**/*.c",
    ".lake/build/ir/**/*.c",
    "ffi/**/*.c",
    s!"{podDir}/ffi/**/*.c"
  ]
  match cSourcesPatterns.mapM (λ x ↦ Prod.mk x <$> FilePathPattern.parse x) with
  | .error e =>
    IO.eprintln e
    return 1
  | .ok cSourcePatterns =>
    let cSources ← flip cSourcePatterns.foldlM #[] λ acc (raw, x) ↦
      IO.println s!"Searching files with pattern {raw}" *>
      FilePathPattern.find acc x
    let emccArgs := emccArgs ++ cSources.map System.FilePath.toString ++ optionExtraEmccArgs
    IO.println s!"Running {optionEmcc} with args {repr emccArgs}"
    tryRunProcessStreaming true {
      cmd := optionEmcc
      args := emccArgs
    }
    IO.println "Success."
    IO.println "Example usage:"
    IO.println "xdg-open http://localhost:8080/main.html && python3 -m http.server 8080 -d .lake/build/web"
    return 0
