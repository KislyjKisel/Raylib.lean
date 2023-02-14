#pragma once

#include "util.h"


// # Vectors

static inline lean_object* lean_raylib_Vector2_to (Vector2 const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Vector2 const* lean_raylib_Vector2_from (b_lean_obj_arg obj) {
    return (Vector2 const*) lean_get_external_data(obj);
}

static inline lean_object* lean_raylib_Vector3_to (Vector3 const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Vector3 const* lean_raylib_Vector3_from (b_lean_obj_arg obj) {
    return (Vector3 const*) lean_get_external_data(obj);
}

static inline lean_object* lean_raylib_Vector4_to (Vector4 const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Vector4 const* lean_raylib_Vector4_from (b_lean_obj_arg obj) {
    return (Vector4 const*) lean_get_external_data(obj);
}


// # Matrix

static inline lean_object* lean_raylib_Matrix_to (Matrix const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Matrix const* lean_raylib_Matrix_from (b_lean_obj_arg obj) {
    return (Matrix const*) lean_get_external_data(obj);
}


// # Color

static inline Color lean_raylib_Color_from(uint32_t color) {
    Color res = {
        .r = (uint8_t)(color & 0xFF),
        .g = (uint8_t)((color >> 8) & 0xFF),
        .b = (uint8_t)((color >> 16) & 0xFF),
        .a = (uint8_t)((color >> 24) & 0xFF),
    };
    return res;
}

static inline uint32_t lean_raylib_Color_to(Color color) {
    return color.r
        | (color.g << 8)
        | (color.b << 16)
        | (color.a << 24);
}


// # Rectangle

// static inline lean_object* lean_raylib_Rectangle_to (Rectangle const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Rectangle const* lean_raylib_Rectangle_from (b_lean_obj_arg obj) {
//     return (Rectangle const*) lean_get_external_data(obj);
// }


// # Image

static inline Image const* lean_raylib_Image_from (b_lean_obj_arg obj) {
    return (Image const*) lean_get_external_data(obj);
}

static void lean_raylib_Image_finalize(void* image) {
    UnloadImage(*(Image*)image);
}

static inline lean_object* lean_raylib_Image_to (Image const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_Image_finalize, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}


// # Texture

// static inline lean_object* lean_raylib_Texture_to (Texture const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Texture const* lean_raylib_Texture_from (b_lean_obj_arg obj) {
//     return (Texture const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_RenderTexture_to (RenderTexture const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline RenderTexture const* lean_raylib_RenderTexture_from (b_lean_obj_arg obj) {
//     return (RenderTexture const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_NPatchInfo_to (NPatchInfo const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline NPatchInfo const* lean_raylib_NPatchInfo_from (b_lean_obj_arg obj) {
//     return (NPatchInfo const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_GlyphInfo_to (GlyphInfo const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline GlyphInfo const* lean_raylib_GlyphInfo_from (b_lean_obj_arg obj) {
//     return (GlyphInfo const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Font_to (Font const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Font const* lean_raylib_Font_from (b_lean_obj_arg obj) {
//     return (Font const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Camera3D_to (Camera3D const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Camera3D const* lean_raylib_Camera3D_from (b_lean_obj_arg obj) {
//     return (Camera3D const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Camera2D_to (Camera2D const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Camera2D const* lean_raylib_Camera2D_from (b_lean_obj_arg obj) {
//     return (Camera2D const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Mesh_to (Mesh const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Mesh const* lean_raylib_Mesh_from (b_lean_obj_arg obj) {
//     return (Mesh const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Shader_to (Shader const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Shader const* lean_raylib_Shader_from (b_lean_obj_arg obj) {
//     return (Shader const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_MaterialMap_to (MaterialMap const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline MaterialMap const* lean_raylib_MaterialMap_from (b_lean_obj_arg obj) {
//     return (MaterialMap const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Material_to (Material const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Material const* lean_raylib_Material_from (b_lean_obj_arg obj) {
//     return (Material const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Transform_to (Transform const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Transform const* lean_raylib_Transform_from (b_lean_obj_arg obj) {
//     return (Transform const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_BoneInfo_to (BoneInfo const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline BoneInfo const* lean_raylib_BoneInfo_from (b_lean_obj_arg obj) {
//     return (BoneInfo const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Model_to (Model const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Model const* lean_raylib_Model_from (b_lean_obj_arg obj) {
//     return (Model const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_ModelAnimation_to (ModelAnimation const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline ModelAnimation const* lean_raylib_ModelAnimation_from (b_lean_obj_arg obj) {
//     return (ModelAnimation const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Ray_to (Ray const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Ray const* lean_raylib_Ray_from (b_lean_obj_arg obj) {
//     return (Ray const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_RayCollision_to (RayCollision const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline RayCollision const* lean_raylib_RayCollision_from (b_lean_obj_arg obj) {
//     return (RayCollision const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_BoundingBox_to (BoundingBox const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline BoundingBox const* lean_raylib_BoundingBox_from (b_lean_obj_arg obj) {
//     return (BoundingBox const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Wave_to (Wave const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Wave const* lean_raylib_Wave_from (b_lean_obj_arg obj) {
//     return (Wave const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_AudioStream_to (AudioStream const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline AudioStream const* lean_raylib_AudioStream_from (b_lean_obj_arg obj) {
//     return (AudioStream const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Sound_to (Sound const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Sound const* lean_raylib_Sound_from (b_lean_obj_arg obj) {
//     return (Sound const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_Music_to (Music const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline Music const* lean_raylib_Music_from (b_lean_obj_arg obj) {
//     return (Music const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_VrDeviceInfo_to (VrDeviceInfo const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline VrDeviceInfo const* lean_raylib_VrDeviceInfo_from (b_lean_obj_arg obj) {
//     return (VrDeviceInfo const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_VrStereoConfig_to (VrStereoConfig const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline VrStereoConfig const* lean_raylib_VrStereoConfig_from (b_lean_obj_arg obj) {
//     return (VrStereoConfig const*) lean_get_external_data(obj);
// }

// static inline lean_object* lean_raylib_FilePathList_to (FilePathList const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(free, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline FilePathList const* lean_raylib_FilePathList_from (b_lean_obj_arg obj) {
//     return (FilePathList const*) lean_get_external_data(obj);
// }

// LEAN_EXPORT lean_object* lean_raylib__FilePathList_paths_set(/* char ** */lean_obj_arg paths, b_lean_obj_arg obj) {
//     LET_BOX(FilePathList, result_, *lean_raylib_FilePathList_from(obj));
//     result_->paths = /*todo: ptr?*/paths;
//     return lean_raylib_FilePathList_to(result_);
// }
