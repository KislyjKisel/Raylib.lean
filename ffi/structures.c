#include <memory.h>
#include <lean/lean.h>
#include <lean_pod.h>
#include <raylib.h>
#include <rlgl.h>
#include "include/raylib_lean.h"

LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Context)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Image)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_TextureRef)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Texture)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_RenderTexture)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Font)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Mesh)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Shader)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Model)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_ModelAnimation)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Wave)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Sound)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_Music)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_AudioStream)
LEAN_POD_DEFINE_EXTERNAL_CLASS(raylib_AutomationEventList)

lean_object* lean_raylib_Image_empty;
lean_object* lean_raylib_Texture_empty;

static void lean_raylib_Context_finalize(void* ctx_v) {
    lean_raylib_Context_data* ctx = ctx_v;
    CloseWindow();
    RL_FREE(ctx->title);
}

static void lean_raylib_Image_finalize(void* image) {
    UnloadImage(*(Image*)image);
    lean_raylib_free(image);
}

static void lean_raylib_TextureRef_foreach(void* textureRef, b_lean_obj_arg f) {
    lean_object* owner = ((lean_raylib_TextureRef_data*)textureRef)->owner;
    lean_inc_ref(f);
    lean_inc(owner);
    lean_apply_1(f, owner);
}

static void lean_raylib_TextureRef_finalize(void* textureRef) {
    lean_dec(((lean_raylib_TextureRef_data*)textureRef)->owner);
    lean_raylib_free(textureRef);
}

static void lean_raylib_Texture_finalize(void* texture_v) {
    lean_raylib_Texture_data* texture = texture_v;
    if(texture->texture.id != rlGetTextureIdDefault()) { // todo: test if needed
        UnloadTexture(texture->texture);
    }
    if (texture->ctx != NULL) {
        lean_dec_ref(texture->ctx);
    }
    lean_raylib_free(texture);
}

static void lean_raylib_Texture_foreach(void* texture_v, b_lean_obj_arg f) {
    lean_raylib_Texture_data* texture = texture_v;
    if (texture->ctx != NULL) {
        lean_inc_ref(f);
        lean_inc_ref(texture->ctx);
        lean_apply_1(f, texture->ctx);
    }
}

static void lean_raylib_RenderTexture_finalize(void* texture_v) {
    lean_raylib_RenderTexture_data* texture = texture_v;
    UnloadRenderTexture(texture->texture);
    lean_dec_ref(texture->ctx);
    lean_raylib_free(texture);
}

static void lean_raylib_RenderTexture_foreach(void* texture_v, b_lean_obj_arg f) {
    lean_raylib_RenderTexture_data* texture = texture_v;
    lean_inc_ref(f);
    lean_inc_ref(texture->ctx);
    lean_apply_1(f, texture->ctx);
}

static void lean_raylib_Font_finalize(void* font_v) {
    lean_raylib_Font_data* font = font_v;
    UnloadFont(font->font);
    lean_dec_ref(font->ctx);
    lean_raylib_free(font);
}

static void lean_raylib_Font_foreach(void* font_v, b_lean_obj_arg f) {
    lean_raylib_Font_data* font = font_v;
    lean_inc_ref(f);
    lean_inc_ref(font->ctx);
    lean_apply_1(f, font->ctx);
}

static void lean_raylib_Mesh_finalize(void* mesh_v) {
    lean_raylib_Mesh_data* mesh = mesh_v;
    UnloadMesh(mesh->mesh);
    lean_dec_ref(mesh->ctx);
    lean_raylib_free(mesh);
}

static void lean_raylib_Mesh_foreach(void* mesh_v, b_lean_obj_arg f) {
    lean_raylib_Mesh_data* mesh = mesh_v;
    lean_inc_ref(f);
    lean_inc_ref(mesh->ctx);
    lean_apply_1(f, mesh->ctx);
}

static void lean_raylib_Shader_finalize(void* shader_v) {
    lean_raylib_Shader_data* shader = shader_v;
    UnloadShader(shader->shader);
    lean_dec_ref(shader->ctx);
    lean_raylib_free(shader);
}

static void lean_raylib_Shader_foreach(void* shader_v, b_lean_obj_arg f) {
    lean_raylib_Shader_data* shader = shader_v;
    lean_inc_ref(f);
    lean_inc_ref(shader->ctx);
    lean_apply_1(f, shader->ctx);
}

static void lean_raylib_Model_finalize(void* model_v) {
    lean_raylib_Model_data* model = model_v;
    lean_dec_ref(model->meshes);
    lean_dec_ref(model->materials);
    for (size_t i = 0; i < model->model.materialCount; ++i) {
        RL_FREE(model->model.materials[i].maps);
    }
    RL_FREE(model->model.meshes);
    RL_FREE(model->model.materials);
    RL_FREE(model->model.meshMaterial);
    RL_FREE(model->model.bones);
    RL_FREE(model->model.bindPose);
    lean_raylib_free(model_v);
}

