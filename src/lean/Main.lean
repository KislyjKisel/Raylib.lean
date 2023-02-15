import Raylib

open Raylib

partial def loop : IO Unit := do
  BeginDrawing
  ClearBackground RAYWHITE
  EndDrawing

  let mp ← GetMousePosition
  DrawFPS (Int32.mk mp.x.toUInt32) (Int32.mk mp.y.toUInt32)

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
