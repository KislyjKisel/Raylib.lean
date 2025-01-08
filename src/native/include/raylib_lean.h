#pragma once

#include <lean/lean.h>
#include <raylib.h>
#include <GLFW/glfw3.h>
#include "raymath_lean.h"

/// Allocate external raylib object.
/// @param sz must be divisible by `LEAN_OBJECT_SIZE_DELTA`
static inline void* lean_raylib_alloc(size_t sz) {
#ifdef LEAN_RAYLIB_ALLOC_NATIVE
    return malloc(sz);
#else
    return (void*)lean_alloc_small_object(sz);
#endif
}

/// Free external raylib object.
/// @param p pointer to memory allocated with `lean_raylib_alloc`
static inline void lean_raylib_free(void* p) {
#ifdef LEAN_RAYLIB_ALLOC_NATIVE
    free(p);
#else
    lean_free_small_object((lean_object*)p);
#endif
}

#define LEAN_RAYLIB_ALLOC_STRUCT(T, n, x)\
    T* n = lean_raylib_alloc(sizeof(T));\
    *n = x;

#define LEAN_RAYLIB_ALLOC_INIT(T, n, ...) LEAN_RAYLIB_ALLOC_STRUCT(T, n, ((T){__VA_ARGS__}));

static inline void* lean_raylib_rlmemdup(const void* src, size_t size) {
    void* dst = RL_MALLOC(size);
    memcpy(dst, src, size);
    return dst;
}


// # Context

typedef struct {
    char* title;
} lean_raylib_Context_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Context, lean_raylib_Context_data*);

static inline lean_obj_res lean_raylib_Context_new (lean_raylib_Context_data ctx) {
    LEAN_RAYLIB_ALLOC_STRUCT(lean_raylib_Context_data, ctxBoxed, ctx);
    return lean_alloc_external(lean_raylib_Context_class, ctxBoxed);
}


// # VaList

typedef struct {
    va_list v;
} lean_raylib_VaList_data;

LEAN_POD_PTR_ALIAS(raylib_VaList, lean_raylib_VaList_data*);


// # Color

static inline Color lean_raylib_Color_fromRepr(uint32_t color) {
    Color res = {
        .r = (uint8_t)((color >> 24) & 0xFF),
        .g = (uint8_t)((color >> 16) & 0xFF),
        .b = (uint8_t)((color >> 8) & 0xFF),
        .a = (uint8_t)(color & 0xFF),
    };
    return res;
}

static inline Color lean_raylib_Color_unbox(b_lean_obj_arg obj) {
    return lean_raylib_Color_fromRepr(lean_unbox_uint32(obj));
}

static inline uint32_t lean_raylib_Color_toRepr(Color color) {
    return (color.r << 24) | (color.g << 16) | (color.b << 8) | color.a;
}

static inline lean_obj_res lean_raylib_Color_box(Color color) {
    return lean_box_uint32(lean_raylib_Color_toRepr(color));
}


// # Rectangle

static inline void lean_raylib_Rectangle_set (b_lean_obj_arg obj, Rectangle r) {
    lean_ctor_set(obj, 0, lean_pod_Float32_box(r.x));
    lean_ctor_set(obj, 1, lean_pod_Float32_box(r.y));
    lean_ctor_set(obj, 2, lean_pod_Float32_box(r.width));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(r.height));
}

static inline lean_object* lean_raylib_Rectangle_box (Rectangle r) {
    lean_object* obj = lean_alloc_ctor(0, 4, 0);
    lean_raylib_Rectangle_set(obj, r);
    return obj;
}

#define lean_raylib_Rectangle_toRepr lean_raylib_Rectangle_box

static inline Rectangle lean_raylib_Rectangle_unbox (b_lean_obj_arg obj) {
    Rectangle r;
    r.x = lean_pod_Float32_unbox(lean_ctor_get(obj, 0));
    r.y = lean_pod_Float32_unbox(lean_ctor_get(obj, 1));
    r.width = lean_pod_Float32_unbox(lean_ctor_get(obj, 2));
    r.height = lean_pod_Float32_unbox(lean_ctor_get(obj, 3));
    return r;
}

#define lean_raylib_Rectangle_fromRepr lean_raylib_Rectangle_unbox


// # Image

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Image, Image*);

extern lean_object* lean_raylib_Image_empty;

static inline lean_object* lean_raylib_Image_box (Image* obj) {
    return lean_alloc_external(lean_raylib_Image_class, (void*)obj);
}

#define lean_raylib_Image_toRepr lean_raylib_Image_box

static inline lean_obj_res lean_raylib_Image_exclusive(lean_obj_arg image_box) {
    if (LEAN_LIKELY(lean_is_exclusive(image_box))) {
        return image_box;
    }
    LEAN_RAYLIB_ALLOC_STRUCT(Image, image_copy, ImageCopy(*lean_raylib_Image_unbox(image_box)));
    lean_object* image_copy_box = lean_raylib_Image_box(image_copy);
    lean_dec_ref(image_box);
    return image_copy_box;
}


// # Texture

typedef struct {
    lean_object* owner; // NOT NULLABLE
    Texture texture;
} lean_raylib_TextureRef_data;

typedef struct {
    Texture texture;
    lean_object* ctx; // NULLABLE
} lean_raylib_Texture_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_TextureRef, lean_raylib_TextureRef_data*);
LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Texture, lean_raylib_Texture_data*);

extern lean_object* lean_raylib_Texture_empty;

static inline lean_object* lean_raylib_TextureRef_box (Texture2D texture, lean_obj_arg owner) {
    LEAN_RAYLIB_ALLOC_INIT(lean_raylib_TextureRef_data, textureRef,
        .texture = texture,
        .owner = owner,
    );
    return lean_alloc_external(lean_raylib_TextureRef_class, textureRef);
}

#define lean_raylib_TextureRef_toRepr lean_raylib_TextureRef_box

static inline lean_object* lean_raylib_Texture_box (Texture texture, lean_obj_arg ctx) {
    LEAN_RAYLIB_ALLOC_INIT(lean_raylib_Texture_data, textureWctx,
        .texture = texture,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Texture_class, (void*)textureWctx);
}

#define lean_raylib_Texture_toRepr lean_raylib_Texture_box


// # Render texture

typedef struct {
    RenderTexture texture;
    lean_object* ctx;
} lean_raylib_RenderTexture_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_RenderTexture, lean_raylib_RenderTexture_data*);

static inline lean_object* lean_raylib_RenderTexture_box (RenderTexture texture, lean_obj_arg ctx) {
    LEAN_RAYLIB_ALLOC_INIT(lean_raylib_RenderTexture_data, rtWctx,
        .texture = texture,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_RenderTexture_class, (void*)rtWctx);
}

#define lean_raylib_RenderTexture_toRepr lean_raylib_RenderTexture_box


// # NPatch info

