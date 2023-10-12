#pragma once

#include <lean_pod.h>
#include "util.h"
#include <rlgl.h>
#include "include/raymath_lean.h"

#ifdef LEAN_RAYLIB_LIBFFI
#include <ffi.h>
#endif

// # Context

extern lean_external_class* lean_raylib_Context_class;

static inline lean_obj_res lean_raylib_Context_new () {
    return lean_alloc_external(lean_raylib_Context_class, NULL);
}


// # VaList

typedef struct {
    va_list v;
} lean_raylib_VaList;

extern lean_external_class* lean_raylib_VaList_class;

static inline lean_object* lean_raylib_VaList_to (lean_raylib_VaList* obj) {
    return lean_alloc_external(lean_raylib_VaList_class, (void*)obj);
}

static inline lean_raylib_VaList* lean_raylib_VaList_from (b_lean_obj_arg obj) {
    return (lean_raylib_VaList*) lean_get_external_data(obj);
}


// # Color

static inline Color lean_raylib_Color_from(uint32_t color) {
    Color res = {
        .r = (uint8_t)((color >> 24) & 0xFF),
        .g = (uint8_t)((color >> 16) & 0xFF),
        .b = (uint8_t)((color >> 8) & 0xFF),
        .a = (uint8_t)(color & 0xFF),
    };
    return res;
}

static inline uint32_t lean_raylib_Color_to(Color color) {
    return (color.r << 24) | (color.g << 16) | (color.b << 8) | color.a;
}


// # Rectangle

static inline void lean_raylib_Rectangle_set (b_lean_obj_arg obj, Rectangle r) {
    lean_ctor_set(obj, 0, lean_pod_Float32_box(r.x));
    lean_ctor_set(obj, 1, lean_pod_Float32_box(r.y));
    lean_ctor_set(obj, 2, lean_pod_Float32_box(r.width));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(r.height));
}

static inline lean_object* lean_raylib_Rectangle_to (Rectangle r) {
    lean_object* obj = lean_alloc_ctor(0, 4, 0);
    lean_raylib_Rectangle_set(obj, r);
    return obj;
}

static inline Rectangle lean_raylib_Rectangle_from (b_lean_obj_arg obj) {
    Rectangle r;
    r.x = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 0)));
    r.y = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 1)));
    r.width = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 2)));
    r.height = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 3)));
    return r;
}


// # Image

extern lean_external_class* lean_raylib_Image_class;
extern lean_object* lean_raylib_Image_empty;

static inline Image* lean_raylib_Image_from (b_lean_obj_arg obj) {
    return (Image*) lean_get_external_data(obj);
}

static inline lean_object* lean_raylib_Image_to (Image const* obj) {
    return lean_alloc_external(lean_raylib_Image_class, (void*)obj);
}

static inline lean_obj_res lean_raylib_Image_exclusive(lean_obj_arg image_box) {
    if (LEAN_LIKELY(lean_is_exclusive(image_box))) {
        return image_box;
    }
    LET_BOX(Image, image_copy, ImageCopy(*lean_raylib_Image_from(image_box)));
    lean_object* image_copy_box = lean_raylib_Image_to(image_copy);
    lean_dec_ref(image_box);
    return image_copy_box;
}


// # Texture

typedef struct {
    lean_object* owner; // NOT NULLABLE
    Texture texture;
} lean_raylib_TextureRef;

typedef struct {
    Texture texture;
    lean_object* ctx; // NULLABLE
} lean_raylib_Texture;

extern lean_external_class* lean_raylib_TextureRef_class;
extern lean_external_class* lean_raylib_Texture_class;
extern lean_object* lean_raylib_Texture_empty;

static inline lean_object* lean_raylib_TextureRef_alloc (Texture2D texture, lean_obj_arg owner) {
    LET_BOX_STRUCT(lean_raylib_TextureRef, textureRef,
        .texture = texture,
        .owner = owner,
    );
    return lean_alloc_external(lean_raylib_TextureRef_class, textureRef);
}

static inline lean_raylib_TextureRef const* lean_raylib_TextureRef_from (b_lean_obj_arg obj) {
    return (lean_raylib_TextureRef const*) lean_get_external_data(obj);
}

