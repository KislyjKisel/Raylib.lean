import Raylib.Defines
import Raylib.Functions

namespace Raylib.Extras

structure WindowParams where
  windowWidth : UInt32 := 800
  windowHeight : UInt32 := 600
  windowTitle : String := "Raylib"
  configFlags : Raylib.ConfigFlags := .vsyncHint ||| .windowHighdpi ||| .windowResizable
  exitKey : Option Raylib.KeyboardKey := none

@[specialize]
def withWindow {m α} [Monad m] [MonadLiftT IO m] [MonadLiftT BaseIO m] [MonadFinally m]
  (params : WindowParams) (f : Raylib.Context → m α) : m α := do
    setConfigFlags params.configFlags
    let rl ← initWindow params.windowWidth params.windowHeight params.windowTitle.toSubstring
    Raylib.setExitKey <| params.exitKey.getD .null
    tryFinally (f rl) do
      Raylib.closeWindow rl

@[specialize]
def withAudio {m α} [Monad m] [MonadLiftT BaseIO m] [MonadFinally m] (f : m α) : m α := do
  Raylib.setAudioThreadEntryCallback
  Raylib.setAudioThreadExitCallback
  Raylib.initAudioDevice
  tryFinally f do
    Raylib.closeAudioDevice
    Raylib.resetAudioThreadEntryCallback
    Raylib.resetAudioThreadExitCallback

inductive DrawingLoopMode (m : Type → Type) (α : Type) where
| none
| camera2d (getCamera2d : α → m Camera2D)
| camera3d (getCamera3d : α → m Camera3D)

structure DrawingLoop (m : Type → Type) (α β : Type) [Monad m] where
  /-- Clear background every frame. -/
  clearBackground : Option Color := some .raywhite
  /-- Enable toggling fullscreen on `Alt+Enter`. -/
  toggleFullscreen : Bool := true
  /-- Additionally wrap `onDraw` call in `beginMode2D` (or 3D) and `endMode2D` (or 3D). -/
  mode : DrawingLoopMode m α := .none
  /-- Runs on window close events. Return `Sum.inl _` to exit loop. -/
  onClose : α → m (Sum β α) := pure ∘ Sum.inr
  /-- Runs inside the loop wrapped in `beginDrawing` and `endDrawing`. Return `Sum.inl _` to exit loop. -/
  onDraw : α → m (Sum β α) := pure ∘ Sum.inr

@[specialize] partial
def withDrawingLoop
  {m α β} [Monad m] [MonadLiftT BaseIO m] [MonadFinally m] [Nonempty β] (loop : DrawingLoop m α β) (state : α)
  : m β := do
    if loop.toggleFullscreen && (← Raylib.isKeyDown .leftAlt) && (← Raylib.isKeyPressed .enter) then
      Raylib.toggleFullscreen
    Raylib.beginDrawing
    match loop.mode with
    | .none => pure ()
    | .camera2d f => Raylib.beginMode2D (← f state)
    | .camera3d f => Raylib.beginMode3D (← f state)
    if let some background := loop.clearBackground then
      Raylib.clearBackground background
    match ← tryFinally (loop.onDraw state)
      (do
        match loop.mode with
        | .none => pure ()
        | .camera2d _ => Raylib.endMode2D
        | .camera3d _ => Raylib.endMode3D
        Raylib.endDrawing
      )
    with
    | .inl result => pure result
    | .inr state =>
      if ← Raylib.windowShouldClose
        then
          match ← loop.onClose state with
          | .inl result => pure result
          | .inr state => withDrawingLoop loop state
        else
          withDrawingLoop loop state

structure RaylibParams (m : Type → Type) (α β : Type) [Monad m] extends WindowParams, DrawingLoop m α β where
  audio : Bool := true
  init : Raylib.Context → m α

@[specialize]
def withRaylibLoop
  {m α β} [Monad m] [MonadLiftT IO m] [MonadLiftT BaseIO m] [MonadFinally m] [Nonempty β]
  (params : RaylibParams m α β)
  : m β :=
    withWindow params.toWindowParams λ rl ↦
      if params.audio
        then
          withAudio do
            -- NOTE: `init` called after audio initialization
            withDrawingLoop params.toDrawingLoop (← params.init rl)
        else do
          withDrawingLoop params.toDrawingLoop (← params.init rl)