static void lean_raylib_Model_foreach(void* model_v, b_lean_obj_arg f) {
    lean_raylib_Model_data* model = model_v;
    lean_inc_ref_n(f, 2);
    lean_inc_ref(model->meshes);
    lean_inc_ref(model->materials);
    lean_apply_1(f, model->meshes);
    lean_apply_1(f, model->materials);
}

static void lean_raylib_ModelAnimation_finalize(void* anim_v) {
    UnloadModelAnimation(*(ModelAnimation*)anim_v);
    lean_raylib_free(anim_v);
}

static void lean_raylib_Wave_finalize(void* wave) {
    UnloadWave(*(Wave*)wave);
    lean_raylib_free(wave);
}

static void lean_raylib_AudioStream_finalize(void* audioStream_v) {
    lean_raylib_AudioStream_data* audioStream = audioStream_v;
    UnloadAudioStream(audioStream->stream);
#ifdef LEAN_RAYLIB_FORK
    lean_dec_ref(audioStream->callback);
#endif
    lean_dec_ref(audioStream->ctx);
    lean_raylib_free(audioStream);
}

static void lean_raylib_AudioStream_foreach(void* audioStream_v, b_lean_obj_arg f) {
    lean_raylib_AudioStream_data* audioStream = audioStream_v;
    lean_inc_ref(f);
    lean_inc_ref(audioStream->ctx);
    lean_apply_1(f, audioStream->ctx);
#ifdef LEAN_RAYLIB_FORK
    if (audioStream->callback != NULL) {
        lean_inc_ref(f);
        lean_inc_ref(audioStream->callback);
        lean_apply_1(f, audioStream->callback);
    }
#endif
}

static void lean_raylib_Sound_finalize(void* sound_v) {
    lean_raylib_Sound_data* sound = sound_v;
    UnloadSound(sound->sound);
    lean_dec_ref(sound->ctx);
    lean_raylib_free(sound);
}

static void lean_raylib_Sound_foreach(void* sound_v, b_lean_obj_arg f) {
    lean_raylib_Sound_data* sound = sound_v;
    lean_inc_ref(f);
    lean_inc_ref(sound->ctx);
    lean_apply_1(f, sound->ctx);
}

static void lean_raylib_Music_finalize(void* music_v) {
    lean_raylib_Music_data* music = music_v;
    UnloadMusicStream(music->music);
    lean_dec_ref(music->ctx);
    lean_raylib_free(music);
}

static void lean_raylib_Music_foreach(void* music_v, b_lean_obj_arg f) {
    lean_raylib_Music_data* music = music_v;
    lean_inc_ref(f);
    lean_inc_ref(music->ctx);
    lean_apply_1(f, music->ctx);
}

static void lean_raylib_AutomationEventList_finalize(void* automationEventList) {
    UnloadAutomationEventList(*(AutomationEventList*)automationEventList);
    lean_raylib_free(automationEventList);
}

LEAN_EXPORT lean_obj_res lean_raylib_initialize_Structures(lean_obj_arg world) {
    lean_raylib_Context_class = lean_register_external_class(
        lean_raylib_Context_finalize,
        lean_pod_default_foreach
    );
    {
        lean_raylib_Image_class = lean_register_external_class(
            lean_raylib_Image_finalize,
            lean_pod_default_foreach
        );
        LEAN_RAYLIB_ALLOC_INIT(Image, emptyImage,
            .data = NULL,
            .width = 0,
            .height = 0,
            .mipmaps = 1,
            .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
        );
        lean_raylib_Image_empty = lean_raylib_Image_box(emptyImage);
        lean_mark_persistent(lean_raylib_Image_empty);
    }
    {
        lean_raylib_TextureRef_class = lean_register_external_class(
            lean_raylib_TextureRef_finalize,
            lean_raylib_TextureRef_foreach
        );
        lean_raylib_Texture_class = lean_register_external_class(
            lean_raylib_Texture_finalize,
            lean_raylib_Texture_foreach
        );
        lean_raylib_Texture_empty = lean_raylib_Texture_box((Texture) {0}, NULL);
        lean_mark_persistent(lean_raylib_Texture_empty);
    }
    lean_raylib_RenderTexture_class = lean_register_external_class(
        lean_raylib_RenderTexture_finalize,
        lean_raylib_RenderTexture_foreach
    );
    lean_raylib_Font_class = lean_register_external_class(
        lean_raylib_Font_finalize,
        lean_raylib_Font_foreach
    );
    lean_raylib_Mesh_class = lean_register_external_class(
        lean_raylib_Mesh_finalize,
        lean_raylib_Mesh_foreach
    );
    lean_raylib_Shader_class = lean_register_external_class(
        lean_raylib_Shader_finalize,
        lean_raylib_Shader_foreach
    );
    lean_raylib_Model_class = lean_register_external_class(
        lean_raylib_Model_finalize,
        lean_raylib_Model_foreach
    );
    lean_raylib_ModelAnimation_class = lean_register_external_class(
        lean_raylib_ModelAnimation_finalize,
        lean_pod_default_foreach
    );
    lean_raylib_Wave_class = lean_register_external_class(
        lean_raylib_Wave_finalize,
        lean_pod_default_foreach
    );
    lean_raylib_AudioStream_class = lean_register_external_class(
        lean_raylib_AudioStream_finalize,
        lean_raylib_AudioStream_foreach
    );
    lean_raylib_Sound_class = lean_register_external_class(
        lean_raylib_Sound_finalize,
        lean_raylib_Sound_foreach
    );
    lean_raylib_Music_class = lean_register_external_class(
        lean_raylib_Music_finalize,
        lean_raylib_Music_foreach
    );
    lean_raylib_AutomationEventList_class = lean_register_external_class(
        lean_raylib_AutomationEventList_finalize,
        lean_pod_default_foreach
    );
    return lean_io_result_mk_ok(lean_box(0));
}

