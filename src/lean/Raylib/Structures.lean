import Raylib.Enumerations

set_option autoImplicit false

namespace Raylib

/-! # Vectors -/

/-! ## Vector2 -/

opaque Vector2Pointed : NonemptyType
/-- Vector2, 2 components -/
def Vector2 : Type := Vector2Pointed.type
instance : Nonempty Vector2 := Vector2Pointed.property

@[extern "lean_raylib__Vector2_mk"]
opaque Vector2.mk (x : Float) (y : Float) : Vector2

/-- Getter: Vector x component -/
@[extern "lean_raylib__Vector2_x"]
opaque Vector2.x (vector : @& Vector2) : Float

/-- Setter: Vector x component -/
@[extern "lean_raylib__Vector2_x_set"]
opaque Vector2.set_x (x : Float) (vector : Vector2) : Vector2

/-- Getter: Vector y component -/
@[extern "lean_raylib__Vector2_y"]
opaque Vector2.y (vector : @& Vector2) : Float

/-- Setter: Vector y component -/
@[extern "lean_raylib__Vector2_y_set"]
opaque Vector2.set_y (y : Float) (vector : Vector2) : Vector2


/-! ## Vector3 -/

opaque Vector3Pointed : NonemptyType
/-- Vector3, 3 components -/
def Vector3 : Type := Vector3Pointed.type
instance : Nonempty Vector3 := Vector3Pointed.property

@[extern "lean_raylib__Vector3_mk"]
opaque Vector3.mk (x : Float) (y : Float) (z : Float) : Vector3

/-- Getter: Vector x component -/
@[extern "lean_raylib__Vector3_x"]
opaque Vector3.x (vector : @& Vector3) : Float

/-- Setter: Vector x component -/
@[extern "lean_raylib__Vector3_x_set"]
opaque Vector3.set_x (x : Float) (vector : Vector3) : Vector3

/-- Getter: Vector y component -/
@[extern "lean_raylib__Vector3_y"]
opaque Vector3.y (vector : @& Vector3) : Float

/-- Setter: Vector y component -/
@[extern "lean_raylib__Vector3_y_set"]
opaque Vector3.set_y (y : Float) (vector : Vector3) : Vector3

/-- Getter: Vector z component -/
@[extern "lean_raylib__Vector3_z"]
opaque Vector3.z (vector : @& Vector3) : Float

/-- Setter: Vector z component -/
@[extern "lean_raylib__Vector3_z_set"]
opaque Vector3.set_z (z : Float) (vector : Vector3) : Vector3


/-! ## Vector4 -/

opaque Vector4Pointed : NonemptyType
/-- Vector4, 4 components -/
def Vector4 : Type := Vector4Pointed.type
instance : Nonempty Vector4 := Vector4Pointed.property

@[extern "lean_raylib__Vector4_mk"]
opaque Vector4.mk (x : Float) (y : Float) (z : Float) (w : Float) : Vector4

/-- Getter: Vector x component -/
@[extern "lean_raylib__Vector4_x"]
opaque Vector4.x (vector : @& Vector4) : Float

/-- Setter: Vector x component -/
@[extern "lean_raylib__Vector4_x_set"]
opaque Vector4.set_x (x : Float) (vector : Vector4) : Vector4

/-- Getter: Vector y component -/
@[extern "lean_raylib__Vector4_y"]
opaque Vector4.y (vector : @& Vector4) : Float

/-- Setter: Vector y component -/
@[extern "lean_raylib__Vector4_y_set"]
opaque Vector4.set_y (y : Float) (vector : Vector4) : Vector4

/-- Getter: Vector z component -/
@[extern "lean_raylib__Vector4_z"]
opaque Vector4.z (vector : @& Vector4) : Float

/-- Setter: Vector z component -/
@[extern "lean_raylib__Vector4_z_set"]
opaque Vector4.set_z (z : Float) (vector : Vector4) : Vector4

/-- Getter: Vector w component -/
@[extern "lean_raylib__Vector4_w"]
opaque Vector4.w (vector : @& Vector4) : Float

/-- Setter: Vector w component -/
@[extern "lean_raylib__Vector4_w_set"]
opaque Vector4.set_w (w : Float) (vector : Vector4) : Vector4



/-! # Matrix -/

opaque MatrixPointed : NonemptyType
/-- Matrix, 4x4 components, column major, OpenGL style, right-handed -/
def Matrix : Type := MatrixPointed.type
instance : Nonempty Matrix := MatrixPointed.property

@[extern "lean_raylib__Matrix_mk"]
opaque Matrix.mk
  (m0 : Float) (m4 : Float) (m8  : Float) (m12 : Float)
  (m1 : Float) (m5 : Float) (m9  : Float) (m13 : Float)
  (m2 : Float) (m6 : Float) (m10 : Float) (m14 : Float)
  (m3 : Float) (m7 : Float) (m11 : Float) (m15 : Float)
  : Matrix

/-- Getter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m0"]
opaque Matrix.m0 (self : @& Matrix) : Float

