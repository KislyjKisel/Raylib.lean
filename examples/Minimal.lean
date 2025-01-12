import Raylib

def main : IO Unit := do
  let rlctx ← Raylib.initWindow 640 480 "Example".toSubstring

  repeat do
    Raylib.beginDrawing
    Raylib.clearBackground .raywhite
    Raylib.drawCircleV (← Raylib.getMousePosition) 8.0 .blue
    Raylib.endDrawing

    if (← Raylib.windowShouldClose) then break

  Raylib.closeWindow rlctx