static inline void lean_raylib_NPatchInfo_set (b_lean_obj_arg obj, NPatchInfo npi) {
    lean_ctor_set(obj, 0, lean_pod_Float32_box(npi.source.x));
    lean_ctor_set(obj, 1, lean_pod_Float32_box(npi.source.y));
    lean_ctor_set(obj, 2, lean_pod_Float32_box(npi.source.width));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(npi.source.height));
    lean_ctor_set(obj, 4, lean_box_uint32(npi.left));
    lean_ctor_set(obj, 5, lean_box_uint32(npi.top));
    lean_ctor_set(obj, 6, lean_box_uint32(npi.right));
    lean_ctor_set(obj, 7, lean_box_uint32(npi.bottom));
    lean_ctor_set(obj, 8, lean_box_uint32(npi.layout));
}

static inline lean_obj_res lean_raylib_NPatchInfo_box (NPatchInfo npi) {
    lean_object* obj = lean_alloc_ctor(0, 9, 0);
    lean_raylib_NPatchInfo_set(obj, npi);
    return obj;
}

#define lean_raylib_NPatchInfo_toRepr lean_raylib_NPatchInfo_box

static inline NPatchInfo lean_raylib_NPatchInfo_unbox (b_lean_obj_arg obj) {
    NPatchInfo r;
    r.source.x = lean_pod_Float32_unbox(lean_ctor_get(obj, 0));
    r.source.y = lean_pod_Float32_unbox(lean_ctor_get(obj, 1));
    r.source.width = lean_pod_Float32_unbox(lean_ctor_get(obj, 2));
    r.source.height = lean_pod_Float32_unbox(lean_ctor_get(obj, 3));
    r.left = lean_unbox_uint32(lean_ctor_get(obj, 4));
    r.top = lean_unbox_uint32(lean_ctor_get(obj, 5));
    r.right = lean_unbox_uint32(lean_ctor_get(obj, 6));
    r.bottom = lean_unbox_uint32(lean_ctor_get(obj, 7));
    r.layout = lean_unbox_uint32(lean_ctor_get(obj, 8));
    return r;
}

#define lean_raylib_NPatchInfo_fromRepr lean_raylib_NPatchInfo_unbox


// # Glyph info

static inline void lean_raylib_GlyphInfo_set_impl (b_lean_obj_arg obj, uint32_t value, uint32_t offsetX, uint32_t offsetY, uint32_t advanceX, lean_obj_arg image) {
    lean_ctor_set(obj, 0, lean_box_uint32(value));
    lean_ctor_set(obj, 1, lean_box_uint32(offsetX));
    lean_ctor_set(obj, 2, lean_box_uint32(offsetY));
    lean_ctor_set(obj, 3, lean_box_uint32(advanceX));
    lean_ctor_set(obj, 4, image);
}

static inline void lean_raylib_GlyphInfo_set (b_lean_obj_arg obj, uint32_t value, uint32_t offsetX, uint32_t offsetY, uint32_t advanceX, lean_obj_arg image) {
    lean_dec_ref(lean_ctor_get(obj, 4));
    lean_raylib_GlyphInfo_set_impl(obj, value, offsetX, offsetY, advanceX, image);
}

static inline lean_object* lean_raylib_GlyphInfo_box (GlyphInfo r) {
    lean_object* obj = lean_alloc_ctor(0, 5, 0);
    LEAN_RAYLIB_ALLOC_STRUCT(Image, image, r.image);
    lean_raylib_GlyphInfo_set_impl(obj, r.value, r.offsetX, r.offsetY, r.advanceX, lean_raylib_Image_box(image));
    return obj;
}

#define lean_raylib_GlyphInfo_toRepr lean_raylib_GlyphInfo_box

static inline GlyphInfo lean_raylib_GlyphInfo_unbox (b_lean_obj_arg obj) {
    GlyphInfo r;
    r.value = lean_unbox_uint32(lean_ctor_get(obj, 0));
    r.offsetX = lean_unbox_uint32(lean_ctor_get(obj, 1));
    r.offsetY = lean_unbox_uint32(lean_ctor_get(obj, 2));
    r.advanceX = lean_unbox_uint32(lean_ctor_get(obj, 3));
    r.image = *lean_raylib_Image_unbox(lean_ctor_get(obj, 4));
    return r;
}

#define lean_raylib_GlyphInfo_fromRepr lean_raylib_GlyphInfo_unbox


// # Font

typedef struct {
    Font font;
    lean_object* ctx;
} lean_raylib_Font_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Font, lean_raylib_Font_data*);

static inline lean_object* lean_raylib_Font_box (Font font, lean_obj_arg ctx) {
    LEAN_RAYLIB_ALLOC_INIT(lean_raylib_Font_data, fontWctx,
        .font = font,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Font_class, (void*)fontWctx);
}

#define lean_raylib_Font_toRepr lean_raylib_Font_box


// # Camera 3D

static inline void lean_raylib_Camera3D_set_impl (b_lean_obj_arg obj, Camera3D cam) {
    lean_ctor_set(obj, 0, lean_raylib_Vector3_box(cam.position));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_box(cam.target));
    lean_ctor_set(obj, 2, lean_raylib_Vector3_box(cam.up));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(cam.fovy));
    lean_ctor_set(obj, 4, lean_box_uint32(cam.projection));
}

static inline void lean_raylib_Camera3D_set (b_lean_obj_arg obj, Camera3D cam) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_dec_ref(lean_ctor_get(obj, 2));
    lean_raylib_Camera3D_set_impl(obj, cam);
}

static inline lean_object* lean_raylib_Camera3D_box (Camera3D cam) {
    lean_object* obj = lean_alloc_ctor(0, 5, 0);
    lean_raylib_Camera3D_set_impl(obj, cam);
    return obj;
}

#define lean_raylib_Camera3D_toRepr lean_raylib_Camera3D_box

static inline Camera3D lean_raylib_Camera3D_unbox (b_lean_obj_arg obj) {
    Camera3D cam;
    cam.position = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 0));
    cam.target = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 1));
    cam.up = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 2));
    cam.fovy = lean_pod_Float32_unbox(lean_ctor_get(obj, 3));
    cam.projection = lean_unbox_uint32(lean_ctor_get(obj, 4));
    return cam;
}

#define lean_raylib_Camera3D_fromRepr lean_raylib_Camera3D_unbox


// # Camera 2D

static inline void lean_raylib_Camera2D_set_impl (b_lean_obj_arg obj, Camera2D cam) {
    lean_ctor_set(obj, 0, lean_raylib_Vector2_box(cam.offset));
    lean_ctor_set(obj, 1, lean_raylib_Vector2_box(cam.target));
    lean_ctor_set(obj, 2, lean_pod_Float32_box(cam.rotation));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(cam.zoom));
}

