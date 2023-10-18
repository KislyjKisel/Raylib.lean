#include <string.h>
#include "util.h"
#include "structures.h"

LEAN_EXPORT lean_obj_res lean_raylib__InitWindow (uint32_t width, uint32_t height, b_lean_obj_arg title, lean_obj_arg world) {
    lean_raylib_Context ctx;
    size_t titleSize = lean_raylib_Substring_utf8_byte_size(title);
    ctx.title = lean_raylib_rlmemdup(lean_raylib_Substring_cptr(title), titleSize + 1);
    ctx.title[titleSize] = '\0';
    InitWindow(width, height, ctx.title);
    return lean_io_result_mk_ok(lean_raylib_Context_new(ctx));
}

LEAN_EXPORT lean_obj_res lean_raylib__WindowShouldClose (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(WindowShouldClose()));
}

LEAN_EXPORT lean_obj_res lean_raylib__CloseWindow (lean_obj_arg ctx, lean_obj_arg world) {
    lean_dec_ref(ctx);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsWindowReady (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsWindowReady()));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsWindowFullscreen (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsWindowFullscreen()));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsWindowHidden (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsWindowHidden()));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsWindowMinimized (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsWindowMinimized()));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsWindowMaximized (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsWindowMaximized()));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsWindowFocused (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsWindowFocused()));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsWindowResized (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsWindowResized()));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsWindowState (uint32_t flag, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsWindowState(flag)));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowState (uint32_t flags, lean_obj_arg world) {
    SetWindowState(flags);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ClearWindowState (uint32_t flags, lean_obj_arg world) {
    ClearWindowState(flags);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ToggleFullscreen (lean_obj_arg world) {
    ToggleFullscreen();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__MaximizeWindow (lean_obj_arg world) {
    MaximizeWindow();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__MinimizeWindow (lean_obj_arg world) {
    MinimizeWindow();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__RestoreWindow (lean_obj_arg world) {
    RestoreWindow();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowIcon (b_lean_obj_arg image, lean_obj_arg world) {
    SetWindowIcon(*lean_raylib_Image_from(image)); // image data copied by glfw (glfwSetWindowIcon)
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowIcons (b_lean_obj_arg images_box, lean_obj_arg world) {
    size_t count = lean_array_size(images_box);
    Image* images_c = malloc(count * sizeof(Image));
    for(size_t i = 0; i < count; ++i) {
        images_c[i] = *lean_raylib_Image_from(lean_array_get_core(images_box, i));
    }
    SetWindowIcons(images_c, count);
    free(images_c);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowTitle (lean_obj_arg ctxObj, b_lean_obj_arg title, lean_obj_arg world) {
    lean_raylib_Context* ctx = lean_get_external_data(ctxObj);
    size_t titleSize = lean_raylib_Substring_utf8_byte_size(title);
    char* newTitle = lean_raylib_rlmemdup(lean_raylib_Substring_cptr(title), titleSize + 1);
    newTitle[titleSize] = '\0';
    SetWindowTitle(newTitle);
    RL_FREE(ctx->title);
    ctx->title = newTitle;
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowPosition (uint32_t x, uint32_t y, lean_obj_arg world) {
    SetWindowPosition(x, y);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowMonitor (uint32_t monitor, lean_obj_arg world) {
    SetWindowMonitor(monitor);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowMinSize (uint32_t width, uint32_t height, lean_obj_arg world) {
    SetWindowMinSize(width, height);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowSize (uint32_t width, uint32_t height, lean_obj_arg world) {
    SetWindowSize(width, height);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowOpacity (uint32_t opacity, lean_obj_arg world) {
    SetWindowOpacity(lean_pod_Float32_fromBits(opacity));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWindowHandle (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_WindowHandle_box(GetWindowHandle()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetScreenWidth (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetScreenWidth()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetScreenHeight (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetScreenHeight()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRenderWidth (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetRenderWidth()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRenderHeight (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetRenderHeight()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMonitorCount (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetMonitorCount()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetCurrentMonitor (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetCurrentMonitor()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMonitorPosition (uint32_t monitor, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetMonitorPosition(monitor)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMonitorWidth (uint32_t monitor, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetMonitorWidth(monitor)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMonitorHeight (uint32_t monitor, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetMonitorHeight(monitor)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMonitorPhysicalWidth (uint32_t monitor, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetMonitorPhysicalWidth(monitor)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMonitorPhysicalHeight (uint32_t monitor, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetMonitorPhysicalHeight(monitor)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMonitorRefreshRate (uint32_t monitor, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetMonitorRefreshRate(monitor)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWindowPosition (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetWindowPosition()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWindowScaleDPI (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetWindowScaleDPI()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMonitorName (uint32_t monitor, lean_obj_arg world) {
    const char * monitorName = GetMonitorName(monitor); // freed by GLFW (glfwGetMonitorName)
    return lean_io_result_mk_ok(lean_mk_string(monitorName));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetClipboardText (b_lean_obj_arg text, lean_obj_arg world) {
    SetClipboardText(lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetClipboardText (lean_obj_arg world) {
    const char * clipboardText = GetClipboardText(); // freed by GLFW (glfwGetClipboardString)
    return lean_io_result_mk_ok(lean_mk_string(clipboardText));
}

LEAN_EXPORT lean_obj_res lean_raylib__EnableEventWaiting (lean_obj_arg world) {
    EnableEventWaiting();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DisableEventWaiting (lean_obj_arg world) {
    DisableEventWaiting();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SwapScreenBuffer (lean_obj_arg world) {
    SwapScreenBuffer();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__PollInputEvents (lean_obj_arg world) {
    PollInputEvents();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__WaitTime (uint32_t seconds, lean_obj_arg world) {
    WaitTime(lean_pod_Float32_fromBits(seconds));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ShowCursor (lean_obj_arg world) {
    ShowCursor();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__HideCursor (lean_obj_arg world) {
    HideCursor();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsCursorHidden (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsCursorHidden()));
}

LEAN_EXPORT lean_obj_res lean_raylib__EnableCursor (lean_obj_arg world) {
    EnableCursor();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DisableCursor (lean_obj_arg world) {
    DisableCursor();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsCursorOnScreen (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsCursorOnScreen()));
}

LEAN_EXPORT lean_obj_res lean_raylib__ClearBackground (uint32_t color, lean_obj_arg world) {
    ClearBackground(lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginDrawing (lean_obj_arg world) {
    BeginDrawing();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndDrawing (lean_obj_arg world) {
    EndDrawing();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginMode2D (b_lean_obj_arg camera, lean_obj_arg world) {
    BeginMode2D(lean_raylib_Camera2D_from(camera));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndMode2D (lean_obj_arg world) {
    EndMode2D();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginMode3D (b_lean_obj_arg camera, lean_obj_arg world) {
    BeginMode3D(lean_raylib_Camera3D_from(camera));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndMode3D (lean_obj_arg world) {
    EndMode3D();
    return lean_io_result_mk_ok(lean_box(0));
}


static lean_object* lean_raylib_currentRenderTexture = NULL;

LEAN_EXPORT lean_obj_res lean_raylib__BeginTextureMode (lean_obj_arg target, lean_obj_arg world) {
    BeginTextureMode(*lean_raylib_RenderTexture_from(target));
    if(lean_raylib_currentRenderTexture != NULL) {
        lean_dec_ref(lean_raylib_currentRenderTexture);
    }
    lean_raylib_currentRenderTexture = target;
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndTextureMode (lean_obj_arg world) {
    EndTextureMode();
    if(lean_raylib_currentRenderTexture != NULL) {
        lean_dec_ref(lean_raylib_currentRenderTexture);
        lean_raylib_currentRenderTexture = NULL;
    }
    return lean_io_result_mk_ok(lean_box(0));
}

static lean_object* lean_raylib_currentShader = NULL;

LEAN_EXPORT lean_obj_res lean_raylib__BeginShaderMode (lean_obj_arg shader, lean_obj_arg world) {
    BeginShaderMode(*lean_raylib_Shader_from(shader));
    if(lean_raylib_currentShader != NULL) {
        lean_dec_ref(lean_raylib_currentShader);
    }
    lean_raylib_currentShader = shader;
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndShaderMode (lean_obj_arg world) {
    EndShaderMode();
    if(lean_raylib_currentShader != NULL) {
        lean_dec_ref(lean_raylib_currentShader);
        lean_raylib_currentShader = NULL;
    }
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginBlendMode (uint32_t mode, lean_obj_arg world) {
    BeginBlendMode(mode);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndBlendMode (lean_obj_arg world) {
    EndBlendMode();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginScissorMode (uint32_t x, uint32_t y, uint32_t width, uint32_t height, lean_obj_arg world) {
    BeginScissorMode(x, y, width, height);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndScissorMode (lean_obj_arg world) {
    EndScissorMode();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginVrStereoMode (b_lean_obj_arg config, lean_obj_arg world) {
    BeginVrStereoMode(lean_raylib_VrStereoConfig_from(config));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndVrStereoMode (lean_obj_arg world) {
    EndVrStereoMode();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadVrStereoConfig (b_lean_obj_arg device, lean_obj_arg world) {
    VrStereoConfig vrStereoConfig = LoadVrStereoConfig(lean_raylib_VrDeviceInfo_from(device));
    return lean_raylib_VrStereoConfig_to(&vrStereoConfig);
}

LEAN_EXPORT lean_obj_res lean_raylib__UnloadVrStereoConfig (b_lean_obj_arg config, lean_obj_arg world) {
    UnloadVrStereoConfig(lean_raylib_VrStereoConfig_from(config));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadShader (
    lean_obj_arg ctx, b_lean_obj_arg vsFileName_opt, b_lean_obj_arg fsFileName_opt, lean_obj_arg world
) {
    const char* vsFileName = NULL;
    if(lean_option_is_some(vsFileName_opt)) {
        vsFileName = lean_string_cstr(lean_ctor_get(vsFileName_opt, 0));
    }
    const char* fsFileName = NULL;
    if(lean_option_is_some(fsFileName_opt)) {
        fsFileName = lean_string_cstr(lean_ctor_get(fsFileName_opt, 0));
    }
    return lean_io_result_mk_ok(lean_raylib_Shader_to(
        LoadShader(vsFileName, fsFileName),
        ctx
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadShaderFromMemory (
    lean_obj_arg ctx, b_lean_obj_arg vsCode_opt, b_lean_obj_arg fsCode_opt, lean_obj_arg world
) {
    const char* vsCode = NULL;
    if(lean_option_is_some(vsCode_opt)) {
        vsCode = lean_string_cstr(lean_ctor_get(vsCode_opt, 0));
    }
    const char* fsCode = NULL;
    if(lean_option_is_some(fsCode_opt)) {
        fsCode = lean_string_cstr(lean_ctor_get(fsCode_opt, 0));
    }
    return lean_io_result_mk_ok(lean_raylib_Shader_to(
        LoadShaderFromMemory(vsCode, fsCode),
        ctx
    ));
}

LEAN_EXPORT uint8_t lean_raylib__IsShaderReady (b_lean_obj_arg shader) {
    return IsShaderReady(*lean_raylib_Shader_from(shader));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetShaderLocation (lean_obj_arg shader, b_lean_obj_arg uniformName) {
    int location = GetShaderLocation(*lean_raylib_Shader_from(shader), lean_string_cstr(uniformName));
    if (location < 0) {
        return lean_mk_option_none();
    }
    else {
        return lean_mk_option_some(lean_box_uint32(location));
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__GetShaderLocationAttrib (b_lean_obj_arg shader, b_lean_obj_arg attribName) {
    int location = GetShaderLocationAttrib(*lean_raylib_Shader_from(shader), lean_string_cstr(attribName));
    if (location < 0) {
        return lean_mk_option_none();
    }
    else {
        return lean_mk_option_some(lean_box_uint32(location));
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValue (b_lean_obj_arg shader_box, uint32_t loc, uint32_t uniformType, b_lean_obj_arg value_box, lean_obj_arg world) {
    Shader shader = *lean_raylib_Shader_from(shader_box);
    switch(uniformType) {
        case SHADER_UNIFORM_FLOAT: {
            float value = lean_pod_Float32_unbox(value_box);
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_FLOAT);
            break;
        }
        case SHADER_UNIFORM_VEC2: {
            Vector2 value = lean_raylib_Vector2_from(value_box);
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_VEC2);
            break;
        }
        case SHADER_UNIFORM_VEC3: {
            Vector3 value = lean_raylib_Vector3_from(value_box);
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_VEC3);
            break;
        }
        case SHADER_UNIFORM_VEC4: {
            Vector4 value = lean_raylib_Vector4_from(value_box);
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_VEC4);
            break;
        }
        case SHADER_UNIFORM_INT: {
            int value = lean_unbox_uint32(value_box);
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_INT);
            break;
        }
        case SHADER_UNIFORM_IVEC2: {
            int value[2];
            value[0] = lean_unbox_uint32(lean_ctor_get(value_box, 0));
            value[1] = lean_unbox_uint32(lean_ctor_get(value_box, 1));
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_IVEC2);
            break;
        }
        case SHADER_UNIFORM_IVEC3: {
            int value[3];
            value[0] = lean_unbox_uint32(lean_ctor_get(value_box, 0));
            value[1] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(value_box, 1), 0));
            value[2] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(value_box, 1), 1));
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_IVEC3);
            break;
        }
        case SHADER_UNIFORM_IVEC4: {
            int value[4];
            value[0] = lean_unbox_uint32(lean_ctor_get(value_box, 0));
            value[1] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(value_box, 1), 0));
            value[2] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(lean_ctor_get(value_box, 1), 1), 0));
            value[3] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(lean_ctor_get(value_box, 1), 1), 1));
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_IVEC4);
            break;
        }
        case SHADER_UNIFORM_SAMPLER2D: {
            uint32_t value = lean_unbox_uint32(value_box);
            SetShaderValue(shader, loc, &value, SHADER_UNIFORM_SAMPLER2D);
            break;
        }
    }
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueV (b_lean_obj_arg shader_box, uint32_t loc, uint32_t uniformType, b_lean_obj_arg values_box, lean_obj_arg world) {
    Shader shader = *lean_raylib_Shader_from(shader_box);
    size_t count = lean_array_size(values_box);
    switch(uniformType) {
        case SHADER_UNIFORM_FLOAT: {
            float* values = malloc(count * sizeof(float));
            for(size_t i = 0; i < count; ++i) {
                values[i] = lean_pod_Float32_unbox(lean_array_get_core(values_box, i));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_FLOAT, count);
            free(values);
            break;
        }
        case SHADER_UNIFORM_VEC2: {
            Vector2* values = malloc(count * sizeof(Vector2));
            for(size_t i = 0; i < count; ++i) {
                values[i] = lean_raylib_Vector2_from(lean_array_get_core(values_box, i));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_VEC2, count);
            free(values);
            break;
        }
        case SHADER_UNIFORM_VEC3: {
            Vector3* values = malloc(count * sizeof(Vector3));
            for(size_t i = 0; i < count; ++i) {
                values[i] = lean_raylib_Vector3_from(lean_array_get_core(values_box, i));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_VEC3, count);
            free(values);
            break;
        }
        case SHADER_UNIFORM_VEC4: {
            Vector4* values = malloc(count * sizeof(Vector4));
            for(size_t i = 0; i < count; ++i) {
                values[i] = lean_raylib_Vector4_from(lean_array_get_core(values_box, i));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_VEC4, count);
            free(values);
            break;
        }
        case SHADER_UNIFORM_INT: {
            int* values = malloc(count * sizeof(int));
            for(size_t i = 0; i < count; ++i) {
                values[i] = lean_unbox_uint32(lean_array_get_core(values_box, i));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_INT, count);
            free(values);
            break;
        }
        case SHADER_UNIFORM_IVEC2: {
            int* values = malloc(count * sizeof(int[2]));
            for(size_t i = 0; i < count; ++i) {
                lean_object* tuple = lean_array_get_core(values_box, i);
                values[2 * i] = lean_unbox_uint32(lean_ctor_get(tuple, 0));
                values[2 * i + 1] = lean_unbox_uint32(lean_ctor_get(tuple, 1));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_IVEC2, count);
            free(values);
            break;
        }
        case SHADER_UNIFORM_IVEC3: {
            int* values = malloc(count * sizeof(int[3]));
            for(size_t i = 0; i < count; ++i) {
                lean_object* tuple = lean_array_get_core(values_box, i);
                values[3 * i] = lean_unbox_uint32(lean_ctor_get(tuple, 0));
                values[3 * i + 1] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(tuple, 1), 0));
                values[3 * i + 2] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(tuple, 1), 1));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_IVEC3, count);
            free(values);
            break;
        }
        case SHADER_UNIFORM_IVEC4: {
            int* values = malloc(count * sizeof(int[4]));
            for(size_t i = 0; i < count; ++i) {
                lean_object* tuple = lean_array_get_core(values_box, i);
                values[4 * i] = lean_unbox_uint32(lean_ctor_get(tuple, 0));
                values[4 * i + 1] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(tuple, 1), 0));
                values[4 * i + 2] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(lean_ctor_get(tuple, 1), 1), 0));
                values[4 * i + 3] = lean_unbox_uint32(lean_ctor_get(lean_ctor_get(lean_ctor_get(tuple, 1), 1), 1));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_IVEC4, count);
            free(values);
            break;
        }
        case SHADER_UNIFORM_SAMPLER2D: {
            uint32_t* values = malloc(count * sizeof(uint32_t));
            for(size_t i = 0; i < count; ++i) {
                values[i] = lean_unbox_uint32(lean_array_get_core(values_box, i));
            }
            SetShaderValueV(shader, loc, values, SHADER_UNIFORM_SAMPLER2D, count);
            free(values);
            break;
        }
    }
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueMatrix (b_lean_obj_arg shader, uint32_t locIndex, b_lean_obj_arg mat, lean_obj_arg world) {
    SetShaderValueMatrix(*lean_raylib_Shader_from(shader), locIndex, lean_raylib_Matrix_from(mat));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueTexture (b_lean_obj_arg shader, uint32_t locIndex, b_lean_obj_arg texture, lean_obj_arg world) {
    SetShaderValueTexture(*lean_raylib_Shader_from(shader), locIndex, *lean_raylib_Texture_from(texture));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMouseRay (b_lean_obj_arg mousePosition, b_lean_obj_arg camera, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Ray_to(
        GetMouseRay(lean_raylib_Vector2_from(mousePosition), lean_raylib_Camera3D_from(camera))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetCameraMatrix (b_lean_obj_arg camera) {
    return lean_raylib_Matrix_to(GetCameraMatrix(lean_raylib_Camera3D_from(camera)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetCameraMatrix2D (b_lean_obj_arg camera) {
    return lean_raylib_Matrix_to(GetCameraMatrix2D(lean_raylib_Camera2D_from(camera)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWorldToScreen (b_lean_obj_arg position, b_lean_obj_arg camera, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetWorldToScreen(
        lean_raylib_Vector3_from(position),
        lean_raylib_Camera3D_from(camera)
    )));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetScreenToWorld2D (b_lean_obj_arg position, b_lean_obj_arg camera) {
    return lean_raylib_Vector2_to(GetScreenToWorld2D(
        lean_raylib_Vector2_from(position),
        lean_raylib_Camera2D_from(camera)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWorldToScreenEx (
    b_lean_obj_arg position, b_lean_obj_arg camera,
    uint32_t width, uint32_t height, lean_obj_arg world
) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetWorldToScreenEx(
        lean_raylib_Vector3_from(position),
        lean_raylib_Camera3D_from(camera),
        width,
        height
    )));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWorldToScreen2D (lean_obj_arg position, lean_obj_arg camera) {
    return lean_raylib_Vector2_to(GetWorldToScreen2D(
        lean_raylib_Vector2_from(position),
        lean_raylib_Camera2D_from(camera)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetTargetFPS (uint32_t fps, lean_obj_arg world) {
    SetTargetFPS(fps);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetFPS (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetFPS()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetFrameTime (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(lean_pod_Float32_toBits(GetFrameTime())));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetTime (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(lean_pod_Float32_toBits(GetTime())));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRandomValue (uint32_t min, uint32_t max, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetRandomValue(min, max)));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetRandomSeed (uint32_t seed) {
    SetRandomSeed(seed);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__TakeScreenshot (b_lean_obj_arg fileName, lean_obj_arg world) {
    TakeScreenshot(lean_string_cstr(fileName));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetConfigFlags (uint32_t flags, lean_obj_arg world) {
    SetConfigFlags(flags);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__TraceLog (uint32_t logLevel, b_lean_obj_arg text, lean_obj_arg world) {
    {
        const char* s = lean_string_cstr(text);
        while(*s != '\0') {
            if(*s == '%') {
                if(*(s + 1) == '%') {
                    s += 2;
                }
                else {
                    return lean_io_result_mk_error(lean_mk_io_user_error(lean_mk_string(
                        "Lean called TraceLog with text string containing non-literal conversion specification."
                    )));
                }
            }
            else {
                ++s;
            }
        }
    }
    TraceLog(logLevel, lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetTraceLogLevel (uint32_t logLevel, lean_obj_arg world) {
    SetTraceLogLevel(logLevel);
    return lean_io_result_mk_ok(lean_box(0));
}

// "error loading library, ... undefined symbol: MemFree", why?
static void lean_raylib_MemFree(void* p) {
    RL_FREE(p);
}

LEAN_EXPORT lean_obj_res lean_raylib__MemAlloc (b_lean_obj_arg size_nat) {
    size_t size = lean_usize_of_nat(size_nat);
    return lean_pod_Buffer_wrap(MemAlloc(size), lean_raylib_MemFree);
}

LEAN_EXPORT lean_obj_res lean_raylib__MemRealloc (b_lean_obj_arg size1_nat, lean_obj_arg buf_box, b_lean_obj_arg size_nat) {
    size_t size1 = lean_usize_of_nat(size1_nat);
    size_t size = lean_usize_of_nat(size_nat);
    lean_pod_Buffer* buf_c = lean_pod_Buffer_unwrap(buf_box);
    if(lean_is_exclusive(buf_box) && buf_c->free == lean_raylib_MemFree) {
        buf_c->data = MemRealloc(buf_c->data, size);
        return buf_box;
    }
    else {
        void* data_res = MemAlloc(size);
        memcpy(data_res, buf_c->data, size1 <= size ? size1 : size);
        lean_dec_ref(buf_box);
        return lean_pod_Buffer_wrap(data_res, lean_raylib_MemFree);
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__OpenURL (b_lean_obj_arg url, lean_obj_arg world) {
    OpenURL(lean_string_cstr(url));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadFileData (b_lean_obj_arg fileName) {
    unsigned int bytesReadSize;
    unsigned char* bytesRead = LoadFileData(lean_string_cstr(fileName), &bytesReadSize);
    lean_object* arr = lean_alloc_sarray(sizeof(uint8_t), bytesReadSize, bytesReadSize);
    uint8_t* arrBytes = lean_sarray_cptr(arr);
    memcpy(arrBytes, bytesRead, bytesReadSize);
    UnloadFileData(bytesRead);
    return lean_io_result_mk_ok(arr);
}

LEAN_EXPORT lean_obj_res lean_raylib__SaveFileData (b_lean_obj_arg fileName, size_t sz, b_lean_obj_arg data, lean_obj_arg world) {
    lean_pod_BytesView* dataView = lean_pod_BytesView_unwrap(data);
    return lean_io_result_mk_ok(lean_box(
        SaveFileData(lean_string_cstr(fileName), dataView->ptr, sz)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__ExportDataAsCode (size_t sz, b_lean_obj_arg data, b_lean_obj_arg fileName, lean_obj_arg world) {
    lean_pod_BytesView* dataView = lean_pod_BytesView_unwrap(data);
    return lean_io_result_mk_ok(lean_box(
        ExportDataAsCode(dataView->ptr, sz, lean_string_cstr(fileName))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadFileText (b_lean_obj_arg fileName, lean_obj_arg world) {
    char* text = LoadFileText(lean_string_cstr(fileName));
    lean_object* text_box = lean_mk_string(text);
    UnloadFileText(text);
    return lean_io_result_mk_ok(text_box);
}

LEAN_EXPORT lean_obj_res lean_raylib__SaveFileText (b_lean_obj_arg fileName, b_lean_obj_arg text, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(SaveFileText(
        lean_string_cstr(fileName), (char*)lean_string_cstr(text))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__FileExists (b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(FileExists(lean_string_cstr(fileName))));
}

LEAN_EXPORT lean_obj_res lean_raylib__DirectoryExists (b_lean_obj_arg dirPath, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(DirectoryExists(lean_string_cstr(dirPath))));
}

LEAN_EXPORT uint8_t lean_raylib__IsFileExtension (b_lean_obj_arg fileName, b_lean_obj_arg ext) {
    return IsFileExtension(lean_string_cstr(fileName), lean_string_cstr(ext));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetFileLength (b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(
        GetFileLength(lean_string_cstr(fileName))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetFileExtension (b_lean_obj_arg fileName_box) {
    const char * fileName = lean_string_cstr(fileName_box);
    const char * extension = GetFileExtension(fileName);
    if(extension == NULL) {
        return lean_mk_option_none();
    }
    return lean_mk_option_some(lean_box_usize(extension - fileName));
}

LEAN_EXPORT size_t lean_raylib__GetFileName (b_lean_obj_arg filePath) {
    const char* filePathCStr = lean_string_cstr(filePath);
    return GetFileName(filePathCStr) - filePathCStr;
}


// # SECTION STATIC: Uses static internal buffer, don't need to free.

LEAN_EXPORT lean_obj_res lean_raylib__GetFileNameWithoutExt (b_lean_obj_arg filePath) {
    return lean_mk_string(GetFileNameWithoutExt(lean_string_cstr(filePath)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetDirectoryPath (b_lean_obj_arg filePath) {
    return lean_mk_string(GetDirectoryPath(lean_string_cstr(filePath)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetPrevDirectoryPath (b_lean_obj_arg dirPath) {
    return lean_mk_string(GetPrevDirectoryPath(lean_string_cstr(dirPath)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWorkingDirectory (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_mk_string(GetWorkingDirectory()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetApplicationDirectory (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_mk_string(GetApplicationDirectory()));
}

// # END STATIC


LEAN_EXPORT lean_obj_res lean_raylib__ChangeDirectory (b_lean_obj_arg dir, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(ChangeDirectory(lean_string_cstr(dir))));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsPathFile (b_lean_obj_arg path, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsPathFile(lean_string_cstr(path))));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadDirectoryFiles (b_lean_obj_arg dirPath, lean_obj_arg world) {
    FilePathList pathsRaw = LoadDirectoryFiles(lean_string_cstr(dirPath));
    lean_object* paths = lean_alloc_array(pathsRaw.count, pathsRaw.count);
    for(size_t i = 0; i < pathsRaw.count; ++i) {
        lean_array_set_core(paths, i, lean_mk_string(pathsRaw.paths[i]));
    }
    UnloadDirectoryFiles(pathsRaw);
    return lean_io_result_mk_ok(paths);
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadDirectoryFilesEx (b_lean_obj_arg basePath, b_lean_obj_arg filter, uint8_t scanSubdirs, lean_obj_arg world) {
    FilePathList pathsRaw = LoadDirectoryFilesEx(lean_string_cstr(basePath), lean_string_cstr(filter), scanSubdirs);
    lean_object* paths = lean_alloc_array(pathsRaw.count, pathsRaw.count);
    for(size_t i = 0; i < pathsRaw.count; ++i) {
        lean_array_set_core(paths, i, lean_mk_string(pathsRaw.paths[i]));
    }
    UnloadDirectoryFiles(pathsRaw);
    return lean_io_result_mk_ok(paths);
}

LEAN_EXPORT lean_obj_res lean_raylib__IsFileDropped (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsFileDropped()));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadDroppedFiles (lean_obj_arg world) {
    FilePathList pathsRaw = LoadDroppedFiles();
    lean_object* paths = lean_alloc_array(pathsRaw.count, pathsRaw.count);
    for(size_t i = 0; i < pathsRaw.count; ++i) {
        lean_array_set_core(paths, i, lean_mk_string(pathsRaw.paths[i]));
    }
    UnloadDroppedFiles(pathsRaw);
    return lean_io_result_mk_ok(paths);
}

LEAN_EXPORT lean_obj_res lean_raylib__GetFileModTime (b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint64(
        GetFileModTime(lean_string_cstr(fileName))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__CompressData (size_t sz, b_lean_obj_arg data) {
    int compressedDataSize;
    unsigned char* compressedData = CompressData(
        lean_pod_BytesView_unwrap(data)->ptr,
        sz,
        &compressedDataSize
    );
    lean_object* compressedArray = lean_alloc_sarray(sizeof(uint8_t), compressedDataSize, compressedDataSize);
    memcpy(lean_sarray_cptr(compressedArray), compressedData, compressedDataSize);
    MemFree(compressedData);
    return compressedArray;
}

LEAN_EXPORT lean_obj_res lean_raylib__CompressDataST (size_t sz, b_lean_obj_arg data, lean_obj_arg st) {
    int compressedDataSize;
    unsigned char* compressedData = CompressData(
        lean_pod_BytesRef_unwrap(data),
        sz,
        &compressedDataSize
    );
    lean_object* compressedArray = lean_alloc_sarray(sizeof(uint8_t), compressedDataSize, compressedDataSize);
    memcpy(lean_sarray_cptr(compressedArray), compressedData, compressedDataSize);
    MemFree(compressedData);
    return lean_io_result_mk_ok(compressedArray);
}

LEAN_EXPORT lean_obj_res lean_raylib__DecompressData (size_t sz, b_lean_obj_arg compData) {
    int decompressedDataSize;
    unsigned char* decompressedData = DecompressData(
        lean_pod_BytesView_unwrap(compData)->ptr,
        sz,
        &decompressedDataSize
    );
    lean_object* decompressedArray = lean_alloc_sarray(sizeof(uint8_t), decompressedDataSize, decompressedDataSize);
    memcpy(lean_sarray_cptr(decompressedArray), decompressedData, decompressedDataSize);
    MemFree(decompressedData);
    return decompressedArray;
}

LEAN_EXPORT lean_obj_res lean_raylib__EncodeDataBase64 (size_t sz, b_lean_obj_arg data) {
    int encodedDataSize;
    char* encodedData = EncodeDataBase64(
        lean_pod_BytesView_unwrap(data)->ptr,
        sz,
        &encodedDataSize
    );
    lean_object* encodedDataLean = lean_mk_string_from_bytes(encodedData, encodedDataSize);
    MemFree(encodedData);
    return encodedDataLean;
}

LEAN_EXPORT lean_obj_res lean_raylib__EncodeDataBase64ST (size_t sz, b_lean_obj_arg data, lean_obj_arg st) {
    int encodedDataSize;
    char* encodedData = EncodeDataBase64(
        lean_pod_BytesRef_unwrap(data),
        sz,
        &encodedDataSize
    );
    lean_object* encodedDataLean = lean_mk_string_from_bytes(encodedData, encodedDataSize);
    MemFree(encodedData);
    return lean_io_result_mk_ok(encodedDataLean);
}

LEAN_EXPORT lean_obj_res lean_raylib__DecodeDataBase64 (b_lean_obj_arg data) {
    int decodedDataSize;
    unsigned char* decodedData = DecodeDataBase64((unsigned char*)lean_string_cstr(data), &decodedDataSize);
    lean_object* decodedArray = lean_alloc_sarray(sizeof(uint8_t), decodedDataSize, decodedDataSize);
    memcpy(lean_sarray_cptr(decodedArray), decodedData, decodedDataSize);
    MemFree(decodedData);
    return decodedArray;
}

LEAN_EXPORT lean_obj_res lean_raylib__IsKeyPressed (uint32_t key, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsKeyPressed(key)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsKeyDown (uint32_t key, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsKeyDown(key)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsKeyReleased (uint32_t key, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsKeyReleased(key)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsKeyUp (uint32_t key, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsKeyUp(key)));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetExitKey (uint32_t key, lean_obj_arg world) {
    SetExitKey(key);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetKeyPressed (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetKeyPressed()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetCharPressed (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetCharPressed()));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsGamepadAvailable (uint32_t gamepad) {
    return lean_io_result_mk_ok(lean_box(IsGamepadAvailable(gamepad)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGamepadName (uint32_t gamepad) {
    const char * result_ = GetGamepadName(gamepad); // freed by GLFW (glfwGetGamepadName)
    return lean_io_result_mk_ok(
        lean_mk_string(result_)
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__IsGamepadButtonPressed (uint32_t gamepad, uint32_t button, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsGamepadButtonPressed(gamepad, button)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsGamepadButtonDown (uint32_t gamepad, uint32_t button, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsGamepadButtonDown(gamepad, button)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsGamepadButtonReleased (uint32_t gamepad, uint32_t button, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsGamepadButtonReleased(gamepad, button)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsGamepadButtonUp (uint32_t gamepad, uint32_t button, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsGamepadButtonUp(gamepad, button)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGamepadButtonPressed (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetGamepadButtonPressed()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGamepadAxisCount (uint32_t gamepad) {
    return lean_io_result_mk_ok(lean_box_uint32(GetGamepadAxisCount(gamepad)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGamepadAxisMovement (uint32_t gamepad, uint32_t axis, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(lean_pod_Float32_toBits(GetGamepadAxisMovement(gamepad, axis))));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetGamepadMappings (b_lean_obj_arg mappings, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(SetGamepadMappings(lean_string_cstr(mappings))));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsMouseButtonPressed (uint32_t button, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsMouseButtonPressed(button)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsMouseButtonDown (uint32_t button, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsMouseButtonDown(button)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsMouseButtonReleased (uint32_t button, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsMouseButtonReleased(button)));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsMouseButtonUp (uint32_t button, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsMouseButtonUp(button)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMouseX (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetMouseX()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMouseY (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetMouseY()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMousePosition (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetMousePosition()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMouseDelta (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetMouseDelta()));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMousePosition (uint32_t x, uint32_t y, lean_obj_arg world) {
    SetMousePosition(x, y);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMouseOffset (uint32_t offsetX, uint32_t offsetY, lean_obj_arg world) {
    SetMouseOffset(offsetX, offsetY);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMouseScale (uint32_t scaleX, uint32_t scaleY, lean_obj_arg world) {
    SetMouseScale(lean_pod_Float32_fromBits(scaleX), lean_pod_Float32_fromBits(scaleY));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMouseWheelMove (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(lean_pod_Float32_toBits(GetMouseWheelMove())));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMouseWheelMoveV (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetMouseWheelMoveV()));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMouseCursor (uint32_t cursor, lean_obj_arg world) {
    SetMouseCursor(cursor);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetTouchX (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetTouchX()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetTouchY (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetTouchY()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetTouchPosition (uint32_t index, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetTouchPosition(index)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetTouchPointId (uint32_t index, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetTouchPointId(index)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetTouchPointCount (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetTouchPointCount()));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetGesturesEnabled (uint32_t flags, lean_obj_arg world) {
    SetGesturesEnabled(flags);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsGestureDetected (uint32_t gesture, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsGestureDetected(gesture)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGestureDetected (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetGestureDetected()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGestureHoldDuration (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(lean_pod_Float32_toBits(GetGestureHoldDuration())));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGestureDragVector (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetGestureDragVector()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGestureDragAngle (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(lean_pod_Float32_toBits(GetGestureDragAngle())));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGesturePinchVector (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetGesturePinchVector()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGesturePinchAngle (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(lean_pod_Float32_toBits(GetGesturePinchAngle())));
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateCamera (lean_obj_arg camera_old_box, uint32_t mode, lean_obj_arg world) {
    Camera3D camera = lean_raylib_Camera3D_from(camera_old_box);
    UpdateCamera(&camera, mode);
    if(lean_is_exclusive(camera_old_box)) {
        lean_raylib_Camera3D_set(camera_old_box, camera);
        return lean_io_result_mk_ok(camera_old_box);
    }
    else {
        lean_dec_ref(camera_old_box);
        return lean_io_result_mk_ok(lean_raylib_Camera3D_to(camera));
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateCameraPro (lean_obj_arg camera_old_box, b_lean_obj_arg movement, b_lean_obj_arg rotation, uint32_t zoom) {
    Camera3D camera = lean_raylib_Camera3D_from(camera_old_box);
    UpdateCameraPro(
        &camera,
        lean_raylib_Vector3_from(movement),
        lean_raylib_Vector3_from(rotation),
        lean_pod_Float32_fromBits(zoom)
    );
    if(lean_is_exclusive(camera_old_box)) {
        lean_raylib_Camera3D_set(camera_old_box, camera);
        return lean_io_result_mk_ok(camera_old_box);
    }
    else {
        lean_dec_ref(camera_old_box);
        return lean_io_result_mk_ok(lean_raylib_Camera3D_to(camera));
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__SetShapesTexture (lean_obj_arg textureRef_box, b_lean_obj_arg source, lean_obj_arg world) {
    static lean_object* currentShapesTextureOwner = NULL;
    lean_raylib_TextureRef const* textureRef = lean_raylib_TextureRef_from(textureRef_box);
    SetShapesTexture(textureRef->texture, lean_raylib_Rectangle_from(source));
    if(currentShapesTextureOwner != NULL) {
        lean_dec(currentShapesTextureOwner);
    }
    currentShapesTextureOwner = textureRef->owner;
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPixel (uint32_t posX, uint32_t posY, uint32_t color, lean_obj_arg world) {
    DrawPixel(posX, posY, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPixelV (lean_obj_arg position, uint32_t color, lean_obj_arg world) {
    DrawPixelV(lean_raylib_Vector2_from(position), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLine (uint32_t startPosX, uint32_t startPosY, uint32_t endPosX, uint32_t endPosY, uint32_t color, lean_obj_arg world) {
    DrawLine(startPosX, startPosY, endPosX, endPosY, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineV (lean_obj_arg startPos, lean_obj_arg endPos, uint32_t color, lean_obj_arg world) {
    DrawLineV(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineEx (lean_obj_arg startPos, lean_obj_arg endPos, uint32_t thick, uint32_t color, lean_obj_arg world) {
    DrawLineEx(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_pod_Float32_fromBits(thick), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezier (lean_obj_arg startPos, lean_obj_arg endPos, uint32_t thick, uint32_t color, lean_obj_arg world) {
    DrawLineBezier(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_pod_Float32_fromBits(thick), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezierQuad (lean_obj_arg startPos, lean_obj_arg endPos, lean_obj_arg controlPos, uint32_t thick, uint32_t color, lean_obj_arg world) {
    DrawLineBezierQuad(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_raylib_Vector2_from(controlPos), lean_pod_Float32_fromBits(thick), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezierCubic (lean_obj_arg startPos, lean_obj_arg endPos, lean_obj_arg startControlPos, lean_obj_arg endControlPos, uint32_t thick, uint32_t color, lean_obj_arg world) {
    DrawLineBezierCubic(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_raylib_Vector2_from(startControlPos), lean_raylib_Vector2_from(endControlPos), lean_pod_Float32_fromBits(thick), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineStrip (b_lean_obj_arg points, uint32_t color, lean_obj_arg world) {
    size_t pointCount = lean_array_size(points);
    Vector2* points_c = malloc(pointCount * sizeof(Vector2));
    for(size_t i = 0; i < pointCount; ++i) {
        points_c[i] = lean_raylib_Vector2_from(lean_array_get_core(points, i));
    }
    DrawLineStrip(points_c, pointCount, lean_raylib_Color_from(color));
    free(points_c);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircle (int32_t centerX, int32_t centerY, uint32_t radius, uint32_t color, lean_obj_arg world) {
    DrawCircle(centerX, centerY, lean_pod_Float32_fromBits(radius), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleSector (b_lean_obj_arg center, uint32_t radius, uint32_t startAngle, uint32_t endAngle, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawCircleSector(lean_raylib_Vector2_from(center), lean_pod_Float32_fromBits(radius), lean_pod_Float32_fromBits(startAngle), lean_pod_Float32_fromBits(endAngle), segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleSectorLines (b_lean_obj_arg center, uint32_t radius, uint32_t startAngle, uint32_t endAngle, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawCircleSectorLines(lean_raylib_Vector2_from(center), lean_pod_Float32_fromBits(radius), lean_pod_Float32_fromBits(startAngle), lean_pod_Float32_fromBits(endAngle), segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleGradient (int32_t centerX, int32_t centerY, uint32_t radius, uint32_t color1, uint32_t color2, lean_obj_arg world) {
    DrawCircleGradient(centerX, centerY, lean_pod_Float32_fromBits(radius), lean_raylib_Color_from(color1), lean_raylib_Color_from(color2));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleV (b_lean_obj_arg center, uint32_t radius, uint32_t color, lean_obj_arg world) {
    DrawCircleV(lean_raylib_Vector2_from(center), lean_pod_Float32_fromBits(radius), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleLines (int32_t centerX, int32_t centerY, uint32_t radius, uint32_t color, lean_obj_arg world) {
    DrawCircleLines(centerX, centerY, lean_pod_Float32_fromBits(radius), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawEllipse (int32_t centerX, int32_t centerY, uint32_t radiusH, uint32_t radiusV, uint32_t color, lean_obj_arg world) {
    DrawEllipse(centerX, centerY, lean_pod_Float32_fromBits(radiusH), lean_pod_Float32_fromBits(radiusV), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawEllipseLines (int32_t centerX, int32_t centerY, uint32_t radiusH, uint32_t radiusV, uint32_t color, lean_obj_arg world) {
    DrawEllipseLines(centerX, centerY, lean_pod_Float32_fromBits(radiusH), lean_pod_Float32_fromBits(radiusV), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRing (b_lean_obj_arg center, uint32_t innerRadius, uint32_t outerRadius, uint32_t startAngle, uint32_t endAngle, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawRing(lean_raylib_Vector2_from(center), lean_pod_Float32_fromBits(innerRadius), lean_pod_Float32_fromBits(outerRadius), lean_pod_Float32_fromBits(startAngle), lean_pod_Float32_fromBits(endAngle), segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRingLines (b_lean_obj_arg center, uint32_t innerRadius, uint32_t outerRadius, uint32_t startAngle, uint32_t endAngle, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawRingLines(lean_raylib_Vector2_from(center), lean_pod_Float32_fromBits(innerRadius), lean_pod_Float32_fromBits(outerRadius), lean_pod_Float32_fromBits(startAngle), lean_pod_Float32_fromBits(endAngle), segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangle (int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color, lean_obj_arg world) {
    DrawRectangle(posX, posY, width, height, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleV (b_lean_obj_arg position, b_lean_obj_arg size, uint32_t color, lean_obj_arg world) {
    DrawRectangleV(lean_raylib_Vector2_from(position), lean_raylib_Vector2_from(size), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleRec (b_lean_obj_arg rec, uint32_t color, lean_obj_arg world) {
    DrawRectangleRec(lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectanglePro (b_lean_obj_arg rec, b_lean_obj_arg origin, uint32_t rotation, uint32_t color, lean_obj_arg world) {
    DrawRectanglePro(lean_raylib_Rectangle_from(rec), lean_raylib_Vector2_from(origin), lean_pod_Float32_fromBits(rotation), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleGradientV (int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color1, uint32_t color2, lean_obj_arg world) {
    DrawRectangleGradientV(posX, posY, width, height, lean_raylib_Color_from(color1), lean_raylib_Color_from(color2));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleGradientH (int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color1, uint32_t color2, lean_obj_arg world) {
    DrawRectangleGradientH(posX, posY, width, height, lean_raylib_Color_from(color1), lean_raylib_Color_from(color2));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleGradientEx (b_lean_obj_arg rec, uint32_t col1, uint32_t col2, uint32_t col3, uint32_t col4, lean_obj_arg world) {
    DrawRectangleGradientEx(lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(col1), lean_raylib_Color_from(col2), lean_raylib_Color_from(col3), lean_raylib_Color_from(col4));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleLines (int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color, lean_obj_arg world) {
    DrawRectangleLines(posX, posY, width, height, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleLinesEx (b_lean_obj_arg rec, uint32_t lineThick, uint32_t color, lean_obj_arg world) {
    DrawRectangleLinesEx(lean_raylib_Rectangle_from(rec), lean_pod_Float32_fromBits(lineThick), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleRounded (b_lean_obj_arg rec, uint32_t roundness, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawRectangleRounded(lean_raylib_Rectangle_from(rec), lean_pod_Float32_fromBits(roundness), segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleRoundedLines (b_lean_obj_arg rec, uint32_t roundness, uint32_t segments, uint32_t lineThick, uint32_t color, lean_obj_arg world) {
    DrawRectangleRoundedLines(lean_raylib_Rectangle_from(rec), lean_pod_Float32_fromBits(roundness), segments, lean_pod_Float32_fromBits(lineThick), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangle (b_lean_obj_arg v1, b_lean_obj_arg v2, b_lean_obj_arg v3, uint32_t color, lean_obj_arg world) {
    DrawTriangle(lean_raylib_Vector2_from(v1), lean_raylib_Vector2_from(v2), lean_raylib_Vector2_from(v3), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleLines (b_lean_obj_arg v1, b_lean_obj_arg v2, b_lean_obj_arg v3, uint32_t color, lean_obj_arg world) {
    DrawTriangleLines(lean_raylib_Vector2_from(v1), lean_raylib_Vector2_from(v2), lean_raylib_Vector2_from(v3), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleFan (b_lean_obj_arg points, uint32_t color, lean_obj_arg world) {
    size_t pointCount = lean_array_size(points);
    Vector2* points_c = malloc(pointCount * sizeof(Vector2));
    for(size_t i = 0; i < pointCount; ++i) {
        points_c[i] = lean_raylib_Vector2_from(lean_array_get_core(points, i));
    }
    DrawTriangleFan(points_c, pointCount, lean_raylib_Color_from(color));
    free(points_c);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleStrip (b_lean_obj_arg points, uint32_t color, lean_obj_arg world) {
    size_t pointCount = lean_array_size(points);
    Vector2* points_c = malloc(pointCount * sizeof(Vector2));
    for(size_t i = 0; i < pointCount; ++i) {
        points_c[i] = lean_raylib_Vector2_from(lean_array_get_core(points, i));
    }
    DrawTriangleStrip(points_c, pointCount, lean_raylib_Color_from(color));
    free(points_c);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPoly (lean_obj_arg center, uint32_t sides, uint32_t radius, uint32_t rotation, uint32_t color, lean_obj_arg world) {
    DrawPoly(
        lean_raylib_Vector2_from(center),
        sides,
        lean_pod_Float32_fromBits(radius),
        lean_pod_Float32_fromBits(rotation),
        lean_raylib_Color_from(color)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPolyLines (lean_obj_arg center, uint32_t sides, uint32_t radius, uint32_t rotation, uint32_t color, lean_obj_arg world) {
    DrawPolyLines(
        lean_raylib_Vector2_from(center),
        sides,
        lean_pod_Float32_fromBits(radius),
        lean_pod_Float32_fromBits(rotation),
        lean_raylib_Color_from(color)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPolyLinesEx (lean_obj_arg center, uint32_t sides, uint32_t radius, uint32_t rotation, uint32_t lineThick, uint32_t color, lean_obj_arg world) {
    DrawPolyLinesEx(
        lean_raylib_Vector2_from(center),
        sides,
        lean_pod_Float32_fromBits(radius),
        lean_pod_Float32_fromBits(rotation),
        lean_pod_Float32_fromBits(lineThick),
        lean_raylib_Color_from(color)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionRecs (b_lean_obj_arg rec1, b_lean_obj_arg rec2) {
    return CheckCollisionRecs(lean_raylib_Rectangle_from(rec1), lean_raylib_Rectangle_from(rec2));
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionCircles (b_lean_obj_arg center1, uint32_t radius1, b_lean_obj_arg center2, uint32_t radius2) {
    return CheckCollisionCircles(
        lean_raylib_Vector2_from(center1),
        lean_pod_Float32_fromBits(radius1),
        lean_raylib_Vector2_from(center2),
        lean_pod_Float32_fromBits(radius2)
    );
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionCircleRec (b_lean_obj_arg center, uint32_t radius, b_lean_obj_arg rec) {
    return CheckCollisionCircleRec(
        lean_raylib_Vector2_from(center),
        lean_pod_Float32_fromBits(radius),
        lean_raylib_Rectangle_from(rec)
    );
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointRec (b_lean_obj_arg point, b_lean_obj_arg rec) {
    return CheckCollisionPointRec(lean_raylib_Vector2_from(point), lean_raylib_Rectangle_from(rec));
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointCircle (b_lean_obj_arg point, b_lean_obj_arg center, uint32_t radius) {
    return CheckCollisionPointCircle(
        lean_raylib_Vector2_from(point),
        lean_raylib_Vector2_from(center),
        lean_pod_Float32_fromBits(radius)
    );
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointTriangle (b_lean_obj_arg point, b_lean_obj_arg p1, b_lean_obj_arg p2, b_lean_obj_arg p3) {
    return CheckCollisionPointTriangle(
        lean_raylib_Vector2_from(point),
        lean_raylib_Vector2_from(p1),
        lean_raylib_Vector2_from(p2),
        lean_raylib_Vector2_from(p3)
    );
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointPoly (b_lean_obj_arg point, b_lean_obj_arg points) {
    size_t pointCount = lean_array_size(points);
    Vector2* points_c = malloc(pointCount * sizeof(Vector2));
    for(size_t i = 0; i < pointCount; ++i) {
        points_c[i] = lean_raylib_Vector2_from(lean_array_get_core(points, i));
    }
    bool result = CheckCollisionPointPoly(lean_raylib_Vector2_from(point), points_c, pointCount);
    free(points_c);
    return result;
}

LEAN_EXPORT lean_obj_res lean_raylib__CheckCollisionLines (b_lean_obj_arg startPos1, b_lean_obj_arg endPos1, b_lean_obj_arg startPos2, b_lean_obj_arg endPos2) {
    Vector2 collisionPoint;
    if(CheckCollisionLines(
        lean_raylib_Vector2_from(startPos1),
        lean_raylib_Vector2_from(endPos1),
        lean_raylib_Vector2_from(startPos2),
        lean_raylib_Vector2_from(endPos2),
        &collisionPoint
    )) {
        return lean_mk_option_some(lean_raylib_Vector2_to(collisionPoint));
    }
    return lean_mk_option_none();
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointLine (b_lean_obj_arg point, b_lean_obj_arg p1, b_lean_obj_arg p2, uint32_t threshold) {
    return CheckCollisionPointLine(
        lean_raylib_Vector2_from(point),
        lean_raylib_Vector2_from(p1),
        lean_raylib_Vector2_from(p2),
        threshold
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GetCollisionRec (b_lean_obj_arg rec1, b_lean_obj_arg rec2) {
    return lean_raylib_Rectangle_to(GetCollisionRec(
        lean_raylib_Rectangle_from(rec1),
        lean_raylib_Rectangle_from(rec2)
    ));
}


// # Images

LEAN_EXPORT lean_obj_res lean_raylib__LoadImage (/* String */ b_lean_obj_arg fileName, lean_obj_arg world) {
    LET_BOX(Image, image, LoadImage(lean_string_cstr(fileName)));
    return lean_io_result_mk_ok(lean_raylib_Image_to(image));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadImageRaw (
    /* String */ b_lean_obj_arg fileName,
    uint32_t width, uint32_t height, uint32_t format, uint32_t headerSize
, lean_obj_arg world) {
    LET_BOX(Image, image, LoadImageRaw(
        lean_string_cstr(fileName), width, height, format, headerSize
    ));
    return lean_io_result_mk_ok(lean_raylib_Image_to(image));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadImageAnim (/* String */ b_lean_obj_arg fileName, lean_obj_arg world) {
    int frames;
    LET_BOX(Image, image, LoadImageAnim(lean_string_cstr(fileName), &frames));
    return lean_io_result_mk_ok(lean_mk_tuple2(
        lean_raylib_Image_to(image),
        lean_box_uint32(frames)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadImageFromMemory (size_t sz, b_lean_obj_arg fileType, b_lean_obj_arg fileData) {
    LET_BOX(Image, image, LoadImageFromMemory(
        lean_string_cstr(fileType),
        lean_pod_BytesView_unwrap(fileData)->ptr,
        sz
    ));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadImageFromTexture (b_lean_obj_arg textureRef, lean_obj_arg world) {
    LET_BOX(Image, image, LoadImageFromTexture(lean_raylib_TextureRef_from(textureRef)->texture));
    return lean_io_result_mk_ok(lean_raylib_Image_to(image));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadImageFromScreen (lean_obj_arg world) {
    LET_BOX(Image, image, LoadImageFromScreen());
    return lean_io_result_mk_ok(lean_raylib_Image_to(image));
}

LEAN_EXPORT uint8_t lean_raylib__IsImageReady (b_lean_obj_arg image) {
    return IsImageReady(*lean_raylib_Image_from(image));
}

LEAN_EXPORT lean_obj_res lean_raylib__ExportImage (b_lean_obj_arg image, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        ExportImage(*lean_raylib_Image_from(image), lean_string_cstr(fileName))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__ExportImageAsCode (b_lean_obj_arg image, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        ExportImageAsCode(*lean_raylib_Image_from(image), lean_string_cstr(fileName))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageColor (uint32_t width, uint32_t height, uint32_t color) {
    LET_BOX(Image, image, GenImageColor(width, height, lean_raylib_Color_from(color)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageGradientV (uint32_t width, uint32_t height, uint32_t top, uint32_t bottom) {
    LET_BOX(Image, image, GenImageGradientV(width, height, lean_raylib_Color_from(top), lean_raylib_Color_from(bottom)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageGradientH (uint32_t width, uint32_t height, uint32_t left, uint32_t right) {
    LET_BOX(Image, image, GenImageGradientH(width, height, lean_raylib_Color_from(left), lean_raylib_Color_from(right)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageGradientRadial (uint32_t width, uint32_t height, uint32_t density, uint32_t inner, uint32_t outer) {
    LET_BOX(Image, image, GenImageGradientRadial(width, height, lean_pod_Float32_fromBits(density), lean_raylib_Color_from(inner), lean_raylib_Color_from(outer)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageChecked (uint32_t width, uint32_t height, uint32_t checksX, uint32_t checksY, uint32_t col1, uint32_t col2) {
    LET_BOX(Image, image, GenImageChecked(width, height, checksX, checksY, lean_raylib_Color_from(col1), lean_raylib_Color_from(col2)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageWhiteNoise (uint32_t width, uint32_t height, uint32_t factor, lean_obj_arg world) {
    LET_BOX(Image, image, GenImageWhiteNoise(width, height, lean_pod_Float32_fromBits(factor)));
    return lean_io_result_mk_ok(lean_raylib_Image_to(image));
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImagePerlinNoise (uint32_t width, uint32_t height, uint32_t offsetX, uint32_t offsetY, uint32_t scale) {
    LET_BOX(Image, image, GenImagePerlinNoise(width, height, offsetX, offsetY, lean_pod_Float32_fromBits(scale)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageCellular (uint32_t width, uint32_t height, uint32_t tileSize, lean_obj_arg world) {
    LET_BOX(Image, image, GenImageCellular(width, height, tileSize));
    return lean_io_result_mk_ok(lean_raylib_Image_to(image));
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageText (uint32_t width, uint32_t height, b_lean_obj_arg text) {
    LET_BOX(Image, image, GenImageText(width, height, lean_string_cstr(text)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageCopy (b_lean_obj_arg image) {
    LET_BOX(Image, image_copy, ImageCopy(*lean_raylib_Image_from(image)));
    return lean_raylib_Image_to(image_copy);
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageFromImage (b_lean_obj_arg image, b_lean_obj_arg rec) {
    LET_BOX(Image, image_copy, ImageFromImage(*lean_raylib_Image_from(image), lean_raylib_Rectangle_from(rec)));
    return lean_raylib_Image_to(image_copy);
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageText (b_lean_obj_arg text, uint32_t fontSize, uint32_t color) {
    LET_BOX(Image, image, ImageText(lean_string_cstr(text), fontSize, lean_raylib_Color_from(color)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageTextEx (b_lean_obj_arg font, b_lean_obj_arg text, uint32_t fontSize, uint32_t spacing, uint32_t tint) {
    LET_BOX(Image, image, ImageTextEx(
        *lean_raylib_Font_from(font),
        lean_string_cstr(text),
        lean_pod_Float32_fromBits(fontSize),
        lean_pod_Float32_fromBits(spacing),
        lean_raylib_Color_from(tint)
    ));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageFormat (lean_obj_arg image_old_box, uint32_t newFormat) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageFormat(lean_raylib_Image_from(image_res_box), newFormat);
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageToPOT (lean_obj_arg image_old_box, uint32_t fill) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageToPOT(lean_raylib_Image_from(image_res_box), lean_raylib_Color_from(fill));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageCrop (lean_obj_arg image_old_box, b_lean_obj_arg crop) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageCrop(lean_raylib_Image_from(image_res_box), lean_raylib_Rectangle_from(crop));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaCrop (lean_obj_arg image_old_box, uint32_t threshold) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageAlphaCrop(lean_raylib_Image_from(image_res_box), lean_pod_Float32_fromBits(threshold));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaClear (lean_obj_arg image_old_box, uint32_t color, uint32_t threshold) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageAlphaClear(lean_raylib_Image_from(image_res_box), lean_raylib_Color_from(color), lean_pod_Float32_fromBits(threshold));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaMask (lean_obj_arg image_old_box, b_lean_obj_arg alphaMask) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageAlphaMask(lean_raylib_Image_from(image_res_box), *lean_raylib_Image_from(alphaMask));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaPremultiply (lean_obj_arg image_old_box) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageAlphaPremultiply(lean_raylib_Image_from(image_res_box));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageBlurGaussian (lean_obj_arg image_old_box, uint32_t blurSize) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageBlurGaussian(lean_raylib_Image_from(image_res_box), blurSize);
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageResize (lean_obj_arg image_old_box, uint32_t newWidth, uint32_t newHeight) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageResize(lean_raylib_Image_from(image_res_box), newWidth, newHeight);
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageResizeNN (lean_obj_arg image_old_box, uint32_t newWidth, uint32_t newHeight) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageResizeNN(lean_raylib_Image_from(image_res_box), newWidth, newHeight);
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageResizeCanvas (lean_obj_arg image_old_box, uint32_t newWidth, uint32_t newHeight, uint32_t offsetX, uint32_t offsetY, uint32_t fill) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageResizeCanvas(lean_raylib_Image_from(image_res_box), newWidth, newHeight, offsetX, offsetY, lean_raylib_Color_from(fill));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageMipmaps (lean_obj_arg image_old_box) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageMipmaps(lean_raylib_Image_from(image_res_box));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDither (lean_obj_arg image_old_box, uint32_t rBpp, uint32_t gBpp, uint32_t bBpp, uint32_t aBpp) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDither(lean_raylib_Image_from(image_res_box), rBpp, gBpp, bBpp, aBpp);
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageFlipVertical (lean_obj_arg image_old_box) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageFlipVertical(lean_raylib_Image_from(image_res_box));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageFlipHorizontal (lean_obj_arg image_old_box) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageFlipHorizontal(lean_raylib_Image_from(image_res_box));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageRotateCW (lean_obj_arg image_old_box) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageRotateCW(lean_raylib_Image_from(image_res_box));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageRotateCCW (lean_obj_arg image_old_box) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageRotateCCW(lean_raylib_Image_from(image_res_box));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageColorTint (lean_obj_arg image_old_box, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageColorTint(lean_raylib_Image_from(image_res_box), lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageColorInvert (lean_obj_arg image_old_box) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageColorInvert(lean_raylib_Image_from(image_res_box));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageColorGrayscale (lean_obj_arg image_old_box) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageColorGrayscale(lean_raylib_Image_from(image_res_box));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageColorContrast (lean_obj_arg image_old_box, uint32_t contrast) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageColorContrast(lean_raylib_Image_from(image_res_box), lean_pod_Float32_fromBits(contrast));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageColorBrightness (lean_obj_arg image_old_box, uint32_t brightness) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageColorBrightness(lean_raylib_Image_from(image_res_box), brightness);
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageColorReplace (lean_obj_arg image_old_box, uint32_t color, uint32_t replace) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageColorReplace(lean_raylib_Image_from(image_res_box), lean_raylib_Color_from(color), lean_raylib_Color_from(replace));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadImageColors (b_lean_obj_arg image_box) {
    Image image = *lean_raylib_Image_from(image_box);
    size_t colorCount = image.width * image.height * sizeof(Color);
    Color* colors = LoadImageColors(image);
    lean_object* colors_box = lean_alloc_array(colorCount, colorCount);
    for(size_t i = 0; i < colorCount; ++i) {
        lean_array_cptr(colors_box)[i] = lean_box_uint32(lean_raylib_Color_to(colors[i]));
    }
    UnloadImageColors(colors);
    return colors_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadImagePalette (b_lean_obj_arg image_box, uint32_t maxPaletteSize) {
    Image image = *lean_raylib_Image_from(image_box);
    int colorCount;
    Color* colors = LoadImagePalette(image, maxPaletteSize, &colorCount);
    lean_object* colors_box = lean_alloc_array(colorCount, colorCount);
    for(size_t i = 0; i < colorCount; ++i) {
        lean_array_cptr(colors_box)[i] = lean_box_uint32(lean_raylib_Color_to(colors[i]));
    }
    UnloadImagePalette(colors);
    return colors_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__GetImageAlphaBorder (b_lean_obj_arg image, uint32_t threshold) {
    return lean_raylib_Rectangle_to(GetImageAlphaBorder(
        *lean_raylib_Image_from(image),
        lean_pod_Float32_fromBits(threshold)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__GetImageColor (lean_obj_arg image, uint32_t x, uint32_t y) {
    return lean_raylib_Color_to(GetImageColor(*lean_raylib_Image_from(image), x, y));
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageClearBackground (lean_obj_arg image_old_box, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageClearBackground(lean_raylib_Image_from(image_res_box), lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawPixel (lean_obj_arg image_old_box, uint32_t posX, uint32_t posY, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawPixel(lean_raylib_Image_from(image_res_box), posX, posY, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawPixelV (lean_obj_arg image_old_box, b_lean_obj_arg position, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawPixelV(lean_raylib_Image_from(image_res_box), lean_raylib_Vector2_from(position), lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawLine (lean_obj_arg image_old_box, uint32_t startPosX, uint32_t startPosY, uint32_t endPosX, uint32_t endPosY, uint32_t color, lean_obj_arg world) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawLine(lean_raylib_Image_from(image_res_box), startPosX, startPosY, endPosX, endPosY, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawLineV (lean_obj_arg image_old_box, b_lean_obj_arg start, b_lean_obj_arg end, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawLineV(lean_raylib_Image_from(image_res_box), lean_raylib_Vector2_from(start), lean_raylib_Vector2_from(end), lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircle (lean_obj_arg image_old_box, uint32_t centerX, uint32_t centerY, uint32_t radius, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawCircle(lean_raylib_Image_from(image_res_box), centerX, centerY, radius, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleV (lean_obj_arg image_old_box, b_lean_obj_arg center, uint32_t radius, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawCircleV(lean_raylib_Image_from(image_res_box), lean_raylib_Vector2_from(center), radius, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleLines (lean_obj_arg image_old_box, uint32_t centerX, uint32_t centerY, uint32_t radius, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawCircleLines(lean_raylib_Image_from(image_res_box), centerX, centerY, radius, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleLinesV (lean_obj_arg image_old_box, b_lean_obj_arg center, uint32_t radius, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawCircleLinesV(lean_raylib_Image_from(image_res_box), lean_raylib_Vector2_from(center), radius, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangle (lean_obj_arg image_old_box, uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawRectangle(lean_raylib_Image_from(image_res_box), posX, posY, width, height, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleV (lean_obj_arg image_old_box, b_lean_obj_arg position, b_lean_obj_arg size, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawRectangleV(lean_raylib_Image_from(image_res_box), lean_raylib_Vector2_from(position), lean_raylib_Vector2_from(size), lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleRec (lean_obj_arg image_old_box, b_lean_obj_arg rec, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawRectangleRec(lean_raylib_Image_from(image_res_box), lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleLines (lean_obj_arg image_old_box, b_lean_obj_arg rec, uint32_t thick, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawRectangleLines(lean_raylib_Image_from(image_res_box), lean_raylib_Rectangle_from(rec), thick, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDraw (lean_obj_arg image_old_box, b_lean_obj_arg src, b_lean_obj_arg srcRec, b_lean_obj_arg dstRec, uint32_t tint) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDraw(lean_raylib_Image_from(image_res_box), *lean_raylib_Image_from(src), lean_raylib_Rectangle_from(srcRec), lean_raylib_Rectangle_from(dstRec), lean_raylib_Color_from(tint));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawText (lean_obj_arg image_old_box, b_lean_obj_arg text, uint32_t posX, uint32_t posY, uint32_t fontSize, uint32_t color) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawText(lean_raylib_Image_from(image_res_box), lean_string_cstr(text), posX, posY, fontSize, lean_raylib_Color_from(color));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawTextEx (lean_obj_arg image_old_box, b_lean_obj_arg font, b_lean_obj_arg text, b_lean_obj_arg position, uint32_t fontSize, uint32_t spacing, uint32_t tint) {
    lean_object* image_res_box = lean_raylib_Image_exclusive(image_old_box);
    ImageDrawTextEx(lean_raylib_Image_from(image_res_box), *lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), lean_pod_Float32_fromBits(fontSize), lean_pod_Float32_fromBits(spacing), lean_raylib_Color_from(tint));
    return image_res_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadTexture (lean_obj_arg ctx, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Texture_to(
        LoadTexture(lean_string_cstr(fileName)),
        ctx
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadTextureFromImage (lean_obj_arg ctx, b_lean_obj_arg image) {
    return lean_raylib_Texture_to(
        LoadTextureFromImage(*lean_raylib_Image_from(image)),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadTextureCubemap (lean_obj_arg ctx, b_lean_obj_arg image, uint32_t layout) {
    return lean_raylib_Texture_to(
        LoadTextureCubemap(*lean_raylib_Image_from(image), layout),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadRenderTexture (lean_obj_arg ctx, uint32_t width, uint32_t height, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_RenderTexture_to(
        LoadRenderTexture(width, height),
        ctx
    ));
}

LEAN_EXPORT uint8_t lean_raylib__IsTextureReady (b_lean_obj_arg textureRef) {
    return IsTextureReady(lean_raylib_TextureRef_from(textureRef)->texture);
}

LEAN_EXPORT uint8_t lean_raylib__IsRenderTextureReady (b_lean_obj_arg target) {
    return IsRenderTextureReady(*lean_raylib_RenderTexture_from(target));
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateTexture (b_lean_obj_arg texture, b_lean_obj_arg pixels, lean_obj_arg world) {
    UpdateTexture(
        *lean_raylib_Texture_from(texture),
        lean_pod_BytesView_unwrap(pixels)->ptr
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateTextureRec (b_lean_obj_arg texture, b_lean_obj_arg rec, b_lean_obj_arg pixels, lean_obj_arg world) {
    UpdateTextureRec(
        *lean_raylib_Texture_from(texture),
        lean_raylib_Rectangle_from(rec),
        lean_pod_BytesView_unwrap(pixels)->ptr
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GenTextureMipmaps (lean_obj_arg texture_old_box) {
    lean_object* texture_res_box;
    if(lean_is_exclusive(texture_old_box)) {
        texture_res_box = texture_old_box;
    }
    else {
        lean_raylib_Texture* texture = lean_get_external_data(texture_old_box);
        Image image = LoadImageFromTexture(texture->texture);
        lean_inc_ref(texture->ctx);
        texture_res_box = lean_raylib_Texture_to(LoadTextureFromImage(image), texture->ctx);
        UnloadImage(image);
        lean_dec_ref(texture_old_box);
    }
    GenTextureMipmaps(lean_raylib_Texture_from(texture_res_box));
    return texture_old_box;
}

LEAN_EXPORT lean_obj_res lean_raylib__SetTextureFilter (b_lean_obj_arg textureRef, uint32_t filter, lean_obj_arg world) {
    SetTextureFilter(lean_raylib_TextureRef_from(textureRef)->texture, filter);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetTextureWrap (b_lean_obj_arg textureRef, uint32_t wrap, lean_obj_arg world) {
    SetTextureWrap(lean_raylib_TextureRef_from(textureRef)->texture, wrap);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTexture (b_lean_obj_arg textureRef, uint32_t posX, uint32_t posY, uint32_t tint, lean_obj_arg world) {
    DrawTexture(lean_raylib_TextureRef_from(textureRef)->texture, posX, posY, lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureV (b_lean_obj_arg textureRef, b_lean_obj_arg position, uint32_t tint, lean_obj_arg world) {
    DrawTextureV(lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Vector2_from(position), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureEx (b_lean_obj_arg textureRef, b_lean_obj_arg position, uint32_t rotation, uint32_t scale, uint32_t tint, lean_obj_arg world) {
    DrawTextureEx(lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Vector2_from(position), lean_pod_Float32_fromBits(rotation), lean_pod_Float32_fromBits(scale), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureRec (b_lean_obj_arg textureRef, b_lean_obj_arg source, b_lean_obj_arg position, uint32_t tint, lean_obj_arg world) {
    DrawTextureRec(lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Rectangle_from(source), lean_raylib_Vector2_from(position), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTexturePro (b_lean_obj_arg textureRef, b_lean_obj_arg source, b_lean_obj_arg dest, b_lean_obj_arg origin, uint32_t rotation, uint32_t tint, lean_obj_arg world) {
    DrawTexturePro(lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Rectangle_from(source), lean_raylib_Rectangle_from(dest), lean_raylib_Vector2_from(origin), lean_pod_Float32_fromBits(rotation), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureNPatch (b_lean_obj_arg texture, b_lean_obj_arg nPatchInfo, b_lean_obj_arg dest, b_lean_obj_arg origin, uint32_t rotation, uint32_t tint, lean_obj_arg world) {
    DrawTextureNPatch(
        *lean_raylib_Texture_from(texture),
        lean_raylib_NPatchInfo_from(nPatchInfo),
        lean_raylib_Rectangle_from(dest),
        lean_raylib_Vector2_from(origin),
        lean_pod_Float32_fromBits(rotation),
        lean_raylib_Color_from(tint)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT uint32_t lean_raylib__Fade (uint32_t color, uint32_t alpha) {
    return lean_raylib_Color_to(Fade(lean_raylib_Color_from(color), lean_pod_Float32_fromBits(alpha)));
}

LEAN_EXPORT uint32_t lean_raylib__ColorToInt (uint32_t color) {
    return ColorToInt(lean_raylib_Color_from(color));
}

LEAN_EXPORT lean_obj_res lean_raylib__ColorNormalize (uint32_t color) {
    return lean_raylib_Vector4_to(ColorNormalize(lean_raylib_Color_from(color)));
}

LEAN_EXPORT uint32_t lean_raylib__ColorFromNormalized (lean_obj_arg normalized) {
    return lean_raylib_Color_to(ColorFromNormalized(lean_raylib_Vector4_from(normalized)));
}

LEAN_EXPORT lean_obj_res lean_raylib__ColorToHSV (uint32_t color) {
    return lean_raylib_Vector3_to(ColorToHSV(lean_raylib_Color_from(color)));
}

LEAN_EXPORT uint32_t lean_raylib__ColorFromHSV (uint32_t hue, uint32_t saturation, uint32_t value) {
    return lean_raylib_Color_to(ColorFromHSV(
        lean_pod_Float32_fromBits(hue),
        lean_pod_Float32_fromBits(saturation),
        lean_pod_Float32_fromBits(value)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorTint (uint32_t color, uint32_t tint) {
    return lean_raylib_Color_to(ColorTint(
        lean_raylib_Color_from(color),
        lean_raylib_Color_from(tint)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorBrightness (uint32_t color, uint32_t factor) {
    return lean_raylib_Color_to(ColorBrightness(
        lean_raylib_Color_from(color),
        lean_pod_Float32_fromBits(factor)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorContrast (uint32_t color, uint32_t contrast) {
    return lean_raylib_Color_to(ColorContrast(
        lean_raylib_Color_from(color),
        lean_pod_Float32_fromBits(contrast)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorAlpha (uint32_t color, uint32_t alpha) {
    return lean_raylib_Color_to(ColorAlpha(
        lean_raylib_Color_from(color),
        lean_pod_Float32_fromBits(alpha)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorAlphaBlend (uint32_t dst, uint32_t src, uint32_t tint) {
    return lean_raylib_Color_to(ColorAlphaBlend(
        lean_raylib_Color_from(dst),
        lean_raylib_Color_from(src),
        lean_raylib_Color_from(tint)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__GetColor (uint32_t hexValue) {
    return lean_raylib_Color_to(GetColor(hexValue));
}

LEAN_EXPORT uint32_t lean_raylib__GetPixelColor (uint32_t format, b_lean_obj_arg v) {
    return lean_raylib_Color_to(GetPixelColor(lean_pod_BytesView_unwrap(v)->ptr, format));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetPixelColorST (uint32_t format, b_lean_obj_arg br, lean_obj_arg st) {
    return lean_io_result_mk_ok(lean_box_uint32(lean_raylib_Color_to(
        GetPixelColor(lean_pod_BytesRef_unwrap(br), format)
    )));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetPixelColorST (uint32_t format, b_lean_obj_arg br, uint32_t color, lean_obj_arg st) {
    SetPixelColor(lean_pod_BytesRef_unwrap(br), lean_raylib_Color_from(color), format);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT uint32_t lean_raylib__GetPixelDataSize (uint32_t width, uint32_t height, uint32_t format) {
    return GetPixelDataSize(width, height, format);
}

LEAN_EXPORT lean_obj_res lean_raylib__GetFontDefault (lean_obj_arg ctx, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Font_to(GetFontDefault(), ctx));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadFont (lean_obj_arg ctx, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Font_to(
        LoadFont(lean_string_cstr(fileName)),
        ctx
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadFontEx (lean_obj_arg ctx, b_lean_obj_arg fileName, uint32_t fontSize, b_lean_obj_arg fontChars_opt, lean_obj_arg world) {
    size_t glyphCount = 0;
    int* fontChars_c = NULL;
    if(lean_option_is_some(fontChars_opt)) {
        lean_object* fontChars_arr = lean_ctor_get(fontChars_opt, 0);
        glyphCount = lean_array_size(fontChars_arr);
        fontChars_c = malloc(sizeof(int) * glyphCount);
        for(size_t i = 0; i < glyphCount; ++i) {
            fontChars_c[i] = lean_unbox_uint32(lean_array_get_core(fontChars_arr, i));
        }
    }
    Font font = LoadFontEx(lean_string_cstr(fileName), fontSize, fontChars_c, glyphCount);
    free(fontChars_c);
    return lean_io_result_mk_ok(lean_raylib_Font_to(font, ctx));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadFontFromImage (lean_obj_arg ctx, b_lean_obj_arg image, uint32_t key, uint32_t firstChar) {
    return lean_raylib_Font_to(
        LoadFontFromImage(*lean_raylib_Image_from(image), lean_raylib_Color_from(key), firstChar),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadFontFromMemory (size_t sz, lean_obj_arg ctx, b_lean_obj_arg fileType, b_lean_obj_arg data, uint32_t fontSize, b_lean_obj_arg fontChars_opt) {
    size_t glyphCount = 0;
    int* fontChars_c = NULL;
    if(lean_option_is_some(fontChars_opt)) {
        lean_object* fontChars_arr = lean_ctor_get(fontChars_opt, 0);
        glyphCount = lean_array_size(fontChars_arr);
        fontChars_c = malloc(sizeof(int) * glyphCount);
        for(size_t i = 0; i < glyphCount; ++i) {
            fontChars_c[i] = lean_unbox_uint32(lean_array_get_core(fontChars_arr, i));
        }
    }
    Font font = LoadFontFromMemory(
        lean_string_cstr(fileType),
        lean_pod_BytesView_unwrap(data)->ptr,
        sz,
        fontSize,
        fontChars_c,
        glyphCount
    );
    free(fontChars_c);
    return lean_raylib_Font_to(font, ctx);
}

LEAN_EXPORT uint8_t lean_raylib__IsFontReady (lean_obj_arg font) {
    return IsFontReady(*lean_raylib_Font_from(font));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadFontData (
    b_lean_obj_arg n, b_lean_obj_arg data, uint32_t fontSize, b_lean_obj_arg fontChars,
    uint32_t type, lean_obj_arg world
) {
    int glyphCount;
    int* fontCharsC = NULL;
    if (lean_ptr_tag(fontChars) == 0) {
        glyphCount = lean_unbox_uint32(lean_ctor_get(fontChars, 0));
    }
    else {
        lean_object* fontCharsA = lean_ctor_get(fontChars, 0);
        glyphCount = lean_array_size(fontCharsA);
        fontCharsC = RL_MALLOC(glyphCount * sizeof(int));
        for (size_t i = 0; i < glyphCount; ++i) {
            fontCharsC[i] = lean_unbox_uint32(lean_array_get_core(fontCharsA, i));
        }
    }
    GlyphInfo* glyphs = LoadFontData(
        lean_pod_BytesView_unwrap(data)->ptr,
        lean_usize_of_nat(n),
        fontSize,
        fontCharsC,
        glyphCount,
        type
    );
    RL_FREE(fontCharsC);
    if (glyphs == NULL) {
        return lean_mk_option_none();
    }
    lean_object* glyphsA = lean_alloc_array(glyphCount, glyphCount);
    for (size_t i = 0; i < glyphCount; ++i) {
        lean_array_set_core(glyphsA, i, lean_raylib_GlyphInfo_to(glyphs[i]));
    }
    RL_FREE(glyphs);
    return lean_mk_option_some(glyphsA);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageFontAtlas (
    b_lean_obj_arg chars, uint32_t fontSize, uint32_t padding, uint32_t packMethod
) {
    size_t glyphCount = lean_array_size(chars);
    GlyphInfo* charsC = malloc(sizeof(int) * glyphCount);
    for(size_t i = 0; i < glyphCount; ++i) {
        charsC[i] = lean_raylib_GlyphInfo_from(lean_array_get_core(chars, i));
    }
    Rectangle* recsC = NULL;
    LET_BOX(Image, image, GenImageFontAtlas(charsC, &recsC, glyphCount, fontSize, padding, packMethod));
    free(charsC);
    lean_object* recs = lean_alloc_array(glyphCount, glyphCount);
    for(size_t i = 0; i < glyphCount; ++i) {
        lean_array_set_core(recs, i, lean_raylib_Rectangle_to(recsC[i]));
    }
    RL_FREE(recsC);
    return lean_mk_tuple2(lean_raylib_Image_to(image), recs);
}

LEAN_EXPORT lean_obj_res lean_raylib__ExportFontAsCode (b_lean_obj_arg font, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(ExportFontAsCode(*lean_raylib_Font_from(font), lean_string_cstr(fileName))));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawFPS (uint32_t posX, uint32_t posY, lean_obj_arg world) {
    DrawFPS(posX, posY);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawText (b_lean_obj_arg text, uint32_t posX, uint32_t posY, uint32_t fontSize, uint32_t color, lean_obj_arg world) {
    DrawText(lean_string_cstr(text), posX, posY, fontSize, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextEx (b_lean_obj_arg font, b_lean_obj_arg text, b_lean_obj_arg position, uint32_t fontSize, uint32_t spacing, uint32_t tint, lean_obj_arg world) {
    DrawTextEx(*lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), lean_pod_Float32_fromBits(fontSize), lean_pod_Float32_fromBits(spacing), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextPro (b_lean_obj_arg font, b_lean_obj_arg text, b_lean_obj_arg position, b_lean_obj_arg origin, uint32_t rotation, uint32_t fontSize, uint32_t spacing, uint32_t tint, lean_obj_arg world) {
    DrawTextPro(*lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), lean_raylib_Vector2_from(origin), lean_pod_Float32_fromBits(rotation), lean_pod_Float32_fromBits(fontSize), lean_pod_Float32_fromBits(spacing), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextCodepoints (b_lean_obj_arg font, b_lean_obj_arg text, b_lean_obj_arg position, uint32_t fontSize, uint32_t spacing, uint32_t tint, lean_obj_arg world) {
    DrawTextCodepoints(*lean_raylib_Font_from(font), (int*)lean_string_cstr(text), lean_string_len(text), lean_raylib_Vector2_from(position), lean_pod_Float32_fromBits(fontSize), lean_pod_Float32_fromBits(spacing), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextCodepoint (b_lean_obj_arg font, uint32_t codepoint, b_lean_obj_arg position, uint32_t fontSize, uint32_t tint, lean_obj_arg world) {
    DrawTextCodepoint(*lean_raylib_Font_from(font), codepoint, lean_raylib_Vector2_from(position), lean_pod_Float32_fromBits(fontSize), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__MeasureText (b_lean_obj_arg text, uint32_t fontSize, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(MeasureText(lean_string_cstr(text), fontSize)));
}

LEAN_EXPORT lean_obj_res lean_raylib__MeasureTextEx (b_lean_obj_arg font, b_lean_obj_arg text, uint32_t fontSize, uint32_t spacing) {
    return lean_raylib_Vector2_to(MeasureTextEx(
        *lean_raylib_Font_from(font),
        lean_string_cstr(text),
        lean_pod_Float32_fromBits(fontSize),
        lean_pod_Float32_fromBits(spacing)
    ));
}

// Changed to recieve string size as a parameter.
static Vector2 MeasureTextExSize(Font font, const char *text, size_t size, float fontSize, float spacing)
{
    // Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
    Vector2 textSize = { 0 };

    if ((font.texture.id == 0) || (text == NULL)) return textSize;

    int tempByteCounter = 0;        // Used to count longer text line num chars
    int byteCounter = 0;

    float textWidth = 0.0f;
    float tempTextWidth = 0.0f;     // Used to count longer text line width

    float textHeight = (float)font.baseSize;
    float scaleFactor = fontSize/(float)font.baseSize;

    int letter = 0;                 // Current character
    int index = 0;                  // Index position in sprite font

    for (int i = 0; i < size; i++)
    {
        byteCounter++;

        int next = 0;
        letter = GetCodepointNext(&text[i], &next);
        index = GetGlyphIndex(font, letter);

        // NOTE: normally we exit the decoding sequence as soon as a bad byte is found (and return 0x3f)
        // but we need to draw all the bad bytes using the '?' symbol so to not skip any we set next = 1
        if (letter == 0x3f) next = 1;
        i += next - 1;

        if (letter != '\n')
        {
            if (font.glyphs[index].advanceX != 0) textWidth += font.glyphs[index].advanceX;
            else textWidth += (font.recs[index].width + font.glyphs[index].offsetX);
        }
        else
        {
            if (tempTextWidth < textWidth) tempTextWidth = textWidth;
            byteCounter = 0;
            textWidth = 0;
            textHeight += ((float)font.baseSize*1.5f); // NOTE: Fixed line spacing of 1.5 lines
        }

        if (tempByteCounter < byteCounter) tempByteCounter = byteCounter;
    }

    if (tempTextWidth < textWidth) tempTextWidth = textWidth;

    textSize.x = tempTextWidth*scaleFactor + (float)((tempByteCounter - 1)*spacing); // Adds chars spacing to measure
    textSize.y = textHeight*scaleFactor;

    return textSize;
}

LEAN_EXPORT lean_obj_res lean_raylib__MeasureTextExSize (b_lean_obj_arg font, b_lean_obj_arg text, uint32_t fontSize, uint32_t spacing) {
    return lean_raylib_Vector2_to(MeasureTextExSize(
        *lean_raylib_Font_from(font),
        lean_raylib_Substring_cptr(text),
        lean_raylib_Substring_utf8_byte_size(text),
        lean_pod_Float32_fromBits(fontSize),
        lean_pod_Float32_fromBits(spacing)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__GetGlyphIndex (b_lean_obj_arg font, uint32_t codepoint) {
    return GetGlyphIndex(*lean_raylib_Font_from(font), codepoint);
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGlyphInfo (b_lean_obj_arg font, uint32_t codepoint) {
    GlyphInfo glyph = GetGlyphInfo(*lean_raylib_Font_from(font), codepoint);
    glyph.image = ImageCopy(glyph.image);
    return lean_raylib_GlyphInfo_to(glyph);
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGlyphAtlasRec (b_lean_obj_arg font, uint32_t codepoint) {
    return lean_raylib_Rectangle_to(GetGlyphAtlasRec(*lean_raylib_Font_from(font), codepoint));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLine3D (b_lean_obj_arg startPos, b_lean_obj_arg endPos, uint32_t color, lean_obj_arg world) {
    DrawLine3D(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPoint3D (b_lean_obj_arg position, uint32_t color, lean_obj_arg world) {
    DrawPoint3D(lean_raylib_Vector3_from(position), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircle3D (b_lean_obj_arg center, uint32_t radius, b_lean_obj_arg rotationAxis, uint32_t rotationAngle, uint32_t color, lean_obj_arg world) {
    DrawCircle3D(lean_raylib_Vector3_from(center), lean_pod_Float32_fromBits(radius), lean_raylib_Vector3_from(rotationAxis), lean_pod_Float32_fromBits(rotationAngle), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangle3D (b_lean_obj_arg v1, b_lean_obj_arg v2, b_lean_obj_arg v3, uint32_t color, lean_obj_arg world) {
    DrawTriangle3D(lean_raylib_Vector3_from(v1), lean_raylib_Vector3_from(v2), lean_raylib_Vector3_from(v3), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleStrip3D (b_lean_obj_arg points, uint32_t color, lean_obj_arg world) {
    size_t pointCount = lean_array_size(points);
    Vector3* points_raw = malloc(pointCount * sizeof(Vector3));
    for(size_t i = 0; i < pointCount; ++i) {
        points_raw[i] = lean_raylib_Vector3_from(lean_array_get_core(points, i));
    }
    DrawTriangleStrip3D(points_raw, pointCount, lean_raylib_Color_from(color));
    free(points_raw);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCube (b_lean_obj_arg position, uint32_t width, uint32_t height, uint32_t length, uint32_t color, lean_obj_arg world) {
    DrawCube(lean_raylib_Vector3_from(position), lean_pod_Float32_fromBits(width), lean_pod_Float32_fromBits(height), lean_pod_Float32_fromBits(length), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeV (b_lean_obj_arg position, b_lean_obj_arg size, uint32_t color, lean_obj_arg world) {
    DrawCubeV(lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(size), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeWires (b_lean_obj_arg position, uint32_t width, uint32_t height, uint32_t length, uint32_t color, lean_obj_arg world) {
    DrawCubeWires(lean_raylib_Vector3_from(position), lean_pod_Float32_fromBits(width), lean_pod_Float32_fromBits(height), lean_pod_Float32_fromBits(length), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeWiresV (b_lean_obj_arg position, b_lean_obj_arg size, uint32_t color, lean_obj_arg world) {
    DrawCubeWiresV(lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(size), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawSphere (b_lean_obj_arg centerPos, uint32_t radius, uint32_t color, lean_obj_arg world) {
    DrawSphere(lean_raylib_Vector3_from(centerPos), lean_pod_Float32_fromBits(radius), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawSphereEx (b_lean_obj_arg centerPos, uint32_t radius, uint32_t rings, uint32_t slices, uint32_t color, lean_obj_arg world) {
    DrawSphereEx(lean_raylib_Vector3_from(centerPos), lean_pod_Float32_fromBits(radius), rings, slices, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawSphereWires (b_lean_obj_arg centerPos, uint32_t radius, uint32_t rings, uint32_t slices, uint32_t color, lean_obj_arg world) {
    DrawSphereWires(lean_raylib_Vector3_from(centerPos), lean_pod_Float32_fromBits(radius), rings, slices, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinder (b_lean_obj_arg position, uint32_t radiusTop, uint32_t radiusBottom, uint32_t height, uint32_t slices, uint32_t color, lean_obj_arg world) {
    DrawCylinder(lean_raylib_Vector3_from(position), lean_pod_Float32_fromBits(radiusTop), lean_pod_Float32_fromBits(radiusBottom), lean_pod_Float32_fromBits(height), slices, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderEx (b_lean_obj_arg startPos, b_lean_obj_arg endPos, uint32_t startRadius, uint32_t endRadius, uint32_t sides, uint32_t color, lean_obj_arg world) {
    DrawCylinderEx(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), lean_pod_Float32_fromBits(startRadius), lean_pod_Float32_fromBits(endRadius), sides, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderWires (b_lean_obj_arg position, uint32_t radiusTop, uint32_t radiusBottom, uint32_t height, uint32_t slices, uint32_t color, lean_obj_arg world) {
    DrawCylinderWires(lean_raylib_Vector3_from(position), lean_pod_Float32_fromBits(radiusTop), lean_pod_Float32_fromBits(radiusBottom), lean_pod_Float32_fromBits(height), slices, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderWiresEx (b_lean_obj_arg startPos, b_lean_obj_arg endPos, uint32_t startRadius, uint32_t endRadius, uint32_t sides, uint32_t color, lean_obj_arg world) {
    DrawCylinderWiresEx(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), lean_pod_Float32_fromBits(startRadius), lean_pod_Float32_fromBits(endRadius), sides, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCapsule (b_lean_obj_arg startPos, b_lean_obj_arg endPos, uint32_t radius, uint32_t slices, uint32_t rings, uint32_t color, lean_obj_arg world) {
    DrawCapsule(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), lean_pod_Float32_fromBits(radius), slices, rings, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCapsuleWires (b_lean_obj_arg startPos, b_lean_obj_arg endPos, uint32_t radius, uint32_t slices, uint32_t rings, uint32_t color, lean_obj_arg world) {
    DrawCapsuleWires(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), lean_pod_Float32_fromBits(radius), slices, rings, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPlane (b_lean_obj_arg centerPos, b_lean_obj_arg size, uint32_t color, lean_obj_arg world) {
    DrawPlane(lean_raylib_Vector3_from(centerPos), lean_raylib_Vector2_from(size), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRay (b_lean_obj_arg ray, uint32_t color, lean_obj_arg world) {
    DrawRay(lean_raylib_Ray_from(ray), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawGrid (uint32_t slices, uint32_t spacing, lean_obj_arg world) {
    DrawGrid(slices, lean_pod_Float32_fromBits(spacing));
    return lean_io_result_mk_ok(lean_box(0));
}

static lean_obj_res lean_raylib_Material_own (Material* mat, b_lean_obj_arg ctx) {
    Vector4 params = {
        .x = mat->params[0],
        .y = mat->params[1],
        .z = mat->params[2],
        .w = mat->params[3]
    };
    lean_object* mmaps = lean_alloc_array(LEAN_RAYLIB_MAX_MATERIAL_MAPS, LEAN_RAYLIB_MAX_MATERIAL_MAPS);
    lean_inc_ref_n(ctx, LEAN_RAYLIB_MAX_MATERIAL_MAPS);
    for (size_t j = 0; j < LEAN_RAYLIB_MAX_MATERIAL_MAPS; ++j) {
        MaterialMap* mmap = &mat->maps[j];
        lean_array_set_core(mmaps, j, lean_raylib_MaterialMap_to(
            lean_raylib_Texture_to(mmap->texture, ctx),
            mmap->color,
            mmap->value
        ));
    }
    return lean_raylib_Material_to(lean_raylib__Shader_getDefault(ctx), mmaps, params);
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadModel (b_lean_obj_arg ctx, b_lean_obj_arg fileName, lean_obj_arg world) {
    lean_raylib_Model model;
    model.model = LoadModel(lean_string_cstr(fileName));
    model.meshesCapacity = model.model.meshCount;
    model.materialsCapacity = model.model.materialCount;
    model.meshes = lean_alloc_array(model.model.meshCount, model.model.meshCount);
    // per each mesh + material(->shader)
    lean_inc_ref_n(ctx, model.model.meshCount + model.model.materialCount);
    for (size_t i = 0; i < model.model.meshCount; ++i) {
        lean_object* meshXmatIdx = lean_alloc_ctor(0, 2, 0);
        lean_ctor_set(meshXmatIdx, 0, lean_raylib_Mesh_to(model.model.meshes[i], ctx));
        lean_ctor_set(meshXmatIdx, 1, lean_uint32_to_nat(model.model.meshMaterial[i]));
        lean_array_set_core(model.meshes, i, meshXmatIdx);
    }
    model.materials = lean_alloc_array(model.model.materialCount, model.model.materialCount);
    for (size_t i = 0; i < model.model.materialCount; ++i) {
        lean_array_set_core(
            model.materials,
            i,
            lean_raylib_Material_own(&model.model.materials[i], ctx)
        );
    }
    return lean_io_result_mk_ok(lean_raylib_Model_to(model));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadModelFromMesh (lean_obj_arg mesh) {
    lean_raylib_Model model;
    model.model = LoadModelFromMesh(*lean_raylib_Mesh_from(mesh));
    model.meshes = lean_alloc_array(1, 1);
    lean_array_set_core(model.meshes, 0, mesh);
    model.materials = lean_alloc_array(1, 1);
    lean_object* ctx = ((lean_raylib_Mesh*)lean_get_external_data(mesh))->ctx;
    lean_inc_ref(ctx);
    lean_array_set_core(
        model.materials,
        0,
        lean_raylib_Material_own(&model.model.materials[0], ctx)
    );
    return lean_raylib_Model_to(model);
}

LEAN_EXPORT uint8_t lean_raylib__IsModelReady (b_lean_obj_arg model) {
    return IsModelReady(lean_raylib_Model_from(model)->model);
}

LEAN_EXPORT lean_obj_res lean_raylib__GetModelBoundingBox (b_lean_obj_arg model) {
    return lean_raylib_BoundingBox_to(
        GetModelBoundingBox(lean_raylib_Model_from(model)->model)
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawModel (b_lean_obj_arg model, b_lean_obj_arg position, uint32_t scale, uint32_t tint, lean_obj_arg world) {
    DrawModel(
        lean_raylib_Model_from(model)->model,
        lean_raylib_Vector3_from(position),
        lean_pod_Float32_fromBits(scale),
        lean_raylib_Color_from(tint)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawModelEx (b_lean_obj_arg model, b_lean_obj_arg position, b_lean_obj_arg rotationAxis, uint32_t rotationAngle, b_lean_obj_arg scale, uint32_t tint, lean_obj_arg world) {
    DrawModelEx(
        lean_raylib_Model_from(model)->model,
        lean_raylib_Vector3_from(position),
        lean_raylib_Vector3_from(rotationAxis),
        lean_pod_Float32_fromBits(rotationAngle),
        lean_raylib_Vector3_from(scale),
        lean_raylib_Color_from(tint)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawModelWires (b_lean_obj_arg model, b_lean_obj_arg position, uint32_t scale, uint32_t tint, lean_obj_arg world) {
    DrawModelWires(
        lean_raylib_Model_from(model)->model,
        lean_raylib_Vector3_from(position),
        lean_pod_Float32_fromBits(scale),
        lean_raylib_Color_from(tint)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawModelWiresEx (b_lean_obj_arg model, b_lean_obj_arg position, b_lean_obj_arg rotationAxis, uint32_t rotationAngle, b_lean_obj_arg scale, uint32_t tint, lean_obj_arg world) {
    DrawModelWiresEx(
        lean_raylib_Model_from(model)->model,
        lean_raylib_Vector3_from(position),
        lean_raylib_Vector3_from(rotationAxis),
        lean_pod_Float32_fromBits(rotationAngle),
        lean_raylib_Vector3_from(scale),
        lean_raylib_Color_from(tint)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawBoundingBox (b_lean_obj_arg box, uint32_t color, lean_obj_arg world) {
    DrawBoundingBox(lean_raylib_BoundingBox_from(box), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboard (b_lean_obj_arg camera, b_lean_obj_arg textureRef, b_lean_obj_arg position, uint32_t size, uint32_t tint, lean_obj_arg world) {
    DrawBillboard(lean_raylib_Camera3D_from(camera), lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Vector3_from(position), lean_pod_Float32_fromBits(size), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboardRec (b_lean_obj_arg camera, b_lean_obj_arg textureRef, b_lean_obj_arg source, b_lean_obj_arg position, b_lean_obj_arg size, uint32_t tint, lean_obj_arg world) {
    DrawBillboardRec(lean_raylib_Camera3D_from(camera), lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Rectangle_from(source), lean_raylib_Vector3_from(position), lean_raylib_Vector2_from(size), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboardPro (b_lean_obj_arg camera, b_lean_obj_arg textureRef, b_lean_obj_arg source, b_lean_obj_arg position, b_lean_obj_arg up, b_lean_obj_arg size, b_lean_obj_arg origin, uint32_t rotation, uint32_t tint, lean_obj_arg world) {
    DrawBillboardPro(lean_raylib_Camera3D_from(camera), lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Rectangle_from(source), lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(up), lean_raylib_Vector2_from(size), lean_raylib_Vector2_from(origin), lean_pod_Float32_fromBits(rotation), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__MeshCopy(b_lean_obj_arg mesh) {
    lean_object* ctx = ((lean_raylib_Mesh*)lean_get_external_data(mesh))->ctx;
    lean_inc_ref(ctx);
    return lean_raylib_Mesh_to(
        lean_raylib_Mesh_clone(lean_raylib_Mesh_from(mesh)),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__UploadMesh (lean_obj_arg mesh, uint8_t dynamic, lean_obj_arg world) {
    if(LEAN_LIKELY(lean_is_exclusive(mesh))) {
        UploadMesh(lean_raylib_Mesh_from(mesh), dynamic);
        return lean_io_result_mk_ok(mesh);
    }
    else {
        lean_object* mesh_copy = lean_raylib__MeshCopy(mesh);
        lean_dec_ref(mesh);
        UploadMesh(lean_raylib_Mesh_from(mesh_copy), dynamic);
        return lean_io_result_mk_ok(mesh_copy);
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateMeshBuffer (lean_obj_arg mesh, b_lean_obj_arg i, b_lean_obj_arg n, b_lean_obj_arg data, uint32_t offset, lean_obj_arg world) {
    mesh = lean_raylib_Mesh_ensure_exclusive(mesh);
    lean_raylib_Mesh* meshC = lean_get_external_data(mesh);
    if (meshC->mesh.vaoId == 0 || meshC->mesh.vboId == NULL) {
        UploadMesh(&meshC->mesh, true);
    }
    UpdateMeshBuffer(
        *lean_raylib_Mesh_from(mesh),
        lean_usize_of_nat(i),
        lean_pod_BytesView_unwrap(data)->ptr,
        lean_usize_of_nat(n),
        offset
    );
    return lean_io_result_mk_ok(mesh);
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawMesh (
    b_lean_obj_arg mesh, b_lean_obj_arg material, b_lean_obj_arg transform, lean_obj_arg world
) {
    MaterialMap mmaps[LEAN_RAYLIB_MAX_MATERIAL_MAPS]; // 4KB
    DrawMesh(
        *lean_raylib_Mesh_from(mesh),
        lean_raylib_Material_from(material, mmaps),
        lean_raylib_Matrix_from(transform)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawMeshInstanced (
    b_lean_obj_arg mesh, b_lean_obj_arg material, b_lean_obj_arg transforms, lean_obj_arg world
) {
    MaterialMap mmaps[LEAN_RAYLIB_MAX_MATERIAL_MAPS]; // 4KB
    size_t instances = lean_array_size(transforms);
    Matrix* transformsC = RL_MALLOC(instances * sizeof(Matrix));
    for (size_t i = 0; i < instances; ++i) {
        transformsC[i] = lean_raylib_Matrix_from(lean_array_get_core(transforms, i));
    }
    DrawMeshInstanced(
        *lean_raylib_Mesh_from(mesh),
        lean_raylib_Material_from(material, mmaps),
        transformsC,
        instances
    );
    RL_FREE(transformsC);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawMeshInstancedBv (
    b_lean_obj_arg mesh, b_lean_obj_arg material, b_lean_obj_arg n,
    b_lean_obj_arg transforms, lean_obj_arg world
) {
    MaterialMap mmaps[LEAN_RAYLIB_MAX_MATERIAL_MAPS]; // 4KB
    DrawMeshInstanced(
        *lean_raylib_Mesh_from(mesh),
        lean_raylib_Material_from(material, mmaps),
        (Matrix*)lean_pod_BytesView_unwrap(transforms)->ptr,
        lean_usize_of_nat(n)
    );
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ExportMesh (b_lean_obj_arg mesh, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(ExportMesh(*lean_raylib_Mesh_from(mesh), lean_string_cstr(fileName))));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMeshBoundingBox (b_lean_obj_arg mesh) {
    return lean_raylib_BoundingBox_to(GetMeshBoundingBox(*lean_raylib_Mesh_from(mesh)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshTangents (lean_obj_arg mesh) {
    if(LEAN_LIKELY(lean_is_exclusive(mesh))) {
        GenMeshTangents(lean_raylib_Mesh_from(mesh));
        return mesh;
    }
    else {
        lean_object* mesh_copy = lean_raylib__MeshCopy(mesh);
        lean_dec_ref(mesh);
        GenMeshTangents(lean_raylib_Mesh_from(mesh_copy));
        return mesh_copy;
    }
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshPoly (lean_obj_arg ctx, uint32_t sides, uint32_t radius) {
    return lean_raylib_Mesh_to(
        GenMeshPoly(sides, lean_pod_Float32_fromBits(radius)),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshPlane (lean_obj_arg ctx, uint32_t width, uint32_t length, uint32_t resX, uint32_t resZ) {
    return lean_raylib_Mesh_to(
        GenMeshPlane(lean_pod_Float32_fromBits(width), lean_pod_Float32_fromBits(length), resX, resZ),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshCube (lean_obj_arg ctx, uint32_t width, uint32_t height, uint32_t length) {
    return lean_raylib_Mesh_to(
        GenMeshCube(lean_pod_Float32_fromBits(width), lean_pod_Float32_fromBits(height), lean_pod_Float32_fromBits(length)),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshSphere (lean_obj_arg ctx, uint32_t radius, uint32_t rings, uint32_t slices) {
    return lean_raylib_Mesh_to(
        GenMeshSphere(lean_pod_Float32_fromBits(radius), rings, slices),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshHemiSphere (lean_obj_arg ctx, uint32_t radius, uint32_t rings, uint32_t slices) {
    return lean_raylib_Mesh_to(
        GenMeshHemiSphere(lean_pod_Float32_fromBits(radius), rings, slices),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshCylinder (lean_obj_arg ctx, uint32_t radius, uint32_t height, uint32_t slices) {
    return lean_raylib_Mesh_to(
        GenMeshCylinder(lean_pod_Float32_fromBits(radius), lean_pod_Float32_fromBits(height), slices),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshCone (lean_obj_arg ctx, uint32_t radius, uint32_t height, uint32_t slices) {
    return lean_raylib_Mesh_to(
        GenMeshCone(lean_pod_Float32_fromBits(radius), lean_pod_Float32_fromBits(height), slices),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshTorus (lean_obj_arg ctx, uint32_t radius, uint32_t size, uint32_t radSeg, uint32_t sides) {
    return lean_raylib_Mesh_to(
        GenMeshTorus(lean_pod_Float32_fromBits(radius), lean_pod_Float32_fromBits(size), radSeg, sides),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshKnot (lean_obj_arg ctx, uint32_t radius, uint32_t size, uint32_t radSeg, uint32_t sides) {
    return lean_raylib_Mesh_to(
        GenMeshKnot(lean_pod_Float32_fromBits(radius), lean_pod_Float32_fromBits(size), radSeg, sides),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshHeightmap (lean_obj_arg ctx, b_lean_obj_arg heightmap, lean_obj_arg size) {
    return lean_raylib_Mesh_to(
        GenMeshHeightmap(*lean_raylib_Image_from(heightmap), lean_raylib_Vector3_from(size)),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GenMeshCubicmap (lean_obj_arg ctx, b_lean_obj_arg cubicmap, lean_obj_arg cubeSize) {
    return lean_raylib_Mesh_to(
        GenMeshCubicmap(*lean_raylib_Image_from(cubicmap), lean_raylib_Vector3_from(cubeSize)),
        ctx
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadMaterials (b_lean_obj_arg ctx, b_lean_obj_arg fileName, lean_obj_arg world) {
    int materialCount;
    Material* materials = LoadMaterials(lean_string_cstr(fileName), &materialCount);
    lean_object* lmats = lean_alloc_array(materialCount, materialCount);
    for (size_t i = 0; i < materialCount; ++i) {
        lean_array_set_core(lmats, i, lean_raylib_Material_own(&materials[i], ctx));
        RL_FREE(materials[i].maps);
    }
    MemFree(materials);
    return lean_io_result_mk_ok(lmats);
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadModelAnimations (b_lean_obj_arg fileName, lean_obj_arg world) {
    unsigned int animCount;
    ModelAnimation* anims = LoadModelAnimations(lean_string_cstr(fileName), &animCount);
    lean_object* lanims = lean_alloc_array(animCount, animCount);
    for (size_t i = 0; i < animCount; ++i) {
        lean_array_set_core(lanims, i, lean_raylib_ModelAnimation_to(anims[i]));
    }
    RL_FREE(anims);
    return lean_io_result_mk_ok(lanims);
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateModelAnimation (
    lean_obj_arg modelObj, b_lean_obj_arg anim, uint32_t frame, lean_obj_arg world
) {
    if (LEAN_UNLIKELY(!lean_is_exclusive(modelObj))) {
        lean_raylib_Model modelClone = lean_raylib_Model_clone(lean_get_external_data(modelObj));
        lean_dec_ref(modelObj);
        modelObj = lean_raylib_Model_to(modelClone);
    }
    lean_raylib_Model* model = lean_get_external_data(modelObj);
    model->meshes = lean_ensure_exclusive_array(model->meshes);
    for (size_t i = 0; i < model->model.meshCount; ++i) {
        lean_array_set_core(model->meshes, i,
            lean_raylib_Mesh_ensure_exclusive(lean_array_get_core(model->meshes, i))
        );
    }
    UpdateModelAnimation(
        model->model,
        *lean_raylib_ModelAnimation_from(anim),
        frame
    );
    return lean_io_result_mk_ok(modelObj);
}

LEAN_EXPORT uint8_t lean_raylib__IsModelAnimationValid (b_lean_obj_arg model, b_lean_obj_arg anim) {
    return IsModelAnimationValid(
        lean_raylib_Model_from(model)->model,
        *lean_raylib_ModelAnimation_from(anim)
    );
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionSpheres (b_lean_obj_arg center1, uint32_t radius1, b_lean_obj_arg center2, uint32_t radius2) {
    return CheckCollisionSpheres(
        lean_raylib_Vector3_from(center1),
        lean_pod_Float32_fromBits(radius1),
        lean_raylib_Vector3_from(center2),
        lean_pod_Float32_fromBits(radius2)
    );
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionBoxes (b_lean_obj_arg box1, b_lean_obj_arg box2) {
    return CheckCollisionBoxes(lean_raylib_BoundingBox_from(box1), lean_raylib_BoundingBox_from(box2));
}

LEAN_EXPORT uint8_t lean_raylib__CheckCollisionBoxSphere (b_lean_obj_arg box, b_lean_obj_arg center, uint32_t radius) {
    return CheckCollisionBoxSphere(
        lean_raylib_BoundingBox_from(box),
        lean_raylib_Vector3_from(center),
        lean_pod_Float32_fromBits(radius)
    );
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionSphere (b_lean_obj_arg ray, b_lean_obj_arg center, uint32_t radius) {
    return lean_raylib_RayCollision_to(GetRayCollisionSphere(
        lean_raylib_Ray_from(ray),
        lean_raylib_Vector3_from(center),
        lean_pod_Float32_fromBits(radius)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionBox (b_lean_obj_arg ray, b_lean_obj_arg box) {
    return lean_raylib_RayCollision_to(GetRayCollisionBox(
        lean_raylib_Ray_from(ray),
        lean_raylib_BoundingBox_from(box)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionMesh (b_lean_obj_arg ray, b_lean_obj_arg mesh, b_lean_obj_arg transform) {
    return lean_raylib_RayCollision_to(GetRayCollisionMesh(lean_raylib_Ray_from(ray), *lean_raylib_Mesh_from(mesh), lean_raylib_Matrix_from(transform)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionTriangle (b_lean_obj_arg ray, b_lean_obj_arg p1, b_lean_obj_arg p2, b_lean_obj_arg p3) {
    return lean_raylib_RayCollision_to(GetRayCollisionTriangle(
        lean_raylib_Ray_from(ray),
        lean_raylib_Vector3_from(p1),
        lean_raylib_Vector3_from(p2),
        lean_raylib_Vector3_from(p3)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionQuad (b_lean_obj_arg ray, b_lean_obj_arg p1, b_lean_obj_arg p2, b_lean_obj_arg p3, b_lean_obj_arg p4) {
    return lean_raylib_RayCollision_to(GetRayCollisionQuad(
        lean_raylib_Ray_from(ray),
        lean_raylib_Vector3_from(p1),
        lean_raylib_Vector3_from(p2),
        lean_raylib_Vector3_from(p3),
        lean_raylib_Vector3_from(p4)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__InitAudioDevice (lean_obj_arg world) {
    InitAudioDevice();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__CloseAudioDevice (lean_obj_arg world) {
    CloseAudioDevice();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsAudioDeviceReady (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(IsAudioDeviceReady()));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMasterVolume (uint32_t volume, lean_obj_arg world) {
    SetMasterVolume(lean_pod_Float32_fromBits(volume));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadWave (b_lean_obj_arg fileName, lean_obj_arg world) {
    LET_BOX(Wave, wave, LoadWave(lean_string_cstr(fileName)));
    return lean_io_result_mk_ok(lean_raylib_Wave_to(wave));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadWaveFromMemory (size_t sz, b_lean_obj_arg fileType, b_lean_obj_arg fileData) {
    LET_BOX(Wave, wave, LoadWaveFromMemory(
        lean_string_cstr(fileType),
        lean_pod_BytesView_unwrap(fileData)->ptr,
        sz
    ));
    return lean_raylib_Wave_to(wave);
}

LEAN_EXPORT uint8_t lean_raylib__IsWaveReady (b_lean_obj_arg wave) {
    return IsWaveReady(*lean_raylib_Wave_from(wave));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadSound (lean_obj_arg ctx, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Sound_to(
        LoadSound(lean_string_cstr(fileName)),
        ctx
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadSoundFromWave (lean_obj_arg ctx, b_lean_obj_arg wave) {
    return lean_raylib_Sound_to(
        LoadSoundFromWave(*lean_raylib_Wave_from(wave)),
        ctx
    );
}

LEAN_EXPORT uint8_t lean_raylib__IsSoundReady (b_lean_obj_arg sound) {
    return IsSoundReady(*lean_raylib_Sound_from(sound));
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateSound (b_lean_obj_arg soundObj, uint32_t frameCount, b_lean_obj_arg data, lean_obj_arg world) {
    Sound* sound = lean_raylib_Sound_from (soundObj);
    UpdateSound(*sound, lean_pod_BytesView_unwrap(data)->ptr, frameCount);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ExportWave (b_lean_obj_arg wave, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        ExportWave(*lean_raylib_Wave_from(wave), lean_string_cstr(fileName))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__ExportWaveAsCode (b_lean_obj_arg wave, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        ExportWaveAsCode(*lean_raylib_Wave_from(wave), lean_string_cstr(fileName))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__PlaySound (b_lean_obj_arg sound, lean_obj_arg world) {
    PlaySound(*lean_raylib_Sound_from(sound));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__StopSound (b_lean_obj_arg sound, lean_obj_arg world) {
    StopSound(*lean_raylib_Sound_from(sound));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__PauseSound (b_lean_obj_arg sound, lean_obj_arg world) {
    PauseSound(*lean_raylib_Sound_from(sound));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ResumeSound (b_lean_obj_arg sound, lean_obj_arg world) {
    ResumeSound(*lean_raylib_Sound_from(sound));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsSoundPlaying (b_lean_obj_arg sound, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        IsSoundPlaying(*lean_raylib_Sound_from(sound))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetSoundVolume (b_lean_obj_arg sound, uint32_t volume, lean_obj_arg world) {
    SetSoundVolume(*lean_raylib_Sound_from(sound), lean_pod_Float32_fromBits(volume));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetSoundPitch (b_lean_obj_arg sound, uint32_t pitch, lean_obj_arg world) {
    SetSoundPitch(*lean_raylib_Sound_from(sound), lean_pod_Float32_fromBits(pitch));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetSoundPan (b_lean_obj_arg sound, uint32_t pan, lean_obj_arg world) {
    SetSoundPan(*lean_raylib_Sound_from(sound), lean_pod_Float32_fromBits(pan));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__WaveCopy (b_lean_obj_arg wave_orig) {
    LET_BOX(Wave, wave, WaveCopy(*lean_raylib_Wave_from(wave_orig)));
    return lean_raylib_Wave_to(wave);
}

LEAN_EXPORT lean_obj_res lean_raylib__WaveCrop (lean_obj_arg wave, uint32_t initSample, uint32_t finalSample) {
    if(LEAN_LIKELY(lean_is_exclusive(wave))) {
        WaveCrop(lean_raylib_Wave_from(wave), initSample, finalSample);
        return wave;
    }
    LET_BOX(Wave, wave_new, WaveCopy(*lean_raylib_Wave_from(wave)));
    WaveCrop(wave_new, initSample, finalSample);
    lean_dec_ref(wave);
    return lean_raylib_Wave_to(wave_new);
}

LEAN_EXPORT lean_obj_res lean_raylib__WaveFormat (lean_obj_arg wave, uint32_t sampleRate, uint32_t sampleSize, uint32_t channels) {
    if(LEAN_LIKELY(lean_is_exclusive(wave))) {
        WaveFormat(lean_raylib_Wave_from(wave), sampleRate, sampleSize, channels);
        return wave;
    }
    LET_BOX(Wave, wave_new, WaveCopy(*lean_raylib_Wave_from(wave)));
    WaveFormat(wave_new, sampleRate, sampleSize, channels);
    return lean_raylib_Wave_to(wave_new);
}

LEAN_EXPORT lean_obj_arg lean_raylib__LoadWaveSamples (lean_obj_arg wave_box, lean_obj_arg world) {
    Wave wave = *lean_raylib_Wave_from(wave_box);
    size_t sampleCount = wave.frameCount * wave.channels;
    float* samples = LoadWaveSamples(wave);
    lean_object* samples_box = lean_alloc_array(sampleCount, sampleCount);
    for(size_t i = 0; i < sampleCount; ++i) {
        lean_array_cptr(samples_box)[i] = lean_pod_Float32_box(samples[i]);
    }
    UnloadWaveSamples(samples);
    return lean_io_result_mk_ok(samples_box);
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadMusicStream (lean_obj_arg ctx, b_lean_obj_arg fileName, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Music_to(
        LoadMusicStream(lean_string_cstr(fileName)),
        ctx
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadMusicStreamFromMemory (lean_obj_arg ctx, b_lean_obj_arg fileType, b_lean_obj_arg data, lean_obj_arg world) {
    return lean_raylib_Music_to(
        LoadMusicStreamFromMemory(
            lean_string_cstr(fileType),
            lean_sarray_cptr(data),
            lean_sarray_size(data)
        ),
        ctx
    );
}

LEAN_EXPORT uint8_t lean_raylib__IsMusicReady (b_lean_obj_arg music) {
    return IsMusicReady(*lean_raylib_Music_from(music));
}

LEAN_EXPORT lean_obj_res lean_raylib__PlayMusicStream (lean_obj_arg music, lean_obj_arg world) {
    PlayMusicStream(*lean_raylib_Music_from(music));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsMusicStreamPlaying (lean_obj_arg music, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        IsMusicStreamPlaying(*lean_raylib_Music_from(music))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateMusicStream (b_lean_obj_arg music, lean_obj_arg world) {
    UpdateMusicStream(*lean_raylib_Music_from(music));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__StopMusicStream (b_lean_obj_arg music, lean_obj_arg world) {
    StopMusicStream(*lean_raylib_Music_from(music));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__PauseMusicStream (b_lean_obj_arg music, lean_obj_arg world) {
    PauseMusicStream(*lean_raylib_Music_from(music));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ResumeMusicStream (b_lean_obj_arg music, lean_obj_arg world) {
    ResumeMusicStream(*lean_raylib_Music_from(music));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SeekMusicStream (b_lean_obj_arg music, uint32_t position, lean_obj_arg world) {
    SeekMusicStream(*lean_raylib_Music_from(music), lean_pod_Float32_fromBits(position));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMusicVolume (b_lean_obj_arg music, uint32_t volume, lean_obj_arg world) {
    SetMusicVolume(*lean_raylib_Music_from(music), lean_pod_Float32_fromBits(volume));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMusicPitch (b_lean_obj_arg music, uint32_t pitch, lean_obj_arg world) {
    SetMusicPitch(*lean_raylib_Music_from(music), lean_pod_Float32_fromBits(pitch));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMusicPan (b_lean_obj_arg music, uint32_t pan, lean_obj_arg world) {
    SetMusicPan(*lean_raylib_Music_from(music), lean_pod_Float32_fromBits(pan));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT uint32_t lean_raylib__GetMusicTimeLength (b_lean_obj_arg music) {
    return lean_pod_Float32_toBits(GetMusicTimeLength(*lean_raylib_Music_from(music)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMusicTimePlayed (b_lean_obj_arg music, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_float(
        GetMusicTimePlayed(*lean_raylib_Music_from(music))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadAudioStream (lean_obj_arg ctx, uint32_t sampleRate, uint32_t sampleSize, uint32_t channels, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_AudioStream_to(
        LoadAudioStream(sampleRate, sampleSize, channels),
        ctx,
        NULL
    ));
}

LEAN_EXPORT uint8_t lean_raylib__IsAudioStreamReady (uint32_t st, b_lean_obj_arg stream) {
    return IsAudioStreamReady(lean_raylib_AudioStream_from(stream)->stream);
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateAudioStream (uint32_t st, b_lean_obj_arg stream, b_lean_obj_arg data, uint32_t frameCount, lean_obj_arg world) {
    UpdateAudioStream(lean_raylib_AudioStream_from(stream)->stream, lean_sarray_cptr(data), frameCount);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsAudioStreamProcessed (uint32_t st, b_lean_obj_arg stream, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        IsAudioStreamProcessed(lean_raylib_AudioStream_from(stream)->stream)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__PlayAudioStream (uint32_t st, b_lean_obj_arg stream, lean_obj_arg world) {
    PlayAudioStream(lean_raylib_AudioStream_from(stream)->stream);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__PauseAudioStream (uint32_t st, b_lean_obj_arg stream, lean_obj_arg world) {
    PauseAudioStream(lean_raylib_AudioStream_from(stream)->stream);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ResumeAudioStream (uint32_t st, b_lean_obj_arg stream, lean_obj_arg world) {
    ResumeAudioStream(lean_raylib_AudioStream_from(stream)->stream);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsAudioStreamPlaying (uint32_t st, b_lean_obj_arg stream, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        IsAudioStreamPlaying(lean_raylib_AudioStream_from(stream)->stream)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__StopAudioStream (uint32_t st, b_lean_obj_arg stream, lean_obj_arg world) {
    StopAudioStream(lean_raylib_AudioStream_from(stream)->stream);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamVolume (uint32_t st, b_lean_obj_arg stream, uint32_t volume, lean_obj_arg world) {
    SetAudioStreamVolume(lean_raylib_AudioStream_from(stream)->stream, lean_pod_Float32_fromBits(volume));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamPitch (uint32_t st, b_lean_obj_arg stream, uint32_t pitch, lean_obj_arg world) {
    SetAudioStreamPitch(lean_raylib_AudioStream_from(stream)->stream, lean_pod_Float32_fromBits(pitch));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamPan (uint32_t st, b_lean_obj_arg stream, uint32_t pan, lean_obj_arg world) {
    SetAudioStreamPan(lean_raylib_AudioStream_from(stream)->stream, lean_pod_Float32_fromBits(pan));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamBufferSizeDefault (uint32_t size, lean_obj_arg world) {
    SetAudioStreamBufferSizeDefault(size);
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__AttachAudioStreamProcessor (lean_obj_arg stream, lean_obj_arg processor, lean_obj_arg world) {
//     AttachAudioStreamProcessor(lean_raylib_AudioStream_from(stream), /*cast AudioCallback to_lean?false*/(processor));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DetachAudioStreamProcessor (lean_obj_arg stream, lean_obj_arg processor, lean_obj_arg world) {
//     DetachAudioStreamProcessor(lean_raylib_AudioStream_from(stream), /*cast AudioCallback to_lean?false*/(processor));
//     return lean_io_result_mk_ok(lean_box(0));
// }