// # VaList

LEAN_EXPORT lean_obj_res lean_raylib__VaList_next(b_lean_obj_arg vl, uint8_t typ, lean_obj_arg token) {
    lean_object* value;
    switch(typ) {
        case 0:
            value = lean_pod_Int32_box(va_arg(lean_raylib_VaList_fromRepr(vl)->v, int32_t));
            break;
        case 1:
            value = lean_box_uint32(va_arg(lean_raylib_VaList_fromRepr(vl)->v, uint32_t));
            break;
        case 2:
            value = lean_box_uint64(va_arg(lean_raylib_VaList_fromRepr(vl)->v, uint64_t));
            break;
        case 3:
            value = lean_box_float(va_arg(lean_raylib_VaList_fromRepr(vl)->v, double));
            break;
        case 4:
            value = lean_mk_string(va_arg(lean_raylib_VaList_fromRepr(vl)->v, const char*));
            break;
        default:
            lean_internal_panic_unreachable();
    }
    return lean_io_result_mk_ok(value);
}


// # Image

LEAN_EXPORT uint32_t lean_raylib__Image_width(b_lean_obj_arg obj) {
    return lean_raylib_Image_fromRepr(obj)->width;
}

LEAN_EXPORT uint32_t lean_raylib__Image_height(b_lean_obj_arg obj) {
    return lean_raylib_Image_fromRepr(obj)->height;
}

LEAN_EXPORT uint32_t lean_raylib__Image_mipmaps(b_lean_obj_arg obj) {
    return lean_raylib_Image_fromRepr(obj)->mipmaps;
}

LEAN_EXPORT uint32_t lean_raylib__Image_format(b_lean_obj_arg obj) {
    return lean_raylib_Image_fromRepr(obj)->format;
}

LEAN_EXPORT lean_obj_res lean_raylib__Image_getEmpty(lean_obj_arg unit) {
    return lean_raylib_Image_empty;
}


// # Texture