static inline void lean_raylib_Camera2D_set (b_lean_obj_arg obj, Camera2D cam) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_raylib_Camera2D_set_impl(obj, cam);
}

static inline lean_object* lean_raylib_Camera2D_box (Camera2D cam) {
    lean_object* obj = lean_alloc_ctor(0, 4, 0);
    lean_raylib_Camera2D_set_impl(obj, cam);
    return obj;
}

#define lean_raylib_Camera2D_toRepr lean_raylib_Camera2D_box

static inline Camera2D lean_raylib_Camera2D_unbox (b_lean_obj_arg obj) {
    Camera2D cam;
    cam.offset = lean_raylib_Vector2_fromRepr(lean_ctor_get(obj, 0));
    cam.target = lean_raylib_Vector2_fromRepr(lean_ctor_get(obj, 1));
    cam.rotation = lean_pod_Float32_unbox(lean_ctor_get(obj, 2));
    cam.zoom = lean_pod_Float32_unbox(lean_ctor_get(obj, 3));
    return cam;
}

#define lean_raylib_Camera2D_fromRepr lean_raylib_Camera2D_unbox


// # Mesh

typedef struct {
    Mesh mesh;
    lean_object* ctx;
} lean_raylib_Mesh_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Mesh, lean_raylib_Mesh_data*);

static inline lean_object* lean_raylib_Mesh_box (Mesh mesh, lean_obj_arg ctx) {
    LEAN_RAYLIB_ALLOC_INIT(lean_raylib_Mesh_data, meshWctx,
        .mesh = mesh,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Mesh_class, (void*)meshWctx);
}

#define lean_raylib_Mesh_toRepr lean_raylib_Mesh_box

static inline Mesh lean_raylib_Mesh_clone(Mesh* meshSrc) {
    Mesh mesh = *meshSrc;
    mesh.vertices = lean_raylib_rlmemdup(mesh.vertices, sizeof(float[3]) * mesh.vertexCount);
    if(mesh.texcoords != NULL) {
        mesh.texcoords = lean_raylib_rlmemdup(mesh.texcoords, sizeof(float[2]) * mesh.vertexCount);
    }
    if(mesh.texcoords2 != NULL) {
        mesh.texcoords2 = lean_raylib_rlmemdup(mesh.texcoords2, sizeof(float[2]) * mesh.vertexCount);
    }
    if(mesh.normals != NULL) {
        mesh.normals = lean_raylib_rlmemdup(mesh.normals, sizeof(float[3]) * mesh.vertexCount);
    }
    if(mesh.tangents != NULL) {
        mesh.tangents = lean_raylib_rlmemdup(mesh.tangents, sizeof(float[4]) * mesh.vertexCount);
    }
    if(mesh.colors != NULL) {
        mesh.colors = lean_raylib_rlmemdup(mesh.colors, sizeof(unsigned char[4]) * mesh.vertexCount);
    }
    if(mesh.indices != NULL) {
        mesh.indices = lean_raylib_rlmemdup(mesh.indices, sizeof(unsigned short[3]) * mesh.triangleCount);
    }
    if(mesh.boneIds != NULL) {
        mesh.boneIds = lean_raylib_rlmemdup(mesh.boneIds, sizeof(unsigned char[4]) * mesh.vertexCount);
    }
    if(mesh.boneWeights != NULL) {
        mesh.boneWeights = lean_raylib_rlmemdup(mesh.boneWeights, sizeof(float[4]) * mesh.vertexCount);
    }
    if(mesh.boneMatrices != NULL) {
        mesh.boneMatrices = lean_raylib_rlmemdup(mesh.boneMatrices, sizeof(float[16]) * mesh.boneCount);
    }
    if(mesh.animVertices != NULL) {
        mesh.animVertices = lean_raylib_rlmemdup(mesh.animVertices, sizeof(float[3]) * mesh.vertexCount);
    }
    if(mesh.animNormals != NULL) {
        mesh.animNormals = lean_raylib_rlmemdup(mesh.animNormals, sizeof(float[3]) * mesh.vertexCount);
    }
    mesh.vaoId = 0;
    mesh.vboId = NULL;
    return mesh;
}

static inline lean_obj_res lean_raylib_Mesh_ensure_exclusive(lean_obj_arg meshObj) {
    if (LEAN_LIKELY(lean_is_exclusive(meshObj))) {
        return meshObj;
    }
    lean_raylib_Mesh_data* mesh = lean_get_external_data(meshObj);
    lean_inc_ref(mesh->ctx);
    lean_object* meshNew = lean_raylib_Mesh_box(lean_raylib_Mesh_clone(&mesh->mesh), mesh->ctx);
    lean_dec_ref(meshObj);
    return meshNew;
}


// # Shader

typedef struct {
    Shader shader;
    lean_object* ctx;
} lean_raylib_Shader_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Shader, lean_raylib_Shader_data*);

static inline lean_object* lean_raylib_Shader_box (Shader shader, lean_obj_arg ctx) {
    LEAN_RAYLIB_ALLOC_INIT(lean_raylib_Shader_data, shaderWctx,
        .shader = shader,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Shader_class, (void*)shaderWctx);
}

#define lean_raylib_Shader_toRepr lean_raylib_Shader_box

lean_obj_res lean_raylib__Shader_getDefault(lean_obj_arg ctx);


// # Material

// NOTE: Returned mmap contains pointers to data owned by the boxed mmap!
static inline MaterialMap lean_raylib_MaterialMap_unbox (b_lean_obj_arg mmap_box) {
    MaterialMap mmap;
    mmap.texture = lean_raylib_Texture_unbox(lean_ctor_get(mmap_box, 0))->texture;
    mmap.color = lean_raylib_Color_unbox(lean_ctor_get(mmap_box, 1));
    mmap.value = lean_pod_Float32_unbox(lean_ctor_get(mmap_box, 2));
    return mmap;
}

#define lean_raylib_MaterialMap_fromRepr lean_raylib_MaterialMap_unbox

static inline lean_obj_res lean_raylib_MaterialMap_box (lean_obj_arg texture, Color color, float value) {
    lean_object* mmap = lean_alloc_ctor(0, 3, 0);
    lean_ctor_set(mmap, 0, texture);
    lean_ctor_set(mmap, 1, lean_raylib_Color_box(color));
    lean_ctor_set(mmap, 2, lean_pod_Float32_box(value));
    return mmap;
}

#define lean_raylib_MaterialMap_toRepr lean_raylib_MaterialMap_box

// todo: configure from lake (and pass to raylib (config.h - MAX_MATERIAL_MAPS))
#define LEAN_RAYLIB_MAX_MATERIAL_MAPS 12

