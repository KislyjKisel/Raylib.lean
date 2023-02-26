#include <lean/lean.h>
#include <raylib.h>

/// @param stream \@& AudioStream
/// @param callback nullable
static inline void lean_raylib_AudioStream_setCallback(b_lean_obj_arg stream, AudioCallback callback) {
    SetAudioStreamCallback(*((AudioStream*)lean_get_external_data(stream)), callback);
}