LEAN_EXPORT lean_obj_res lean_raylib__Texture_ref(lean_obj_arg texture) {
    return lean_raylib_TextureRef_box(
        lean_raylib_Texture_fromRepr(texture)->texture,
        texture
    );
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_id(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_fromRepr(obj)->texture.id;
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_width(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_fromRepr(obj)->texture.width;
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_height(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_fromRepr(obj)->texture.height;
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_mipmaps(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_fromRepr(obj)->texture.mipmaps;
}

LEAN_EXPORT uint32_t lean_raylib__TextureRef_format(b_lean_obj_arg obj) {
    return lean_raylib_TextureRef_fromRepr(obj)->texture.format;
}

LEAN_EXPORT lean_obj_res lean_raylib__Texture_getEmpty(lean_obj_arg unit) {
    return lean_raylib_Texture_empty;
}

LEAN_EXPORT lean_obj_res lean_raylib__Texture_getDefault(lean_obj_arg ctx) {
    return lean_raylib_Texture_toRepr(
        (Texture){
            .id = rlGetTextureIdDefault(),
            .width = 1,
            .height = 1,
            .mipmaps = 1,
            .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
        },
        ctx
    );
}


// # Render texture

LEAN_EXPORT uint32_t lean_raylib__RenderTexture_id(b_lean_obj_arg obj) {
    return lean_raylib_RenderTexture_fromRepr(obj)->texture.id;
}

LEAN_EXPORT lean_obj_res lean_raylib__RenderTexture_texture(lean_obj_arg rt_box) {
    return lean_raylib_TextureRef_box(
        lean_raylib_RenderTexture_fromRepr(rt_box)->texture.texture,
        rt_box
    );
}


// # Font

LEAN_EXPORT uint32_t lean_raylib__Font_baseSize(b_lean_obj_arg obj) {
    return lean_raylib_Font_fromRepr(obj)->font.baseSize;
}

LEAN_EXPORT uint32_t lean_raylib__Font_glyphCount(b_lean_obj_arg obj) {
    return lean_raylib_Font_fromRepr(obj)->font.glyphCount;
}

LEAN_EXPORT uint32_t lean_raylib__Font_glyphPadding(b_lean_obj_arg obj) {
    return lean_raylib_Font_fromRepr(obj)->font.glyphPadding;
}

LEAN_EXPORT lean_obj_res lean_raylib__Font_texture(lean_obj_arg obj) {
    return lean_raylib_TextureRef_box(lean_raylib_Font_fromRepr(obj)->font.texture, obj);
}

LEAN_EXPORT lean_obj_res lean_raylib__Font_recs(b_lean_obj_arg obj) {
    const Font* font = &lean_raylib_Font_fromRepr(obj)->font;
    lean_object* arr = lean_alloc_array(font->glyphCount, font->glyphCount);
    for(size_t i = 0; i < font->glyphCount; ++i) {
        lean_array_set_core(arr, i, lean_raylib_Rectangle_box(font->recs[i]));
    }
    return arr;
}


// # Mesh

LEAN_EXPORT lean_obj_res lean_raylib__Mesh_mkBv(
    lean_obj_arg ctx,
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
        lean_pod_BytesView_fromRepr(vertices)->ptr,
        sizeof(float[3]) * vertexCount
    );

    if(lean_option_is_some(texcoords)) {
        mesh.texcoords = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(texcoords, 0))->ptr,
            sizeof(float[2]) * vertexCount
        );
    }
    if(lean_option_is_some(texcoords2)) {
        mesh.texcoords2 = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(texcoords2, 0))->ptr,
            sizeof(float[2]) * vertexCount
        );
    }
    if(lean_option_is_some(normals)) {
        mesh.normals = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(normals, 0))->ptr,
            sizeof(float[3]) * vertexCount
        );
    }
    if(lean_option_is_some(tangents)) {
        mesh.tangents = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(tangents, 0))->ptr,
            sizeof(float[4]) * vertexCount
        );
    }
    if(lean_option_is_some(colors)) {
        mesh.colors = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(colors, 0))->ptr,
            sizeof(unsigned char[4]) * vertexCount
        );
    }
    if(lean_option_is_some(skinning) && mesh.normals != NULL) {
        lean_object* skinning_val = lean_ctor_get(skinning, 0);
        mesh.boneIds = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(skinning_val, 0))->ptr,
            sizeof(unsigned char[4]) * vertexCount
        );
        mesh.boneWeights = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(skinning_val, 1))->ptr,
            sizeof(float[4]) * vertexCount
        );
        uint32_t boneCount = lean_ctor_get_uint32(skinning_val, sizeof(lean_object*) * 3);
        mesh.boneCount = boneCount;
        mesh.boneMatrices = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(skinning_val, 2))->ptr,
            sizeof(float[16]) * boneCount
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
    return lean_raylib_Mesh_toRepr(mesh, ctx);
}


LEAN_EXPORT lean_obj_res lean_raylib__Mesh_mkIndexedBv(
    lean_obj_arg ctx,
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
    void* indices_c = lean_pod_BytesView_fromRepr(indices)->ptr;
    #ifndef NDEBUG
        for(size_t i = 0; i < 3 * triangleCount; ++i) {
            uint16_t index;
            memcpy(&index, indices_c + i * sizeof(uint16_t), sizeof(index));
            if(index >= vertexCount) {
                return lean_panic_fn(
                    lean_raylib_Mesh_box(mesh, ctx),
                    lean_mk_string("Mesh index out of bounds")
                );
            }
        }
    #endif
    mesh.vertexCount = vertexCount;
    mesh.triangleCount = triangleCount;

    mesh.vertices = lean_raylib_rlmemdup(
        lean_pod_BytesView_fromRepr(vertices)->ptr,
        sizeof(float[3]) * vertexCount
    );
    mesh.indices = lean_raylib_rlmemdup(
        indices_c,
        sizeof(uint16_t[3]) * triangleCount
    );
    if(lean_option_is_some(texcoords)) {
        mesh.texcoords = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(texcoords, 0))->ptr,
            sizeof(float[2]) * vertexCount
        );
    }
    if(lean_option_is_some(texcoords2)) {
        mesh.texcoords2 = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(texcoords2, 0))->ptr,
            sizeof(float[2]) * vertexCount
        );
    }
    if(lean_option_is_some(normals)) {
        mesh.normals = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(normals, 0))->ptr,
            sizeof(float[3]) * vertexCount
        );
    }
    if(lean_option_is_some(tangents)) {
        mesh.tangents = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(tangents, 0))->ptr,
            sizeof(float[4]) * vertexCount
        );
    }
    if(lean_option_is_some(colors)) {
        mesh.colors = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(colors, 0))->ptr,
            sizeof(unsigned char[4]) * vertexCount
        );
    }
    if(lean_option_is_some(skinning) && mesh.normals != NULL) {
        lean_object* skinning_val = lean_ctor_get(skinning, 0);
        mesh.boneIds = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(skinning_val, 0))->ptr,
            sizeof(unsigned char[4]) * vertexCount
        );
        mesh.boneWeights = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(skinning_val, 1))->ptr,
            sizeof(float[4]) * vertexCount
        );
        uint32_t boneCount = lean_ctor_get_uint32(skinning_val, sizeof(lean_object*) * 3);
        mesh.boneCount = boneCount;
        mesh.boneMatrices = lean_raylib_rlmemdup(
            lean_pod_BytesView_fromRepr(lean_ctor_get(skinning_val, 2))->ptr,
            sizeof(float[16]) * boneCount
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
    return lean_raylib_Mesh_toRepr(mesh, ctx);
}

