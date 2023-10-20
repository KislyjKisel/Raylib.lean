import Pod.BytesView
import Raymath.Core
import Raylib.Enumerations
import Raylib.Util.RangeMap

open Pod (Float32 Int32)
open Raymath (Vector2 Vector3 Vector4 Matrix Quaternion)

namespace Raylib

@[extern "lean_raylib_initialize_Structures"] private
opaque «initialize» : BaseIO Unit

builtin_initialize «initialize»

/-! # Context -/

opaque ContextPointed : NonemptyType
def Context : Type := ContextPointed.type
instance : Nonempty Context := ContextPointed.property


/-! # VaList -/

opaque VaListPointed (σ : Type) : NonemptyType
def VaList (σ : Type) : Type := (VaListPointed σ).type
instance {σ} : Nonempty (VaList σ) := (VaListPointed σ).property

inductive VaArg where
-- Tag values are inspected by native code in `lean_raylib__VaList_next`
| i32 | u32 | u64 | f64 | cstr

def VaArg.type : VaArg → Type
| i32 => Int32
| u32 => UInt32
| u64 => UInt64
| f64 => Float
| cstr => String

instance {a : VaArg} : Inhabited a.type where
  default := match a with
  | .i32 => (default : Int32)
  | .u32 => (default : UInt32)
  | .u64 => (default : UInt64)
  | .f64 => (default : Float)
  | .cstr => (default : String)

/-- **unsafe**: causes UB if called too many times or when called with an incorrect `VaArg` -/
@[extern "lean_raylib__VaList_next"]
opaque VaList.next {σ} (vl : @& VaList σ) (a : VaArg) : ST σ a.type


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
    ((v.x.max 0).min 255).toUInt8
    ((v.y.max 0).min 255).toUInt8
    ((v.z.max 0).min 255).toUInt8
    ((v.w.max 0).min 255).toUInt8

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

def Rectangle.position (rect : Rectangle) : Vector2 :=
  { rect with }

def Rectangle.size (rect : Rectangle) : Vector2 :=
  { x := rect.width, y := rect.height }

def Rectangle.move (offset : Vector2) (rect : Rectangle) : Rectangle :=
  { rect with
    x := rect.x + offset.x
    y := rect.y + offset.y
  }


/-! # Image -/

opaque ImagePointed : NonemptyType
/-- Image, pixel data stored in CPU memory (RAM) -/
def Image : Type := ImagePointed.type
instance : Nonempty Image := ImagePointed.property

/-- Image base width -/
@[extern "lean_raylib__Image_width"]
opaque Image.width (self : @& Image) : UInt32

/-- Image base height -/
@[extern "lean_raylib__Image_height"]
opaque Image.height (self : @& Image) : UInt32

/-- Mipmap levels, 1 by default -/
@[extern "lean_raylib__Image_mipmaps"]
opaque Image.mipmaps (self : @& Image) : UInt32

/-- Data format (PixelFormat type) -/
@[extern "lean_raylib__Image_format"]
opaque Image.format (self : @& Image) : PixelFormat

@[extern "lean_raylib__Image_getEmpty"]
private opaque Image.getEmpty : Unit → Image

def Image.empty : Image := Image.getEmpty ()


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

@[extern "lean_raylib__Texture_getEmpty"]
private opaque Texture.getEmpty : Unit → Texture

/-- null -/
def Texture.empty : Texture := Texture.getEmpty ()

/-- Texture used on shapes drawing (usually a white pixel) -/
@[extern "lean_raylib__Texture_getDefault"]
opaque Texture.getDefault (ctx : Context) : Texture


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

/-- NPatchInfo, n-patch layout info -/
structure NPatchInfo where
  /-- Texture source rectangle (x) -/
  sourceX : Float32
  /-- Texture source rectangle (y) -/
  sourceY : Float32
  /-- Texture source rectangle (width) -/
  sourceWidth : Float32
  /-- Texture source rectangle (height) -/
  sourceHeight : Float32
  /-- Left border offset -/
  left : UInt32
  /-- Top border offset -/
  top : UInt32
  /-- Right border offset -/
  right : UInt32
  /-- Bottom border offset -/
  bottom : UInt32
  /-- Layout of the n-patch: 3x3, 1x3 or 3x1 -/
  layout : NPatchLayout


