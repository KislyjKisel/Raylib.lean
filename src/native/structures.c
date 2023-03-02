#include <memory.h>
#include "util.h"
#include "structures.h"


// # Vectors

// ## Vector2

LEAN_EXPORT lean_obj_res lean_raylib__Vector2_mk(double x, double y) {
    LET_BOX_STRUCT(Vector2, vec,
        .x = (float)x,
        .y = (float)y
    );
    return lean_raylib_Vector2_to(vec);
}

LEAN_EXPORT double lean_raylib__Vector2_x(b_lean_obj_arg vec) {
    return lean_raylib_Vector2_from(vec)->x;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector2_x_set(double x, lean_obj_arg vec_box) {
    if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector2_from(vec_box)->x = x;
        return vec_box;
    }
    Vector2 const* vec = lean_raylib_Vector2_from(vec_box);
    LET_BOX_STRUCT(Vector2, vec_new_box,
        .x = x,
        .y = vec->y,
    );
    lean_dec_ref(vec_box);
    return lean_raylib_Vector2_to(vec_new_box);
}

LEAN_EXPORT double lean_raylib__Vector2_y(b_lean_obj_arg vec) {
    return lean_raylib_Vector2_from(vec)->y;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector2_y_set(double y, lean_obj_arg vec_box) {
    if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector2_from(vec_box)->y = y;
        return vec_box;
    }
    Vector2 const* vec = lean_raylib_Vector2_from(vec_box);
    LET_BOX_STRUCT(Vector2, vec_new_box,
        .x = vec->x,
        .y = y,
    );
    lean_dec_ref(vec_box);
    return lean_raylib_Vector2_to(vec_new_box);
}


// ## Vector3

LEAN_EXPORT lean_obj_res lean_raylib__Vector3_mk(double x, double y, double z) {
    LET_BOX_STRUCT(Vector3, result_,
        .x = (float)x,
        .y = (float)y,
        .z = (float)z
    );
    return lean_raylib_Vector3_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector3_x(b_lean_obj_arg obj) {
    return lean_raylib_Vector3_from(obj)->x;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector3_x_set(double x, lean_obj_arg vec_box) {
    if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector3_from(vec_box)->x = x;
        return vec_box;
    }
    Vector3 const* vec = lean_raylib_Vector3_from(vec_box);
    LET_BOX_STRUCT(Vector3, vec_new_box,
        .x = x,
        .y = vec->y,
        .z = vec->z,
    );
    lean_dec_ref(vec_box);
    return lean_raylib_Vector3_to(vec_new_box);
}

LEAN_EXPORT double lean_raylib__Vector3_y(b_lean_obj_arg obj) {
    return lean_raylib_Vector3_from(obj)->y;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector3_y_set(double y, lean_obj_arg vec_box) {
    if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector3_from(vec_box)->y = y;
        return vec_box;
    }
    Vector3 const* vec = lean_raylib_Vector3_from(vec_box);
    LET_BOX_STRUCT(Vector3, vec_new_box,
        .x = vec->x,
        .y = y,
        .z = vec->z,
    );
    lean_dec_ref(vec_box);
    return lean_raylib_Vector3_to(vec_new_box);
}

LEAN_EXPORT double lean_raylib__Vector3_z(b_lean_obj_arg obj) {
    return lean_raylib_Vector3_from(obj)->z;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector3_z_set(double z, lean_obj_arg vec_box) {
    if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector3_from(vec_box)->z = z;
        return vec_box;
    }
    Vector3 const* vec = lean_raylib_Vector3_from(vec_box);
    LET_BOX_STRUCT(Vector3, vec_new_box,
        .x = vec->x,
        .y = vec->y,
        .z = z,
    );
    lean_dec_ref(vec_box);
    return lean_raylib_Vector3_to(vec_new_box);
}


// ## Vector4

LEAN_EXPORT lean_obj_res lean_raylib__Vector4_mk(double x, double y, double z, double w) {
    LET_BOX_STRUCT(Vector4, result_,
        .x = (float)x,
        .y = (float)y,
        .z = (float)z,
        .w = (float)w
    );
    return lean_raylib_Vector4_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector4_x(b_lean_obj_arg obj) {
    return lean_raylib_Vector4_from(obj)->x;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector4_x_set(double x, lean_obj_arg vec_box) {
    if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector4_from(vec_box)->x = x;
        return vec_box;
    }
    Vector4 const* vec = lean_raylib_Vector4_from(vec_box);
    LET_BOX_STRUCT(Vector4, vec_new_box,
        .x = x,
        .y = vec->y,
        .z = vec->z,
        .w = vec->w
    );
    lean_dec_ref(vec_box);
    return lean_raylib_Vector4_to(vec_new_box);
}

LEAN_EXPORT double lean_raylib__Vector4_y(b_lean_obj_arg obj) {
    return lean_raylib_Vector4_from(obj)->y;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector4_y_set(double y, lean_obj_arg vec_box) {
   if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector4_from(vec_box)->y = y;
        return vec_box;
    }
    Vector4 const* vec = lean_raylib_Vector4_from(vec_box);
    LET_BOX_STRUCT(Vector4, vec_new_box,
        .x = vec->x,
        .y = y,
        .z = vec->z,
        .w = vec->w,
    );
    lean_dec_ref(vec);
    return lean_raylib_Vector4_to(vec_new_box);
}

LEAN_EXPORT double lean_raylib__Vector4_z(b_lean_obj_arg obj) {
    return lean_raylib_Vector4_from(obj)->z;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector4_z_set(double z, lean_obj_arg vec_box) {
    if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector4_from(vec_box)->z = z;
        return vec_box;
    }
    Vector4 const* vec = lean_raylib_Vector4_from(vec_box);
    LET_BOX_STRUCT(Vector4, vec_new_box,
        .x = vec->x,
        .y = vec->y,
        .z = z,
        .w = vec->w,
    );
    lean_dec_ref(vec_box);
    return lean_raylib_Vector4_to(vec_new_box);
}

LEAN_EXPORT double lean_raylib__Vector4_w(b_lean_obj_arg obj) {
    return lean_raylib_Vector4_from(obj)->w;
}

LEAN_EXPORT lean_obj_res lean_raylib__Vector4_w_set(double w, lean_obj_arg vec_box) {
    if(LEAN_LIKELY(lean_is_exclusive(vec_box))) {
        lean_raylib_Vector4_from(vec_box)->w = w;
        return vec_box;
    }
    Vector4 const* vec = lean_raylib_Vector4_from(vec_box);
    LET_BOX_STRUCT(Vector4, vec_new_box,
        .x = vec->x,
        .y = vec->y,
        .z = vec->z,
        .w = w,
    );
    lean_dec_ref(vec_box);
    return lean_raylib_Vector4_to(vec_new_box);
}


// # Matrix

LEAN_EXPORT lean_obj_res lean_raylib__Matrix_mk(
    double m0, double m4, double m8,  double m12,
    double m1, double m5, double m9,  double m13,
    double m2, double m6, double m10, double m14,
    double m3, double m7, double m11, double m15
) {
    LET_BOX_STRUCT(Matrix, result_,
        .m0 = (float)m0, .m4 = (float)m4, .m8 = (float)m8, .m12 = (float)m12,
        .m1 = (float)m1, .m5 = (float)m5, .m9 = (float)m9, .m13 = (float)m13,
        .m2 = (float)m2, .m6 = (float)m6, .m10 = (float)m10, .m14 = (float)m14,
        .m3 = (float)m3, .m7 = (float)m7, .m11 = (float)m11, .m15 = (float)m15
    );
    return lean_raylib_Matrix_to(result_);
}

#define MATRIX_ACCESSORS(N)\
    LEAN_EXPORT double lean_raylib__Matrix_m##N(b_lean_obj_arg mat) {\
        return (double)lean_raylib_Matrix_from(mat)->m##N;\
    }\
    LEAN_EXPORT lean_obj_res lean_raylib__Matrix_m##N##_set(double m##N, lean_obj_arg mat_box) {\
        if(LEAN_LIKELY(lean_is_exclusive(mat_box))) {\
            lean_raylib_Matrix_from(mat_box)->m##N = m##N;\
            return mat_box;\
        }\
        lean_dec_ref(mat_box);\
        LET_BOX(Matrix, mat_new_box, *lean_raylib_Matrix_from(mat_box));\
        mat_new_box->m##N = m##N;\
        return lean_raylib_Matrix_to(mat_new_box);\
    }

