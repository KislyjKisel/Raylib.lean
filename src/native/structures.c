#include <memory.h>
#include "util.h"
#include <rlgl.h>
#include "structures.h"

lean_object* lean_raylib_Image_empty;
lean_object* lean_raylib_Texture_default;
lean_object* lean_raylib_Texture_empty;
lean_object* lean_raylib_Shader_default;
lean_object* lean_raylib_Material_default;

LEAN_EXPORT lean_obj_res lean_raylib_initialize_Structures(lean_obj_arg world) {
    {
        LET_BOX_STRUCT(Image, emptyImage,
            .data = NULL,
            .width = 0,
            .height = 0,
            .mipmaps = 1,
            .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
        );
        lean_raylib_Image_empty = lean_raylib_Image_to(emptyImage);
        lean_mark_persistent(lean_raylib_Image_empty);
    }
    {
        LET_BOX_STRUCT(Texture, defaultTexture,
            .id = rlGetTextureIdDefault(),
            .width = 1,
            .height = 1,
            .mipmaps = 1,
            .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
        );
        lean_raylib_Texture_default = lean_raylib_Texture_to(defaultTexture);
        lean_mark_persistent(lean_raylib_Texture_default);
    }
    {
        LET_BOX(Texture, emptyTexture, (Texture){0});
        lean_raylib_Texture_empty = lean_raylib_Texture_to(emptyTexture);
        lean_mark_persistent(lean_raylib_Texture_empty);
    }
    {
        LET_BOX_STRUCT(Shader, defaultShader,
            .id = rlGetShaderIdDefault(),
            .locs = rlGetShaderLocsDefault()
        );
        lean_raylib_Shader_default = lean_raylib_Shader_to(defaultShader);
        lean_mark_persistent(lean_raylib_Shader_default);
    }
    {
        lean_object* mmaps = lean_alloc_array(LEAN_RAYLIB_MAX_MATERIAL_MAPS, LEAN_RAYLIB_MAX_MATERIAL_MAPS);
        lean_array_set_core(
            mmaps,
            MATERIAL_MAP_DIFFUSE, // 0
            lean_raylib_MaterialMap_to(lean_raylib_Texture_default, WHITE, 0.0f)
        );
        lean_array_set_core(
            mmaps,
            MATERIAL_MAP_SPECULAR, // 1
            lean_raylib_MaterialMap_to(lean_raylib_Texture_empty, WHITE, 0.0f)
        );
        for (size_t i = 2; i < LEAN_RAYLIB_MAX_MATERIAL_MAPS; ++i) {
            lean_array_set_core(
                mmaps,
                i,
                lean_raylib_MaterialMap_to(lean_raylib_Texture_empty, BLANK, 0.0f)
            );
        }
        lean_raylib_Material_default = lean_raylib_Material_to(
            lean_raylib_Shader_default,
            mmaps,
            (Vector4) { .x = 0, .y = 0, .z = 0, .w = 0 }
        );
        lean_mark_persistent(lean_raylib_Material_default);
    }
    return lean_io_result_mk_ok(lean_box(0));
}

// # VaList

LEAN_EXPORT lean_obj_res lean_raylib__VaList_next(b_lean_obj_arg vl, uint8_t typ, lean_obj_arg token) {
    lean_object* value;
    switch(typ) {
        case 0:
            value = lean_box_uint32((uint32_t)va_arg(lean_raylib_VaList_from(vl)->v, int32_t));
            break;
        case 1:
            value = lean_box_uint32(va_arg(lean_raylib_VaList_from(vl)->v, uint32_t));
            break;
        case 2:
            value = lean_box_uint64(va_arg(lean_raylib_VaList_from(vl)->v, uint64_t));
            break;
        case 3:
            value = lean_box_float(va_arg(lean_raylib_VaList_from(vl)->v, double));
            break;
        case 4:
            value = lean_mk_string(va_arg(lean_raylib_VaList_from(vl)->v, const char*));
            break;
        default:
            lean_internal_panic_unreachable();
    }
    return lean_io_result_mk_ok(value);
}


// # Image

LEAN_EXPORT uint32_t lean_raylib__Image_width(b_lean_obj_arg obj) {
    return lean_raylib_Image_from(obj)->width;
}

LEAN_EXPORT uint32_t lean_raylib__Image_height(b_lean_obj_arg obj) {
    return lean_raylib_Image_from(obj)->height;
}