/-! # Glyph info -/

structure GlyphInfo where
  /-- Character value (Unicode) -/
  value : Char
  /-- Character offset X when drawing -/
  offsetX : UInt32
  /-- Character offset Y when drawing -/
  offsetY : UInt32
  /-- Character advance position X -/
  advanceX : UInt32
  /-- Character image data -/
  image : Image
deriving Nonempty


/-! # Font -/

opaque FontPointed : NonemptyType
/-- Font, font texture and GlyphInfo array data -/
def Font : Type := FontPointed.type
instance : Nonempty Font := FontPointed.property

/-- Base size (default chars height) -/
@[extern "lean_raylib__Font_baseSize"]
opaque Font.baseSize (font : @& Font) : UInt32

/-- Number of glyph characters -/
@[extern "lean_raylib__Font_glyphCount"]
opaque Font.glyphCount (font : @& Font) : UInt32

/-- Padding around the glyph characters -/
@[extern "lean_raylib__Font_glyphPadding"]
opaque Font.glyphPadding (font : @& Font) : UInt32

/-- Texture atlas containing the glyphs -/
@[extern "lean_raylib__Font_texture"]
opaque Font.texture (font : Font) : TextureRef

/-- Rectangles in texture for the glyphs -/
@[extern "lean_raylib__Font_recs"]
opaque Font.recs (font : @& Font) : Array Rectangle


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

opaque MeshPointed : NonemptyType
/-- Mesh, vertex data and vao/vbo -/
def Mesh : Type := MeshPointed.type
instance : Nonempty Mesh := MeshPointed.property

structure Mesh.Skinning (vertexCount : UInt32) where
  boneIds : Pod.BytesView (vertexCount.toNat * 4 * Pod.byteSize UInt8) 1
  boneWeights : Pod.BytesView (vertexCount.toNat * 4 * Pod.byteSize Float32) 1

/-- `MAX_MESH_VERTEX_BUFFERS` -/
abbrev Mesh.maxVertexBuffers : Nat := 7

def Mesh.bufferSize (vertexCount triangleCount : Nat) : Fin Mesh.maxVertexBuffers → Nat
| ⟨0, _⟩ => vertexCount * 3 * Pod.byteSize Float32
| ⟨1, _⟩ => vertexCount * 2 * Pod.byteSize Float32
| ⟨2, _⟩ => vertexCount * 3 * Pod.byteSize Float32
| ⟨3, _⟩ => vertexCount * 4
| ⟨4, _⟩ => vertexCount * 4 * Pod.byteSize Float32
| ⟨5, _⟩ => vertexCount * 2 * Pod.byteSize Float32
| ⟨6, _⟩ => triangleCount * 3 * Pod.byteSize UInt16

/-- NOTE: Skinning requires normals and is ignored otherwise -/
@[extern "lean_raylib__Mesh_mkBv"]
opaque Mesh.mkBv
  (ctx : Context)
  (vertexCount : UInt32)
  (vertices : @& Pod.BytesView (vertexCount.toNat * 3 * Pod.byteSize Float32) 1)
  (texcoords : @& (Option $ Pod.BytesView (vertexCount.toNat * 2 * Pod.byteSize Float32) 1))
  (texcoords2 : @& (Option $ Pod.BytesView (vertexCount.toNat * 2 * Pod.byteSize Float32) 1))
  (normals : @& (Option $ Pod.BytesView (vertexCount.toNat * 3 * Pod.byteSize Float32) 1))
  (tangents : @& (Option $ Pod.BytesView (vertexCount.toNat * 4 * Pod.byteSize Float32) 1))
  (colors : @& (Option $ Pod.BytesView (vertexCount.toNat * 4 * Pod.byteSize UInt8) 1))
  (skinning : @& Option (Mesh.Skinning vertexCount))
  : Mesh

