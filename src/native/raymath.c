#include <lean/lean.h>
#include <lean_pod.h>
#include "include/raymath_lean.h"

LEAN_POD_RWBYTES_INST(Raymath_Vector2, Vector2, lean_object*, lean_raylib_Vector2_box, lean_raylib_Vector2_toRepr, lean_raylib_Vector2_fromRepr)
LEAN_POD_RWBYTES_INST(Raymath_Vector3, Vector3, lean_object*, lean_raylib_Vector3_box, lean_raylib_Vector3_toRepr, lean_raylib_Vector3_fromRepr)
LEAN_POD_RWBYTES_INST(Raymath_Vector4, Vector4, lean_object*, lean_raylib_Vector4_box, lean_raylib_Vector4_toRepr, lean_raylib_Vector4_fromRepr)
LEAN_POD_RWBYTES_INST(Raymath_Matrix, Matrix, lean_object*, lean_raylib_Matrix_box, lean_raylib_Matrix_toRepr, lean_raylib_Matrix_fromRepr)

LEAN_EXPORT uint32_t lean_raymath_Vector_uget(b_lean_obj_arg v, uint32_t i) {
    return lean_unbox_uint32(lean_ctor_get(v, i));
}

LEAN_EXPORT lean_obj_res lean_raymath_Vector2_uset(lean_obj_arg v, uint32_t i, uint32_t value) {
    if(lean_is_exclusive(v)) {
        lean_ctor_set(v, i, lean_box_uint32(value));
        return v;
    }
    else {
        union {
            Vector2 vector;
            float fields[2];
        } u;
        u.vector = lean_raylib_Vector2_fromRepr(v);
        lean_dec_ref(v);
        u.fields[i] = lean_pod_Float32_fromRepr(value);
        return lean_raylib_Vector2_toRepr(u.vector);
    }
}

LEAN_EXPORT lean_obj_res lean_raymath_Vector3_unproject(b_lean_obj_arg source, b_lean_obj_arg projection, b_lean_obj_arg view) {
    return lean_raylib_Vector3_toRepr(Vector3Unproject(
        lean_raylib_Vector3_fromRepr(source),
        lean_raylib_Matrix_fromRepr(projection),
        lean_raylib_Matrix_fromRepr(view)
    ));
}

LEAN_EXPORT lean_obj_res lean_raymath_Vector3_uset(lean_obj_arg v, uint32_t i, uint32_t value) {
    if(lean_is_exclusive(v)) {
        lean_ctor_set(v, i, lean_box_uint32(value));
        return v;
    }
    else {
        union {
            Vector3 vector;
            float fields[3];
        } u;
        u.vector = lean_raylib_Vector3_fromRepr(v);
        lean_dec_ref(v);
        u.fields[i] = lean_pod_Float32_fromRepr(value);
        return lean_raylib_Vector3_toRepr(u.vector);
    }
}

LEAN_EXPORT lean_obj_res lean_raymath_Vector4_uset(lean_obj_arg v, uint32_t i, uint32_t value) {
    if(lean_is_exclusive(v)) {
        lean_ctor_set(v, i, lean_box_uint32(value));
        return v;
    }
    else {
        union {
            Vector4 vector;
            float fields[4];
        } u;
        u.vector = lean_raylib_Vector4_fromRepr(v);
        lean_dec_ref(v);
        u.fields[i] = lean_pod_Float32_fromRepr(value);
        return lean_raylib_Vector4_toRepr(u.vector);
    }
}

LEAN_EXPORT lean_obj_res lean_raymath_Matrix_decompose(b_lean_obj_arg mat) {
    Vector3 translation, scale;
    Quaternion rotation;
    MatrixDecompose(lean_raylib_Matrix_fromRepr(mat), &translation, &rotation, &scale);
    return lean_mk_tuple3(
        lean_raylib_Vector3_box(translation),
        lean_raylib_Quaternion_box(rotation),
        lean_raylib_Vector3_box(scale)
    );
}

LEAN_EXPORT lean_obj_res lean_raymath_Matrix_urow(b_lean_obj_arg m, uint32_t i) {
    uint32_t offset = 4 * i;
    return lean_raylib_Vector4_toRepr((Vector4){
        lean_pod_Float32_unbox(lean_ctor_get(m, offset)),
        lean_pod_Float32_unbox(lean_ctor_get(m, offset + 1)),
        lean_pod_Float32_unbox(lean_ctor_get(m, offset + 2)),
        lean_pod_Float32_unbox(lean_ctor_get(m, offset + 3)),
    });
}

LEAN_EXPORT lean_obj_res lean_raymath_Matrix_ucolumn(b_lean_obj_arg m, uint32_t i) {
    return lean_raylib_Vector4_toRepr((Vector4){
        lean_pod_Float32_unbox(lean_ctor_get(m, i)),
        lean_pod_Float32_unbox(lean_ctor_get(m, i + 4)),
        lean_pod_Float32_unbox(lean_ctor_get(m, i + 8)),
        lean_pod_Float32_unbox(lean_ctor_get(m, i + 12)),
    });
}