LEAN_EXPORT uint32_t lean_raylib__Image_mipmaps(b_lean_obj_arg obj) {
    return lean_raylib_Image_from(obj)->mipmaps;
}

LEAN_EXPORT uint32_t lean_raylib__Image_format(b_lean_obj_arg obj) {
    return lean_raylib_Image_from(obj)->format;
}

LEAN_EXPORT lean_obj_res lean_raylib__Image_getEmpty(lean_obj_arg unit) {
    return lean_raylib_Image_empty;
}


// # Texture

LEAN_EXPORT lean_obj_res lean_raylib__Texture_ref(lean_obj_arg texture) {
    return lean_raylib_TextureRef_alloc(
        *lean_raylib_Texture_from(texture),
        texture
    );
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_id(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_from(obj)->texture.id;
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_width(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_from(obj)->texture.width;
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_height(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_from(obj)->texture.height;
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_mipmaps(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_from(obj)->texture.mipmaps;
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_format(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_from(obj)->texture.format;
}

LEAN_EXPORT lean_obj_res lean_raylib__Texture_getEmpty(lean_obj_arg unit) {
    return lean_raylib_Texture_empty;

}

LEAN_EXPORT lean_obj_res lean_raylib__Texture_getDefault(lean_obj_arg unit) {
    return lean_raylib_Texture_default;
}


// # Render texture

LEAN_EXPORT uint32_t lean_raylib__RenderTexture_id(b_lean_obj_arg obj) {
    return lean_raylib_RenderTexture_from(obj)->id;
}

LEAN_EXPORT lean_obj_res lean_raylib__RenderTexture_texture(lean_obj_arg rt_box) {
    return lean_raylib_TextureRef_alloc(
        lean_raylib_RenderTexture_from(rt_box)->texture,
        rt_box
    );
}


// # NPatch info

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_mk(
    b_lean_obj_arg source, uint32_t left, uint32_t top,
    uint32_t right, uint32_t bottom, uint32_t layout
) {
    LET_BOX_STRUCT(NPatchInfo, npatchInfo,
        .source = lean_raylib_Rectangle_from(source),
        .left = left,
        .top = top,
        .right = right,
        .bottom = bottom,
        .layout = layout
    );
    return lean_raylib_NPatchInfo_to(npatchInfo);
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_source(b_lean_obj_arg npatchInfo) {
    return lean_raylib_Rectangle_to(lean_raylib_NPatchInfo_from(npatchInfo)->source);
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_source_set(b_lean_obj_arg source_box, lean_obj_arg npatchInfo_box) {
    Rectangle source = lean_raylib_Rectangle_from(source_box);
    if(LEAN_LIKELY(lean_is_exclusive(npatchInfo_box))) {
        lean_raylib_NPatchInfo_from(npatchInfo_box)->source = source;
        return npatchInfo_box;
    }
    lean_dec_ref(npatchInfo_box);
    LET_BOX(NPatchInfo, npatchInfo_new, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new->source = source;
    return lean_raylib_NPatchInfo_to(npatchInfo_new);
}

LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_left(b_lean_obj_arg npatchInfo) {
    return lean_raylib_NPatchInfo_from(npatchInfo)->left;
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_left_set(uint32_t left, lean_obj_arg npatchInfo_box) {
    if(LEAN_LIKELY(lean_is_exclusive(npatchInfo_box))) {
        lean_raylib_NPatchInfo_from(npatchInfo_box)->left = left;
        return npatchInfo_box;
    }
    lean_dec_ref(npatchInfo_box);
    LET_BOX(NPatchInfo, npatchInfo_new, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new->left = left;
    return lean_raylib_NPatchInfo_to(npatchInfo_new);
}

LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_top(b_lean_obj_arg npatchInfo) {
    return lean_raylib_NPatchInfo_from(npatchInfo)->top;
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_top_set(uint32_t top, lean_obj_arg npatchInfo_box) {
    if(LEAN_LIKELY(lean_is_exclusive(npatchInfo_box))) {
        lean_raylib_NPatchInfo_from(npatchInfo_box)->top = top;
        return npatchInfo_box;
    }
    lean_dec_ref(npatchInfo_box);
    LET_BOX(NPatchInfo, npatchInfo_new, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new->top = top;
    return lean_raylib_NPatchInfo_to(npatchInfo_new);
}

LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_right(b_lean_obj_arg npatchInfo) {
    return lean_raylib_NPatchInfo_from(npatchInfo)->right;
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_right_set(uint32_t right, lean_obj_arg npatchInfo_box) {
    if(LEAN_LIKELY(lean_is_exclusive(npatchInfo_box))) {
        lean_raylib_NPatchInfo_from(npatchInfo_box)->right = right;
        return npatchInfo_box;
    }
    lean_dec_ref(npatchInfo_box);
    LET_BOX(NPatchInfo, npatchInfo_new, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new->right = right;
    return lean_raylib_NPatchInfo_to(npatchInfo_new);

}

LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_bottom(b_lean_obj_arg npatchInfo) {
    return lean_raylib_NPatchInfo_from(npatchInfo)->bottom;
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_bottom_set(uint32_t bottom, lean_obj_arg npatchInfo_box) {
    if(LEAN_LIKELY(lean_is_exclusive(npatchInfo_box))) {
        lean_raylib_NPatchInfo_from(npatchInfo_box)->bottom = bottom;
        return npatchInfo_box;
    }
    lean_dec_ref(npatchInfo_box);
    LET_BOX(NPatchInfo, npatchInfo_new, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new->bottom = bottom;
    return lean_raylib_NPatchInfo_to(npatchInfo_new);

}

LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_layout(b_lean_obj_arg npatchInfo) {
    return lean_raylib_NPatchInfo_from(npatchInfo)->layout;
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_layout_set(uint32_t layout, lean_obj_arg npatchInfo_box) {
    if(LEAN_LIKELY(lean_is_exclusive(npatchInfo_box))) {
        lean_raylib_NPatchInfo_from(npatchInfo_box)->layout = layout;
        return npatchInfo_box;
    }
    lean_dec_ref(npatchInfo_box);
    LET_BOX(NPatchInfo, npatchInfo_new, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new->layout = layout;
    return lean_raylib_NPatchInfo_to(npatchInfo_new);
}


// # Font

LEAN_EXPORT uint32_t lean_raylib__Font_baseSize(b_lean_obj_arg obj) {
    return lean_raylib_Font_from(obj)->baseSize;
}

LEAN_EXPORT uint32_t lean_raylib__Font_glyphCount(b_lean_obj_arg obj) {
    return lean_raylib_Font_from(obj)->glyphCount;
}

LEAN_EXPORT uint32_t lean_raylib__Font_glyphPadding(b_lean_obj_arg obj) {
    return lean_raylib_Font_from(obj)->glyphPadding;
}

LEAN_EXPORT lean_obj_res lean_raylib__Font_texture(lean_obj_arg obj) {
    return lean_raylib_TextureRef_alloc(lean_raylib_Font_from(obj)->texture, obj);
}

LEAN_EXPORT lean_obj_res lean_raylib__Font_recs(b_lean_obj_arg obj) {
    const Font* font = lean_raylib_Font_from(obj);
    lean_object* arr = lean_alloc_array(font->glyphCount, font->glyphCount);
    for(size_t i = 0; i < font->glyphCount; ++i) {
        lean_array_set_core(arr, i, lean_raylib_Rectangle_to(font->recs[i]));
    }
    return arr;
}


// # Mesh

LEAN_EXPORT lean_obj_res lean_raylib__Mesh_mkBv(
    uint32_t vertexCount,
    b_lean_obj_arg vertices,
    b_lean_obj_arg texcoords,
    b_lean_obj_arg texcoords2,
    b_lean_obj_arg normals,
    b_lean_obj_arg tangents,
    b_lean_obj_arg colors,
    b_lean_obj_arg skinning
) {
    Mesh mesh = {0};
    mesh.vertexCount = vertexCount;
    mesh.triangleCount = vertexCount / 3;

    mesh.vertices = lean_raylib_rlmemdup(
        lean_pod_BytesView_unwrap(vertices)->ptr,
        sizeof(float[3]) * vertexCount
    );

    if(lean_option_is_some(texcoords)) {
        mesh.texcoords = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(texcoords, 0))->ptr,
            sizeof(float[2]) * vertexCount
        );
    }
    if(lean_option_is_some(texcoords2)) {
        mesh.texcoords2 = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(texcoords2, 0))->ptr,
            sizeof(float[2]) * vertexCount
        );
    }
    if(lean_option_is_some(normals)) {
        mesh.normals = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(normals, 0))->ptr,
            sizeof(float[3]) * vertexCount
        );
    }
    if(lean_option_is_some(tangents)) {
        mesh.tangents = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(tangents, 0))->ptr,
            sizeof(float[4]) * vertexCount
        );
    }
    if(lean_option_is_some(colors)) {
        mesh.colors = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(colors, 0))->ptr,
            sizeof(unsigned char[4]) * vertexCount
        );
    }
    if(lean_option_is_some(skinning) && mesh.normals != NULL) {
        lean_object* skinning_val = lean_ctor_get(skinning, 0);
        mesh.boneIds = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(skinning_val, 0))->ptr,
            sizeof(unsigned char[4]) * vertexCount
        );
        mesh.boneWeights = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(skinning_val, 1))->ptr,
            sizeof(float[4]) * vertexCount
        );
        mesh.animVertices = lean_raylib_rlmemdup(
            mesh.vertices,
            sizeof(float[3]) * vertexCount
        );
        mesh.animNormals = lean_raylib_rlmemdup(
            mesh.normals,
            sizeof(float[3]) * vertexCount
        );
    }
    LET_BOX(Mesh, mesh_heap, mesh);
    return lean_raylib_Mesh_to(mesh_heap);
}


LEAN_EXPORT lean_obj_res lean_raylib__Mesh_mkIndexedBv(
    uint32_t vertexCount,
    uint32_t triangleCount,
    b_lean_obj_arg vertices,
    b_lean_obj_arg indices,
    b_lean_obj_arg texcoords,
    b_lean_obj_arg texcoords2,
    b_lean_obj_arg normals,
    b_lean_obj_arg tangents,
    b_lean_obj_arg colors,
    b_lean_obj_arg skinning
) {
    Mesh mesh = {0};
    void* indices_c = lean_pod_BytesView_unwrap(indices)->ptr;
    #ifndef NDEBUG
        for(size_t i = 0; i < 3 * triangleCount; ++i) {
            uint16_t index;
            memcpy(&index, indices_c + i * sizeof(uint16_t), sizeof(index));
            if(index >= vertexCount) {
                LET_BOX(Mesh, mesh_heap, mesh);
                return lean_panic_fn(
                    lean_raylib_Mesh_to(mesh_heap),
                    lean_mk_string("Mesh index out of bounds")
                );
            }
        }
    #endif
    mesh.vertexCount = vertexCount;
    mesh.triangleCount = triangleCount;

    mesh.vertices = lean_raylib_rlmemdup(
        lean_pod_BytesView_unwrap(vertices)->ptr,
        sizeof(float[3]) * vertexCount
    );
    mesh.indices = lean_raylib_rlmemdup(
        indices_c,
        sizeof(uint16_t[3]) * triangleCount
    );
    if(lean_option_is_some(texcoords)) {
        mesh.texcoords = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(texcoords, 0))->ptr,
            sizeof(float[2]) * vertexCount
        );
    }
    if(lean_option_is_some(texcoords2)) {
        mesh.texcoords2 = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(texcoords2, 0))->ptr,
            sizeof(float[2]) * vertexCount
        );
    }
    if(lean_option_is_some(normals)) {
        mesh.normals = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(normals, 0))->ptr,
            sizeof(float[3]) * vertexCount
        );
    }
    if(lean_option_is_some(tangents)) {
        mesh.tangents = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(tangents, 0))->ptr,
            sizeof(float[4]) * vertexCount
        );
    }
    if(lean_option_is_some(colors)) {
        mesh.colors = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(colors, 0))->ptr,
            sizeof(unsigned char[4]) * vertexCount
        );
    }
    if(lean_option_is_some(skinning) && mesh.normals != NULL) {
        lean_object* skinning_val = lean_ctor_get(skinning, 0);
        mesh.boneIds = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(skinning_val, 0))->ptr,
            sizeof(unsigned char[4]) * vertexCount
        );
        mesh.boneWeights = lean_raylib_rlmemdup(
            lean_pod_BytesView_unwrap(lean_ctor_get(skinning_val, 1))->ptr,
            sizeof(float[4]) * vertexCount
        );
        mesh.animVertices = lean_raylib_rlmemdup(
            mesh.vertices,
            sizeof(float[3]) * vertexCount
        );
        mesh.animNormals = lean_raylib_rlmemdup(
            mesh.normals,
            sizeof(float[3]) * vertexCount
        );
    }
    LET_BOX(Mesh, mesh_heap, mesh);
    return lean_raylib_Mesh_to(mesh_heap);
}

