import Raymath
import Raylib
import Raygui

open Pod (Float32 Int32)
open Raymath
open Raylib

def windowWidth : UInt32 := 800
def windowHeight : UInt32 := 600
def mouseSensitivity : Float32 := 1 / 200
def moveSpeed : Float32 := 0.15

inductive TestModel where
| cube (m : Mesh)
| model (m : Model)

def main : IO Unit := do
  setConfigFlags .vsyncHint
  let rlctx ← initWindow windowWidth windowHeight "Hello, Raylib-Lean".toSubstring
  initAudioDevice
  setExitKey .null

  IO.println "Supported video modes:"
  let videoModes ← (Glfw.getVideoModes (← Glfw.getPrimaryMonitor.toIO)).toIO
  for videoMode in videoModes do
    IO.println <| repr videoMode
  IO.println "Current video mode:"
  IO.println <| repr <| ← (Glfw.getVideoMode (← Glfw.getPrimaryMonitor.toIO)).toIO

  -- let audioStream ← loadAudioStream rlctx 44100 .u16 1
  -- setMasterVolume 0.5
  -- setAudioStreamCallback audioStream λ frames data ↦ do
  --   EST2.lift₂ $ IO.println "Audio callback called"
  -- playAudioStream audioStream

  let camUp := Vector3.mk 0 1 0
  let mut camForward := Vector3.mk 0 0 1
  let mut cam3d := Camera3D.mk (Vector3.mk 0 0 0) camForward camUp 90 .perspective

  setMousePosition (Int32.mk (windowWidth / 2)) (Int32.mk (windowHeight / 2))
  let mut lastMousePosition ← getMousePosition

  let shader ← loadShaderFromMemory rlctx
    (some "
      #version 330
      uniform mat4 mvp;
      uniform mat4 matNormal;
      in vec3 vertexPosition;
      in vec3 vertexNormal;
      in vec4 vertexColor;
      out vec3 fragNormal;
      out vec4 fragColor;
      void main(){
        fragColor = vertexColor;
        fragNormal = normalize((matNormal * vec4(vertexNormal, 1.0)).xyz);
        gl_Position = mvp * vec4(vertexPosition, 1.0);
      }
    ")
    (some "
      #version 330
      uniform vec4 colDiffuse;
      in vec4 fragColor;
      in vec3 fragNormal;
      out vec4 finalColor;
      void main() {
        finalColor = fragColor * colDiffuse *
          clamp(dot(normalize(fragNormal), normalize(vec3(0.5, 2, -1))), 0.2, 1.0);
      }
    ")

  let material : Material := {
    shader
    maps := .ofFn λ m ↦
      match m with
      | .diffuse => {
        texture := .getDefault rlctx
        color := .maroon
      }
      | _ => .empty
  }
  let modelPath : System.FilePath := "teapot.obj"
  let model ← if ← modelPath.pathExists
    then do
      let model ← loadModel rlctx modelPath
      pure $ TestModel.model $ model.setMaterial? 0 material
    else
      pure $ .cube $ genMeshCube rlctx 1.0 1.0 1.0

  repeat do
    beginDrawing
    clearBackground .raywhite
    drawFPS (.mk 0) (.mk 0)
    let _ ← Raygui.button {x := 100, y := 10, width := 100, height := 50} "Click me"
    beginMode3D cam3d

    let modelPos := Vector3.mk 0 0 5
    match model with
    | .model m =>
      drawModel m modelPos 1.0 .white
    | .cube m =>
      drawMesh m material (Matrix.translateV $ .mk 0 0 5)

    endMode3D
    endDrawing

    let mp ← getMousePosition
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

  -- stopAudioStream audioStream -- keep reference alive
  closeAudioDevice
  closeWindow rlctx