static inline lean_object* lean_raylib_Texture_to (Texture texture, lean_obj_arg ctx) {
    LET_BOX_STRUCT(lean_raylib_Texture, textureWctx,
        .texture = texture,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Texture_class, (void*)textureWctx);
}

static inline Texture* lean_raylib_Texture_from (b_lean_obj_arg obj) {
    return (Texture*) lean_get_external_data(obj);
}


// # Render texture

extern lean_external_class* lean_raylib_RenderTexture_class;

static inline lean_object* lean_raylib_RenderTexture_to (RenderTexture const* obj) {
    return lean_alloc_external(lean_raylib_RenderTexture_class, (void*)obj);
}

static inline RenderTexture const* lean_raylib_RenderTexture_from (b_lean_obj_arg obj) {
    return (RenderTexture const*) lean_get_external_data(obj);
}


// # NPatch info

static inline lean_object* lean_raylib_NPatchInfo_to (NPatchInfo const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline NPatchInfo* lean_raylib_NPatchInfo_from (b_lean_obj_arg obj) {
    return (NPatchInfo*) lean_get_external_data(obj);
}


// # Glyph info

// static inline void lean_raylib_GlyphInfo_set (b_lean_obj_arg obj, uint32_t value, uint32_t offsetX, uint32_t offsetY, uint32_t advanceX, lean_obj_arg image) {
//     lean_ctor_set(obj, 0, lean_box_uint32(value));
//     lean_ctor_set(obj, 1, lean_box_uint32(offsetX));
//     lean_ctor_set(obj, 2, lean_box_uint32(offsetY));
//     lean_ctor_set(obj, 3, lean_box_uint32(advanceX));
//     lean_ctor_set(obj, 4, image); // todo: lean_dec_ref(lean_ctor_get(obj, 4))
// }

// static inline lean_object* lean_raylib_GlyphInfo_to (GlyphInfo r) {
//     lean_object* obj = lean_alloc_ctor(0, 5, 0);
//     LET_BOX(Image, image, r.image);
//     lean_raylib_GlyphInfo_set(obj, r.value, r.offsetX, r.offsetY, r.advanceX, lean_raylib_Image_to(image));
//     return obj;
// }

// static inline GlyphInfo lean_raylib_GlyphInfo_from (b_lean_obj_arg obj) {
//     GlyphInfo r;
//     r.value = lean_unbox_uint32(lean_ctor_get(obj, 0));
//     r.offsetX = lean_unbox_uint32(lean_ctor_get(obj, 1));
//     r.offsetY = lean_unbox_uint32(lean_ctor_get(obj, 2));
//     r.advanceX = lean_unbox_uint32(lean_ctor_get(obj, 3));
//     r.image = *lean_raylib_Image_from(lean_ctor_get(obj, 4));
//     return r;
// }


// # Font

extern lean_external_class* lean_raylib_Font_class;

static inline lean_object* lean_raylib_Font_to (Font const* obj) {
    return lean_alloc_external(lean_raylib_Font_class, (void*)obj);
}

static inline Font const* lean_raylib_Font_from (b_lean_obj_arg obj) {
    return (Font const*) lean_get_external_data(obj);
}


// # Camera 3D

static inline void lean_raylib_Camera3D_set_impl (b_lean_obj_arg obj, Camera3D cam) {
    lean_ctor_set(obj, 0, lean_raylib_Vector3_to(cam.position));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_to(cam.target));
    lean_ctor_set(obj, 2, lean_raylib_Vector3_to(cam.up));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(cam.fovy));
    lean_ctor_set(obj, 4, lean_box_uint32(cam.projection));
}

static inline void lean_raylib_Camera3D_set (b_lean_obj_arg obj, Camera3D cam) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_dec_ref(lean_ctor_get(obj, 2));
    lean_raylib_Camera3D_set_impl(obj, cam);
}

static inline lean_object* lean_raylib_Camera3D_to (Camera3D cam) {
    lean_object* obj = lean_alloc_ctor(0, 5, 0);
    lean_raylib_Camera3D_set_impl(obj, cam);
    return obj;
}

