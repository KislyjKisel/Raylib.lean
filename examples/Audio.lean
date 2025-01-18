import Raylib
import Raygui

def main : IO Unit := do
  let rlctx ← Raylib.initWindow 640 300 "Example".toSubstring
  Raylib.setTargetFPS 60 -- not important, but avoids 100% cpu usage

  -- Set audio thread entry and exit callbacks.
  -- Otherwise audio callbacks would cause UB.
  -- Must be done before the initialization of audio subsystem!
  -- Callbacks will be augmented with initialization and finalization of Lean's thread-local state,
  -- so even `pure ()` callback will be enough to run audio stream callbacks without segfaults.
  Raylib.setAudioThreadEntryCallback
  Raylib.setAudioThreadExitCallback
  Raylib.initAudioDevice
  Raylib.setMasterVolume 0.5

  -- NOTE: If a music object or an audio stream object is finalized, it will stop playing.
  -- To keep playing - keep a reference alive (e.g. call close on it when it will be no longer necessary).
  let music ← Raylib.loadMusicStream rlctx "raylib/examples/audio/resources/country.mp3"
  music.setLooping true

  let sound ← Raylib.loadSound rlctx "raylib/examples/audio/resources/coin.wav"

  -- Generating audio steam from code using a callback
  let audioSampleRate := 44100
  let audioDt := 1.0 / audioSampleRate.toFloat32
  let audioStream ← Raylib.loadAudioStream rlctx audioSampleRate .f32 1
  let audioFrequency : IO.Ref Float32 := ← IO.mkRef 440.0
  let audioX ← IO.mkRef (0.0 : Float32)
  Raylib.setAudioStreamCallback audioStream λ frames data ↦ do
    Raylib.EST2.ignoreErrors do
      let mut x ← audioX.get
      let freq ← audioFrequency.get
      for h: _ in [:frames] do
        Raylib.EST2.lift₁ <| Raylib.setSample h.upper data x.sin
        x := x + 2 * .pi * freq * audioDt
      audioX.set x

  let mut prevSelectedStreamMode : UInt32 := 0
  let mut selectedStreamMode : UInt32 := 0

  repeat do
    if selectedStreamMode == 1 then
      Raylib.updateMusicStream music

    Raylib.beginDrawing
    Raylib.clearBackground .raywhite

    match selectedStreamMode with
    | 0 => pure ()
    | 1 =>
      let progress := (← Raylib.getMusicTimePlayed music) / (Raylib.getMusicTimeLength music)
      Raylib.drawRectangleRec ⟨100, 170, 440, 30⟩ .gray
      Raylib.drawRectangleRec ⟨100, 170, 440 * progress, 30⟩ .blue
    | 2 =>
      let freq ← audioFrequency.get
      audioFrequency.set <|
        ← Raygui.sliderBar ⟨300, 10, 300, 40⟩
          "Callback wave frequency"
          (toString freq.toUInt32)
          freq 40 1000
      let ax := (← audioX.get)
      let n := 100
      let scale := 0.005
      let mut prev : Option Raymath.Vector2 := none
      for i in [0:n] do
        let nx := i.toFloat32 / n.toFloat32
        let x := nx * 600 + 20
        let y := 190 + 90 * (ax + 2 * .pi * freq * ((nx - 0.5) * scale)).sin
        let p := ⟨x, y⟩
        if let some p2 := prev then
          Raylib.drawLineEx p2 p 2.0 .green
        prev := p

    | _ => unreachable!

    selectedStreamMode :=
      ← Raygui.comboBox ⟨10, 10, 130, 40⟩ "Paused;Music;Callback" selectedStreamMode

    if ← Raygui.button ⟨10, 50, 130, 40⟩ "Sound" then
      Raylib.playSound sound

    Raylib.endDrawing

    if prevSelectedStreamMode != selectedStreamMode then
      match prevSelectedStreamMode with
      | 0 => pure ()
      | 1 => Raylib.pauseMusicStream music
      | 2 => Raylib.pauseAudioStream audioStream
      | _ => unreachable!
      prevSelectedStreamMode := selectedStreamMode
      match selectedStreamMode with
      | 0 => pure ()
      | 1 => Raylib.playMusicStream music
      | 2 => Raylib.playAudioStream audioStream
      | _ => unreachable!

    if (← Raylib.windowShouldClose) then break

  Raylib.stopAudioStream audioStream
  Raylib.stopMusicStream music
  Raylib.closeAudioDevice
  Raylib.resetAudioThreadEntryCallback -- destroy reference to callback
  Raylib.resetAudioThreadExitCallback -- destroy reference to callback

  Raylib.closeWindow rlctx