LEAN_EXPORT uint32_t lean_raylib__Mesh_vertexCount(b_lean_obj_arg mesh) {
    return lean_raylib_Mesh_from(mesh)->vertexCount;
}

LEAN_EXPORT uint32_t lean_raylib__Mesh_triangleCount(b_lean_obj_arg mesh) {
    return lean_raylib_Mesh_from(mesh)->triangleCount;
}

LEAN_EXPORT lean_obj_res lean_raylib__Mesh_vertices(lean_obj_arg mesh) {
    float* vertices = lean_raylib_Mesh_from(mesh)->vertices;
    return lean_pod_BytesView_wrap((unsigned char*)vertices, mesh);
}

#define LEAN_RAYLIB_MESH_VIEW_OPT(id, ty)\
LEAN_EXPORT lean_obj_arg lean_raylib__Mesh_##id(b_lean_obj_arg mesh) {\
    ty * id = lean_raylib_Mesh_from(mesh)-> id;\
    if(id == NULL) {\
        return lean_mk_option_none();\
    }\
    else {\
        return lean_mk_option_some(lean_pod_BytesView_wrap((unsigned char*)id, mesh));\
    }\
}

LEAN_RAYLIB_MESH_VIEW_OPT(texcoords, float);
LEAN_RAYLIB_MESH_VIEW_OPT(texcoords2, float);
LEAN_RAYLIB_MESH_VIEW_OPT(normals, float);
LEAN_RAYLIB_MESH_VIEW_OPT(tangents, float);
LEAN_RAYLIB_MESH_VIEW_OPT(colors, unsigned char);
LEAN_RAYLIB_MESH_VIEW_OPT(indices, unsigned short);
LEAN_RAYLIB_MESH_VIEW_OPT(animVertices, float);
LEAN_RAYLIB_MESH_VIEW_OPT(animNormals, float);
LEAN_RAYLIB_MESH_VIEW_OPT(boneIds, unsigned char);
LEAN_RAYLIB_MESH_VIEW_OPT(boneWeights, float);