// NOTE: Returned material contains pointers to `out_mmaps` and to data owned by the boxed material!
static inline Material lean_raylib_Material_unbox (b_lean_obj_arg material_box, MaterialMap* out_mmaps) {
    Material material;
    material.shader = lean_raylib_Shader_unbox(lean_ctor_get(material_box, 0))->shader;
    lean_object* mmaps = lean_ctor_get(material_box, 1);
    for(size_t i = 0; i < LEAN_RAYLIB_MAX_MATERIAL_MAPS; ++i) {
        out_mmaps[i] = lean_raylib_MaterialMap_unbox(lean_array_get_core(mmaps, i));
    }
    material.maps = out_mmaps;
    material.params[0] = lean_pod_Float32_unbox(lean_ctor_get(material_box, 2));
    material.params[1] = lean_pod_Float32_unbox(lean_ctor_get(material_box, 3));
    material.params[2] = lean_pod_Float32_unbox(lean_ctor_get(material_box, 4));
    material.params[3] = lean_pod_Float32_unbox(lean_ctor_get(material_box, 5));
    return material;
}

#define lean_raylib_Material_fromRepr lean_raylib_Material_unbox

static inline lean_obj_res lean_raylib_Material_box (lean_obj_arg shader, lean_obj_arg mmaps, Vector4 params) {
    lean_object* material = lean_alloc_ctor(0, 6, 0);
    lean_ctor_set(material, 0, shader);
    lean_ctor_set(material, 1, mmaps);
    lean_ctor_set(material, 2, lean_pod_Float32_box(params.x));
    lean_ctor_set(material, 3, lean_pod_Float32_box(params.y));
    lean_ctor_set(material, 4, lean_pod_Float32_box(params.z));
    lean_ctor_set(material, 5, lean_pod_Float32_box(params.w));
    return material;
}

#define lean_raylib_Material_toRepr lean_raylib_Material_box


// # Transform

static inline void lean_raylib_Transform_set_impl (b_lean_obj_arg obj, Transform transform) {
    lean_ctor_set(obj, 0, lean_raylib_Vector3_box(transform.translation));
    lean_ctor_set(obj, 1, lean_raylib_Vector4_box(transform.rotation));
    lean_ctor_set(obj, 2, lean_raylib_Vector3_box(transform.scale));
}

static inline void lean_raylib_Transform_set (b_lean_obj_arg obj, Transform transform) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_dec_ref(lean_ctor_get(obj, 2));
    lean_raylib_Transform_set_impl(obj, transform);
}

static inline lean_object* lean_raylib_Transform_box (Transform transform) {
    lean_object* obj = lean_alloc_ctor(0, 3, 0);
    lean_raylib_Transform_set_impl(obj, transform);
    return obj;
}

#define lean_raylib_Transform_toRepr lean_raylib_Transform_box

static inline Transform lean_raylib_Transform_unbox (b_lean_obj_arg obj) {
    Transform transform;
    transform.translation = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 0));
    transform.rotation = lean_raylib_Vector4_fromRepr(lean_ctor_get(obj, 1));
    transform.scale = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 2));
    return transform;
}

#define lean_raylib_Transform_fromRepr lean_raylib_Transform_unbox


// # BoneInfo

static inline void lean_raylib_BoneInfo_set_impl (b_lean_obj_arg obj, BoneInfo boneInfo) {
    lean_ctor_set(obj, 0, lean_mk_string_from_bytes(boneInfo.name, sizeof(boneInfo.name)));
    if (boneInfo.parent < 0) {
        lean_ctor_set(obj, 1, lean_mk_option_none());
    }
    else {
        lean_ctor_set(obj, 1, lean_mk_option_some(lean_box_uint32(boneInfo.parent)));
    }
}

static inline void lean_raylib_BoneInfo_set (b_lean_obj_arg obj, BoneInfo boneInfo) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_raylib_BoneInfo_set_impl(obj, boneInfo);
}

static inline lean_object* lean_raylib_BoneInfo_box (BoneInfo boneInfo) {
    lean_object* obj = lean_alloc_ctor(0, 2, 0);
    lean_raylib_BoneInfo_set_impl(obj, boneInfo);
    return obj;
}

#define lean_raylib_BoneInfo_toRepr lean_raylib_BoneInfo_box

static inline BoneInfo lean_raylib_BoneInfo_unbox (b_lean_obj_arg obj) {
    lean_object* name = lean_ctor_get(obj, 0);
    lean_object* parent = lean_ctor_get(obj, 1);
    BoneInfo boneInfo;
    strncpy(boneInfo.name, lean_string_cstr(name), sizeof(boneInfo.name));
    if(lean_option_is_some(parent)) {
        boneInfo.parent = (int)lean_unbox_uint32(lean_ctor_get(parent, 0));
    }
    else {
        boneInfo.parent = -1;
    }
    return boneInfo;
}

#define lean_raylib_BoneInfo_fromRepr lean_raylib_BoneInfo_unbox


// # Model

typedef struct {
    lean_object* materials; // Array Material
    lean_object* meshes; // Array (Mesh x Fin materials.size)
    uint32_t meshesCapacity;
    uint32_t materialsCapacity;
    Model model;
} lean_raylib_Model_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Model, lean_raylib_Model_data*);

static inline lean_object* lean_raylib_Model_box (lean_raylib_Model_data model) {
    LEAN_RAYLIB_ALLOC_STRUCT(lean_raylib_Model_data, modelBoxed, model);
    return lean_alloc_external(lean_raylib_Model_class, (void*)modelBoxed);
}

#define lean_raylib_Model_toRepr lean_raylib_Model_box

// New model references the same (Lean) meshes and materials
static inline lean_raylib_Model_data lean_raylib_Model_clone(lean_raylib_Model_data* modelSrc) {
    lean_raylib_Model_data modelDst;
    lean_inc_ref(modelSrc->meshes);
    lean_inc_ref(modelSrc->materials);
    modelDst.meshes = modelSrc->meshes;
    modelDst.materials = modelSrc->materials;
    modelDst.model.transform = modelSrc->model.transform;
    modelDst.meshesCapacity = modelDst.model.meshCount = modelSrc->model.meshCount;
    modelDst.model.meshes = lean_raylib_rlmemdup(modelSrc->model.meshes, modelDst.meshesCapacity * sizeof(Mesh));
    modelDst.materialsCapacity = modelDst.model.materialCount = modelSrc->model.materialCount;
    modelDst.model.materials = RL_MALLOC(modelDst.materialsCapacity * sizeof(Material));
    for (size_t i = 0; i < modelDst.model.materialCount; ++i) {
        memcpy(&modelDst.model.materials[i].params, &modelSrc->model.materials[i].params, sizeof(modelDst.model.materials[i].params));
        modelDst.model.materials[i].shader = modelSrc->model.materials[i].shader;
        modelDst.model.materials[i].maps = RL_MALLOC(LEAN_RAYLIB_MAX_MATERIAL_MAPS * sizeof(MaterialMap));
        memcpy(
            &modelDst.model.materials[i].maps,
            &modelSrc->model.materials[i].maps,
            LEAN_RAYLIB_MAX_MATERIAL_MAPS * sizeof(MaterialMap)
        );
    }
    modelDst.model.meshMaterial = RL_MALLOC(modelDst.meshesCapacity * sizeof(int));
    memcpy(modelDst.model.meshMaterial, modelSrc->model.meshMaterial, modelDst.model.meshCount * sizeof(int));
    modelDst.model.boneCount = modelSrc->model.boneCount;
    modelDst.model.bones = lean_raylib_rlmemdup(modelSrc->model.bones, modelDst.model.boneCount * sizeof(BoneInfo));
    modelDst.model.bindPose = lean_raylib_rlmemdup(modelSrc->model.bindPose, modelDst.model.boneCount * sizeof(Transform));
    return modelDst;
}