/--
NOTE: If `∃ i j, indices[i][j] ≥ vertexCount` then rendering is UB; panics in debug builds.
NOTE: Skinning requires normals and is ignored otherwise.
-/
@[extern "lean_raylib__Mesh_mkIndexedBv"]
opaque Mesh.mkIndexedBv
  (ctx : Context)
  (vertexCount : UInt32) (triangleCount : UInt32)
  (vertices : @& Pod.BytesView (vertexCount.toNat * 3 * Pod.byteSize Float32) 1)
  (indices : @& Pod.BytesView (triangleCount.toNat * 3 * Pod.byteSize UInt16) 1)
  (texcoords : @& (Option $ Pod.BytesView (vertexCount.toNat * 2 * Pod.byteSize Float32) 1))
  (texcoords2 : @& (Option $ Pod.BytesView (vertexCount.toNat * 2 * Pod.byteSize Float32) 1))
  (normals : @& (Option $ Pod.BytesView (vertexCount.toNat * 3 * Pod.byteSize Float32) 1))
  (tangents : @& (Option $ Pod.BytesView (vertexCount.toNat * 4 * Pod.byteSize Float32) 1))
  (colors : @& (Option $ Pod.BytesView (vertexCount.toNat * 4 * Pod.byteSize UInt8) 1))
  (skinning : @& Option (Mesh.Skinning vertexCount))
  : Mesh

/-- Number of vertices stored in arrays -/
@[extern "lean_raylib__Mesh_vertexCount"]
opaque Mesh.vertexCount (self : @& Mesh) : UInt32

/-- Number of triangles stored (indexed or not) -/
@[extern "lean_raylib__Mesh_triangleCount"]
opaque Mesh.triangleCount (self : @& Mesh) : UInt32

/-- Vertex position (XYZ - 3 components per vertex) (shader-location = 0) -/
@[extern "lean_raylib__Mesh_vertices"]
opaque Mesh.vertices (self : Mesh) : Pod.BytesView (self.vertexCount.toNat * 3 * Pod.byteSize Float32) (Pod.alignment Float32)

/-- Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1) -/
@[extern "lean_raylib__Mesh_texcoords"]
opaque Mesh.texcoords (self : Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 2 * Pod.byteSize Float32) (Pod.alignment Float32)

/-- Vertex texture second coordinates (UV - 2 components per vertex) (shader-location = 5) -/
@[extern "lean_raylib__Mesh_texcoords2"]
opaque Mesh.texcoords2 (self : Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 2 * Pod.byteSize Float32) (Pod.alignment Float32)

/-- Vertex normals (XYZ - 3 components per vertex) (shader-location = 2) -/
@[extern "lean_raylib__Mesh_normals"]
opaque Mesh.normals (self : Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 3 * Pod.byteSize Float32) (Pod.alignment Float32)

/-- Vertex tangents (XYZW - 4 components per vertex) (shader-location = 4) -/
@[extern "lean_raylib__Mesh_tangents"]
opaque Mesh.tangents (self : Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 4 * Pod.byteSize Float32) (Pod.alignment Float32)

/-- Vertex colors (RGBA - 4 components per vertex) (shader-location = 3) -/
@[extern "lean_raylib__Mesh_colors"]
opaque Mesh.colors (self : Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 4 * Pod.byteSize UInt8) (Pod.alignment UInt8)

/-- Vertex indices (in case vertex data comes indexed) -/
@[extern "lean_raylib__Mesh_indices"]
opaque Mesh.indices (self : Mesh) : Option $ Pod.BytesView (self.triangleCount.toNat * 3 * Pod.byteSize UInt16) (Pod.alignment UInt16)

/-- Animated vertex positions (after bones transformations) -/
@[extern "lean_raylib__Mesh_animVertices"]
opaque Mesh.animVertices (self : @& Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 3 * Pod.byteSize Float32) (Pod.alignment Float32)

/-- Animated normals (after bones transformations) -/
@[extern "lean_raylib__Mesh_animNormals"]
opaque Mesh.animNormals (self : @& Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 3 * Pod.byteSize Float32) (Pod.alignment Float32)

/-- Vertex bone ids, max 255 bone ids, up to 4 bones influence by vertex (skinning) -/
@[extern "lean_raylib__Mesh_boneIds"]
opaque Mesh.boneIds (self : @& Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 4 * Pod.byteSize UInt8) (Pod.alignment UInt8)

/-- Vertex bone weight, up to 4 bones influence by vertex (skinning) -/
@[extern "lean_raylib__Mesh_boneWeights"]
opaque Mesh.boneWeights (self : @& Mesh) : Option $ Pod.BytesView (self.vertexCount.toNat * 4 * Pod.byteSize Float32) (Pod.alignment Float32)

