import Raymath
import Raylib

open Pod (Float32)
open Raymath
open Raylib

def windowWidth : UInt32 := 800
def windowHeight : UInt32 := 600
def mouseSensitivity : Float32 := 1 / 100
def moveSpeed : Float32 := 0.1

def main : IO Unit := do
  setConfigFlags .vsyncHint
  initWindow windowWidth windowHeight "Hello, Raylib-Lean"
  initAudioDevice
  setExitKey .null

  let mut cam3d := Camera3D.mk
    (Vector3.mk 0 0 0)
    (Vector3.mk 0 0 10)
    (Vector3.mk 0 1 0)
    90
    .perspective

  repeat do
    beginDrawing
    clearBackground .raywhite
    drawFPS 0 0
    beginMode3D cam3d

    drawCube
      (Vector3.mk 0 0 5)
      3 3 3
      .red

    endMode3D
    endDrawing

    let mp ← getMousePosition

    cam3d := { cam3d with
      position := Vector3.mk
        ((mp.x - (windowWidth / 2).toUInt64.toFloat32) * mouseSensitivity)
        ((mp.y - (windowHeight / 2).toUInt64.toFloat32) * mouseSensitivity)
        0
    }

    let camPos := cam3d.position
    if (← isKeyDown .w)
      then cam3d := { cam3d with position := Vector3.mk camPos.x camPos.y (camPos.z + moveSpeed) }
    if (← isKeyDown .s)
      then cam3d := { cam3d with position := Vector3.mk camPos.x camPos.y (camPos.z - moveSpeed) }

    if (← isKeyDown .leftAlt) && (← isKeyPressed .enter)
      then toggleFullscreen

    if (← windowShouldClose) then break

  closeAudioDevice
  closeWindow