// # ModelAnimation

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_ModelAnimation, ModelAnimation*);

static inline lean_object* lean_raylib_ModelAnimation_box (ModelAnimation anim) {
    LEAN_RAYLIB_ALLOC_STRUCT(ModelAnimation, animBox, anim);
    return lean_alloc_external(lean_raylib_ModelAnimation_class, (void*)animBox);
}

#define lean_raylib_ModelAnimation_toRepr lean_raylib_ModelAnimation_box

static inline lean_obj_res lean_raylib_ModelAnimation_ensure_exclusive(lean_obj_arg animObj) {
    if(LEAN_LIKELY(lean_is_exclusive(animObj))) {
        return animObj;
    }
    ModelAnimation animNew;
    ModelAnimation* animOld = lean_raylib_ModelAnimation_unbox(animObj);
    animNew.boneCount = animOld->boneCount;
    animNew.frameCount = animOld->frameCount;
    animNew.bones = lean_raylib_rlmemdup(animOld->bones, animNew.boneCount * sizeof(BoneInfo));
    animNew.framePoses = RL_MALLOC(animNew.frameCount * sizeof(Transform*));
    for (size_t i = 0; i < animNew.frameCount; ++i) {
        animNew.framePoses[i] = lean_raylib_rlmemdup(animOld->framePoses[i], animNew.boneCount * sizeof(Transform));
    }
    lean_dec_ref(animObj);
    return lean_raylib_ModelAnimation_box(animNew);
}


// # Ray

static inline void lean_raylib_Ray_set (b_lean_obj_arg obj, Ray ray) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_ctor_set(obj, 0, lean_raylib_Vector3_box(ray.position));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_box(ray.direction));
}

static inline lean_object* lean_raylib_Ray_box (Ray ray) {
    lean_object* obj = lean_alloc_ctor(0, 2, 0);
    lean_ctor_set(obj, 0, lean_raylib_Vector3_box(ray.position));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_box(ray.direction));
    return obj;
}

#define lean_raylib_Ray_toRepr lean_raylib_Ray_box

static inline Ray lean_raylib_Ray_unbox (b_lean_obj_arg obj) {
    Ray ray;
    ray.position = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 0));
    ray.direction = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 1));
    return ray;
}

#define lean_raylib_Ray_fromRepr lean_raylib_Ray_unbox


// # Ray collision

static inline void lean_raylib_RayCollision_set_impl (b_lean_obj_arg obj, RayCollision rayCol) {
    lean_ctor_set(obj, 0, lean_box(rayCol.hit));
    lean_ctor_set(obj, 1, lean_pod_Float32_box(rayCol.distance));
    lean_ctor_set(obj, 2, lean_raylib_Vector3_box(rayCol.point));
    lean_ctor_set(obj, 3, lean_raylib_Vector3_box(rayCol.normal));
}

static inline void lean_raylib_RayCollision_set (b_lean_obj_arg obj, RayCollision rayCol) {
    lean_dec_ref(lean_ctor_get(obj, 2));
    lean_dec_ref(lean_ctor_get(obj, 3));
    lean_raylib_RayCollision_set_impl(obj, rayCol);
}

static inline lean_object* lean_raylib_RayCollision_box (RayCollision rayCol) {
    lean_object* obj = lean_alloc_ctor(0, 4, 0);
    lean_raylib_RayCollision_set_impl(obj, rayCol);
    return obj;
}

#define lean_raylib_RayCollision_toRepr lean_raylib_RayCollision_box

static inline RayCollision lean_raylib_RayCollision_unbox (b_lean_obj_arg obj) {
    RayCollision rayCol;
    rayCol.hit = lean_unbox(lean_ctor_get(obj, 0));
    rayCol.distance = lean_pod_Float32_unbox(lean_ctor_get(obj, 1));
    rayCol.point = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 2));
    rayCol.normal = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 3));
    return rayCol;
}

#define lean_raylib_RayCollision_fromRepr lean_raylib_RayCollision_unbox


// # Bounding box

static inline void lean_raylib_BoundingBox_set (b_lean_obj_arg obj, BoundingBox bb) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_ctor_set(obj, 0, lean_raylib_Vector3_box(bb.min));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_box(bb.max));
}

static inline lean_object* lean_raylib_BoundingBox_box (BoundingBox bb) {
    lean_object* obj = lean_alloc_ctor(0, 2, 0);
    lean_ctor_set(obj, 0, lean_raylib_Vector3_box(bb.min));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_box(bb.max));
    return obj;
}

#define lean_raylib_BoundingBox_toRepr lean_raylib_BoundingBox_box

static inline BoundingBox lean_raylib_BoundingBox_unbox (b_lean_obj_arg obj) {
    BoundingBox bb;
    bb.min = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 0));
    bb.max = lean_raylib_Vector3_fromRepr(lean_ctor_get(obj, 1));
    return bb;
}

#define lean_raylib_BoundingBox_fromRepr lean_raylib_BoundingBox_unbox


// # Wave

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Wave, Wave*);

static inline lean_object* lean_raylib_Wave_box (Wave const* obj) {
    return lean_alloc_external(lean_raylib_Wave_class, (void*)obj);
}

#define lean_raylib_Wave_toRepr lean_raylib_Wave_box


// # Audio stream

typedef struct {
    AudioStream stream;
    lean_object* ctx;
#ifdef LEAN_RAYLIB_FORK
    lean_object* callback; // NULLABLE
#endif
} lean_raylib_AudioStream_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_AudioStream, lean_raylib_AudioStream_data*);

static inline lean_object* lean_raylib_AudioStream_box (AudioStream stream, lean_obj_arg ctx, lean_obj_arg callback) {
    lean_raylib_AudioStream_data* stream_heap = lean_raylib_alloc(sizeof(lean_raylib_AudioStream_data));
    stream_heap->stream = stream;
    stream_heap->ctx = ctx;
#ifdef LEAN_RAYLIB_FORK
    stream_heap->callback = callback;
#endif
    return lean_alloc_external(lean_raylib_AudioStream_class, (void*)stream_heap);
}