static inline Camera3D lean_raylib_Camera3D_from (b_lean_obj_arg obj) {
    Camera3D cam;
    cam.position = lean_raylib_Vector3_from(lean_ctor_get(obj, 0));
    cam.target = lean_raylib_Vector3_from(lean_ctor_get(obj, 1));
    cam.up = lean_raylib_Vector3_from(lean_ctor_get(obj, 2));
    cam.fovy = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 3)));
    cam.projection = lean_unbox_uint32(lean_ctor_get(obj, 4));
    return cam;
}


// # Camera 2D

static inline void lean_raylib_Camera2D_set_impl (b_lean_obj_arg obj, Camera2D cam) {
    lean_ctor_set(obj, 0, lean_raylib_Vector2_to(cam.offset));
    lean_ctor_set(obj, 1, lean_raylib_Vector2_to(cam.target));
    lean_ctor_set(obj, 2, lean_pod_Float32_box(cam.rotation));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(cam.zoom));
}

static inline void lean_raylib_Camera2D_set (b_lean_obj_arg obj, Camera2D cam) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_raylib_Camera2D_set_impl(obj, cam);
}

static inline lean_object* lean_raylib_Camera2D_to (Camera2D cam) {
    lean_object* obj = lean_alloc_ctor(0, 4, 0);
    lean_raylib_Camera2D_set_impl(obj, cam);
    return obj;
}

static inline Camera2D lean_raylib_Camera2D_from (b_lean_obj_arg obj) {
    Camera2D cam;
    cam.offset = lean_raylib_Vector2_from(lean_ctor_get(obj, 0));
    cam.target = lean_raylib_Vector2_from(lean_ctor_get(obj, 1));
    cam.rotation = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 2)));
    cam.zoom = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 3)));
    return cam;
}


// # Mesh

typedef struct {
    Mesh mesh;
    lean_object* ctx;
} lean_raylib_Mesh;

extern lean_external_class* lean_raylib_Mesh_class;

static inline lean_object* lean_raylib_Mesh_to (Mesh mesh, lean_obj_arg ctx) {
    LET_BOX_STRUCT(lean_raylib_Mesh, meshWctx,
        .mesh = mesh,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Mesh_class, (void*)meshWctx);
}

static inline Mesh* lean_raylib_Mesh_from (b_lean_obj_arg obj) {
    return (Mesh*) lean_get_external_data(obj);
}

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


// # Shader

typedef struct {
    Shader shader;
    lean_object* ctx;
} lean_raylib_Shader;

extern lean_external_class* lean_raylib_Shader_class;

static inline lean_object* lean_raylib_Shader_to (Shader shader, lean_obj_arg ctx) {
    LET_BOX_STRUCT(lean_raylib_Shader, shaderWctx,
        .shader = shader,
        .ctx = ctx
    );
    return lean_alloc_external(lean_raylib_Shader_class, (void*)shaderWctx);
}

static inline Shader* lean_raylib_Shader_from (b_lean_obj_arg obj) {
    return (Shader*) lean_get_external_data(obj);
}

lean_obj_res lean_raylib__Shader_getDefault(lean_obj_arg ctx);


// # Material

// NOTE: Returned mmap contains pointers to data owned by the boxed mmap!
static inline MaterialMap lean_raylib_MaterialMap_from (b_lean_obj_arg mmap_box) {
    MaterialMap mmap;
    mmap.texture = *lean_raylib_Texture_from(lean_ctor_get(mmap_box, 0));
    mmap.color = lean_raylib_Color_from(lean_unbox_uint32(lean_ctor_get(mmap_box, 1)));
    mmap.value = lean_pod_Float32_unbox(lean_ctor_get(mmap_box, 2));
    return mmap;
}

static inline lean_obj_res lean_raylib_MaterialMap_to (lean_obj_arg texture, Color color, float value) {
    lean_object* mmap = lean_alloc_ctor(0, 3, 0);
    lean_ctor_set(mmap, 0, texture);
    lean_ctor_set(mmap, 1, lean_box_uint32(lean_raylib_Color_to(color)));
    lean_ctor_set(mmap, 2, lean_pod_Float32_box(value));
    return mmap;
}

