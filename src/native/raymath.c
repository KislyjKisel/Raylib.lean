#include <lean/lean.h>
#include <raymath.h>
#include <lean_pod.h>

LEAN_EXPORT uint32_t lean_raymath_Vector_get(b_lean_obj_arg v, size_t i) {
    return lean_unbox_uint32(lean_ctor_get(v, i));
}
