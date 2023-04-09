#include <string.h>
#include "util.h"
#include "structures.h"

LEAN_EXPORT lean_obj_res lean_raylib__InitWindow (uint32_t width, uint32_t height, lean_obj_arg title, lean_obj_arg world) {
    InitWindow(width, height, strdup(lean_string_cstr(title)));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__WindowShouldClose (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(WindowShouldClose()));
}

LEAN_EXPORT lean_obj_res lean_raylib__CloseWindow (lean_obj_arg world) {
    CloseWindow();
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
        images_c[i] = *lean_raylib_Image_from(lean_array_uget(images_box, i));
    }
    SetWindowIcons(images_c, count);
    free(images_c);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowTitle (lean_obj_arg title, lean_obj_arg world) {
    SetWindowTitle(lean_string_cstr(title));
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

LEAN_EXPORT lean_obj_res lean_raylib__SetWindowOpacity (double opacity, lean_obj_arg world) {
    SetWindowOpacity((float)opacity);
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__GetWindowHandle (lean_obj_arg world) {
//     void * result_ = GetWindowHandle();
//     return /*todo: ptr?*/result_;
// }

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

LEAN_EXPORT lean_obj_res lean_raylib__SetClipboardText (lean_obj_arg text, lean_obj_arg world) {
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

LEAN_EXPORT lean_obj_res lean_raylib__WaitTime (double seconds, lean_obj_arg world) {
    WaitTime(seconds);
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
    BeginMode2D(*lean_raylib_Camera2D_from(camera));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndMode2D (lean_obj_arg world) {
    EndMode2D();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginMode3D (b_lean_obj_arg camera, lean_obj_arg world) {
    BeginMode3D(*lean_raylib_Camera3D_from(camera));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndMode3D (lean_obj_arg world) {
    EndMode3D();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginTextureMode (b_lean_obj_arg target, lean_obj_arg world) {
    BeginTextureMode(*lean_raylib_RenderTexture_from(target));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndTextureMode (lean_obj_arg world) {
    EndTextureMode();
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__BeginShaderMode (lean_obj_arg shader, lean_obj_arg world) {
//     BeginShaderMode(lean_raylib_Shader_from(shader));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndShaderMode (lean_obj_arg world) {
//     EndShaderMode();
//     return lean_io_result_mk_ok(lean_box(0));
// }

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

// LEAN_EXPORT lean_obj_res lean_raylib__BeginVrStereoMode (lean_obj_arg config, lean_obj_arg world) {
//     BeginVrStereoMode(lean_raylib_VrStereoConfig_from(config));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndVrStereoMode (lean_obj_arg world) {
//     EndVrStereoMode();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadVrStereoConfig (lean_obj_arg device, lean_obj_arg world) {
//     VrStereoConfig result_ = LoadVrStereoConfig(lean_raylib_VrDeviceInfo_from(device));
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadVrStereoConfig (lean_obj_arg config, lean_obj_arg world) {
//     UnloadVrStereoConfig(lean_raylib_VrStereoConfig_from(config));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadShader (/* const char* */lean_obj_arg vsFileName, /* const char* */lean_obj_arg fsFileName, lean_obj_arg world) {
//     Shader result_ = LoadShader(lean_string_cstr(vsFileName), lean_string_cstr(fsFileName));
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadShaderFromMemory (/* const char* */lean_obj_arg vsCode, /* const char* */lean_obj_arg fsCode, lean_obj_arg world) {
//     Shader result_ = LoadShaderFromMemory(lean_string_cstr(vsCode), lean_string_cstr(fsCode));
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsShaderReady (lean_obj_arg shader, lean_obj_arg world) {
//     bool result_ = IsShaderReady(lean_raylib_Shader_from(shader));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetShaderLocation (lean_obj_arg shader, /* const char* */lean_obj_arg uniformName, lean_obj_arg world) {
//     int result_ = GetShaderLocation(lean_raylib_Shader_from(shader), lean_string_cstr(uniformName));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetShaderLocationAttrib (lean_obj_arg shader, /* const char* */lean_obj_arg attribName, lean_obj_arg world) {
//     int result_ = GetShaderLocationAttrib(lean_raylib_Shader_from(shader), lean_string_cstr(attribName));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValue (lean_obj_arg shader, uint32_t locIndex, /* const void* */lean_obj_arg value, uint32_t uniformType, lean_obj_arg world) {
//     SetShaderValue(lean_raylib_Shader_from(shader), locIndex, /*todo: ptr?*/value, uniformType);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueV (lean_obj_arg shader, uint32_t locIndex, /* const void* */lean_obj_arg value, uint32_t uniformType, uint32_t count, lean_obj_arg world) {
//     SetShaderValueV(lean_raylib_Shader_from(shader), locIndex, /*todo: ptr?*/value, uniformType, count);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueMatrix (lean_obj_arg shader, uint32_t locIndex, lean_obj_arg mat, lean_obj_arg world) {
//     SetShaderValueMatrix(lean_raylib_Shader_from(shader), locIndex, lean_raylib_Matrix_from(mat));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueTexture (lean_obj_arg shader, uint32_t locIndex, lean_obj_arg texture, lean_obj_arg world) {
//     SetShaderValueTexture(lean_raylib_Shader_from(shader), locIndex, /*cast Texture2D to_lean?false*/(texture));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadShader (lean_obj_arg shader, lean_obj_arg world) {
//     UnloadShader(lean_raylib_Shader_from(shader));
//     return lean_io_result_mk_ok(lean_box(0));
// }

LEAN_EXPORT lean_obj_res lean_raylib__GetMouseRay (b_lean_obj_arg mousePosition, b_lean_obj_arg camera, lean_obj_arg world) {
    LET_BOX(Ray, ray, GetMouseRay(lean_raylib_Vector2_from(mousePosition), *lean_raylib_Camera3D_from(camera)));
    return lean_io_result_mk_ok(lean_raylib_Ray_to(ray));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetCameraMatrix (b_lean_obj_arg camera) {
    return lean_raylib_Matrix_to(GetCameraMatrix(*lean_raylib_Camera3D_from(camera)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetCameraMatrix2D (b_lean_obj_arg camera) {
    return lean_raylib_Matrix_to(GetCameraMatrix2D(*lean_raylib_Camera2D_from(camera)));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWorldToScreen (b_lean_obj_arg position, b_lean_obj_arg camera, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetWorldToScreen(
        lean_raylib_Vector3_from(position),
        *lean_raylib_Camera3D_from(camera)
    )));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetScreenToWorld2D (b_lean_obj_arg position, b_lean_obj_arg camera) {
    return lean_raylib_Vector2_to(GetScreenToWorld2D(
        lean_raylib_Vector2_from(position),
        *lean_raylib_Camera2D_from(camera)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWorldToScreenEx (
    b_lean_obj_arg position, b_lean_obj_arg camera,
    uint32_t width, uint32_t height, lean_obj_arg world
) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetWorldToScreenEx(
        lean_raylib_Vector3_from(position),
        *lean_raylib_Camera3D_from(camera),
        width,
        height
    )));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetWorldToScreen2D (lean_obj_arg position, lean_obj_arg camera) {
    return lean_raylib_Vector2_to(GetWorldToScreen2D(
        lean_raylib_Vector2_from(position),
        *lean_raylib_Camera2D_from(camera)
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
    return lean_io_result_mk_ok(lean_box_float(GetFrameTime()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetTime (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_float(GetTime()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetRandomValue (uint32_t min, uint32_t max, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_uint32(GetRandomValue(min, max)));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetRandomSeed (uint32_t seed) {
    SetRandomSeed(seed);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__TakeScreenshot (lean_obj_arg fileName, lean_obj_arg world) {
    TakeScreenshot(lean_string_cstr(fileName));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetConfigFlags (uint32_t flags, lean_obj_arg world) {
    SetConfigFlags(flags);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__TraceLog_s (uint32_t logLevel, b_lean_obj_arg text, lean_obj_arg world) {
    TraceLog(logLevel, lean_string_cstr(text));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetTraceLogLevel (uint32_t logLevel, lean_obj_arg world) {
    SetTraceLogLevel(logLevel);
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__MemAlloc (uint32_t size, lean_obj_arg world) {
//     void * result_ = MemAlloc(size);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__MemRealloc (/* void* */lean_obj_arg ptr, uint32_t size, lean_obj_arg world) {
//     void * result_ = MemRealloc(/*todo: ptr?*/ptr, size);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MemFree (/* void* */lean_obj_arg ptr, lean_obj_arg world) {
//     MemFree(/*todo: ptr?*/ptr);
//     return lean_io_result_mk_ok(lean_box(0));
// }

LEAN_EXPORT lean_obj_res lean_raylib__OpenURL (b_lean_obj_arg url, lean_obj_arg world) {
    OpenURL(lean_string_cstr(url));
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__SetTraceLogCallback (lean_obj_arg callback, lean_obj_arg world) {
//     SetTraceLogCallback(/*cast TraceLogCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetLoadFileDataCallback (lean_obj_arg callback, lean_obj_arg world) {
//     SetLoadFileDataCallback(/*cast LoadFileDataCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetSaveFileDataCallback (lean_obj_arg callback, lean_obj_arg world) {
//     SetSaveFileDataCallback(/*cast SaveFileDataCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetLoadFileTextCallback (lean_obj_arg callback, lean_obj_arg world) {
//     SetLoadFileTextCallback(/*cast LoadFileTextCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetSaveFileTextCallback (lean_obj_arg callback, lean_obj_arg world) {
//     SetSaveFileTextCallback(/*cast SaveFileTextCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

LEAN_EXPORT lean_obj_res lean_raylib__LoadFileData (b_lean_obj_arg fileName) {
    unsigned int bytesReadSize;
    unsigned char* bytesRead = LoadFileData(lean_string_cstr(fileName), &bytesReadSize);
    lean_object* arr = lean_alloc_sarray(sizeof(uint8_t), bytesReadSize, bytesReadSize);
    uint8_t* arrBytes = lean_sarray_cptr(arr);
    memcpy(arrBytes, bytesRead, bytesReadSize); // todo: avoid copying
    UnloadFileData(bytesRead);
    return lean_io_result_mk_ok(arr);
}

LEAN_EXPORT lean_obj_res lean_raylib__UnloadFileData (b_lean_obj_arg data) {
    return lean_box(0);
}

LEAN_EXPORT lean_obj_res lean_raylib__SaveFileData (b_lean_obj_arg fileName, b_lean_obj_arg data, size_t offset, uint32_t bytesToWrite, lean_obj_arg world) {
    unsigned int size = lean_sarray_elem_size(data);
    if(offset >= size || offset + bytesToWrite > size) {
        return lean_io_result_mk_error(lean_mk_io_user_error(lean_mk_string("Saved data span out of ByteArray bounds.")));
    }
    return lean_io_result_mk_ok(lean_box(
        SaveFileData(lean_string_cstr(fileName), lean_sarray_cptr(data) + offset, bytesToWrite)
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__ExportDataAsCode (b_lean_obj_arg data, size_t offset, uint32_t exportSize, b_lean_obj_arg fileName, lean_obj_arg world) {
    unsigned int arraySize = lean_sarray_elem_size(data);
    if(offset >= arraySize || offset + exportSize > arraySize) {
        return lean_io_result_mk_error(lean_mk_io_user_error(lean_mk_string("Exported data span out of ByteArray bounds.")));
    }
    return lean_io_result_mk_ok(lean_box(
        ExportDataAsCode(lean_sarray_cptr(data) + offset, exportSize, lean_string_cstr(fileName))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadFileText (b_lean_obj_arg fileName, lean_obj_arg world) {
    char* text = LoadFileText(lean_string_cstr(fileName));
    lean_object* text_box = lean_mk_string(text);
    UnloadFileText(text);
    return lean_io_result_mk_ok(text_box);
}

LEAN_EXPORT lean_obj_res lean_raylib__UnloadFileText (b_lean_obj_arg text) {
    return lean_box(0);
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

LEAN_EXPORT lean_obj_res lean_raylib__CompressData (b_lean_obj_arg data) {
    int compressedDataSize;
    unsigned char * compressedData = CompressData(lean_sarray_cptr(data), lean_sarray_byte_size(data), &compressedDataSize);
    lean_object* compressedArray = lean_alloc_sarray(sizeof(uint8_t), compressedDataSize, compressedDataSize);
    memcpy(lean_sarray_cptr(compressedArray), compressedData, compressedDataSize);
    MemFree(compressedData);
    return compressedArray;
}

LEAN_EXPORT lean_obj_res lean_raylib__DecompressData (b_lean_obj_arg compData) {
    int decompressedDataSize;
    unsigned char * decompressedData = DecompressData(lean_sarray_cptr(compData), lean_sarray_byte_size(compData), &decompressedDataSize);
    lean_object* decompressedArray = lean_alloc_sarray(sizeof(uint8_t), decompressedDataSize, decompressedDataSize);
    memcpy(lean_sarray_cptr(decompressedArray), decompressedData, decompressedDataSize);
    MemFree(decompressedData);
    return decompressedArray;
}

LEAN_EXPORT lean_obj_res lean_raylib__EncodeDataBase64 (b_lean_obj_arg data) {
    int encodedDataSize;
    char * encodedData = EncodeDataBase64(lean_sarray_cptr(data), lean_sarray_byte_size(data), &encodedDataSize);
    lean_object* encodedDataLean = lean_mk_string_from_bytes(encodedData, encodedDataSize);
    MemFree(encodedData);
    return encodedDataLean;
}

LEAN_EXPORT lean_obj_res lean_raylib__DecodeDataBase64 (b_lean_obj_arg data) {
    int decodedDataSize;
    unsigned char * decodedData = DecodeDataBase64(lean_string_cstr(data), &decodedDataSize);
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
    return lean_io_result_mk_ok(lean_box_float(GetGamepadAxisMovement(gamepad, axis)));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetGamepadMappings (lean_obj_arg mappings, lean_obj_arg world) {
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

LEAN_EXPORT lean_obj_res lean_raylib__SetMouseScale (double scaleX, double scaleY, lean_obj_arg world) {
    SetMouseScale((float)scaleX, (float)scaleY);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMouseWheelMove (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_float(GetMouseWheelMove()));
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
    return lean_io_result_mk_ok(lean_box_float(GetGestureHoldDuration()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGestureDragVector (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetGestureDragVector()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGestureDragAngle (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_float(GetGestureDragAngle()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGesturePinchVector (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_raylib_Vector2_to(GetGesturePinchVector()));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetGesturePinchAngle (lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_float(GetGesturePinchAngle()));
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateCamera (lean_obj_arg camera_old_box, uint32_t mode, lean_obj_arg world) {
    lean_object* camera_res_box;
    if(LEAN_LIKELY(lean_is_exclusive(camera_old_box))) {
        camera_res_box = camera_old_box;
    }
    else {
        LET_BOX(Camera, camera_res, *lean_raylib_Camera3D_from(camera_old_box));
        lean_dec_ref(camera_old_box);
        camera_res_box = lean_raylib_Camera3D_to(camera_res);
    }
    UpdateCamera(lean_raylib_Camera3D_from(camera_res_box), mode);
    return lean_io_result_mk_ok(camera_res_box);
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateCameraPro (lean_obj_arg camera_old_box, b_lean_obj_arg movement, b_lean_obj_arg rotation, double zoom) {
    lean_object* camera_res_box;
    if(LEAN_LIKELY(lean_is_exclusive(camera_old_box))) {
        camera_res_box = camera_old_box;
    }
    else {
        LET_BOX(Camera, camera_res, *lean_raylib_Camera3D_from(camera_old_box));
        lean_dec_ref(camera_old_box);
        camera_res_box = lean_raylib_Camera3D_to(camera_res);
    }
    UpdateCameraPro(
        lean_raylib_Camera3D_from(camera_res_box),
        lean_raylib_Vector3_from(movement),
        lean_raylib_Vector3_from(rotation),
        (float)zoom
    );
    return lean_io_result_mk_ok(camera_res_box);
}

LEAN_EXPORT lean_obj_res lean_raylib__SetShapesTexture (lean_obj_arg textureRef_box, b_lean_obj_arg source, lean_obj_arg world) {
    static lean_object* current = NULL;
    lean_raylib_TextureRef const* textureRef = lean_raylib_TextureRef_from(textureRef_box);
    if(current != NULL) {
        lean_dec(current);
    }
    current = textureRef->owner;
    SetShapesTexture(textureRef->texture, *lean_raylib_Rectangle_from(source));
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

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineEx (lean_obj_arg startPos, lean_obj_arg endPos, double thick, uint32_t color, lean_obj_arg world) {
    DrawLineEx(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), (float)thick, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezier (lean_obj_arg startPos, lean_obj_arg endPos, double thick, uint32_t color, lean_obj_arg world) {
    DrawLineBezier(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), (float)thick, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezierQuad (lean_obj_arg startPos, lean_obj_arg endPos, lean_obj_arg controlPos, double thick, uint32_t color, lean_obj_arg world) {
    DrawLineBezierQuad(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_raylib_Vector2_from(controlPos), (float)thick, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezierCubic (lean_obj_arg startPos, lean_obj_arg endPos, lean_obj_arg startControlPos, lean_obj_arg endControlPos, double thick, uint32_t color, lean_obj_arg world) {
    DrawLineBezierCubic(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_raylib_Vector2_from(startControlPos), lean_raylib_Vector2_from(endControlPos), (float)thick, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLineStrip (/* Vector2* */lean_obj_arg points, uint32_t pointCount, uint32_t color, lean_obj_arg world) {
//     DrawLineStrip(/*todo: ptr?*/points, pointCount, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircle (int32_t centerX, int32_t centerY, double radius, uint32_t color, lean_obj_arg world) {
    DrawCircle(centerX, centerY, (float)radius, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleSector (b_lean_obj_arg center, double radius, double startAngle, double endAngle, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawCircleSector(lean_raylib_Vector2_from(center), (float)radius, (float)startAngle, (float)endAngle, segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleSectorLines (b_lean_obj_arg center, double radius, double startAngle, double endAngle, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawCircleSectorLines(lean_raylib_Vector2_from(center), (float)radius, (float)startAngle, (float)endAngle, segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleGradient (int32_t centerX, int32_t centerY, double radius, uint32_t color1, uint32_t color2, lean_obj_arg world) {
    DrawCircleGradient(centerX, centerY, (float)radius, lean_raylib_Color_from(color1), lean_raylib_Color_from(color2));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleV (b_lean_obj_arg center, double radius, uint32_t color, lean_obj_arg world) {
    DrawCircleV(lean_raylib_Vector2_from(center), (float)radius, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleLines (int32_t centerX, int32_t centerY, double radius, uint32_t color, lean_obj_arg world) {
    DrawCircleLines(centerX, centerY, (float)radius, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawEllipse (int32_t centerX, int32_t centerY, double radiusH, double radiusV, uint32_t color, lean_obj_arg world) {
    DrawEllipse(centerX, centerY, (float)radiusH, (float)radiusV, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawEllipseLines (int32_t centerX, int32_t centerY, double radiusH, double radiusV, uint32_t color, lean_obj_arg world) {
    DrawEllipseLines(centerX, centerY, (float)radiusH, (float)radiusV, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRing (b_lean_obj_arg center, double innerRadius, double outerRadius, double startAngle, double endAngle, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawRing(lean_raylib_Vector2_from(center), (float)innerRadius, (float)outerRadius, (float)startAngle, (float)endAngle, segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRingLines (b_lean_obj_arg center, double innerRadius, double outerRadius, double startAngle, double endAngle, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawRingLines(lean_raylib_Vector2_from(center), (float)innerRadius, (float)outerRadius, (float)startAngle, (float)endAngle, segments, lean_raylib_Color_from(color));
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
    DrawRectangleRec(*lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectanglePro (b_lean_obj_arg rec, b_lean_obj_arg origin, double rotation, uint32_t color, lean_obj_arg world) {
    DrawRectanglePro(*lean_raylib_Rectangle_from(rec), lean_raylib_Vector2_from(origin), (float)rotation, lean_raylib_Color_from(color));
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
    DrawRectangleGradientEx(*lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(col1), lean_raylib_Color_from(col2), lean_raylib_Color_from(col3), lean_raylib_Color_from(col4));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleLines (int32_t posX, int32_t posY, int32_t width, int32_t height, uint32_t color, lean_obj_arg world) {
    DrawRectangleLines(posX, posY, width, height, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleLinesEx (b_lean_obj_arg rec, double lineThick, uint32_t color, lean_obj_arg world) {
    DrawRectangleLinesEx(*lean_raylib_Rectangle_from(rec), (float)lineThick, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleRounded (b_lean_obj_arg rec, double roundness, uint32_t segments, uint32_t color, lean_obj_arg world) {
    DrawRectangleRounded(*lean_raylib_Rectangle_from(rec), (float)roundness, segments, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleRoundedLines (b_lean_obj_arg rec, double roundness, uint32_t segments, double lineThick, uint32_t color, lean_obj_arg world) {
    DrawRectangleRoundedLines(*lean_raylib_Rectangle_from(rec), (float)roundness, segments, (float)lineThick, lean_raylib_Color_from(color));
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

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleFan (/* Vector2* */lean_obj_arg points, uint32_t pointCount, uint32_t color, lean_obj_arg world) {
//     DrawTriangleFan(/*todo: ptr?*/points, pointCount, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleStrip (/* Vector2* */lean_obj_arg points, uint32_t pointCount, uint32_t color, lean_obj_arg world) {
//     DrawTriangleStrip(/*todo: ptr?*/points, pointCount, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPoly (lean_obj_arg center, uint32_t sides, double radius, double rotation, uint32_t color, lean_obj_arg world) {
//     DrawPoly(lean_raylib_Vector2_from(center), sides, (float)radius, (float)rotation, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPolyLines (lean_obj_arg center, uint32_t sides, double radius, double rotation, uint32_t color, lean_obj_arg world) {
//     DrawPolyLines(lean_raylib_Vector2_from(center), sides, (float)radius, (float)rotation, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPolyLinesEx (lean_obj_arg center, uint32_t sides, double radius, double rotation, double lineThick, uint32_t color, lean_obj_arg world) {
//     DrawPolyLinesEx(lean_raylib_Vector2_from(center), sides, (float)radius, (float)rotation, (float)lineThick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionRecs (lean_obj_arg rec1, lean_obj_arg rec2, lean_obj_arg world) {
//     bool result_ = CheckCollisionRecs(lean_raylib_Rectangle_from(rec1), lean_raylib_Rectangle_from(rec2));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionCircles (lean_obj_arg center1, double radius1, lean_obj_arg center2, double radius2, lean_obj_arg world) {
//     bool result_ = CheckCollisionCircles(lean_raylib_Vector2_from(center1), (float)radius1, lean_raylib_Vector2_from(center2), (float)radius2);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionCircleRec (lean_obj_arg center, double radius, lean_obj_arg rec, lean_obj_arg world) {
//     bool result_ = CheckCollisionCircleRec(lean_raylib_Vector2_from(center), (float)radius, lean_raylib_Rectangle_from(rec));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointRec (lean_obj_arg point, lean_obj_arg rec, lean_obj_arg world) {
//     bool result_ = CheckCollisionPointRec(lean_raylib_Vector2_from(point), lean_raylib_Rectangle_from(rec));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointCircle (lean_obj_arg point, lean_obj_arg center, double radius, lean_obj_arg world) {
//     bool result_ = CheckCollisionPointCircle(lean_raylib_Vector2_from(point), lean_raylib_Vector2_from(center), (float)radius);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointTriangle (lean_obj_arg point, lean_obj_arg p1, lean_obj_arg p2, lean_obj_arg p3, lean_obj_arg world) {
//     bool result_ = CheckCollisionPointTriangle(lean_raylib_Vector2_from(point), lean_raylib_Vector2_from(p1), lean_raylib_Vector2_from(p2), lean_raylib_Vector2_from(p3));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointPoly (lean_obj_arg point, /* Vector2* */lean_obj_arg points, uint32_t pointCount, lean_obj_arg world) {
//     bool result_ = CheckCollisionPointPoly(lean_raylib_Vector2_from(point), /*todo: ptr?*/points, pointCount);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionLines (lean_obj_arg startPos1, lean_obj_arg endPos1, lean_obj_arg startPos2, lean_obj_arg endPos2, /* Vector2* */lean_obj_arg collisionPoint, lean_obj_arg world) {
//     bool result_ = CheckCollisionLines(lean_raylib_Vector2_from(startPos1), lean_raylib_Vector2_from(endPos1), lean_raylib_Vector2_from(startPos2), lean_raylib_Vector2_from(endPos2), /*todo: ptr?*/collisionPoint);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointLine (lean_obj_arg point, lean_obj_arg p1, lean_obj_arg p2, uint32_t threshold) {
//     bool result_ = CheckCollisionPointLine(lean_raylib_Vector2_from(point), lean_raylib_Vector2_from(p1), lean_raylib_Vector2_from(p2), threshold);
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetCollisionRec (lean_obj_arg rec1, lean_obj_arg rec2, lean_obj_arg world) {
//     Rectangle result_ = GetCollisionRec(lean_raylib_Rectangle_from(rec1), lean_raylib_Rectangle_from(rec2));
//     return lean_raylib_Rectangle_to(result_);
// }


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

LEAN_EXPORT lean_obj_res lean_raylib__LoadImageFromMemory (
    /* String */ b_lean_obj_arg fileType,
    /* ByteArray */ b_lean_obj_arg fileDataArray
, lean_obj_arg world) {
    size_t dataSize = lean_sarray_byte_size(fileDataArray);
    uint8_t* fileData = lean_sarray_cptr(fileDataArray);
    LET_BOX(Image, image, LoadImageFromMemory(
        lean_string_cstr(fileType),
        fileData,
        dataSize
    ));
    return lean_io_result_mk_ok(lean_raylib_Image_to(image));
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

LEAN_EXPORT lean_obj_res lean_raylib__UnloadImage (b_lean_obj_arg _image) {
    return lean_box(0);
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

LEAN_EXPORT lean_obj_res lean_raylib__GenImageGradientRadial (uint32_t width, uint32_t height, double density, uint32_t inner, uint32_t outer) {
    LET_BOX(Image, image, GenImageGradientRadial(width, height, (float)density, lean_raylib_Color_from(inner), lean_raylib_Color_from(outer)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageChecked (uint32_t width, uint32_t height, uint32_t checksX, uint32_t checksY, uint32_t col1, uint32_t col2) {
    LET_BOX(Image, image, GenImageChecked(width, height, checksX, checksY, lean_raylib_Color_from(col1), lean_raylib_Color_from(col2)));
    return lean_raylib_Image_to(image);
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImageWhiteNoise (uint32_t width, uint32_t height, double factor, lean_obj_arg world) {
    LET_BOX(Image, image, GenImageWhiteNoise(width, height, (float)factor));
    return lean_io_result_mk_ok(lean_raylib_Image_to(image));
}

LEAN_EXPORT lean_obj_res lean_raylib__GenImagePerlinNoise (uint32_t width, uint32_t height, uint32_t offsetX, uint32_t offsetY, double scale) {
    LET_BOX(Image, image, GenImagePerlinNoise(width, height, offsetX, offsetY, (float)scale));
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
    LET_BOX(Image, image_copy, ImageFromImage(*lean_raylib_Image_from(image), *lean_raylib_Rectangle_from(rec)));
    return lean_raylib_Image_to(image_copy);
}

// LEAN_EXPORT lean_obj_res lean_raylib__ImageText (/* const char* */lean_obj_arg text, uint32_t fontSize, uint32_t color, lean_obj_arg world) {
//     Image result_ = ImageText(lean_string_cstr(text), fontSize, lean_raylib_Color_from(color));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageTextEx (lean_obj_arg font, /* const char* */lean_obj_arg text, double fontSize, double spacing, uint32_t tint, lean_obj_arg world) {
//     Image result_ = ImageTextEx(lean_raylib_Font_from(font), lean_string_cstr(text), (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageFormat (/* Image* */lean_obj_arg image, uint32_t newFormat, lean_obj_arg world) {
//     ImageFormat(/*todo: ptr?*/image, newFormat);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageToPOT (/* Image* */lean_obj_arg image, uint32_t fill, lean_obj_arg world) {
//     ImageToPOT(/*todo: ptr?*/image, lean_raylib_Color_from(fill));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageCrop (/* Image* */lean_obj_arg image, lean_obj_arg crop, lean_obj_arg world) {
//     ImageCrop(/*todo: ptr?*/image, lean_raylib_Rectangle_from(crop));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaCrop (/* Image* */lean_obj_arg image, double threshold) {
//     ImageAlphaCrop(/*todo: ptr?*/image, (float)threshold);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaClear (/* Image* */lean_obj_arg image, uint32_t color, double threshold) {
//     ImageAlphaClear(/*todo: ptr?*/image, lean_raylib_Color_from(color), (float)threshold);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaMask (/* Image* */lean_obj_arg image, lean_obj_arg alphaMask, lean_obj_arg world) {
//     ImageAlphaMask(/*todo: ptr?*/image, lean_raylib_Image_from(alphaMask));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaPremultiply (/* Image* */lean_obj_arg image, lean_obj_arg world) {
//     ImageAlphaPremultiply(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageBlurGaussian (/* Image* */lean_obj_arg image, uint32_t blurSize, lean_obj_arg world) {
//     ImageBlurGaussian(/*todo: ptr?*/image, blurSize);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageResize (/* Image* */lean_obj_arg image, uint32_t newWidth, uint32_t newHeight, lean_obj_arg world) {
//     ImageResize(/*todo: ptr?*/image, newWidth, newHeight);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageResizeNN (/* Image* */lean_obj_arg image, uint32_t newWidth, uint32_t newHeight, lean_obj_arg world) {
//     ImageResizeNN(/*todo: ptr?*/image, newWidth, newHeight);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageResizeCanvas (/* Image* */lean_obj_arg image, uint32_t newWidth, uint32_t newHeight, uint32_t offsetX, uint32_t offsetY, uint32_t fill, lean_obj_arg world) {
//     ImageResizeCanvas(/*todo: ptr?*/image, newWidth, newHeight, offsetX, offsetY, lean_raylib_Color_from(fill));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageMipmaps (/* Image* */lean_obj_arg image, lean_obj_arg world) {
//     ImageMipmaps(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDither (/* Image* */lean_obj_arg image, uint32_t rBpp, uint32_t gBpp, uint32_t bBpp, uint32_t aBpp, lean_obj_arg world) {
//     ImageDither(/*todo: ptr?*/image, rBpp, gBpp, bBpp, aBpp);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageFlipVertical (/* Image* */lean_obj_arg image, lean_obj_arg world) {
//     ImageFlipVertical(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageFlipHorizontal (/* Image* */lean_obj_arg image, lean_obj_arg world) {
//     ImageFlipHorizontal(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageRotateCW (/* Image* */lean_obj_arg image, lean_obj_arg world) {
//     ImageRotateCW(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageRotateCCW (/* Image* */lean_obj_arg image, lean_obj_arg world) {
//     ImageRotateCCW(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorTint (/* Image* */lean_obj_arg image, uint32_t color, lean_obj_arg world) {
//     ImageColorTint(/*todo: ptr?*/image, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorInvert (/* Image* */lean_obj_arg image, lean_obj_arg world) {
//     ImageColorInvert(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorGrayscale (/* Image* */lean_obj_arg image, lean_obj_arg world) {
//     ImageColorGrayscale(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorContrast (/* Image* */lean_obj_arg image, double contrast, lean_obj_arg world) {
//     ImageColorContrast(/*todo: ptr?*/image, (float)contrast);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorBrightness (/* Image* */lean_obj_arg image, uint32_t brightness, lean_obj_arg world) {
//     ImageColorBrightness(/*todo: ptr?*/image, brightness);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorReplace (/* Image* */lean_obj_arg image, uint32_t color, uint32_t replace, lean_obj_arg world) {
//     ImageColorReplace(/*todo: ptr?*/image, lean_raylib_Color_from(color), lean_raylib_Color_from(replace));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* Color* */lean_obj_arg lean_raylib__LoadImageColors (lean_obj_arg image, lean_obj_arg world) {
//     Color * result_ = LoadImageColors(lean_raylib_Image_from(image));
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* Color* */lean_obj_arg lean_raylib__LoadImagePalette (lean_obj_arg image, uint32_t maxPaletteSize, /* int* */lean_obj_arg colorCount, lean_obj_arg world) {
//     Color * result_ = LoadImagePalette(lean_raylib_Image_from(image), maxPaletteSize, /*todo: ptr?*/colorCount);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadImageColors (/* Color* */lean_obj_arg colors, lean_obj_arg world) {
//     UnloadImageColors(/*todo: ptr?*/colors);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadImagePalette (/* Color* */lean_obj_arg colors, lean_obj_arg world) {
//     UnloadImagePalette(/*todo: ptr?*/colors);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetImageAlphaBorder (lean_obj_arg image, double threshold) {
//     Rectangle result_ = GetImageAlphaBorder(lean_raylib_Image_from(image), (float)threshold);
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GetImageColor (lean_obj_arg image, uint32_t x, uint32_t y, lean_obj_arg world) {
//     Color result_ = GetImageColor(lean_raylib_Image_from(image), x, y);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageClearBackground (/* Image* */lean_obj_arg dst, uint32_t color, lean_obj_arg world) {
//     ImageClearBackground(/*todo: ptr?*/dst, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawPixel (/* Image* */lean_obj_arg dst, uint32_t posX, uint32_t posY, uint32_t color, lean_obj_arg world) {
//     ImageDrawPixel(/*todo: ptr?*/dst, posX, posY, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawPixelV (/* Image* */lean_obj_arg dst, lean_obj_arg position, uint32_t color, lean_obj_arg world) {
//     ImageDrawPixelV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(position), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawLine (/* Image* */lean_obj_arg dst, uint32_t startPosX, uint32_t startPosY, uint32_t endPosX, uint32_t endPosY, uint32_t color, lean_obj_arg world) {
//     ImageDrawLine(/*todo: ptr?*/dst, startPosX, startPosY, endPosX, endPosY, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawLineV (/* Image* */lean_obj_arg dst, lean_obj_arg start, lean_obj_arg end, uint32_t color, lean_obj_arg world) {
//     ImageDrawLineV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(start), lean_raylib_Vector2_from(end), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircle (/* Image* */lean_obj_arg dst, uint32_t centerX, uint32_t centerY, uint32_t radius, uint32_t color, lean_obj_arg world) {
//     ImageDrawCircle(/*todo: ptr?*/dst, centerX, centerY, radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleV (/* Image* */lean_obj_arg dst, lean_obj_arg center, uint32_t radius, uint32_t color, lean_obj_arg world) {
//     ImageDrawCircleV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(center), radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleLines (/* Image* */lean_obj_arg dst, uint32_t centerX, uint32_t centerY, uint32_t radius, uint32_t color, lean_obj_arg world) {
//     ImageDrawCircleLines(/*todo: ptr?*/dst, centerX, centerY, radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleLinesV (/* Image* */lean_obj_arg dst, lean_obj_arg center, uint32_t radius, uint32_t color, lean_obj_arg world) {
//     ImageDrawCircleLinesV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(center), radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangle (/* Image* */lean_obj_arg dst, uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t color, lean_obj_arg world) {
//     ImageDrawRectangle(/*todo: ptr?*/dst, posX, posY, width, height, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleV (/* Image* */lean_obj_arg dst, lean_obj_arg position, lean_obj_arg size, uint32_t color, lean_obj_arg world) {
//     ImageDrawRectangleV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(position), lean_raylib_Vector2_from(size), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleRec (/* Image* */lean_obj_arg dst, lean_obj_arg rec, uint32_t color, lean_obj_arg world) {
//     ImageDrawRectangleRec(/*todo: ptr?*/dst, lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleLines (/* Image* */lean_obj_arg dst, lean_obj_arg rec, uint32_t thick, uint32_t color, lean_obj_arg world) {
//     ImageDrawRectangleLines(/*todo: ptr?*/dst, lean_raylib_Rectangle_from(rec), thick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDraw (/* Image* */lean_obj_arg dst, lean_obj_arg src, lean_obj_arg srcRec, lean_obj_arg dstRec, uint32_t tint, lean_obj_arg world) {
//     ImageDraw(/*todo: ptr?*/dst, lean_raylib_Image_from(src), lean_raylib_Rectangle_from(srcRec), lean_raylib_Rectangle_from(dstRec), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawText (/* Image* */lean_obj_arg dst, /* const char* */lean_obj_arg text, uint32_t posX, uint32_t posY, uint32_t fontSize, uint32_t color, lean_obj_arg world) {
//     ImageDrawText(/*todo: ptr?*/dst, lean_string_cstr(text), posX, posY, fontSize, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawTextEx (/* Image* */lean_obj_arg dst, lean_obj_arg font, /* const char* */lean_obj_arg text, lean_obj_arg position, double fontSize, double spacing, uint32_t tint, lean_obj_arg world) {
//     ImageDrawTextEx(/*todo: ptr?*/dst, lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

LEAN_EXPORT lean_obj_res lean_raylib__LoadTexture (b_lean_obj_arg fileName, lean_obj_arg world) {
    LET_BOX(Texture2D, texture, LoadTexture(lean_string_cstr(fileName)));
    return lean_io_result_mk_ok(lean_raylib_Texture_to(texture));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadTextureFromImage (b_lean_obj_arg image) {
    LET_BOX(Texture2D, texture, LoadTextureFromImage(*lean_raylib_Image_from(image)));
    return lean_raylib_Texture_to(texture);
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadTextureCubemap (b_lean_obj_arg image, uint32_t layout) {
    LET_BOX(TextureCubemap, texture, LoadTextureCubemap(*lean_raylib_Image_from(image), layout));
    return lean_raylib_Texture_to(texture);
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadRenderTexture (uint32_t width, uint32_t height, lean_obj_arg world) {
    LET_BOX(RenderTexture2D, rt, LoadRenderTexture(width, height));
    return lean_io_result_mk_ok(lean_raylib_RenderTexture_to(rt));
}

LEAN_EXPORT uint8_t lean_raylib__IsTextureReady (b_lean_obj_arg textureRef) {
    return IsTextureReady(lean_raylib_TextureRef_from(textureRef)->texture);
}

LEAN_EXPORT lean_obj_res lean_raylib__UnloadTexture (b_lean_obj_arg texture) {
    return lean_box(0);
}

LEAN_EXPORT uint8_t lean_raylib__IsRenderTextureReady (b_lean_obj_arg target) {
    return IsRenderTextureReady(*lean_raylib_RenderTexture_from(target));
}

LEAN_EXPORT lean_obj_res lean_raylib__UnloadRenderTexture (b_lean_obj_arg target) {
    return lean_box(0);
}

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateTexture (lean_obj_arg texture, /* const void* */lean_obj_arg pixels, lean_obj_arg world) {
//     UpdateTexture(/*cast Texture2D to_lean?false*/(texture), /*todo: ptr?*/pixels);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateTextureRec (lean_obj_arg texture, lean_obj_arg rec, /* const void* */lean_obj_arg pixels, lean_obj_arg world) {
//     UpdateTextureRec(/*cast Texture2D to_lean?false*/(texture), lean_raylib_Rectangle_from(rec), /*todo: ptr?*/pixels);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenTextureMipmaps (/* Texture2D* */lean_obj_arg texture, lean_obj_arg world) {
//     GenTextureMipmaps(/*todo: ptr?*/texture);
//     return lean_io_result_mk_ok(lean_box(0));
// }

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

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureEx (b_lean_obj_arg textureRef, b_lean_obj_arg position, double rotation, double scale, uint32_t tint, lean_obj_arg world) {
    DrawTextureEx(lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Vector2_from(position), (float)rotation, (float)scale, lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureRec (b_lean_obj_arg textureRef, b_lean_obj_arg source, b_lean_obj_arg position, uint32_t tint, lean_obj_arg world) {
    DrawTextureRec(lean_raylib_TextureRef_from(textureRef)->texture, *lean_raylib_Rectangle_from(source), lean_raylib_Vector2_from(position), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTexturePro (b_lean_obj_arg textureRef, b_lean_obj_arg source, b_lean_obj_arg dest, b_lean_obj_arg origin, double rotation, uint32_t tint, lean_obj_arg world) {
    DrawTexturePro(lean_raylib_TextureRef_from(textureRef)->texture, *lean_raylib_Rectangle_from(source), *lean_raylib_Rectangle_from(dest), lean_raylib_Vector2_from(origin), (float)rotation, lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureNPatch (b_lean_obj_arg texture, b_lean_obj_arg nPatchInfo, b_lean_obj_arg dest, b_lean_obj_arg origin, double rotation, uint32_t tint, lean_obj_arg world) {
    DrawTextureNPatch(*lean_raylib_Texture_from(texture), *lean_raylib_NPatchInfo_from(nPatchInfo), *lean_raylib_Rectangle_from(dest), lean_raylib_Vector2_from(origin), (float)rotation, lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT uint32_t lean_raylib__Fade (uint32_t color, double alpha) {
    return lean_raylib_Color_to(Fade(lean_raylib_Color_from(color), alpha));
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

LEAN_EXPORT uint32_t lean_raylib__ColorFromHSV (double hue, double saturation, double value) {
    return lean_raylib_Color_to(ColorFromHSV(
        (float)hue,
        (float)saturation,
        (float)value
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorTint (uint32_t color, uint32_t tint) {
    return lean_raylib_Color_to(ColorTint(
        lean_raylib_Color_from(color),
        lean_raylib_Color_from(tint)
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorBrightness (uint32_t color, double factor) {
    return lean_raylib_Color_to(ColorBrightness(
        lean_raylib_Color_from(color),
        (float)factor
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorContrast (uint32_t color, double contrast) {
    return lean_raylib_Color_to(ColorContrast(
        lean_raylib_Color_from(color),
        (float)contrast
    ));
}

LEAN_EXPORT uint32_t lean_raylib__ColorAlpha (uint32_t color, double alpha) {
    return lean_raylib_Color_to(ColorAlpha(
        lean_raylib_Color_from(color),
        (float)alpha
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

// LEAN_EXPORT uint32_t lean_raylib__GetPixelColor (/* void* */lean_obj_arg srcPtr, uint32_t format, lean_obj_arg world) {
//     Color result_ = GetPixelColor(/*todo: ptr?*/srcPtr, format);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetPixelColor (/* void* */lean_obj_arg dstPtr, uint32_t color, uint32_t format, lean_obj_arg world) {
//     SetPixelColor(/*todo: ptr?*/dstPtr, lean_raylib_Color_from(color), format);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__GetPixelDataSize (uint32_t width, uint32_t height, uint32_t format, lean_obj_arg world) {
//     int result_ = GetPixelDataSize(width, height, format);
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetFontDefault (lean_obj_arg world) {
//     Font result_ = GetFontDefault();
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadFont (/* const char* */lean_obj_arg fileName, lean_obj_arg world) {
//     Font result_ = LoadFont(lean_string_cstr(fileName));
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadFontEx (/* const char* */lean_obj_arg fileName, uint32_t fontSize, /* int* */lean_obj_arg fontChars, uint32_t glyphCount, lean_obj_arg world) {
//     Font result_ = LoadFontEx(lean_string_cstr(fileName), fontSize, /*todo: ptr?*/fontChars, glyphCount);
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadFontFromImage (lean_obj_arg image, uint32_t key, uint32_t firstChar, lean_obj_arg world) {
//     Font result_ = LoadFontFromImage(lean_raylib_Image_from(image), lean_raylib_Color_from(key), firstChar);
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadFontFromMemory (/* const char* */lean_obj_arg fileType, /* const unsigned char* */lean_obj_arg fileData, uint32_t dataSize, uint32_t fontSize, /* int* */lean_obj_arg fontChars, uint32_t glyphCount, lean_obj_arg world) {
//     Font result_ = LoadFontFromMemory(lean_string_cstr(fileType), /*todo: ptr?*/fileData, dataSize, fontSize, /*todo: ptr?*/fontChars, glyphCount);
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsFontReady (lean_obj_arg font, lean_obj_arg world) {
//     bool result_ = IsFontReady(lean_raylib_Font_from(font));
//     return result_;
// }

// LEAN_EXPORT /* GlyphInfo* */lean_obj_arg lean_raylib__LoadFontData (/* const unsigned char* */lean_obj_arg fileData, uint32_t dataSize, uint32_t fontSize, /* int* */lean_obj_arg fontChars, uint32_t glyphCount, uint32_t type, lean_obj_arg world) {
//     GlyphInfo * result_ = LoadFontData(/*todo: ptr?*/fileData, dataSize, fontSize, /*todo: ptr?*/fontChars, glyphCount, type);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenImageFontAtlas (/* const GlyphInfo* */lean_obj_arg chars, /* Rectangle ** */lean_obj_arg recs, uint32_t glyphCount, uint32_t fontSize, uint32_t padding, uint32_t packMethod) {
//     Image result_ = GenImageFontAtlas(/*todo: ptr?*/chars, /*todo: ptr?*/recs, glyphCount, fontSize, padding, packMethod);
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadFontData (/* GlyphInfo* */lean_obj_arg chars, uint32_t glyphCount, lean_obj_arg world) {
//     UnloadFontData(/*todo: ptr?*/chars, glyphCount);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadFont (lean_obj_arg font, lean_obj_arg world) {
//     UnloadFont(lean_raylib_Font_from(font));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportFontAsCode (lean_obj_arg font, /* const char* */lean_obj_arg fileName, lean_obj_arg world) {
//     bool result_ = ExportFontAsCode(lean_raylib_Font_from(font), lean_string_cstr(fileName));
//     return result_;
// }

LEAN_EXPORT lean_obj_res lean_raylib__DrawFPS (uint32_t posX, uint32_t posY, lean_obj_arg world) {
    DrawFPS(posX, posY);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawText (lean_obj_arg text, uint32_t posX, uint32_t posY, uint32_t fontSize, uint32_t color, lean_obj_arg world) {
    DrawText(lean_string_cstr(text), posX, posY, fontSize, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextEx (lean_obj_arg font, /* const char* */lean_obj_arg text, lean_obj_arg position, double fontSize, double spacing, uint32_t tint, lean_obj_arg world) {
//     DrawTextEx(lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextPro (lean_obj_arg font, /* const char* */lean_obj_arg text, lean_obj_arg position, lean_obj_arg origin, double rotation, double fontSize, double spacing, uint32_t tint, lean_obj_arg world) {
//     DrawTextPro(lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), lean_raylib_Vector2_from(origin), (float)rotation, (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextCodepoint (lean_obj_arg font, uint32_t codepoint, lean_obj_arg position, double fontSize, uint32_t tint, lean_obj_arg world) {
//     DrawTextCodepoint(lean_raylib_Font_from(font), codepoint, lean_raylib_Vector2_from(position), (float)fontSize, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextCodepoints (lean_obj_arg font, /* const int* */lean_obj_arg codepoints, uint32_t count, lean_obj_arg position, double fontSize, double spacing, uint32_t tint, lean_obj_arg world) {
//     DrawTextCodepoints(lean_raylib_Font_from(font), /*todo: ptr?*/codepoints, count, lean_raylib_Vector2_from(position), (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__MeasureText (/* const char* */lean_obj_arg text, uint32_t fontSize, lean_obj_arg world) {
//     int result_ = MeasureText(lean_string_cstr(text), fontSize);
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MeasureTextEx (lean_obj_arg font, /* const char* */lean_obj_arg text, double fontSize, double spacing, lean_obj_arg world) {
//     Vector2 result_ = MeasureTextEx(lean_raylib_Font_from(font), lean_string_cstr(text), (float)fontSize, (float)spacing);
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GetGlyphIndex (lean_obj_arg font, uint32_t codepoint, lean_obj_arg world) {
//     int result_ = GetGlyphIndex(lean_raylib_Font_from(font), codepoint);
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetGlyphInfo (lean_obj_arg font, uint32_t codepoint, lean_obj_arg world) {
//     GlyphInfo result_ = GetGlyphInfo(lean_raylib_Font_from(font), codepoint);
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetGlyphAtlasRec (lean_obj_arg font, uint32_t codepoint, lean_obj_arg world) {
//     Rectangle result_ = GetGlyphAtlasRec(lean_raylib_Font_from(font), codepoint);
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT /* char* */lean_obj_arg lean_raylib__LoadUTF8 (/* const int* */lean_obj_arg codepoints, uint32_t length, lean_obj_arg world) {
//     char * result_ = LoadUTF8(/*todo: ptr?*/codepoints, length);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadUTF8 (/* char* */lean_obj_arg text, lean_obj_arg world) {
//     UnloadUTF8(/*todo: ptr?*/text);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* int* */lean_obj_arg lean_raylib__LoadCodepoints (/* const char* */lean_obj_arg text, /* int* */lean_obj_arg count, lean_obj_arg world) {
//     int * result_ = LoadCodepoints(lean_string_cstr(text), /*todo: ptr?*/count);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadCodepoints (/* int* */lean_obj_arg codepoints, lean_obj_arg world) {
//     UnloadCodepoints(/*todo: ptr?*/codepoints);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCodepointCount (/* const char* */lean_obj_arg text, lean_obj_arg world) {
//     int result_ = GetCodepointCount(lean_string_cstr(text));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCodepoint (/* const char* */lean_obj_arg text, /* int* */lean_obj_arg codepointSize, lean_obj_arg world) {
//     int result_ = GetCodepoint(lean_string_cstr(text), /*todo: ptr?*/codepointSize);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCodepointNext (/* const char* */lean_obj_arg text, /* int* */lean_obj_arg codepointSize, lean_obj_arg world) {
//     int result_ = GetCodepointNext(lean_string_cstr(text), /*todo: ptr?*/codepointSize);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCodepointPrevious (/* const char* */lean_obj_arg text, /* int* */lean_obj_arg codepointSize, lean_obj_arg world) {
//     int result_ = GetCodepointPrevious(lean_string_cstr(text), /*todo: ptr?*/codepointSize);
//     return result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__CodepointToUTF8 (uint32_t codepoint, /* int* */lean_obj_arg utf8Size, lean_obj_arg world) {
//     const char * result_ = CodepointToUTF8(codepoint, /*todo: ptr?*/utf8Size);
//     return lean_mk_string(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__TextCopy (/* char* */lean_obj_arg dst, /* const char* */lean_obj_arg src, lean_obj_arg world) {
//     int result_ = TextCopy(/*todo: ptr?*/dst, lean_string_cstr(src));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__TextIsEqual (/* const char* */lean_obj_arg text1, /* const char* */lean_obj_arg text2, lean_obj_arg world) {
//     bool result_ = TextIsEqual(lean_string_cstr(text1), lean_string_cstr(text2));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__TextLength (/* const char* */lean_obj_arg text, lean_obj_arg world) {
//     unsigned int result_ = TextLength(lean_string_cstr(text));
//     return result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextFormat (/* const char* */lean_obj_arg text, /* variadic */ ... args, lean_obj_arg world) {
//     const char * result_ = TextFormat(lean_string_cstr(text), /*todo: variadic*/args);
//     return lean_mk_string(result_);
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextSubtext (/* const char* */lean_obj_arg text, uint32_t position, uint32_t length, lean_obj_arg world) {
//     const char * result_ = TextSubtext(lean_string_cstr(text), position, length);
//     return lean_mk_string(result_);
// }

// LEAN_EXPORT /* char* */lean_obj_arg lean_raylib__TextReplace (/* char* */lean_obj_arg text, /* const char* */lean_obj_arg replace, /* const char* */lean_obj_arg by, lean_obj_arg world) {
//     char * result_ = TextReplace(/*todo: ptr?*/text, lean_string_cstr(replace), lean_string_cstr(by));
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* char* */lean_obj_arg lean_raylib__TextInsert (/* const char* */lean_obj_arg text, /* const char* */lean_obj_arg insert, uint32_t position, lean_obj_arg world) {
//     char * result_ = TextInsert(lean_string_cstr(text), lean_string_cstr(insert), position);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextJoin (/* const char ** */lean_obj_arg textList, uint32_t count, /* const char* */lean_obj_arg delimiter, lean_obj_arg world) {
//     const char * result_ = TextJoin(/*todo: ptr?*/textList, count, lean_string_cstr(delimiter));
//     return lean_mk_string(result_);
// }

// LEAN_EXPORT /* const char ** */lean_obj_arg lean_raylib__TextSplit (/* const char* */lean_obj_arg text, char delimiter, /* int* */lean_obj_arg count, lean_obj_arg world) {
//     const char * * result_ = TextSplit(lean_string_cstr(text), /*todo: char?*/delimiter, /*todo: ptr?*/count);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__TextAppend (/* char* */lean_obj_arg text, /* const char* */lean_obj_arg append, /* int* */lean_obj_arg position, lean_obj_arg world) {
//     TextAppend(/*todo: ptr?*/text, lean_string_cstr(append), /*todo: ptr?*/position);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__TextFindIndex (/* const char* */lean_obj_arg text, /* const char* */lean_obj_arg find) {
//     int result_ = TextFindIndex(lean_string_cstr(text), lean_string_cstr(find));
//     return result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextToUpper (/* const char* */lean_obj_arg text, lean_obj_arg world) {
//     const char * result_ = TextToUpper(lean_string_cstr(text));
//     return lean_mk_string(result_);
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextToLower (/* const char* */lean_obj_arg text, lean_obj_arg world) {
//     const char * result_ = TextToLower(lean_string_cstr(text));
//     return lean_mk_string(result_);
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextToPascal (/* const char* */lean_obj_arg text, lean_obj_arg world) {
//     const char * result_ = TextToPascal(lean_string_cstr(text));
//     return lean_mk_string(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__TextToInteger (/* const char* */lean_obj_arg text, lean_obj_arg world) {
//     int result_ = TextToInteger(lean_string_cstr(text));
//     return result_;
// }

LEAN_EXPORT lean_obj_res lean_raylib__DrawLine3D (b_lean_obj_arg startPos, b_lean_obj_arg endPos, uint32_t color, lean_obj_arg world) {
    DrawLine3D(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPoint3D (b_lean_obj_arg position, uint32_t color, lean_obj_arg world) {
    DrawPoint3D(lean_raylib_Vector3_from(position), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCircle3D (b_lean_obj_arg center, double radius, b_lean_obj_arg rotationAxis, double rotationAngle, uint32_t color, lean_obj_arg world) {
    DrawCircle3D(lean_raylib_Vector3_from(center), (float)radius, lean_raylib_Vector3_from(rotationAxis), (float)rotationAngle, lean_raylib_Color_from(color));
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

LEAN_EXPORT lean_obj_res lean_raylib__DrawCube (b_lean_obj_arg position, double width, double height, double length, uint32_t color, lean_obj_arg world) {
    DrawCube(lean_raylib_Vector3_from(position), (float)width, (float)height, (float)length, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeV (b_lean_obj_arg position, b_lean_obj_arg size, uint32_t color, lean_obj_arg world) {
    DrawCubeV(lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(size), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeWires (b_lean_obj_arg position, double width, double height, double length, uint32_t color, lean_obj_arg world) {
    DrawCubeWires(lean_raylib_Vector3_from(position), (float)width, (float)height, (float)length, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeWiresV (b_lean_obj_arg position, b_lean_obj_arg size, uint32_t color, lean_obj_arg world) {
    DrawCubeWiresV(lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(size), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawSphere (b_lean_obj_arg centerPos, double radius, uint32_t color, lean_obj_arg world) {
    DrawSphere(lean_raylib_Vector3_from(centerPos), (float)radius, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawSphereEx (b_lean_obj_arg centerPos, double radius, uint32_t rings, uint32_t slices, uint32_t color, lean_obj_arg world) {
    DrawSphereEx(lean_raylib_Vector3_from(centerPos), (float)radius, rings, slices, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawSphereWires (b_lean_obj_arg centerPos, double radius, uint32_t rings, uint32_t slices, uint32_t color, lean_obj_arg world) {
    DrawSphereWires(lean_raylib_Vector3_from(centerPos), (float)radius, rings, slices, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinder (b_lean_obj_arg position, double radiusTop, double radiusBottom, double height, uint32_t slices, uint32_t color, lean_obj_arg world) {
    DrawCylinder(lean_raylib_Vector3_from(position), (float)radiusTop, (float)radiusBottom, (float)height, slices, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderEx (b_lean_obj_arg startPos, b_lean_obj_arg endPos, double startRadius, double endRadius, uint32_t sides, uint32_t color, lean_obj_arg world) {
    DrawCylinderEx(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), (float)startRadius, (float)endRadius, sides, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderWires (b_lean_obj_arg position, double radiusTop, double radiusBottom, double height, uint32_t slices, uint32_t color, lean_obj_arg world) {
    DrawCylinderWires(lean_raylib_Vector3_from(position), (float)radiusTop, (float)radiusBottom, (float)height, slices, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderWiresEx (b_lean_obj_arg startPos, b_lean_obj_arg endPos, double startRadius, double endRadius, uint32_t sides, uint32_t color, lean_obj_arg world) {
    DrawCylinderWiresEx(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), (float)startRadius, (float)endRadius, sides, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCapsule (b_lean_obj_arg startPos, b_lean_obj_arg endPos, double radius, uint32_t slices, uint32_t rings, uint32_t color, lean_obj_arg world) {
    DrawCapsule(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), (float)radius, slices, rings, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawCapsuleWires (b_lean_obj_arg startPos, b_lean_obj_arg endPos, double radius, uint32_t slices, uint32_t rings, uint32_t color, lean_obj_arg world) {
    DrawCapsuleWires(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), (float)radius, slices, rings, lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawPlane (b_lean_obj_arg centerPos, b_lean_obj_arg size, uint32_t color, lean_obj_arg world) {
    DrawPlane(lean_raylib_Vector3_from(centerPos), lean_raylib_Vector2_from(size), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawRay (b_lean_obj_arg ray, uint32_t color, lean_obj_arg world) {
    DrawRay(*lean_raylib_Ray_from(ray), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawGrid (uint32_t slices, double spacing, lean_obj_arg world) {
    DrawGrid(slices, (float)spacing);
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__LoadModel (/* const char* */lean_obj_arg fileName, lean_obj_arg world) {
//     Model result_ = LoadModel(lean_string_cstr(fileName));
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadModelFromMesh (lean_obj_arg mesh, lean_obj_arg world) {
//     Model result_ = LoadModelFromMesh(lean_raylib_Mesh_from(mesh));
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsModelReady (lean_obj_arg model, lean_obj_arg world) {
//     bool result_ = IsModelReady(lean_raylib_Model_from(model));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadModel (lean_obj_arg model, lean_obj_arg world) {
//     UnloadModel(lean_raylib_Model_from(model));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetModelBoundingBox (lean_obj_arg model, lean_obj_arg world) {
//     BoundingBox result_ = GetModelBoundingBox(lean_raylib_Model_from(model));
//     return lean_raylib_BoundingBox_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawModel (lean_obj_arg model, lean_obj_arg position, double scale, uint32_t tint, lean_obj_arg world) {
//     DrawModel(lean_raylib_Model_from(model), lean_raylib_Vector3_from(position), (float)scale, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawModelEx (lean_obj_arg model, lean_obj_arg position, lean_obj_arg rotationAxis, double rotationAngle, lean_obj_arg scale, uint32_t tint, lean_obj_arg world) {
//     DrawModelEx(lean_raylib_Model_from(model), lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(rotationAxis), (float)rotationAngle, lean_raylib_Vector3_from(scale), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawModelWires (lean_obj_arg model, lean_obj_arg position, double scale, uint32_t tint, lean_obj_arg world) {
//     DrawModelWires(lean_raylib_Model_from(model), lean_raylib_Vector3_from(position), (float)scale, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawModelWiresEx (lean_obj_arg model, lean_obj_arg position, lean_obj_arg rotationAxis, double rotationAngle, lean_obj_arg scale, uint32_t tint, lean_obj_arg world) {
//     DrawModelWiresEx(lean_raylib_Model_from(model), lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(rotationAxis), (float)rotationAngle, lean_raylib_Vector3_from(scale), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

LEAN_EXPORT lean_obj_res lean_raylib__DrawBoundingBox (b_lean_obj_arg box, uint32_t color, lean_obj_arg world) {
    DrawBoundingBox(*lean_raylib_BoundingBox_from(box), lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboard (b_lean_obj_arg camera, b_lean_obj_arg textureRef, b_lean_obj_arg position, double size, uint32_t tint, lean_obj_arg world) {
    DrawBillboard(*lean_raylib_Camera3D_from(camera), lean_raylib_TextureRef_from(textureRef)->texture, lean_raylib_Vector3_from(position), (float)size, lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboardRec (b_lean_obj_arg camera, b_lean_obj_arg textureRef, b_lean_obj_arg source, b_lean_obj_arg position, b_lean_obj_arg size, uint32_t tint, lean_obj_arg world) {
    DrawBillboardRec(*lean_raylib_Camera3D_from(camera), lean_raylib_TextureRef_from(textureRef)->texture, *lean_raylib_Rectangle_from(source), lean_raylib_Vector3_from(position), lean_raylib_Vector2_from(size), lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboardPro (b_lean_obj_arg camera, b_lean_obj_arg textureRef, b_lean_obj_arg source, b_lean_obj_arg position, b_lean_obj_arg up, b_lean_obj_arg size, b_lean_obj_arg origin, double rotation, uint32_t tint, lean_obj_arg world) {
    DrawBillboardPro(*lean_raylib_Camera3D_from(camera), lean_raylib_TextureRef_from(textureRef)->texture, *lean_raylib_Rectangle_from(source), lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(up), lean_raylib_Vector2_from(size), lean_raylib_Vector2_from(origin), (float)rotation, lean_raylib_Color_from(tint));
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__UploadMesh (/* Mesh* */lean_obj_arg mesh, uint8_t dynamic, lean_obj_arg world) {
//     UploadMesh(/*todo: ptr?*/mesh, dynamic);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateMeshBuffer (lean_obj_arg mesh, uint32_t index, /* const void* */lean_obj_arg data, uint32_t dataSize, uint32_t offset, lean_obj_arg world) {
//     UpdateMeshBuffer(lean_raylib_Mesh_from(mesh), index, /*todo: ptr?*/data, dataSize, offset);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadMesh (lean_obj_arg mesh, lean_obj_arg world) {
//     UnloadMesh(lean_raylib_Mesh_from(mesh));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawMesh (lean_obj_arg mesh, lean_obj_arg material, lean_obj_arg transform, lean_obj_arg world) {
//     DrawMesh(lean_raylib_Mesh_from(mesh), lean_raylib_Material_from(material), lean_raylib_Matrix_from(transform));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawMeshInstanced (lean_obj_arg mesh, lean_obj_arg material, /* const Matrix* */lean_obj_arg transforms, uint32_t instances, lean_obj_arg world) {
//     DrawMeshInstanced(lean_raylib_Mesh_from(mesh), lean_raylib_Material_from(material), /*todo: ptr?*/transforms, instances);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportMesh (lean_obj_arg mesh, /* const char* */lean_obj_arg fileName, lean_obj_arg world) {
//     bool result_ = ExportMesh(lean_raylib_Mesh_from(mesh), lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetMeshBoundingBox (lean_obj_arg mesh, lean_obj_arg world) {
//     BoundingBox result_ = GetMeshBoundingBox(lean_raylib_Mesh_from(mesh));
//     return lean_raylib_BoundingBox_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshTangents (/* Mesh* */lean_obj_arg mesh, lean_obj_arg world) {
//     GenMeshTangents(/*todo: ptr?*/mesh);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshPoly (uint32_t sides, double radius, lean_obj_arg world) {
//     Mesh result_ = GenMeshPoly(sides, (float)radius);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshPlane (double width, double length, uint32_t resX, uint32_t resZ, lean_obj_arg world) {
//     Mesh result_ = GenMeshPlane((float)width, (float)length, resX, resZ);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshCube (double width, double height, double length, lean_obj_arg world) {
//     Mesh result_ = GenMeshCube((float)width, (float)height, (float)length);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshSphere (double radius, uint32_t rings, uint32_t slices, lean_obj_arg world) {
//     Mesh result_ = GenMeshSphere((float)radius, rings, slices);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshHemiSphere (double radius, uint32_t rings, uint32_t slices, lean_obj_arg world) {
//     Mesh result_ = GenMeshHemiSphere((float)radius, rings, slices);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshCylinder (double radius, double height, uint32_t slices, lean_obj_arg world) {
//     Mesh result_ = GenMeshCylinder((float)radius, (float)height, slices);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshCone (double radius, double height, uint32_t slices, lean_obj_arg world) {
//     Mesh result_ = GenMeshCone((float)radius, (float)height, slices);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshTorus (double radius, double size, uint32_t radSeg, uint32_t sides, lean_obj_arg world) {
//     Mesh result_ = GenMeshTorus((float)radius, (float)size, radSeg, sides);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshKnot (double radius, double size, uint32_t radSeg, uint32_t sides, lean_obj_arg world) {
//     Mesh result_ = GenMeshKnot((float)radius, (float)size, radSeg, sides);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshHeightmap (lean_obj_arg heightmap, lean_obj_arg size, lean_obj_arg world) {
//     Mesh result_ = GenMeshHeightmap(lean_raylib_Image_from(heightmap), lean_raylib_Vector3_from(size));
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshCubicmap (lean_obj_arg cubicmap, lean_obj_arg cubeSize, lean_obj_arg world) {
//     Mesh result_ = GenMeshCubicmap(lean_raylib_Image_from(cubicmap), lean_raylib_Vector3_from(cubeSize));
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* Material* */lean_obj_arg lean_raylib__LoadMaterials (/* const char* */lean_obj_arg fileName, /* int* */lean_obj_arg materialCount, lean_obj_arg world) {
//     Material * result_ = LoadMaterials(lean_string_cstr(fileName), /*todo: ptr?*/materialCount);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__LoadMaterialDefault (lean_obj_arg world) {
//     Material result_ = LoadMaterialDefault();
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsMaterialReady (lean_obj_arg material, lean_obj_arg world) {
//     bool result_ = IsMaterialReady(lean_raylib_Material_from(material));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadMaterial (lean_obj_arg material, lean_obj_arg world) {
//     UnloadMaterial(lean_raylib_Material_from(material));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMaterialTexture (/* Material* */lean_obj_arg material, uint32_t mapType, lean_obj_arg texture, lean_obj_arg world) {
//     SetMaterialTexture(/*todo: ptr?*/material, mapType, /*cast Texture2D to_lean?false*/(texture));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetModelMeshMaterial (/* Model* */lean_obj_arg model, uint32_t meshId, uint32_t materialId) {
//     SetModelMeshMaterial(/*todo: ptr?*/model, meshId, materialId);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* ModelAnimation* */lean_obj_arg lean_raylib__LoadModelAnimations (/* const char* */lean_obj_arg fileName, /* unsigned int* */lean_obj_arg animCount, lean_obj_arg world) {
//     ModelAnimation * result_ = LoadModelAnimations(lean_string_cstr(fileName), /*todo: ptr?*/animCount);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateModelAnimation (lean_obj_arg model, lean_obj_arg anim, uint32_t frame, lean_obj_arg world) {
//     UpdateModelAnimation(lean_raylib_Model_from(model), lean_raylib_ModelAnimation_from(anim), frame);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadModelAnimation (lean_obj_arg anim, lean_obj_arg world) {
//     UnloadModelAnimation(lean_raylib_ModelAnimation_from(anim));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadModelAnimations (/* ModelAnimation* */lean_obj_arg animations, uint32_t count, lean_obj_arg world) {
//     UnloadModelAnimations(/*todo: ptr?*/animations, count);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsModelAnimationValid (lean_obj_arg model, lean_obj_arg anim, lean_obj_arg world) {
//     bool result_ = IsModelAnimationValid(lean_raylib_Model_from(model), lean_raylib_ModelAnimation_from(anim));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionSpheres (lean_obj_arg center1, double radius1, lean_obj_arg center2, double radius2, lean_obj_arg world) {
//     bool result_ = CheckCollisionSpheres(lean_raylib_Vector3_from(center1), (float)radius1, lean_raylib_Vector3_from(center2), (float)radius2);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionBoxes (lean_obj_arg box1, lean_obj_arg box2, lean_obj_arg world) {
//     bool result_ = CheckCollisionBoxes(lean_raylib_BoundingBox_from(box1), lean_raylib_BoundingBox_from(box2));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionBoxSphere (lean_obj_arg box, lean_obj_arg center, double radius, lean_obj_arg world) {
//     bool result_ = CheckCollisionBoxSphere(lean_raylib_BoundingBox_from(box), lean_raylib_Vector3_from(center), (float)radius);
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionSphere (lean_obj_arg ray, lean_obj_arg center, double radius, lean_obj_arg world) {
//     RayCollision result_ = GetRayCollisionSphere(lean_raylib_Ray_from(ray), lean_raylib_Vector3_from(center), (float)radius);
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionBox (lean_obj_arg ray, lean_obj_arg box, lean_obj_arg world) {
//     RayCollision result_ = GetRayCollisionBox(lean_raylib_Ray_from(ray), lean_raylib_BoundingBox_from(box));
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionMesh (lean_obj_arg ray, lean_obj_arg mesh, lean_obj_arg transform, lean_obj_arg world) {
//     RayCollision result_ = GetRayCollisionMesh(lean_raylib_Ray_from(ray), lean_raylib_Mesh_from(mesh), lean_raylib_Matrix_from(transform));
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionTriangle (lean_obj_arg ray, lean_obj_arg p1, lean_obj_arg p2, lean_obj_arg p3, lean_obj_arg world) {
//     RayCollision result_ = GetRayCollisionTriangle(lean_raylib_Ray_from(ray), lean_raylib_Vector3_from(p1), lean_raylib_Vector3_from(p2), lean_raylib_Vector3_from(p3));
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GetRayCollisionQuad (lean_obj_arg ray, lean_obj_arg p1, lean_obj_arg p2, lean_obj_arg p3, lean_obj_arg p4, lean_obj_arg world) {
//     RayCollision result_ = GetRayCollisionQuad(lean_raylib_Ray_from(ray), lean_raylib_Vector3_from(p1), lean_raylib_Vector3_from(p2), lean_raylib_Vector3_from(p3), lean_raylib_Vector3_from(p4));
//     return lean_raylib_RayCollision_to(result_);
// }

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

LEAN_EXPORT lean_obj_res lean_raylib__SetMasterVolume (double volume, lean_obj_arg world) {
    SetMasterVolume((float)volume);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadWave (b_lean_obj_arg fileName, lean_obj_arg world) {
    LET_BOX(Wave, wave, LoadWave(lean_string_cstr(fileName)));
    return lean_io_result_mk_ok(lean_raylib_Wave_to(wave));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadWaveFromMemory (b_lean_obj_arg fileType, b_lean_obj_arg fileData, lean_obj_arg world) {
    LET_BOX(Wave, wave, LoadWaveFromMemory(lean_string_cstr(fileType), lean_sarray_cptr(fileData), lean_sarray_byte_size(fileData)));
    return lean_io_result_mk_ok(lean_raylib_Wave_to(wave));
}

LEAN_EXPORT uint8_t lean_raylib__IsWaveReady (b_lean_obj_arg wave) {
    return IsWaveReady(*lean_raylib_Wave_from(wave));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadSound (b_lean_obj_arg fileName, lean_obj_arg world) {
    LET_BOX(Sound, sound, LoadSound(lean_string_cstr(fileName)));
    return lean_io_result_mk_ok(lean_raylib_Sound_to(sound));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadSoundFromWave (b_lean_obj_arg wave, lean_obj_arg world) {
    LET_BOX(Sound, sound, LoadSoundFromWave(*lean_raylib_Wave_from(wave)));
    return lean_io_result_mk_ok(lean_raylib_Sound_to(sound));
}

LEAN_EXPORT uint8_t lean_raylib__IsSoundReady (b_lean_obj_arg sound) {
    return IsSoundReady(*lean_raylib_Sound_from(sound));
}

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateSound (lean_obj_arg sound, /* const void* */lean_obj_arg data, uint32_t sampleCount, lean_obj_arg world) {
//     UpdateSound(lean_raylib_Sound_from(sound), /*todo: ptr?*/data, sampleCount);
//     return lean_io_result_mk_ok(lean_box(0));
// }

LEAN_EXPORT lean_obj_res lean_raylib__UnloadWave (b_lean_obj_arg wave) {
    return lean_box(0);
}

LEAN_EXPORT lean_obj_res lean_raylib__UnloadSound (b_lean_obj_arg sound) {
    return lean_box(0);
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

LEAN_EXPORT lean_obj_res lean_raylib__SetSoundVolume (b_lean_obj_arg sound, double volume, lean_obj_arg world) {
    SetSoundVolume(*lean_raylib_Sound_from(sound), (float)volume);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetSoundPitch (b_lean_obj_arg sound, double pitch, lean_obj_arg world) {
    SetSoundPitch(*lean_raylib_Sound_from(sound), (float)pitch);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetSoundPan (b_lean_obj_arg sound, double pan, lean_obj_arg world) {
    SetSoundPan(*lean_raylib_Sound_from(sound), (float)pan);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__WaveCopy (b_lean_obj_arg wave_orig) {
    LET_BOX(Wave, wave, WaveCopy(*lean_raylib_Wave_from(wave_orig)));
    return lean_raylib_Wave_to(wave);
}

LEAN_EXPORT lean_obj_res lean_raylib__WaveCrop (lean_obj_arg wave, uint32_t initSample, uint32_t finalSample, lean_obj_arg world) {
    if(LEAN_LIKELY(lean_is_exclusive(wave))) {
        WaveCrop(lean_raylib_Wave_from(wave), initSample, finalSample);
        return lean_io_result_mk_ok(wave);
    }
    LET_BOX(Wave, wave_new, WaveCopy(*lean_raylib_Wave_from(wave)));
    WaveCrop(wave_new, initSample, finalSample);
    lean_dec_ref(wave);
    return lean_io_result_mk_ok(lean_raylib_Wave_to(wave_new));
}

LEAN_EXPORT lean_obj_res lean_raylib__WaveFormat (lean_obj_arg wave, uint32_t sampleRate, uint32_t sampleSize, uint32_t channels, lean_obj_arg world) {
    if(LEAN_LIKELY(lean_is_exclusive(wave))) {
        WaveFormat(lean_raylib_Wave_from(wave), sampleRate, sampleSize, channels);
        return lean_io_result_mk_ok(wave);
    }
    LET_BOX(Wave, wave_new, WaveCopy(*lean_raylib_Wave_from(wave)));
    WaveFormat(wave_new, sampleRate, sampleSize, channels);
    return lean_io_result_mk_ok(lean_raylib_Wave_to(wave_new));
}

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__LoadWaveSamples (lean_obj_arg wave, lean_obj_arg world) {
//     float * result_ = LoadWaveSamples(lean_raylib_Wave_from(wave));
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadWaveSamples (/* float* */lean_obj_arg samples, lean_obj_arg world) {
//     UnloadWaveSamples(/*todo: ptr?*/samples);
//     return lean_io_result_mk_ok(lean_box(0));
// }

LEAN_EXPORT lean_obj_res lean_raylib__LoadMusicStream (b_lean_obj_arg fileName, lean_obj_arg world) {
    LET_BOX(Music, music, LoadMusicStream(lean_string_cstr(fileName)));
    return lean_io_result_mk_ok(lean_raylib_Music_to(music));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadMusicStreamFromMemory (b_lean_obj_arg fileType, b_lean_obj_arg data, lean_obj_arg world) {
    LET_BOX(Music, music, LoadMusicStreamFromMemory(
        lean_string_cstr(fileType),
        lean_sarray_cptr(data),
        lean_sarray_size(data)
    ));
    return lean_raylib_Music_to(music);
}

LEAN_EXPORT uint8_t lean_raylib__IsMusicReady (b_lean_obj_arg music) {
    return IsMusicReady(*lean_raylib_Music_from(music));
}

LEAN_EXPORT lean_obj_res lean_raylib__UnloadMusicStream (lean_obj_arg music) {
    return lean_box(0);
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

LEAN_EXPORT lean_obj_res lean_raylib__SeekMusicStream (b_lean_obj_arg music, double position, lean_obj_arg world) {
    SeekMusicStream(*lean_raylib_Music_from(music), (float)position);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMusicVolume (b_lean_obj_arg music, double volume, lean_obj_arg world) {
    SetMusicVolume(*lean_raylib_Music_from(music), (float)volume);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMusicPitch (b_lean_obj_arg music, double pitch, lean_obj_arg world) {
    SetMusicPitch(*lean_raylib_Music_from(music), (float)pitch);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetMusicPan (b_lean_obj_arg music, double pan, lean_obj_arg world) {
    SetMusicPan(*lean_raylib_Music_from(music), (float)pan);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT double lean_raylib__GetMusicTimeLength (b_lean_obj_arg music) {
    return (float)GetMusicTimeLength(*lean_raylib_Music_from(music));
}

LEAN_EXPORT lean_obj_res lean_raylib__GetMusicTimePlayed (b_lean_obj_arg music, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box_float(
        GetMusicTimePlayed(*lean_raylib_Music_from(music))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__LoadAudioStream (uint32_t sampleRate, uint32_t sampleSize, uint32_t channels, lean_obj_arg world) {
    LET_BOX(AudioStream, stream, LoadAudioStream(sampleRate, sampleSize, channels));
    return lean_io_result_mk_ok(lean_raylib_AudioStream_to(stream));
}

LEAN_EXPORT uint8_t lean_raylib__IsAudioStreamReady (lean_obj_arg stream) {
    return IsAudioStreamReady(*lean_raylib_AudioStream_from(stream));
}

LEAN_EXPORT lean_obj_res lean_raylib__UnloadAudioStream (b_lean_obj_arg stream) {
    return lean_box(0);
}

LEAN_EXPORT lean_obj_res lean_raylib__UpdateAudioStream (b_lean_obj_arg stream, b_lean_obj_arg data, uint32_t frameCount, lean_obj_arg world) {
    UpdateAudioStream(*lean_raylib_AudioStream_from(stream), lean_sarray_cptr(data), frameCount);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsAudioStreamProcessed (b_lean_obj_arg stream, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        IsAudioStreamProcessed(*lean_raylib_AudioStream_from(stream))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__PlayAudioStream (b_lean_obj_arg stream, lean_obj_arg world) {
    PlayAudioStream(*lean_raylib_AudioStream_from(stream));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__PauseAudioStream (b_lean_obj_arg stream, lean_obj_arg world) {
    PauseAudioStream(*lean_raylib_AudioStream_from(stream));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__ResumeAudioStream (b_lean_obj_arg stream, lean_obj_arg world) {
    ResumeAudioStream(*lean_raylib_AudioStream_from(stream));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__IsAudioStreamPlaying (b_lean_obj_arg stream, lean_obj_arg world) {
    return lean_io_result_mk_ok(lean_box(
        IsAudioStreamPlaying(*lean_raylib_AudioStream_from(stream))
    ));
}

LEAN_EXPORT lean_obj_res lean_raylib__StopAudioStream (b_lean_obj_arg stream, lean_obj_arg world) {
    StopAudioStream(*lean_raylib_AudioStream_from(stream));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamVolume (b_lean_obj_arg stream, double volume, lean_obj_arg world) {
    SetAudioStreamVolume(*lean_raylib_AudioStream_from(stream), (float)volume);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamPitch (b_lean_obj_arg stream, double pitch, lean_obj_arg world) {
    SetAudioStreamPitch(*lean_raylib_AudioStream_from(stream), (float)pitch);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamPan (b_lean_obj_arg stream, double pan, lean_obj_arg world) {
    SetAudioStreamPan(*lean_raylib_AudioStream_from(stream), (float)pan);
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamBufferSizeDefault (uint32_t size, lean_obj_arg world) {
    SetAudioStreamBufferSizeDefault(size);
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamCallback (lean_obj_arg stream, lean_obj_arg callback, lean_obj_arg world) {
//     SetAudioStreamCallback(lean_raylib_AudioStream_from(stream), /*cast AudioCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__AttachAudioStreamProcessor (lean_obj_arg stream, lean_obj_arg processor, lean_obj_arg world) {
//     AttachAudioStreamProcessor(lean_raylib_AudioStream_from(stream), /*cast AudioCallback to_lean?false*/(processor));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DetachAudioStreamProcessor (lean_obj_arg stream, lean_obj_arg processor, lean_obj_arg world) {
//     DetachAudioStreamProcessor(lean_raylib_AudioStream_from(stream), /*cast AudioCallback to_lean?false*/(processor));
//     return lean_io_result_mk_ok(lean_box(0));
// }
