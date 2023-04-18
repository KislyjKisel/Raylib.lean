#pragma once

#include <lean/lean.h>
#include <raylib.h>

#define LEAN_RAYLIB_FFCALL

#ifdef LEAN_RAYLIB_FFCALL
static inline AudioCallback lean_raylib_AudioStream_mkCallback(b_lean_obj_arg cb) {

}
#endif
