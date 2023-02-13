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

static void lean_raylib_default_foreach(void* a, b_lean_obj_arg b);
