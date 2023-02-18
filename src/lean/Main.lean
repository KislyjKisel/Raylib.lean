import Raylib

open Raylib

partial def loop : IO Unit := do
  BeginDrawing
  do
    ClearBackground RAYWHITE
    DrawFPS 0 0
    let mp ← GetMousePosition
    DrawRectangleGradientEx (Rectangle.mk 100.0 100.0 mp.x mp.y) RED GREEN BLUE YELLOW
  EndDrawing

  let exit ← WindowShouldClose
  if exit
    then pure ()
    else loop

def main : IO Unit := do
  SetConfigFlags FLAG_VSYNC_HINT
  InitWindow 640 480 "Hello, Raylib-Lean"
  SetExitKey KEY_NULL
  loop
  CloseWindow