// todo: configure from lake (and pass to raylib (config.h - MAX_MATERIAL_MAPS))
#define LEAN_RAYLIB_MAX_MATERIAL_MAPS 12

// NOTE: Returned material contains pointers to `out_mmaps` and to data owned by the boxed material!
static inline Material lean_raylib_Material_from (b_lean_obj_arg material_box, MaterialMap* out_mmaps) {
    Material material;
    material.shader = *lean_raylib_Shader_from(lean_ctor_get(material_box, 0));
    lean_object* mmaps = lean_ctor_get(material_box, 1);
    for(size_t i = 0; i < LEAN_RAYLIB_MAX_MATERIAL_MAPS; ++i) {
        out_mmaps[i] = lean_raylib_MaterialMap_from(lean_array_get_core(mmaps, i));
    }
    material.maps = out_mmaps;
    material.params[0] = lean_pod_Float32_unbox(lean_ctor_get(material_box, 2));
    material.params[1] = lean_pod_Float32_unbox(lean_ctor_get(material_box, 3));
    material.params[2] = lean_pod_Float32_unbox(lean_ctor_get(material_box, 4));
    material.params[3] = lean_pod_Float32_unbox(lean_ctor_get(material_box, 5));
    return material;
}

static inline lean_obj_res lean_raylib_Material_to (lean_obj_arg shader, lean_obj_arg mmaps, Vector4 params) {
    lean_object* material = lean_alloc_ctor(0, 6, 0);
    lean_ctor_set(material, 0, shader);
    lean_ctor_set(material, 1, mmaps);
    lean_ctor_set(material, 2, lean_pod_Float32_box(params.x));
    lean_ctor_set(material, 3, lean_pod_Float32_box(params.y));
    lean_ctor_set(material, 4, lean_pod_Float32_box(params.z));
    lean_ctor_set(material, 5, lean_pod_Float32_box(params.w));
    return material;
}


// # Transform

static inline void lean_raylib_Transform_set_impl (b_lean_obj_arg obj, Transform transform) {
    lean_ctor_set(obj, 0, lean_raylib_Vector3_to(transform.translation));
    lean_ctor_set(obj, 1, lean_raylib_Vector4_to(transform.rotation));
    lean_ctor_set(obj, 2, lean_raylib_Vector3_to(transform.scale));
}

static inline void lean_raylib_Transform_set (b_lean_obj_arg obj, Transform transform) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_dec_ref(lean_ctor_get(obj, 2));
    lean_raylib_Transform_set_impl(obj, transform);
}

static inline lean_object* lean_raylib_Transform_to (Transform transform) {
    lean_object* obj = lean_alloc_ctor(0, 3, 0);
    lean_raylib_Transform_set_impl(obj, transform);
    return obj;
}

static inline Transform lean_raylib_Transform_from (b_lean_obj_arg obj) {
    Transform transform;
    transform.translation = lean_raylib_Vector3_from(lean_ctor_get(obj, 0));
    transform.rotation = lean_raylib_Vector4_from(lean_ctor_get(obj, 1));
    transform.scale = lean_raylib_Vector3_from(lean_ctor_get(obj, 2));
    return transform;
}


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

static inline lean_object* lean_raylib_BoneInfo_to (BoneInfo boneInfo) {
    lean_object* obj = lean_alloc_ctor(0, 2, 0);
    lean_raylib_BoneInfo_set_impl(obj, boneInfo);
    return obj;
}

