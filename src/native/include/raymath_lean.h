#pragma once

#include <lean/lean.h>
#include <raylib.h>
#include <raymath.h>
#include <lean_pod.h>

// # Vectors

static inline void lean_raylib_Vector2_set (b_lean_obj_arg obj, Vector2 v) {
    lean_ctor_set(obj, 0, lean_box_uint32(lean_pod_Float32_toRepr(v.x)));
    lean_ctor_set(obj, 1, lean_box_uint32(lean_pod_Float32_toRepr(v.y)));
}

static inline lean_object* lean_raylib_Vector2_to (Vector2 v) {
    lean_object* obj = lean_alloc_ctor(0, 2, 0);
    lean_raylib_Vector2_set(obj, v);
    return obj;
}

static inline Vector2 lean_raylib_Vector2_from (b_lean_obj_arg obj) {
    Vector2 v;
    v.x = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 0)));
    v.y = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 1)));
    return v;
}

static inline void lean_raylib_Vector3_set (b_lean_obj_arg obj, Vector3 v) {
    lean_ctor_set(obj, 0, lean_box_uint32(lean_pod_Float32_toRepr(v.x)));
    lean_ctor_set(obj, 1, lean_box_uint32(lean_pod_Float32_toRepr(v.y)));
    lean_ctor_set(obj, 2, lean_box_uint32(lean_pod_Float32_toRepr(v.z)));
}

static inline lean_object* lean_raylib_Vector3_to (Vector3 v) {
    lean_object* obj = lean_alloc_ctor(0, 3, 0);
    lean_raylib_Vector3_set(obj, v);
    return obj;
}

static inline Vector3 lean_raylib_Vector3_from (b_lean_obj_arg obj) {
    Vector3 v;
    v.x = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 0)));
    v.y = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 1)));
    v.z = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 2)));
    return v;
}

static inline void lean_raylib_Vector4_set (b_lean_obj_arg obj, Vector4 v) {
    lean_ctor_set(obj, 0, lean_box_uint32(lean_pod_Float32_toRepr(v.x)));
    lean_ctor_set(obj, 1, lean_box_uint32(lean_pod_Float32_toRepr(v.y)));
    lean_ctor_set(obj, 2, lean_box_uint32(lean_pod_Float32_toRepr(v.z)));
    lean_ctor_set(obj, 3, lean_box_uint32(lean_pod_Float32_toRepr(v.w)));
}

static inline lean_object* lean_raylib_Vector4_to (Vector4 v) {
    lean_object* obj = lean_alloc_ctor(0, 4, 0);
    lean_raylib_Vector4_set(obj, v);
    return obj;
}

static inline Vector4 lean_raylib_Vector4_from (b_lean_obj_arg obj) {
    Vector4 v;
    v.x = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 0)));
    v.y = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 1)));
    v.z = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 2)));
    v.w = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 3)));
    return v;
}


// # Matrix

static inline void lean_raylib_Matrix_set (b_lean_obj_arg obj, Matrix m) {
    lean_ctor_set(obj, 0, lean_box_uint32(lean_pod_Float32_toRepr(m.m0)));
    lean_ctor_set(obj, 1, lean_box_uint32(lean_pod_Float32_toRepr(m.m4)));
    lean_ctor_set(obj, 2, lean_box_uint32(lean_pod_Float32_toRepr(m.m8)));
    lean_ctor_set(obj, 3, lean_box_uint32(lean_pod_Float32_toRepr(m.m12)));
    lean_ctor_set(obj, 4, lean_box_uint32(lean_pod_Float32_toRepr(m.m1)));
    lean_ctor_set(obj, 5, lean_box_uint32(lean_pod_Float32_toRepr(m.m5)));
    lean_ctor_set(obj, 6, lean_box_uint32(lean_pod_Float32_toRepr(m.m9)));
    lean_ctor_set(obj, 7, lean_box_uint32(lean_pod_Float32_toRepr(m.m13)));
    lean_ctor_set(obj, 8, lean_box_uint32(lean_pod_Float32_toRepr(m.m2)));
    lean_ctor_set(obj, 9, lean_box_uint32(lean_pod_Float32_toRepr(m.m6)));
    lean_ctor_set(obj, 10, lean_box_uint32(lean_pod_Float32_toRepr(m.m10)));
    lean_ctor_set(obj, 11, lean_box_uint32(lean_pod_Float32_toRepr(m.m14)));
    lean_ctor_set(obj, 12, lean_box_uint32(lean_pod_Float32_toRepr(m.m3)));
    lean_ctor_set(obj, 13, lean_box_uint32(lean_pod_Float32_toRepr(m.m7)));
    lean_ctor_set(obj, 14, lean_box_uint32(lean_pod_Float32_toRepr(m.m11)));
    lean_ctor_set(obj, 15, lean_box_uint32(lean_pod_Float32_toRepr(m.m15)));
}

static inline lean_object* lean_raylib_Matrix_to (Matrix m) {
    lean_object* obj = lean_alloc_ctor(0, 16, 0);
    lean_raylib_Matrix_set(obj, m);
    return obj;
}

static inline Matrix lean_raylib_Matrix_from (b_lean_obj_arg obj) {
    Matrix m;
    m.m0 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 0)));
    m.m4 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 1)));
    m.m8 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 2)));
    m.m12 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 3)));
    m.m1 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 4)));
    m.m5 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 5)));
    m.m9 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 6)));
    m.m13 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 7)));
    m.m2 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 8)));
    m.m6 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 9)));
    m.m10 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 10)));
    m.m14 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 11)));
    m.m3 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 12)));
    m.m7 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 13)));
    m.m11 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 14)));
    m.m15 = lean_pod_Float32_fromRepr(lean_unbox_uint32(lean_ctor_get(obj, 15)));
    return m;
}
