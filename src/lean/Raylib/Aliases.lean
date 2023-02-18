import Raylib.Structures

namespace Raylib

/-! # Aliases -/
/-- Quaternion, 4 components (Vector4 alias) -/
abbrev Quaternion : Type := Vector4
-- /-- Texture2D, same as Texture -/
-- abbrev Texture2D : Type := Texture
-- /-- TextureCubemap, same as Texture -/
-- abbrev TextureCubemap : Type := Texture
-- /-- RenderTexture2D, same as RenderTexture -/
-- abbrev RenderTexture2D : Type := RenderTexture
/-- Camera type fallback, defaults to Camera3D -/
abbrev Camera : Type := Camera3D

end Raylib
