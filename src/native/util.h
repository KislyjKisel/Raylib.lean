#pragma once

#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <lean/lean.h>
#include <raylib.h>
#include "include/raylib_lean.h"

// Where in raylib `int` is used it is assumed to be the same with `int32_t` 
#ifdef static_assert
    static_assert (sizeof(int) == 4, "`sizeof(int) != 4` unsupported");
#endif

#define LET_BOX(T, n, x)\
    T* n = lean_raylib_alloc(sizeof(T));\
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
    lean_object* result = lean_alloc_ctor(1, 1, 0);
    lean_ctor_set(result, 0, value);
    return result;
}

static inline int lean_option_is_some(b_lean_obj_arg opt) {
    return !lean_is_scalar(opt);
}

static inline void* lean_raylib_rlmemdup(const void* src, size_t size) {
    void* dst = RL_MALLOC(size);
    memcpy(dst, src, size);
    return dst;
}

// NOT \0 terminated
static inline const char* lean_raylib_Substring_cptr(b_lean_obj_arg ss) {
    return lean_string_cstr(lean_ctor_get(ss, 0)) + lean_usize_of_nat(lean_ctor_get(ss, 1));
}

static inline size_t lean_raylib_Substring_utf8_byte_size(b_lean_obj_arg ss) {
    return lean_usize_of_nat(lean_ctor_get(ss, 2)) - lean_usize_of_nat(lean_ctor_get(ss, 1));
}
