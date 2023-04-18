#include <string.h>
#include <lean_pod.h>
#include "util.h"

static lean_object* lean_raylib_TraceLogCallback_current = NULL;
static lean_object* lean_raylib_LoadFileDataCallback_current = NULL;
static lean_object* lean_raylib_SaveFileDataCallback_current = NULL;
static lean_object* lean_raylib_LoadFileTextCallback_current = NULL;
static lean_object* lean_raylib_SaveFileTextCallback_current = NULL;

static unsigned char* lean_raylib_LoadFileDataCallback_wrapper(const char* fileName, unsigned int* bytesRead) {
    assert(lean_raylib_LoadFileDataCallback_current != NULL);
    lean_object* fileName_box = lean_mk_string(fileName);
    lean_inc_ref(lean_raylib_LoadFileDataCallback_current);
    lean_object* bytes_iores = lean_apply_2(lean_raylib_LoadFileDataCallback_current, fileName_box, lean_box(0));
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
    *bytesRead = size;
    return bytes_c;
}

static bool lean_raylib_SaveFileDataCallback_wrapper(const char* fileName, void* data, unsigned int bytesToWrite) {
    assert(lean_raylib_SaveFileDataCallback_current != NULL);
    lean_object* fileName_box = lean_mk_string(fileName);
    lean_object* view = lean_pod_BytesView_wrap(data, NULL);
    lean_inc_ref(lean_raylib_SaveFileDataCallback_current);
    // EST2.Result
    lean_object* success_iores = lean_apply_6(
        lean_raylib_SaveFileDataCallback_current,
        lean_box(0),
        fileName_box,
        lean_box_usize(bytesToWrite),
        view,
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
    lean_object* fileName_box = lean_mk_string(fileName);
    lean_inc_ref(lean_raylib_LoadFileTextCallback_current);
    lean_object* text_iores = lean_apply_2(lean_raylib_LoadFileTextCallback_current, fileName_box, lean_box(0));
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
    lean_object* fileName_box = lean_mk_string(fileName);
    lean_object* text_box = lean_mk_string(text);
    lean_inc_ref(lean_raylib_SaveFileTextCallback_current);
    lean_object* success_iores = lean_apply_3(lean_raylib_SaveFileTextCallback_current, fileName_box, text_box, lean_box(0));
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

#define LEAN_RAYLIB_CALLBACK_RESET(action)\
LEAN_EXPORT lean_obj_res lean_raylib__Reset##action##Callback (lean_obj_arg world) {\
    Set##action##Callback(NULL);\
    if(lean_raylib_##action##Callback_current != NULL) {\
        lean_dec_ref(lean_raylib_##action##Callback_current);\
        lean_raylib_##action##Callback_current = NULL;\
    }\
    return lean_io_result_mk_ok(lean_box(0));\
}

#define LEAN_RAYLIB_CALLBACK_SET_RESET(action)\
LEAN_EXPORT lean_obj_res lean_raylib__Set##action##Callback (lean_obj_arg callback, lean_obj_arg world) {\
    if (lean_raylib_##action##Callback_current != NULL) {\
        lean_dec_ref(lean_raylib_##action##Callback_current);\
    }\
    lean_raylib_##action##Callback_current = callback;\
    Set##action##Callback(lean_raylib_##action##Callback_wrapper);\
    return lean_io_result_mk_ok(lean_box(0));\
}\
LEAN_RAYLIB_CALLBACK_RESET(action)

LEAN_RAYLIB_CALLBACK_RESET(TraceLog);
LEAN_RAYLIB_CALLBACK_SET_RESET(LoadFileData);
LEAN_RAYLIB_CALLBACK_SET_RESET(SaveFileData);
LEAN_RAYLIB_CALLBACK_SET_RESET(LoadFileText);
LEAN_RAYLIB_CALLBACK_SET_RESET(SaveFileText);
