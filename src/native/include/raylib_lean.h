#pragma once

#include <lean/lean.h>
#include <raylib.h>

/// Allocate external raylib object.
/// @param sz must be divisible by `LEAN_OBJECT_SIZE_DELTA`
static inline void* lean_raylib_alloc(size_t sz) {
#ifdef LEAN_RAYLIB_ALLOC_NATIVE
    return malloc(sz);
#else
    return (void*)lean_alloc_small_object(sz);
#endif
}

/// Free external raylib object.
/// @param p pointer to memory allocated with `lean_raylib_alloc`
static inline void lean_raylib_free(void* p) {
#ifdef LEAN_RAYLIB_ALLOC_NATIVE
    free(p);
#else
    lean_free_small_object((lean_object*)p);
#endif
}

/// @param stream \@& AudioStream
/// @param callback nullable
static inline void lean_raylib_AudioStream_setCallback(b_lean_obj_arg stream, AudioCallback callback) {
    SetAudioStreamCallback(*((AudioStream*)lean_get_external_data(stream)), callback);
}

static inline void* lean_raylib_WindowHandle_unbox (b_lean_obj_arg handle) {
    return lean_get_external_data(handle);
}
