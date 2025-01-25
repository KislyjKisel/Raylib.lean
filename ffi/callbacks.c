#include <string.h>
#include <lean/lean.h>
#include <lean_pod.h>
#include <raylib.h>
#include "include/raylib_lean.h"

static lean_object* lean_raylib_TraceLogCallback_current = NULL;
static lean_object* lean_raylib_LoadFileDataCallback_current = NULL;
static lean_object* lean_raylib_SaveFileDataCallback_current = NULL;
static lean_object* lean_raylib_LoadFileTextCallback_current = NULL;
static lean_object* lean_raylib_SaveFileTextCallback_current = NULL;

#ifdef LEAN_RAYLIB_FORK
static lean_object* lean_raylib_AudioThreadEntryCallback_current = NULL;
static lean_object* lean_raylib_AudioThreadExitCallback_current = NULL;
#endif

static void lean_raylib_TraceLogCallback_wrapper(int logLevel, const char* text, va_list args) {
    assert(lean_raylib_TraceLogCallback_current != NULL);
    lean_inc_ref(lean_raylib_TraceLogCallback_current);
    lean_raylib_VaList_data args_wrapped;
    va_copy(args_wrapped.v, args);
    // EST2.Result
    lean_object* result = lean_apply_6(
        lean_raylib_TraceLogCallback_current,
        lean_box(0),
        lean_box_uint32(logLevel),
        lean_mk_string(text),
        lean_raylib_VaList_box(&args_wrapped),
        lean_box(0),
        lean_box(0)
    );
    if(lean_ptr_tag(result) == 1) {
        lean_io_result_show_error(result);
    }
    lean_dec_ref(result);
    va_end(args_wrapped.v);
}

static unsigned char* lean_raylib_LoadFileDataCallback_wrapper(const char* fileName, int* dataSize) {
    assert(lean_raylib_LoadFileDataCallback_current != NULL);
    lean_inc_ref(lean_raylib_LoadFileDataCallback_current);
    lean_object* bytes_iores = lean_apply_2(
        lean_raylib_LoadFileDataCallback_current,
        lean_mk_string(fileName),
        lean_box(0)
    );
    if(lean_io_result_is_error(bytes_iores)) {
        lean_io_result_show_error(bytes_iores);
        lean_dec_ref(bytes_iores);
        TraceLog(LOG_WARNING, "FILEIO: [%s] Failed to load file data (custom callback)", fileName);
        return NULL;
    }
    lean_object* bytes_box = lean_io_result_get_value(bytes_iores); // borrow
    size_t size = lean_sarray_byte_size(bytes_box);
    unsigned char* bytes_c = RL_MALLOC(size);
    memcpy(bytes_c, lean_sarray_cptr(bytes_box), size);
    lean_dec_ref(bytes_iores);
    *dataSize = size;
    return bytes_c;
}

static bool lean_raylib_SaveFileDataCallback_wrapper(const char* fileName, void* data, int dataSize) {
    assert(lean_raylib_SaveFileDataCallback_current != NULL);
    lean_inc_ref(lean_raylib_SaveFileDataCallback_current);
    // EST2.Result
    lean_object* success_iores = lean_apply_6(
        lean_raylib_SaveFileDataCallback_current,
        lean_box(0),
        lean_mk_string(fileName),
        lean_uint32_to_nat(dataSize),
        lean_pod_BytesRef_box(data),
        lean_box(0),
        lean_box(0)
    );
    if(lean_ptr_tag(success_iores) == 1) {
        lean_io_result_show_error(success_iores);
        // lean_object* err = lean_ctor_get(success_iores, 0);
        // lean_inc_ref(err);
        // lean_object* str = lean_io_error_to_string(err);
        // fprintf(stderr, "uncaught exception: %s\n", lean_string_cstr(str));
        // lean_dec_ref(str);
        lean_dec_ref(success_iores);
        TraceLog(LOG_WARNING, "FILEIO: [%s] Failed to save file data (custom callback)", fileName);
        return false;
    }
    bool success = lean_unbox(lean_ctor_get(success_iores, 0));
    lean_dec_ref(success_iores);
    return success;
}

