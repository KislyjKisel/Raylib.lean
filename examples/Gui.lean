import Raylib
import Raygui

inductive Shape where
| circle
| square
| triangle
deriving Inhabited

instance : ToString Shape where
  toString
  | .circle => "Circle"
  | .square => "Square"
  | .triangle => "Triangle"

def Shape.values : List Shape :=
  [.circle, .square, .triangle]

def Shape.valuesString : String :=
  values
    |>.map toString
    |> ";".intercalate

#eval Shape.valuesString -- Combo box expects a string describing available options

def main : IO Unit := do
  let rlctx ← Raylib.initWindow 800 600 "Example".toSubstring
  Raylib.setTargetFPS 60 -- not important, but avoids 100% cpu usage

  let mut size: Float32 := 16
  let mut selected_shape: UInt32 := 0
  let mut color: Raylib.Color := .blue
  let mut position_x: Float32 := 400
  let position_y := 160

  let iconNames ← List.replicate 32 0 |>.mapM λ _ ↦ Nat.toUInt8 <$> IO.rand 0 200
  let iconNamesString := iconNames.map toString |> ";".intercalate
  let mut selectedIcon : UInt32 := 0
  let mut iconScrollIndex : UInt32 := 0

  let mut textBoxValue := ""

  repeat do
    Raylib.beginDrawing
    Raylib.clearBackground .raywhite

    position_x := ← Raygui.slider ⟨50, 50, 300, 30⟩ "Left" "Right" position_x 50 350
    if ← Raygui.button ⟨50, 230, 75, 40⟩ "Larger" then
      size := size + 1
    if ← Raygui.button ⟨140, 230, 75, 40⟩ "Smaller" then
      size := size - 1
    selected_shape := ← Raygui.comboBox ⟨230, 230, 130, 40⟩ Shape.valuesString selected_shape
    color := ← Raygui.colorPicker ⟨50, 280, 310, 200⟩ "Color" color

    match Shape.values[selected_shape.toNat]! with
    | .circle => Raylib.drawCircleV ⟨position_x, position_y⟩ size color
    | .square => Raylib.drawRectangleRec ⟨position_x - size, position_y - size, size * 2, size * 2⟩ color
    | .triangle =>
      let point: Float32 → Raymath.Vector2 := λ degrees ↦
        let radians := degrees * Raymath.deg2Rad
        ⟨position_x + radians.cos * size, position_y + radians.sin * size⟩
      Raylib.drawTriangle (point 30) (point 270) (point 150) color
    Raylib.endDrawing

    Raygui.drawIcon iconNames[selectedIcon.toNat]! 650 50 2 .black
    (iconScrollIndex, selectedIcon) ←
      Raygui.listView ⟨650, 100, 100, 380⟩ iconNamesString iconScrollIndex selectedIcon

    let mut textBoxFlush := false
    (textBoxFlush, textBoxValue) ← Raygui.textBox ⟨100, 500, 600, 50⟩ textBoxValue 72 true
    if textBoxFlush then
      IO.println textBoxValue
      textBoxValue := ""

    if (← Raylib.windowShouldClose) then break

  Raygui.disable
  Raylib.closeWindow rlctx
