#pragma once

#include <lean_pod.h>
#include "util.h"


// # Vectors

static inline void lean_raylib_Vector2_set (b_lean_obj_arg obj, Vector2 v) {
    lean_ctor_set(obj, 0, lean_box_uint32(lean_pod_Float32_toBits(v.x)));
    lean_ctor_set(obj, 1, lean_box_uint32(lean_pod_Float32_toBits(v.y)));
}

static inline lean_object* lean_raylib_Vector2_to (Vector2 v) {
    lean_object* obj = lean_alloc_ctor(0, 2, 0);
    lean_raylib_Vector2_set(obj, v);
    return obj;
}

static inline Vector2 lean_raylib_Vector2_from (b_lean_obj_arg obj) {
    Vector2 v;
    v.x = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 0)));
    v.y = lean_pod_Float32_fromBits(lean_unbox_uint32(lean_ctor_get(obj, 1)));
    return v;
}

static inline lean_object* lean_raylib_Vector3_to (Vector3 const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Vector3* lean_raylib_Vector3_from (b_lean_obj_arg obj) {
    return (Vector3*) lean_get_external_data(obj);
}

static inline lean_object* lean_raylib_Vector4_to (Vector4 const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Vector4* lean_raylib_Vector4_from (b_lean_obj_arg obj) {
    return (Vector4*) lean_get_external_data(obj);
}


// # Matrix

static inline lean_object* lean_raylib_Matrix_to (Matrix const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Matrix* lean_raylib_Matrix_from (b_lean_obj_arg obj) {
    return (Matrix*) lean_get_external_data(obj);
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

static inline lean_object* lean_raylib_Rectangle_to (Rectangle const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Rectangle* lean_raylib_Rectangle_from (b_lean_obj_arg obj) {
    return (Rectangle*) lean_get_external_data(obj);
}


// # Image

static inline Image const* lean_raylib_Image_from (b_lean_obj_arg obj) {
    return (Image const*) lean_get_external_data(obj);
}

static void lean_raylib_Image_finalize(void* image) {
    UnloadImage(*(Image*)image);
    free(image);
}

static inline lean_object* lean_raylib_Image_to (Image const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_Image_finalize, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

// /// Decrements RC and returns image. Makes a copy if the ref is not exclusive.
// static inline Image lean_raylib_Image_from_own(lean_obj_arg image_box) {
//     Image image = *lean_raylib_Image_from(image_box);
//     if (!lean_is_exclusive(image_box)) {
//         image = ImageCopy(image);
//     }
//     lean_dec_ref(image_box);
//     return image;
// }


// # Texture

typedef struct {
    lean_object* owner;
    Texture texture;
} lean_raylib_TextureRef;

static void lean_raylib_TextureRef_foreach(void* textureRef, b_lean_obj_arg f) {
    lean_apply_1(f, ((lean_raylib_TextureRef*)textureRef)->owner);
}

static void lean_raylib_TextureRef_finalize(void* textureRef) {
    lean_dec(((lean_raylib_TextureRef*)textureRef)->owner);
    free(textureRef);
}

static inline lean_object* lean_raylib_TextureRef_alloc (Texture2D texture, lean_obj_arg owner) {
    LET_BOX_STRUCT(lean_raylib_TextureRef, textureRef,
        .texture = texture,
        .owner = owner,
    );
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_TextureRef_finalize, lean_raylib_TextureRef_foreach);
    }
    return lean_alloc_external(class_, textureRef);
}

static inline lean_raylib_TextureRef const* lean_raylib_TextureRef_from (b_lean_obj_arg obj) {
    return (lean_raylib_TextureRef const*) lean_get_external_data(obj);
}

static void lean_raylib_Texture_finalize(void* texture) {
    UnloadTexture(*(Texture*)texture);
    free(texture);
}

static inline lean_object* lean_raylib_Texture_to (Texture const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_Texture_finalize, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Texture const* lean_raylib_Texture_from (b_lean_obj_arg obj) {
    return (Texture const*) lean_get_external_data(obj);
}


// # Render texture

static void lean_raylib_RenderTexture_finalize(void* texture) {
    UnloadRenderTexture(*(RenderTexture*)texture);
    free(texture);
}

static inline lean_object* lean_raylib_RenderTexture_to (RenderTexture const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_RenderTexture_finalize, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline RenderTexture const* lean_raylib_RenderTexture_from (b_lean_obj_arg obj) {
    return (RenderTexture const*) lean_get_external_data(obj);
}


// # NPatch info

static inline lean_object* lean_raylib_NPatchInfo_to (NPatchInfo const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline NPatchInfo* lean_raylib_NPatchInfo_from (b_lean_obj_arg obj) {
    return (NPatchInfo*) lean_get_external_data(obj);
}


// # Glyph info

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


// # Camera 3D

static inline lean_object* lean_raylib_Camera3D_to (Camera3D const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Camera3D* lean_raylib_Camera3D_from (b_lean_obj_arg obj) {
    return (Camera3D*) lean_get_external_data(obj);
}


// # Camera 2D

static inline lean_object* lean_raylib_Camera2D_to (Camera2D const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Camera2D* lean_raylib_Camera2D_from (b_lean_obj_arg obj) {
    return (Camera2D*) lean_get_external_data(obj);
}


// # Mesh

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


// # Ray

static inline lean_object* lean_raylib_Ray_to (Ray const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Ray* lean_raylib_Ray_from (b_lean_obj_arg obj) {
    return (Ray*) lean_get_external_data(obj);
}


// # Ray collision

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


// # Bounding box

static inline lean_object* lean_raylib_BoundingBox_to (BoundingBox const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(free, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline BoundingBox* lean_raylib_BoundingBox_from (b_lean_obj_arg obj) {
    return (BoundingBox*) lean_get_external_data(obj);
}


// # Wave

static void lean_raylib_Wave_finalize(void* wave) {
    UnloadWave(*(Wave*)wave);
    free(wave);
}

static inline lean_object* lean_raylib_Wave_to (Wave const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_Wave_finalize, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Wave* lean_raylib_Wave_from (b_lean_obj_arg obj) {
    return (Wave*) lean_get_external_data(obj);
}


// # Audio stream

static void lean_raylib_AudioStream_finalize(void* audioStream) {
    UnloadAudioStream(*(AudioStream*)audioStream);
    free(audioStream);
}

static inline lean_object* lean_raylib_AudioStream_to (AudioStream const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_AudioStream_finalize, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline AudioStream const* lean_raylib_AudioStream_from (b_lean_obj_arg obj) {
    return (AudioStream const*) lean_get_external_data(obj);
}


// # Sound

static void lean_raylib_Sound_finalize(void* sound) {
    UnloadSound(*(Sound*)sound);
    free(sound);
}

static inline lean_object* lean_raylib_Sound_to (Sound const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_Sound_finalize, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Sound const* lean_raylib_Sound_from (b_lean_obj_arg obj) {
    return (Sound const*) lean_get_external_data(obj);
}


// # Music

static void lean_raylib_Music_finalize(void* music) {
    UnloadMusicStream(*(Music*)music);
    free(music);
}

static inline lean_object* lean_raylib_Music_to (Music const* obj) {
    static lean_external_class* class_ = NULL;
    if (class_ == NULL) {
        class_ = lean_register_external_class(lean_raylib_Music_finalize, lean_raylib_default_foreach);
    }
    return lean_alloc_external(class_, (void*)obj);
}

static inline Music * lean_raylib_Music_from (b_lean_obj_arg obj) {
    return (Music*) lean_get_external_data(obj);
}


// # Vr device info

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


// # Vr stereo config

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


// // # File path list

// static void lean_raylib_FilePathList_finalize(void* filePathList) {
//     UnloadDirectoryFiles(*(FilePathList*)filePathList);
//     free(filePathList);
// }

// static inline lean_object* lean_raylib_FilePathList_to (FilePathList const* obj) {
//     static lean_external_class* class_ = NULL;
//     if (class_ == NULL) {
//         class_ = lean_register_external_class(lean_raylib_FilePathList_finalize, lean_raylib_default_foreach);
//     }
//     return lean_alloc_external(class_, (void*)obj);
// }

// static inline FilePathList const* lean_raylib_FilePathList_from (b_lean_obj_arg obj) {
//     return (FilePathList const*) lean_get_external_data(obj);
// }
