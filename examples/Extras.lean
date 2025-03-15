import Raylib

def main : IO Unit := do
  Raylib.Extras.withRaylibLoop {
    init := pure (f := IO)
    onClose := λ _ ↦
      pure <| .inl ()
    onDraw := λ rl ↦ do
      Raylib.drawCircleV (← Raylib.getMousePosition) 8.0 .blue
      pure <| .inr rl
  }