static inline BoneInfo lean_raylib_BoneInfo_from (b_lean_obj_arg obj) {
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


// # Model

typedef struct {
    lean_object* materials; // Array Material
    lean_object* meshes; // Array (Mesh x Fin materials.size)
    uint32_t meshesCapacity;
    uint32_t materialsCapacity;
    Model model;
} lean_raylib_Model;

extern lean_external_class* lean_raylib_Model_class;

static inline lean_object* lean_raylib_Model_to (lean_raylib_Model model) {
    LET_BOX(lean_raylib_Model, modelBoxed, model);
    return lean_alloc_external(lean_raylib_Model_class, (void*)modelBoxed);
}

static inline lean_raylib_Model* lean_raylib_Model_from (b_lean_obj_arg obj) {
    return (lean_raylib_Model*)lean_get_external_data(obj);
}

static inline lean_raylib_Model lean_raylib_Model_clone(lean_raylib_Model* modelSrc) {
    lean_raylib_Model modelDst;
    lean_inc_ref(modelSrc->meshes);
    lean_inc_ref(modelSrc->materials);
    modelDst.meshes = modelSrc->meshes;
    modelDst.materials = modelSrc->materials;
    modelDst.model.transform = modelSrc->model.transform;
    modelDst.meshesCapacity = modelDst.model.meshCount = modelSrc->model.meshCount;
    modelDst.model.meshes = RL_MALLOC(modelDst.meshesCapacity * sizeof(Mesh));
    for (size_t i = 0; i < modelDst.model.meshCount; ++i) {
        modelDst.model.meshes[i] = lean_raylib_Mesh_clone(&modelSrc->model.meshes[i]);
    }
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

// static inline lean_object* lean_raylib_ModelAnimation_to (ModelAnimation const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(lean_raylib_free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline ModelAnimation const* lean_raylib_ModelAnimation_from (b_lean_obj_arg obj) {
//     return (ModelAnimation const*) lean_get_external_data(obj);
// }


// # Ray

static inline void lean_raylib_Ray_set (b_lean_obj_arg obj, Ray ray) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_ctor_set(obj, 0, lean_raylib_Vector3_to(ray.position));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_to(ray.direction));
}

static inline lean_object* lean_raylib_Ray_to (Ray ray) {
    lean_object* obj = lean_alloc_ctor(0, 2, 0);
    lean_ctor_set(obj, 0, lean_raylib_Vector3_to(ray.position));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_to(ray.direction));
    return obj;
}

static inline Ray lean_raylib_Ray_from (b_lean_obj_arg obj) {
    Ray ray;
    ray.position = lean_raylib_Vector3_from(lean_ctor_get(obj, 0));
    ray.direction = lean_raylib_Vector3_from(lean_ctor_get(obj, 1));
    return ray;
}


// # Ray collision

static inline void lean_raylib_RayCollision_set_impl (b_lean_obj_arg obj, RayCollision rayCol) {
    lean_ctor_set(obj, 0, lean_box(rayCol.hit));
    lean_ctor_set(obj, 1, lean_pod_Float32_box(rayCol.distance));
    lean_ctor_set(obj, 2, lean_raylib_Vector3_to(rayCol.point));
    lean_ctor_set(obj, 3, lean_raylib_Vector3_to(rayCol.normal));
}

static inline void lean_raylib_RayCollision_set (b_lean_obj_arg obj, RayCollision rayCol) {
    lean_dec_ref(lean_ctor_get(obj, 2));
    lean_dec_ref(lean_ctor_get(obj, 3));
    lean_raylib_RayCollision_set_impl(obj, rayCol);
}

static inline lean_object* lean_raylib_RayCollision_to (RayCollision rayCol) {
    lean_object* obj = lean_alloc_ctor(0, 4, 0);
    lean_raylib_RayCollision_set_impl(obj, rayCol);
    return obj;
}

static inline RayCollision lean_raylib_RayCollision_from (b_lean_obj_arg obj) {
    RayCollision rayCol;
    rayCol.hit = lean_unbox(lean_ctor_get(obj, 0));
    rayCol.distance = lean_pod_Float32_unbox(lean_ctor_get(obj, 1));
    rayCol.point = lean_raylib_Vector3_from(lean_ctor_get(obj, 2));
    rayCol.normal = lean_raylib_Vector3_from(lean_ctor_get(obj, 3));
    return rayCol;
}


// # Bounding box

static inline void lean_raylib_BoundingBox_set (b_lean_obj_arg obj, BoundingBox bb) {
    lean_dec_ref(lean_ctor_get(obj, 0));
    lean_ctor_set(obj, 0, lean_raylib_Vector3_to(bb.min));
    lean_dec_ref(lean_ctor_get(obj, 1));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_to(bb.max));
}

static inline lean_object* lean_raylib_BoundingBox_to (BoundingBox bb) {
    lean_object* obj = lean_alloc_ctor(0, 2, 0);
    lean_ctor_set(obj, 0, lean_raylib_Vector3_to(bb.min));
    lean_ctor_set(obj, 1, lean_raylib_Vector3_to(bb.max));
    return obj;
}

