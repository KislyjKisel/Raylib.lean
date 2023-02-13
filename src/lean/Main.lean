import Raylib

open Raylib

partial def loop : IO Unit := do
  BeginDrawing ()
  ClearBackground RAYWHITE
  EndDrawing ()

  let mp ← GetMousePosition ()
  DrawLineV (Vector2.mk 0.0 0.0) mp YELLOW

  let exit ← WindowShouldClose ()
  if exit
    then pure ()
    else loop

def main : IO Unit := do
  InitWindow 640 480 "Hello, Raylib-Lean"
  SetExitKey KEY_NULL
  loop
  CloseWindow ()
