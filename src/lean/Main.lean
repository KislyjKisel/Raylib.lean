import Raymath
import Raylib

open Pod (Float32)
open Raymath
open Raylib

def windowWidth : UInt32 := 800
def windowHeight : UInt32 := 600
def mouseSensitivity : Float32 := 1 / 200
def moveSpeed : Float32 := 0.15

def main : IO Unit := do
  setConfigFlags .vsyncHint
  initWindow windowWidth windowHeight "Hello, Raylib-Lean"
  initAudioDevice
  setExitKey .null

  let camUp := Vector3.mk 0 1 0
  let mut camForward := Vector3.mk 0 0 1
  let mut cam3d := Camera3D.mk
    (Vector3.mk 0 0 0)
    (camForward.scale 10)
    camUp
    90
    .perspective

  setMousePosition (Int32.mk (windowWidth / 2)) (Int32.mk (windowHeight / 2))
  let mut lastMousePosition : Vector2 ← getMousePosition

  repeat do
    let mp ← getMousePosition

    beginDrawing
    clearBackground .raywhite
    drawFPS 0 0
    drawTextPro (← getFontDefault) "TEXT" mp Vector2.zero (100 * (← getTime)) 36 10 .black
    beginMode3D cam3d

    drawCube
      (Vector3.mk 0 0 5)
      3 3 3
      .red

    endMode3D
    endDrawing

    let dmp := (lastMousePosition - mp).scale mouseSensitivity
    camForward := camForward.rotateByAxisAngle camUp dmp.x
    camForward := camForward.rotateByAxisAngle (camForward.cross camUp) dmp.y

    if ← isWindowFullscreen
      then
        setMousePosition (Int32.mk (windowWidth / 2)) (Int32.mk (windowHeight / 2))
        lastMousePosition ← getMousePosition
      else
        lastMousePosition := mp

    if (← isKeyDown .w)
      then cam3d := { cam3d with position := cam3d.position + camForward.scale moveSpeed }
    if (← isKeyDown .s)
      then cam3d := { cam3d with position := cam3d.position - camForward.scale moveSpeed }
    if (← isKeyDown .a)
      then cam3d := { cam3d with position := cam3d.position - (camForward.cross camUp).scale moveSpeed }
    if (← isKeyDown .d)
      then cam3d := { cam3d with position := cam3d.position + (camForward.cross camUp).scale moveSpeed }

    if (← isKeyDown .leftAlt) && (← isKeyPressed .enter)
      then
        toggleFullscreen
        if ← isWindowFullscreen
          then hideCursor
          else showCursor

    cam3d := { cam3d with target := cam3d.position + camForward }

    if (← windowShouldClose) then break

  closeAudioDevice
  closeWindow
