#include "util.h"
#include "structures.h"


// # Vectors

// ## Vector2

LEAN_EXPORT lean_object* lean_raylib__Vector2_mk(double x, double y) {
    LET_BOX_STRUCT(Vector2, result_,
        .x = (float)x,
        .y = (float)y
    );
    return lean_raylib_Vector2_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector2_x(b_lean_obj_arg obj) {
    return lean_raylib_Vector2_from(obj)->x;
}

LEAN_EXPORT lean_object* lean_raylib__Vector2_x_set(double x, b_lean_obj_arg obj) {
    Vector2 const* obj_c = lean_raylib_Vector2_from(obj);
    LET_BOX_STRUCT(Vector2, result_,
        .x = x,
        .y = obj_c->y,
    );
    return lean_raylib_Vector2_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector2_y(b_lean_obj_arg obj) {
    return lean_raylib_Vector2_from(obj)->y;
}

LEAN_EXPORT lean_object* lean_raylib__Vector2_y_set(double y, b_lean_obj_arg obj) {
    Vector2 const* obj_c = lean_raylib_Vector2_from(obj);
    LET_BOX_STRUCT(Vector2, result_,
        .x = obj_c->x,
        .y = y,
    );
    return lean_raylib_Vector2_to(result_);
}


// ## Vector3

LEAN_EXPORT lean_object* lean_raylib__Vector3_mk(double x, double y, double z) {
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

LEAN_EXPORT lean_object* lean_raylib__Vector3_x_set(double x, b_lean_obj_arg obj) {
    Vector3 const* obj_c = lean_raylib_Vector3_from(obj);
    LET_BOX_STRUCT(Vector3, result_,
        .x = x,
        .y = obj_c->y,
        .z = obj_c->z,
    );
    return lean_raylib_Vector3_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector3_y(b_lean_obj_arg obj) {
    return lean_raylib_Vector3_from(obj)->y;
}

LEAN_EXPORT lean_object* lean_raylib__Vector3_y_set(double y, b_lean_obj_arg obj) {
    Vector3 const* obj_c = lean_raylib_Vector3_from(obj);
    LET_BOX_STRUCT(Vector3, result_,
        .x = obj_c->x,
        .y = y,
        .z = obj_c->z,
    );
    return lean_raylib_Vector3_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector3_z(b_lean_obj_arg obj) {
    return lean_raylib_Vector3_from(obj)->z;
}

LEAN_EXPORT lean_object* lean_raylib__Vector3_z_set(double z, b_lean_obj_arg obj) {
    Vector3 const* obj_c = lean_raylib_Vector3_from(obj);
    LET_BOX_STRUCT(Vector3, result_,
        .x = obj_c->x,
        .y = obj_c->y,
        .z = z,
    );
    return lean_raylib_Vector3_to(result_);
}


// ## Vector4

LEAN_EXPORT lean_object* lean_raylib__Vector4_mk(double x, double y, double z, double w) {
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

LEAN_EXPORT lean_object* lean_raylib__Vector4_x_set(double x, b_lean_obj_arg obj) {
    Vector4 const* obj_c = lean_raylib_Vector4_from(obj);
    LET_BOX_STRUCT(Vector4, result_,
        .x = x,
        .y = obj_c->y,
        .z = obj_c->z,
        .w = obj_c->w
    );
    return lean_raylib_Vector4_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector4_y(b_lean_obj_arg obj) {
    return lean_raylib_Vector4_from(obj)->y;
}

LEAN_EXPORT lean_object* lean_raylib__Vector4_y_set(double y, b_lean_obj_arg obj) {
    Vector4 const* obj_c = lean_raylib_Vector4_from(obj);
    LET_BOX_STRUCT(Vector4, result_,
        .x = obj_c->x,
        .y = y,
        .z = obj_c->z,
        .w = obj_c->w,
    );
    return lean_raylib_Vector4_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector4_z(b_lean_obj_arg obj) {
    return lean_raylib_Vector4_from(obj)->z;
}

LEAN_EXPORT lean_object* lean_raylib__Vector4_z_set(double z, b_lean_obj_arg obj) {
    Vector4 const* obj_c = lean_raylib_Vector4_from(obj);
    LET_BOX_STRUCT(Vector4, result_,
        .x = obj_c->x,
        .y = obj_c->y,
        .z = z,
        .w = obj_c->w,
    );
    return lean_raylib_Vector4_to(result_);
}

LEAN_EXPORT double lean_raylib__Vector4_w(b_lean_obj_arg obj) {
    return lean_raylib_Vector4_from(obj)->w;
}

LEAN_EXPORT lean_object* lean_raylib__Vector4_w_set(double w, b_lean_obj_arg obj) {
    Vector4 const* obj_c = lean_raylib_Vector4_from(obj);
    LET_BOX_STRUCT(Vector4, result_,
        .x = obj_c->x,
        .y = obj_c->y,
        .z = obj_c->z,
        .w = w,
    );
    return lean_raylib_Vector4_to(result_);
}


// # Matrices

// LEAN_EXPORT lean_object* lean_raylib__Matrix_mk(double m0, double m4, double m8, double m12, double m1, double m5, double m9, double m13, double m2, double m6, double m10, double m14, double m3, double m7, double m11, double m15) {
//     LET_BOX_STRUCT(Matrix, result_,
//         .m0 = (float)m0,
//         .m4 = (float)m4,
//         .m8 = (float)m8,
//         .m12 = (float)m12,
//         .m1 = (float)m1,
//         .m5 = (float)m5,
//         .m9 = (float)m9,
//         .m13 = (float)m13,
//         .m2 = (float)m2,
//         .m6 = (float)m6,
//         .m10 = (float)m10,
//         .m14 = (float)m14,
//         .m3 = (float)m3,
//         .m7 = (float)m7,
//         .m11 = (float)m11,
//         .m15 = (float)m15
//     );
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m0(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m0;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m0_set(double m0, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m0 = (float)m0;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m4(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m4;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m4_set(double m4, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m4 = (float)m4;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m8(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m8;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m8_set(double m8, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m8 = (float)m8;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m12(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m12;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m12_set(double m12, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m12 = (float)m12;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m1(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m1;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m1_set(double m1, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m1 = (float)m1;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m5(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m5;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m5_set(double m5, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m5 = (float)m5;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m9(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m9;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m9_set(double m9, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m9 = (float)m9;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m13(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m13;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m13_set(double m13, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m13 = (float)m13;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m2(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m2;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m2_set(double m2, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m2 = (float)m2;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m6(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m6;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m6_set(double m6, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m6 = (float)m6;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m10(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m10;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m10_set(double m10, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m10 = (float)m10;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m14(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m14;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m14_set(double m14, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m14 = (float)m14;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m3(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m3;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m3_set(double m3, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m3 = (float)m3;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m7(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m7;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m7_set(double m7, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m7 = (float)m7;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m11(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m11;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m11_set(double m11, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m11 = (float)m11;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Matrix_m15(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Matrix_from(obj)->m15;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Matrix_m15_set(double m15, b_lean_obj_arg obj) {
//     LET_BOX(Matrix, result_, *lean_raylib_Matrix_from(obj));
//     result_->m15 = (float)m15;
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Rectangle_mk(double x, double y, double width, double height) {
//     LET_BOX_STRUCT(Rectangle, result_,
//         .x = (float)x,
//         .y = (float)y,
//         .width = (float)width,
//         .height = (float)height
//     );
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Rectangle_x(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Rectangle_from(obj)->x;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Rectangle_x_set(double x, b_lean_obj_arg obj) {
//     LET_BOX(Rectangle, result_, *lean_raylib_Rectangle_from(obj));
//     result_->x = (float)x;
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Rectangle_y(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Rectangle_from(obj)->y;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Rectangle_y_set(double y, b_lean_obj_arg obj) {
//     LET_BOX(Rectangle, result_, *lean_raylib_Rectangle_from(obj));
//     result_->y = (float)y;
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Rectangle_width(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Rectangle_from(obj)->width;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Rectangle_width_set(double width, b_lean_obj_arg obj) {
//     LET_BOX(Rectangle, result_, *lean_raylib_Rectangle_from(obj));
//     result_->width = (float)width;
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Rectangle_height(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Rectangle_from(obj)->height;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Rectangle_height_set(double height, b_lean_obj_arg obj) {
//     LET_BOX(Rectangle, result_, *lean_raylib_Rectangle_from(obj));
//     result_->height = (float)height;
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Image_mk(/* void* */lean_obj_arg data, uint32_t width, uint32_t height, uint32_t mipmaps, uint32_t format) {
//     LET_BOX_STRUCT(Image, result_,
//         .data = /*todo: ptr?*/data,
//         .width = width,
//         .height = height,
//         .mipmaps = mipmaps,
//         .format = format
//     );
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__Image_data(b_lean_obj_arg obj) {
//     void * result_ = lean_raylib_Image_from(obj)->data;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Image_data_set(/* void* */lean_obj_arg data, b_lean_obj_arg obj) {
//     LET_BOX(Image, result_, *lean_raylib_Image_from(obj));
//     result_->data = /*todo: ptr?*/data;
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Image_width(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Image_from(obj)->width;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Image_width_set(uint32_t width, b_lean_obj_arg obj) {
//     LET_BOX(Image, result_, *lean_raylib_Image_from(obj));
//     result_->width = width;
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Image_height(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Image_from(obj)->height;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Image_height_set(uint32_t height, b_lean_obj_arg obj) {
//     LET_BOX(Image, result_, *lean_raylib_Image_from(obj));
//     result_->height = height;
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Image_mipmaps(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Image_from(obj)->mipmaps;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Image_mipmaps_set(uint32_t mipmaps, b_lean_obj_arg obj) {
//     LET_BOX(Image, result_, *lean_raylib_Image_from(obj));
//     result_->mipmaps = mipmaps;
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Image_format(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Image_from(obj)->format;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Image_format_set(uint32_t format, b_lean_obj_arg obj) {
//     LET_BOX(Image, result_, *lean_raylib_Image_from(obj));
//     result_->format = format;
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Texture_mk(uint32_t id, uint32_t width, uint32_t height, uint32_t mipmaps, uint32_t format) {
//     LET_BOX_STRUCT(Texture, result_,
//         .id = id,
//         .width = width,
//         .height = height,
//         .mipmaps = mipmaps,
//         .format = format
//     );
//     return lean_raylib_Texture_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Texture_id(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Texture_from(obj)->id;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Texture_id_set(uint32_t id, b_lean_obj_arg obj) {
//     LET_BOX(Texture, result_, *lean_raylib_Texture_from(obj));
//     result_->id = id;
//     return lean_raylib_Texture_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Texture_width(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Texture_from(obj)->width;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Texture_width_set(uint32_t width, b_lean_obj_arg obj) {
//     LET_BOX(Texture, result_, *lean_raylib_Texture_from(obj));
//     result_->width = width;
//     return lean_raylib_Texture_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Texture_height(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Texture_from(obj)->height;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Texture_height_set(uint32_t height, b_lean_obj_arg obj) {
//     LET_BOX(Texture, result_, *lean_raylib_Texture_from(obj));
//     result_->height = height;
//     return lean_raylib_Texture_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Texture_mipmaps(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Texture_from(obj)->mipmaps;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Texture_mipmaps_set(uint32_t mipmaps, b_lean_obj_arg obj) {
//     LET_BOX(Texture, result_, *lean_raylib_Texture_from(obj));
//     result_->mipmaps = mipmaps;
//     return lean_raylib_Texture_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Texture_format(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Texture_from(obj)->format;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Texture_format_set(uint32_t format, b_lean_obj_arg obj) {
//     LET_BOX(Texture, result_, *lean_raylib_Texture_from(obj));
//     result_->format = format;
//     return lean_raylib_Texture_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__RenderTexture_mk(uint32_t id, lean_obj_arg texture, lean_obj_arg depth) {
//     LET_BOX_STRUCT(RenderTexture, result_,
//         .id = id,
//         .texture = lean_raylib_Texture_from(texture),
//         .depth = lean_raylib_Texture_from(depth)
//     );
//     return lean_raylib_RenderTexture_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__RenderTexture_id(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_RenderTexture_from(obj)->id;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__RenderTexture_id_set(uint32_t id, b_lean_obj_arg obj) {
//     LET_BOX(RenderTexture, result_, *lean_raylib_RenderTexture_from(obj));
//     result_->id = id;
//     return lean_raylib_RenderTexture_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__RenderTexture_texture(b_lean_obj_arg obj) {
//     Texture result_ = lean_raylib_RenderTexture_from(obj)->texture;
//     return lean_raylib_Texture_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__RenderTexture_texture_set(lean_obj_arg texture, b_lean_obj_arg obj) {
//     LET_BOX(RenderTexture, result_, *lean_raylib_RenderTexture_from(obj));
//     result_->texture = lean_raylib_Texture_from(texture);
//     return lean_raylib_RenderTexture_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__RenderTexture_depth(b_lean_obj_arg obj) {
//     Texture result_ = lean_raylib_RenderTexture_from(obj)->depth;
//     return lean_raylib_Texture_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__RenderTexture_depth_set(lean_obj_arg depth, b_lean_obj_arg obj) {
//     LET_BOX(RenderTexture, result_, *lean_raylib_RenderTexture_from(obj));
//     result_->depth = lean_raylib_Texture_from(depth);
//     return lean_raylib_RenderTexture_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__NPatchInfo_mk(lean_obj_arg source, uint32_t left, uint32_t top, uint32_t right, uint32_t bottom, uint32_t layout) {
//     LET_BOX_STRUCT(NPatchInfo, result_,
//         .source = lean_raylib_Rectangle_from(source),
//         .left = left,
//         .top = top,
//         .right = right,
//         .bottom = bottom,
//         .layout = layout
//     );
//     return lean_raylib_NPatchInfo_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__NPatchInfo_source(b_lean_obj_arg obj) {
//     Rectangle result_ = lean_raylib_NPatchInfo_from(obj)->source;
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__NPatchInfo_source_set(lean_obj_arg source, b_lean_obj_arg obj) {
//     LET_BOX(NPatchInfo, result_, *lean_raylib_NPatchInfo_from(obj));
//     result_->source = lean_raylib_Rectangle_from(source);
//     return lean_raylib_NPatchInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_left(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_NPatchInfo_from(obj)->left;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__NPatchInfo_left_set(uint32_t left, b_lean_obj_arg obj) {
//     LET_BOX(NPatchInfo, result_, *lean_raylib_NPatchInfo_from(obj));
//     result_->left = left;
//     return lean_raylib_NPatchInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_top(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_NPatchInfo_from(obj)->top;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__NPatchInfo_top_set(uint32_t top, b_lean_obj_arg obj) {
//     LET_BOX(NPatchInfo, result_, *lean_raylib_NPatchInfo_from(obj));
//     result_->top = top;
//     return lean_raylib_NPatchInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_right(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_NPatchInfo_from(obj)->right;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__NPatchInfo_right_set(uint32_t right, b_lean_obj_arg obj) {
//     LET_BOX(NPatchInfo, result_, *lean_raylib_NPatchInfo_from(obj));
//     result_->right = right;
//     return lean_raylib_NPatchInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_bottom(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_NPatchInfo_from(obj)->bottom;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__NPatchInfo_bottom_set(uint32_t bottom, b_lean_obj_arg obj) {
//     LET_BOX(NPatchInfo, result_, *lean_raylib_NPatchInfo_from(obj));
//     result_->bottom = bottom;
//     return lean_raylib_NPatchInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__NPatchInfo_layout(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_NPatchInfo_from(obj)->layout;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__NPatchInfo_layout_set(uint32_t layout, b_lean_obj_arg obj) {
//     LET_BOX(NPatchInfo, result_, *lean_raylib_NPatchInfo_from(obj));
//     result_->layout = layout;
//     return lean_raylib_NPatchInfo_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__GlyphInfo_mk(uint32_t value, uint32_t offsetX, uint32_t offsetY, uint32_t advanceX, lean_obj_arg image) {
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

// LEAN_EXPORT lean_object* lean_raylib__GlyphInfo_value_set(uint32_t value, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->value = value;
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GlyphInfo_offsetX(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_GlyphInfo_from(obj)->offsetX;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__GlyphInfo_offsetX_set(uint32_t offsetX, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->offsetX = offsetX;
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GlyphInfo_offsetY(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_GlyphInfo_from(obj)->offsetY;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__GlyphInfo_offsetY_set(uint32_t offsetY, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->offsetY = offsetY;
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GlyphInfo_advanceX(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_GlyphInfo_from(obj)->advanceX;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__GlyphInfo_advanceX_set(uint32_t advanceX, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->advanceX = advanceX;
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GlyphInfo_image(b_lean_obj_arg obj) {
//     Image result_ = lean_raylib_GlyphInfo_from(obj)->image;
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__GlyphInfo_image_set(lean_obj_arg image, b_lean_obj_arg obj) {
//     LET_BOX(GlyphInfo, result_, *lean_raylib_GlyphInfo_from(obj));
//     result_->image = lean_raylib_Image_from(image);
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Font_mk(uint32_t baseSize, uint32_t glyphCount, uint32_t glyphPadding, lean_obj_arg texture, /* Rectangle* */lean_obj_arg recs, /* GlyphInfo* */lean_obj_arg glyphs) {
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

// LEAN_EXPORT lean_object* lean_raylib__Font_baseSize_set(uint32_t baseSize, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->baseSize = baseSize;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Font_glyphCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Font_from(obj)->glyphCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Font_glyphCount_set(uint32_t glyphCount, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->glyphCount = glyphCount;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Font_glyphPadding(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Font_from(obj)->glyphPadding;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Font_glyphPadding_set(uint32_t glyphPadding, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->glyphPadding = glyphPadding;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Font_texture(b_lean_obj_arg obj) {
//     Texture2D result_ = lean_raylib_Font_from(obj)->texture;
//     return /*cast Texture2D to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Font_texture_set(lean_obj_arg texture, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->texture = /*cast Texture2D to_lean?false*/(texture);
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT /* Rectangle* */lean_obj_arg lean_raylib__Font_recs(b_lean_obj_arg obj) {
//     Rectangle * result_ = lean_raylib_Font_from(obj)->recs;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Font_recs_set(/* Rectangle* */lean_obj_arg recs, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->recs = /*todo: ptr?*/recs;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT /* GlyphInfo* */lean_obj_arg lean_raylib__Font_glyphs(b_lean_obj_arg obj) {
//     GlyphInfo * result_ = lean_raylib_Font_from(obj)->glyphs;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Font_glyphs_set(/* GlyphInfo* */lean_obj_arg glyphs, b_lean_obj_arg obj) {
//     LET_BOX(Font, result_, *lean_raylib_Font_from(obj));
//     result_->glyphs = /*todo: ptr?*/glyphs;
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera3D_mk(lean_obj_arg position, lean_obj_arg target, lean_obj_arg up, double fovy, uint32_t projection) {
//     LET_BOX_STRUCT(Camera3D, result_,
//         .position = lean_raylib_Vector3_from(position),
//         .target = lean_raylib_Vector3_from(target),
//         .up = lean_raylib_Vector3_from(up),
//         .fovy = (float)fovy,
//         .projection = projection
//     );
//     return lean_raylib_Camera3D_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Camera3D_position(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_Camera3D_from(obj)->position;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera3D_position_set(lean_obj_arg position, b_lean_obj_arg obj) {
//     LET_BOX(Camera3D, result_, *lean_raylib_Camera3D_from(obj));
//     result_->position = lean_raylib_Vector3_from(position);
//     return lean_raylib_Camera3D_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Camera3D_target(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_Camera3D_from(obj)->target;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera3D_target_set(lean_obj_arg target, b_lean_obj_arg obj) {
//     LET_BOX(Camera3D, result_, *lean_raylib_Camera3D_from(obj));
//     result_->target = lean_raylib_Vector3_from(target);
//     return lean_raylib_Camera3D_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Camera3D_up(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_Camera3D_from(obj)->up;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera3D_up_set(lean_obj_arg up, b_lean_obj_arg obj) {
//     LET_BOX(Camera3D, result_, *lean_raylib_Camera3D_from(obj));
//     result_->up = lean_raylib_Vector3_from(up);
//     return lean_raylib_Camera3D_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Camera3D_fovy(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Camera3D_from(obj)->fovy;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera3D_fovy_set(double fovy, b_lean_obj_arg obj) {
//     LET_BOX(Camera3D, result_, *lean_raylib_Camera3D_from(obj));
//     result_->fovy = (float)fovy;
//     return lean_raylib_Camera3D_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Camera3D_projection(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Camera3D_from(obj)->projection;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera3D_projection_set(uint32_t projection, b_lean_obj_arg obj) {
//     LET_BOX(Camera3D, result_, *lean_raylib_Camera3D_from(obj));
//     result_->projection = projection;
//     return lean_raylib_Camera3D_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera2D_mk(lean_obj_arg offset, lean_obj_arg target, double rotation, double zoom) {
//     LET_BOX_STRUCT(Camera2D, result_,
//         .offset = lean_raylib_Vector2_from(offset),
//         .target = lean_raylib_Vector2_from(target),
//         .rotation = (float)rotation,
//         .zoom = (float)zoom
//     );
//     return lean_raylib_Camera2D_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Camera2D_offset(b_lean_obj_arg obj) {
//     Vector2 result_ = lean_raylib_Camera2D_from(obj)->offset;
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera2D_offset_set(lean_obj_arg offset, b_lean_obj_arg obj) {
//     LET_BOX(Camera2D, result_, *lean_raylib_Camera2D_from(obj));
//     result_->offset = lean_raylib_Vector2_from(offset);
//     return lean_raylib_Camera2D_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Camera2D_target(b_lean_obj_arg obj) {
//     Vector2 result_ = lean_raylib_Camera2D_from(obj)->target;
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera2D_target_set(lean_obj_arg target, b_lean_obj_arg obj) {
//     LET_BOX(Camera2D, result_, *lean_raylib_Camera2D_from(obj));
//     result_->target = lean_raylib_Vector2_from(target);
//     return lean_raylib_Camera2D_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Camera2D_rotation(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Camera2D_from(obj)->rotation;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera2D_rotation_set(double rotation, b_lean_obj_arg obj) {
//     LET_BOX(Camera2D, result_, *lean_raylib_Camera2D_from(obj));
//     result_->rotation = (float)rotation;
//     return lean_raylib_Camera2D_to(result_);
// }

// LEAN_EXPORT double lean_raylib__Camera2D_zoom(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_Camera2D_from(obj)->zoom;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Camera2D_zoom_set(double zoom, b_lean_obj_arg obj) {
//     LET_BOX(Camera2D, result_, *lean_raylib_Camera2D_from(obj));
//     result_->zoom = (float)zoom;
//     return lean_raylib_Camera2D_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_mk(uint32_t vertexCount, uint32_t triangleCount, /* float* */lean_obj_arg vertices, /* float* */lean_obj_arg texcoords, /* float* */lean_obj_arg texcoords2, /* float* */lean_obj_arg normals, /* float* */lean_obj_arg tangents, /* unsigned char* */lean_obj_arg colors, /* unsigned short* */lean_obj_arg indices, /* float* */lean_obj_arg animVertices, /* float* */lean_obj_arg animNormals, /* unsigned char* */lean_obj_arg boneIds, /* float* */lean_obj_arg boneWeights, uint32_t vaoId, /* unsigned int* */lean_obj_arg vboId) {
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

// LEAN_EXPORT lean_object* lean_raylib__Mesh_vertexCount_set(uint32_t vertexCount, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->vertexCount = vertexCount;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Mesh_triangleCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Mesh_from(obj)->triangleCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_triangleCount_set(uint32_t triangleCount, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->triangleCount = triangleCount;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_vertices(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->vertices;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_vertices_set(/* float* */lean_obj_arg vertices, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->vertices = /*todo: ptr?*/vertices;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_texcoords(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->texcoords;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_texcoords_set(/* float* */lean_obj_arg texcoords, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->texcoords = /*todo: ptr?*/texcoords;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_texcoords2(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->texcoords2;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_texcoords2_set(/* float* */lean_obj_arg texcoords2, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->texcoords2 = /*todo: ptr?*/texcoords2;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_normals(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->normals;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_normals_set(/* float* */lean_obj_arg normals, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->normals = /*todo: ptr?*/normals;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_tangents(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->tangents;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_tangents_set(/* float* */lean_obj_arg tangents, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->tangents = /*todo: ptr?*/tangents;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* unsigned char* */lean_obj_arg lean_raylib__Mesh_colors(b_lean_obj_arg obj) {
//     unsigned char * result_ = lean_raylib_Mesh_from(obj)->colors;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_colors_set(/* unsigned char* */lean_obj_arg colors, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->colors = /*todo: ptr?*/colors;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* unsigned short* */lean_obj_arg lean_raylib__Mesh_indices(b_lean_obj_arg obj) {
//     unsigned short * result_ = lean_raylib_Mesh_from(obj)->indices;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_indices_set(/* unsigned short* */lean_obj_arg indices, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->indices = /*todo: ptr?*/indices;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_animVertices(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->animVertices;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_animVertices_set(/* float* */lean_obj_arg animVertices, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->animVertices = /*todo: ptr?*/animVertices;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_animNormals(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->animNormals;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_animNormals_set(/* float* */lean_obj_arg animNormals, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->animNormals = /*todo: ptr?*/animNormals;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* unsigned char* */lean_obj_arg lean_raylib__Mesh_boneIds(b_lean_obj_arg obj) {
//     unsigned char * result_ = lean_raylib_Mesh_from(obj)->boneIds;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_boneIds_set(/* unsigned char* */lean_obj_arg boneIds, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->boneIds = /*todo: ptr?*/boneIds;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__Mesh_boneWeights(b_lean_obj_arg obj) {
//     float * result_ = lean_raylib_Mesh_from(obj)->boneWeights;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_boneWeights_set(/* float* */lean_obj_arg boneWeights, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->boneWeights = /*todo: ptr?*/boneWeights;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Mesh_vaoId(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Mesh_from(obj)->vaoId;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_vaoId_set(uint32_t vaoId, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->vaoId = vaoId;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* unsigned int* */lean_obj_arg lean_raylib__Mesh_vboId(b_lean_obj_arg obj) {
//     unsigned int * result_ = lean_raylib_Mesh_from(obj)->vboId;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Mesh_vboId_set(/* unsigned int* */lean_obj_arg vboId, b_lean_obj_arg obj) {
//     LET_BOX(Mesh, result_, *lean_raylib_Mesh_from(obj));
//     result_->vboId = /*todo: ptr?*/vboId;
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Shader_mk(uint32_t id, /* int* */lean_obj_arg locs) {
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

// LEAN_EXPORT lean_object* lean_raylib__Shader_id_set(uint32_t id, b_lean_obj_arg obj) {
//     LET_BOX(Shader, result_, *lean_raylib_Shader_from(obj));
//     result_->id = id;
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT /* int* */lean_obj_arg lean_raylib__Shader_locs(b_lean_obj_arg obj) {
//     int * result_ = lean_raylib_Shader_from(obj)->locs;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Shader_locs_set(/* int* */lean_obj_arg locs, b_lean_obj_arg obj) {
//     LET_BOX(Shader, result_, *lean_raylib_Shader_from(obj));
//     result_->locs = /*todo: ptr?*/locs;
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__MaterialMap_mk(lean_obj_arg texture, uint32_t color, double value) {
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

// LEAN_EXPORT lean_object* lean_raylib__MaterialMap_texture_set(lean_obj_arg texture, b_lean_obj_arg obj) {
//     LET_BOX(MaterialMap, result_, *lean_raylib_MaterialMap_from(obj));
//     result_->texture = /*cast Texture2D to_lean?false*/(texture);
//     return lean_raylib_MaterialMap_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__MaterialMap_color(b_lean_obj_arg obj) {
//     Color result_ = lean_raylib_MaterialMap_from(obj)->color;
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__MaterialMap_color_set(uint32_t color, b_lean_obj_arg obj) {
//     LET_BOX(MaterialMap, result_, *lean_raylib_MaterialMap_from(obj));
//     result_->color = lean_raylib_Color_from(color);
//     return lean_raylib_MaterialMap_to(result_);
// }

// LEAN_EXPORT double lean_raylib__MaterialMap_value(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_MaterialMap_from(obj)->value;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__MaterialMap_value_set(double value, b_lean_obj_arg obj) {
//     LET_BOX(MaterialMap, result_, *lean_raylib_MaterialMap_from(obj));
//     result_->value = (float)value;
//     return lean_raylib_MaterialMap_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Material_mk(lean_obj_arg shader, /* MaterialMap* */lean_obj_arg maps, /*float[4]*/lean_obj_arg params) {
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

// LEAN_EXPORT lean_object* lean_raylib__Material_shader_set(lean_obj_arg shader, b_lean_obj_arg obj) {
//     LET_BOX(Material, result_, *lean_raylib_Material_from(obj));
//     result_->shader = lean_raylib_Shader_from(shader);
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT /* MaterialMap* */lean_obj_arg lean_raylib__Material_maps(b_lean_obj_arg obj) {
//     MaterialMap * result_ = lean_raylib_Material_from(obj)->maps;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Material_maps_set(/* MaterialMap* */lean_obj_arg maps, b_lean_obj_arg obj) {
//     LET_BOX(Material, result_, *lean_raylib_Material_from(obj));
//     result_->maps = /*todo: ptr?*/maps;
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT /*float[4]*/lean_obj_arg lean_raylib__Material_params(b_lean_obj_arg obj) {
//     float[4] result_ = lean_raylib_Material_from(obj)->params;
//     return /*cast float[4] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Material_params_set(/*float[4]*/lean_obj_arg params, b_lean_obj_arg obj) {
//     LET_BOX(Material, result_, *lean_raylib_Material_from(obj));
//     result_->params = /*cast float[4] to_lean?false*/(params);
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Transform_mk(lean_obj_arg translation, lean_obj_arg rotation, lean_obj_arg scale) {
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

// LEAN_EXPORT lean_object* lean_raylib__Transform_translation_set(lean_obj_arg translation, b_lean_obj_arg obj) {
//     LET_BOX(Transform, result_, *lean_raylib_Transform_from(obj));
//     result_->translation = lean_raylib_Vector3_from(translation);
//     return lean_raylib_Transform_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Transform_rotation(b_lean_obj_arg obj) {
//     Quaternion result_ = lean_raylib_Transform_from(obj)->rotation;
//     return /*cast Quaternion to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Transform_rotation_set(lean_obj_arg rotation, b_lean_obj_arg obj) {
//     LET_BOX(Transform, result_, *lean_raylib_Transform_from(obj));
//     result_->rotation = /*cast Quaternion to_lean?false*/(rotation);
//     return lean_raylib_Transform_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Transform_scale(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_Transform_from(obj)->scale;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Transform_scale_set(lean_obj_arg scale, b_lean_obj_arg obj) {
//     LET_BOX(Transform, result_, *lean_raylib_Transform_from(obj));
//     result_->scale = lean_raylib_Vector3_from(scale);
//     return lean_raylib_Transform_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__BoneInfo_mk(/*char[32]*/lean_obj_arg name, uint32_t parent) {
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

// LEAN_EXPORT lean_object* lean_raylib__BoneInfo_name_set(/*char[32]*/lean_obj_arg name, b_lean_obj_arg obj) {
//     LET_BOX(BoneInfo, result_, *lean_raylib_BoneInfo_from(obj));
//     result_->name = /*cast char[32] to_lean?false*/(name);
//     return lean_raylib_BoneInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__BoneInfo_parent(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_BoneInfo_from(obj)->parent;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__BoneInfo_parent_set(uint32_t parent, b_lean_obj_arg obj) {
//     LET_BOX(BoneInfo, result_, *lean_raylib_BoneInfo_from(obj));
//     result_->parent = parent;
//     return lean_raylib_BoneInfo_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_mk(lean_obj_arg transform, uint32_t meshCount, uint32_t materialCount, /* Mesh* */lean_obj_arg meshes, /* Material* */lean_obj_arg materials, /* int* */lean_obj_arg meshMaterial, uint32_t boneCount, /* BoneInfo* */lean_obj_arg bones, /* Transform* */lean_obj_arg bindPose) {
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

// LEAN_EXPORT lean_object* lean_raylib__Model_transform_set(lean_obj_arg transform, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->transform = lean_raylib_Matrix_from(transform);
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Model_meshCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Model_from(obj)->meshCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_meshCount_set(uint32_t meshCount, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->meshCount = meshCount;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Model_materialCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Model_from(obj)->materialCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_materialCount_set(uint32_t materialCount, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->materialCount = materialCount;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* Mesh* */lean_obj_arg lean_raylib__Model_meshes(b_lean_obj_arg obj) {
//     Mesh * result_ = lean_raylib_Model_from(obj)->meshes;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_meshes_set(/* Mesh* */lean_obj_arg meshes, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->meshes = /*todo: ptr?*/meshes;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* Material* */lean_obj_arg lean_raylib__Model_materials(b_lean_obj_arg obj) {
//     Material * result_ = lean_raylib_Model_from(obj)->materials;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_materials_set(/* Material* */lean_obj_arg materials, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->materials = /*todo: ptr?*/materials;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* int* */lean_obj_arg lean_raylib__Model_meshMaterial(b_lean_obj_arg obj) {
//     int * result_ = lean_raylib_Model_from(obj)->meshMaterial;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_meshMaterial_set(/* int* */lean_obj_arg meshMaterial, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->meshMaterial = /*todo: ptr?*/meshMaterial;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Model_boneCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Model_from(obj)->boneCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_boneCount_set(uint32_t boneCount, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->boneCount = boneCount;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* BoneInfo* */lean_obj_arg lean_raylib__Model_bones(b_lean_obj_arg obj) {
//     BoneInfo * result_ = lean_raylib_Model_from(obj)->bones;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_bones_set(/* BoneInfo* */lean_obj_arg bones, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->bones = /*todo: ptr?*/bones;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT /* Transform* */lean_obj_arg lean_raylib__Model_bindPose(b_lean_obj_arg obj) {
//     Transform * result_ = lean_raylib_Model_from(obj)->bindPose;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Model_bindPose_set(/* Transform* */lean_obj_arg bindPose, b_lean_obj_arg obj) {
//     LET_BOX(Model, result_, *lean_raylib_Model_from(obj));
//     result_->bindPose = /*todo: ptr?*/bindPose;
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__ModelAnimation_mk(uint32_t boneCount, uint32_t frameCount, /* BoneInfo* */lean_obj_arg bones, /* Transform ** */lean_obj_arg framePoses) {
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

// LEAN_EXPORT lean_object* lean_raylib__ModelAnimation_boneCount_set(uint32_t boneCount, b_lean_obj_arg obj) {
//     LET_BOX(ModelAnimation, result_, *lean_raylib_ModelAnimation_from(obj));
//     result_->boneCount = boneCount;
//     return lean_raylib_ModelAnimation_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ModelAnimation_frameCount(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_ModelAnimation_from(obj)->frameCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__ModelAnimation_frameCount_set(uint32_t frameCount, b_lean_obj_arg obj) {
//     LET_BOX(ModelAnimation, result_, *lean_raylib_ModelAnimation_from(obj));
//     result_->frameCount = frameCount;
//     return lean_raylib_ModelAnimation_to(result_);
// }

// LEAN_EXPORT /* BoneInfo* */lean_obj_arg lean_raylib__ModelAnimation_bones(b_lean_obj_arg obj) {
//     BoneInfo * result_ = lean_raylib_ModelAnimation_from(obj)->bones;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__ModelAnimation_bones_set(/* BoneInfo* */lean_obj_arg bones, b_lean_obj_arg obj) {
//     LET_BOX(ModelAnimation, result_, *lean_raylib_ModelAnimation_from(obj));
//     result_->bones = /*todo: ptr?*/bones;
//     return lean_raylib_ModelAnimation_to(result_);
// }

// LEAN_EXPORT /* Transform ** */lean_obj_arg lean_raylib__ModelAnimation_framePoses(b_lean_obj_arg obj) {
//     Transform * * result_ = lean_raylib_ModelAnimation_from(obj)->framePoses;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__ModelAnimation_framePoses_set(/* Transform ** */lean_obj_arg framePoses, b_lean_obj_arg obj) {
//     LET_BOX(ModelAnimation, result_, *lean_raylib_ModelAnimation_from(obj));
//     result_->framePoses = /*todo: ptr?*/framePoses;
//     return lean_raylib_ModelAnimation_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Ray_mk(lean_obj_arg position, lean_obj_arg direction) {
//     LET_BOX_STRUCT(Ray, result_,
//         .position = lean_raylib_Vector3_from(position),
//         .direction = lean_raylib_Vector3_from(direction)
//     );
//     return lean_raylib_Ray_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Ray_position(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_Ray_from(obj)->position;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Ray_position_set(lean_obj_arg position, b_lean_obj_arg obj) {
//     LET_BOX(Ray, result_, *lean_raylib_Ray_from(obj));
//     result_->position = lean_raylib_Vector3_from(position);
//     return lean_raylib_Ray_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Ray_direction(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_Ray_from(obj)->direction;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Ray_direction_set(lean_obj_arg direction, b_lean_obj_arg obj) {
//     LET_BOX(Ray, result_, *lean_raylib_Ray_from(obj));
//     result_->direction = lean_raylib_Vector3_from(direction);
//     return lean_raylib_Ray_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__RayCollision_mk(uint8_t hit, double distance, lean_obj_arg point, lean_obj_arg normal) {
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

// LEAN_EXPORT lean_object* lean_raylib__RayCollision_hit_set(uint8_t hit, b_lean_obj_arg obj) {
//     LET_BOX(RayCollision, result_, *lean_raylib_RayCollision_from(obj));
//     result_->hit = hit;
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT double lean_raylib__RayCollision_distance(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_RayCollision_from(obj)->distance;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__RayCollision_distance_set(double distance, b_lean_obj_arg obj) {
//     LET_BOX(RayCollision, result_, *lean_raylib_RayCollision_from(obj));
//     result_->distance = (float)distance;
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__RayCollision_point(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_RayCollision_from(obj)->point;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__RayCollision_point_set(lean_obj_arg point, b_lean_obj_arg obj) {
//     LET_BOX(RayCollision, result_, *lean_raylib_RayCollision_from(obj));
//     result_->point = lean_raylib_Vector3_from(point);
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__RayCollision_normal(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_RayCollision_from(obj)->normal;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__RayCollision_normal_set(lean_obj_arg normal, b_lean_obj_arg obj) {
//     LET_BOX(RayCollision, result_, *lean_raylib_RayCollision_from(obj));
//     result_->normal = lean_raylib_Vector3_from(normal);
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__BoundingBox_mk(lean_obj_arg min, lean_obj_arg max) {
//     LET_BOX_STRUCT(BoundingBox, result_,
//         .min = lean_raylib_Vector3_from(min),
//         .max = lean_raylib_Vector3_from(max)
//     );
//     return lean_raylib_BoundingBox_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__BoundingBox_min(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_BoundingBox_from(obj)->min;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__BoundingBox_min_set(lean_obj_arg min, b_lean_obj_arg obj) {
//     LET_BOX(BoundingBox, result_, *lean_raylib_BoundingBox_from(obj));
//     result_->min = lean_raylib_Vector3_from(min);
//     return lean_raylib_BoundingBox_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__BoundingBox_max(b_lean_obj_arg obj) {
//     Vector3 result_ = lean_raylib_BoundingBox_from(obj)->max;
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__BoundingBox_max_set(lean_obj_arg max, b_lean_obj_arg obj) {
//     LET_BOX(BoundingBox, result_, *lean_raylib_BoundingBox_from(obj));
//     result_->max = lean_raylib_Vector3_from(max);
//     return lean_raylib_BoundingBox_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Wave_mk(uint32_t frameCount, uint32_t sampleRate, uint32_t sampleSize, uint32_t channels, /* void* */lean_obj_arg data) {
//     LET_BOX_STRUCT(Wave, result_,
//         .frameCount = frameCount,
//         .sampleRate = sampleRate,
//         .sampleSize = sampleSize,
//         .channels = channels,
//         .data = /*todo: ptr?*/data
//     );
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Wave_frameCount(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Wave_from(obj)->frameCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Wave_frameCount_set(uint32_t frameCount, b_lean_obj_arg obj) {
//     LET_BOX(Wave, result_, *lean_raylib_Wave_from(obj));
//     result_->frameCount = frameCount;
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Wave_sampleRate(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Wave_from(obj)->sampleRate;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Wave_sampleRate_set(uint32_t sampleRate, b_lean_obj_arg obj) {
//     LET_BOX(Wave, result_, *lean_raylib_Wave_from(obj));
//     result_->sampleRate = sampleRate;
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Wave_sampleSize(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Wave_from(obj)->sampleSize;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Wave_sampleSize_set(uint32_t sampleSize, b_lean_obj_arg obj) {
//     LET_BOX(Wave, result_, *lean_raylib_Wave_from(obj));
//     result_->sampleSize = sampleSize;
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Wave_channels(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Wave_from(obj)->channels;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Wave_channels_set(uint32_t channels, b_lean_obj_arg obj) {
//     LET_BOX(Wave, result_, *lean_raylib_Wave_from(obj));
//     result_->channels = channels;
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__Wave_data(b_lean_obj_arg obj) {
//     void * result_ = lean_raylib_Wave_from(obj)->data;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Wave_data_set(/* void* */lean_obj_arg data, b_lean_obj_arg obj) {
//     LET_BOX(Wave, result_, *lean_raylib_Wave_from(obj));
//     result_->data = /*todo: ptr?*/data;
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__AudioStream_mk(/* unknown_t* */lean_obj_arg buffer, /* unknown_t* */lean_obj_arg processor, uint32_t sampleRate, uint32_t sampleSize, uint32_t channels) {
//     LET_BOX_STRUCT(AudioStream, result_,
//         .buffer = /*todo: ptr?*/buffer,
//         .processor = /*todo: ptr?*/processor,
//         .sampleRate = sampleRate,
//         .sampleSize = sampleSize,
//         .channels = channels
//     );
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT /* unknown_t* */lean_obj_arg lean_raylib__AudioStream_buffer(b_lean_obj_arg obj) {
//     unknown_t * result_ = lean_raylib_AudioStream_from(obj)->buffer;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__AudioStream_buffer_set(/* unknown_t* */lean_obj_arg buffer, b_lean_obj_arg obj) {
//     LET_BOX(AudioStream, result_, *lean_raylib_AudioStream_from(obj));
//     result_->buffer = /*todo: ptr?*/buffer;
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT /* unknown_t* */lean_obj_arg lean_raylib__AudioStream_processor(b_lean_obj_arg obj) {
//     unknown_t * result_ = lean_raylib_AudioStream_from(obj)->processor;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__AudioStream_processor_set(/* unknown_t* */lean_obj_arg processor, b_lean_obj_arg obj) {
//     LET_BOX(AudioStream, result_, *lean_raylib_AudioStream_from(obj));
//     result_->processor = /*todo: ptr?*/processor;
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__AudioStream_sampleRate(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_AudioStream_from(obj)->sampleRate;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__AudioStream_sampleRate_set(uint32_t sampleRate, b_lean_obj_arg obj) {
//     LET_BOX(AudioStream, result_, *lean_raylib_AudioStream_from(obj));
//     result_->sampleRate = sampleRate;
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__AudioStream_sampleSize(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_AudioStream_from(obj)->sampleSize;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__AudioStream_sampleSize_set(uint32_t sampleSize, b_lean_obj_arg obj) {
//     LET_BOX(AudioStream, result_, *lean_raylib_AudioStream_from(obj));
//     result_->sampleSize = sampleSize;
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__AudioStream_channels(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_AudioStream_from(obj)->channels;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__AudioStream_channels_set(uint32_t channels, b_lean_obj_arg obj) {
//     LET_BOX(AudioStream, result_, *lean_raylib_AudioStream_from(obj));
//     result_->channels = channels;
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Sound_mk(lean_obj_arg stream, uint32_t frameCount) {
//     LET_BOX_STRUCT(Sound, result_,
//         .stream = lean_raylib_AudioStream_from(stream),
//         .frameCount = frameCount
//     );
//     return lean_raylib_Sound_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Sound_stream(b_lean_obj_arg obj) {
//     AudioStream result_ = lean_raylib_Sound_from(obj)->stream;
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Sound_stream_set(lean_obj_arg stream, b_lean_obj_arg obj) {
//     LET_BOX(Sound, result_, *lean_raylib_Sound_from(obj));
//     result_->stream = lean_raylib_AudioStream_from(stream);
//     return lean_raylib_Sound_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Sound_frameCount(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Sound_from(obj)->frameCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Sound_frameCount_set(uint32_t frameCount, b_lean_obj_arg obj) {
//     LET_BOX(Sound, result_, *lean_raylib_Sound_from(obj));
//     result_->frameCount = frameCount;
//     return lean_raylib_Sound_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Music_mk(lean_obj_arg stream, uint32_t frameCount, uint8_t looping, uint32_t ctxType, /* void* */lean_obj_arg ctxData) {
//     LET_BOX_STRUCT(Music, result_,
//         .stream = lean_raylib_AudioStream_from(stream),
//         .frameCount = frameCount,
//         .looping = looping,
//         .ctxType = ctxType,
//         .ctxData = /*todo: ptr?*/ctxData
//     );
//     return lean_raylib_Music_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__Music_stream(b_lean_obj_arg obj) {
//     AudioStream result_ = lean_raylib_Music_from(obj)->stream;
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__Music_stream_set(lean_obj_arg stream, b_lean_obj_arg obj) {
//     LET_BOX(Music, result_, *lean_raylib_Music_from(obj));
//     result_->stream = lean_raylib_AudioStream_from(stream);
//     return lean_raylib_Music_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Music_frameCount(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_Music_from(obj)->frameCount;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Music_frameCount_set(uint32_t frameCount, b_lean_obj_arg obj) {
//     LET_BOX(Music, result_, *lean_raylib_Music_from(obj));
//     result_->frameCount = frameCount;
//     return lean_raylib_Music_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__Music_looping(b_lean_obj_arg obj) {
//     bool result_ = lean_raylib_Music_from(obj)->looping;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Music_looping_set(uint8_t looping, b_lean_obj_arg obj) {
//     LET_BOX(Music, result_, *lean_raylib_Music_from(obj));
//     result_->looping = looping;
//     return lean_raylib_Music_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__Music_ctxType(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_Music_from(obj)->ctxType;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Music_ctxType_set(uint32_t ctxType, b_lean_obj_arg obj) {
//     LET_BOX(Music, result_, *lean_raylib_Music_from(obj));
//     result_->ctxType = ctxType;
//     return lean_raylib_Music_to(result_);
// }

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__Music_ctxData(b_lean_obj_arg obj) {
//     void * result_ = lean_raylib_Music_from(obj)->ctxData;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__Music_ctxData_set(/* void* */lean_obj_arg ctxData, b_lean_obj_arg obj) {
//     LET_BOX(Music, result_, *lean_raylib_Music_from(obj));
//     result_->ctxData = /*todo: ptr?*/ctxData;
//     return lean_raylib_Music_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_mk(uint32_t hResolution, uint32_t vResolution, double hScreenSize, double vScreenSize, double vScreenCenter, double eyeToScreenDistance, double lensSeparationDistance, double interpupillaryDistance, /*float[4]*/lean_obj_arg lensDistortionValues, /*float[4]*/lean_obj_arg chromaAbCorrection) {
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

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_hResolution_set(uint32_t hResolution, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->hResolution = hResolution;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__VrDeviceInfo_vResolution(b_lean_obj_arg obj) {
//     int result_ = lean_raylib_VrDeviceInfo_from(obj)->vResolution;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_vResolution_set(uint32_t vResolution, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->vResolution = vResolution;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_hScreenSize(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->hScreenSize;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_hScreenSize_set(double hScreenSize, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->hScreenSize = (float)hScreenSize;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_vScreenSize(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->vScreenSize;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_vScreenSize_set(double vScreenSize, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->vScreenSize = (float)vScreenSize;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_vScreenCenter(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->vScreenCenter;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_vScreenCenter_set(double vScreenCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->vScreenCenter = (float)vScreenCenter;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_eyeToScreenDistance(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->eyeToScreenDistance;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_eyeToScreenDistance_set(double eyeToScreenDistance, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->eyeToScreenDistance = (float)eyeToScreenDistance;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_lensSeparationDistance(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->lensSeparationDistance;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_lensSeparationDistance_set(double lensSeparationDistance, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->lensSeparationDistance = (float)lensSeparationDistance;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT double lean_raylib__VrDeviceInfo_interpupillaryDistance(b_lean_obj_arg obj) {
//     float result_ = lean_raylib_VrDeviceInfo_from(obj)->interpupillaryDistance;
//     return (double)result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_interpupillaryDistance_set(double interpupillaryDistance, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->interpupillaryDistance = (float)interpupillaryDistance;
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT /*float[4]*/lean_obj_arg lean_raylib__VrDeviceInfo_lensDistortionValues(b_lean_obj_arg obj) {
//     float[4] result_ = lean_raylib_VrDeviceInfo_from(obj)->lensDistortionValues;
//     return /*cast float[4] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_lensDistortionValues_set(/*float[4]*/lean_obj_arg lensDistortionValues, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->lensDistortionValues = /*cast float[4] to_lean?false*/(lensDistortionValues);
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT /*float[4]*/lean_obj_arg lean_raylib__VrDeviceInfo_chromaAbCorrection(b_lean_obj_arg obj) {
//     float[4] result_ = lean_raylib_VrDeviceInfo_from(obj)->chromaAbCorrection;
//     return /*cast float[4] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrDeviceInfo_chromaAbCorrection_set(/*float[4]*/lean_obj_arg chromaAbCorrection, b_lean_obj_arg obj) {
//     LET_BOX(VrDeviceInfo, result_, *lean_raylib_VrDeviceInfo_from(obj));
//     result_->chromaAbCorrection = /*cast float[4] to_lean?false*/(chromaAbCorrection);
//     return lean_raylib_VrDeviceInfo_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_mk(/*Matrix[2]*/lean_obj_arg projection, /*Matrix[2]*/lean_obj_arg viewOffset, /*float[2]*/lean_obj_arg leftLensCenter, /*float[2]*/lean_obj_arg rightLensCenter, /*float[2]*/lean_obj_arg leftScreenCenter, /*float[2]*/lean_obj_arg rightScreenCenter, /*float[2]*/lean_obj_arg scale, /*float[2]*/lean_obj_arg scaleIn) {
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

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_projection_set(/*Matrix[2]*/lean_obj_arg projection, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->projection = /*cast Matrix[2] to_lean?false*/(projection);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*Matrix[2]*/lean_obj_arg lean_raylib__VrStereoConfig_viewOffset(b_lean_obj_arg obj) {
//     Matrix[2] result_ = lean_raylib_VrStereoConfig_from(obj)->viewOffset;
//     return /*cast Matrix[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_viewOffset_set(/*Matrix[2]*/lean_obj_arg viewOffset, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->viewOffset = /*cast Matrix[2] to_lean?false*/(viewOffset);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_leftLensCenter(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->leftLensCenter;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_leftLensCenter_set(/*float[2]*/lean_obj_arg leftLensCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->leftLensCenter = /*cast float[2] to_lean?false*/(leftLensCenter);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_rightLensCenter(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->rightLensCenter;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_rightLensCenter_set(/*float[2]*/lean_obj_arg rightLensCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->rightLensCenter = /*cast float[2] to_lean?false*/(rightLensCenter);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_leftScreenCenter(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->leftScreenCenter;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_leftScreenCenter_set(/*float[2]*/lean_obj_arg leftScreenCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->leftScreenCenter = /*cast float[2] to_lean?false*/(leftScreenCenter);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_rightScreenCenter(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->rightScreenCenter;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_rightScreenCenter_set(/*float[2]*/lean_obj_arg rightScreenCenter, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->rightScreenCenter = /*cast float[2] to_lean?false*/(rightScreenCenter);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_scale(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->scale;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_scale_set(/*float[2]*/lean_obj_arg scale, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->scale = /*cast float[2] to_lean?false*/(scale);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT /*float[2]*/lean_obj_arg lean_raylib__VrStereoConfig_scaleIn(b_lean_obj_arg obj) {
//     float[2] result_ = lean_raylib_VrStereoConfig_from(obj)->scaleIn;
//     return /*cast float[2] to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__VrStereoConfig_scaleIn_set(/*float[2]*/lean_obj_arg scaleIn, b_lean_obj_arg obj) {
//     LET_BOX(VrStereoConfig, result_, *lean_raylib_VrStereoConfig_from(obj));
//     result_->scaleIn = /*cast float[2] to_lean?false*/(scaleIn);
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT lean_object* lean_raylib__FilePathList_mk(uint32_t capacity, uint32_t count, /* char ** */lean_obj_arg paths) {
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

// LEAN_EXPORT lean_object* lean_raylib__FilePathList_capacity_set(uint32_t capacity, b_lean_obj_arg obj) {
//     LET_BOX(FilePathList, result_, *lean_raylib_FilePathList_from(obj));
//     result_->capacity = capacity;
//     return lean_raylib_FilePathList_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__FilePathList_count(b_lean_obj_arg obj) {
//     unsigned int result_ = lean_raylib_FilePathList_from(obj)->count;
//     return result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__FilePathList_count_set(uint32_t count, b_lean_obj_arg obj) {
//     LET_BOX(FilePathList, result_, *lean_raylib_FilePathList_from(obj));
//     result_->count = count;
//     return lean_raylib_FilePathList_to(result_);
// }

// LEAN_EXPORT /* char ** */lean_obj_arg lean_raylib__FilePathList_paths(b_lean_obj_arg obj) {
//     char * * result_ = lean_raylib_FilePathList_from(obj)->paths;
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_object* lean_raylib__FilePathList_paths_set(/* char ** */lean_obj_arg paths, b_lean_obj_arg obj) {
//     LET_BOX(FilePathList, result_, *lean_raylib_FilePathList_from(obj));
//     result_->paths = /*todo: ptr?*/paths;
//     return lean_raylib_FilePathList_to(result_);
// }
