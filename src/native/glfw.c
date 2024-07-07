#include <lean/lean.h>
#include <GLFW/glfw3.h>
#include "include/raylib_lean.h"

static inline lean_obj_res lean_raylib_glfw_error_impl(int code, const char* description) {
    lean_object* description_box = (description == NULL) ? lean_mk_string("") : lean_mk_string(description);
    lean_object* error_box = LEAN_POD_ALLOC_CTOR(LEAN_RAYLIB_GLFW_Error_LAYOUT);
    LEAN_POD_CTOR_SET(error_box, lean_raylib_glfw_ErrorCode_toRepr(code), LEAN_RAYLIB_GLFW_Error_code);
    LEAN_POD_CTOR_SET(error_box, description_box, LEAN_RAYLIB_GLFW_Error_description);
    return lean_io_result_mk_error(error_box);
}

static inline lean_obj_res lean_raylib_glfw_error(void) {
    const char* description = NULL;
    int code = glfwGetError(&description);
    return lean_raylib_glfw_error_impl(code, description);
}

#define lean_raylib_glfw_tryError()\
{\
    const char* te_description__ = NULL;\
    int te_code__ = glfwGetError(&te_description__);\
    if (te_code__ != GLFW_NO_ERROR) {\
        return lean_raylib_glfw_error_impl(te_code__, te_description__);\
    }\
}

LEAN_EXPORT lean_obj_res lean_raylib_glfw_Window_mk(lean_raylib_WindowBackendHandle handle) {
    return lean_raylib_glfw_Window_mk_(handle);
}

LEAN_EXPORT lean_obj_res lean_raylib_glfw_getPrimaryMonitor(lean_obj_arg io_) {
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    if (monitor == NULL) {
        return lean_raylib_glfw_error();
    }
    return lean_io_result_mk_ok(lean_raylib_glfw_Monitor_box(monitor));
}

LEAN_EXPORT lean_obj_res lean_raylib_glfw_setWindowMonitor(
    lean_raylib_glfw_Window window, lean_raylib_glfw_Monitor monitor,
    lean_pod_Int32 xpos, lean_pod_Int32 ypos, uint32_t width, uint32_t height, uint32_t refreshRate,
    lean_obj_arg io_
) {
    GLFWmonitor* monitor_c = NULL;
    if (lean_option_is_some(monitor)) {
        monitor_c = lean_raylib_glfw_Monitor_fromRepr(lean_ctor_get(monitor, 0));
    }
    glfwSetWindowMonitor(
        lean_raylib_glfw_Window_fromRepr(window),
        monitor_c,
        lean_pod_Int32_fromRepr(xpos),
        lean_pod_Int32_fromRepr(ypos),
        width, height, refreshRate
    );
    lean_raylib_glfw_tryError();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib_glfw_getVideoModes(lean_raylib_glfw_Monitor monitor, lean_obj_arg io_) {
    int count;
    const GLFWvidmode* modes = glfwGetVideoModes(lean_raylib_glfw_Monitor_fromRepr(monitor), &count);
    if (LEAN_UNLIKELY(modes == NULL)) {
        return lean_raylib_glfw_error();
    }
    lean_object* arr = lean_alloc_array(count, count);
    for (int i = 0; i < count; ++i) {
        lean_array_set_core(arr, i, lean_raylib_glfw_VideoMode_box(&modes[i]));
    }
    return lean_io_result_mk_ok(arr);
}

LEAN_EXPORT lean_obj_res lean_raylib_glfw_getVideoMode(lean_raylib_glfw_Monitor monitor, lean_obj_arg io_) {
    const GLFWvidmode* mode = glfwGetVideoMode(lean_raylib_glfw_Monitor_fromRepr(monitor));
    if (LEAN_UNLIKELY(mode == NULL)) {
        return lean_raylib_glfw_error();
    }
    return lean_io_result_mk_ok(lean_raylib_glfw_VideoMode_box(mode));
}