MATRIX_ACCESSORS(0);
MATRIX_ACCESSORS(1);
MATRIX_ACCESSORS(2);
MATRIX_ACCESSORS(3);
MATRIX_ACCESSORS(4);
MATRIX_ACCESSORS(5);
MATRIX_ACCESSORS(6);
MATRIX_ACCESSORS(7);
MATRIX_ACCESSORS(8);
MATRIX_ACCESSORS(9);
MATRIX_ACCESSORS(10);
MATRIX_ACCESSORS(11);
MATRIX_ACCESSORS(12);
MATRIX_ACCESSORS(13);
MATRIX_ACCESSORS(14);
MATRIX_ACCESSORS(15);


// # Rectangle

LEAN_EXPORT lean_obj_res lean_raylib__Rectangle_mk(double x, double y, double width, double height) {
    LET_BOX_STRUCT(Rectangle, rectangle,
        .x = (float)x,
        .y = (float)y,
        .width = (float)width,
        .height = (float)height
    );
    return lean_raylib_Rectangle_to(rectangle);
}

LEAN_EXPORT double lean_raylib__Rectangle_x(b_lean_obj_arg obj) {
    return lean_raylib_Rectangle_from(obj)->x;
}

LEAN_EXPORT lean_obj_res lean_raylib__Rectangle_x_set(double x, lean_obj_arg rect_box) {
    if(LEAN_LIKELY(lean_is_exclusive(rect_box))) {
        lean_raylib_Rectangle_from(rect_box)->x = x;
        return rect_box;
    }
    lean_dec_ref(rect_box);
    LET_BOX(Rectangle, rect_new_box, *lean_raylib_Rectangle_from(rect_box));
    rect_new_box->x = x;
    return lean_raylib_Rectangle_to(rect_new_box);
}

LEAN_EXPORT double lean_raylib__Rectangle_y(b_lean_obj_arg obj) {
    return lean_raylib_Rectangle_from(obj)->y;
}

LEAN_EXPORT lean_obj_res lean_raylib__Rectangle_y_set(double y, lean_obj_arg rect_box) {
    if(LEAN_LIKELY(lean_is_exclusive(rect_box))) {
        lean_raylib_Rectangle_from(rect_box)->y = y;
        return rect_box;
    }
    lean_dec_ref(rect_box);
    LET_BOX(Rectangle, rect_new_box, *lean_raylib_Rectangle_from(rect_box));
    rect_new_box->y = y;
    return lean_raylib_Rectangle_to(rect_new_box);
}

