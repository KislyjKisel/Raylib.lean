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
opaque Vector2.x (self : @& Vector2) : Float

/-- Setter: Vector x component -/
@[extern "lean_raylib__Vector2_x_set"]
opaque Vector2.set_x (x : Float) (self : @& Vector2) : Vector2

/-- Getter: Vector y component -/
@[extern "lean_raylib__Vector2_y"]
opaque Vector2.y (self : @& Vector2) : Float

/-- Setter: Vector y component -/
@[extern "lean_raylib__Vector2_y_set"]
opaque Vector2.set_y (y : Float) (self : @& Vector2) : Vector2


/-! ## Vector3 -/

opaque Vector3Pointed : NonemptyType
/-- Vector3, 3 components -/
def Vector3 : Type := Vector3Pointed.type
instance : Nonempty Vector3 := Vector3Pointed.property

@[extern "lean_raylib__Vector3_mk"]
opaque Vector3.mk (x : Float) (y : Float) (z : Float) : Vector3

/-- Getter: Vector x component -/
@[extern "lean_raylib__Vector3_x"]
opaque Vector3.x (self : @& Vector3) : Float

/-- Setter: Vector x component -/
@[extern "lean_raylib__Vector3_x_set"]
opaque Vector3.set_x (x : Float) (self : @& Vector3) : Vector3

/-- Getter: Vector y component -/
@[extern "lean_raylib__Vector3_y"]
opaque Vector3.y (self : @& Vector3) : Float

/-- Setter: Vector y component -/
@[extern "lean_raylib__Vector3_y_set"]
opaque Vector3.set_y (y : Float) (self : @& Vector3) : Vector3

/-- Getter: Vector z component -/
@[extern "lean_raylib__Vector3_z"]
opaque Vector3.z (self : @& Vector3) : Float

/-- Setter: Vector z component -/
@[extern "lean_raylib__Vector3_z_set"]
opaque Vector3.set_z (z : Float) (self : @& Vector3) : Vector3


/-! ## Vector4 -/

opaque Vector4Pointed : NonemptyType
/-- Vector4, 4 components -/
def Vector4 : Type := Vector4Pointed.type
instance : Nonempty Vector4 := Vector4Pointed.property

@[extern "lean_raylib__Vector4_mk"]
opaque Vector4.mk (x : Float) (y : Float) (z : Float) (w : Float) : Vector4

/-- Getter: Vector x component -/
@[extern "lean_raylib__Vector4_x"]
opaque Vector4.x (self : @& Vector4) : Float

/-- Setter: Vector x component -/
@[extern "lean_raylib__Vector4_x_set"]
opaque Vector4.set_x (x : Float) (self : @& Vector4) : Vector4

/-- Getter: Vector y component -/
@[extern "lean_raylib__Vector4_y"]
opaque Vector4.y (self : @& Vector4) : Float

/-- Setter: Vector y component -/
@[extern "lean_raylib__Vector4_y_set"]
opaque Vector4.set_y (y : Float) (self : @& Vector4) : Vector4

/-- Getter: Vector z component -/
@[extern "lean_raylib__Vector4_z"]
opaque Vector4.z (self : @& Vector4) : Float

/-- Setter: Vector z component -/
@[extern "lean_raylib__Vector4_z_set"]
opaque Vector4.set_z (z : Float) (self : @& Vector4) : Vector4

/-- Getter: Vector w component -/
@[extern "lean_raylib__Vector4_w"]
opaque Vector4.w (self : @& Vector4) : Float

/-- Setter: Vector w component -/
@[extern "lean_raylib__Vector4_w_set"]
opaque Vector4.set_w (w : Float) (self : @& Vector4) : Vector4



/-! # Matrices -/