/-- Setter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m0_set"]
opaque Matrix.set_m0 (m0 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m4"]
opaque Matrix.m4 (self : @& Matrix) : Float

/-- Setter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m4_set"]
opaque Matrix.set_m4 (m4 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m8"]
opaque Matrix.m8 (self : @& Matrix) : Float

/-- Setter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m8_set"]
opaque Matrix.set_m8 (m8 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m12"]
opaque Matrix.m12 (self : @& Matrix) : Float

/-- Setter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m12_set"]
opaque Matrix.set_m12 (m12 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m1"]
opaque Matrix.m1 (self : @& Matrix) : Float

/-- Setter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m1_set"]
opaque Matrix.set_m1 (m1 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m5"]
opaque Matrix.m5 (self : @& Matrix) : Float

/-- Setter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m5_set"]
opaque Matrix.set_m5 (m5 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m9"]
opaque Matrix.m9 (self : @& Matrix) : Float

/-- Setter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m9_set"]
opaque Matrix.set_m9 (m9 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m13"]
opaque Matrix.m13 (self : @& Matrix) : Float

/-- Setter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m13_set"]
opaque Matrix.set_m13 (m13 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m2"]
opaque Matrix.m2 (self : @& Matrix) : Float

/-- Setter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m2_set"]
opaque Matrix.set_m2 (m2 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m6"]
opaque Matrix.m6 (self : @& Matrix) : Float

/-- Setter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m6_set"]
opaque Matrix.set_m6 (m6 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m10"]
opaque Matrix.m10 (self : @& Matrix) : Float

/-- Setter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m10_set"]
opaque Matrix.set_m10 (m10 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m14"]
opaque Matrix.m14 (self : @& Matrix) : Float

/-- Setter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m14_set"]
opaque Matrix.set_m14 (m14 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m3"]
opaque Matrix.m3 (self : @& Matrix) : Float

/-- Setter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m3_set"]
opaque Matrix.set_m3 (m3 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m7"]
opaque Matrix.m7 (self : @& Matrix) : Float

/-- Setter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m7_set"]
opaque Matrix.set_m7 (m7 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m11"]
opaque Matrix.m11 (self : @& Matrix) : Float

/-- Setter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m11_set"]
opaque Matrix.set_m11 (m11 : Float) (matrix : Matrix) : Matrix

/-- Getter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m15"]
opaque Matrix.m15 (self : @& Matrix) : Float

/-- Setter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m15_set"]
opaque Matrix.set_m15 (m15 : Float) (matrix : Matrix) : Matrix



/-! # Color -/

/-- Color, 4 components, R8G8B8A8 (32bit) -/
structure Color where
  /-- Color components encoded in a single `UInt32`, little endian. -/
  rgba : UInt32
deriving Inhabited, Repr

def Color.fromRgba (r : UInt8) (g : UInt8) (b : UInt8) (a : UInt8) : Color := Color.mk ((.|||.) r.toUInt32 ((.|||.) ((.<<<.) g.toUInt32 8) ((.|||.) ((.<<<.) b.toUInt32 16) ((.<<<.) a.toUInt32 24))))
/-- Returns the red component of the color -/
def Color.r (color : Color) : UInt8 := (Color.rgba color).toUInt8
/-- Returns the red component of the color -/
def Color.g (color : Color) : UInt8 := (Color.rgba color >>> 8).toUInt8
/-- Returns the red component of the color -/
def Color.b (color : Color) : UInt8 := (Color.rgba color >>> 16).toUInt8
/-- Returns the red component of the color -/
def Color.a (color : Color) : UInt8 := (Color.rgba color >>> 24).toUInt8
/-- Return the color with the red component replaced by the passed value -/
def Color.setR (x : UInt8) (color : Color) : Color := Color.mk ((color.rgba &&& ⟨0xFFFFFF00, by simp⟩) ||| x.toUInt32)
/-- Return the color with the red component replaced by the passed value -/
def Color.setG (x : UInt8) (color : Color) : Color := Color.mk ((color.rgba &&& ⟨0xFFFF00FF, by simp⟩) ||| (x.toUInt32 <<< 8))
/-- Return the color with the red component replaced by the passed value -/
def Color.setB (x : UInt8) (color : Color) : Color := Color.mk ((color.rgba &&& ⟨0xFF00FFFF, by simp⟩) ||| (x.toUInt32 <<< 16))
/-- Return the color with the red component replaced by the passed value -/
def Color.setA (x : UInt8) (color : Color) : Color := Color.mk ((color.rgba &&& ⟨0x00FFFFFF, by simp⟩) ||| (x.toUInt32 <<< 24))


-- # Rectangle

opaque RectanglePointed : NonemptyType
/-- Rectangle, 4 components -/
def Rectangle : Type := RectanglePointed.type
instance : Nonempty Rectangle := RectanglePointed.property

@[extern "lean_raylib__Rectangle_mk"]
opaque Rectangle.mk (x : Float) (y : Float) (width : Float) (height : Float) : Rectangle

/-- Getter: Rectangle top-left corner position x -/
@[extern "lean_raylib__Rectangle_x"]
opaque Rectangle.x (self : @& Rectangle) : Float

/-- Setter: Rectangle top-left corner position x -/
@[extern "lean_raylib__Rectangle_x_set"]
opaque Rectangle.set_x (x : Float) (rectangle : Rectangle) : Rectangle

/-- Getter: Rectangle top-left corner position y -/
@[extern "lean_raylib__Rectangle_y"]
opaque Rectangle.y (self : @& Rectangle) : Float

/-- Setter: Rectangle top-left corner position y -/
@[extern "lean_raylib__Rectangle_y_set"]
opaque Rectangle.set_y (y : Float) (rectangle : Rectangle) : Rectangle

/-- Getter: Rectangle width -/
@[extern "lean_raylib__Rectangle_width"]
opaque Rectangle.width (self : @& Rectangle) : Float

/-- Setter: Rectangle width -/
@[extern "lean_raylib__Rectangle_width_set"]
opaque Rectangle.set_width (width : Float) (rectangle : Rectangle) : Rectangle

/-- Getter: Rectangle height -/
@[extern "lean_raylib__Rectangle_height"]
opaque Rectangle.height (self : @& Rectangle) : Float

/-- Setter: Rectangle height -/
@[extern "lean_raylib__Rectangle_height_set"]
opaque Rectangle.set_height (height : Float) (rectangle : Rectangle) : Rectangle


/-! # Image -/

opaque ImagePointed : NonemptyType
/-- Image, pixel data stored in CPU memory (RAM) -/
def Image : Type := ImagePointed.type
instance : Nonempty Image := ImagePointed.property

@[extern "lean_raylib__Image_default"]
opaque Image.empty (_ : Unit) : Image

@[extern "lean_raylib__Image_mk"]
unsafe opaque Image.mk
  (data : ByteArray) (width : UInt32) (height : UInt32)
  (mipmaps : UInt32) (format : PixelFormat) : Image

/-- Getter: Image base width -/
@[extern "lean_raylib__Image_width"]
opaque Image.width (self : @& Image) : UInt32

/-- Getter: Image base height -/
@[extern "lean_raylib__Image_height"]
opaque Image.height (self : @& Image) : UInt32

/-- Getter: Mipmap levels, 1 by default -/
@[extern "lean_raylib__Image_mipmaps"]
opaque Image.mipmaps (self : @& Image) : UInt32

/-- Getter: Data format (PixelFormat type) -/
@[extern "lean_raylib__Image_format"]
opaque Image.format (self : @& Image) : PixelFormat


/-! # Texture -/

opaque TextureRefPointed : NonemptyType
/--
Reference to `Texture`,
may be a `Texture` or a part of a bigger object like `RenderTexture`.
-/
def TextureRef : Type := TextureRefPointed.type
instance : Nonempty TextureRef := TextureRefPointed.property

opaque TexturePointed : NonemptyType
/-- Texture, tex data stored in GPU memory (VRAM) -/
def Texture : Type := TexturePointed.type
instance : Nonempty Texture := TexturePointed.property

@[extern "lean_raylib__Texture_ref"]
opaque Texture.ref (texture : Texture) : TextureRef

@[extern "lean_raylib__TextureRef_id"]
opaque TextureRef.id (texture : @& TextureRef) : UInt32

/-- Texture base width -/
@[extern "lean_raylib__TextureRef_width"]
opaque TextureRef.width (texture : @& TextureRef) : UInt32

/-- Texture base height -/
@[extern "lean_raylib__TextureRef_height"]
opaque TextureRef.height (texture : @& TextureRef) : UInt32

/-- Mipmap levels, 1 by default -/
@[extern "lean_raylib__TextureRef_mipmaps"]
opaque TextureRef.mipmaps (texture : @& TextureRef) : UInt32

/-- Data format -/
@[extern "lean_raylib__TextureRef_format"]
opaque TextureRef.format (texture : @& TextureRef) : PixelFormat


/-! # Render texture -/

opaque RenderTexturePointed : NonemptyType
/-- RenderTexture, fbo for texture rendering -/
def RenderTexture : Type := RenderTexturePointed.type
instance : Nonempty RenderTexture := RenderTexturePointed.property

@[extern "lean_raylib__RenderTexture_id"]
opaque RenderTexture.id (texture : @& RenderTexture) : UInt32

/-- Color buffer attachment texture -/
@[extern "lean_raylib__RenderTexture_texture"]
opaque RenderTexture.texture (rt : RenderTexture) : TextureRef


/-! # NPatch info -/

opaque NPatchInfoPointed : NonemptyType
/-- NPatchInfo, n-patch layout info -/
def NPatchInfo : Type := NPatchInfoPointed.type
instance : Nonempty NPatchInfo := NPatchInfoPointed.property

@[extern "lean_raylib__NPatchInfo_mk"]
opaque NPatchInfo.mk (source : @& Rectangle) (left : UInt32) (top : UInt32)
  (right : UInt32) (bottom : UInt32) (layout : NPatchLayout) : NPatchInfo

/-- Getter: Texture source rectangle -/
@[extern "lean_raylib__NPatchInfo_source"]
opaque NPatchInfo.source (npatchInfo : @& NPatchInfo) : Rectangle
/-- Setter: Texture source rectangle -/
@[extern "lean_raylib__NPatchInfo_source_set"]
opaque NPatchInfo.set_source (source : Rectangle) (npatchInfo : NPatchInfo) : NPatchInfo
/-- Getter: Left border offset -/
@[extern "lean_raylib__NPatchInfo_left"]
opaque NPatchInfo.left (npatchInfo : @& NPatchInfo) : UInt32
/-- Setter: Left border offset -/
@[extern "lean_raylib__NPatchInfo_left_set"]
opaque NPatchInfo.set_left (left : UInt32) (npatchInfo : NPatchInfo) : NPatchInfo
/-- Getter: Top border offset -/
@[extern "lean_raylib__NPatchInfo_top"]
opaque NPatchInfo.top (npatchInfo : @& NPatchInfo) : UInt32
/-- Setter: Top border offset -/
@[extern "lean_raylib__NPatchInfo_top_set"]
opaque NPatchInfo.set_top (top : UInt32) (npatchInfo : NPatchInfo) : NPatchInfo
/-- Getter: Right border offset -/
@[extern "lean_raylib__NPatchInfo_right"]
opaque NPatchInfo.right (npatchInfo : @& NPatchInfo) : UInt32
/-- Setter: Right border offset -/
@[extern "lean_raylib__NPatchInfo_right_set"]
opaque NPatchInfo.set_right (right : UInt32) (npatchInfo : NPatchInfo) : NPatchInfo
/-- Getter: Bottom border offset -/
@[extern "lean_raylib__NPatchInfo_bottom"]
opaque NPatchInfo.bottom (npatchInfo : @& NPatchInfo) : UInt32
/-- Setter: Bottom border offset -/
@[extern "lean_raylib__NPatchInfo_bottom_set"]
opaque NPatchInfo.set_bottom (bottom : UInt32) (npatchInfo : NPatchInfo) : NPatchInfo
/-- Getter: Layout of the n-patch: 3x3, 1x3 or 3x1 -/
@[extern "lean_raylib__NPatchInfo_layout"]
opaque NPatchInfo.layout (npatchInfo : @& NPatchInfo) : NPatchLayout
/-- Setter: Layout of the n-patch: 3x3, 1x3 or 3x1 -/
@[extern "lean_raylib__NPatchInfo_layout_set"]
opaque NPatchInfo.set_layout (layout : NPatchLayout) (npatchInfo : NPatchInfo) : NPatchInfo


/-! # Glyph info -/

-- opaque GlyphInfoPointed : NonemptyType
-- /-- GlyphInfo, font characters glyphs info -/
-- def GlyphInfo : Type := GlyphInfoPointed.type
-- instance : Nonempty GlyphInfo := GlyphInfoPointed.property
-- @[extern "lean_raylib__GlyphInfo_mk"]
-- opaque GlyphInfo.mk (value : Int32) (offsetX : Int32) (offsetY : Int32) (advanceX : Int32) (image : Image) : GlyphInfo
-- /-- Getter: Character value (Unicode) -/
-- @[extern "lean_raylib__GlyphInfo_value"]
-- opaque GlyphInfo.value (self : @& GlyphInfo) : Int32
-- /-- Setter: Character value (Unicode) -/
-- @[extern "lean_raylib__GlyphInfo_value_set"]
-- opaque GlyphInfo.set_value (value : Int32) (self : GlyphInfo) : GlyphInfo
-- /-- Getter: Character offset X when drawing -/
-- @[extern "lean_raylib__GlyphInfo_offsetX"]
-- opaque GlyphInfo.offsetX (self : @& GlyphInfo) : Int32
-- /-- Setter: Character offset X when drawing -/
-- @[extern "lean_raylib__GlyphInfo_offsetX_set"]
-- opaque GlyphInfo.set_offsetX (offsetX : Int32) (self : GlyphInfo) : GlyphInfo
-- /-- Getter: Character offset Y when drawing -/
-- @[extern "lean_raylib__GlyphInfo_offsetY"]
-- opaque GlyphInfo.offsetY (self : @& GlyphInfo) : Int32
-- /-- Setter: Character offset Y when drawing -/
-- @[extern "lean_raylib__GlyphInfo_offsetY_set"]
-- opaque GlyphInfo.set_offsetY (offsetY : Int32) (self : GlyphInfo) : GlyphInfo
-- /-- Getter: Character advance position X -/
-- @[extern "lean_raylib__GlyphInfo_advanceX"]
-- opaque GlyphInfo.advanceX (self : @& GlyphInfo) : Int32
-- /-- Setter: Character advance position X -/
-- @[extern "lean_raylib__GlyphInfo_advanceX_set"]
-- opaque GlyphInfo.set_advanceX (advanceX : Int32) (self : GlyphInfo) : GlyphInfo
-- /-- Getter: Character image data -/
-- @[extern "lean_raylib__GlyphInfo_image"]
-- opaque GlyphInfo.image (self : @& GlyphInfo) : Image
-- /-- Setter: Character image data -/
-- @[extern "lean_raylib__GlyphInfo_image_set"]
-- opaque GlyphInfo.set_image (image : Image) (self : GlyphInfo) : GlyphInfo
-- opaque FontPointed : NonemptyType
-- /-- Font, font texture and GlyphInfo array data -/
-- def Font : Type := FontPointed.type
-- instance : Nonempty Font := FontPointed.property
-- @[extern "lean_raylib__Font_mk"]
-- opaque Font.mk : Font
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | baseSize: int -- Base size (default chars height)
--   | glyphCount: int -- Number of glyph characters
--   | glyphPadding: int -- Padding around the glyph characters
--   | texture: Texture2D -- Texture atlas containing the glyphs
--   | recs: Rectangle * -- Rectangles in texture for the glyphs
--   | glyphs: GlyphInfo * -- Glyphs info data
-- -/
-- /-- Getter: Base size (default chars height) -/
-- @[extern "lean_raylib__Font_baseSize"]
-- opaque Font.baseSize (self : @& Font) : Int32
-- /-- Setter: Base size (default chars height) -/
-- @[extern "lean_raylib__Font_baseSize_set"]
-- opaque Font.set_baseSize (baseSize : Int32) (self : Font) : Font
-- /-- Getter: Number of glyph characters -/
-- @[extern "lean_raylib__Font_glyphCount"]
-- opaque Font.glyphCount (self : @& Font) : Int32
-- /-- Setter: Number of glyph characters -/
-- @[extern "lean_raylib__Font_glyphCount_set"]
-- opaque Font.set_glyphCount (glyphCount : Int32) (self : Font) : Font
-- /-- Getter: Padding around the glyph characters -/
-- @[extern "lean_raylib__Font_glyphPadding"]
-- opaque Font.glyphPadding (self : @& Font) : Int32
-- /-- Setter: Padding around the glyph characters -/
-- @[extern "lean_raylib__Font_glyphPadding_set"]
-- opaque Font.set_glyphPadding (glyphPadding : Int32) (self : Font) : Font
-- /-- Getter: Texture atlas containing the glyphs -/
-- @[extern "lean_raylib__Font_texture"]
-- opaque Font.texture (self : @& Font) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Texture atlas containing the glyphs -/
-- @[extern "lean_raylib__Font_texture_set"]
-- opaque Font.set_texture (texture : Unit) (self : Font) : Font
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Rectangles in texture for the glyphs -/
-- @[extern "lean_raylib__Font_recs"]
-- opaque Font.recs (self : @& Font) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Rectangles in texture for the glyphs -/
-- @[extern "lean_raylib__Font_recs_set"]
-- opaque Font.set_recs (recs : Unit) (self : Font) : Font
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Glyphs info data -/
-- @[extern "lean_raylib__Font_glyphs"]
-- opaque Font.glyphs (self : @& Font) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Glyphs info data -/
-- @[extern "lean_raylib__Font_glyphs_set"]
-- opaque Font.set_glyphs (glyphs : Unit) (self : Font) : Font
-- /-
-- todo: ^^ struct setter ^^
-- -/


/-! # Camera 3D -/

opaque Camera3DPointed : NonemptyType
/-- Camera, defines position/orientation in 3d space -/
def Camera3D : Type := Camera3DPointed.type
instance : Nonempty Camera3D := Camera3DPointed.property

@[extern "lean_raylib__Camera3D_mk"]
opaque Camera3D.mk
  (position : @& Vector3) (target : @& Vector3) (up : @& Vector3)
  (fovy : Float) (projection : CameraProjection)
  : Camera3D

/-- Getter: Camera position -/
@[extern "lean_raylib__Camera3D_position"]
opaque Camera3D.position (cam3d : @& Camera3D) : Vector3
/-- Setter: Camera position -/
@[extern "lean_raylib__Camera3D_position_set"]
opaque Camera3D.set_position (position : @& Vector3) (cam3d : Camera3D) : Camera3D
/-- Getter: Camera target it looks-at -/
@[extern "lean_raylib__Camera3D_target"]
opaque Camera3D.target (cam3d : @& Camera3D) : Vector3
/-- Setter: Camera target it looks-at -/
@[extern "lean_raylib__Camera3D_target_set"]
opaque Camera3D.set_target (target : @& Vector3) (cam3d : Camera3D) : Camera3D
/-- Getter: Camera up vector (rotation over its axis) -/
@[extern "lean_raylib__Camera3D_up"]
opaque Camera3D.up (cam3d : @& Camera3D) : Vector3
/-- Setter: Camera up vector (rotation over its axis) -/
@[extern "lean_raylib__Camera3D_up_set"]
opaque Camera3D.set_up (up : @& Vector3) (cam3d : Camera3D) : Camera3D
/-- Getter: Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic -/
@[extern "lean_raylib__Camera3D_fovy"]
opaque Camera3D.fovy (cam3d : @& Camera3D) : Float
/-- Setter: Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic -/
@[extern "lean_raylib__Camera3D_fovy_set"]
opaque Camera3D.set_fovy (fovy : Float) (cam3d : Camera3D) : Camera3D
/-- Getter: Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC -/
@[extern "lean_raylib__Camera3D_projection"]
opaque Camera3D.projection (cam3d : @& Camera3D) : CameraProjection
/-- Setter: Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC -/
@[extern "lean_raylib__Camera3D_projection_set"]
opaque Camera3D.set_projection (projection : CameraProjection) (cam3d : Camera3D) : Camera3D


/-! # Camera 2D -/

opaque Camera2DPointed : NonemptyType
/-- Camera2D, defines position/orientation in 2d space -/
def Camera2D : Type := Camera2DPointed.type
instance : Nonempty Camera2D := Camera2DPointed.property

@[extern "lean_raylib__Camera2D_mk"]
opaque Camera2D.mk (offset : @& Vector2) (target : @& Vector2) (rotation : Float) (zoom : Float) : Camera2D

/-- Getter: Camera offset (displacement from target) -/
@[extern "lean_raylib__Camera2D_offset"]
opaque Camera2D.offset (cam2d : @& Camera2D) : Vector2
/-- Setter: Camera offset (displacement from target) -/
@[extern "lean_raylib__Camera2D_offset_set"]
opaque Camera2D.set_offset (offset : @& Vector2) (cam2d : Camera2D) : Camera2D
/-- Getter: Camera target (rotation and zoom origin) -/
@[extern "lean_raylib__Camera2D_target"]
opaque Camera2D.target (cam2d : @& Camera2D) : Vector2
/-- Setter: Camera target (rotation and zoom origin) -/
@[extern "lean_raylib__Camera2D_target_set"]
opaque Camera2D.set_target (target : @& Vector2) (cam2d : Camera2D) : Camera2D
/-- Getter: Camera rotation in degrees -/
@[extern "lean_raylib__Camera2D_rotation"]
opaque Camera2D.rotation (cam2d : @& Camera2D) : Float
/-- Setter: Camera rotation in degrees -/
@[extern "lean_raylib__Camera2D_rotation_set"]
opaque Camera2D.set_rotation (rotation : Float) (cam2d : Camera2D) : Camera2D
/-- Getter: Camera zoom (scaling), should be 1.0f by default -/
@[extern "lean_raylib__Camera2D_zoom"]
opaque Camera2D.zoom (cam2d : @& Camera2D) : Float
/-- Setter: Camera zoom (scaling), should be 1.0f by default -/
@[extern "lean_raylib__Camera2D_zoom_set"]
opaque Camera2D.set_zoom (zoom : Float) (cam2d : Camera2D) : Camera2D


/-! # Mesh -/

-- opaque MeshPointed : NonemptyType
-- /-- Mesh, vertex data and vao/vbo -/
-- def Mesh : Type := MeshPointed.type
-- instance : Nonempty Mesh := MeshPointed.property
-- @[extern "lean_raylib__Mesh_mk"]
-- opaque Mesh.mk : Mesh
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | vertexCount: int -- Number of vertices stored in arrays
--   | triangleCount: int -- Number of triangles stored (indexed or not)
--   | vertices: float * -- Vertex position (XYZ - 3 components per vertex) (shader-location = 0)
--   | texcoords: float * -- Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1)
--   | texcoords2: float * -- Vertex texture second coordinates (UV - 2 components per vertex) (shader-location = 5)
--   | normals: float * -- Vertex normals (XYZ - 3 components per vertex) (shader-location = 2)
--   | tangents: float * -- Vertex tangents (XYZW - 4 components per vertex) (shader-location = 4)
--   | colors: unsigned char * -- Vertex colors (RGBA - 4 components per vertex) (shader-location = 3)
--   | indices: unsigned short * -- Vertex indices (in case vertex data comes indexed)
--   | animVertices: float * -- Animated vertex positions (after bones transformations)
--   | animNormals: float * -- Animated normals (after bones transformations)
--   | boneIds: unsigned char * -- Vertex bone ids, max 255 bone ids, up to 4 bones influence by vertex (skinning)
--   | boneWeights: float * -- Vertex bone weight, up to 4 bones influence by vertex (skinning)
--   | vaoId: unsigned int -- OpenGL Vertex Array Object id
--   | vboId: unsigned int * -- OpenGL Vertex Buffer Objects id (default vertex data)
-- -/
-- /-- Getter: Number of vertices stored in arrays -/
-- @[extern "lean_raylib__Mesh_vertexCount"]
-- opaque Mesh.vertexCount (self : @& Mesh) : Int32
-- /-- Setter: Number of vertices stored in arrays -/
-- @[extern "lean_raylib__Mesh_vertexCount_set"]
-- opaque Mesh.set_vertexCount (vertexCount : Int32) (self : Mesh) : Mesh
-- /-- Getter: Number of triangles stored (indexed or not) -/
-- @[extern "lean_raylib__Mesh_triangleCount"]
-- opaque Mesh.triangleCount (self : @& Mesh) : Int32
-- /-- Setter: Number of triangles stored (indexed or not) -/
-- @[extern "lean_raylib__Mesh_triangleCount_set"]
-- opaque Mesh.set_triangleCount (triangleCount : Int32) (self : Mesh) : Mesh
-- /-- Getter: Vertex position (XYZ - 3 components per vertex) (shader-location = 0) -/
-- @[extern "lean_raylib__Mesh_vertices"]
-- opaque Mesh.vertices (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex position (XYZ - 3 components per vertex) (shader-location = 0) -/
-- @[extern "lean_raylib__Mesh_vertices_set"]
-- opaque Mesh.set_vertices (vertices : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1) -/
-- @[extern "lean_raylib__Mesh_texcoords"]
-- opaque Mesh.texcoords (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1) -/
-- @[extern "lean_raylib__Mesh_texcoords_set"]
-- opaque Mesh.set_texcoords (texcoords : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Vertex texture second coordinates (UV - 2 components per vertex) (shader-location = 5) -/
-- @[extern "lean_raylib__Mesh_texcoords2"]
-- opaque Mesh.texcoords2 (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex texture second coordinates (UV - 2 components per vertex) (shader-location = 5) -/
-- @[extern "lean_raylib__Mesh_texcoords2_set"]
-- opaque Mesh.set_texcoords2 (texcoords2 : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Vertex normals (XYZ - 3 components per vertex) (shader-location = 2) -/
-- @[extern "lean_raylib__Mesh_normals"]
-- opaque Mesh.normals (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex normals (XYZ - 3 components per vertex) (shader-location = 2) -/
-- @[extern "lean_raylib__Mesh_normals_set"]
-- opaque Mesh.set_normals (normals : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Vertex tangents (XYZW - 4 components per vertex) (shader-location = 4) -/
-- @[extern "lean_raylib__Mesh_tangents"]
-- opaque Mesh.tangents (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex tangents (XYZW - 4 components per vertex) (shader-location = 4) -/
-- @[extern "lean_raylib__Mesh_tangents_set"]
-- opaque Mesh.set_tangents (tangents : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Vertex colors (RGBA - 4 components per vertex) (shader-location = 3) -/
-- @[extern "lean_raylib__Mesh_colors"]
-- opaque Mesh.colors (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex colors (RGBA - 4 components per vertex) (shader-location = 3) -/
-- @[extern "lean_raylib__Mesh_colors_set"]
-- opaque Mesh.set_colors (colors : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Vertex indices (in case vertex data comes indexed) -/
-- @[extern "lean_raylib__Mesh_indices"]
-- opaque Mesh.indices (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex indices (in case vertex data comes indexed) -/
-- @[extern "lean_raylib__Mesh_indices_set"]
-- opaque Mesh.set_indices (indices : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Animated vertex positions (after bones transformations) -/
-- @[extern "lean_raylib__Mesh_animVertices"]
-- opaque Mesh.animVertices (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Animated vertex positions (after bones transformations) -/
-- @[extern "lean_raylib__Mesh_animVertices_set"]
-- opaque Mesh.set_animVertices (animVertices : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Animated normals (after bones transformations) -/
-- @[extern "lean_raylib__Mesh_animNormals"]
-- opaque Mesh.animNormals (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Animated normals (after bones transformations) -/
-- @[extern "lean_raylib__Mesh_animNormals_set"]
-- opaque Mesh.set_animNormals (animNormals : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Vertex bone ids, max 255 bone ids, up to 4 bones influence by vertex (skinning) -/
-- @[extern "lean_raylib__Mesh_boneIds"]
-- opaque Mesh.boneIds (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex bone ids, max 255 bone ids, up to 4 bones influence by vertex (skinning) -/
-- @[extern "lean_raylib__Mesh_boneIds_set"]
-- opaque Mesh.set_boneIds (boneIds : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Vertex bone weight, up to 4 bones influence by vertex (skinning) -/
-- @[extern "lean_raylib__Mesh_boneWeights"]
-- opaque Mesh.boneWeights (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Vertex bone weight, up to 4 bones influence by vertex (skinning) -/
-- @[extern "lean_raylib__Mesh_boneWeights_set"]
-- opaque Mesh.set_boneWeights (boneWeights : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: OpenGL Vertex Array Object id -/
-- @[extern "lean_raylib__Mesh_vaoId"]
-- opaque Mesh.vaoId (self : @& Mesh) : UInt32
-- /-- Setter: OpenGL Vertex Array Object id -/
-- @[extern "lean_raylib__Mesh_vaoId_set"]
-- opaque Mesh.set_vaoId (vaoId : UInt32) (self : Mesh) : Mesh
-- /-- Getter: OpenGL Vertex Buffer Objects id (default vertex data) -/
-- @[extern "lean_raylib__Mesh_vboId"]
-- opaque Mesh.vboId (self : @& Mesh) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: OpenGL Vertex Buffer Objects id (default vertex data) -/
-- @[extern "lean_raylib__Mesh_vboId_set"]
-- opaque Mesh.set_vboId (vboId : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/


/-! # Shader -/

-- opaque ShaderPointed : NonemptyType
-- /-- Shader -/
-- def Shader : Type := ShaderPointed.type
-- instance : Nonempty Shader := ShaderPointed.property
-- @[extern "lean_raylib__Shader_mk"]
-- opaque Shader.mk : Shader
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | id: unsigned int -- Shader program id
--   | locs: int * -- Shader locations array (RL_MAX_SHADER_LOCATIONS)
-- -/
-- /-- Getter: Shader program id -/
-- @[extern "lean_raylib__Shader_id"]
-- opaque Shader.id (self : @& Shader) : UInt32
-- /-- Setter: Shader program id -/
-- @[extern "lean_raylib__Shader_id_set"]
-- opaque Shader.set_id (id : UInt32) (self : Shader) : Shader
-- /-- Getter: Shader locations array (RL_MAX_SHADER_LOCATIONS) -/
-- @[extern "lean_raylib__Shader_locs"]
-- opaque Shader.locs (self : @& Shader) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Shader locations array (RL_MAX_SHADER_LOCATIONS) -/
-- @[extern "lean_raylib__Shader_locs_set"]
-- opaque Shader.set_locs (locs : Unit) (self : Shader) : Shader
-- /-
-- todo: ^^ struct setter ^^
-- -/


/-! # Material map -/

-- opaque MaterialMapPointed : NonemptyType
-- /-- MaterialMap -/
-- def MaterialMap : Type := MaterialMapPointed.type
-- instance : Nonempty MaterialMap := MaterialMapPointed.property
-- @[extern "lean_raylib__MaterialMap_mk"]
-- opaque MaterialMap.mk : MaterialMap
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | texture: Texture2D -- Material map texture
--   | color: Color -- Material map color
--   | value: float -- Material map value
-- -/
-- /-- Getter: Material map texture -/
-- @[extern "lean_raylib__MaterialMap_texture"]
-- opaque MaterialMap.texture (self : @& MaterialMap) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Material map texture -/
-- @[extern "lean_raylib__MaterialMap_texture_set"]
-- opaque MaterialMap.set_texture (texture : Unit) (self : MaterialMap) : MaterialMap
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Material map color -/
-- @[extern "lean_raylib__MaterialMap_color"]
-- opaque MaterialMap.color (self : @& MaterialMap) : Color
-- /-- Setter: Material map color -/
-- @[extern "lean_raylib__MaterialMap_color_set"]
-- opaque MaterialMap.set_color (color : Color) (self : MaterialMap) : MaterialMap
-- /-- Getter: Material map value -/
-- @[extern "lean_raylib__MaterialMap_value"]
-- opaque MaterialMap.value (self : @& MaterialMap) : Float
-- /-- Setter: Material map value -/
-- @[extern "lean_raylib__MaterialMap_value_set"]
-- opaque MaterialMap.set_value (value : Float) (self : MaterialMap) : MaterialMap


/-! # Material -/

-- opaque MaterialPointed : NonemptyType
-- /-- Material, includes shader and maps -/
-- def Material : Type := MaterialPointed.type
-- instance : Nonempty Material := MaterialPointed.property
-- @[extern "lean_raylib__Material_mk"]
-- opaque Material.mk : Material
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | shader: Shader -- Material shader
--   | maps: MaterialMap * -- Material maps array (MAX_MATERIAL_MAPS)
--   | params: float[4] -- Material generic parameters (if required)
-- -/
-- /-- Getter: Material shader -/
-- @[extern "lean_raylib__Material_shader"]
-- opaque Material.shader (self : @& Material) : Shader
-- /-- Setter: Material shader -/
-- @[extern "lean_raylib__Material_shader_set"]
-- opaque Material.set_shader (shader : Shader) (self : Material) : Material
-- /-- Getter: Material maps array (MAX_MATERIAL_MAPS) -/
-- @[extern "lean_raylib__Material_maps"]
-- opaque Material.maps (self : @& Material) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Material maps array (MAX_MATERIAL_MAPS) -/
-- @[extern "lean_raylib__Material_maps_set"]
-- opaque Material.set_maps (maps : Unit) (self : Material) : Material
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Material generic parameters (if required) -/
-- @[extern "lean_raylib__Material_params"]
-- opaque Material.params (self : @& Material) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Material generic parameters (if required) -/
-- @[extern "lean_raylib__Material_params_set"]
-- opaque Material.set_params (params : Unit) (self : Material) : Material
-- /-
-- todo: ^^ struct setter ^^
-- -/


/-! # Transform -/

-- opaque TransformPointed : NonemptyType
-- /-- Transform, vertex transformation data -/
-- def Transform : Type := TransformPointed.type
-- instance : Nonempty Transform := TransformPointed.property
-- @[extern "lean_raylib__Transform_mk"]
-- opaque Transform.mk : Transform
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | translation: Vector3 -- Translation
--   | rotation: Quaternion -- Rotation
--   | scale: Vector3 -- Scale
-- -/
-- /-- Getter: Translation -/
-- @[extern "lean_raylib__Transform_translation"]
-- opaque Transform.translation (self : @& Transform) : Vector3
-- /-- Setter: Translation -/
-- @[extern "lean_raylib__Transform_translation_set"]
-- opaque Transform.set_translation (translation : Vector3) (self : Transform) : Transform
-- /-- Getter: Rotation -/
-- @[extern "lean_raylib__Transform_rotation"]
-- opaque Transform.rotation (self : @& Transform) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Rotation -/
-- @[extern "lean_raylib__Transform_rotation_set"]
-- opaque Transform.set_rotation (rotation : Unit) (self : Transform) : Transform
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Scale -/
-- @[extern "lean_raylib__Transform_scale"]
-- opaque Transform.scale (self : @& Transform) : Vector3
-- /-- Setter: Scale -/
-- @[extern "lean_raylib__Transform_scale_set"]
-- opaque Transform.set_scale (scale : Vector3) (self : Transform) : Transform


/-! # Bone info -/

-- opaque BoneInfoPointed : NonemptyType
-- /-- Bone, skeletal animation bone -/
-- def BoneInfo : Type := BoneInfoPointed.type
-- instance : Nonempty BoneInfo := BoneInfoPointed.property
-- @[extern "lean_raylib__BoneInfo_mk"]
-- opaque BoneInfo.mk : BoneInfo
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | name: char[32] -- Bone name
--   | parent: int -- Bone parent
-- -/
-- /-- Getter: Bone name -/
-- @[extern "lean_raylib__BoneInfo_name"]
-- opaque BoneInfo.name (self : @& BoneInfo) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Bone name -/
-- @[extern "lean_raylib__BoneInfo_name_set"]
-- opaque BoneInfo.set_name (name : Unit) (self : BoneInfo) : BoneInfo
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Bone parent -/
-- @[extern "lean_raylib__BoneInfo_parent"]
-- opaque BoneInfo.parent (self : @& BoneInfo) : Int32
-- /-- Setter: Bone parent -/
-- @[extern "lean_raylib__BoneInfo_parent_set"]
-- opaque BoneInfo.set_parent (parent : Int32) (self : BoneInfo) : BoneInfo


/-! # Model -/

-- opaque ModelPointed : NonemptyType
-- /-- Model, meshes, materials and animation data -/
-- def Model : Type := ModelPointed.type
-- instance : Nonempty Model := ModelPointed.property
-- @[extern "lean_raylib__Model_mk"]
-- opaque Model.mk : Model
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | transform: Matrix -- Local transform matrix
--   | meshCount: int -- Number of meshes
--   | materialCount: int -- Number of materials
--   | meshes: Mesh * -- Meshes array
--   | materials: Material * -- Materials array
--   | meshMaterial: int * -- Mesh material number
--   | boneCount: int -- Number of bones
--   | bones: BoneInfo * -- Bones information (skeleton)
--   | bindPose: Transform * -- Bones base transformation (pose)
-- -/
-- /-- Getter: Local transform matrix -/
-- @[extern "lean_raylib__Model_transform"]
-- opaque Model.transform (self : @& Model) : Matrix
-- /-- Setter: Local transform matrix -/
-- @[extern "lean_raylib__Model_transform_set"]
-- opaque Model.set_transform (transform : Matrix) (self : Model) : Model
-- /-- Getter: Number of meshes -/
-- @[extern "lean_raylib__Model_meshCount"]
-- opaque Model.meshCount (self : @& Model) : Int32
-- /-- Setter: Number of meshes -/
-- @[extern "lean_raylib__Model_meshCount_set"]
-- opaque Model.set_meshCount (meshCount : Int32) (self : Model) : Model
-- /-- Getter: Number of materials -/
-- @[extern "lean_raylib__Model_materialCount"]
-- opaque Model.materialCount (self : @& Model) : Int32
-- /-- Setter: Number of materials -/
-- @[extern "lean_raylib__Model_materialCount_set"]
-- opaque Model.set_materialCount (materialCount : Int32) (self : Model) : Model
-- /-- Getter: Meshes array -/
-- @[extern "lean_raylib__Model_meshes"]
-- opaque Model.meshes (self : @& Model) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Meshes array -/
-- @[extern "lean_raylib__Model_meshes_set"]
-- opaque Model.set_meshes (meshes : Unit) (self : Model) : Model
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Materials array -/
-- @[extern "lean_raylib__Model_materials"]
-- opaque Model.materials (self : @& Model) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Materials array -/
-- @[extern "lean_raylib__Model_materials_set"]
-- opaque Model.set_materials (materials : Unit) (self : Model) : Model
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Mesh material number -/
-- @[extern "lean_raylib__Model_meshMaterial"]
-- opaque Model.meshMaterial (self : @& Model) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Mesh material number -/
-- @[extern "lean_raylib__Model_meshMaterial_set"]
-- opaque Model.set_meshMaterial (meshMaterial : Unit) (self : Model) : Model
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Number of bones -/
-- @[extern "lean_raylib__Model_boneCount"]
-- opaque Model.boneCount (self : @& Model) : Int32
-- /-- Setter: Number of bones -/
-- @[extern "lean_raylib__Model_boneCount_set"]
-- opaque Model.set_boneCount (boneCount : Int32) (self : Model) : Model
-- /-- Getter: Bones information (skeleton) -/
-- @[extern "lean_raylib__Model_bones"]
-- opaque Model.bones (self : @& Model) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Bones information (skeleton) -/
-- @[extern "lean_raylib__Model_bones_set"]
-- opaque Model.set_bones (bones : Unit) (self : Model) : Model
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Bones base transformation (pose) -/
-- @[extern "lean_raylib__Model_bindPose"]
-- opaque Model.bindPose (self : @& Model) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Bones base transformation (pose) -/
-- @[extern "lean_raylib__Model_bindPose_set"]
-- opaque Model.set_bindPose (bindPose : Unit) (self : Model) : Model
-- /-
-- todo: ^^ struct setter ^^
-- -/


/-! # Model animation -/

-- opaque ModelAnimationPointed : NonemptyType
-- /-- ModelAnimation -/
-- def ModelAnimation : Type := ModelAnimationPointed.type
-- instance : Nonempty ModelAnimation := ModelAnimationPointed.property
-- @[extern "lean_raylib__ModelAnimation_mk"]
-- opaque ModelAnimation.mk : ModelAnimation
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | boneCount: int -- Number of bones
--   | frameCount: int -- Number of animation frames
--   | bones: BoneInfo * -- Bones information (skeleton)
--   | framePoses: Transform * * -- Poses array by frame
-- -/
-- /-- Getter: Number of bones -/
-- @[extern "lean_raylib__ModelAnimation_boneCount"]
-- opaque ModelAnimation.boneCount (self : @& ModelAnimation) : Int32
-- /-- Setter: Number of bones -/
-- @[extern "lean_raylib__ModelAnimation_boneCount_set"]
-- opaque ModelAnimation.set_boneCount (boneCount : Int32) (self : ModelAnimation) : ModelAnimation
-- /-- Getter: Number of animation frames -/
-- @[extern "lean_raylib__ModelAnimation_frameCount"]
-- opaque ModelAnimation.frameCount (self : @& ModelAnimation) : Int32
-- /-- Setter: Number of animation frames -/
-- @[extern "lean_raylib__ModelAnimation_frameCount_set"]
-- opaque ModelAnimation.set_frameCount (frameCount : Int32) (self : ModelAnimation) : ModelAnimation
-- /-- Getter: Bones information (skeleton) -/
-- @[extern "lean_raylib__ModelAnimation_bones"]
-- opaque ModelAnimation.bones (self : @& ModelAnimation) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Bones information (skeleton) -/
-- @[extern "lean_raylib__ModelAnimation_bones_set"]
-- opaque ModelAnimation.set_bones (bones : Unit) (self : ModelAnimation) : ModelAnimation
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Poses array by frame -/
-- @[extern "lean_raylib__ModelAnimation_framePoses"]
-- opaque ModelAnimation.framePoses (self : @& ModelAnimation) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Poses array by frame -/
-- @[extern "lean_raylib__ModelAnimation_framePoses_set"]
-- opaque ModelAnimation.set_framePoses (framePoses : Unit) (self : ModelAnimation) : ModelAnimation
-- /-
-- todo: ^^ struct setter ^^
-- -/


/-! # Ray -/

opaque RayPointed : NonemptyType
/-- Ray, ray for raycasting -/
def Ray : Type := RayPointed.type
instance : Nonempty Ray := RayPointed.property

@[extern "lean_raylib__Ray_mk"]
opaque Ray.mk (position : @& Vector3) (direction : @& Vector3) : Ray

/-- Getter: Ray position (origin) -/
@[extern "lean_raylib__Ray_position"]
opaque Ray.position (ray : @& Ray) : Vector3
/-- Setter: Ray position (origin) -/
@[extern "lean_raylib__Ray_position_set"]
opaque Ray.set_position (position : @& Vector3) (ray : Ray) : Ray
/-- Getter: Ray direction -/
@[extern "lean_raylib__Ray_direction"]
opaque Ray.direction (ray : @& Ray) : Vector3
/-- Setter: Ray direction -/
@[extern "lean_raylib__Ray_direction_set"]
opaque Ray.set_direction (direction : @& Vector3) (ray : Ray) : Ray


/-! # Ray collision -/

-- opaque RayCollisionPointed : NonemptyType
-- /-- RayCollision, ray hit information -/
-- def RayCollision : Type := RayCollisionPointed.type
-- instance : Nonempty RayCollision := RayCollisionPointed.property
-- @[extern "lean_raylib__RayCollision_mk"]
-- opaque RayCollision.mk (hit : Bool) (distance : Float) (point : Vector3) (normal : Vector3) : RayCollision
-- /-- Getter: Did the ray hit something? -/
-- @[extern "lean_raylib__RayCollision_hit"]
-- opaque RayCollision.hit (self : @& RayCollision) : Bool
-- /-- Setter: Did the ray hit something? -/
-- @[extern "lean_raylib__RayCollision_hit_set"]
-- opaque RayCollision.set_hit (hit : Bool) (self : RayCollision) : RayCollision
-- /-- Getter: Distance to the nearest hit -/
-- @[extern "lean_raylib__RayCollision_distance"]
-- opaque RayCollision.distance (self : @& RayCollision) : Float
-- /-- Setter: Distance to the nearest hit -/
-- @[extern "lean_raylib__RayCollision_distance_set"]
-- opaque RayCollision.set_distance (distance : Float) (self : RayCollision) : RayCollision
-- /-- Getter: Point of the nearest hit -/
-- @[extern "lean_raylib__RayCollision_point"]
-- opaque RayCollision.point (self : @& RayCollision) : Vector3
-- /-- Setter: Point of the nearest hit -/
-- @[extern "lean_raylib__RayCollision_point_set"]
-- opaque RayCollision.set_point (point : Vector3) (self : RayCollision) : RayCollision
-- /-- Getter: Surface normal of hit -/
-- @[extern "lean_raylib__RayCollision_normal"]
-- opaque RayCollision.normal (self : @& RayCollision) : Vector3
-- /-- Setter: Surface normal of hit -/
-- @[extern "lean_raylib__RayCollision_normal_set"]
-- opaque RayCollision.set_normal (normal : Vector3) (self : RayCollision) : RayCollision


/-! # Bounding box -/

opaque BoundingBoxPointed : NonemptyType
/-- BoundingBox -/
def BoundingBox : Type := BoundingBoxPointed.type
instance : Nonempty BoundingBox := BoundingBoxPointed.property

@[extern "lean_raylib__BoundingBox_mk"]
opaque BoundingBox.mk (min : @& Vector3) (max : @& Vector3) : BoundingBox

/-- Getter: Minimum vertex box-corner -/
@[extern "lean_raylib__BoundingBox_min"]
opaque BoundingBox.min (bbox : @& BoundingBox) : Vector3
/-- Setter: Minimum vertex box-corner -/
@[extern "lean_raylib__BoundingBox_min_set"]
opaque BoundingBox.set_min (min : @& Vector3) (bbox : BoundingBox) : BoundingBox
/-- Getter: Maximum vertex box-corner -/
@[extern "lean_raylib__BoundingBox_max"]
opaque BoundingBox.max (bbox : @& BoundingBox) : Vector3
/-- Setter: Maximum vertex box-corner -/
@[extern "lean_raylib__BoundingBox_max_set"]
opaque BoundingBox.set_max (max : @& Vector3) (bbox : BoundingBox) : BoundingBox


/-! # Wave -/

opaque WavePointed : NonemptyType
/-- Wave, audio wave data -/
def Wave : Type := WavePointed.type
instance : Nonempty Wave := WavePointed.property

/-- Getter: Total number of frames (considering channels) -/
@[extern "lean_raylib__Wave_frameCount"]
opaque Wave.frameCount (wave : @& Wave) : UInt32
/-- Getter: Frequency (samples per second) -/
@[extern "lean_raylib__Wave_sampleRate"]
opaque Wave.sampleRate (wave : @& Wave) : UInt32
/-- Getter: Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
@[extern "lean_raylib__Wave_sampleSize"]
opaque Wave.sampleSize (wave : @& Wave) : UInt32
/-- Getter: Number of channels (1-mono, 2-stereo, ...) -/
@[extern "lean_raylib__Wave_channels"]
opaque Wave.channels (wave : @& Wave) : UInt32


/-! # Audio stream -/

opaque AudioStreamPointed : NonemptyType
/-- AudioStream, custom audio stream -/
def AudioStream : Type := AudioStreamPointed.type
instance : Nonempty AudioStream := AudioStreamPointed.property

/-- Getter: Frequency (samples per second) -/
@[extern "lean_raylib__AudioStream_sampleRate"]
opaque AudioStream.sampleRate (self : @& AudioStream) : UInt32
/-- Getter: Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
@[extern "lean_raylib__AudioStream_sampleSize"]
opaque AudioStream.sampleSize (self : @& AudioStream) : UInt32
/-- Getter: Number of channels (1-mono, 2-stereo, ...) -/
@[extern "lean_raylib__AudioStream_channels"]
opaque AudioStream.channels (self : @& AudioStream) : UInt32


/-! # Sound -/

opaque SoundPointed : NonemptyType
/-- Sound -/
def Sound : Type := SoundPointed.type
instance : Nonempty Sound := SoundPointed.property

/-- Getter: Frequency (samples per second) -/
@[extern "lean_raylib__Sound_sampleRate"]
opaque Sound.sampleRate (sound : @& Sound) : UInt32
/-- Getter: Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
@[extern "lean_raylib__Sound_sampleSize"]
opaque Sound.sampleSize (sound : @& Sound) : UInt32
/-- Getter: Number of channels (1-mono, 2-stereo, ...) -/
@[extern "lean_raylib__Sound_channels"]
opaque Sound.channels (sound : @& Sound) : UInt32
/-- Getter: Total number of frames (considering channels) -/
@[extern "lean_raylib__Sound_frameCount"]
opaque Sound.frameCount (sound : @& Sound) : UInt32

/-! # Music -/

opaque MusicPointed : NonemptyType
/-- Music, audio stream, anything longer than ~10 seconds should be streamed -/
def Music : Type := MusicPointed.type
instance : Nonempty Music := MusicPointed.property

/-- Getter: Frequency (samples per second) -/
@[extern "lean_raylib__Sound_sampleRate"]
opaque Music.sampleRate (music : @& Music) : UInt32
/-- Getter: Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
@[extern "lean_raylib__Sound_sampleSize"]
opaque Music.sampleSize (music : @& Music) : UInt32
/-- Getter: Number of channels (1-mono, 2-stereo, ...) -/
@[extern "lean_raylib__Sound_channels"]
opaque Music.channels (music : @& Music) : UInt32
/-- Getter: Total number of frames (considering channels) -/
@[extern "lean_raylib__Music_frameCount"]
opaque Music.frameCount (music : @& Music) : UInt32
/-- Getter: Music looping enable -/
@[extern "lean_raylib__Music_looping"]
opaque Music.looping (music : @& Music) : Bool
/-- Setter: Music looping enable -/
@[extern "lean_raylib__Music_looping_set"]
opaque Music.set_looping (looping : Bool) (music : Music) : Music


/-! # Vr device info -/

-- opaque VrDeviceInfoPointed : NonemptyType
-- /-- VrDeviceInfo, Head-Mounted-Display device parameters -/
-- def VrDeviceInfo : Type := VrDeviceInfoPointed.type
-- instance : Nonempty VrDeviceInfo := VrDeviceInfoPointed.property
-- @[extern "lean_raylib__VrDeviceInfo_mk"]
-- opaque VrDeviceInfo.mk : VrDeviceInfo
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | hResolution: int -- Horizontal resolution in pixels
--   | vResolution: int -- Vertical resolution in pixels
--   | hScreenSize: float -- Horizontal size in meters
--   | vScreenSize: float -- Vertical size in meters
--   | vScreenCenter: float -- Screen center in meters
--   | eyeToScreenDistance: float -- Distance between eye and display in meters
--   | lensSeparationDistance: float -- Lens separation distance in meters
--   | interpupillaryDistance: float -- IPD (distance between pupils) in meters
--   | lensDistortionValues: float[4] -- Lens distortion constant parameters
--   | chromaAbCorrection: float[4] -- Chromatic aberration correction parameters
-- -/
-- /-- Getter: Horizontal resolution in pixels -/
-- @[extern "lean_raylib__VrDeviceInfo_hResolution"]
-- opaque VrDeviceInfo.hResolution (self : @& VrDeviceInfo) : Int32
-- /-- Setter: Horizontal resolution in pixels -/
-- @[extern "lean_raylib__VrDeviceInfo_hResolution_set"]
-- opaque VrDeviceInfo.set_hResolution (hResolution : Int32) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Vertical resolution in pixels -/
-- @[extern "lean_raylib__VrDeviceInfo_vResolution"]
-- opaque VrDeviceInfo.vResolution (self : @& VrDeviceInfo) : Int32
-- /-- Setter: Vertical resolution in pixels -/
-- @[extern "lean_raylib__VrDeviceInfo_vResolution_set"]
-- opaque VrDeviceInfo.set_vResolution (vResolution : Int32) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Horizontal size in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_hScreenSize"]
-- opaque VrDeviceInfo.hScreenSize (self : @& VrDeviceInfo) : Float
-- /-- Setter: Horizontal size in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_hScreenSize_set"]
-- opaque VrDeviceInfo.set_hScreenSize (hScreenSize : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Vertical size in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_vScreenSize"]
-- opaque VrDeviceInfo.vScreenSize (self : @& VrDeviceInfo) : Float
-- /-- Setter: Vertical size in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_vScreenSize_set"]
-- opaque VrDeviceInfo.set_vScreenSize (vScreenSize : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Screen center in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_vScreenCenter"]
-- opaque VrDeviceInfo.vScreenCenter (self : @& VrDeviceInfo) : Float
-- /-- Setter: Screen center in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_vScreenCenter_set"]
-- opaque VrDeviceInfo.set_vScreenCenter (vScreenCenter : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Distance between eye and display in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_eyeToScreenDistance"]
-- opaque VrDeviceInfo.eyeToScreenDistance (self : @& VrDeviceInfo) : Float
-- /-- Setter: Distance between eye and display in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_eyeToScreenDistance_set"]
-- opaque VrDeviceInfo.set_eyeToScreenDistance (eyeToScreenDistance : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Lens separation distance in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_lensSeparationDistance"]
-- opaque VrDeviceInfo.lensSeparationDistance (self : @& VrDeviceInfo) : Float
-- /-- Setter: Lens separation distance in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_lensSeparationDistance_set"]
-- opaque VrDeviceInfo.set_lensSeparationDistance (lensSeparationDistance : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: IPD (distance between pupils) in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_interpupillaryDistance"]
-- opaque VrDeviceInfo.interpupillaryDistance (self : @& VrDeviceInfo) : Float
-- /-- Setter: IPD (distance between pupils) in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_interpupillaryDistance_set"]
-- opaque VrDeviceInfo.set_interpupillaryDistance (interpupillaryDistance : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Lens distortion constant parameters -/
-- @[extern "lean_raylib__VrDeviceInfo_lensDistortionValues"]
-- opaque VrDeviceInfo.lensDistortionValues (self : @& VrDeviceInfo) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Lens distortion constant parameters -/
-- @[extern "lean_raylib__VrDeviceInfo_lensDistortionValues_set"]
-- opaque VrDeviceInfo.set_lensDistortionValues (lensDistortionValues : Unit) (self : VrDeviceInfo) : VrDeviceInfo
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Chromatic aberration correction parameters -/
-- @[extern "lean_raylib__VrDeviceInfo_chromaAbCorrection"]
-- opaque VrDeviceInfo.chromaAbCorrection (self : @& VrDeviceInfo) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Chromatic aberration correction parameters -/
-- @[extern "lean_raylib__VrDeviceInfo_chromaAbCorrection_set"]
-- opaque VrDeviceInfo.set_chromaAbCorrection (chromaAbCorrection : Unit) (self : VrDeviceInfo) : VrDeviceInfo
-- /-
-- todo: ^^ struct setter ^^
-- -/


/-! # Vr stereo config -/

-- opaque VrStereoConfigPointed : NonemptyType
-- /-- VrStereoConfig, VR stereo rendering configuration for simulator -/
-- def VrStereoConfig : Type := VrStereoConfigPointed.type
-- instance : Nonempty VrStereoConfig := VrStereoConfigPointed.property
-- @[extern "lean_raylib__VrStereoConfig_mk"]
-- opaque VrStereoConfig.mk : VrStereoConfig
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | projection: Matrix[2] -- VR projection matrices (per eye)
--   | viewOffset: Matrix[2] -- VR view offset matrices (per eye)
--   | leftLensCenter: float[2] -- VR left lens center
--   | rightLensCenter: float[2] -- VR right lens center
--   | leftScreenCenter: float[2] -- VR left screen center
--   | rightScreenCenter: float[2] -- VR right screen center
--   | scale: float[2] -- VR distortion scale
--   | scaleIn: float[2] -- VR distortion scale in
-- -/
-- /-- Getter: VR projection matrices (per eye) -/
-- @[extern "lean_raylib__VrStereoConfig_projection"]
-- opaque VrStereoConfig.projection (self : @& VrStereoConfig) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR projection matrices (per eye) -/
-- @[extern "lean_raylib__VrStereoConfig_projection_set"]
-- opaque VrStereoConfig.set_projection (projection : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: VR view offset matrices (per eye) -/
-- @[extern "lean_raylib__VrStereoConfig_viewOffset"]
-- opaque VrStereoConfig.viewOffset (self : @& VrStereoConfig) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR view offset matrices (per eye) -/
-- @[extern "lean_raylib__VrStereoConfig_viewOffset_set"]
-- opaque VrStereoConfig.set_viewOffset (viewOffset : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: VR left lens center -/
-- @[extern "lean_raylib__VrStereoConfig_leftLensCenter"]
-- opaque VrStereoConfig.leftLensCenter (self : @& VrStereoConfig) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR left lens center -/
-- @[extern "lean_raylib__VrStereoConfig_leftLensCenter_set"]
-- opaque VrStereoConfig.set_leftLensCenter (leftLensCenter : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: VR right lens center -/
-- @[extern "lean_raylib__VrStereoConfig_rightLensCenter"]
-- opaque VrStereoConfig.rightLensCenter (self : @& VrStereoConfig) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR right lens center -/
-- @[extern "lean_raylib__VrStereoConfig_rightLensCenter_set"]
-- opaque VrStereoConfig.set_rightLensCenter (rightLensCenter : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: VR left screen center -/
-- @[extern "lean_raylib__VrStereoConfig_leftScreenCenter"]
-- opaque VrStereoConfig.leftScreenCenter (self : @& VrStereoConfig) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR left screen center -/
-- @[extern "lean_raylib__VrStereoConfig_leftScreenCenter_set"]
-- opaque VrStereoConfig.set_leftScreenCenter (leftScreenCenter : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: VR right screen center -/
-- @[extern "lean_raylib__VrStereoConfig_rightScreenCenter"]
-- opaque VrStereoConfig.rightScreenCenter (self : @& VrStereoConfig) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR right screen center -/
-- @[extern "lean_raylib__VrStereoConfig_rightScreenCenter_set"]
-- opaque VrStereoConfig.set_rightScreenCenter (rightScreenCenter : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: VR distortion scale -/
-- @[extern "lean_raylib__VrStereoConfig_scale"]
-- opaque VrStereoConfig.scale (self : @& VrStereoConfig) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR distortion scale -/
-- @[extern "lean_raylib__VrStereoConfig_scale_set"]
-- opaque VrStereoConfig.set_scale (scale : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: VR distortion scale in -/
-- @[extern "lean_raylib__VrStereoConfig_scaleIn"]
-- opaque VrStereoConfig.scaleIn (self : @& VrStereoConfig) : Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR distortion scale in -/
-- @[extern "lean_raylib__VrStereoConfig_scaleIn_set"]
-- opaque VrStereoConfig.set_scaleIn (scaleIn : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/

end Raylib