LEAN_EXPORT double lean_raylib__Rectangle_width(b_lean_obj_arg obj) {
    return lean_raylib_Rectangle_from(obj)->width;
}

LEAN_EXPORT lean_obj_res lean_raylib__Rectangle_width_set(double width, lean_obj_arg rect_box) {
    if(LEAN_LIKELY(lean_is_exclusive(rect_box))) {
        lean_raylib_Rectangle_from(rect_box)->width = width;
        return rect_box;
    }
    lean_dec_ref(rect_box);
    LET_BOX(Rectangle, rect_new_box, *lean_raylib_Rectangle_from(rect_box));
    rect_new_box->width = width;
    return lean_raylib_Rectangle_to(rect_new_box);
}

LEAN_EXPORT double lean_raylib__Rectangle_height(b_lean_obj_arg obj) {
    return lean_raylib_Rectangle_from(obj)->height;
}

LEAN_EXPORT lean_obj_res lean_raylib__Rectangle_height_set(double height, lean_obj_arg rect_box) {
    if(LEAN_LIKELY(lean_is_exclusive(rect_box))) {
        lean_raylib_Rectangle_from(rect_box)->height = height;
        return rect_box;
    }
    lean_dec_ref(rect_box);
    LET_BOX(Rectangle, rect_new_box, *lean_raylib_Rectangle_from(rect_box));
    rect_new_box->height = height;
    return lean_raylib_Rectangle_to(rect_new_box);
}


// # Image

LEAN_EXPORT lean_obj_res lean_raylib__Image_mk(
    /* ByteArray */ lean_obj_arg data, uint32_t width, uint32_t height,
    uint32_t mipmaps, uint32_t format
) {
    void* own_data;
    if(lean_is_exclusive(data)) {
        own_data = lean_sarray_cptr(data);
        #ifdef RAYLIB_LEAN_UNSAFE_OPTS
            lean_dealloc(data);
        #else
            lean_dec_ref_cold(data);
        #endif
    }
    else {
        size_t size = lean_sarray_size(data);
        own_data = malloc(size);
        memcpy(own_data, data, size);
        lean_dec(data);
    }
    LET_BOX_STRUCT(Image, image,
        .data = own_data,
        .width = width,
        .height = height,
        .mipmaps = mipmaps,
        .format = format
    );
    return lean_raylib_Image_to(image);
}

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
        .source = *lean_raylib_Rectangle_from(source),
        .left = left,
        .top = top,
        .right = right,
        .bottom = bottom,
        .layout = layout
    );
    return lean_raylib_NPatchInfo_to(npatchInfo);
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_source(b_lean_obj_arg npatchInfo) {
    LET_BOX(Rectangle, source, lean_raylib_NPatchInfo_from(npatchInfo)->source);
    return lean_raylib_Rectangle_to(source);
}