LEAN_EXPORT uint32_t lean_raylib__Mesh_vertexCount(b_lean_obj_arg mesh) {
    return lean_raylib_Mesh_fromRepr(mesh)->mesh.vertexCount;
}

LEAN_EXPORT uint32_t lean_raylib__Mesh_triangleCount(b_lean_obj_arg mesh) {
    return lean_raylib_Mesh_fromRepr(mesh)->mesh.triangleCount;
}

LEAN_EXPORT uint32_t lean_raylib__Mesh_boneCount(b_lean_obj_arg mesh) {
    return lean_raylib_Mesh_fromRepr(mesh)->mesh.boneCount;
}

LEAN_EXPORT lean_obj_res lean_raylib__Mesh_vertices(lean_obj_arg mesh) {
    float* vertices = lean_raylib_Mesh_fromRepr(mesh)->mesh.vertices;
    return lean_pod_BytesView_toRepr((unsigned char*)vertices, mesh);
}

#define LEAN_RAYLIB_MESH_VIEW_OPT(id, ty)\
LEAN_EXPORT lean_obj_arg lean_raylib__Mesh_##id(b_lean_obj_arg mesh) {\
    ty * id = lean_raylib_Mesh_fromRepr(mesh)->mesh. id;\
    if(id == NULL) {\
        return lean_mk_option_none();\
    }\
    else {\
        return lean_mk_option_some(lean_pod_BytesView_box((unsigned char*)id, mesh));\
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
LEAN_RAYLIB_MESH_VIEW_OPT(boneMatrices, Matrix);

LEAN_EXPORT uint32_t lean_raylib__Mesh_vaoId(b_lean_obj_arg mesh) {
    return lean_raylib_Mesh_fromRepr(mesh)->mesh.vaoId;
}

LEAN_EXPORT uint32_t lean_raylib__Mesh_vboId(b_lean_obj_arg mesh, b_lean_obj_arg i) {
    return lean_raylib_Mesh_fromRepr(mesh)->mesh.vboId[lean_usize_of_nat(i)];
}


// # Shader

LEAN_EXPORT uint32_t lean_raylib__Shader_id(b_lean_obj_arg shader) {
    return lean_raylib_Shader_fromRepr(shader)->shader.id;
}

LEAN_EXPORT lean_obj_res lean_raylib__Shader_locs(b_lean_obj_arg shader) {
    int* locs_c = lean_raylib_Shader_fromRepr(shader)->shader.locs;
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
    int location = lean_raylib_Shader_fromRepr(shader)->shader.locs[index];
    if (location < 0) {
        return lean_mk_option_none();
    }
    else {
        return lean_mk_option_some(lean_box_uint32(location));
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__Shader_getDefault(lean_obj_arg ctx) {
    return lean_raylib_Shader_toRepr(
        (Shader) {
            .id = rlGetShaderIdDefault(),
            .locs = rlGetShaderLocsDefault()
        },
        ctx
    );
}


// # Model

LEAN_EXPORT lean_obj_res lean_raylib__Model_mk(
    b_lean_obj_arg transform, lean_obj_arg materials, lean_obj_arg meshes,
    b_lean_obj_arg bones, b_lean_obj_arg bindPose
) {
    lean_raylib_Model_data lmodel;
    lmodel.materials = materials;
    lmodel.meshes = meshes;
    lmodel.model.transform = lean_raylib_Matrix_fromRepr(transform);
    lmodel.meshesCapacity = lmodel.model.meshCount = lean_array_size(meshes);
    lmodel.materialsCapacity = lmodel.model.materialCount = lean_array_size(materials);
    lmodel.model.meshes = RL_MALLOC(lmodel.meshesCapacity * sizeof(Mesh));
    lmodel.model.meshMaterial = RL_MALLOC(lmodel.meshesCapacity * sizeof(int));
    for (size_t i = 0; i < lmodel.model.meshCount; ++i) {
        lean_object* meshXmatIdx = lean_array_get_core(meshes, i);
        lmodel.model.meshes[i] = lean_raylib_Mesh_fromRepr(lean_ctor_get(meshXmatIdx, 0))->mesh;
        lmodel.model.meshMaterial[i] = lean_usize_of_nat(lean_ctor_get(meshXmatIdx, 1));
    }
    lmodel.model.materials = RL_MALLOC(lmodel.materialsCapacity * sizeof(Material));
    for (size_t i = 0; i < lmodel.model.materialCount; ++i) {
        lmodel.model.materials[i] = lean_raylib_Material_fromRepr(
            lean_array_get_core(materials, i),
            RL_MALLOC(LEAN_RAYLIB_MAX_MATERIAL_MAPS * sizeof(MaterialMap))
        );
    }
    lmodel.model.boneCount = lean_array_size(bones);
    lmodel.model.bones = RL_MALLOC(lmodel.model.boneCount * sizeof(BoneInfo));
    lmodel.model.bindPose = RL_MALLOC(lmodel.model.boneCount * sizeof(Transform));
    for (size_t i = 0; i < lmodel.model.boneCount; ++i) {
        lmodel.model.bones[i] = lean_raylib_BoneInfo_fromRepr(
            lean_array_get_core(bones, i)
        );
        lmodel.model.bindPose[i] = lean_raylib_Transform_fromRepr(
            lean_array_get_core(bindPose, i)
        );
    }
    return lean_raylib_Model_toRepr(lmodel);
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_transform(b_lean_obj_arg model) {
    return lean_raylib_Matrix_toRepr(lean_raylib_Model_fromRepr(model)->model.transform);
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_setTransform(b_lean_obj_arg matrix, lean_obj_arg model) {
    Matrix matrixVal = lean_raylib_Matrix_fromRepr(matrix);
    if (LEAN_LIKELY(lean_is_exclusive(model))) {
        lean_raylib_Model_fromRepr(model)->model.transform = matrixVal;
        return model;
    }
    else {
        lean_raylib_Model_data modelCopy = lean_raylib_Model_clone(lean_raylib_Model_fromRepr(model));
        modelCopy.model.transform = matrixVal;
        lean_dec_ref(model);
        return lean_raylib_Model_toRepr(modelCopy);
    }
}

LEAN_EXPORT uint32_t lean_raylib__Model_meshCount(b_lean_obj_arg model) {
    return lean_raylib_Model_fromRepr(model)->model.meshCount;
}

LEAN_EXPORT uint32_t lean_raylib__Model_materialCount(b_lean_obj_arg model) {
    return lean_raylib_Model_fromRepr(model)->model.materialCount;
}

LEAN_EXPORT uint32_t lean_raylib__Model_boneCount(b_lean_obj_arg model) {
    return lean_raylib_Model_fromRepr(model)->model.boneCount;
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_bone(b_lean_obj_arg model, uint32_t i) {
    return lean_raylib_BoneInfo_toRepr(lean_raylib_Model_fromRepr(model)->model.bones[i]);
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_bindPose(b_lean_obj_arg model, uint32_t i) {
    return lean_raylib_Transform_toRepr(lean_raylib_Model_fromRepr(model)->model.bindPose[i]);
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_material(b_lean_obj_arg model, uint32_t i) {
    lean_object* mat = lean_array_get_core(lean_raylib_Model_fromRepr(model)->materials, i);
    lean_inc_ref(mat);
    return mat;
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_setMaterial(lean_obj_arg model, uint32_t i, lean_obj_arg mat) {
    if(LEAN_LIKELY(lean_is_exclusive(model))) {
        lean_raylib_Model_data* modelC = lean_raylib_Model_fromRepr(model);
        modelC->materials = lean_array_uset(modelC->materials, i, mat);
        modelC->model.materials[i] = lean_raylib_Material_fromRepr(mat, modelC->model.materials[i].maps);
        return model;
    }
    else {
        lean_raylib_Model_data modelCopy = lean_raylib_Model_clone(lean_raylib_Model_fromRepr(model));
        modelCopy.materials = lean_array_uset(modelCopy.materials, i, mat);
        modelCopy.model.materials[i] = lean_raylib_Material_fromRepr(mat, modelCopy.model.materials[i].maps);
        lean_dec_ref(model);
        return lean_raylib_Model_toRepr(modelCopy);
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_addMaterial(lean_obj_arg model, lean_obj_arg mat) {
    if(LEAN_UNLIKELY(!lean_is_exclusive(model))) {
        lean_raylib_Model_data modelCopy = lean_raylib_Model_clone(lean_raylib_Model_fromRepr(model));
        lean_dec_ref(model);
        model = lean_raylib_Model_box(modelCopy);
    }
    lean_raylib_Model_data* modelC = lean_raylib_Model_fromRepr(model);
    modelC->materials = lean_array_push(modelC->materials, mat);
    if (modelC->model.materialCount >= modelC->materialsCapacity) {
        Material* mats = RL_MALLOC(modelC->materialsCapacity * 2 * sizeof(Material));
        memcpy(mats, modelC->model.materials, modelC->model.materialCount * sizeof(Material));
        RL_FREE(modelC->model.materials);
        modelC->model.materials = mats;
    }
    MaterialMap* newMmaps = RL_MALLOC(LEAN_RAYLIB_MAX_MATERIAL_MAPS * sizeof(MaterialMap));
    modelC->model.materials[modelC->model.materialCount] = lean_raylib_Material_fromRepr(mat, newMmaps);
    modelC->model.materialCount += 1;
    return model;
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_removeMaterial(lean_obj_arg model, uint32_t i) {
    if(LEAN_UNLIKELY(!lean_is_exclusive(model))) {
        lean_raylib_Model_data modelCopy = lean_raylib_Model_clone(lean_raylib_Model_fromRepr(model));
        lean_dec_ref(model);
        model = lean_raylib_Model_box(modelCopy);
    }
    lean_raylib_Model_data* modelC = lean_raylib_Model_fromRepr(model);
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
    return lean_raylib_Model_fromRepr(model)->model.meshMaterial[i];
}

LEAN_EXPORT lean_obj_res lean_raylib__Model_setMeshMaterial(lean_obj_arg model, uint32_t i, uint32_t j) {
    if(LEAN_LIKELY(lean_is_exclusive(model))) {
        lean_raylib_Model_data* modelC = lean_raylib_Model_fromRepr(model);
        modelC->model.meshMaterial[i] = j;
        return model;
    }
    else {
        lean_raylib_Model_data modelCopy = lean_raylib_Model_clone(lean_raylib_Model_fromRepr(model));
        modelCopy.model.meshMaterial[i] = j;
        lean_dec_ref(model);
        return lean_raylib_Model_toRepr(modelCopy);
    }
}


// # ModelAnimation

LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_mk(b_lean_obj_arg bones, b_lean_obj_arg framePoses) {
    ModelAnimation anim;
    anim.boneCount = lean_array_size(bones);
    anim.frameCount = lean_array_size(framePoses);
    anim.bones = RL_MALLOC(anim.boneCount * sizeof(BoneInfo));
    for (size_t i = 0; i < anim.boneCount; ++i) {
        anim.bones[i] = lean_raylib_BoneInfo_unbox(lean_array_get_core(bones, i));
    }
    anim.framePoses = RL_MALLOC(anim.frameCount * sizeof(Transform*));
    for (size_t i = 0; i < anim.frameCount; ++i) {
        lean_object* framePose = lean_array_get_core(framePoses, i);
        anim.framePoses[i] = RL_MALLOC(anim.boneCount * sizeof(Transform));
        for (size_t j = 0; j < anim.boneCount; ++j) {
            anim.framePoses[i][j] = lean_raylib_Transform_unbox(lean_array_get_core(framePose, j));
        }
    }
    return lean_raylib_ModelAnimation_toRepr(anim);
}

LEAN_EXPORT uint32_t lean_raylib__ModelAnimation_boneCount(b_lean_obj_arg anim) {
    return lean_raylib_ModelAnimation_fromRepr(anim)->boneCount;
}

LEAN_EXPORT uint32_t lean_raylib__ModelAnimation_frameCount(b_lean_obj_arg anim) {
    return lean_raylib_ModelAnimation_fromRepr(anim)->frameCount;
}

LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_bone(b_lean_obj_arg anim, uint32_t i) {
    return lean_raylib_BoneInfo_toRepr(lean_raylib_ModelAnimation_fromRepr(anim)->bones[i]);
}

LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_setBone(lean_obj_arg anim, uint32_t i, b_lean_obj_arg bone) {
    anim = lean_raylib_ModelAnimation_ensure_exclusive(anim);
    lean_raylib_ModelAnimation_fromRepr(anim)->bones[i] = lean_raylib_BoneInfo_fromRepr(bone);
    return anim;
}

LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_framePose(b_lean_obj_arg obj, uint32_t i, uint32_t j) {
    return lean_raylib_Transform_toRepr(lean_raylib_ModelAnimation_fromRepr(obj)->framePoses[i][j]);
}

LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_setFramePose(
    lean_obj_arg anim, uint32_t i, uint32_t j, b_lean_obj_arg t
) {
    anim = lean_raylib_ModelAnimation_ensure_exclusive(anim);
    lean_raylib_ModelAnimation_fromRepr(anim)->framePoses[i][j] = lean_raylib_Transform_fromRepr(t);
    return anim;
}

LEAN_EXPORT lean_obj_res lean_raylib__ModelAnimation_name(b_lean_obj_arg anim) {
    return lean_mk_string(lean_raylib_ModelAnimation_fromRepr(anim)->name);
}


// # Wave

LEAN_EXPORT uint32_t lean_raylib__Wave_frameCount(b_lean_obj_arg wave) {
    return lean_raylib_Wave_fromRepr(wave)->frameCount;
}

LEAN_EXPORT uint32_t lean_raylib__Wave_sampleRate(b_lean_obj_arg wave) {
    return lean_raylib_Wave_fromRepr(wave)->sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__Wave_sampleSize(b_lean_obj_arg wave) {
    return lean_raylib_Wave_fromRepr(wave)->sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__Wave_channels(b_lean_obj_arg wave) {
    return lean_raylib_Wave_fromRepr(wave)->channels;
}


// # Audio stream

LEAN_EXPORT uint32_t lean_raylib__AudioStream_sampleRate(b_lean_obj_arg audioStream) {
    return lean_raylib_AudioStream_fromRepr(audioStream)->stream.sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__AudioStream_sampleSize(b_lean_obj_arg audioStream) {
    return lean_raylib_AudioStream_fromRepr(audioStream)->stream.sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__AudioStream_channels(b_lean_obj_arg audioStream) {
    return lean_raylib_AudioStream_fromRepr(audioStream)->stream.channels;
}


// # Sound

LEAN_EXPORT uint32_t lean_raylib__Sound_sampleRate(b_lean_obj_arg sound) {
    return lean_raylib_Sound_fromRepr(sound)->sound.stream.sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__Sound_sampleSize(b_lean_obj_arg sound) {
    return lean_raylib_Sound_fromRepr(sound)->sound.stream.sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__Sound_channels(b_lean_obj_arg sound) {
    return lean_raylib_Sound_fromRepr(sound)->sound.stream.channels;
}

LEAN_EXPORT uint32_t lean_raylib__Sound_frameCount(b_lean_obj_arg sound) {
    return lean_raylib_Sound_fromRepr(sound)->sound.frameCount;
}


// # Music

LEAN_EXPORT uint32_t lean_raylib__Music_sampleRate(b_lean_obj_arg music) {
    return lean_raylib_Music_fromRepr(music)->music.stream.sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__Music_sampleSize(b_lean_obj_arg music) {
    return lean_raylib_Music_fromRepr(music)->music.stream.sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__Music_channels(b_lean_obj_arg music) {
    return lean_raylib_Music_fromRepr(music)->music.stream.channels;
}

LEAN_EXPORT uint32_t lean_raylib__Music_frameCount(b_lean_obj_arg music) {
    return lean_raylib_Music_fromRepr(music)->music.frameCount;
}

LEAN_EXPORT lean_obj_res lean_raylib__Music_looping(b_lean_obj_arg music, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(lean_raylib_Music_fromRepr(music)->music.looping));
}

LEAN_EXPORT lean_obj_res lean_raylib__Music_looping_set(uint8_t looping, b_lean_obj_arg music, lean_obj_arg world) {
    lean_raylib_Music_fromRepr(music)->music.looping = looping;
    return lean_io_result_mk_ok(lean_box(0));
}


// # Automation event list

LEAN_EXPORT uint32_t lean_raylib__AutomationEventList_capacity(b_lean_obj_arg automationEventList) {
    return lean_raylib_AutomationEventList_fromRepr(automationEventList)->capacity;
}

LEAN_EXPORT lean_obj_res lean_raylib__AutomationEventList_count(b_lean_obj_arg automationEventList, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(
        lean_raylib_AutomationEventList_fromRepr(automationEventList)->count
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__AutomationEventList_setCount(b_lean_obj_arg automationEventList, uint32_t newCount, lean_obj_arg world) {
    AutomationEventList* list = lean_raylib_AutomationEventList_fromRepr(automationEventList);
    list->count = newCount <= list->capacity ? newCount : list->capacity;
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__AutomationEventList_get(b_lean_obj_arg automationEventList, uint32_t index, lean_obj_arg world) {
    AutomationEventList* list = lean_raylib_AutomationEventList_fromRepr(automationEventList);
    return lean_io_result_mk_ok(lean_raylib_AutomationEvent_box(list->events[index]));
}

LEAN_EXPORT lean_obj_res lean_raylib__AutomationEventList_set(b_lean_obj_arg automationEventList, uint32_t index, b_lean_obj_arg event, lean_obj_arg world) {
    AutomationEventList* list = lean_raylib_AutomationEventList_fromRepr(automationEventList);
    list->events[index] = lean_raylib_AutomationEvent_fromRepr(event);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__AutomationEventList_withCapacity(uint32_t capacity) {
    AutomationEventList list;
    list.capacity = capacity;
    list.count = 0;
    list.events = RL_MALLOC(capacity * sizeof(AutomationEvent));
    return lean_raylib_AutomationEventList_toRepr(list);
}