#define lean_raylib_AudioStream_toRepr lean_raylib_AudioStream_box

/// @param stream \@& AudioStream
/// @param callback nullable
static inline void lean_raylib_AudioStream_setCallback(
    b_lean_obj_arg stream, AudioCallback callback
#ifdef LEAN_RAYLIB_FORK
    , void* userdata
#endif
) {
    lean_raylib_AudioStream_data* data = lean_raylib_AudioStream_unbox(stream);
    #ifdef LEAN_RAYLIB_FORK
    if (data->callback != NULL) {
        lean_dec_ref(data->callback);
        data->callback = NULL;
    }
    SetAudioStreamCallback(data->stream, callback, userdata);
    #else
    SetAudioStreamCallback(data->stream, callback);
    #endif
}


// # Sound

typedef struct {
    Sound sound;
    lean_object* ctx;
} lean_raylib_Sound_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Sound, lean_raylib_Sound_data*);

static inline lean_object* lean_raylib_Sound_box (Sound sound, lean_obj_arg ctx) {
    LEAN_RAYLIB_ALLOC_INIT(lean_raylib_Sound_data, soundWctx,
        .sound = sound,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Sound_class, (void*)soundWctx);
}

#define lean_raylib_Sound_toRepr lean_raylib_Sound_box


// # Music

typedef struct {
    Music music;
    lean_object* ctx;
} lean_raylib_Music_data;

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_Music, lean_raylib_Music_data*);

static inline lean_object* lean_raylib_Music_box (Music music, lean_obj_arg ctx) {
    LEAN_RAYLIB_ALLOC_INIT(lean_raylib_Music_data, musicWctx,
        .music = music,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Music_class, (void*)musicWctx);
}

#define lean_raylib_Music_toRepr lean_raylib_Music_box


// # Vr device info

static inline void lean_raylib_VrDeviceInfo_set_impl (b_lean_obj_arg obj, VrDeviceInfo* vrDeviceInfo) {
    lean_ctor_set(obj, 0, lean_box_uint32(vrDeviceInfo->hResolution));
    lean_ctor_set(obj, 1, lean_box_uint32(vrDeviceInfo->vResolution));
    lean_ctor_set(obj, 2, lean_pod_Float32_box(vrDeviceInfo->hScreenSize));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(vrDeviceInfo->vScreenSize));
    lean_ctor_set(obj, 4, lean_pod_Float32_box(vrDeviceInfo->eyeToScreenDistance));
    lean_ctor_set(obj, 5, lean_pod_Float32_box(vrDeviceInfo->lensSeparationDistance));
    lean_ctor_set(obj, 6, lean_pod_Float32_box(vrDeviceInfo->interpupillaryDistance));
    Vector4 lensDistortionValues;
    lensDistortionValues.x = vrDeviceInfo->lensDistortionValues[0];
    lensDistortionValues.y = vrDeviceInfo->lensDistortionValues[1];
    lensDistortionValues.z = vrDeviceInfo->lensDistortionValues[2];
    lensDistortionValues.w = vrDeviceInfo->lensDistortionValues[3];
    lean_ctor_set(obj, 7, lean_raylib_Vector4_box(lensDistortionValues));
    Vector4 chromaAbCorrection;
    chromaAbCorrection.x = vrDeviceInfo->chromaAbCorrection[0];
    chromaAbCorrection.y = vrDeviceInfo->chromaAbCorrection[1];
    chromaAbCorrection.z = vrDeviceInfo->chromaAbCorrection[2];
    chromaAbCorrection.w = vrDeviceInfo->chromaAbCorrection[3];
    lean_ctor_set(obj, 8, lean_raylib_Vector4_box(chromaAbCorrection));
}

static inline void lean_raylib_VrDeviceInfo_set (b_lean_obj_arg obj, VrDeviceInfo* vrDeviceInfo) {
    lean_dec_ref(lean_ctor_get(obj, 7));
    lean_dec_ref(lean_ctor_get(obj, 8));
    lean_raylib_VrDeviceInfo_set_impl(obj, vrDeviceInfo);
}

static inline lean_object* lean_raylib_VrDeviceInfo_box (VrDeviceInfo* vrDeviceInfo) {
    lean_object* obj = lean_alloc_ctor(0, 9, 0);
    lean_raylib_VrDeviceInfo_set_impl(obj, vrDeviceInfo);
    return obj;
}

#define lean_raylib_VrDeviceInfo_toRepr lean_raylib_VrDeviceInfo_box

static inline VrDeviceInfo lean_raylib_VrDeviceInfo_unbox (b_lean_obj_arg obj) {
    VrDeviceInfo vrDeviceInfo;
    vrDeviceInfo.hResolution = lean_unbox_uint32(lean_ctor_get(obj, 0));
    vrDeviceInfo.vResolution = lean_unbox_uint32(lean_ctor_get(obj, 1));
    vrDeviceInfo.hScreenSize = lean_pod_Float32_unbox(lean_ctor_get(obj, 2));
    vrDeviceInfo.vScreenSize = lean_pod_Float32_unbox(lean_ctor_get(obj, 3));
    vrDeviceInfo.eyeToScreenDistance = lean_pod_Float32_unbox(lean_ctor_get(obj, 4));
    vrDeviceInfo.lensSeparationDistance = lean_pod_Float32_unbox(lean_ctor_get(obj, 5));
    vrDeviceInfo.interpupillaryDistance = lean_pod_Float32_unbox(lean_ctor_get(obj, 6));
    Vector4 lensDistortionValues = lean_raylib_Vector4_fromRepr(lean_ctor_get(obj, 7));
    vrDeviceInfo.lensDistortionValues[0] = lensDistortionValues.x;
    vrDeviceInfo.lensDistortionValues[1] = lensDistortionValues.y;
    vrDeviceInfo.lensDistortionValues[2] = lensDistortionValues.z;
    vrDeviceInfo.lensDistortionValues[3] = lensDistortionValues.w;
    Vector4 chromaAbCorrection = lean_raylib_Vector4_fromRepr(lean_ctor_get(obj, 8));
    vrDeviceInfo.chromaAbCorrection[0] = chromaAbCorrection.x;
    vrDeviceInfo.chromaAbCorrection[1] = chromaAbCorrection.y;
    vrDeviceInfo.chromaAbCorrection[2] = chromaAbCorrection.z;
    vrDeviceInfo.chromaAbCorrection[3] = chromaAbCorrection.w;
    return vrDeviceInfo;
}

#define lean_raylib_VrDeviceInfo_fromRepr lean_raylib_VrDeviceInfo_unbox


// # Vr stereo config