LEAN_EXPORT lean_obj_res lean_raylib__NPatchInfo_source_set(b_lean_obj_arg source_box, lean_obj_arg npatchInfo_box) {
    Rectangle source = *lean_raylib_Rectangle_from(source_box);
    if(LEAN_LIKELY(lean_is_exclusive(npatchInfo_box))) {
        lean_raylib_NPatchInfo_from(npatchInfo_box)->source = source;
        return npatchInfo_box;
    }
    lean_dec_ref(npatchInfo_box);
    LET_BOX(NPatchInfo, npatchInfo_new_box, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new_box->source = source;
    return lean_raylib_NPatchInfo_to(npatchInfo_new_box);
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
    LET_BOX(NPatchInfo, npatchInfo_new_box, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new_box->left = left;
    return lean_raylib_NPatchInfo_to(npatchInfo_new_box);
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
    LET_BOX(NPatchInfo, npatchInfo_new_box, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new_box->top = top;
    return lean_raylib_NPatchInfo_to(npatchInfo_new_box);
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
    LET_BOX(NPatchInfo, npatchInfo_new_box, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new_box->right = right;
    return lean_raylib_NPatchInfo_to(npatchInfo_new_box);

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
    LET_BOX(NPatchInfo, npatchInfo_new_box, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new_box->bottom = bottom;
    return lean_raylib_NPatchInfo_to(npatchInfo_new_box);

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
    LET_BOX(NPatchInfo, npatchInfo_new_box, *lean_raylib_NPatchInfo_from(npatchInfo_box));
    npatchInfo_new_box->layout = layout;
    return lean_raylib_NPatchInfo_to(npatchInfo_new_box);
}


// # Glyph info

// LEAN_EXPORT lean_obj_res lean_raylib__GlyphInfo_mk(uint32_t value, uint32_t offsetX, uint32_t offsetY, uint32_t advanceX, lean_obj_arg image) {
//     LET_BOX_STRUCT(GlyphInfo, result_,
//         .value = value,
//         .offsetX = offsetX,
//         .offsetY = offsetY,
//         .advanceX = advanceX,
//         .image = lean_raylib_Image_from(image)
//     );
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GlyphInfo_value(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_GlyphInfo_from(obj)->value;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GlyphInfo_value_set(uint32_t value, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->value = value;
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GlyphInfo_offsetX(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_GlyphInfo_from(obj)->offsetX;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GlyphInfo_offsetX_set(uint32_t offsetX, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->offsetX = offsetX;
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GlyphInfo_offsetY(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_GlyphInfo_from(obj)->offsetY;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GlyphInfo_offsetY_set(uint32_t offsetY, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->offsetY = offsetY;
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GlyphInfo_advanceX(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_GlyphInfo_from(obj)->advanceX;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GlyphInfo_advanceX_set(uint32_t advanceX, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->advanceX = advanceX;
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GlyphInfo_image(b_lean_obj_arg obj) {
//     Image result_ = lean_raylib_GlyphInfo_from(obj)->image;
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GlyphInfo_image_set(lean_obj_arg image, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->image = lean_raylib_Image_from(image);
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Font_mk(uint32_t baseSize, uint32_t glyphCount, uint32_t glyphPadding, lean_obj_arg texture, /* Rectangle* */lean_obj_arg recs, /* GlyphInfo* */lean_obj_arg glyphs) {
//     LET_BOX_STRUCT(Font, result_,
//         .baseSize = baseSize,
//         .glyphCount = glyphCount,
//         .glyphPadding = glyphPadding,
//         .texture = /*cast Texture2D to_lean?false*/(texture),
//         .recs = /*todo: ptr?*/recs,
//         .glyphs = /*todo: ptr?*/glyphs
//     );
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Font_baseSize(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Font_from(obj)->baseSize;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Font_baseSize_set(uint32_t baseSize, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->baseSize = baseSize;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Font_glyphCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Font_from(obj)->glyphCount;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Font_glyphCount_set(uint32_t glyphCount, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->glyphCount = glyphCount;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Font_glyphPadding(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Font_from(obj)->glyphPadding;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Font_glyphPadding_set(uint32_t glyphPadding, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->glyphPadding = glyphPadding;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Font_texture(b_lean_obj_arg obj) {
//     Texture2D result_ = lean_raylib_Font_from(obj)->texture;
//     return /*cast Texture2D to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Font_texture_set(lean_obj_arg texture, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->texture = /*cast Texture2D to_lean?false*/(texture);
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT /* Rectangle* */lean_obj_arg lean_raylib__Font_recs(b_lean_obj_arg obj) {
//     Rectangle * result_ = lean_raylib_Font_from(obj)->recs;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Font_recs_set(/* Rectangle* */lean_obj_arg recs, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->recs = /*todo: ptr?*/recs;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT /* GlyphInfo* */lean_obj_arg lean_raylib__Font_glyphs(b_lean_obj_arg obj) {
//     GlyphInfo * result_ = lean_raylib_Font_from(obj)->glyphs;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Font_glyphs_set(/* GlyphInfo* */lean_obj_arg glyphs, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->glyphs = /*todo: ptr?*/glyphs;
//     return lean_raylib_Font_to(result_);
// }


// # Camera 3D

LEAN_EXPORT lean_obj_res lean_raylib__Camera3D_mk(
    b_lean_obj_arg position, b_lean_obj_arg target, b_lean_obj_arg up,
    double fovy, uint32_t projection
) {
    LET_BOX_STRUCT(Camera3D, cam3d,
        .position = *lean_raylib_Vector3_from(position),
        .target = *lean_raylib_Vector3_from(target),
        .up = *lean_raylib_Vector3_from(up),
        .fovy = (float)fovy,
        .projection = projection
    );
    return lean_raylib_Camera3D_to(cam3d);
}

LEAN_EXPORT lean_obj_arg lean_raylib__Camera3D_position(b_lean_obj_arg cam3d) {
    LET_BOX(Vector3, position, lean_raylib_Camera3D_from(cam3d)->position);
    return lean_raylib_Vector3_to(position);
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera3D_position_set(lean_obj_arg position, lean_obj_arg cam3d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam3d))) {
        lean_raylib_Camera3D_from(cam3d)->position = *lean_raylib_Vector3_from(position);
        return cam3d;
    }
    LET_BOX(Camera3D, cam3d_new, *lean_raylib_Camera3D_from(cam3d));
    lean_dec_ref(cam3d);
    cam3d_new->position = *lean_raylib_Vector3_from(position);
    return lean_raylib_Camera3D_to(cam3d_new);
}

LEAN_EXPORT lean_obj_arg lean_raylib__Camera3D_target(b_lean_obj_arg cam3d) {
    LET_BOX(Vector3, target, lean_raylib_Camera3D_from(cam3d)->target);
    return lean_raylib_Vector3_to(target);
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera3D_target_set(lean_obj_arg target, lean_obj_arg cam3d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam3d))) {
        lean_raylib_Camera3D_from(cam3d)->target = *lean_raylib_Vector3_from(target);
        return cam3d;
    }
    LET_BOX(Camera3D, cam3d_new, *lean_raylib_Camera3D_from(cam3d));
    lean_dec_ref(cam3d);
    cam3d_new->target = *lean_raylib_Vector3_from(target);
    return lean_raylib_Camera3D_to(cam3d_new);
}

LEAN_EXPORT lean_obj_arg lean_raylib__Camera3D_up(b_lean_obj_arg cam3d) {
    LET_BOX(Vector3, up, lean_raylib_Camera3D_from(cam3d)->up);
    return lean_raylib_Vector3_to(up);
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera3D_up_set(lean_obj_arg up, lean_obj_arg cam3d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam3d))) {
        lean_raylib_Camera3D_from(cam3d)->up = *lean_raylib_Vector3_from(up);
        return cam3d;
    }
    LET_BOX(Camera3D, cam3d_new, *lean_raylib_Camera3D_from(cam3d));
    lean_dec_ref(cam3d);
    cam3d_new->up = *lean_raylib_Vector3_from(up);
    return lean_raylib_Camera3D_to(cam3d_new);
}

LEAN_EXPORT double lean_raylib__Camera3D_fovy(b_lean_obj_arg cam3d) {
    return (double)lean_raylib_Camera3D_from(cam3d)->fovy;
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera3D_fovy_set(double fovy, lean_obj_arg cam3d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam3d))) {
        lean_raylib_Camera3D_from(cam3d)->fovy = fovy;
        return cam3d;
    }
    LET_BOX(Camera3D, cam3d_new, *lean_raylib_Camera3D_from(cam3d));
    lean_dec_ref(cam3d);
    cam3d_new->fovy = (float)fovy;
    return lean_raylib_Camera3D_to(cam3d_new);
}

LEAN_EXPORT uint32_t lean_raylib__Camera3D_projection(b_lean_obj_arg cam3d) {
    return lean_raylib_Camera3D_from(cam3d)->projection;
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera3D_projection_set(uint32_t projection, lean_obj_arg cam3d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam3d))) {
        lean_raylib_Camera3D_from(cam3d)->projection = projection;
        return cam3d;
    }
    LET_BOX(Camera3D, cam3d_new, *lean_raylib_Camera3D_from(cam3d));
    lean_dec_ref(cam3d);
    cam3d_new->projection = projection;
    return lean_raylib_Camera3D_to(cam3d_new);
}


// # Camera 2D

LEAN_EXPORT lean_obj_res lean_raylib__Camera2D_mk(b_lean_obj_arg offset, b_lean_obj_arg target, double rotation, double zoom) {
    LET_BOX_STRUCT(Camera2D, cam2d,
        .offset = *lean_raylib_Vector2_from(offset),
        .target = *lean_raylib_Vector2_from(target),
        .rotation = (float)rotation,
        .zoom = (float)zoom
    );
    return lean_raylib_Camera2D_to(cam2d);
}

LEAN_EXPORT lean_obj_arg lean_raylib__Camera2D_offset(b_lean_obj_arg cam2d) {
    LET_BOX(Vector2, offset, lean_raylib_Camera2D_from(cam2d)->offset);
    return lean_raylib_Vector2_to(offset);
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera2D_offset_set(b_lean_obj_arg offset, lean_obj_arg cam2d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam2d))) {
        lean_raylib_Camera2D_from(cam2d)->offset = *lean_raylib_Vector2_from(offset);
        return cam2d;
    }
    LET_BOX(Camera2D, cam2d_new, *lean_raylib_Camera2D_from(cam2d));
    lean_dec_ref(cam2d);
    cam2d_new->offset = *lean_raylib_Vector2_from(offset);
    return lean_raylib_Camera2D_to(cam2d_new);
}

LEAN_EXPORT lean_obj_arg lean_raylib__Camera2D_target(b_lean_obj_arg cam2d) {
    LET_BOX(Vector2, target, lean_raylib_Camera2D_from(cam2d)->target);
    return lean_raylib_Vector2_to(target);
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera2D_target_set(b_lean_obj_arg target, lean_obj_arg cam2d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam2d))) {
        lean_raylib_Camera2D_from(cam2d)->target = *lean_raylib_Vector2_from(target);
        return cam2d;
    }
    LET_BOX(Camera2D, cam2d_new, *lean_raylib_Camera2D_from(cam2d));
    lean_dec_ref(cam2d);
    cam2d_new->target = *lean_raylib_Vector2_from(target);
    return lean_raylib_Camera2D_to(cam2d_new);
}

LEAN_EXPORT double lean_raylib__Camera2D_rotation(b_lean_obj_arg cam2d) {
    return (double)lean_raylib_Camera2D_from(cam2d)->rotation;
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera2D_rotation_set(double rotation, lean_obj_arg cam2d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam2d))) {
        lean_raylib_Camera2D_from(cam2d)->rotation = rotation;
        return cam2d;
    }
    LET_BOX(Camera2D, cam2d_new, *lean_raylib_Camera2D_from(cam2d));
    lean_dec_ref(cam2d);
    cam2d_new->rotation = (float)rotation;
    return lean_raylib_Camera2D_to(cam2d_new);
}

LEAN_EXPORT double lean_raylib__Camera2D_zoom(b_lean_obj_arg cam2d) {
    return (double)lean_raylib_Camera2D_from(cam2d)->zoom;
}

LEAN_EXPORT lean_obj_res lean_raylib__Camera2D_zoom_set(double zoom, lean_obj_arg cam2d) {
    if(LEAN_LIKELY(lean_is_exclusive(cam2d))) {
        lean_raylib_Camera2D_from(cam2d)->zoom = zoom;
        return cam2d;
    }
    LET_BOX(Camera2D, cam2d_new, *lean_raylib_Camera2D_from(cam2d));
    lean_dec_ref(cam2d);
    cam2d_new->zoom = (float)zoom;
    return lean_raylib_Camera2D_to(cam2d_new);
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

// LEAN_EXPORT lean_obj_res lean_raylib__Shader_mk(uint32_t id, /* int* */lean_obj_arg locs) {
//     LET_BOX_STRUCT(Shader, result_,
//         .id = id,
//         .locs = /*todo: ptr?*/locs
//     );
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Shader_id(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Shader_from(obj)->id;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Shader_id_set(uint32_t id, b_lean_obj_arg obj) {
//     LET_BOX(Shader, result_, *lean_raylib_Shader_from(obj));
//     result_->id = id;
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT /* int* */lean_obj_arg lean_raylib__Shader_locs(b_lean_obj_arg obj) {
//     int * result_ = lean_raylib_Shader_from(obj)->locs;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__Shader_locs_set(/* int* */lean_obj_arg locs, b_lean_obj_arg obj) {
//     LET_BOX(Shader, result_, *lean_raylib_Shader_from(obj));
//     result_->locs = /*todo: ptr?*/locs;
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MaterialMap_mk(lean_obj_arg texture, uint32_t color, double value) {
//     LET_BOX_STRUCT(MaterialMap, result_,
//         .texture = /*cast Texture2D to_lean?false*/(texture),
//         .color = lean_raylib_Color_from(color),
//         .value = (float)value
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

// LEAN_EXPORT double lean_raylib__MaterialMap_value(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_MaterialMap_from(obj)->value;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MaterialMap_value_set(double value, b_lean_obj_arg obj) {
//     LET_BOX(MaterialMap, result_, *lean_raylib_MaterialMap_from(obj));
//     result_->value = (float)value;
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


// # Ray

LEAN_EXPORT lean_obj_res lean_raylib__Ray_mk(b_lean_obj_arg position, b_lean_obj_arg direction) {
    LET_BOX_STRUCT(Ray, ray,
        .position = *lean_raylib_Vector3_from(position),
        .direction = *lean_raylib_Vector3_from(direction)
    );
    return lean_raylib_Ray_to(ray);
}

LEAN_EXPORT lean_obj_arg lean_raylib__Ray_position(b_lean_obj_arg ray) {
    LET_BOX(Vector3, position, lean_raylib_Ray_from(ray)->position);
    return lean_raylib_Vector3_to(position);
}

LEAN_EXPORT lean_obj_res lean_raylib__Ray_position_set(b_lean_obj_arg position, lean_obj_arg ray) {
    if(LEAN_LIKELY(lean_is_exclusive(ray))) {
        lean_raylib_Ray_from(ray)->position = *lean_raylib_Vector3_from(position);
        return ray;
    }
    LET_BOX(Ray, ray_new, *lean_raylib_Ray_from(ray));
    lean_dec_ref(ray);
    ray_new->position = *lean_raylib_Vector3_from(position);
    return lean_raylib_Ray_to(ray_new);
}

LEAN_EXPORT lean_obj_arg lean_raylib__Ray_direction(b_lean_obj_arg ray) {
    LET_BOX(Vector3, direction, lean_raylib_Ray_from(ray)->direction);
    return lean_raylib_Vector3_to(direction);
}

LEAN_EXPORT lean_obj_res lean_raylib__Ray_direction_set(b_lean_obj_arg direction, lean_obj_arg ray) {
    if(LEAN_LIKELY(lean_is_exclusive(ray))) {
        lean_raylib_Ray_from(ray)->direction = *lean_raylib_Vector3_from(direction);
        return ray;
    }
    LET_BOX(Ray, ray_new, *lean_raylib_Ray_from(ray));
    lean_dec_ref(ray);
    ray_new->direction = *lean_raylib_Vector3_from(direction);
    return lean_raylib_Ray_to(ray_new);
}


// # Ray collision

// LEAN_EXPORT lean_obj_res lean_raylib__RayCollision_mk(uint8_t hit, double distance, lean_obj_arg point, lean_obj_arg normal) {
//     LET_BOX_STRUCT(RayCollision, result_,
//         .hit = hit,
//         .distance = (float)distance,
//         .point = lean_raylib_Vector3_from(point),
//         .normal = lean_raylib_Vector3_from(normal)
//     );
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__RayCollision_hit(b_lean_obj_arg obj) {
//     bool result_ = lean_raylib_RayCollision_from(obj)->hit;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__RayCollision_hit_set(uint8_t hit, b_lean_obj_arg obj) {
//     LET_BOX(RayCollision, result_, *lean_raylib_RayCollision_from(obj));
//     result_->hit = hit;
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT double lean_raylib__RayCollision_distance(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_RayCollision_from(obj)->distance;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__RayCollision_distance_set(double distance, b_lean_obj_arg obj) {
//     LET_BOX(RayCollision, result_, *lean_raylib_RayCollision_from(obj));
//     result_->distance = (float)distance;
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__RayCollision_point(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_RayCollision_from(obj)->point;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__RayCollision_point_set(lean_obj_arg point, b_lean_obj_arg obj) {
//     LET_BOX(RayCollision, result_, *lean_raylib_RayCollision_from(obj));
//     result_->point = lean_raylib_Vector3_from(point);
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__RayCollision_normal(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_RayCollision_from(obj)->normal;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__RayCollision_normal_set(lean_obj_arg normal, b_lean_obj_arg obj) {
//     LET_BOX(RayCollision, result_, *lean_raylib_RayCollision_from(obj));
//     result_->normal = lean_raylib_Vector3_from(normal);
//     return lean_raylib_RayCollision_to(result_);
// }


// # Bounding box

LEAN_EXPORT lean_obj_res lean_raylib__BoundingBox_mk(b_lean_obj_arg min, b_lean_obj_arg max) {
    LET_BOX_STRUCT(BoundingBox, result_,
        .min = *lean_raylib_Vector3_from(min),
        .max = *lean_raylib_Vector3_from(max)
    );
    return lean_raylib_BoundingBox_to(result_);
}

LEAN_EXPORT lean_obj_arg lean_raylib__BoundingBox_min(b_lean_obj_arg bbox) {
    LET_BOX(Vector3, min, lean_raylib_BoundingBox_from(bbox)->min);
    return lean_raylib_Vector3_to(min);
}

LEAN_EXPORT lean_obj_res lean_raylib__BoundingBox_min_set(lean_obj_arg min, lean_obj_arg bbox_box) {
    if(LEAN_LIKELY(lean_is_exclusive(bbox_box))) {
        lean_raylib_BoundingBox_from(bbox_box)->min = *lean_raylib_Vector3_from(min);
        return bbox_box;
    }
    LET_BOX(BoundingBox, bbox_new, *lean_raylib_BoundingBox_from(bbox_box));
    bbox_new->min = *lean_raylib_Vector3_from(min);
    lean_dec_ref(bbox_box);
    return lean_raylib_BoundingBox_to(bbox_new);
}

LEAN_EXPORT lean_obj_arg lean_raylib__BoundingBox_max(b_lean_obj_arg bbox) {
    LET_BOX(Vector3, max, lean_raylib_BoundingBox_from(bbox)->max);
    return lean_raylib_Vector3_to(max);
}

LEAN_EXPORT lean_obj_res lean_raylib__BoundingBox_max_set(lean_obj_arg max, lean_obj_arg bbox_box) {
    if(LEAN_LIKELY(lean_is_exclusive(bbox_box))) {
        lean_raylib_BoundingBox_from(bbox_box)->max = *lean_raylib_Vector3_from(max);
        return bbox_box;
    }
    LET_BOX(BoundingBox, bbox_new, *lean_raylib_BoundingBox_from(bbox_box));
    bbox_new->max = *lean_raylib_Vector3_from(max);
    lean_dec_ref(bbox_box);
    return lean_raylib_BoundingBox_to(bbox_new);
}


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
    return lean_raylib_AudioStream_from(audioStream)->sampleRate;
}

LEAN_EXPORT uint32_t lean_raylib__AudioStream_sampleSize(b_lean_obj_arg audioStream) {
    return lean_raylib_AudioStream_from(audioStream)->sampleSize;
}

LEAN_EXPORT uint32_t lean_raylib__AudioStream_channels(b_lean_obj_arg audioStream) {
    return lean_raylib_AudioStream_from(audioStream)->channels;
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


// # Vr device info

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_mk(uint32_t hResolution, uint32_t vResolution, double hScreenSize, double vScreenSize, double vScreenCenter, double eyeToScreenDistance, double lensSeparationDistance, double interpupillaryDistance, /*float[4]*/lean_obj_arg lensDistortionValues, /*float[4]*/lean_obj_arg chromaAbCorrection) {
//     LET_BOX_STRUCT(VrDeviceInfo, result_,
//         .hResolution = hResolution,
//         .vResolution = vResolution,
//         .hScreenSize = (float)hScreenSize,
//         .vScreenSize = (float)vScreenSize,
//         .vScreenCenter = (float)vScreenCenter,
//         .eyeToScreenDistance = (float)eyeToScreenDistance,
//         .lensSeparationDistance = (float)lensSeparationDistance,
//         .interpupillaryDistance = (float)interpupillaryDistance,
//         .lensDistortionValues = /*cast float[4] to_lean?false*/(lensDistortionValues),
//         .chromaAbCorrection = /*cast float[4] to_lean?false*/(chromaAbCorrection)
//     );
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__VrDeviceInfo_hResolution(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_VrDeviceInfo_from(obj)->hResolution;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_hResolution_set(uint32_t hResolution, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->hResolution = hResolution;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__VrDeviceInfo_vResolution(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_VrDeviceInfo_from(obj)->vResolution;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_vResolution_set(uint32_t vResolution, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->vResolution = vResolution;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_hScreenSize(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->hScreenSize;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_hScreenSize_set(double hScreenSize, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->hScreenSize = (float)hScreenSize;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_vScreenSize(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->vScreenSize;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_vScreenSize_set(double vScreenSize, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->vScreenSize = (float)vScreenSize;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_vScreenCenter(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->vScreenCenter;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_vScreenCenter_set(double vScreenCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->vScreenCenter = (float)vScreenCenter;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_eyeToScreenDistance(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->eyeToScreenDistance;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_eyeToScreenDistance_set(double eyeToScreenDistance, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->eyeToScreenDistance = (float)eyeToScreenDistance;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_lensSeparationDistance(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->lensSeparationDistance;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_lensSeparationDistance_set(double lensSeparationDistance, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->lensSeparationDistance = (float)lensSeparationDistance;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_interpupillaryDistance(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->interpupillaryDistance;
//     return (double)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_interpupillaryDistance_set(double interpupillaryDistance, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->interpupillaryDistance = (float)interpupillaryDistance;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT /*float[4]*/lean_obj_arg lean_raylib__VrDeviceInfo_lensDistortionValues(b_lean_obj_arg obj) {
//     float[4] result_ = lean_raylib_VrDeviceInfo_from(obj)->lensDistortionValues;
//     return /*cast float[4] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_lensDistortionValues_set(/*float[4]*/lean_obj_arg lensDistortionValues, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->lensDistortionValues = /*cast float[4] to_lean?false*/(lensDistortionValues);
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT /*float[4]*/lean_obj_arg lean_raylib__VrDeviceInfo_chromaAbCorrection(b_lean_obj_arg obj) {
//     float[4] result_ = lean_raylib_VrDeviceInfo_from(obj)->chromaAbCorrection;
//     return /*cast float[4] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrDeviceInfo_chromaAbCorrection_set(/*float[4]*/lean_obj_arg chromaAbCorrection, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->chromaAbCorrection = /*cast float[4] to_lean?false*/(chromaAbCorrection);
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_mk(/*Matrix[2]*/lean_obj_arg projection, /*Matrix[2]*/lean_obj_arg viewOffset, /*float[2]*/lean_obj_arg leftLensCenter, /*float[2]*/lean_obj_arg rightLensCenter, /*float[2]*/lean_obj_arg leftScreenCenter, /*float[2]*/lean_obj_arg rightScreenCenter, /*float[2]*/lean_obj_arg scale, /*float[2]*/lean_obj_arg scaleIn) {
//     LET_BOX_STRUCT(VrStereoConfig, result_,
//         .projection = /*cast Matrix[2] to_lean?false*/(projection),
//         .viewOffset = /*cast Matrix[2] to_lean?false*/(viewOffset),
//         .leftLensCenter = /*cast float[2] to_lean?false*/(leftLensCenter),
//         .rightLensCenter = /*cast float[2] to_lean?false*/(rightLensCenter),
//         .leftScreenCenter = /*cast float[2] to_lean?false*/(leftScreenCenter),
//         .rightScreenCenter = /*cast float[2] to_lean?false*/(rightScreenCenter),
//         .scale = /*cast float[2] to_lean?false*/(scale),
//         .scaleIn = /*cast float[2] to_lean?false*/(scaleIn)
//     );
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*Matrix[2]*/lean_obj_arg lean_raylib__VrStereoConfig_projection(b_lean_obj_arg obj) {
//     Matrix[2] result_ = lean_raylib_VrStereoConfig_from(obj)->projection;
//     return /*cast Matrix[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_projection_set(/*Matrix[2]*/lean_obj_arg projection, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->projection = /*cast Matrix[2] to_lean?false*/(projection);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*Matrix[2]*/lean_obj_arg lean_raylib__VrStereoConfig_viewOffset(b_lean_obj_arg obj) {
//     Matrix[2] result_ = lean_raylib_VrStereoConfig_from(obj)->viewOffset;
//     return /*cast Matrix[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_viewOffset_set(/*Matrix[2]*/lean_obj_arg viewOffset, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->viewOffset = /*cast Matrix[2] to_lean?false*/(viewOffset);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_leftLensCenter(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->leftLensCenter;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_leftLensCenter_set(/*float[2]*/lean_obj_arg leftLensCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->leftLensCenter = /*cast float[2] to_lean?false*/(leftLensCenter);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_rightLensCenter(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->rightLensCenter;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_rightLensCenter_set(/*float[2]*/lean_obj_arg rightLensCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->rightLensCenter = /*cast float[2] to_lean?false*/(rightLensCenter);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_leftScreenCenter(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->leftScreenCenter;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_leftScreenCenter_set(/*float[2]*/lean_obj_arg leftScreenCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->leftScreenCenter = /*cast float[2] to_lean?false*/(leftScreenCenter);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_rightScreenCenter(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->rightScreenCenter;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_rightScreenCenter_set(/*float[2]*/lean_obj_arg rightScreenCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->rightScreenCenter = /*cast float[2] to_lean?false*/(rightScreenCenter);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_scale(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->scale;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_scale_set(/*float[2]*/lean_obj_arg scale, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->scale = /*cast float[2] to_lean?false*/(scale);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_scaleIn(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->scaleIn;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__VrStereoConfig_scaleIn_set(/*float[2]*/lean_obj_arg scaleIn, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->scaleIn = /*cast float[2] to_lean?false*/(scaleIn);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__FilePathList_mk(uint32_t capacity, uint32_t count, /* char ** */lean_obj_arg paths) {
//     LET_BOX_STRUCT(FilePathList, result_,
//         .capacity = capacity,
//         .count = count,
//         .paths = /*todo: ptr?*/paths
//     );
//     return lean_raylib_FilePathList_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__FilePathList_capacity(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_FilePathList_from(obj)->capacity;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__FilePathList_capacity_set(uint32_t capacity, b_lean_obj_arg obj) {
//     LET_BOX(FilePathList, result_, *lean_raylib_FilePathList_from(obj));
//     result_->capacity = capacity;
//     return lean_raylib_FilePathList_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__FilePathList_count(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_FilePathList_from(obj)->count;
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__FilePathList_count_set(uint32_t count, b_lean_obj_arg obj) {
//     LET_BOX(FilePathList, result_, *lean_raylib_FilePathList_from(obj));
//     result_->count = count;
//     return lean_raylib_FilePathList_to(result_);
// }

// LEAN_EXPORT /* char ** */lean_obj_arg lean_raylib__FilePathList_paths(b_lean_obj_arg obj) {
//     char * * result_ = lean_raylib_FilePathList_from(obj)->paths;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__FilePathList_paths_set(/* char ** */lean_obj_arg paths, b_lean_obj_arg obj) {
//     LET_BOX(FilePathList, result_, *lean_raylib_FilePathList_from(obj));
//     result_->paths = /*todo: ptr?*/paths;
//     return lean_raylib_FilePathList_to(result_);
// }
