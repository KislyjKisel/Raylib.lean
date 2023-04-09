import Raylib.Structures

namespace Raylib

/-! # Aliases -/

/-- Texture2D, same as Texture -/
abbrev Texture2D : Type := Texture

abbrev Texture2DRef : Type := TextureRef

/-- TextureCubemap, same as Texture -/
abbrev TextureCubemap : Type := Texture

/-- RenderTexture2D, same as RenderTexture -/
abbrev RenderTexture2D : Type := RenderTexture

/-- Camera type fallback, defaults to Camera3D -/
abbrev Camera : Type := Camera3D

end Raylib