static char* lean_raylib_LoadFileTextCallback_wrapper(const char* fileName) {
    assert(lean_raylib_LoadFileTextCallback_current != NULL);
    lean_inc_ref(lean_raylib_LoadFileTextCallback_current);
    lean_object* text_iores = lean_apply_2(
        lean_raylib_LoadFileTextCallback_current,
        lean_mk_string(fileName),
        lean_box(0)
    );
    if(lean_io_result_is_error(text_iores)) {
        lean_io_result_show_error(text_iores);
        lean_dec_ref(text_iores);
        TraceLog(LOG_WARNING, "FILEIO: [%s] Failed to load file text (custom callback)", fileName);
        return false;
    }
    lean_object* text = lean_io_result_get_value(text_iores); // borrow
    size_t textSize = lean_string_capacity(text);
    char* text_c = RL_MALLOC(textSize);
    memcpy(text_c, lean_string_cstr(text), textSize);
    lean_dec_ref(text_iores);
    return text_c;
}

static bool lean_raylib_SaveFileTextCallback_wrapper(const char* fileName, char* text) {
    assert(lean_raylib_SaveFileTextCallback_current != NULL);
    lean_inc_ref(lean_raylib_SaveFileTextCallback_current);
    lean_object* success_iores = lean_apply_3(
        lean_raylib_SaveFileTextCallback_current,
        lean_mk_string(fileName),
        lean_mk_string(text),
        lean_box(0)
    );
    if(lean_io_result_is_error(success_iores)) {
        lean_io_result_show_error(success_iores);
        lean_dec_ref(success_iores);
        TraceLog(LOG_WARNING, "FILEIO: [%s] Failed to save file text (custom callback)", fileName);
        return false;
    }
    bool success = lean_unbox(lean_io_result_get_value(success_iores));
    lean_dec_ref(success_iores);
    return success;
}

#ifdef LEAN_RAYLIB_FORK
void lean_initialize_thread(void);
void lean_finalize_thread(void);

static void lean_raylib_AudioThreadEntryCallback_wrapper(void) {
    assert(lean_raylib_AudioThreadEntryCallback_current != NULL);
    lean_initialize_thread();
    lean_inc_ref(lean_raylib_AudioThreadEntryCallback_current);
    lean_dec_ref(lean_apply_1(
        lean_raylib_AudioThreadEntryCallback_current,
        lean_box(0)
    ));
}

static void lean_raylib_AudioThreadExitCallback_wrapper(void) {
    assert(lean_raylib_AudioThreadExitCallback_current != NULL);
    lean_inc_ref(lean_raylib_AudioThreadExitCallback_current);
    lean_dec_ref(lean_apply_1(
        lean_raylib_AudioThreadExitCallback_current,
        lean_box(0)
    ));
    lean_finalize_thread();
}
#endif

#define LEAN_RAYLIB_CALLBACK_SET_RESET(action)\
LEAN_EXPORT lean_obj_res lean_raylib__Set##action##Callback (lean_obj_arg callback, lean_obj_arg world) {\
    if (lean_raylib_##action##Callback_current != NULL) {\
        lean_dec_ref(lean_raylib_##action##Callback_current);\
    }\
    lean_mark_mt(callback);\
    lean_raylib_##action##Callback_current = callback;\
    Set##action##Callback(lean_raylib_##action##Callback_wrapper);\
    return lean_io_result_mk_ok(lean_box(0));\
}\
LEAN_EXPORT lean_obj_res lean_raylib__Reset##action##Callback (lean_obj_arg world) {\
    Set##action##Callback(NULL);\
    if(lean_raylib_##action##Callback_current != NULL) {\
        lean_dec_ref(lean_raylib_##action##Callback_current);\
        lean_raylib_##action##Callback_current = NULL;\
    }\
    return lean_io_result_mk_ok(lean_box(0));\
}