LEAN_EXPORT uint32_t lean_raylib__Mesh_vaoId(b_lean_obj_arg mesh) {
    return lean_raylib_Mesh_from(mesh)->vaoId;
}

LEAN_EXPORT uint32_t lean_raylib__Mesh_vboId(b_lean_obj_arg mesh, b_lean_obj_arg i) {
    return lean_raylib_Mesh_from(mesh)->vboId[lean_usize_of_nat(i)];
}


// # Shader

LEAN_EXPORT uint32_t lean_raylib__Shader_id(b_lean_obj_arg shader) {
    return lean_raylib_Shader_from(shader)->id;
}

LEAN_EXPORT lean_obj_res lean_raylib__Shader_locs(b_lean_obj_arg shader) {
    int* locs_c = lean_raylib_Shader_from(shader)->locs;
    size_t count = 0;
    for(size_t i = 0; i < RL_MAX_SHADER_LOCATIONS; ++i) {
        count += locs_c[i] >= 0;
    }
    lean_object* locs_lean = lean_alloc_array(count, count);
    size_t last = 0;
    for(size_t i = 0; i < RL_MAX_SHADER_LOCATIONS; ++i) {
        if(locs_c[i] >= 0) {
            lean_array_set_core(locs_lean, last++, lean_box_uint32(locs_c[i]));
        }
    }
    return locs_lean;
}