static inline void lean_raylib_VrStereoConfig_set_impl (b_lean_obj_arg obj, VrStereoConfig* vrStereoConfig) {
    lean_ctor_set(obj, 0, lean_raylib_Matrix_box(vrStereoConfig->projection[0]));
    lean_ctor_set(obj, 1, lean_raylib_Matrix_box(vrStereoConfig->projection[1]));
    lean_ctor_set(obj, 2, lean_raylib_Matrix_box(vrStereoConfig->viewOffset[0]));
    lean_ctor_set(obj, 3, lean_raylib_Matrix_box(vrStereoConfig->viewOffset[1]));
    Vector2 leftLensCenter;
    leftLensCenter.x = vrStereoConfig->leftLensCenter[0];
    leftLensCenter.y = vrStereoConfig->leftLensCenter[1];
    lean_ctor_set(obj, 4, lean_raylib_Vector2_box(leftLensCenter));
    Vector2 rightLensCenter;
    rightLensCenter.x = vrStereoConfig->rightLensCenter[0];
    rightLensCenter.y = vrStereoConfig->rightLensCenter[1];
    lean_ctor_set(obj, 5, lean_raylib_Vector2_box(rightLensCenter));
    Vector2 leftScreenCenter;
    leftScreenCenter.x = vrStereoConfig->leftScreenCenter[0];
    leftScreenCenter.y = vrStereoConfig->leftScreenCenter[1];
    lean_ctor_set(obj, 6, lean_raylib_Vector2_box(leftScreenCenter));
    Vector2 rightScreenCenter;
    rightScreenCenter.x = vrStereoConfig->rightScreenCenter[0];
    rightScreenCenter.y = vrStereoConfig->rightScreenCenter[1];
    lean_ctor_set(obj, 7, lean_raylib_Vector2_box(rightScreenCenter));
    Vector2 scale;
    scale.x = vrStereoConfig->scale[0];
    scale.y = vrStereoConfig->scale[1];
    lean_ctor_set(obj, 8, lean_raylib_Vector2_box(scale));
    Vector2 scaleIn;
    scaleIn.x = vrStereoConfig->scaleIn[0];
    scaleIn.y = vrStereoConfig->scaleIn[1];
    lean_ctor_set(obj, 9, lean_raylib_Vector2_box(scaleIn));
}

static inline void lean_raylib_VrStereoConfig_set (b_lean_obj_arg obj, VrStereoConfig* vrStereoConfig) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_dec_ref(lean_ctor_get(obj, 2));
    lean_dec_ref(lean_ctor_get(obj, 3));
    lean_dec_ref(lean_ctor_get(obj, 4));
    lean_dec_ref(lean_ctor_get(obj, 5));
    lean_dec_ref(lean_ctor_get(obj, 6));
    lean_dec_ref(lean_ctor_get(obj, 7));
    lean_dec_ref(lean_ctor_get(obj, 8));
    lean_dec_ref(lean_ctor_get(obj, 9));
    lean_raylib_VrStereoConfig_set_impl(obj, vrStereoConfig);
}

static inline lean_object* lean_raylib_VrStereoConfig_box (VrStereoConfig* vrStereoConfig) {
    lean_object* obj = lean_alloc_ctor(0, 10, 0);
    lean_raylib_VrStereoConfig_set_impl(obj, vrStereoConfig);
    return obj;
}

#define lean_raylib_VrStereoConfig_toRepr lean_raylib_VrStereoConfig_box

static inline VrStereoConfig lean_raylib_VrStereoConfig_unbox (b_lean_obj_arg obj) {
    VrStereoConfig vrStereoConfig;
    vrStereoConfig.projection[0] = lean_raylib_Matrix_unbox(lean_ctor_get(obj, 0));
    vrStereoConfig.projection[1] = lean_raylib_Matrix_unbox(lean_ctor_get(obj, 1));
    vrStereoConfig.viewOffset[0] = lean_raylib_Matrix_unbox(lean_ctor_get(obj, 2));
    vrStereoConfig.viewOffset[1] = lean_raylib_Matrix_unbox(lean_ctor_get(obj, 3));
    Vector2 leftLensCenter = lean_raylib_Vector2_fromRepr(lean_ctor_get(obj, 4));
    vrStereoConfig.leftLensCenter[0] = leftLensCenter.x;
    vrStereoConfig.leftLensCenter[1] = leftLensCenter.y;
    Vector2 rightLensCenter = lean_raylib_Vector2_fromRepr(lean_ctor_get(obj, 5));
    vrStereoConfig.rightLensCenter[0] = rightLensCenter.x;
    vrStereoConfig.rightLensCenter[1] = rightLensCenter.y;
    Vector2 leftScreenCenter = lean_raylib_Vector2_fromRepr(lean_ctor_get(obj, 6));
    vrStereoConfig.leftScreenCenter[0] = leftScreenCenter.x;
    vrStereoConfig.leftScreenCenter[1] = leftScreenCenter.y;
    Vector2 rightScreenCenter = lean_raylib_Vector2_fromRepr(lean_ctor_get(obj, 7));
    vrStereoConfig.rightScreenCenter[0] = rightScreenCenter.x;
    vrStereoConfig.rightScreenCenter[1] = rightScreenCenter.y;
    Vector2 scale = lean_raylib_Vector2_fromRepr(lean_ctor_get(obj, 8));
    vrStereoConfig.scale[0] = scale.x;
    vrStereoConfig.scale[1] = scale.y;
    Vector2 scaleIn = lean_raylib_Vector2_fromRepr(lean_ctor_get(obj, 9));
    vrStereoConfig.scaleIn[0] = scaleIn.x;
    vrStereoConfig.scaleIn[1] = scaleIn.y;
    return vrStereoConfig;
}

#define lean_raylib_VrStereoConfig_fromRepr lean_raylib_VrStereoConfig_unbox


// # Automation Event

static inline void lean_raylib_AutomationEvent_set_impl (b_lean_obj_arg obj, AutomationEvent automationEvent) {
    lean_ctor_set_uint32(obj, 4 * sizeof(void*) + 0, automationEvent.frame);
    lean_ctor_set_uint32(obj, 4 * sizeof(void*) + sizeof(uint32_t), automationEvent.type);
    lean_ctor_set(obj, 0, lean_pod_Int32_box((int32_t)automationEvent.params[0]));
    lean_ctor_set(obj, 1, lean_pod_Int32_box((int32_t)automationEvent.params[1]));
    lean_ctor_set(obj, 2, lean_pod_Int32_box((int32_t)automationEvent.params[2]));
    lean_ctor_set(obj, 3, lean_pod_Int32_box((int32_t)automationEvent.params[3]));
}

static inline lean_object* lean_raylib_AutomationEvent_box (AutomationEvent automationEvent) {
    lean_object* obj = lean_alloc_ctor(0, 4, 2 * sizeof(uint32_t));
    lean_raylib_AutomationEvent_set_impl(obj, automationEvent);
    return obj;
}

#define lean_raylib_AutomationEvent_toRepr lean_raylib_AutomationEvent_box

