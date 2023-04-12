import Raymath
import Raylib.Enumerations

set_option autoImplicit false

open Pod (Float32)
open Raymath (Vector2 Vector3 Vector4 Matrix)

namespace Raylib

/-! # Color -/

/-- Color, 4 components, 8 bits per component -/
structure Color where
  /-- R8G8B8A8 -/
  rgba : UInt32
deriving Inhabited, Repr

namespace Color

def fromRgba (r g b a : UInt8) : Color :=
  Color.mk $
    r.toUInt32 <<< 24 |||
    g.toUInt32 <<< 16 |||
    b.toUInt32 <<< 8 |||
    a.toUInt32 

def r (color : Color) : UInt8 := (Color.rgba color >>> 24).toUInt8
def g (color : Color) : UInt8 := (Color.rgba color >>> 16).toUInt8
def b (color : Color) : UInt8 := (Color.rgba color >>> 8).toUInt8
def a (color : Color) : UInt8 := (Color.rgba color).toUInt8

def set_r (r : UInt8) (color : Color) : Color := ⟨color.rgba &&& ⟨0x00FFFFFF, by decide⟩ ||| (r.toUInt32 <<< 24)⟩
def set_g (g : UInt8) (color : Color) : Color := ⟨color.rgba &&& ⟨0xFF00FFFF, by decide⟩ ||| (g.toUInt32 <<< 16)⟩
def set_b (b : UInt8) (color : Color) : Color := ⟨color.rgba &&& ⟨0xFFFF00FF, by decide⟩ ||| (b.toUInt32 <<< 8)⟩
def set_a (a : UInt8) (color : Color) : Color := ⟨color.rgba &&& ⟨0xFFFFFF00, by decide⟩ ||| a.toUInt32⟩

def toVector4 (color : Color) : Vector4 :=
  Vector4.mk color.r.toFloat32 color.g.toFloat32 color.b.toFloat32 color.a.toFloat32

/--
Clamps vector components between 0 and 255 and convers them to `UInt8` producing a `Color`.
Maps `XYZW` to `RGBA`.
-/
def _root_.Raymath.Vector4.toColor (v : Vector4) : Color :=
  Color.fromRgba
    (v.x.clamp 0 255).toUInt8
    (v.y.clamp 0 255).toUInt8
    (v.z.clamp 0 255).toUInt8
    (v.w.clamp 0 255).toUInt8

end Color


/-! # Rectangle -/

structure Rectangle where
  /-- Top-left corner position `x` -/
  x : Float32
  /-- Top-left corner position `y` -/
  y : Float32
  width : Float32
  height : Float32
deriving Inhabited, Repr


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
/-- Points to a native texture object while holding a reference to its managed owner -/
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

@[extern "lean_raylib__Texture_default"]
private opaque Texture.default_ : Unit → Texture

/-- Texture used on shapes drawing (usually a white pixel) -/
def Texture.default : Texture := Texture.default_ ()


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

/-- Camera, defines position/orientation in 3d space -/
structure Camera3D where
  /-- Camera position -/
  position : Vector3
  /-- Camera target it looks-at -/
  target : Vector3
  /-- Camera up vector (rotation over its axis) -/
  up : Vector3
  /-- Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic -/
  fovy : Float32
  /-- Camera projection: `.perspective` or `.orthographic` -/
  projection : CameraProjection
deriving Inhabited, Repr


/-! # Camera 2D -/

/-- Camera2D, defines position/orientation in 2d space -/
structure Camera2D where
  /-- Camera offset (displacement from target) -/
  offset : Vector2
  /-- Camera target (rotation and zoom origin) -/
  target : Vector2
  /-- Camera rotation in degrees -/
  rotation : Float32
  /-- Camera zoom (scaling), should be `1.0` by default -/
  zoom : Float32
deriving Inhabited, Repr


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

opaque ShaderPointed : NonemptyType
def Shader : Type := ShaderPointed.type
instance : Nonempty Shader := ShaderPointed.property

/-- Shader program id -/
@[extern "lean_raylib__Shader_id"]
opaque Shader.id (self : @& Shader) : UInt32

/-- Shader locations array -/
@[extern "lean_raylib__Shader_locs"]
opaque Shader.locs (self : @& Shader) : Array UInt32

@[extern "lean_raylib__Shader_defaultLoc"]
opaque Shader.defaultLoc (self : @& Shader) (index : ShaderLocationIndex) : Option UInt32


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
-- opaque MaterialMap.value (self : @& MaterialMap) : Float32
-- /-- Setter: Material map value -/
-- @[extern "lean_raylib__MaterialMap_value_set"]
-- opaque MaterialMap.set_value (value : Float32) (self : MaterialMap) : MaterialMap


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

/-- Ray, ray for raycasting -/
structure Ray where
  /-- Ray position (origin) -/
  position : Vector3
  /-- Ray direction -/
  direction : Vector3
deriving Inhabited, Repr


/-! # Ray collision -/

/-- RayCollision, ray hit information -/
structure RayCollision where
  /-- Did the ray hit something? -/
  hit : Bool
  /-- Distance to the nearest hit -/
  distance : Float32
  /-- Point of the nearest hit -/
  point : Vector3
  /-- Surface normal of hit -/
  normal : Vector3
deriving Inhabited, Repr


/-! # Bounding box -/

structure BoundingBox where
  /-- Minimum vertex box-corner -/
  min : Vector3
  /-- Maximum vertex box-corner -/
  max : Vector3
deriving Inhabited, Repr


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

/-- Head-Mounted-Display device parameters -/
structure VrDeviceInfo where
  /-- Horizontal resolution in pixels -/
  hResolution : UInt32
  /-- Vertical resolution in pixels -/
  vResolution : UInt32
  /-- Horizontal size in meters -/
  hScreenSize : Float32
  /-- Vertical size in meters -/
  vScreenSize : Float32
  /-- Screen center in meters -/
  vScreenCenter : Float32
  /-- Distance between eye and display in meters -/
  eyeToScreenDistance : Float32
  /-- Lens separation distance in meters -/
  lensSeparationDistance : Float32
  /-- IPD (distance between pupils) in meters -/
  interpupillaryDistance : Float32
  /-- Lens distortion constant parameters -/
  lensDistortionValues : Vector4
  /-- Chromatic aberration correction parameters -/
  chromaAbCorrection : Vector4
deriving Inhabited, Repr


/-! # Vr stereo config -/

/-- VR stereo rendering configuration for simulator -/
structure VrStereoConfig where
  /-- VR left projection matrix -/
  leftProjection : Matrix
  /-- VR right projection matrix -/
  rightProjection : Matrix
  /-- VR left view offset matrix -/
  leftViewOffset : Matrix
  /-- VR right view offset matrix -/
  rightViewOffset : Matrix
  /-- VR left lens center -/
  leftLensCenter : Vector2
  /-- VR right lens center -/
  rightLensCenter : Vector2
  /-- VR left screen center -/
  leftScreenCenter : Vector2
  /-- VR right screen center -/
  rightScreenCenter : Vector2
  /-- VR distortion scale -/
  scale : Vector2
  /-- VR distortion scale in -/
  scaleIn : Vector2
deriving Inhabited, Repr

/-! # Window handle -/

opaque WindowHandlePointed : NonemptyType
def WindowHandle : Type := WindowHandlePointed.type
instance : Nonempty WindowHandle := WindowHandlePointed.property

end Raylib
