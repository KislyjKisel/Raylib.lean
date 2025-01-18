#pragma once

#include <lean/lean.h>
#include <raylib.h>
#include <raymath.h>
#include <lean_pod.h>

// # Vectors

// NOTE: Layout changes must be synchronized with raymath.c getters/setters
#define LEAN_RAYLIB_Vector2_LAYOUT 0, 0, 0, 0, 2, 0, 0
#define LEAN_RAYLIB_Vector2_x F32, 0, LEAN_RAYLIB_Vector2_LAYOUT
#define LEAN_RAYLIB_Vector2_y F32, 1, LEAN_RAYLIB_Vector2_LAYOUT

static inline void lean_raylib_Vector2_set (b_lean_obj_arg obj, Vector2 v) {
    LEAN_POD_CTOR_SET(obj, v.x, LEAN_RAYLIB_Vector2_x);
    LEAN_POD_CTOR_SET(obj, v.y, LEAN_RAYLIB_Vector2_y);
}

static inline lean_object* lean_raylib_Vector2_box (Vector2 v) {
    lean_object* obj = LEAN_POD_ALLOC_CTOR(LEAN_RAYLIB_Vector2_LAYOUT);
    lean_raylib_Vector2_set(obj, v);
    return obj;
}

#define lean_raylib_Vector2_toRepr lean_raylib_Vector2_box

static inline Vector2 lean_raylib_Vector2_unbox (b_lean_obj_arg obj) {
    Vector2 v;
    v.x = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector2_x);
    v.y = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector2_y);
    return v;
}

#define lean_raylib_Vector2_fromRepr lean_raylib_Vector2_unbox


// NOTE: Layout changes must be synchronized with raymath.c getters/setters
#define LEAN_RAYLIB_Vector3_LAYOUT 0, 0, 0, 0, 3, 0, 0
#define LEAN_RAYLIB_Vector3_x F32, 0, LEAN_RAYLIB_Vector3_LAYOUT
#define LEAN_RAYLIB_Vector3_y F32, 1, LEAN_RAYLIB_Vector3_LAYOUT
#define LEAN_RAYLIB_Vector3_z F32, 2, LEAN_RAYLIB_Vector3_LAYOUT

static inline void lean_raylib_Vector3_set (b_lean_obj_arg obj, Vector3 v) {
    LEAN_POD_CTOR_SET(obj, v.x, LEAN_RAYLIB_Vector3_x);
    LEAN_POD_CTOR_SET(obj, v.y, LEAN_RAYLIB_Vector3_y);
    LEAN_POD_CTOR_SET(obj, v.z, LEAN_RAYLIB_Vector3_z);
}

static inline lean_object* lean_raylib_Vector3_box (Vector3 v) {
    lean_object* obj = LEAN_POD_ALLOC_CTOR(LEAN_RAYLIB_Vector3_LAYOUT);
    lean_raylib_Vector3_set(obj, v);
    return obj;
}

#define lean_raylib_Vector3_toRepr lean_raylib_Vector3_box

static inline Vector3 lean_raylib_Vector3_unbox (b_lean_obj_arg obj) {
    Vector3 v;
    v.x = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector3_x);
    v.y = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector3_y);
    v.z = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector3_z);
    return v;
}

#define lean_raylib_Vector3_fromRepr lean_raylib_Vector3_unbox


// NOTE: Layout changes must be synchronized with raymath.c getters/setters
#define LEAN_RAYLIB_Vector4_LAYOUT 0, 0, 0, 0, 4, 0, 0
#define LEAN_RAYLIB_Vector4_x F32, 0, LEAN_RAYLIB_Vector4_LAYOUT
#define LEAN_RAYLIB_Vector4_y F32, 1, LEAN_RAYLIB_Vector4_LAYOUT
#define LEAN_RAYLIB_Vector4_z F32, 2, LEAN_RAYLIB_Vector4_LAYOUT
#define LEAN_RAYLIB_Vector4_w F32, 3, LEAN_RAYLIB_Vector4_LAYOUT

static inline void lean_raylib_Vector4_set (b_lean_obj_arg obj, Vector4 v) {
    LEAN_POD_CTOR_SET(obj, v.x, LEAN_RAYLIB_Vector4_x);
    LEAN_POD_CTOR_SET(obj, v.y, LEAN_RAYLIB_Vector4_y);
    LEAN_POD_CTOR_SET(obj, v.z, LEAN_RAYLIB_Vector4_z);
    LEAN_POD_CTOR_SET(obj, v.w, LEAN_RAYLIB_Vector4_w);
}

static inline lean_object* lean_raylib_Vector4_box (Vector4 v) {
    lean_object* obj = LEAN_POD_ALLOC_CTOR(LEAN_RAYLIB_Vector4_LAYOUT);
    lean_raylib_Vector4_set(obj, v);
    return obj;
}