LEAN_RAYLIB_CALLBACK_SET_RESET(TraceLog);
LEAN_RAYLIB_CALLBACK_SET_RESET(LoadFileData);
LEAN_RAYLIB_CALLBACK_SET_RESET(SaveFileData);
LEAN_RAYLIB_CALLBACK_SET_RESET(LoadFileText);
LEAN_RAYLIB_CALLBACK_SET_RESET(SaveFileText);

#ifdef LEAN_RAYLIB_FORK
LEAN_RAYLIB_CALLBACK_SET_RESET(AudioThreadEntry);
LEAN_RAYLIB_CALLBACK_SET_RESET(AudioThreadExit);
#else
LEAN_EXPORT lean_obj_res lean_raylib__SetAudioThreadEntryCallback (lean_obj_arg callback, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(0));
}
LEAN_EXPORT lean_obj_res lean_raylib__ResetAudioThreadEntryCallback (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(0));
}
LEAN_EXPORT lean_obj_res lean_raylib__SetAudioThreadExitCallback (lean_obj_arg callback, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(0));
}
LEAN_EXPORT lean_obj_res lean_raylib__ResetAudioThreadExitCallback (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(0));
}
#endif

// BELOW: TODO

#ifdef LEAN_RAYLIB_FORK
static void lean_raylib_AudioStreamCallback_wrapper(void* bufferData, unsigned int frames, void* userdata) {
    lean_object* callback = userdata;
    lean_inc_ref(callback);
    lean_dec_ref(lean_apply_5(
        callback,
        lean_box(0),
        lean_usize_to_nat(frames),
        lean_pod_BytesRef_box(bufferData),
        lean_box(0),
        lean_box(0)
    ));
}
#endif

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamCallback (uint32_t st, b_lean_obj_arg stream_box, lean_obj_arg callback, lean_obj_arg world) {
#ifdef LEAN_RAYLIB_FORK
    lean_mark_mt(callback);
    lean_raylib_AudioStream_data* stream = lean_raylib_AudioStream_fromRepr(stream_box);
    if(stream->callback != NULL) {
        lean_dec_ref(stream->callback);
    }
    stream->callback = callback;
    SetAudioStreamCallback(stream->stream, lean_raylib_AudioStreamCallback_wrapper, callback);
#else
    lean_dec_ref(callback);
#endif
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__AttachAudioStreamProcessor (uint32_t st, b_lean_obj_arg stream, lean_obj_arg processor, lean_obj_arg io_) {
#ifdef LEAN_RAYLIB_FORK
    AttachAudioStreamProcessor(
        lean_raylib_AudioStream_fromRepr(stream)->stream,
        lean_raylib_AudioStreamCallback_wrapper,
        processor
    );
#endif
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DetachAudioStreamProcessor (uint32_t st, b_lean_obj_arg stream, lean_obj_arg processor, lean_obj_arg io_) {
#ifdef LEAN_RAYLIB_FORK
    bool success = DetachAudioStreamProcessor(
        lean_raylib_AudioStream_fromRepr(stream)->stream,
        lean_raylib_AudioStreamCallback_wrapper,
        processor
    );
    if (success) {
        lean_dec_ref(processor);
    }
    return lean_io_result_mk_ok(lean_box(success));
#else
    return lean_io_result_mk_ok(lean_box(false));
#endif
}

LEAN_EXPORT lean_obj_res lean_raylib__AttachAudioMixedProcessor (lean_obj_arg processor, lean_obj_arg io_) {
#ifdef LEAN_RAYLIB_FORK
    AttachAudioMixedProcessor(lean_raylib_AudioStreamCallback_wrapper, processor);
#endif
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DetachAudioMixedProcessor (b_lean_obj_arg processor, lean_obj_arg io_) {
#ifdef LEAN_RAYLIB_FORK
    bool success = DetachAudioMixedProcessor(lean_raylib_AudioStreamCallback_wrapper, processor);
    if (success) {
        lean_dec_ref(processor);
    }
    return lean_io_result_mk_ok(lean_box(success));
#else
    return lean_io_result_mk_ok(lean_box(false));
#endif
}