LEAN_EXPORT uint32_t lean_raymath_Matrix_ugetLinear(b_lean_obj_arg m, uint32_t i) {
    return lean_unbox_uint32(lean_ctor_get(m, i));
}

LEAN_EXPORT uint32_t lean_raymath_Matrix_uget(b_lean_obj_arg m, uint32_t i, uint32_t j) {
    return lean_unbox_uint32(lean_ctor_get(m, 4 * i + j));
}

LEAN_EXPORT lean_obj_res lean_raymath_Matrix_usetRow(lean_obj_arg m, uint32_t i, b_lean_obj_arg value_box) {
    Vector4 value = lean_raylib_Vector4_fromRepr(value_box);
    uint32_t offset = 4 * i;
    if(LEAN_LIKELY(lean_is_exclusive(m))) {
        lean_ctor_set(m, offset, lean_pod_Float32_box(value.x));
        lean_ctor_set(m, offset + 1, lean_pod_Float32_box(value.y));
        lean_ctor_set(m, offset + 2, lean_pod_Float32_box(value.z));
        lean_ctor_set(m, offset + 3, lean_pod_Float32_box(value.w));
        return m;
    }
    else {
        union {
            Matrix matrix;
            float fields[16];
        } u;
        u.matrix = lean_raylib_Matrix_fromRepr(m);
        lean_dec_ref(m);
        u.fields[offset] = value.x;
        u.fields[offset + 1] = value.y;
        u.fields[offset + 2] = value.z;
        u.fields[offset + 3] = value.w;
        return lean_raylib_Matrix_toRepr(u.matrix);
    }
}

LEAN_EXPORT lean_obj_res lean_raymath_Matrix_usetColumn(lean_obj_arg m, uint32_t i, b_lean_obj_arg value_box) {
    Vector4 value = lean_raylib_Vector4_fromRepr(value_box);
    if(LEAN_LIKELY(lean_is_exclusive(m))) {
        lean_ctor_set(m, i, lean_pod_Float32_box(value.x));
        lean_ctor_set(m, i + 4, lean_pod_Float32_box(value.y));
        lean_ctor_set(m, i + 8, lean_pod_Float32_box(value.z));
        lean_ctor_set(m, i + 12, lean_pod_Float32_box(value.w));
        return m;
    }
    else {
        union {
            Matrix matrix;
            float fields[16];
        } u;
        u.matrix = lean_raylib_Matrix_fromRepr(m);
        lean_dec_ref(m);
        u.fields[i] = value.x;
        u.fields[i + 4] = value.y;
        u.fields[i + 8] = value.z;
        u.fields[i + 12] = value.w;
        return lean_raylib_Matrix_toRepr(u.matrix);
    }
}

LEAN_EXPORT lean_obj_res lean_raymath_Matrix_usetLinear(lean_obj_arg m, uint32_t i, uint32_t value) {
    if(LEAN_LIKELY(lean_is_exclusive(m))) {
        lean_ctor_set(m, i, lean_box_uint32(value));
        return m;
    }
    else {
        union {
            Matrix matrix;
            float fields[16];
        } u;
        u.matrix = lean_raylib_Matrix_fromRepr(m);
        lean_dec_ref(m);
        u.fields[i] = lean_pod_Float32_fromRepr(value);
        return lean_raylib_Matrix_toRepr(u.matrix);
    }
}

LEAN_EXPORT lean_obj_res lean_raymath_Matrix_uset(lean_obj_arg m, uint32_t i, uint32_t j, uint32_t value) {
    return lean_raymath_Matrix_usetLinear(m, 4 * i + j, value);
}

LEAN_EXPORT lean_obj_res lean_raymath_Quaternion_fromMatrix(b_lean_obj_arg mat) {
    return lean_raylib_Vector4_toRepr(QuaternionFromMatrix(lean_raylib_Matrix_fromRepr(mat)));
}

LEAN_EXPORT lean_obj_res lean_raymath_Quaternion_fromAxisAngle(b_lean_obj_arg axis, uint32_t angle) {
    return lean_raylib_Vector4_toRepr(QuaternionFromAxisAngle(
        lean_raylib_Vector3_fromRepr(axis),
        lean_pod_Float32_fromRepr(angle)
    ));
}

LEAN_EXPORT lean_obj_res lean_raymath_Quaternion_toAxisAngle(b_lean_obj_arg q) {
    Vector3 axis;
    float angle;
    QuaternionToAxisAngle(lean_raylib_Vector4_fromRepr(q), &axis, &angle);
    return lean_mk_tuple2(lean_raylib_Vector3_box(axis), lean_pod_Float32_box(angle));
}

LEAN_EXPORT lean_obj_res lean_raymath_Quaternion_toEuler(b_lean_obj_res q) {
    return lean_raylib_Vector3_toRepr(QuaternionToEuler(lean_raylib_Vector4_fromRepr(q)));
}

LEAN_EXPORT uint8_t lean_raymath_Quaternion_equals(b_lean_obj_arg p, b_lean_obj_arg q) {
    return QuaternionEquals(
        lean_raylib_Vector4_fromRepr(p),
        lean_raylib_Vector4_fromRepr(q)
    );
}