static inline BoundingBox lean_raylib_BoundingBox_from (b_lean_obj_arg obj) {
    BoundingBox bb;
    bb.min = lean_raylib_Vector3_from(lean_ctor_get(obj, 0));
    bb.max = lean_raylib_Vector3_from(lean_ctor_get(obj, 1));
    return bb;
}


// # Wave

extern lean_external_class* lean_raylib_Wave_class;

static inline lean_object* lean_raylib_Wave_to (Wave const* obj) {
    return lean_alloc_external(lean_raylib_Wave_class, (void*)obj);
}

static inline Wave* lean_raylib_Wave_from (b_lean_obj_arg obj) {
    return (Wave*) lean_get_external_data(obj);
}


// # Audio stream

typedef struct {
    AudioStream stream;
#ifdef LEAN_RAYLIB_LIBFFI
    ffi_closure* closure; // NULLABLE
#endif
} lean_raylib_AudioStream;

extern lean_external_class* lean_raylib_AudioStream_class;

static inline lean_object* lean_raylib_AudioStream_to (AudioStream stream, void* closure) {
    lean_raylib_AudioStream* stream_heap = lean_raylib_alloc(sizeof(lean_raylib_AudioStream));
    stream_heap->stream = stream;
#ifdef LEAN_RAYLIB_LIBFFI
    stream_heap->closure = closure;
#endif
    return lean_alloc_external(lean_raylib_AudioStream_class, (void*)stream_heap);
}

static inline lean_raylib_AudioStream* lean_raylib_AudioStream_from (b_lean_obj_arg obj) {
    return (lean_raylib_AudioStream*) lean_get_external_data(obj);
}


// # Sound

extern lean_external_class* lean_raylib_Sound_class;

static inline lean_object* lean_raylib_Sound_to (Sound const* obj) {
    return lean_alloc_external(lean_raylib_Sound_class, (void*)obj);
}

static inline Sound const* lean_raylib_Sound_from (b_lean_obj_arg obj) {
    return (Sound const*) lean_get_external_data(obj);
}


// # Music

extern lean_external_class* lean_raylib_Music_class;

static inline lean_object* lean_raylib_Music_to (Music const* obj) {
    return lean_alloc_external(lean_raylib_Music_class, (void*)obj);
}

static inline Music * lean_raylib_Music_from (b_lean_obj_arg obj) {
    return (Music*) lean_get_external_data(obj);
}


// # Vr device info

static inline void lean_raylib_VrDeviceInfo_set_impl (b_lean_obj_arg obj, VrDeviceInfo* vrDeviceInfo) {
    lean_ctor_set(obj, 0, lean_box_uint32(vrDeviceInfo->hResolution));
    lean_ctor_set(obj, 1, lean_box_uint32(vrDeviceInfo->vResolution));
    lean_ctor_set(obj, 2, lean_pod_Float32_box(vrDeviceInfo->hScreenSize));
    lean_ctor_set(obj, 3, lean_pod_Float32_box(vrDeviceInfo->vScreenSize));
    lean_ctor_set(obj, 4, lean_pod_Float32_box(vrDeviceInfo->vScreenCenter));
    lean_ctor_set(obj, 5, lean_pod_Float32_box(vrDeviceInfo->eyeToScreenDistance));
    lean_ctor_set(obj, 6, lean_pod_Float32_box(vrDeviceInfo->lensSeparationDistance));
    lean_ctor_set(obj, 7, lean_pod_Float32_box(vrDeviceInfo->interpupillaryDistance));
    Vector4 lensDistortionValues;
    lensDistortionValues.x = vrDeviceInfo->lensDistortionValues[0];
    lensDistortionValues.y = vrDeviceInfo->lensDistortionValues[1];
    lensDistortionValues.z = vrDeviceInfo->lensDistortionValues[2];
    lensDistortionValues.w = vrDeviceInfo->lensDistortionValues[3];
    lean_ctor_set(obj, 8, lean_raylib_Vector4_to(lensDistortionValues));
    Vector4 chromaAbCorrection;
    chromaAbCorrection.x = vrDeviceInfo->chromaAbCorrection[0];
    chromaAbCorrection.y = vrDeviceInfo->chromaAbCorrection[1];
    chromaAbCorrection.z = vrDeviceInfo->chromaAbCorrection[2];
    chromaAbCorrection.w = vrDeviceInfo->chromaAbCorrection[3];
    lean_ctor_set(obj, 9, lean_raylib_Vector4_to(chromaAbCorrection));
}