/-- OpenGL Vertex Array Object id -/
@[extern "lean_raylib__Mesh_vaoId"]
opaque Mesh.vaoId (self : @& Mesh) : UInt32

/-- OpenGL Vertex Buffer Objects id (default vertex data) -/
@[extern "lean_raylib__Mesh_vboId"]
opaque Mesh.vboId (self : @& Mesh) (i : @& Fin Mesh.maxVertexBuffers) : UInt32


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

@[extern "lean_raylib__Shader_getDefault"]
opaque Shader.getDefault (ctx : Context) : Shader


/-! # Material -/

structure MaterialMap where
  texture : Texture
  color : Color := .mk 0xFFFFFFFF
  value : Float32 := 0
deriving Nonempty

def MaterialMap.empty : MaterialMap where
  texture := Texture.empty
  color := .mk 0

abbrev MaterialMapArray : Type := RangeMap 0 maxMaterialMaps.toUInt32 MaterialMap

namespace MaterialMapArray

def ofFn (f : MaterialMapIndex → MaterialMap) : MaterialMapArray :=
  RangeMap.ofFn (by decide) (λ i h ↦ f ⟨i, h.2⟩)

def get (a : MaterialMapArray) (i : MaterialMapIndex) : MaterialMap :=
  RangeMap.get a i.val ⟨Nat.zero_le _, i.property⟩

def set (a : MaterialMapArray) (i : MaterialMapIndex) (m : MaterialMap) : MaterialMapArray :=
  RangeMap.set a i.val m ⟨Nat.zero_le _, i.property⟩

end MaterialMapArray

structure Material where
  shader : Shader
  maps : MaterialMapArray
  param0 : Float32 := .zero
  param1 : Float32 := .zero
  param2 : Float32 := .zero
  param3 : Float32 := .zero
deriving Nonempty

def Material.params (m : Material) : Vector4 :=
  Vector4.mk m.param0 m.param1 m.param2 m.param3

def Material.getDefault (ctx : Context) : Material where
  shader := Shader.getDefault ctx
  maps := .ofFn λ
    | .diffuse => {
      texture := .getDefault ctx
    }
    | .specular => {
      texture := .empty
    }
    | _ => .empty


/-! # Transform -/

/-- Transform, vertex transformation data -/
structure Transform where
  translation : Vector3
  rotation : Quaternion
  scale : Vector3
deriving Inhabited, Repr


/-! # Bone info -/

/-- Bone, skeletal animation bone -/
structure BoneInfo where
  /-- Truncated if its byte size is greater than 31 -/
  name : String
  parent : Option UInt32
deriving Inhabited, Repr


/-! # Model -/

opaque ModelPointed : NonemptyType
/-- Model, meshes, materials and animation data created with raylib's functions -/
def Model : Type := ModelPointed.type
instance : Nonempty Model := ModelPointed.property

