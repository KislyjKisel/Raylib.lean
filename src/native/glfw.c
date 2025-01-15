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

LEAN_EXPORT lean_obj_res lean_raylib_glfw_initHint(int32_t hint, b_lean_obj_arg value) {
    unsigned int value_tag = lean_obj_tag(value);
    int value_c;
    switch (value_tag) {
        case 0:
            value_c = (int32_t)lean_ctor_get_uint32(value, 0);
            break;
        case 1:
            value_c = GLFW_FALSE;
            break;
        case 2:
            value_c = GLFW_TRUE;
            break;
        case 3:
            value_c = GLFW_ANY_PLATFORM;
            break;
        case 4:
            value_c = GLFW_PLATFORM_WIN32;
            break;
        case 5:
            value_c = GLFW_PLATFORM_COCOA;
            break;
        case 6:
            value_c = GLFW_PLATFORM_WAYLAND;
            break;
        case 7:
            value_c = GLFW_PLATFORM_X11;
            break;
        case 8:
            value_c = GLFW_PLATFORM_NULL;
            break;
        case 9:
            value_c = GLFW_ANGLE_PLATFORM_TYPE_NONE;
            break;
        case 10:
            value_c = GLFW_ANGLE_PLATFORM_TYPE_OPENGL;
            break;
        case 11:
            value_c = GLFW_ANGLE_PLATFORM_TYPE_OPENGLES;
            break;
        case 12:
            value_c = GLFW_ANGLE_PLATFORM_TYPE_D3D9;
            break;
        case 13:
            value_c = GLFW_ANGLE_PLATFORM_TYPE_D3D11;
            break;
        case 14:
            value_c = GLFW_ANGLE_PLATFORM_TYPE_VULKAN;
            break;
        case 15:
            value_c = GLFW_ANGLE_PLATFORM_TYPE_METAL;
            break;
        case 16:
            value_c = GLFW_WAYLAND_DISABLE_LIBDECOR;
            break;
        case 17:
            value_c = GLFW_WAYLAND_PREFER_LIBDECOR;
            break;
        default:
            value_c = 0;
            break;
    };
    glfwInitHint(hint, value_c);
    lean_raylib_glfw_tryError();
    return lean_io_result_mk_ok(lean_box(0));
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
    int32_t xpos, int32_t ypos, uint32_t width, uint32_t height, b_lean_obj_arg refreshRate,
    lean_obj_arg io_
) {
    GLFWmonitor* monitor_c = NULL;
    if (lean_option_is_some(monitor)) {
        monitor_c = lean_raylib_glfw_Monitor_fromRepr(lean_ctor_get(monitor, 0));
    }
    int refreshRate_value;
    if (lean_option_is_some(refreshRate)) {
        refreshRate_value = lean_unbox_uint32(lean_ctor_get(refreshRate, 0));
    }
    else {
        refreshRate_value = GLFW_DONT_CARE;
    }
    glfwSetWindowMonitor(
        lean_raylib_glfw_Window_fromRepr(window),
        monitor_c,
        xpos,
        ypos,
        width, height,
        refreshRate_value
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

LEAN_EXPORT lean_obj_res lean_raylib_glfw_swapInterval(int32_t interval, lean_obj_arg io_) {
    glfwSwapInterval(interval);
    lean_raylib_glfw_tryError();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib_glfw_extensionSupported(b_lean_obj_arg extension, lean_obj_arg io_) {
    int res = glfwExtensionSupported(lean_string_cstr(extension));
    lean_raylib_glfw_tryError();
    return lean_io_result_mk_ok(lean_box(res == GLFW_TRUE));
}
