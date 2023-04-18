#include <memory.h>
#include "util.h"
#include <rlgl.h>
#include "structures.h"

// # Image

LEAN_EXPORT lean_obj_res lean_raylib__Image_default(lean_obj_arg unit) {
    LET_BOX_STRUCT(Image, image,
        .data = NULL,
        .width = 0,
        .height = 0,
        .mipmaps = 1,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
    );
    return lean_raylib_Image_to(image);
}

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

LEAN_EXPORT lean_obj_res lean_raylib__Texture_default() {
    LET_BOX(Texture, texture, (Texture){0});
    return lean_raylib_Texture_to(texture);
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

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_mk(uint32_t vertexCount, uint32_t triangleCount, /* float* */lean_obj_arg vertices, /* float* */lean_obj_arg texcoords, /* float* */lean_obj_arg texcoords2, /* float* */lean_obj_arg normals, /* float* */lean_obj_arg tangents, /* unsigned char* */lean_obj_arg colors, /* unsigned short* */lean_obj_arg indices, /* float* */lean_obj_arg animVertices, /* float* */lean_obj_arg animNormals, /* unsigned char* */lean_obj_arg boneIds, /* float* */lean_obj_arg boneWeights, uint32_t vaoId, /* unsigned int* */lean_obj_arg vboId) {
//     LET_BOX_STRUCT(Mesh, result_,
//         .vertexCount = vertexCount,
//         .triangleCount = triangleCount,
//         .vertices = /*todo: ptr?*/vertices,
//         .texcoords = /*todo: ptr?*/texcoords,
//         .texcoords2 = /*todo: ptr?*/texcoords2,
//         .normals = /*todo: ptr?*/normals,
//         .tangents = /*todo: ptr?*/tangents,
//         .colors = /*todo: ptr?*/colors,
//         .indices = /*todo: ptr?*/indices,
//         .animVertices = /*todo: ptr?*/animVertices,
//         .animNormals = /*todo: ptr?*/animNormals,
//         .boneIds = /*todo: ptr?*/boneIds,
//         .boneWeights = /*todo: ptr?*/boneWeights,
//         .vaoId = vaoId,
//         .vboId = /*todo: ptr?*/vboId
//     );
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Mesh_vertexCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Mesh_from(obj)->vertexCount;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_vertexCount_set(uint32_t vertexCount, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->vertexCount = vertexCount;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Mesh_triangleCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Mesh_from(obj)->triangleCount;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_triangleCount_set(uint32_t triangleCount, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->triangleCount = triangleCount;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_vertices(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->vertices;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_vertices_set(/* float* */lean_obj_arg vertices, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->vertices = /*todo: ptr?*/vertices;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_texcoords(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->texcoords;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_texcoords_set(/* float* */lean_obj_arg texcoords, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->texcoords = /*todo: ptr?*/texcoords;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_texcoords2(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->texcoords2;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_texcoords2_set(/* float* */lean_obj_arg texcoords2, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->texcoords2 = /*todo: ptr?*/texcoords2;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_normals(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->normals;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_normals_set(/* float* */lean_obj_arg normals, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->normals = /*todo: ptr?*/normals;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_tangents(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->tangents;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_tangents_set(/* float* */lean_obj_arg tangents, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->tangents = /*todo: ptr?*/tangents;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* unsigned char* */lean_obj_arg lean_raylib__Mesh_colors(b_lean_obj_arg obj) {
//     unsigned char * result_ = lean_raylib_Mesh_from(obj)->colors;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_colors_set(/* unsigned char* */lean_obj_arg colors, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->colors = /*todo: ptr?*/colors;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* unsigned short* */lean_obj_arg lean_raylib__Mesh_indices(b_lean_obj_arg obj) {
//     unsigned short * result_ = lean_raylib_Mesh_from(obj)->indices;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_indices_set(/* unsigned short* */lean_obj_arg indices, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->indices = /*todo: ptr?*/indices;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_animVertices(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->animVertices;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_animVertices_set(/* float* */lean_obj_arg animVertices, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->animVertices = /*todo: ptr?*/animVertices;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_animNormals(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->animNormals;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_animNormals_set(/* float* */lean_obj_arg animNormals, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->animNormals = /*todo: ptr?*/animNormals;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* unsigned char* */lean_obj_arg lean_raylib__Mesh_boneIds(b_lean_obj_arg obj) {
//     unsigned char * result_ = lean_raylib_Mesh_from(obj)->boneIds;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_boneIds_set(/* unsigned char* */lean_obj_arg boneIds, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->boneIds = /*todo: ptr?*/boneIds;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_boneWeights(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->boneWeights;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_boneWeights_set(/* float* */lean_obj_arg boneWeights, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->boneWeights = /*todo: ptr?*/boneWeights;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Mesh_vaoId(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Mesh_from(obj)->vaoId;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_vaoId_set(uint32_t vaoId, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->vaoId = vaoId;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* unsigned int* */lean_obj_arg lean_raylib__Mesh_vboId(b_lean_obj_arg obj) {
//     unsigned int * result_ = lean_raylib_Mesh_from(obj)->vboId;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Mesh_vboId_set(/* unsigned int* */lean_obj_arg vboId, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->vboId = /*todo: ptr?*/vboId;
//     return lean_raylib_Mesh_to(result_);
// }


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


// # Material map

// LEAN_EXPORT lean_obj_res lean_raylib__MaterialMap_mk(lean_obj_arg texture, uint32_t color, uint32_t value) {
//     LET_BOX_STRUCT(MaterialMap, result_,
//         .texture = /*cast Texture2D to_lean?false*/(texture),
//         .color = lean_raylib_Color_from(color),
//         .value = lean_pod_Float32_fromBits(value)
//     );
//     return lean_raylib_MaterialMap_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__MaterialMap_texture(b_lean_obj_arg obj) {
//     Texture2D result_ = lean_raylib_MaterialMap_from(obj)->texture;
//     return /*cast Texture2D to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MaterialMap_texture_set(lean_obj_arg texture, b_lean_obj_arg obj) {
//     LET_BOX(MaterialMap, result_, *lean_raylib_MaterialMap_from(obj));
//     result_->texture = /*cast Texture2D to_lean?false*/(texture);
//     return lean_raylib_MaterialMap_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__MaterialMap_color(b_lean_obj_arg obj) {
//     Color result_ = lean_raylib_MaterialMap_from(obj)->color;
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MaterialMap_color_set(uint32_t color, b_lean_obj_arg obj) {
//     LET_BOX(MaterialMap, result_, *lean_raylib_MaterialMap_from(obj));
//     result_->color = lean_raylib_Color_from(color);
//     return lean_raylib_MaterialMap_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__MaterialMap_value(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_MaterialMap_from(obj)->value;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MaterialMap_value_set(uint32_t value, b_lean_obj_arg obj) {
//     LET_BOX(MaterialMap, result_, *lean_raylib_MaterialMap_from(obj));
//     result_->value = lean_pod_Float32_fromBits(value);
//     return lean_raylib_MaterialMap_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Material_mk(lean_obj_arg shader, /* MaterialMap* */lean_obj_arg maps, /*float[4]*/lean_obj_arg params) {
//     LET_BOX_STRUCT(Material, result_,
//         .shader = lean_raylib_Shader_from(shader),
//         .maps = /*todo: ptr?*/maps,
//         .params = /*cast float[4] to_lean?false*/(params)
//     );
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Material_shader(b_lean_obj_arg obj) {
//     Shader result_ = lean_raylib_Material_from(obj)->shader;
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Material_shader_set(lean_obj_arg shader, b_lean_obj_arg obj) {
//     LET_BOX(Material, result_, *lean_raylib_Material_from(obj));
//     result_->shader = lean_raylib_Shader_from(shader);
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT /* MaterialMap* */lean_obj_arg lean_raylib__Material_maps(b_lean_obj_arg obj) {
//     MaterialMap * result_ = lean_raylib_Material_from(obj)->maps;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Material_maps_set(/* MaterialMap* */lean_obj_arg maps, b_lean_obj_arg obj) {
//     LET_BOX(Material, result_, *lean_raylib_Material_from(obj));
//     result_->maps = /*todo: ptr?*/maps;
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT /*float[4]*/lean_obj_arg lean_raylib__Material_params(b_lean_obj_arg obj) {
//     float[4] result_ = lean_raylib_Material_from(obj)->params;
//     return /*cast float[4] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Material_params_set(/*float[4]*/lean_obj_arg params, b_lean_obj_arg obj) {
//     LET_BOX(Material, result_, *lean_raylib_Material_from(obj));
//     result_->params = /*cast float[4] to_lean?false*/(params);
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Transform_mk(lean_obj_arg translation, lean_obj_arg rotation, lean_obj_arg scale) {
//     LET_BOX_STRUCT(Transform, result_,
//         .translation = lean_raylib_Vector3_from(translation),
//         .rotation = /*cast Quaternion to_lean?false*/(rotation),
//         .scale = lean_raylib_Vector3_from(scale)
//     );
//     return lean_raylib_Transform_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Transform_translation(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_Transform_from(obj)->translation;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Transform_translation_set(lean_obj_arg translation, b_lean_obj_arg obj) {
//     LET_BOX(Transform, result_, *lean_raylib_Transform_from(obj));
//     result_->translation = lean_raylib_Vector3_from(translation);
//     return lean_raylib_Transform_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Transform_rotation(b_lean_obj_arg obj) {
//     Quaternion result_ = lean_raylib_Transform_from(obj)->rotation;
//     return /*cast Quaternion to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Transform_rotation_set(lean_obj_arg rotation, b_lean_obj_arg obj) {
//     LET_BOX(Transform, result_, *lean_raylib_Transform_from(obj));
//     result_->rotation = /*cast Quaternion to_lean?false*/(rotation);
//     return lean_raylib_Transform_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Transform_scale(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_Transform_from(obj)->scale;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Transform_scale_set(lean_obj_arg scale, b_lean_obj_arg obj) {
//     LET_BOX(Transform, result_, *lean_raylib_Transform_from(obj));
//     result_->scale = lean_raylib_Vector3_from(scale);
//     return lean_raylib_Transform_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BoneInfo_mk(/*char[32]*/lean_obj_arg name, uint32_t parent) {
//     LET_BOX_STRUCT(BoneInfo, result_,
//         .name = /*cast char[32] to_lean?false*/(name),
//         .parent = parent
//     );
//     return lean_raylib_BoneInfo_to(result_);
// }

// LEAN_EXPORT /*char[32]*/lean_obj_arg lean_raylib__BoneInfo_name(b_lean_obj_arg obj) {
//     char[32] result_ = lean_raylib_BoneInfo_from(obj)->name;
//     return /*cast char[32] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BoneInfo_name_set(/*char[32]*/lean_obj_arg name, b_lean_obj_arg obj) {
//     LET_BOX(BoneInfo, result_, *lean_raylib_BoneInfo_from(obj));
//     result_->name = /*cast char[32] to_lean?false*/(name);
//     return lean_raylib_BoneInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__BoneInfo_parent(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_BoneInfo_from(obj)->parent;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BoneInfo_parent_set(uint32_t parent, b_lean_obj_arg obj) {
//     LET_BOX(BoneInfo, result_, *lean_raylib_BoneInfo_from(obj));
//     result_->parent = parent;
//     return lean_raylib_BoneInfo_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_mk(lean_obj_arg transform, uint32_t meshCount, uint32_t materialCount, /* Mesh* */lean_obj_arg meshes, /* Material* */lean_obj_arg materials, /* int* */lean_obj_arg meshMaterial, uint32_t boneCount, /* BoneInfo* */lean_obj_arg bones, /* Transform* */lean_obj_arg bindPose) {
//     LET_BOX_STRUCT(Model, result_,
//         .transform = lean_raylib_Matrix_from(transform),
//         .meshCount = meshCount,
//         .materialCount = materialCount,
//         .meshes = /*todo: ptr?*/meshes,
//         .materials = /*todo: ptr?*/materials,
//         .meshMaterial = /*todo: ptr?*/meshMaterial,
//         .boneCount = boneCount,
//         .bones = /*todo: ptr?*/bones,
//         .bindPose = /*todo: ptr?*/bindPose
//     );
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Model_transform(b_lean_obj_arg obj) {
//     Matrix result_ = lean_raylib_Model_from(obj)->transform;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_transform_set(lean_obj_arg transform, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->transform = lean_raylib_Matrix_from(transform);
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Model_meshCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Model_from(obj)->meshCount;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_meshCount_set(uint32_t meshCount, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->meshCount = meshCount;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Model_materialCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Model_from(obj)->materialCount;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_materialCount_set(uint32_t materialCount, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->materialCount = materialCount;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* Mesh* */lean_obj_arg lean_raylib__Model_meshes(b_lean_obj_arg obj) {
//     Mesh * result_ = lean_raylib_Model_from(obj)->meshes;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_meshes_set(/* Mesh* */lean_obj_arg meshes, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->meshes = /*todo: ptr?*/meshes;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* Material* */lean_obj_arg lean_raylib__Model_materials(b_lean_obj_arg obj) {
//     Material * result_ = lean_raylib_Model_from(obj)->materials;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_materials_set(/* Material* */lean_obj_arg materials, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->materials = /*todo: ptr?*/materials;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* int* */lean_obj_arg lean_raylib__Model_meshMaterial(b_lean_obj_arg obj) {
//     int * result_ = lean_raylib_Model_from(obj)->meshMaterial;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_meshMaterial_set(/* int* */lean_obj_arg meshMaterial, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->meshMaterial = /*todo: ptr?*/meshMaterial;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Model_boneCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Model_from(obj)->boneCount;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_boneCount_set(uint32_t boneCount, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->boneCount = boneCount;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* BoneInfo* */lean_obj_arg lean_raylib__Model_bones(b_lean_obj_arg obj) {
//     BoneInfo * result_ = lean_raylib_Model_from(obj)->bones;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_bones_set(/* BoneInfo* */lean_obj_arg bones, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->bones = /*todo: ptr?*/bones;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* Transform* */lean_obj_arg lean_raylib__Model_bindPose(b_lean_obj_arg obj) {
//     Transform * result_ = lean_raylib_Model_from(obj)->bindPose;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Model_bindPose_set(/* Transform* */lean_obj_arg bindPose, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->bindPose = /*todo: ptr?*/bindPose;
//     return lean_raylib_Model_to(result_);
// }

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
