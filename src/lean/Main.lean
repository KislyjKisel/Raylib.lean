import Raylib

open Raylib

def main : IO Unit := do
  SetConfigFlags FLAG_VSYNC_HINT
  InitWindow 640 480 "Hello, Raylib-Lean"
  InitAudioDevice
  SetExitKey KEY_NULL

  repeat do
    BeginDrawing
    do
      ClearBackground RAYWHITE
      DrawFPS 0 0
      let mp ← GetMousePosition
      DrawRectangleGradientEx (Rectangle.mk 100.0 100.0 mp.x mp.y) RED GREEN BLUE YELLOW
    EndDrawing

    if (← WindowShouldClose) then break

  CloseAudioDevice
  CloseWindow