static inline AutomationEvent lean_raylib_AutomationEvent_unbox (b_lean_obj_arg obj) {
    AutomationEvent automationEvent;
    automationEvent.frame = lean_ctor_get_uint32(obj, 4 * sizeof(void*) + 0);
    automationEvent.type = lean_ctor_get_uint32(obj, 4 * sizeof(void*) + sizeof(uint32_t));
    for (size_t i = 0; i < 4; ++i) {
        automationEvent.params[i] = lean_pod_Int32_unbox(lean_ctor_get(obj, i));
    }
    return automationEvent;
}

#define lean_raylib_AutomationEvent_fromRepr lean_raylib_AutomationEvent_unbox


// # Automation event list

LEAN_POD_DECLARE_EXTERNAL_CLASS(raylib_AutomationEventList, AutomationEventList*);

static inline lean_object* lean_raylib_AutomationEventList_box (AutomationEventList value) {
    LEAN_RAYLIB_ALLOC_STRUCT(AutomationEventList, boxed, value);
    return lean_alloc_external(lean_raylib_AutomationEventList_class, (void*)boxed);
}

#define lean_raylib_AutomationEventList_toRepr lean_raylib_AutomationEventList_box

static inline lean_obj_res lean_raylib_AutomationEventList_ensure_exclusive(lean_obj_arg obj) {
    if(LEAN_LIKELY(lean_is_exclusive(obj))) {
        return obj;
    }
    AutomationEventList newList;
    AutomationEventList* oldList = lean_raylib_AutomationEventList_fromRepr(obj);
    newList.capacity = oldList->capacity;
    newList.count = oldList->count;
    newList.events = lean_raylib_rlmemdup(oldList->events, newList.capacity * sizeof(AutomationEvent));
    lean_dec_ref(obj);
    return lean_raylib_AutomationEventList_toRepr(newList);
}


// # Window Handle

LEAN_POD_PTR_ALIAS(raylib_WindowHandle, void*);
LEAN_POD_PTR_ALIAS(raylib_WindowBackendHandle, void*);


// # GLFW

static inline uint8_t lean_raylib_glfw_ErrorCode_toRepr(int err) {
    switch (err) {
        case GLFW_NO_ERROR: return 0;
        case GLFW_NOT_INITIALIZED: return 1;
        case GLFW_NO_CURRENT_CONTEXT: return 2;
        case GLFW_INVALID_ENUM: return 3;
        case GLFW_INVALID_VALUE: return 4;
        case GLFW_OUT_OF_MEMORY: return 5;
        case GLFW_API_UNAVAILABLE: return 6;
        case GLFW_VERSION_UNAVAILABLE: return 7;
        case GLFW_PLATFORM_ERROR: return 8;
        case GLFW_FORMAT_UNAVAILABLE: return 9;
        case GLFW_NO_WINDOW_CONTEXT: return 10;
#ifdef GLFW_CURSOR_UNAVAILABLE
        case GLFW_CURSOR_UNAVAILABLE: return 11;
#endif
#ifdef GLFW_FEATURE_UNAVAILABLE
        case GLFW_FEATURE_UNAVAILABLE: return 12;
#endif
#ifdef GLFW_FEATURE_UNIMPLEMENTED
        case GLFW_FEATURE_UNIMPLEMENTED: return 13;
#endif
#ifdef GLFW_PLATFORM_UNAVAILABLE
        case GLFW_PLATFORM_UNAVAILABLE: return 14;
#endif
        default:
            return 15;
    }
}

#define lean_raylib_glfw_ErrorCode_box(x) lean_box(lean_raylib_glfw_ErrorCode_toRepr(x))

#define LEAN_RAYLIB_GLFW_Error_LAYOUT 0, 1, 0, 0, 0, 0, 1
#define LEAN_RAYLIB_GLFW_Error_code U8, 0, LEAN_RAYLIB_GLFW_Error_LAYOUT
#define LEAN_RAYLIB_GLFW_Error_description BOX, 0, LEAN_RAYLIB_GLFW_Error_LAYOUT

LEAN_POD_PTR_ALIAS(raylib_glfw_Window, GLFWwindow*)
// @param handle owned
static inline lean_obj_res lean_raylib_glfw_Window_mk_(lean_raylib_WindowBackendHandle handle) {
    // return lean_raylib_glfw_Window_toRepr(lean_raylib_WindowBackendHandle_fromRepr(handle)); // lean_dec_ref handle
    return handle; // Both are ptr aliases
}

LEAN_POD_PTR_ALIAS(raylib_glfw_Monitor, GLFWmonitor*)

#define LEAN_RAYLIB_GLFW_VideoMode_LAYOUT 0, 0, 0, 0, 6, 0, 0
#define LEAN_RAYLIB_GLFW_VideoMode_width U32, 0, LEAN_RAYLIB_GLFW_VideoMode_LAYOUT
#define LEAN_RAYLIB_GLFW_VideoMode_height U32, 1, LEAN_RAYLIB_GLFW_VideoMode_LAYOUT
#define LEAN_RAYLIB_GLFW_VideoMode_redBits U32, 2, LEAN_RAYLIB_GLFW_VideoMode_LAYOUT
#define LEAN_RAYLIB_GLFW_VideoMode_greenBits U32, 3, LEAN_RAYLIB_GLFW_VideoMode_LAYOUT
#define LEAN_RAYLIB_GLFW_VideoMode_blueBits U32, 4, LEAN_RAYLIB_GLFW_VideoMode_LAYOUT
#define LEAN_RAYLIB_GLFW_VideoMode_refreshRate U32, 5, LEAN_RAYLIB_GLFW_VideoMode_LAYOUT

static inline lean_obj_res lean_raylib_glfw_VideoMode_box(const GLFWvidmode* vidmode) {
    lean_object* vidmode_box = LEAN_POD_ALLOC_CTOR(LEAN_RAYLIB_GLFW_VideoMode_LAYOUT);
    LEAN_POD_CTOR_SET(vidmode_box, vidmode->width, LEAN_RAYLIB_GLFW_VideoMode_width);
    LEAN_POD_CTOR_SET(vidmode_box, vidmode->height, LEAN_RAYLIB_GLFW_VideoMode_height);
    LEAN_POD_CTOR_SET(vidmode_box, vidmode->redBits, LEAN_RAYLIB_GLFW_VideoMode_redBits);
    LEAN_POD_CTOR_SET(vidmode_box, vidmode->greenBits, LEAN_RAYLIB_GLFW_VideoMode_greenBits);
    LEAN_POD_CTOR_SET(vidmode_box, vidmode->blueBits, LEAN_RAYLIB_GLFW_VideoMode_blueBits);
    LEAN_POD_CTOR_SET(vidmode_box, vidmode->refreshRate, LEAN_RAYLIB_GLFW_VideoMode_refreshRate);
    return vidmode_box;
}
