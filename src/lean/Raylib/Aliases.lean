import Raylib.Structures

namespace Raylib

/-! # Aliases -/

/-- Same as `Texture` -/
abbrev Texture2D : Type := Texture

/-- Same as `TextureRef` -/
abbrev Texture2DRef : Type := TextureRef

/-- Same as `Texture` -/
abbrev TextureCubemap : Type := Texture

/-- Same as `RenderTexture` -/
abbrev RenderTexture2D : Type := RenderTexture

/-- Camera type fallback, defaults to Camera3D -/
abbrev Camera : Type := Camera3D

end Raylib