static inline void lean_raylib_VrDeviceInfo_set (b_lean_obj_arg obj, VrDeviceInfo* vrDeviceInfo) {
    lean_dec_ref(lean_ctor_get(obj, 8));
    lean_dec_ref(lean_ctor_get(obj, 9));
    lean_raylib_VrDeviceInfo_set_impl(obj, vrDeviceInfo);
}

static inline lean_object* lean_raylib_VrDeviceInfo_to (VrDeviceInfo* vrDeviceInfo) {
    lean_object* obj = lean_alloc_ctor(0, 10, 0);
    lean_raylib_VrDeviceInfo_set_impl(obj, vrDeviceInfo);
    return obj;
}

static inline VrDeviceInfo lean_raylib_VrDeviceInfo_from (b_lean_obj_arg obj) {
    VrDeviceInfo vrDeviceInfo;
    vrDeviceInfo.hResolution = lean_unbox_uint32(lean_ctor_get(obj, 0));
    vrDeviceInfo.vResolution = lean_unbox_uint32(lean_ctor_get(obj, 1));
    vrDeviceInfo.hScreenSize = lean_pod_Float32_unbox(lean_ctor_get(obj, 2));
    vrDeviceInfo.vScreenSize = lean_pod_Float32_unbox(lean_ctor_get(obj, 3));
    vrDeviceInfo.vScreenCenter = lean_pod_Float32_unbox(lean_ctor_get(obj, 4));
    vrDeviceInfo.eyeToScreenDistance = lean_pod_Float32_unbox(lean_ctor_get(obj, 5));
    vrDeviceInfo.lensSeparationDistance = lean_pod_Float32_unbox(lean_ctor_get(obj, 6));
    vrDeviceInfo.interpupillaryDistance = lean_pod_Float32_unbox(lean_ctor_get(obj, 7));
    Vector4 lensDistortionValues = lean_raylib_Vector4_from(lean_ctor_get(obj, 8));
    vrDeviceInfo.lensDistortionValues[0] = lensDistortionValues.x;
    vrDeviceInfo.lensDistortionValues[1] = lensDistortionValues.y;
    vrDeviceInfo.lensDistortionValues[2] = lensDistortionValues.z;
    vrDeviceInfo.lensDistortionValues[3] = lensDistortionValues.w;
    Vector4 chromaAbCorrection = lean_raylib_Vector4_from(lean_ctor_get(obj, 9));
    vrDeviceInfo.chromaAbCorrection[0] = chromaAbCorrection.x;
    vrDeviceInfo.chromaAbCorrection[1] = chromaAbCorrection.y;
    vrDeviceInfo.chromaAbCorrection[2] = chromaAbCorrection.z;
    vrDeviceInfo.chromaAbCorrection[3] = chromaAbCorrection.w;
    return vrDeviceInfo;
}


// # Vr stereo config