#define lean_raylib_Vector4_toRepr lean_raylib_Vector4_box

static inline Vector4 lean_raylib_Vector4_unbox (b_lean_obj_arg obj) {
    Vector4 v;
    v.x = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector4_x);
    v.y = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector4_y);
    v.z = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector4_z);
    v.w = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Vector4_w);
    return v;
}

#define lean_raylib_Vector4_fromRepr lean_raylib_Vector4_unbox


// # Matrix

// NOTE: Layout changes must be synchronized with raymath.c getters/setters
#define LEAN_RAYLIB_Matrix_LAYOUT 0, 0, 0, 0, 16, 0, 0
#define LEAN_RAYLIB_Matrix_m0 F32, 0, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m4 F32, 1, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m8 F32, 2, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m12 F32, 3, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m1 F32, 4, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m5 F32, 5, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m9 F32, 6, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m13 F32, 7, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m2 F32, 8, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m6 F32, 9, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m10 F32, 10, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m14 F32, 11, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m3 F32, 12, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m7 F32, 13, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m11 F32, 14, LEAN_RAYLIB_Matrix_LAYOUT
#define LEAN_RAYLIB_Matrix_m15 F32, 15, LEAN_RAYLIB_Matrix_LAYOUT

static inline void lean_raylib_Matrix_set (b_lean_obj_arg obj, Matrix m) {
    LEAN_POD_CTOR_SET(obj, m.m0, LEAN_RAYLIB_Matrix_m0);
    LEAN_POD_CTOR_SET(obj, m.m4, LEAN_RAYLIB_Matrix_m4);
    LEAN_POD_CTOR_SET(obj, m.m8, LEAN_RAYLIB_Matrix_m8);
    LEAN_POD_CTOR_SET(obj, m.m12, LEAN_RAYLIB_Matrix_m12);
    LEAN_POD_CTOR_SET(obj, m.m1, LEAN_RAYLIB_Matrix_m1);
    LEAN_POD_CTOR_SET(obj, m.m5, LEAN_RAYLIB_Matrix_m5);
    LEAN_POD_CTOR_SET(obj, m.m9, LEAN_RAYLIB_Matrix_m9);
    LEAN_POD_CTOR_SET(obj, m.m13, LEAN_RAYLIB_Matrix_m13);
    LEAN_POD_CTOR_SET(obj, m.m2, LEAN_RAYLIB_Matrix_m2);
    LEAN_POD_CTOR_SET(obj, m.m6, LEAN_RAYLIB_Matrix_m6);
    LEAN_POD_CTOR_SET(obj, m.m10, LEAN_RAYLIB_Matrix_m10);
    LEAN_POD_CTOR_SET(obj, m.m14, LEAN_RAYLIB_Matrix_m14);
    LEAN_POD_CTOR_SET(obj, m.m3, LEAN_RAYLIB_Matrix_m3);
    LEAN_POD_CTOR_SET(obj, m.m7, LEAN_RAYLIB_Matrix_m7);
    LEAN_POD_CTOR_SET(obj, m.m11, LEAN_RAYLIB_Matrix_m11);
    LEAN_POD_CTOR_SET(obj, m.m15, LEAN_RAYLIB_Matrix_m15);
}

static inline lean_object* lean_raylib_Matrix_box (Matrix m) {
    lean_object* obj = lean_alloc_ctor(0, 16, 0);
    lean_raylib_Matrix_set(obj, m);
    return obj;
}

#define lean_raylib_Matrix_toRepr lean_raylib_Matrix_box

static inline Matrix lean_raylib_Matrix_unbox (b_lean_obj_arg obj) {
    Matrix m;
    m.m0 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m0);
    m.m4 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m4);
    m.m8 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m8);
    m.m12 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m12);
    m.m1 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m1);
    m.m5 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m5);
    m.m9 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m9);
    m.m13 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m13);
    m.m2 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m2);
    m.m6 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m6);
    m.m10 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m10);
    m.m14 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m14);
    m.m3 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m3);
    m.m7 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m7);
    m.m11 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m11);
    m.m15 = LEAN_POD_CTOR_GET(obj, LEAN_RAYLIB_Matrix_m15);
    return m;
}

#define lean_raylib_Matrix_fromRepr lean_raylib_Matrix_unbox


#define lean_raylib_Quaternion_fromRepr lean_raylib_Vector4_fromRepr
#define lean_raylib_Quaternion_unbox lean_raylib_Vector4_unbox
#define lean_raylib_Quaternion_toRepr lean_raylib_Vector4_toRepr
#define lean_raylib_Quaternion_box lean_raylib_Vector4_box