LEAN_EXPORT lean_obj_res lean_raylib__Shader_defaultLoc(b_lean_obj_arg shader, uint32_t index) {
    int location = lean_raylib_Shader_from(shader)->locs[index];
    if (location < 0) {
        return lean_mk_option_none();
    }
    else {
        return lean_mk_option_some(lean_box_uint32(location));
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__Shader_getDefault(lean_obj_arg unit) {
    return lean_raylib_Shader_default;
}


// # Material

LEAN_EXPORT lean_obj_res lean_raylib__Material_getDefault(lean_obj_arg unit) {
    return lean_raylib_Material_default;
}


// # Model

LEAN_EXPORT lean_obj_res lean_raylib__Model_mk(
    b_lean_obj_arg transform, lean_obj_arg materials, lean_obj_arg meshes,
    b_lean_obj_arg bones, b_lean_obj_arg bindPose
) {
    lean_raylib_Model lmodel;
    lmodel.materials = materials;
    lmodel.meshes = meshes;
    lmodel.model.transform = lean_raylib_Matrix_from(transform);
    lmodel.meshesCapacity = lmodel.model.meshCount = lean_array_size(meshes);
    lmodel.materialsCapacity = lmodel.model.materialCount = lean_array_size(materials);
    lmodel.model.meshes = RL_MALLOC(lmodel.meshesCapacity * sizeof(Mesh));
    lmodel.model.meshMaterial = RL_MALLOC(lmodel.meshesCapacity * sizeof(int));
    for (size_t i = 0; i < lmodel.model.meshCount; ++i) {
        lean_object* meshXmatIdx = lean_array_get_core(meshes, i);
        lmodel.model.meshes[i] = *lean_raylib_Mesh_from(lean_ctor_get(meshXmatIdx, 0));
        lmodel.model.meshMaterial[i] = lean_usize_of_nat(lean_ctor_get(meshXmatIdx, 1));
    }
    lmodel.model.materials = RL_MALLOC(lmodel.materialsCapacity * sizeof(Material));
    for (size_t i = 0; i < lmodel.model.materialCount; ++i) {
        lmodel.model.materials[i] = lean_raylib_Material_from(
            lean_array_get_core(materials, i),
            RL_MALLOC(LEAN_RAYLIB_MAX_MATERIAL_MAPS * sizeof(MaterialMap))
        );
    }
    lmodel.model.boneCount = lean_array_size(bones);
    lmodel.model.bones = RL_MALLOC(lmodel.model.boneCount * sizeof(BoneInfo));
    lmodel.model.bindPose = RL_MALLOC(lmodel.model.boneCount * sizeof(Transform));
    for (size_t i = 0; i < lmodel.model.boneCount; ++i) {
        lmodel.model.bones[i] = lean_raylib_BoneInfo_from(
            lean_array_get_core(bones, i)
        );
        lmodel.model.bindPose[i] = lean_raylib_Transform_from(
            lean_array_get_core(bindPose, i)
        );
    }
    return lean_raylib_Model_to(lmodel);
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_transform(b_lean_obj_arg model) {
    return lean_raylib_Matrix_to(lean_raylib_Model_from(model)->model.transform);
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_setTransform(b_lean_obj_arg matrix, lean_obj_arg model) {
    Matrix matrixVal = lean_raylib_Matrix_from(matrix);
    if (LEAN_LIKELY(lean_is_exclusive(model))) {
        lean_raylib_Model_from(model)->model.transform = matrixVal;
        return model;
    }
    else {
        lean_raylib_Model modelCopy = lean_raylib_Model_clone(lean_raylib_Model_from(model));
        modelCopy.model.transform = matrixVal;
        lean_dec_ref(model);
        return lean_raylib_Model_to(modelCopy);
    }
}

LEAN_EXPORT uint32_t lean_raylib__Model_meshCount(b_lean_obj_arg model) {
    return lean_raylib_Model_from(model)->model.meshCount;
}

LEAN_EXPORT uint32_t lean_raylib__Model_materialCount(b_lean_obj_arg model) {
    return lean_raylib_Model_from(model)->model.materialCount;
}

LEAN_EXPORT uint32_t lean_raylib__Model_boneCount(b_lean_obj_arg model) {
    return lean_raylib_Model_from(model)->model.boneCount;
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_bone(b_lean_obj_arg model, uint32_t i) {
    return lean_raylib_BoneInfo_to(lean_raylib_Model_from(model)->model.bones[i]);
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_bindPose(b_lean_obj_arg model, uint32_t i) {
    return lean_raylib_Transform_to(lean_raylib_Model_from(model)->model.bindPose[i]);
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_material(b_lean_obj_arg model, uint32_t i) {
    lean_object* mat = lean_array_get_core(lean_raylib_Model_from(model)->materials, i);
    lean_inc_ref(mat);
    return mat;
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_setMaterial(lean_obj_arg model, uint32_t i, lean_obj_arg mat) {
    if(LEAN_LIKELY(lean_is_exclusive(model))) {
        lean_raylib_Model* modelC = lean_raylib_Model_from(model);
        modelC->materials = lean_array_uset(modelC->materials, i, mat);
        modelC->model.materials[i] = lean_raylib_Material_from(mat, modelC->model.materials[i].maps);
        return model;
    }
    else {
        lean_raylib_Model modelCopy = lean_raylib_Model_clone(lean_raylib_Model_from(model));
        modelCopy.materials = lean_array_uset(modelCopy.materials, i, mat);
        modelCopy.model.materials[i] = lean_raylib_Material_from(mat, modelCopy.model.materials[i].maps);
        lean_dec_ref(model);
        return lean_raylib_Model_to(modelCopy);
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_addMaterial(lean_obj_arg model, lean_obj_arg mat) {
    if(LEAN_UNLIKELY(!lean_is_exclusive(model))) {
        lean_raylib_Model modelCopy = lean_raylib_Model_clone(lean_raylib_Model_from(model));
        lean_dec_ref(model);
        model = lean_raylib_Model_to(modelCopy);
    }
    lean_raylib_Model* modelC = lean_raylib_Model_from(model);
    modelC->materials = lean_array_push(modelC->materials, mat);
    if (modelC->model.materialCount >= modelC->materialsCapacity) {
        Material* mats = RL_MALLOC(modelC->materialsCapacity * 2 * sizeof(Material));
        memcpy(mats, modelC->model.materials, modelC->model.materialCount * sizeof(Material));
        RL_FREE(modelC->model.materials);
        modelC->model.materials = mats;
    }
    MaterialMap* newMmaps = RL_MALLOC(LEAN_RAYLIB_MAX_MATERIAL_MAPS * sizeof(MaterialMap));
    modelC->model.materials[modelC->model.materialCount] = lean_raylib_Material_from(mat, newMmaps);
    modelC->model.materialCount += 1;
    return model;
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_removeMaterial(lean_obj_arg model, uint32_t i) {
    if(LEAN_UNLIKELY(!lean_is_exclusive(model))) {
        lean_raylib_Model modelCopy = lean_raylib_Model_clone(lean_raylib_Model_from(model));
        lean_dec_ref(model);
        model = lean_raylib_Model_to(modelCopy);
    }
    lean_raylib_Model* modelC = lean_raylib_Model_from(model);
    for (size_t j = 0; j < modelC->model.meshCount; ++j) {
        if (modelC->model.meshMaterial[j] == i) {
            modelC->model.meshMaterial[j] = 0;
        }
    }
    modelC->materials = lean_ensure_exclusive_array(modelC->materials);
    modelC->model.materialCount -= 1;
    lean_dec_ref(lean_array_get_core(modelC->materials, i));
    RL_FREE(modelC->model.materials[i].maps);
    for (size_t j = i; j < modelC->model.materialCount; ++j) {
        lean_array_set_core(modelC->materials, j, lean_array_get_core(modelC->materials, j + 1));
        modelC->model.materials[j] = modelC->model.materials[j + 1];
    }
    return model;
}

LEAN_EXPORT uint32_t lean_raylib__Model_meshMaterial(b_lean_obj_arg model, uint32_t i) {
    return lean_raylib_Model_from(model)->model.meshMaterial[i];
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_setMeshMaterial(lean_obj_arg model, uint32_t i, uint32_t j) {
    if(LEAN_LIKELY(lean_is_exclusive(model))) {
        lean_raylib_Model* modelC = lean_raylib_Model_from(model);
        modelC->model.meshMaterial[i] = j;
        return model;
    }
    else {
        lean_raylib_Model modelCopy = lean_raylib_Model_clone(lean_raylib_Model_from(model));
        modelCopy.model.meshMaterial[i] = j;
        lean_dec_ref(model);
        return lean_raylib_Model_to(modelCopy);
    }
}


// # ModelAnimation

// LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_mk(uint32_t boneCount, uint32_t frameCount, /* BoneInfo* */lean_obj_arg bones, /* Transform ** */lean_obj_arg framePoses) {
//     LET_BOX_STRUCT(ModelAnimation, result_,
//         .boneCount = boneCount,
//         .frameCount = frameCount,
//         .bones = /*todo: ptr?*/bones,
//         .framePoses = /*todo: ptr?*/framePoses
//     );
//     return lean_raylib_ModelAnimation_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ModelAnimation_boneCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_ModelAnimation_from(obj)->boneCount;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_boneCount_set(uint32_t boneCount, b_lean_obj_arg obj) {
//     LET_BOX(ModelAnimation, result_, *lean_raylib_ModelAnimation_from(obj));
//     result_->boneCount = boneCount;
//     return lean_raylib_ModelAnimation_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ModelAnimation_frameCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_ModelAnimation_from(obj)->frameCount;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_frameCount_set(uint32_t frameCount, b_lean_obj_arg obj) {
//     LET_BOX(ModelAnimation, result_, *lean_raylib_ModelAnimation_from(obj));
//     result_->frameCount = frameCount;
//     return lean_raylib_ModelAnimation_to(result_);
// }

// LEAN_EXPORT /* BoneInfo* */lean_obj_arg lean_raylib__ModelAnimation_bones(b_lean_obj_arg obj) {
//     BoneInfo * result_ = lean_raylib_ModelAnimation_from(obj)->bones;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_bones_set(/* BoneInfo* */lean_obj_arg bones, b_lean_obj_arg obj) {
//     LET_BOX(ModelAnimation, result_, *lean_raylib_ModelAnimation_from(obj));
//     result_->bones = /*todo: ptr?*/bones;
//     return lean_raylib_ModelAnimation_to(result_);
// }

// LEAN_EXPORT /* Transform ** */lean_obj_arg lean_raylib__ModelAnimation_framePoses(b_lean_obj_arg obj) {
//     Transform * * result_ = lean_raylib_ModelAnimation_from(obj)->framePoses;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_framePoses_set(/* Transform ** */lean_obj_arg framePoses, b_lean_obj_arg obj) {
//     LET_BOX(ModelAnimation, result_, *lean_raylib_ModelAnimation_from(obj));
//     result_->framePoses = /*todo: ptr?*/framePoses;
//     return lean_raylib_ModelAnimation_to(result_);
// }


// # Wave

LEAN_EXPORT uint32_t lean_raylib__Wave_frameCount(b_lean_obj_arg wave) {
    return lean_raylib_Wave_from(wave)->frameCount;
}

LEAN_EXPORT uint32_t lean_raylib__Wave_sampleRate(b_lean_obj_arg wave) {
    return lean_raylib_Wave_from(wave)->sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__Wave_sampleSize(b_lean_obj_arg wave) {
    return lean_raylib_Wave_from(wave)->sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__Wave_channels(b_lean_obj_arg wave) {
    return lean_raylib_Wave_from(wave)->channels;
}


// # Audio stream

LEAN_EXPORT uint32_t lean_raylib__AudioStream_sampleRate(b_lean_obj_arg audioStream) {
    return lean_raylib_AudioStream_from(audioStream)->stream.sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__AudioStream_sampleSize(b_lean_obj_arg audioStream) {
    return lean_raylib_AudioStream_from(audioStream)->stream.sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__AudioStream_channels(b_lean_obj_arg audioStream) {
    return lean_raylib_AudioStream_from(audioStream)->stream.channels;
}


// # Sound

LEAN_EXPORT uint32_t lean_raylib__Sound_sampleRate(b_lean_obj_arg sound) {
    return lean_raylib_Sound_from(sound)->stream.sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__Sound_sampleSize(b_lean_obj_arg sound) {
    return lean_raylib_Sound_from(sound)->stream.sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__Sound_channels(b_lean_obj_arg sound) {
    return lean_raylib_Sound_from(sound)->stream.channels;
}

LEAN_EXPORT uint32_t lean_raylib__Sound_frameCount(b_lean_obj_arg sound) {
    return lean_raylib_Sound_from(sound)->frameCount;
}


// # Music

LEAN_EXPORT uint32_t lean_raylib__Music_sampleRate(b_lean_obj_arg music) {
    return lean_raylib_Music_from(music)->stream.sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__Music_sampleSize(b_lean_obj_arg music) {
    return lean_raylib_Music_from(music)->stream.sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__Music_chanels(b_lean_obj_arg music) {
    return lean_raylib_Music_from(music)->stream.channels;
}

LEAN_EXPORT uint32_t lean_raylib__Music_frameCount(b_lean_obj_arg music) {
    return lean_raylib_Music_from(music)->frameCount;
}

LEAN_EXPORT uint8_t lean_raylib__Music_looping(b_lean_obj_arg music) {
    return lean_raylib_Music_from(music)->looping;
}

LEAN_EXPORT lean_obj_res lean_raylib__Music_looping_set(uint8_t looping, lean_obj_arg music) {
    if(LEAN_LIKELY(lean_is_exclusive(music))) {
        lean_raylib_Music_from(music)->looping = looping;
        return music;
    }
    LET_BOX(Music, music_new, *lean_raylib_Music_from(music));
    lean_dec_ref(music);
    music_new->looping = looping;
    return lean_raylib_Music_to(music_new);
}
