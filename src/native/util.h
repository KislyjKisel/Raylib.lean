#pragma once

#include <assert.h>
#include <stdint.h>
#include <lean/lean.h>
#include <raylib.h>

#ifdef static_assert
    static_assert (sizeof(int) == 4, "`sizeof(int) != 4` unsupported");
#endif

#define LET_BOX(T, n, x)\
    T* n = malloc(sizeof(T));\
    *n = x;

#define LET_BOX_STRUCT(T, n, ...) LET_BOX(T, n, ((T){__VA_ARGS__}));

static void lean_raylib_default_foreach(void* a, b_lean_obj_arg b) {}
static void lean_raylib_default_finalize(void* a) {}

static inline lean_object* lean_mk_tuple2(lean_object* fst, lean_object* snd) {
    lean_object* result = lean_alloc_ctor(0, 2, 0);
    lean_ctor_set(result, 0, fst);
    lean_ctor_set(result, 1, snd);
    return result;
}

static inline lean_object* lean_mk_option_none() {
    return lean_box(0);
}

static inline lean_object* lean_mk_option_some(lean_object* value) {
    lean_object* result = lean_alloc_ctor(0, 1, 0);
    lean_ctor_set(result, 0, value);
    return result;
}