@[extern "lean_raylib__Model_mk"]
opaque Model.mk
  (transform : @& Matrix)
  (materials : Array Material)
  (meshes : Array (Mesh × Fin materials.size))
  (bones : @& Array BoneInfo)
  (bindPose : @& { a : Array Transform // a.size = bones.size })
  : Model

/-- Local transform matrix -/
@[extern "lean_raylib__Model_transform"]
opaque Model.transform (model : @& Model) : Matrix

/-- Set local transform matrix -/
@[extern "lean_raylib__Model_setTransform"]
opaque Model.setTransform (transform : @& Matrix) (model : Model) : Model

/-- Number of meshes -/
@[extern "lean_raylib__Model_meshCount"]
opaque Model.meshCount (model : @& Model) : UInt32

/-- Number of materials -/
@[extern "lean_raylib__Model_materialCount"]
opaque Model.materialCount (model : @& Model) : { i : UInt32 // 0 < i ∨ model.meshCount = 0 } :=
  .mk 1 (Or.inl Nat.zero_lt_one)

/-- Number of bones -/
@[extern "lean_raylib__Model_boneCount"]
opaque Model.boneCount (model : @& Model) : UInt32

/-- Bone information (skeleton) -/
@[extern "lean_raylib__Model_bone"]
opaque Model.bone (model : @& Model) (i : UInt32) (h : i < model.boneCount) : BoneInfo

/-- Bone base transformation (pose) -/
@[extern "lean_raylib__Model_bindPose"]
opaque Model.bindPose (model : @& Model) (i : UInt32) (h : i < model.boneCount) : Transform

@[extern "lean_raylib__Model_material"]
opaque Model.material (model : @& Model) (i : UInt32) (h : i < model.materialCount) : Material

def Model.material? (model : Model) (i : UInt32) : Option Material :=
  if h: i < model.materialCount
    then some $ material model i h
    else none

@[extern "lean_raylib__Model_setMaterial"]
opaque Model.setMaterial (model : Model) (i : UInt32) (mat : Material) (h : i < model.materialCount) : Model

def Model.setMaterial? (model : Model) (i : UInt32) (mat : Material) : Model :=
  if h: i < model.materialCount
    then setMaterial model i mat h
    else model

@[extern "lean_raylib__Model_addMaterial"]
opaque Model.addMaterial (model : Model) (mat : Material) : Model

@[extern "lean_raylib__Model_removeMaterial"]
opaque Model.removeMaterial (model : Model) (i : UInt32)
  (h₁ : i < model.materialCount) (h₂ : 1 < model.materialCount.1) : Model

def Model.removeMaterial? (model : Model) (i : UInt32) : Model :=
  if h: i < model.materialCount ∧ 1 < model.materialCount.1
    then removeMaterial model i h.1 h.2
    else model

@[extern "lean_raylib__Model_meshMaterial"]
opaque Model.meshMaterial (model : @& Model) (i : UInt32) (h : i < model.meshCount) :
  { j : UInt32 // j < model.materialCount } :=
    .mk 0 $ by
      have := Nat.zero_lt_of_lt h
      cases model.materialCount.2
      assumption
      case inr h =>
        rewrite [h] at this
        contradiction

def Model.meshMaterial? (model : @& Model) (i : UInt32) :
  Option { j : UInt32 // j < model.materialCount } :=
    if h: i < model.meshCount
      then some $ model.meshMaterial i h
      else none

@[extern "lean_raylib__Model_setMeshMaterial"]
opaque Model.setMeshMaterial (model : Model) (i j : UInt32)
  (h₁ : i < model.meshCount) (h₂ : j < model.materialCount) : Model

def Model.setMeshMaterial? (model : Model) (i j : UInt32) : Model :=
  if h: i < model.meshCount ∧ j < model.materialCount
    then setMeshMaterial model i j h.1 h.2
    else model


/-! # Model animation -/

opaque ModelAnimationPointed : NonemptyType
def ModelAnimation : Type := ModelAnimationPointed.type
instance : Nonempty ModelAnimation := ModelAnimationPointed.property

@[extern "lean_raylib__ModelAnimation_mk"]
opaque ModelAnimation.mk (bones : @& Array BoneInfo)
  (framePoses : @& Array { a : Array Transform // a.size = bones.size }) : ModelAnimation

/-- Number of bones -/
@[extern "lean_raylib__ModelAnimation_boneCount"]
opaque ModelAnimation.boneCount (anim : @& ModelAnimation) : UInt32

/-- Number of animation frames -/
@[extern "lean_raylib__ModelAnimation_frameCount"]
opaque ModelAnimation.frameCount (anim : @& ModelAnimation) : UInt32

/-- Bone information (skeleton) -/
@[extern "lean_raylib__ModelAnimation_bone"]
opaque ModelAnimation.bone (anim : @& ModelAnimation) (i : UInt32) (h : i < anim.boneCount) : BoneInfo

def ModelAnimation.bone? (anim : ModelAnimation) (i : UInt32) : Option BoneInfo :=
  if h: i < anim.boneCount
    then some $ bone anim i h
    else none

/-- Set bone information (skeleton) -/
@[extern "lean_raylib__ModelAnimation_setBone"]
opaque ModelAnimation.setBone (anim : ModelAnimation) (i : UInt32) (bone : @& BoneInfo)
  (h : i < anim.boneCount) : ModelAnimation

def ModelAnimation.setBone? (anim : ModelAnimation) (i : UInt32) (bone : BoneInfo) : ModelAnimation :=
  if h: i < anim.boneCount
    then setBone anim i bone h
    else anim

/-- Pose bone transform -/
@[extern "lean_raylib__ModelAnimation_framePose"]
opaque ModelAnimation.framePose (anim : @& ModelAnimation) (i j : UInt32)
  (h₁ : i < anim.frameCount) (h₂ : j < anim.boneCount) : Transform

def ModelAnimation.framePose? (anim : ModelAnimation) (i j : UInt32) : Option Transform :=
  if h: i < anim.frameCount ∧ j < anim.boneCount
    then some $ framePose anim i j h.1 h.2
    else none

/-- Set pose bone transform -/
@[extern "lean_raylib__ModelAnimation_setFramePose"]
opaque ModelAnimation.setFramePose (anim : ModelAnimation) (i j : UInt32) (t : @& Transform)
  (h₁ : i < anim.frameCount) (h₂ : j < anim.boneCount) : ModelAnimation

def ModelAnimation.setFramePose? (anim : ModelAnimation) (i j : UInt32) (t : Transform) : ModelAnimation :=
  if h: i < anim.frameCount ∧ j < anim.boneCount
    then setFramePose anim i j t h.1 h.2
    else anim


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

opaque AudioStreamPointed (st : AudioSampleType) : NonemptyType
/-- AudioStream, custom audio stream -/
def AudioStream (st : AudioSampleType) : Type := (AudioStreamPointed st).type
instance {st} : Nonempty (AudioStream st) := (AudioStreamPointed st).property

/-- Frequency (samples per second) -/
@[extern "lean_raylib__AudioStream_sampleRate"]
opaque AudioStream.sampleRate {st} (self : @& AudioStream st) : UInt32

/-- Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
@[extern "lean_raylib__AudioStream_sampleSize"]
def AudioStream.sampleSize {st} (self : @& AudioStream st) : UInt32 := st.size

/-- Number of channels (1-mono, 2-stereo, ...) -/
@[extern "lean_raylib__AudioStream_channels"]
opaque AudioStream.channels {st} (self : @& AudioStream st) : UInt32


/-! # Sound -/

opaque SoundPointed : NonemptyType
/-- Sound -/
def Sound : Type := SoundPointed.type
instance : Nonempty Sound := SoundPointed.property

/-- Frequency (samples per second) -/
@[extern "lean_raylib__Sound_sampleRate"]
opaque Sound.sampleRate (sound : @& Sound) : UInt32

/-- Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
@[extern "lean_raylib__Sound_sampleSize"]
opaque Sound.sampleSize (sound : @& Sound) : UInt32

/-- Number of channels (1-mono, 2-stereo, ...) -/
@[extern "lean_raylib__Sound_channels"]
opaque Sound.channels (sound : @& Sound) : UInt32

/-- Total number of frames (considering channels) -/
@[extern "lean_raylib__Sound_frameCount"]
opaque Sound.frameCount (sound : @& Sound) : UInt32

/-! # Music -/

opaque MusicPointed : NonemptyType
/-- Music, audio stream, anything longer than ~10 seconds should be streamed -/
def Music : Type := MusicPointed.type
instance : Nonempty Music := MusicPointed.property

/-- Getter: Frequency (samples per second) -/
@[extern "lean_raylib__Music_sampleRate"]
opaque Music.sampleRate (music : @& Music) : UInt32

/-- Bit depth (bits per sample): 8, 16, 32 (24 not supported) -/
@[extern "lean_raylib__Music_sampleSize"]
opaque Music.sampleSize (music : @& Music) : UInt32

/-- Number of channels (1-mono, 2-stereo, ...) -/
@[extern "lean_raylib__Music_channels"]
opaque Music.channels (music : @& Music) : UInt32

/-- Total number of frames (considering channels) -/
@[extern "lean_raylib__Music_frameCount"]
opaque Music.frameCount (music : @& Music) : UInt32

/-- Music looping enable -/
@[extern "lean_raylib__Music_looping"]
opaque Music.looping (music : @& Music) : BaseIO Bool

/-- Set music looping enable -/
@[extern "lean_raylib__Music_looping_set"]
opaque Music.setLooping (looping : Bool) (music : @& Music) : BaseIO Unit


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
