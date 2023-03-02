import Raylib

open Raylib

def windowWidth : UInt32 := 800
def windowHeight : UInt32 := 600
def mouseSensitivity : Float := 1 / 100
def moveSpeed : Float := 0.1

def main : IO Unit := do
  SetConfigFlags FLAG_VSYNC_HINT
  InitWindow windowWidth windowHeight "Hello, Raylib-Lean"
  InitAudioDevice
  SetExitKey KEY_NULL

  let mut cam3d := Camera3D.mk
    (Vector3.mk 0 0 0)
    (Vector3.mk 0 0 10)
    (Vector3.mk 0 1 0)
    90
    CAMERA_PERSPECTIVE

  repeat do
    BeginDrawing
    ClearBackground RAYWHITE
    DrawFPS 0 0
    BeginMode3D cam3d

    DrawCube
      (Vector3.mk 0 0 5)
      3 3 3
      RED

    EndMode3D
    EndDrawing

    let mp ← GetMousePosition

    cam3d := cam3d.set_position $ Vector3.mk
      ((mp.x - (windowWidth / 2).toUInt64.toFloat) * mouseSensitivity)
      ((mp.y - (windowHeight / 2).toUInt64.toFloat) * mouseSensitivity)
      0

    let camPos := cam3d.position
    if (← IsKeyDown KEY_W)
      then cam3d := cam3d.set_position $ Vector3.mk camPos.x camPos.y (camPos.z + moveSpeed)
    if (← IsKeyDown KEY_S)
      then cam3d := cam3d.set_position $ Vector3.mk camPos.x camPos.y (camPos.z - moveSpeed)

    if (← IsKeyDown KEY_LEFT_ALT) && (← IsKeyPressed KEY_ENTER)
      then ToggleFullscreen

    if (← WindowShouldClose) then break

  CloseAudioDevice
  CloseWindow
