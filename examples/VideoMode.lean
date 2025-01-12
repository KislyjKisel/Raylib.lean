import Raylib
import Raygui

def main : IO Unit := do
  let rlctx ← Raylib.initWindow 640 480 "Example".toSubstring
  Raylib.setTargetFPS 60 -- not important, but avoids 100% cpu usage

  let primaryMonitor ← Raylib.Glfw.getPrimaryMonitor.toIO
  let videoModes ← (Raylib.Glfw.getVideoModes primaryMonitor).toIO
  let videoModeStrings := videoModes.map λ vm ↦
    s!"{vm.width}x{vm.height} {vm.refreshRate} Hz (RGB {vm.redBits}/{vm.greenBits}/{vm.blueBits})"
  let mut currentVideoMode := ← (Raylib.Glfw.getVideoMode primaryMonitor).toIO
  let mut currentVideoModeIndex :=
    UInt32.ofNat <| Option.get! <| videoModes.findIdx? (· == currentVideoMode)
  let mut videoModeScoll := 0
  let mut videoModeFocus := 0

  repeat do
    Raylib.beginDrawing
    Raylib.clearBackground .raywhite

    let padding : Pod.Float32 := 10
    Raylib.drawText "Alt+Enter to toggle fullscreen" padding.toInt32 padding.toInt32 20 .darkpurple

    let prevIndex := currentVideoModeIndex
    let rect := if (← Raylib.isWindowFullscreen)
      then ⟨padding, padding, currentVideoMode.width.toFloat32 - padding * 2, currentVideoMode.height.toFloat32 - padding * 4⟩
      else ⟨padding, padding * 3, 640 - padding * 2, 480 - padding * 4⟩
    (videoModeScoll, currentVideoModeIndex, videoModeFocus) ← Raygui.listViewEx rect videoModeStrings videoModeScoll currentVideoModeIndex videoModeFocus
    if prevIndex != currentVideoModeIndex then
      currentVideoMode := videoModes[currentVideoModeIndex.toNat]!
      if ← Raylib.isWindowFullscreen then
        Raylib.Glfw.GlfwIO.toIO <|
          Raylib.Glfw.setWindowMonitor
            (Raylib.Glfw.Window.mk (← Raylib.getWindowBackendHandle))
            primaryMonitor
            0 0 currentVideoMode.width currentVideoMode.height
            currentVideoMode.refreshRate

    Raylib.endDrawing

    if (← Raylib.isKeyDown .leftAlt) && (← Raylib.isKeyPressed .enter) then
      Raylib.toggleFullscreen
      currentVideoMode := ← (Raylib.Glfw.getVideoMode primaryMonitor).toIO
      match videoModes.findIdx? (· == currentVideoMode) with
      | none => IO.eprintln s!"Video mode not found in list: {repr currentVideoMode}"
      | some i => currentVideoModeIndex := UInt32.ofNat i

    if (← Raylib.windowShouldClose) then break

  Raylib.closeWindow rlctx