opaque MatrixPointed : NonemptyType
/-- Matrix, 4x4 components, column major, OpenGL style, right handed -/
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
opaque Matrix.set_m0 (m0 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m4"]
opaque Matrix.m4 (self : @& Matrix) : Float

/-- Setter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m4_set"]
opaque Matrix.set_m4 (m4 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m8"]
opaque Matrix.m8 (self : @& Matrix) : Float

/-- Setter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m8_set"]
opaque Matrix.set_m8 (m8 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m12"]
opaque Matrix.m12 (self : @& Matrix) : Float

/-- Setter: Matrix first row (4 components) -/
@[extern "lean_raylib__Matrix_m12_set"]
opaque Matrix.set_m12 (m12 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m1"]
opaque Matrix.m1 (self : @& Matrix) : Float

/-- Setter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m1_set"]
opaque Matrix.set_m1 (m1 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m5"]
opaque Matrix.m5 (self : @& Matrix) : Float

/-- Setter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m5_set"]
opaque Matrix.set_m5 (m5 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m9"]
opaque Matrix.m9 (self : @& Matrix) : Float

/-- Setter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m9_set"]
opaque Matrix.set_m9 (m9 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m13"]
opaque Matrix.m13 (self : @& Matrix) : Float

/-- Setter: Matrix second row (4 components) -/
@[extern "lean_raylib__Matrix_m13_set"]
opaque Matrix.set_m13 (m13 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m2"]
opaque Matrix.m2 (self : @& Matrix) : Float

/-- Setter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m2_set"]
opaque Matrix.set_m2 (m2 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m6"]
opaque Matrix.m6 (self : @& Matrix) : Float

/-- Setter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m6_set"]
opaque Matrix.set_m6 (m6 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m10"]
opaque Matrix.m10 (self : @& Matrix) : Float

/-- Setter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m10_set"]
opaque Matrix.set_m10 (m10 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m14"]
opaque Matrix.m14 (self : @& Matrix) : Float

/-- Setter: Matrix third row (4 components) -/
@[extern "lean_raylib__Matrix_m14_set"]
opaque Matrix.set_m14 (m14 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m3"]
opaque Matrix.m3 (self : @& Matrix) : Float

/-- Setter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m3_set"]
opaque Matrix.set_m3 (m3 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m7"]
opaque Matrix.m7 (self : @& Matrix) : Float

/-- Setter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m7_set"]
opaque Matrix.set_m7 (m7 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m11"]
opaque Matrix.m11 (self : @& Matrix) : Float

/-- Setter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m11_set"]
opaque Matrix.set_m11 (m11 : Float) (self : @& Matrix) : Matrix

/-- Getter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m15"]
opaque Matrix.m15 (self : @& Matrix) : Float

/-- Setter: Matrix fourth row (4 components) -/
@[extern "lean_raylib__Matrix_m15_set"]
opaque Matrix.set_m15 (m15 : Float) (self : @& Matrix) : Matrix



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



-- opaque RectanglePointed : NonemptyType
-- /-- Rectangle, 4 components -/
-- def Rectangle : Type := RectanglePointed.type
-- instance : Nonempty Rectangle := RectanglePointed.property
-- @[extern "lean_raylib__Rectangle_mk"]
-- opaque Rectangle.mk (x : Float) (y : Float) (width : Float) (height : Float) : Rectangle
-- /-- Getter: Rectangle top-left corner position x -/
-- @[extern "lean_raylib__Rectangle_x"]
-- opaque Rectangle.x : Rectangle -> Float
-- /-- Setter: Rectangle top-left corner position x -/
-- @[extern "lean_raylib__Rectangle_x_set"]
-- opaque Rectangle.set_x (x : Float) (self : Rectangle) : Rectangle
-- /-- Getter: Rectangle top-left corner position y -/
-- @[extern "lean_raylib__Rectangle_y"]
-- opaque Rectangle.y : Rectangle -> Float
-- /-- Setter: Rectangle top-left corner position y -/
-- @[extern "lean_raylib__Rectangle_y_set"]
-- opaque Rectangle.set_y (y : Float) (self : Rectangle) : Rectangle
-- /-- Getter: Rectangle width -/
-- @[extern "lean_raylib__Rectangle_width"]
-- opaque Rectangle.width : Rectangle -> Float
-- /-- Setter: Rectangle width -/
-- @[extern "lean_raylib__Rectangle_width_set"]
-- opaque Rectangle.set_width (width : Float) (self : Rectangle) : Rectangle
-- /-- Getter: Rectangle height -/
-- @[extern "lean_raylib__Rectangle_height"]
-- opaque Rectangle.height : Rectangle -> Float
-- /-- Setter: Rectangle height -/
-- @[extern "lean_raylib__Rectangle_height_set"]
-- opaque Rectangle.set_height (height : Float) (self : Rectangle) : Rectangle
-- opaque ImagePointed : NonemptyType
-- /-- Image, pixel data stored in CPU memory (RAM) -/
-- def Image : Type := ImagePointed.type
-- instance : Nonempty Image := ImagePointed.property
-- @[extern "lean_raylib__Image_mk"]
-- opaque Image.mk : Image
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | data: void * -- Image raw data
--   | width: int -- Image base width
--   | height: int -- Image base height
--   | mipmaps: int -- Mipmap levels, 1 by default
--   | format: int -- Data format (PixelFormat type)
-- -/
-- /-- Getter: Image raw data -/
-- @[extern "lean_raylib__Image_data"]
-- opaque Image.data : Image -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Image raw data -/
-- @[extern "lean_raylib__Image_data_set"]
-- opaque Image.set_data (data : Unit) (self : Image) : Image
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Image base width -/
-- @[extern "lean_raylib__Image_width"]
-- opaque Image.width : Image -> Int32
-- /-- Setter: Image base width -/
-- @[extern "lean_raylib__Image_width_set"]
-- opaque Image.set_width (width : Int32) (self : Image) : Image
-- /-- Getter: Image base height -/
-- @[extern "lean_raylib__Image_height"]
-- opaque Image.height : Image -> Int32
-- /-- Setter: Image base height -/
-- @[extern "lean_raylib__Image_height_set"]
-- opaque Image.set_height (height : Int32) (self : Image) : Image
-- /-- Getter: Mipmap levels, 1 by default -/
-- @[extern "lean_raylib__Image_mipmaps"]
-- opaque Image.mipmaps : Image -> Int32
-- /-- Setter: Mipmap levels, 1 by default -/
-- @[extern "lean_raylib__Image_mipmaps_set"]
-- opaque Image.set_mipmaps (mipmaps : Int32) (self : Image) : Image
-- /-- Getter: Data format (PixelFormat type) -/
-- @[extern "lean_raylib__Image_format"]
-- opaque Image.format : Image -> Int32
-- /-- Setter: Data format (PixelFormat type) -/
-- @[extern "lean_raylib__Image_format_set"]
-- opaque Image.set_format (format : Int32) (self : Image) : Image
-- opaque TexturePointed : NonemptyType
-- /-- Texture, tex data stored in GPU memory (VRAM) -/
-- def Texture : Type := TexturePointed.type
-- instance : Nonempty Texture := TexturePointed.property
-- @[extern "lean_raylib__Texture_mk"]
-- opaque Texture.mk (id : UInt32) (width : Int32) (height : Int32) (mipmaps : Int32) (format : Int32) : Texture
-- /-- Getter: OpenGL texture id -/
-- @[extern "lean_raylib__Texture_id"]
-- opaque Texture.id : Texture -> UInt32
-- /-- Setter: OpenGL texture id -/
-- @[extern "lean_raylib__Texture_id_set"]
-- opaque Texture.set_id (id : UInt32) (self : Texture) : Texture
-- /-- Getter: Texture base width -/
-- @[extern "lean_raylib__Texture_width"]
-- opaque Texture.width : Texture -> Int32
-- /-- Setter: Texture base width -/
-- @[extern "lean_raylib__Texture_width_set"]
-- opaque Texture.set_width (width : Int32) (self : Texture) : Texture
-- /-- Getter: Texture base height -/
-- @[extern "lean_raylib__Texture_height"]
-- opaque Texture.height : Texture -> Int32
-- /-- Setter: Texture base height -/
-- @[extern "lean_raylib__Texture_height_set"]
-- opaque Texture.set_height (height : Int32) (self : Texture) : Texture
-- /-- Getter: Mipmap levels, 1 by default -/
-- @[extern "lean_raylib__Texture_mipmaps"]
-- opaque Texture.mipmaps : Texture -> Int32
-- /-- Setter: Mipmap levels, 1 by default -/
-- @[extern "lean_raylib__Texture_mipmaps_set"]
-- opaque Texture.set_mipmaps (mipmaps : Int32) (self : Texture) : Texture
-- /-- Getter: Data format (PixelFormat type) -/
-- @[extern "lean_raylib__Texture_format"]
-- opaque Texture.format : Texture -> Int32
-- /-- Setter: Data format (PixelFormat type) -/
-- @[extern "lean_raylib__Texture_format_set"]
-- opaque Texture.set_format (format : Int32) (self : Texture) : Texture
-- opaque RenderTexturePointed : NonemptyType
-- /-- RenderTexture, fbo for texture rendering -/
-- def RenderTexture : Type := RenderTexturePointed.type
-- instance : Nonempty RenderTexture := RenderTexturePointed.property
-- @[extern "lean_raylib__RenderTexture_mk"]
-- opaque RenderTexture.mk (id : UInt32) (texture : Texture) (depth : Texture) : RenderTexture
-- /-- Getter: OpenGL framebuffer object id -/
-- @[extern "lean_raylib__RenderTexture_id"]
-- opaque RenderTexture.id : RenderTexture -> UInt32
-- /-- Setter: OpenGL framebuffer object id -/
-- @[extern "lean_raylib__RenderTexture_id_set"]
-- opaque RenderTexture.set_id (id : UInt32) (self : RenderTexture) : RenderTexture
-- /-- Getter: Color buffer attachment texture -/
-- @[extern "lean_raylib__RenderTexture_texture"]
-- opaque RenderTexture.texture : RenderTexture -> Texture
-- /-- Setter: Color buffer attachment texture -/
-- @[extern "lean_raylib__RenderTexture_texture_set"]
-- opaque RenderTexture.set_texture (texture : Texture) (self : RenderTexture) : RenderTexture
-- /-- Getter: Depth buffer attachment texture -/
-- @[extern "lean_raylib__RenderTexture_depth"]
-- opaque RenderTexture.depth : RenderTexture -> Texture
-- /-- Setter: Depth buffer attachment texture -/
-- @[extern "lean_raylib__RenderTexture_depth_set"]
-- opaque RenderTexture.set_depth (depth : Texture) (self : RenderTexture) : RenderTexture
-- opaque NPatchInfoPointed : NonemptyType
-- /-- NPatchInfo, n-patch layout info -/
-- def NPatchInfo : Type := NPatchInfoPointed.type
-- instance : Nonempty NPatchInfo := NPatchInfoPointed.property
-- @[extern "lean_raylib__NPatchInfo_mk"]
-- opaque NPatchInfo.mk (source : Rectangle) (left : Int32) (top : Int32) (right : Int32) (bottom : Int32) (layout : Int32) : NPatchInfo
-- /-- Getter: Texture source rectangle -/
-- @[extern "lean_raylib__NPatchInfo_source"]
-- opaque NPatchInfo.source : NPatchInfo -> Rectangle
-- /-- Setter: Texture source rectangle -/
-- @[extern "lean_raylib__NPatchInfo_source_set"]
-- opaque NPatchInfo.set_source (source : Rectangle) (self : NPatchInfo) : NPatchInfo
-- /-- Getter: Left border offset -/
-- @[extern "lean_raylib__NPatchInfo_left"]
-- opaque NPatchInfo.left : NPatchInfo -> Int32
-- /-- Setter: Left border offset -/
-- @[extern "lean_raylib__NPatchInfo_left_set"]
-- opaque NPatchInfo.set_left (left : Int32) (self : NPatchInfo) : NPatchInfo
-- /-- Getter: Top border offset -/
-- @[extern "lean_raylib__NPatchInfo_top"]
-- opaque NPatchInfo.top : NPatchInfo -> Int32
-- /-- Setter: Top border offset -/
-- @[extern "lean_raylib__NPatchInfo_top_set"]
-- opaque NPatchInfo.set_top (top : Int32) (self : NPatchInfo) : NPatchInfo
-- /-- Getter: Right border offset -/
-- @[extern "lean_raylib__NPatchInfo_right"]
-- opaque NPatchInfo.right : NPatchInfo -> Int32
-- /-- Setter: Right border offset -/
-- @[extern "lean_raylib__NPatchInfo_right_set"]
-- opaque NPatchInfo.set_right (right : Int32) (self : NPatchInfo) : NPatchInfo
-- /-- Getter: Bottom border offset -/
-- @[extern "lean_raylib__NPatchInfo_bottom"]
-- opaque NPatchInfo.bottom : NPatchInfo -> Int32
-- /-- Setter: Bottom border offset -/
-- @[extern "lean_raylib__NPatchInfo_bottom_set"]
-- opaque NPatchInfo.set_bottom (bottom : Int32) (self : NPatchInfo) : NPatchInfo
-- /-- Getter: Layout of the n-patch: 3x3, 1x3 or 3x1 -/
-- @[extern "lean_raylib__NPatchInfo_layout"]
-- opaque NPatchInfo.layout : NPatchInfo -> Int32
-- /-- Setter: Layout of the n-patch: 3x3, 1x3 or 3x1 -/
-- @[extern "lean_raylib__NPatchInfo_layout_set"]
-- opaque NPatchInfo.set_layout (layout : Int32) (self : NPatchInfo) : NPatchInfo
-- opaque GlyphInfoPointed : NonemptyType
-- /-- GlyphInfo, font characters glyphs info -/
-- def GlyphInfo : Type := GlyphInfoPointed.type
-- instance : Nonempty GlyphInfo := GlyphInfoPointed.property
-- @[extern "lean_raylib__GlyphInfo_mk"]
-- opaque GlyphInfo.mk (value : Int32) (offsetX : Int32) (offsetY : Int32) (advanceX : Int32) (image : Image) : GlyphInfo
-- /-- Getter: Character value (Unicode) -/
-- @[extern "lean_raylib__GlyphInfo_value"]
-- opaque GlyphInfo.value : GlyphInfo -> Int32
-- /-- Setter: Character value (Unicode) -/
-- @[extern "lean_raylib__GlyphInfo_value_set"]
-- opaque GlyphInfo.set_value (value : Int32) (self : GlyphInfo) : GlyphInfo
-- /-- Getter: Character offset X when drawing -/
-- @[extern "lean_raylib__GlyphInfo_offsetX"]
-- opaque GlyphInfo.offsetX : GlyphInfo -> Int32
-- /-- Setter: Character offset X when drawing -/
-- @[extern "lean_raylib__GlyphInfo_offsetX_set"]
-- opaque GlyphInfo.set_offsetX (offsetX : Int32) (self : GlyphInfo) : GlyphInfo
-- /-- Getter: Character offset Y when drawing -/
-- @[extern "lean_raylib__GlyphInfo_offsetY"]
-- opaque GlyphInfo.offsetY : GlyphInfo -> Int32
-- /-- Setter: Character offset Y when drawing -/
-- @[extern "lean_raylib__GlyphInfo_offsetY_set"]
-- opaque GlyphInfo.set_offsetY (offsetY : Int32) (self : GlyphInfo) : GlyphInfo
-- /-- Getter: Character advance position X -/
-- @[extern "lean_raylib__GlyphInfo_advanceX"]
-- opaque GlyphInfo.advanceX : GlyphInfo -> Int32
-- /-- Setter: Character advance position X -/
-- @[extern "lean_raylib__GlyphInfo_advanceX_set"]
-- opaque GlyphInfo.set_advanceX (advanceX : Int32) (self : GlyphInfo) : GlyphInfo
-- /-- Getter: Character image data -/
-- @[extern "lean_raylib__GlyphInfo_image"]
-- opaque GlyphInfo.image : GlyphInfo -> Image
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
-- opaque Font.baseSize : Font -> Int32
-- /-- Setter: Base size (default chars height) -/
-- @[extern "lean_raylib__Font_baseSize_set"]
-- opaque Font.set_baseSize (baseSize : Int32) (self : Font) : Font
-- /-- Getter: Number of glyph characters -/
-- @[extern "lean_raylib__Font_glyphCount"]
-- opaque Font.glyphCount : Font -> Int32
-- /-- Setter: Number of glyph characters -/
-- @[extern "lean_raylib__Font_glyphCount_set"]
-- opaque Font.set_glyphCount (glyphCount : Int32) (self : Font) : Font
-- /-- Getter: Padding around the glyph characters -/
-- @[extern "lean_raylib__Font_glyphPadding"]
-- opaque Font.glyphPadding : Font -> Int32
-- /-- Setter: Padding around the glyph characters -/
-- @[extern "lean_raylib__Font_glyphPadding_set"]
-- opaque Font.set_glyphPadding (glyphPadding : Int32) (self : Font) : Font
-- /-- Getter: Texture atlas containing the glyphs -/
-- @[extern "lean_raylib__Font_texture"]
-- opaque Font.texture : Font -> Unit
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
-- opaque Font.recs : Font -> Unit
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
-- opaque Font.glyphs : Font -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Glyphs info data -/
-- @[extern "lean_raylib__Font_glyphs_set"]
-- opaque Font.set_glyphs (glyphs : Unit) (self : Font) : Font
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- opaque Camera3DPointed : NonemptyType
-- /-- Camera, defines position/orientation in 3d space -/
-- def Camera3D : Type := Camera3DPointed.type
-- instance : Nonempty Camera3D := Camera3DPointed.property
-- @[extern "lean_raylib__Camera3D_mk"]
-- opaque Camera3D.mk (position : Vector3) (target : Vector3) (up : Vector3) (fovy : Float) (projection : Int32) : Camera3D
-- /-- Getter: Camera position -/
-- @[extern "lean_raylib__Camera3D_position"]
-- opaque Camera3D.position : Camera3D -> Vector3
-- /-- Setter: Camera position -/
-- @[extern "lean_raylib__Camera3D_position_set"]
-- opaque Camera3D.set_position (position : Vector3) (self : Camera3D) : Camera3D
-- /-- Getter: Camera target it looks-at -/
-- @[extern "lean_raylib__Camera3D_target"]
-- opaque Camera3D.target : Camera3D -> Vector3
-- /-- Setter: Camera target it looks-at -/
-- @[extern "lean_raylib__Camera3D_target_set"]
-- opaque Camera3D.set_target (target : Vector3) (self : Camera3D) : Camera3D
-- /-- Getter: Camera up vector (rotation over its axis) -/
-- @[extern "lean_raylib__Camera3D_up"]
-- opaque Camera3D.up : Camera3D -> Vector3
-- /-- Setter: Camera up vector (rotation over its axis) -/
-- @[extern "lean_raylib__Camera3D_up_set"]
-- opaque Camera3D.set_up (up : Vector3) (self : Camera3D) : Camera3D
-- /-- Getter: Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic -/
-- @[extern "lean_raylib__Camera3D_fovy"]
-- opaque Camera3D.fovy : Camera3D -> Float
-- /-- Setter: Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic -/
-- @[extern "lean_raylib__Camera3D_fovy_set"]
-- opaque Camera3D.set_fovy (fovy : Float) (self : Camera3D) : Camera3D
-- /-- Getter: Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC -/
-- @[extern "lean_raylib__Camera3D_projection"]
-- opaque Camera3D.projection : Camera3D -> Int32
-- /-- Setter: Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC -/
-- @[extern "lean_raylib__Camera3D_projection_set"]
-- opaque Camera3D.set_projection (projection : Int32) (self : Camera3D) : Camera3D
-- opaque Camera2DPointed : NonemptyType
-- /-- Camera2D, defines position/orientation in 2d space -/
-- def Camera2D : Type := Camera2DPointed.type
-- instance : Nonempty Camera2D := Camera2DPointed.property
-- @[extern "lean_raylib__Camera2D_mk"]
-- opaque Camera2D.mk (offset : Vector2) (target : Vector2) (rotation : Float) (zoom : Float) : Camera2D
-- /-- Getter: Camera offset (displacement from target) -/
-- @[extern "lean_raylib__Camera2D_offset"]
-- opaque Camera2D.offset : Camera2D -> Vector2
-- /-- Setter: Camera offset (displacement from target) -/
-- @[extern "lean_raylib__Camera2D_offset_set"]
-- opaque Camera2D.set_offset (offset : Vector2) (self : Camera2D) : Camera2D
-- /-- Getter: Camera target (rotation and zoom origin) -/
-- @[extern "lean_raylib__Camera2D_target"]
-- opaque Camera2D.target : Camera2D -> Vector2
-- /-- Setter: Camera target (rotation and zoom origin) -/
-- @[extern "lean_raylib__Camera2D_target_set"]
-- opaque Camera2D.set_target (target : Vector2) (self : Camera2D) : Camera2D
-- /-- Getter: Camera rotation in degrees -/
-- @[extern "lean_raylib__Camera2D_rotation"]
-- opaque Camera2D.rotation : Camera2D -> Float
-- /-- Setter: Camera rotation in degrees -/
-- @[extern "lean_raylib__Camera2D_rotation_set"]
-- opaque Camera2D.set_rotation (rotation : Float) (self : Camera2D) : Camera2D
-- /-- Getter: Camera zoom (scaling), should be 1.0f by default -/
-- @[extern "lean_raylib__Camera2D_zoom"]
-- opaque Camera2D.zoom : Camera2D -> Float
-- /-- Setter: Camera zoom (scaling), should be 1.0f by default -/
-- @[extern "lean_raylib__Camera2D_zoom_set"]
-- opaque Camera2D.set_zoom (zoom : Float) (self : Camera2D) : Camera2D
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
-- opaque Mesh.vertexCount : Mesh -> Int32
-- /-- Setter: Number of vertices stored in arrays -/
-- @[extern "lean_raylib__Mesh_vertexCount_set"]
-- opaque Mesh.set_vertexCount (vertexCount : Int32) (self : Mesh) : Mesh
-- /-- Getter: Number of triangles stored (indexed or not) -/
-- @[extern "lean_raylib__Mesh_triangleCount"]
-- opaque Mesh.triangleCount : Mesh -> Int32
-- /-- Setter: Number of triangles stored (indexed or not) -/
-- @[extern "lean_raylib__Mesh_triangleCount_set"]
-- opaque Mesh.set_triangleCount (triangleCount : Int32) (self : Mesh) : Mesh
-- /-- Getter: Vertex position (XYZ - 3 components per vertex) (shader-location = 0) -/
-- @[extern "lean_raylib__Mesh_vertices"]
-- opaque Mesh.vertices : Mesh -> Unit
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
-- opaque Mesh.texcoords : Mesh -> Unit
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
-- opaque Mesh.texcoords2 : Mesh -> Unit
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
-- opaque Mesh.normals : Mesh -> Unit
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
-- opaque Mesh.tangents : Mesh -> Unit
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
-- opaque Mesh.colors : Mesh -> Unit
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
-- opaque Mesh.indices : Mesh -> Unit
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
-- opaque Mesh.animVertices : Mesh -> Unit
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
-- opaque Mesh.animNormals : Mesh -> Unit
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
-- opaque Mesh.boneIds : Mesh -> Unit
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
-- opaque Mesh.boneWeights : Mesh -> Unit
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
-- opaque Mesh.vaoId : Mesh -> UInt32
-- /-- Setter: OpenGL Vertex Array Object id -/
-- @[extern "lean_raylib__Mesh_vaoId_set"]
-- opaque Mesh.set_vaoId (vaoId : UInt32) (self : Mesh) : Mesh
-- /-- Getter: OpenGL Vertex Buffer Objects id (default vertex data) -/
-- @[extern "lean_raylib__Mesh_vboId"]
-- opaque Mesh.vboId : Mesh -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: OpenGL Vertex Buffer Objects id (default vertex data) -/
-- @[extern "lean_raylib__Mesh_vboId_set"]
-- opaque Mesh.set_vboId (vboId : Unit) (self : Mesh) : Mesh
-- /-
-- todo: ^^ struct setter ^^
-- -/
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
-- opaque Shader.id : Shader -> UInt32
-- /-- Setter: Shader program id -/
-- @[extern "lean_raylib__Shader_id_set"]
-- opaque Shader.set_id (id : UInt32) (self : Shader) : Shader
-- /-- Getter: Shader locations array (RL_MAX_SHADER_LOCATIONS) -/
-- @[extern "lean_raylib__Shader_locs"]
-- opaque Shader.locs : Shader -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Shader locations array (RL_MAX_SHADER_LOCATIONS) -/
-- @[extern "lean_raylib__Shader_locs_set"]
-- opaque Shader.set_locs (locs : Unit) (self : Shader) : Shader
-- /-
-- todo: ^^ struct setter ^^
-- -/
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
-- opaque MaterialMap.texture : MaterialMap -> Unit
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
-- opaque MaterialMap.color : MaterialMap -> Color
-- /-- Setter: Material map color -/
-- @[extern "lean_raylib__MaterialMap_color_set"]
-- opaque MaterialMap.set_color (color : Color) (self : MaterialMap) : MaterialMap
-- /-- Getter: Material map value -/
-- @[extern "lean_raylib__MaterialMap_value"]
-- opaque MaterialMap.value : MaterialMap -> Float
-- /-- Setter: Material map value -/
-- @[extern "lean_raylib__MaterialMap_value_set"]
-- opaque MaterialMap.set_value (value : Float) (self : MaterialMap) : MaterialMap
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
-- opaque Material.shader : Material -> Shader
-- /-- Setter: Material shader -/
-- @[extern "lean_raylib__Material_shader_set"]
-- opaque Material.set_shader (shader : Shader) (self : Material) : Material
-- /-- Getter: Material maps array (MAX_MATERIAL_MAPS) -/
-- @[extern "lean_raylib__Material_maps"]
-- opaque Material.maps : Material -> Unit
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
-- opaque Material.params : Material -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Material generic parameters (if required) -/
-- @[extern "lean_raylib__Material_params_set"]
-- opaque Material.set_params (params : Unit) (self : Material) : Material
-- /-
-- todo: ^^ struct setter ^^
-- -/
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
-- opaque Transform.translation : Transform -> Vector3
-- /-- Setter: Translation -/
-- @[extern "lean_raylib__Transform_translation_set"]
-- opaque Transform.set_translation (translation : Vector3) (self : Transform) : Transform
-- /-- Getter: Rotation -/
-- @[extern "lean_raylib__Transform_rotation"]
-- opaque Transform.rotation : Transform -> Unit
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
-- opaque Transform.scale : Transform -> Vector3
-- /-- Setter: Scale -/
-- @[extern "lean_raylib__Transform_scale_set"]
-- opaque Transform.set_scale (scale : Vector3) (self : Transform) : Transform
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
-- opaque BoneInfo.name : BoneInfo -> Unit
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
-- opaque BoneInfo.parent : BoneInfo -> Int32
-- /-- Setter: Bone parent -/
-- @[extern "lean_raylib__BoneInfo_parent_set"]
-- opaque BoneInfo.set_parent (parent : Int32) (self : BoneInfo) : BoneInfo
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
-- opaque Model.transform : Model -> Matrix
-- /-- Setter: Local transform matrix -/
-- @[extern "lean_raylib__Model_transform_set"]
-- opaque Model.set_transform (transform : Matrix) (self : Model) : Model
-- /-- Getter: Number of meshes -/
-- @[extern "lean_raylib__Model_meshCount"]
-- opaque Model.meshCount : Model -> Int32
-- /-- Setter: Number of meshes -/
-- @[extern "lean_raylib__Model_meshCount_set"]
-- opaque Model.set_meshCount (meshCount : Int32) (self : Model) : Model
-- /-- Getter: Number of materials -/
-- @[extern "lean_raylib__Model_materialCount"]
-- opaque Model.materialCount : Model -> Int32
-- /-- Setter: Number of materials -/
-- @[extern "lean_raylib__Model_materialCount_set"]
-- opaque Model.set_materialCount (materialCount : Int32) (self : Model) : Model
-- /-- Getter: Meshes array -/
-- @[extern "lean_raylib__Model_meshes"]
-- opaque Model.meshes : Model -> Unit
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
-- opaque Model.materials : Model -> Unit
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
-- opaque Model.meshMaterial : Model -> Unit
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
-- opaque Model.boneCount : Model -> Int32
-- /-- Setter: Number of bones -/
-- @[extern "lean_raylib__Model_boneCount_set"]
-- opaque Model.set_boneCount (boneCount : Int32) (self : Model) : Model
-- /-- Getter: Bones information (skeleton) -/
-- @[extern "lean_raylib__Model_bones"]
-- opaque Model.bones : Model -> Unit
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
-- opaque Model.bindPose : Model -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Bones base transformation (pose) -/
-- @[extern "lean_raylib__Model_bindPose_set"]
-- opaque Model.set_bindPose (bindPose : Unit) (self : Model) : Model
-- /-
-- todo: ^^ struct setter ^^
-- -/
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
-- opaque ModelAnimation.boneCount : ModelAnimation -> Int32
-- /-- Setter: Number of bones -/
-- @[extern "lean_raylib__ModelAnimation_boneCount_set"]
-- opaque ModelAnimation.set_boneCount (boneCount : Int32) (self : ModelAnimation) : ModelAnimation
-- /-- Getter: Number of animation frames -/
-- @[extern "lean_raylib__ModelAnimation_frameCount"]
-- opaque ModelAnimation.frameCount : ModelAnimation -> Int32
-- /-- Setter: Number of animation frames -/
-- @[extern "lean_raylib__ModelAnimation_frameCount_set"]
-- opaque ModelAnimation.set_frameCount (frameCount : Int32) (self : ModelAnimation) : ModelAnimation
-- /-- Getter: Bones information (skeleton) -/
-- @[extern "lean_raylib__ModelAnimation_bones"]
-- opaque ModelAnimation.bones : ModelAnimation -> Unit
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
-- opaque ModelAnimation.framePoses : ModelAnimation -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Poses array by frame -/
-- @[extern "lean_raylib__ModelAnimation_framePoses_set"]
-- opaque ModelAnimation.set_framePoses (framePoses : Unit) (self : ModelAnimation) : ModelAnimation
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- opaque RayPointed : NonemptyType
-- /-- Ray, ray for raycasting -/
-- def Ray : Type := RayPointed.type
-- instance : Nonempty Ray := RayPointed.property
-- @[extern "lean_raylib__Ray_mk"]
-- opaque Ray.mk (position : Vector3) (direction : Vector3) : Ray
-- /-- Getter: Ray position (origin) -/
-- @[extern "lean_raylib__Ray_position"]
-- opaque Ray.position : Ray -> Vector3
-- /-- Setter: Ray position (origin) -/
-- @[extern "lean_raylib__Ray_position_set"]
-- opaque Ray.set_position (position : Vector3) (self : Ray) : Ray
-- /-- Getter: Ray direction -/
-- @[extern "lean_raylib__Ray_direction"]
-- opaque Ray.direction : Ray -> Vector3
-- /-- Setter: Ray direction -/
-- @[extern "lean_raylib__Ray_direction_set"]
-- opaque Ray.set_direction (direction : Vector3) (self : Ray) : Ray
-- opaque RayCollisionPointed : NonemptyType
-- /-- RayCollision, ray hit information -/
-- def RayCollision : Type := RayCollisionPointed.type
-- instance : Nonempty RayCollision := RayCollisionPointed.property
-- @[extern "lean_raylib__RayCollision_mk"]
-- opaque RayCollision.mk (hit : Bool) (distance : Float) (point : Vector3) (normal : Vector3) : RayCollision
-- /-- Getter: Did the ray hit something? -/
-- @[extern "lean_raylib__RayCollision_hit"]
-- opaque RayCollision.hit : RayCollision -> Bool
-- /-- Setter: Did the ray hit something? -/
-- @[extern "lean_raylib__RayCollision_hit_set"]
-- opaque RayCollision.set_hit (hit : Bool) (self : RayCollision) : RayCollision
-- /-- Getter: Distance to nearest hit -/
-- @[extern "lean_raylib__RayCollision_distance"]
-- opaque RayCollision.distance : RayCollision -> Float
-- /-- Setter: Distance to nearest hit -/
-- @[extern "lean_raylib__RayCollision_distance_set"]
-- opaque RayCollision.set_distance (distance : Float) (self : RayCollision) : RayCollision
-- /-- Getter: Point of nearest hit -/
-- @[extern "lean_raylib__RayCollision_point"]
-- opaque RayCollision.point : RayCollision -> Vector3
-- /-- Setter: Point of nearest hit -/
-- @[extern "lean_raylib__RayCollision_point_set"]
-- opaque RayCollision.set_point (point : Vector3) (self : RayCollision) : RayCollision
-- /-- Getter: Surface normal of hit -/
-- @[extern "lean_raylib__RayCollision_normal"]
-- opaque RayCollision.normal : RayCollision -> Vector3
-- /-- Setter: Surface normal of hit -/
-- @[extern "lean_raylib__RayCollision_normal_set"]
-- opaque RayCollision.set_normal (normal : Vector3) (self : RayCollision) : RayCollision
-- opaque BoundingBoxPointed : NonemptyType
-- /-- BoundingBox -/
-- def BoundingBox : Type := BoundingBoxPointed.type
-- instance : Nonempty BoundingBox := BoundingBoxPointed.property
-- @[extern "lean_raylib__BoundingBox_mk"]
-- opaque BoundingBox.mk (min : Vector3) (max : Vector3) : BoundingBox
-- /-- Getter: Minimum vertex box-corner -/
-- @[extern "lean_raylib__BoundingBox_min"]
-- opaque BoundingBox.min : BoundingBox -> Vector3
-- /-- Setter: Minimum vertex box-corner -/
-- @[extern "lean_raylib__BoundingBox_min_set"]
-- opaque BoundingBox.set_min (min : Vector3) (self : BoundingBox) : BoundingBox
-- /-- Getter: Maximum vertex box-corner -/
-- @[extern "lean_raylib__BoundingBox_max"]
-- opaque BoundingBox.max : BoundingBox -> Vector3
-- /-- Setter: Maximum vertex box-corner -/
-- @[extern "lean_raylib__BoundingBox_max_set"]
-- opaque BoundingBox.set_max (max : Vector3) (self : BoundingBox) : BoundingBox
-- opaque WavePointed : NonemptyType
-- /-- Wave, audio wave data -/
-- def Wave : Type := WavePointed.type
-- instance : Nonempty Wave := WavePointed.property
-- @[extern "lean_raylib__Wave_mk"]
-- opaque Wave.mk : Wave
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | frameCount: unsigned int -- Total number of frames (considering channels)
--   | sampleRate: unsigned int -- Frequency (samples per second)
--   | sampleSize: unsigned int -- Bit depth (bits per sample): 8, 16, 32 (24 not supported)
--   | channels: unsigned int -- Number of channels (1-mono, 2-stereo, ...)
--   | data: void * -- Buffer data pointer
-- -/
-- /-- Getter: Total number of frames (considering channels) -/
-- @[extern "lean_raylib__Wave_frameCount"]
-- opaque Wave.frameCount : Wave -> UInt32
-- /-- Setter: Total number of frames (considering channels) -/
-- @[extern "lean_raylib__Wave_frameCount_set"]
-- opaque Wave.set_frameCount (frameCount : UInt32) (self : Wave) : Wave
-- /-- Getter: Frequency (samples per second) -/
-- @[extern "lean_raylib__Wave_sampleRate"]
-- opaque Wave.sampleRate : Wave -> UInt32
-- /-- Setter: Frequency (samples per second) -/
-- @[extern "lean_raylib__Wave_sampleRate_set"]
-- opaque Wave.set_sampleRate (sampleRate : UInt32) (self : Wave) : Wave
-- /-- Getter: Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
-- @[extern "lean_raylib__Wave_sampleSize"]
-- opaque Wave.sampleSize : Wave -> UInt32
-- /-- Setter: Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
-- @[extern "lean_raylib__Wave_sampleSize_set"]
-- opaque Wave.set_sampleSize (sampleSize : UInt32) (self : Wave) : Wave
-- /-- Getter: Number of channels (1-mono, 2-stereo, ...) -/
-- @[extern "lean_raylib__Wave_channels"]
-- opaque Wave.channels : Wave -> UInt32
-- /-- Setter: Number of channels (1-mono, 2-stereo, ...) -/
-- @[extern "lean_raylib__Wave_channels_set"]
-- opaque Wave.set_channels (channels : UInt32) (self : Wave) : Wave
-- /-- Getter: Buffer data pointer -/
-- @[extern "lean_raylib__Wave_data"]
-- opaque Wave.data : Wave -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Buffer data pointer -/
-- @[extern "lean_raylib__Wave_data_set"]
-- opaque Wave.set_data (data : Unit) (self : Wave) : Wave
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- opaque AudioStreamPointed : NonemptyType
-- /-- AudioStream, custom audio stream -/
-- def AudioStream : Type := AudioStreamPointed.type
-- instance : Nonempty AudioStream := AudioStreamPointed.property
-- @[extern "lean_raylib__AudioStream_mk"]
-- opaque AudioStream.mk : AudioStream
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | buffer: unknown_t * -- Pointer to internal data used by the audio system
--   | processor: unknown_t * -- Pointer to internal data processor, useful for audio effects
--   | sampleRate: unsigned int -- Frequency (samples per second)
--   | sampleSize: unsigned int -- Bit depth (bits per sample): 8, 16, 32 (24 not supported)
--   | channels: unsigned int -- Number of channels (1-mono, 2-stereo, ...)
-- -/
-- /-- Getter: Pointer to internal data used by the audio system -/
-- @[extern "lean_raylib__AudioStream_buffer"]
-- opaque AudioStream.buffer : AudioStream -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Pointer to internal data used by the audio system -/
-- @[extern "lean_raylib__AudioStream_buffer_set"]
-- opaque AudioStream.set_buffer (buffer : Unit) (self : AudioStream) : AudioStream
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Pointer to internal data processor, useful for audio effects -/
-- @[extern "lean_raylib__AudioStream_processor"]
-- opaque AudioStream.processor : AudioStream -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Pointer to internal data processor, useful for audio effects -/
-- @[extern "lean_raylib__AudioStream_processor_set"]
-- opaque AudioStream.set_processor (processor : Unit) (self : AudioStream) : AudioStream
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- /-- Getter: Frequency (samples per second) -/
-- @[extern "lean_raylib__AudioStream_sampleRate"]
-- opaque AudioStream.sampleRate : AudioStream -> UInt32
-- /-- Setter: Frequency (samples per second) -/
-- @[extern "lean_raylib__AudioStream_sampleRate_set"]
-- opaque AudioStream.set_sampleRate (sampleRate : UInt32) (self : AudioStream) : AudioStream
-- /-- Getter: Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
-- @[extern "lean_raylib__AudioStream_sampleSize"]
-- opaque AudioStream.sampleSize : AudioStream -> UInt32
-- /-- Setter: Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
-- @[extern "lean_raylib__AudioStream_sampleSize_set"]
-- opaque AudioStream.set_sampleSize (sampleSize : UInt32) (self : AudioStream) : AudioStream
-- /-- Getter: Number of channels (1-mono, 2-stereo, ...) -/
-- @[extern "lean_raylib__AudioStream_channels"]
-- opaque AudioStream.channels : AudioStream -> UInt32
-- /-- Setter: Number of channels (1-mono, 2-stereo, ...) -/
-- @[extern "lean_raylib__AudioStream_channels_set"]
-- opaque AudioStream.set_channels (channels : UInt32) (self : AudioStream) : AudioStream
-- opaque SoundPointed : NonemptyType
-- /-- Sound -/
-- def Sound : Type := SoundPointed.type
-- instance : Nonempty Sound := SoundPointed.property
-- @[extern "lean_raylib__Sound_mk"]
-- opaque Sound.mk (stream : AudioStream) (frameCount : UInt32) : Sound
-- /-- Getter: Audio stream -/
-- @[extern "lean_raylib__Sound_stream"]
-- opaque Sound.stream : Sound -> AudioStream
-- /-- Setter: Audio stream -/
-- @[extern "lean_raylib__Sound_stream_set"]
-- opaque Sound.set_stream (stream : AudioStream) (self : Sound) : Sound
-- /-- Getter: Total number of frames (considering channels) -/
-- @[extern "lean_raylib__Sound_frameCount"]
-- opaque Sound.frameCount : Sound -> UInt32
-- /-- Setter: Total number of frames (considering channels) -/
-- @[extern "lean_raylib__Sound_frameCount_set"]
-- opaque Sound.set_frameCount (frameCount : UInt32) (self : Sound) : Sound
-- opaque MusicPointed : NonemptyType
-- /-- Music, audio stream, anything longer than ~10 seconds should be streamed -/
-- def Music : Type := MusicPointed.type
-- instance : Nonempty Music := MusicPointed.property
-- @[extern "lean_raylib__Music_mk"]
-- opaque Music.mk : Music
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | stream: AudioStream -- Audio stream
--   | frameCount: unsigned int -- Total number of frames (considering channels)
--   | looping: bool -- Music looping enable
--   | ctxType: int -- Type of music context (audio filetype)
--   | ctxData: void * -- Audio context data, depends on type
-- -/
-- /-- Getter: Audio stream -/
-- @[extern "lean_raylib__Music_stream"]
-- opaque Music.stream : Music -> AudioStream
-- /-- Setter: Audio stream -/
-- @[extern "lean_raylib__Music_stream_set"]
-- opaque Music.set_stream (stream : AudioStream) (self : Music) : Music
-- /-- Getter: Total number of frames (considering channels) -/
-- @[extern "lean_raylib__Music_frameCount"]
-- opaque Music.frameCount : Music -> UInt32
-- /-- Setter: Total number of frames (considering channels) -/
-- @[extern "lean_raylib__Music_frameCount_set"]
-- opaque Music.set_frameCount (frameCount : UInt32) (self : Music) : Music
-- /-- Getter: Music looping enable -/
-- @[extern "lean_raylib__Music_looping"]
-- opaque Music.looping : Music -> Bool
-- /-- Setter: Music looping enable -/
-- @[extern "lean_raylib__Music_looping_set"]
-- opaque Music.set_looping (looping : Bool) (self : Music) : Music
-- /-- Getter: Type of music context (audio filetype) -/
-- @[extern "lean_raylib__Music_ctxType"]
-- opaque Music.ctxType : Music -> Int32
-- /-- Setter: Type of music context (audio filetype) -/
-- @[extern "lean_raylib__Music_ctxType_set"]
-- opaque Music.set_ctxType (ctxType : Int32) (self : Music) : Music
-- /-- Getter: Audio context data, depends on type -/
-- @[extern "lean_raylib__Music_ctxData"]
-- opaque Music.ctxData : Music -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Audio context data, depends on type -/
-- @[extern "lean_raylib__Music_ctxData_set"]
-- opaque Music.set_ctxData (ctxData : Unit) (self : Music) : Music
-- /-
-- todo: ^^ struct setter ^^
-- -/
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
-- opaque VrDeviceInfo.hResolution : VrDeviceInfo -> Int32
-- /-- Setter: Horizontal resolution in pixels -/
-- @[extern "lean_raylib__VrDeviceInfo_hResolution_set"]
-- opaque VrDeviceInfo.set_hResolution (hResolution : Int32) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Vertical resolution in pixels -/
-- @[extern "lean_raylib__VrDeviceInfo_vResolution"]
-- opaque VrDeviceInfo.vResolution : VrDeviceInfo -> Int32
-- /-- Setter: Vertical resolution in pixels -/
-- @[extern "lean_raylib__VrDeviceInfo_vResolution_set"]
-- opaque VrDeviceInfo.set_vResolution (vResolution : Int32) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Horizontal size in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_hScreenSize"]
-- opaque VrDeviceInfo.hScreenSize : VrDeviceInfo -> Float
-- /-- Setter: Horizontal size in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_hScreenSize_set"]
-- opaque VrDeviceInfo.set_hScreenSize (hScreenSize : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Vertical size in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_vScreenSize"]
-- opaque VrDeviceInfo.vScreenSize : VrDeviceInfo -> Float
-- /-- Setter: Vertical size in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_vScreenSize_set"]
-- opaque VrDeviceInfo.set_vScreenSize (vScreenSize : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Screen center in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_vScreenCenter"]
-- opaque VrDeviceInfo.vScreenCenter : VrDeviceInfo -> Float
-- /-- Setter: Screen center in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_vScreenCenter_set"]
-- opaque VrDeviceInfo.set_vScreenCenter (vScreenCenter : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Distance between eye and display in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_eyeToScreenDistance"]
-- opaque VrDeviceInfo.eyeToScreenDistance : VrDeviceInfo -> Float
-- /-- Setter: Distance between eye and display in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_eyeToScreenDistance_set"]
-- opaque VrDeviceInfo.set_eyeToScreenDistance (eyeToScreenDistance : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Lens separation distance in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_lensSeparationDistance"]
-- opaque VrDeviceInfo.lensSeparationDistance : VrDeviceInfo -> Float
-- /-- Setter: Lens separation distance in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_lensSeparationDistance_set"]
-- opaque VrDeviceInfo.set_lensSeparationDistance (lensSeparationDistance : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: IPD (distance between pupils) in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_interpupillaryDistance"]
-- opaque VrDeviceInfo.interpupillaryDistance : VrDeviceInfo -> Float
-- /-- Setter: IPD (distance between pupils) in meters -/
-- @[extern "lean_raylib__VrDeviceInfo_interpupillaryDistance_set"]
-- opaque VrDeviceInfo.set_interpupillaryDistance (interpupillaryDistance : Float) (self : VrDeviceInfo) : VrDeviceInfo
-- /-- Getter: Lens distortion constant parameters -/
-- @[extern "lean_raylib__VrDeviceInfo_lensDistortionValues"]
-- opaque VrDeviceInfo.lensDistortionValues : VrDeviceInfo -> Unit
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
-- opaque VrDeviceInfo.chromaAbCorrection : VrDeviceInfo -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Chromatic aberration correction parameters -/
-- @[extern "lean_raylib__VrDeviceInfo_chromaAbCorrection_set"]
-- opaque VrDeviceInfo.set_chromaAbCorrection (chromaAbCorrection : Unit) (self : VrDeviceInfo) : VrDeviceInfo
-- /-
-- todo: ^^ struct setter ^^
-- -/
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
-- opaque VrStereoConfig.projection : VrStereoConfig -> Unit
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
-- opaque VrStereoConfig.viewOffset : VrStereoConfig -> Unit
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
-- opaque VrStereoConfig.leftLensCenter : VrStereoConfig -> Unit
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
-- opaque VrStereoConfig.rightLensCenter : VrStereoConfig -> Unit
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
-- opaque VrStereoConfig.leftScreenCenter : VrStereoConfig -> Unit
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
-- opaque VrStereoConfig.rightScreenCenter : VrStereoConfig -> Unit
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
-- opaque VrStereoConfig.scale : VrStereoConfig -> Unit
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
-- opaque VrStereoConfig.scaleIn : VrStereoConfig -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: VR distortion scale in -/
-- @[extern "lean_raylib__VrStereoConfig_scaleIn_set"]
-- opaque VrStereoConfig.set_scaleIn (scaleIn : Unit) (self : VrStereoConfig) : VrStereoConfig
-- /-
-- todo: ^^ struct setter ^^
-- -/
-- opaque FilePathListPointed : NonemptyType
-- /-- File path list -/
-- def FilePathList : Type := FilePathListPointed.type
-- instance : Nonempty FilePathList := FilePathListPointed.property
-- @[extern "lean_raylib__FilePathList_mk"]
-- opaque FilePathList.mk : FilePathList
-- /- todo: ^^ struct constructor ^^
--   fields:
--   | capacity: unsigned int -- Filepaths max entries
--   | count: unsigned int -- Filepaths entries count
--   | paths: char * * -- Filepaths entries
-- -/
-- /-- Getter: Filepaths max entries -/
-- @[extern "lean_raylib__FilePathList_capacity"]
-- opaque FilePathList.capacity : FilePathList -> UInt32
-- /-- Setter: Filepaths max entries -/
-- @[extern "lean_raylib__FilePathList_capacity_set"]
-- opaque FilePathList.set_capacity (capacity : UInt32) (self : FilePathList) : FilePathList
-- /-- Getter: Filepaths entries count -/
-- @[extern "lean_raylib__FilePathList_count"]
-- opaque FilePathList.count : FilePathList -> UInt32
-- /-- Setter: Filepaths entries count -/
-- @[extern "lean_raylib__FilePathList_count_set"]
-- opaque FilePathList.set_count (count : UInt32) (self : FilePathList) : FilePathList
-- /-- Getter: Filepaths entries -/
-- @[extern "lean_raylib__FilePathList_paths"]
-- opaque FilePathList.paths : FilePathList -> Unit
-- /-
-- todo: ^^ struct getter ^^
-- -/
-- /-- Setter: Filepaths entries -/
-- @[extern "lean_raylib__FilePathList_paths_set"]
-- opaque FilePathList.set_paths (paths : Unit) (self : FilePathList) : FilePathList
-- /-
-- todo: ^^ struct setter ^^
-- -/

end Raylib