static inline void lean_raylib_VrStereoConfig_set_impl (b_lean_obj_arg obj, VrStereoConfig* vrStereoConfig) {
    lean_ctor_set(obj, 0, lean_raylib_Matrix_to(vrStereoConfig->projection[0]));
    lean_ctor_set(obj, 1, lean_raylib_Matrix_to(vrStereoConfig->projection[1]));
    lean_ctor_set(obj, 2, lean_raylib_Matrix_to(vrStereoConfig->viewOffset[0]));
    lean_ctor_set(obj, 3, lean_raylib_Matrix_to(vrStereoConfig->viewOffset[1]));
    Vector2 leftLensCenter;
    leftLensCenter.x = vrStereoConfig->leftLensCenter[0];
    leftLensCenter.y = vrStereoConfig->leftLensCenter[1];
    lean_ctor_set(obj, 4, lean_raylib_Vector2_to(leftLensCenter));
    Vector2 rightLensCenter;
    rightLensCenter.x = vrStereoConfig->rightLensCenter[0];
    rightLensCenter.y = vrStereoConfig->rightLensCenter[1];
    lean_ctor_set(obj, 5, lean_raylib_Vector2_to(rightLensCenter));
    Vector2 leftScreenCenter;
    leftScreenCenter.x = vrStereoConfig->leftScreenCenter[0];
    leftScreenCenter.y = vrStereoConfig->leftScreenCenter[1];
    lean_ctor_set(obj, 6, lean_raylib_Vector2_to(leftScreenCenter));
    Vector2 rightScreenCenter;
    rightScreenCenter.x = vrStereoConfig->rightScreenCenter[0];
    rightScreenCenter.y = vrStereoConfig->rightScreenCenter[1];
    lean_ctor_set(obj, 7, lean_raylib_Vector2_to(rightScreenCenter));
    Vector2 scale;
    scale.x = vrStereoConfig->scale[0];
    scale.y = vrStereoConfig->scale[1];
    lean_ctor_set(obj, 8, lean_raylib_Vector2_to(scale));
    Vector2 scaleIn;
    scaleIn.x = vrStereoConfig->scaleIn[0];
    scaleIn.y = vrStereoConfig->scaleIn[1];
    lean_ctor_set(obj, 9, lean_raylib_Vector2_to(scaleIn));
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

static inline lean_object* lean_raylib_VrStereoConfig_to (VrStereoConfig* vrStereoConfig) {
    lean_object* obj = lean_alloc_ctor(0, 10, 0);
    lean_raylib_VrStereoConfig_set_impl(obj, vrStereoConfig);
    return obj;
}

static inline VrStereoConfig lean_raylib_VrStereoConfig_from (b_lean_obj_arg obj) {
    VrStereoConfig vrStereoConfig;
    vrStereoConfig.projection[0] = lean_raylib_Matrix_from(lean_ctor_get(obj, 0));
    vrStereoConfig.projection[1] = lean_raylib_Matrix_from(lean_ctor_get(obj, 1));
    vrStereoConfig.viewOffset[0] = lean_raylib_Matrix_from(lean_ctor_get(obj, 2));
    vrStereoConfig.viewOffset[1] = lean_raylib_Matrix_from(lean_ctor_get(obj, 3));
    Vector2 leftLensCenter = lean_raylib_Vector2_from(lean_ctor_get(obj, 4));
    vrStereoConfig.leftLensCenter[0] = leftLensCenter.x;
    vrStereoConfig.leftLensCenter[1] = leftLensCenter.y;
    Vector2 rightLensCenter = lean_raylib_Vector2_from(lean_ctor_get(obj, 5));
    vrStereoConfig.rightLensCenter[0] = rightLensCenter.x;
    vrStereoConfig.rightLensCenter[1] = rightLensCenter.y;
    Vector2 leftScreenCenter = lean_raylib_Vector2_from(lean_ctor_get(obj, 6));
    vrStereoConfig.leftScreenCenter[0] = leftScreenCenter.x;
    vrStereoConfig.leftScreenCenter[1] = leftScreenCenter.y;
    Vector2 rightScreenCenter = lean_raylib_Vector2_from(lean_ctor_get(obj, 7));
    vrStereoConfig.rightScreenCenter[0] = rightScreenCenter.x;
    vrStereoConfig.rightScreenCenter[1] = rightScreenCenter.y;
    Vector2 scale = lean_raylib_Vector2_from(lean_ctor_get(obj, 8));
    vrStereoConfig.scale[0] = scale.x;
    vrStereoConfig.scale[1] = scale.y;
    Vector2 scaleIn = lean_raylib_Vector2_from(lean_ctor_get(obj, 9));
    vrStereoConfig.scaleIn[0] = scaleIn.x;
    vrStereoConfig.scaleIn[1] = scaleIn.y;
    return vrStereoConfig;
}


// # Window Handle

extern lean_external_class* lean_raylib_WindowHandle_class;

static inline lean_object* lean_raylib_WindowHandle_box (void* handle) {
    return lean_alloc_external(lean_raylib_WindowHandle_class, handle);
}
