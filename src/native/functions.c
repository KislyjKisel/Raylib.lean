#include <string.h>
#include "util.h"
#include "structures.h"

LEAN_EXPORT lean_obj_res lean_raylib__InitWindow (uint32_t width, uint32_t height, lean_obj_arg title) {
    InitWindow(width, height, strdup(lean_string_cstr(title)));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__WindowShouldClose () {
    return lean_io_result_mk_ok(lean_box(WindowShouldClose()));
}

LEAN_EXPORT lean_obj_res lean_raylib__CloseWindow () {
    CloseWindow();
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT uint8_t lean_raylib__IsWindowReady () {
//     bool result_ = IsWindowReady();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsWindowFullscreen () {
//     bool result_ = IsWindowFullscreen();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsWindowHidden () {
//     bool result_ = IsWindowHidden();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsWindowMinimized () {
//     bool result_ = IsWindowMinimized();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsWindowMaximized () {
//     bool result_ = IsWindowMaximized();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsWindowFocused () {
//     bool result_ = IsWindowFocused();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsWindowResized () {
//     bool result_ = IsWindowResized();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsWindowState (uint32_t flag) {
//     bool result_ = IsWindowState(flag);
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetWindowState (uint32_t flags) {
//     SetWindowState(flags);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ClearWindowState (uint32_t flags) {
//     ClearWindowState(flags);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ToggleFullscreen () {
//     ToggleFullscreen();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MaximizeWindow () {
//     MaximizeWindow();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MinimizeWindow () {
//     MinimizeWindow();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__RestoreWindow () {
//     RestoreWindow();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetWindowIcon (lean_obj_arg image) {
//     SetWindowIcon(lean_raylib_Image_from(image));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetWindowTitle (/* const char* */lean_obj_arg title) {
//     SetWindowTitle(lean_string_cstr(title));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetWindowPosition (uint32_t x, uint32_t y) {
//     SetWindowPosition(x, y);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetWindowMonitor (uint32_t monitor) {
//     SetWindowMonitor(monitor);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetWindowMinSize (uint32_t width, uint32_t height) {
//     SetWindowMinSize(width, height);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetWindowSize (uint32_t width, uint32_t height) {
//     SetWindowSize(width, height);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetWindowOpacity (double opacity) {
//     SetWindowOpacity((float)opacity);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__GetWindowHandle () {
//     void * result_ = GetWindowHandle();
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetScreenWidth () {
//     int result_ = GetScreenWidth();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetScreenHeight () {
//     int result_ = GetScreenHeight();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetRenderWidth () {
//     int result_ = GetRenderWidth();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetRenderHeight () {
//     int result_ = GetRenderHeight();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetMonitorCount () {
//     int result_ = GetMonitorCount();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCurrentMonitor () {
//     int result_ = GetCurrentMonitor();
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetMonitorPosition (uint32_t monitor) {
//     Vector2 result_ = GetMonitorPosition(monitor);
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GetMonitorWidth (uint32_t monitor) {
//     int result_ = GetMonitorWidth(monitor);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetMonitorHeight (uint32_t monitor) {
//     int result_ = GetMonitorHeight(monitor);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetMonitorPhysicalWidth (uint32_t monitor) {
//     int result_ = GetMonitorPhysicalWidth(monitor);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetMonitorPhysicalHeight (uint32_t monitor) {
//     int result_ = GetMonitorPhysicalHeight(monitor);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetMonitorRefreshRate (uint32_t monitor) {
//     int result_ = GetMonitorRefreshRate(monitor);
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetWindowPosition () {
//     Vector2 result_ = GetWindowPosition();
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetWindowScaleDPI () {
//     Vector2 result_ = GetWindowScaleDPI();
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetMonitorName (uint32_t monitor) {
//     const char * result_ = GetMonitorName(monitor);
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetClipboardText (/* const char* */lean_obj_arg text) {
//     SetClipboardText(lean_string_cstr(text));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetClipboardText () {
//     const char * result_ = GetClipboardText();
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EnableEventWaiting () {
//     EnableEventWaiting();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DisableEventWaiting () {
//     DisableEventWaiting();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SwapScreenBuffer () {
//     SwapScreenBuffer();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__PollInputEvents () {
//     PollInputEvents();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__WaitTime (double seconds) {
//     WaitTime(seconds);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ShowCursor () {
//     ShowCursor();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__HideCursor () {
//     HideCursor();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsCursorHidden () {
//     bool result_ = IsCursorHidden();
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EnableCursor () {
//     EnableCursor();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DisableCursor () {
//     DisableCursor();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsCursorOnScreen () {
//     bool result_ = IsCursorOnScreen();
//     return result_;
// }

LEAN_EXPORT lean_obj_res lean_raylib__ClearBackground (uint32_t color) {
    ClearBackground(lean_raylib_Color_from(color));
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__BeginDrawing () {
    BeginDrawing();
    return lean_io_result_mk_ok(lean_box(0));
}

LEAN_EXPORT lean_obj_res lean_raylib__EndDrawing () {
    EndDrawing();
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT lean_obj_res lean_raylib__BeginMode2D (lean_obj_arg camera) {
//     BeginMode2D(lean_raylib_Camera2D_from(camera));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndMode2D () {
//     EndMode2D();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BeginMode3D (lean_obj_arg camera) {
//     BeginMode3D(lean_raylib_Camera3D_from(camera));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndMode3D () {
//     EndMode3D();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BeginTextureMode (lean_obj_arg target) {
//     BeginTextureMode(/*cast RenderTexture2D to_lean?false*/(target));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndTextureMode () {
//     EndTextureMode();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BeginShaderMode (lean_obj_arg shader) {
//     BeginShaderMode(lean_raylib_Shader_from(shader));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndShaderMode () {
//     EndShaderMode();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BeginBlendMode (uint32_t mode) {
//     BeginBlendMode(mode);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndBlendMode () {
//     EndBlendMode();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BeginScissorMode (uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
//     BeginScissorMode(x, y, width, height);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndScissorMode () {
//     EndScissorMode();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__BeginVrStereoMode (lean_obj_arg config) {
//     BeginVrStereoMode(lean_raylib_VrStereoConfig_from(config));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__EndVrStereoMode () {
//     EndVrStereoMode();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadVrStereoConfig (lean_obj_arg device) {
//     VrStereoConfig result_ = LoadVrStereoConfig(lean_raylib_VrDeviceInfo_from(device));
//     return lean_raylib_VrStereoConfig_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadVrStereoConfig (lean_obj_arg config) {
//     UnloadVrStereoConfig(lean_raylib_VrStereoConfig_from(config));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadShader (/* const char* */lean_obj_arg vsFileName, /* const char* */lean_obj_arg fsFileName) {
//     Shader result_ = LoadShader(lean_string_cstr(vsFileName), lean_string_cstr(fsFileName));
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadShaderFromMemory (/* const char* */lean_obj_arg vsCode, /* const char* */lean_obj_arg fsCode) {
//     Shader result_ = LoadShaderFromMemory(lean_string_cstr(vsCode), lean_string_cstr(fsCode));
//     return lean_raylib_Shader_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsShaderReady (lean_obj_arg shader) {
//     bool result_ = IsShaderReady(lean_raylib_Shader_from(shader));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetShaderLocation (lean_obj_arg shader, /* const char* */lean_obj_arg uniformName) {
//     int result_ = GetShaderLocation(lean_raylib_Shader_from(shader), lean_string_cstr(uniformName));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetShaderLocationAttrib (lean_obj_arg shader, /* const char* */lean_obj_arg attribName) {
//     int result_ = GetShaderLocationAttrib(lean_raylib_Shader_from(shader), lean_string_cstr(attribName));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValue (lean_obj_arg shader, uint32_t locIndex, /* const void* */lean_obj_arg value, uint32_t uniformType) {
//     SetShaderValue(lean_raylib_Shader_from(shader), locIndex, /*todo: ptr?*/value, uniformType);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueV (lean_obj_arg shader, uint32_t locIndex, /* const void* */lean_obj_arg value, uint32_t uniformType, uint32_t count) {
//     SetShaderValueV(lean_raylib_Shader_from(shader), locIndex, /*todo: ptr?*/value, uniformType, count);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueMatrix (lean_obj_arg shader, uint32_t locIndex, lean_obj_arg mat) {
//     SetShaderValueMatrix(lean_raylib_Shader_from(shader), locIndex, lean_raylib_Matrix_from(mat));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShaderValueTexture (lean_obj_arg shader, uint32_t locIndex, lean_obj_arg texture) {
//     SetShaderValueTexture(lean_raylib_Shader_from(shader), locIndex, /*cast Texture2D to_lean?false*/(texture));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadShader (lean_obj_arg shader) {
//     UnloadShader(lean_raylib_Shader_from(shader));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetMouseRay (lean_obj_arg mousePosition, lean_obj_arg camera) {
//     Ray result_ = GetMouseRay(lean_raylib_Vector2_from(mousePosition), /*cast Camera to_lean?false*/(camera));
//     return lean_raylib_Ray_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetCameraMatrix (lean_obj_arg camera) {
//     Matrix result_ = GetCameraMatrix(/*cast Camera to_lean?false*/(camera));
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetCameraMatrix2D (lean_obj_arg camera) {
//     Matrix result_ = GetCameraMatrix2D(lean_raylib_Camera2D_from(camera));
//     return lean_raylib_Matrix_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetWorldToScreen (lean_obj_arg position, lean_obj_arg camera) {
//     Vector2 result_ = GetWorldToScreen(lean_raylib_Vector3_from(position), /*cast Camera to_lean?false*/(camera));
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetScreenToWorld2D (lean_obj_arg position, lean_obj_arg camera) {
//     Vector2 result_ = GetScreenToWorld2D(lean_raylib_Vector2_from(position), lean_raylib_Camera2D_from(camera));
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetWorldToScreenEx (lean_obj_arg position, lean_obj_arg camera, uint32_t width, uint32_t height) {
//     Vector2 result_ = GetWorldToScreenEx(lean_raylib_Vector3_from(position), /*cast Camera to_lean?false*/(camera), width, height);
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetWorldToScreen2D (lean_obj_arg position, lean_obj_arg camera) {
//     Vector2 result_ = GetWorldToScreen2D(lean_raylib_Vector2_from(position), lean_raylib_Camera2D_from(camera));
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetTargetFPS (uint32_t fps) {
//     SetTargetFPS(fps);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__GetFPS () {
//     int result_ = GetFPS();
//     return result_;
// }

// LEAN_EXPORT double lean_raylib__GetFrameTime () {
//     float result_ = GetFrameTime();
//     return (float)result_;
// }

// LEAN_EXPORT double lean_raylib__GetTime () {
//     double result_ = GetTime();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetRandomValue (uint32_t min, uint32_t max) {
//     int result_ = GetRandomValue(min, max);
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetRandomSeed (uint32_t seed) {
//     SetRandomSeed(seed);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__TakeScreenshot (/* const char* */lean_obj_arg fileName) {
//     TakeScreenshot(lean_string_cstr(fileName));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetConfigFlags (uint32_t flags) {
//     SetConfigFlags(flags);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__TraceLog (uint32_t logLevel, /* const char* */lean_obj_arg text, /* variadic */ ... args) {
//     TraceLog(logLevel, lean_string_cstr(text), /*todo: variadic*/args);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetTraceLogLevel (uint32_t logLevel) {
//     SetTraceLogLevel(logLevel);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__MemAlloc (uint32_t size) {
//     void * result_ = MemAlloc(size);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* void* */lean_obj_arg lean_raylib__MemRealloc (/* void* */lean_obj_arg ptr, uint32_t size) {
//     void * result_ = MemRealloc(/*todo: ptr?*/ptr, size);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__MemFree (/* void* */lean_obj_arg ptr) {
//     MemFree(/*todo: ptr?*/ptr);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__OpenURL (/* const char* */lean_obj_arg url) {
//     OpenURL(lean_string_cstr(url));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetTraceLogCallback (lean_obj_arg callback) {
//     SetTraceLogCallback(/*cast TraceLogCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetLoadFileDataCallback (lean_obj_arg callback) {
//     SetLoadFileDataCallback(/*cast LoadFileDataCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetSaveFileDataCallback (lean_obj_arg callback) {
//     SetSaveFileDataCallback(/*cast SaveFileDataCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetLoadFileTextCallback (lean_obj_arg callback) {
//     SetLoadFileTextCallback(/*cast LoadFileTextCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetSaveFileTextCallback (lean_obj_arg callback) {
//     SetSaveFileTextCallback(/*cast SaveFileTextCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* unsigned char* */lean_obj_arg lean_raylib__LoadFileData (/* const char* */lean_obj_arg fileName, /* unsigned int* */lean_obj_arg bytesRead) {
//     unsigned char * result_ = LoadFileData(lean_string_cstr(fileName), /*todo: ptr?*/bytesRead);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadFileData (/* unsigned char* */lean_obj_arg data) {
//     UnloadFileData(/*todo: ptr?*/data);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__SaveFileData (/* const char* */lean_obj_arg fileName, /* void* */lean_obj_arg data, uint32_t bytesToWrite) {
//     bool result_ = SaveFileData(lean_string_cstr(fileName), /*todo: ptr?*/data, bytesToWrite);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportDataAsCode (/* const unsigned char* */lean_obj_arg data, uint32_t size, /* const char* */lean_obj_arg fileName) {
//     bool result_ = ExportDataAsCode(/*todo: ptr?*/data, size, lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT /* char* */lean_obj_arg lean_raylib__LoadFileText (/* const char* */lean_obj_arg fileName) {
//     char * result_ = LoadFileText(lean_string_cstr(fileName));
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadFileText (/* char* */lean_obj_arg text) {
//     UnloadFileText(/*todo: ptr?*/text);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__SaveFileText (/* const char* */lean_obj_arg fileName, /* char* */lean_obj_arg text) {
//     bool result_ = SaveFileText(lean_string_cstr(fileName), /*todo: ptr?*/text);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__FileExists (/* const char* */lean_obj_arg fileName) {
//     bool result_ = FileExists(lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__DirectoryExists (/* const char* */lean_obj_arg dirPath) {
//     bool result_ = DirectoryExists(lean_string_cstr(dirPath));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsFileExtension (/* const char* */lean_obj_arg fileName, /* const char* */lean_obj_arg ext) {
//     bool result_ = IsFileExtension(lean_string_cstr(fileName), lean_string_cstr(ext));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetFileLength (/* const char* */lean_obj_arg fileName) {
//     int result_ = GetFileLength(lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetFileExtension (/* const char* */lean_obj_arg fileName) {
//     const char * result_ = GetFileExtension(lean_string_cstr(fileName));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetFileName (/* const char* */lean_obj_arg filePath) {
//     const char * result_ = GetFileName(lean_string_cstr(filePath));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetFileNameWithoutExt (/* const char* */lean_obj_arg filePath) {
//     const char * result_ = GetFileNameWithoutExt(lean_string_cstr(filePath));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetDirectoryPath (/* const char* */lean_obj_arg filePath) {
//     const char * result_ = GetDirectoryPath(lean_string_cstr(filePath));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetPrevDirectoryPath (/* const char* */lean_obj_arg dirPath) {
//     const char * result_ = GetPrevDirectoryPath(lean_string_cstr(dirPath));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetWorkingDirectory () {
//     const char * result_ = GetWorkingDirectory();
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetApplicationDirectory () {
//     const char * result_ = GetApplicationDirectory();
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT uint8_t lean_raylib__ChangeDirectory (/* const char* */lean_obj_arg dir) {
//     bool result_ = ChangeDirectory(lean_string_cstr(dir));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsPathFile (/* const char* */lean_obj_arg path) {
//     bool result_ = IsPathFile(lean_string_cstr(path));
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadDirectoryFiles (/* const char* */lean_obj_arg dirPath) {
//     FilePathList result_ = LoadDirectoryFiles(lean_string_cstr(dirPath));
//     return lean_raylib_FilePathList_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadDirectoryFilesEx (/* const char* */lean_obj_arg basePath, /* const char* */lean_obj_arg filter, uint8_t scanSubdirs) {
//     FilePathList result_ = LoadDirectoryFilesEx(lean_string_cstr(basePath), lean_string_cstr(filter), scanSubdirs);
//     return lean_raylib_FilePathList_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadDirectoryFiles (lean_obj_arg files) {
//     UnloadDirectoryFiles(lean_raylib_FilePathList_from(files));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsFileDropped () {
//     bool result_ = IsFileDropped();
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadDroppedFiles () {
//     FilePathList result_ = LoadDroppedFiles();
//     return lean_raylib_FilePathList_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadDroppedFiles (lean_obj_arg files) {
//     UnloadDroppedFiles(lean_raylib_FilePathList_from(files));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetFileModTime (/* const char* */lean_obj_arg fileName) {
//     unknown_t result_ = GetFileModTime(lean_string_cstr(fileName));
//     return /*cast unknown_t to_lean?true*/(result_);
// }

// LEAN_EXPORT /* unsigned char* */lean_obj_arg lean_raylib__CompressData (/* const unsigned char* */lean_obj_arg data, uint32_t dataSize, /* int* */lean_obj_arg compDataSize) {
//     unsigned char * result_ = CompressData(/*todo: ptr?*/data, dataSize, /*todo: ptr?*/compDataSize);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* unsigned char* */lean_obj_arg lean_raylib__DecompressData (/* const unsigned char* */lean_obj_arg compData, uint32_t compDataSize, /* int* */lean_obj_arg dataSize) {
//     unsigned char * result_ = DecompressData(/*todo: ptr?*/compData, compDataSize, /*todo: ptr?*/dataSize);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* char* */lean_obj_arg lean_raylib__EncodeDataBase64 (/* const unsigned char* */lean_obj_arg data, uint32_t dataSize, /* int* */lean_obj_arg outputSize) {
//     char * result_ = EncodeDataBase64(/*todo: ptr?*/data, dataSize, /*todo: ptr?*/outputSize);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* unsigned char* */lean_obj_arg lean_raylib__DecodeDataBase64 (/* const unsigned char* */lean_obj_arg data, /* int* */lean_obj_arg outputSize) {
//     unsigned char * result_ = DecodeDataBase64(/*todo: ptr?*/data, /*todo: ptr?*/outputSize);
//     return /*todo: ptr?*/result_;
// }

LEAN_EXPORT lean_obj_res lean_raylib__IsKeyPressed (uint32_t key) {
    return lean_io_result_mk_ok(lean_box(IsKeyPressed(key)));
}

LEAN_EXPORT uint8_t lean_raylib__IsKeyDown (uint32_t key) {
    return lean_io_result_mk_ok(lean_box(IsKeyDown(key)));
}

LEAN_EXPORT uint8_t lean_raylib__IsKeyReleased (uint32_t key) {
    return lean_io_result_mk_ok(lean_box(IsKeyReleased(key)));
}

LEAN_EXPORT uint8_t lean_raylib__IsKeyUp (uint32_t key) {
    return lean_io_result_mk_ok(lean_box(IsKeyUp(key)));
}

LEAN_EXPORT lean_obj_res lean_raylib__SetExitKey (uint32_t key) {
    SetExitKey(key);
    return lean_io_result_mk_ok(lean_box(0));
}

// LEAN_EXPORT uint32_t lean_raylib__GetKeyPressed () {
//     int result_ = GetKeyPressed();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCharPressed () {
//     int result_ = GetCharPressed();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsGamepadAvailable (uint32_t gamepad) {
//     bool result_ = IsGamepadAvailable(gamepad);
//     return result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__GetGamepadName (uint32_t gamepad) {
//     const char * result_ = GetGamepadName(gamepad);
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsGamepadButtonPressed (uint32_t gamepad, uint32_t button) {
//     bool result_ = IsGamepadButtonPressed(gamepad, button);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsGamepadButtonDown (uint32_t gamepad, uint32_t button) {
//     bool result_ = IsGamepadButtonDown(gamepad, button);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsGamepadButtonReleased (uint32_t gamepad, uint32_t button) {
//     bool result_ = IsGamepadButtonReleased(gamepad, button);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsGamepadButtonUp (uint32_t gamepad, uint32_t button) {
//     bool result_ = IsGamepadButtonUp(gamepad, button);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetGamepadButtonPressed () {
//     int result_ = GetGamepadButtonPressed();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetGamepadAxisCount (uint32_t gamepad) {
//     int result_ = GetGamepadAxisCount(gamepad);
//     return result_;
// }

// LEAN_EXPORT double lean_raylib__GetGamepadAxisMovement (uint32_t gamepad, uint32_t axis) {
//     float result_ = GetGamepadAxisMovement(gamepad, axis);
//     return (float)result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__SetGamepadMappings (/* const char* */lean_obj_arg mappings) {
//     int result_ = SetGamepadMappings(lean_string_cstr(mappings));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsMouseButtonPressed (uint32_t button) {
//     bool result_ = IsMouseButtonPressed(button);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsMouseButtonDown (uint32_t button) {
//     bool result_ = IsMouseButtonDown(button);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsMouseButtonReleased (uint32_t button) {
//     bool result_ = IsMouseButtonReleased(button);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsMouseButtonUp (uint32_t button) {
//     bool result_ = IsMouseButtonUp(button);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetMouseX () {
//     int result_ = GetMouseX();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetMouseY () {
//     int result_ = GetMouseY();
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetMousePosition () {
//     Vector2 result_ = GetMousePosition();
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetMouseDelta () {
//     Vector2 result_ = GetMouseDelta();
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMousePosition (uint32_t x, uint32_t y) {
//     SetMousePosition(x, y);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMouseOffset (uint32_t offsetX, uint32_t offsetY) {
//     SetMouseOffset(offsetX, offsetY);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMouseScale (double scaleX, double scaleY) {
//     SetMouseScale((float)scaleX, (float)scaleY);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT double lean_raylib__GetMouseWheelMove () {
//     float result_ = GetMouseWheelMove();
//     return (float)result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetMouseWheelMoveV () {
//     Vector2 result_ = GetMouseWheelMoveV();
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMouseCursor (uint32_t cursor) {
//     SetMouseCursor(cursor);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__GetTouchX () {
//     int result_ = GetTouchX();
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetTouchY () {
//     int result_ = GetTouchY();
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetTouchPosition (uint32_t index) {
//     Vector2 result_ = GetTouchPosition(index);
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GetTouchPointId (uint32_t index) {
//     int result_ = GetTouchPointId(index);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetTouchPointCount () {
//     int result_ = GetTouchPointCount();
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetGesturesEnabled (uint32_t flags) {
//     SetGesturesEnabled(flags);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsGestureDetected (uint32_t gesture) {
//     bool result_ = IsGestureDetected(gesture);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetGestureDetected () {
//     int result_ = GetGestureDetected();
//     return result_;
// }

// LEAN_EXPORT double lean_raylib__GetGestureHoldDuration () {
//     float result_ = GetGestureHoldDuration();
//     return (float)result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetGestureDragVector () {
//     Vector2 result_ = GetGestureDragVector();
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT double lean_raylib__GetGestureDragAngle () {
//     float result_ = GetGestureDragAngle();
//     return (float)result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetGesturePinchVector () {
//     Vector2 result_ = GetGesturePinchVector();
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT double lean_raylib__GetGesturePinchAngle () {
//     float result_ = GetGesturePinchAngle();
//     return (float)result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetCameraMode (lean_obj_arg camera, uint32_t mode) {
//     SetCameraMode(/*cast Camera to_lean?false*/(camera), mode);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateCamera (/* Camera* */lean_obj_arg camera) {
//     UpdateCamera(/*todo: ptr?*/camera);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetCameraPanControl (uint32_t keyPan) {
//     SetCameraPanControl(keyPan);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetCameraAltControl (uint32_t keyAlt) {
//     SetCameraAltControl(keyAlt);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetCameraSmoothZoomControl (uint32_t keySmoothZoom) {
//     SetCameraSmoothZoomControl(keySmoothZoom);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetCameraMoveControls (uint32_t keyFront, uint32_t keyBack, uint32_t keyRight, uint32_t keyLeft, uint32_t keyUp, uint32_t keyDown) {
//     SetCameraMoveControls(keyFront, keyBack, keyRight, keyLeft, keyUp, keyDown);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetShapesTexture (lean_obj_arg texture, lean_obj_arg source) {
//     SetShapesTexture(/*cast Texture2D to_lean?false*/(texture), lean_raylib_Rectangle_from(source));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPixel (uint32_t posX, uint32_t posY, uint32_t color) {
//     DrawPixel(posX, posY, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPixelV (lean_obj_arg position, uint32_t color) {
//     DrawPixelV(lean_raylib_Vector2_from(position), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLine (uint32_t startPosX, uint32_t startPosY, uint32_t endPosX, uint32_t endPosY, uint32_t color) {
//     DrawLine(startPosX, startPosY, endPosX, endPosY, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLineV (lean_obj_arg startPos, lean_obj_arg endPos, uint32_t color) {
//     DrawLineV(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLineEx (lean_obj_arg startPos, lean_obj_arg endPos, double thick, uint32_t color) {
//     DrawLineEx(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), (float)thick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezier (lean_obj_arg startPos, lean_obj_arg endPos, double thick, uint32_t color) {
//     DrawLineBezier(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), (float)thick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezierQuad (lean_obj_arg startPos, lean_obj_arg endPos, lean_obj_arg controlPos, double thick, uint32_t color) {
//     DrawLineBezierQuad(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_raylib_Vector2_from(controlPos), (float)thick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLineBezierCubic (lean_obj_arg startPos, lean_obj_arg endPos, lean_obj_arg startControlPos, lean_obj_arg endControlPos, double thick, uint32_t color) {
//     DrawLineBezierCubic(lean_raylib_Vector2_from(startPos), lean_raylib_Vector2_from(endPos), lean_raylib_Vector2_from(startControlPos), lean_raylib_Vector2_from(endControlPos), (float)thick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLineStrip (/* Vector2* */lean_obj_arg points, uint32_t pointCount, uint32_t color) {
//     DrawLineStrip(/*todo: ptr?*/points, pointCount, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCircle (uint32_t centerX, uint32_t centerY, double radius, uint32_t color) {
//     DrawCircle(centerX, centerY, (float)radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleSector (lean_obj_arg center, double radius, double startAngle, double endAngle, uint32_t segments, uint32_t color) {
//     DrawCircleSector(lean_raylib_Vector2_from(center), (float)radius, (float)startAngle, (float)endAngle, segments, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleSectorLines (lean_obj_arg center, double radius, double startAngle, double endAngle, uint32_t segments, uint32_t color) {
//     DrawCircleSectorLines(lean_raylib_Vector2_from(center), (float)radius, (float)startAngle, (float)endAngle, segments, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleGradient (uint32_t centerX, uint32_t centerY, double radius, uint32_t color1, uint32_t color2) {
//     DrawCircleGradient(centerX, centerY, (float)radius, lean_raylib_Color_from(color1), lean_raylib_Color_from(color2));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleV (lean_obj_arg center, double radius, uint32_t color) {
//     DrawCircleV(lean_raylib_Vector2_from(center), (float)radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCircleLines (uint32_t centerX, uint32_t centerY, double radius, uint32_t color) {
//     DrawCircleLines(centerX, centerY, (float)radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawEllipse (uint32_t centerX, uint32_t centerY, double radiusH, double radiusV, uint32_t color) {
//     DrawEllipse(centerX, centerY, (float)radiusH, (float)radiusV, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawEllipseLines (uint32_t centerX, uint32_t centerY, double radiusH, double radiusV, uint32_t color) {
//     DrawEllipseLines(centerX, centerY, (float)radiusH, (float)radiusV, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRing (lean_obj_arg center, double innerRadius, double outerRadius, double startAngle, double endAngle, uint32_t segments, uint32_t color) {
//     DrawRing(lean_raylib_Vector2_from(center), (float)innerRadius, (float)outerRadius, (float)startAngle, (float)endAngle, segments, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRingLines (lean_obj_arg center, double innerRadius, double outerRadius, double startAngle, double endAngle, uint32_t segments, uint32_t color) {
//     DrawRingLines(lean_raylib_Vector2_from(center), (float)innerRadius, (float)outerRadius, (float)startAngle, (float)endAngle, segments, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangle (uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t color) {
//     DrawRectangle(posX, posY, width, height, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleV (lean_obj_arg position, lean_obj_arg size, uint32_t color) {
//     DrawRectangleV(lean_raylib_Vector2_from(position), lean_raylib_Vector2_from(size), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleRec (lean_obj_arg rec, uint32_t color) {
//     DrawRectangleRec(lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectanglePro (lean_obj_arg rec, lean_obj_arg origin, double rotation, uint32_t color) {
//     DrawRectanglePro(lean_raylib_Rectangle_from(rec), lean_raylib_Vector2_from(origin), (float)rotation, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleGradientV (uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t color1, uint32_t color2) {
//     DrawRectangleGradientV(posX, posY, width, height, lean_raylib_Color_from(color1), lean_raylib_Color_from(color2));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleGradientH (uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t color1, uint32_t color2) {
//     DrawRectangleGradientH(posX, posY, width, height, lean_raylib_Color_from(color1), lean_raylib_Color_from(color2));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleGradientEx (lean_obj_arg rec, uint32_t col1, uint32_t col2, uint32_t col3, uint32_t col4) {
//     DrawRectangleGradientEx(lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(col1), lean_raylib_Color_from(col2), lean_raylib_Color_from(col3), lean_raylib_Color_from(col4));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleLines (uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t color) {
//     DrawRectangleLines(posX, posY, width, height, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleLinesEx (lean_obj_arg rec, double lineThick, uint32_t color) {
//     DrawRectangleLinesEx(lean_raylib_Rectangle_from(rec), (float)lineThick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleRounded (lean_obj_arg rec, double roundness, uint32_t segments, uint32_t color) {
//     DrawRectangleRounded(lean_raylib_Rectangle_from(rec), (float)roundness, segments, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRectangleRoundedLines (lean_obj_arg rec, double roundness, uint32_t segments, double lineThick, uint32_t color) {
//     DrawRectangleRoundedLines(lean_raylib_Rectangle_from(rec), (float)roundness, segments, (float)lineThick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangle (lean_obj_arg v1, lean_obj_arg v2, lean_obj_arg v3, uint32_t color) {
//     DrawTriangle(lean_raylib_Vector2_from(v1), lean_raylib_Vector2_from(v2), lean_raylib_Vector2_from(v3), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleLines (lean_obj_arg v1, lean_obj_arg v2, lean_obj_arg v3, uint32_t color) {
//     DrawTriangleLines(lean_raylib_Vector2_from(v1), lean_raylib_Vector2_from(v2), lean_raylib_Vector2_from(v3), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleFan (/* Vector2* */lean_obj_arg points, uint32_t pointCount, uint32_t color) {
//     DrawTriangleFan(/*todo: ptr?*/points, pointCount, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleStrip (/* Vector2* */lean_obj_arg points, uint32_t pointCount, uint32_t color) {
//     DrawTriangleStrip(/*todo: ptr?*/points, pointCount, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPoly (lean_obj_arg center, uint32_t sides, double radius, double rotation, uint32_t color) {
//     DrawPoly(lean_raylib_Vector2_from(center), sides, (float)radius, (float)rotation, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPolyLines (lean_obj_arg center, uint32_t sides, double radius, double rotation, uint32_t color) {
//     DrawPolyLines(lean_raylib_Vector2_from(center), sides, (float)radius, (float)rotation, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPolyLinesEx (lean_obj_arg center, uint32_t sides, double radius, double rotation, double lineThick, uint32_t color) {
//     DrawPolyLinesEx(lean_raylib_Vector2_from(center), sides, (float)radius, (float)rotation, (float)lineThick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionRecs (lean_obj_arg rec1, lean_obj_arg rec2) {
//     bool result_ = CheckCollisionRecs(lean_raylib_Rectangle_from(rec1), lean_raylib_Rectangle_from(rec2));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionCircles (lean_obj_arg center1, double radius1, lean_obj_arg center2, double radius2) {
//     bool result_ = CheckCollisionCircles(lean_raylib_Vector2_from(center1), (float)radius1, lean_raylib_Vector2_from(center2), (float)radius2);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionCircleRec (lean_obj_arg center, double radius, lean_obj_arg rec) {
//     bool result_ = CheckCollisionCircleRec(lean_raylib_Vector2_from(center), (float)radius, lean_raylib_Rectangle_from(rec));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointRec (lean_obj_arg point, lean_obj_arg rec) {
//     bool result_ = CheckCollisionPointRec(lean_raylib_Vector2_from(point), lean_raylib_Rectangle_from(rec));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointCircle (lean_obj_arg point, lean_obj_arg center, double radius) {
//     bool result_ = CheckCollisionPointCircle(lean_raylib_Vector2_from(point), lean_raylib_Vector2_from(center), (float)radius);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointTriangle (lean_obj_arg point, lean_obj_arg p1, lean_obj_arg p2, lean_obj_arg p3) {
//     bool result_ = CheckCollisionPointTriangle(lean_raylib_Vector2_from(point), lean_raylib_Vector2_from(p1), lean_raylib_Vector2_from(p2), lean_raylib_Vector2_from(p3));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointPoly (lean_obj_arg point, /* Vector2* */lean_obj_arg points, uint32_t pointCount) {
//     bool result_ = CheckCollisionPointPoly(lean_raylib_Vector2_from(point), /*todo: ptr?*/points, pointCount);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionLines (lean_obj_arg startPos1, lean_obj_arg endPos1, lean_obj_arg startPos2, lean_obj_arg endPos2, /* Vector2* */lean_obj_arg collisionPoint) {
//     bool result_ = CheckCollisionLines(lean_raylib_Vector2_from(startPos1), lean_raylib_Vector2_from(endPos1), lean_raylib_Vector2_from(startPos2), lean_raylib_Vector2_from(endPos2), /*todo: ptr?*/collisionPoint);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionPointLine (lean_obj_arg point, lean_obj_arg p1, lean_obj_arg p2, uint32_t threshold) {
//     bool result_ = CheckCollisionPointLine(lean_raylib_Vector2_from(point), lean_raylib_Vector2_from(p1), lean_raylib_Vector2_from(p2), threshold);
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetCollisionRec (lean_obj_arg rec1, lean_obj_arg rec2) {
//     Rectangle result_ = GetCollisionRec(lean_raylib_Rectangle_from(rec1), lean_raylib_Rectangle_from(rec2));
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadImage (/* const char* */lean_obj_arg fileName) {
//     Image result_ = LoadImage(lean_string_cstr(fileName));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadImageRaw (/* const char* */lean_obj_arg fileName, uint32_t width, uint32_t height, uint32_t format, uint32_t headerSize) {
//     Image result_ = LoadImageRaw(lean_string_cstr(fileName), width, height, format, headerSize);
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadImageAnim (/* const char* */lean_obj_arg fileName, /* int* */lean_obj_arg frames) {
//     Image result_ = LoadImageAnim(lean_string_cstr(fileName), /*todo: ptr?*/frames);
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadImageFromMemory (/* const char* */lean_obj_arg fileType, /* const unsigned char* */lean_obj_arg fileData, uint32_t dataSize) {
//     Image result_ = LoadImageFromMemory(lean_string_cstr(fileType), /*todo: ptr?*/fileData, dataSize);
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadImageFromTexture (lean_obj_arg texture) {
//     Image result_ = LoadImageFromTexture(/*cast Texture2D to_lean?false*/(texture));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadImageFromScreen () {
//     Image result_ = LoadImageFromScreen();
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsImageReady (lean_obj_arg image) {
//     bool result_ = IsImageReady(lean_raylib_Image_from(image));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadImage (lean_obj_arg image) {
//     UnloadImage(lean_raylib_Image_from(image));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportImage (lean_obj_arg image, /* const char* */lean_obj_arg fileName) {
//     bool result_ = ExportImage(lean_raylib_Image_from(image), lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportImageAsCode (lean_obj_arg image, /* const char* */lean_obj_arg fileName) {
//     bool result_ = ExportImageAsCode(lean_raylib_Image_from(image), lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageColor (uint32_t width, uint32_t height, uint32_t color) {
//     Image result_ = GenImageColor(width, height, lean_raylib_Color_from(color));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageGradientV (uint32_t width, uint32_t height, uint32_t top, uint32_t bottom) {
//     Image result_ = GenImageGradientV(width, height, lean_raylib_Color_from(top), lean_raylib_Color_from(bottom));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageGradientH (uint32_t width, uint32_t height, uint32_t left, uint32_t right) {
//     Image result_ = GenImageGradientH(width, height, lean_raylib_Color_from(left), lean_raylib_Color_from(right));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageGradientRadial (uint32_t width, uint32_t height, double density, uint32_t inner, uint32_t outer) {
//     Image result_ = GenImageGradientRadial(width, height, (float)density, lean_raylib_Color_from(inner), lean_raylib_Color_from(outer));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageChecked (uint32_t width, uint32_t height, uint32_t checksX, uint32_t checksY, uint32_t col1, uint32_t col2) {
//     Image result_ = GenImageChecked(width, height, checksX, checksY, lean_raylib_Color_from(col1), lean_raylib_Color_from(col2));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageWhiteNoise (uint32_t width, uint32_t height, double factor) {
//     Image result_ = GenImageWhiteNoise(width, height, (float)factor);
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImagePerlinNoise (uint32_t width, uint32_t height, uint32_t offsetX, uint32_t offsetY, double scale) {
//     Image result_ = GenImagePerlinNoise(width, height, offsetX, offsetY, (float)scale);
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageCellular (uint32_t width, uint32_t height, uint32_t tileSize) {
//     Image result_ = GenImageCellular(width, height, tileSize);
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageText (uint32_t width, uint32_t height, /* const char* */lean_obj_arg text) {
//     Image result_ = GenImageText(width, height, lean_string_cstr(text));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__ImageCopy (lean_obj_arg image) {
//     Image result_ = ImageCopy(lean_raylib_Image_from(image));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__ImageFromImage (lean_obj_arg image, lean_obj_arg rec) {
//     Image result_ = ImageFromImage(lean_raylib_Image_from(image), lean_raylib_Rectangle_from(rec));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__ImageText (/* const char* */lean_obj_arg text, uint32_t fontSize, uint32_t color) {
//     Image result_ = ImageText(lean_string_cstr(text), fontSize, lean_raylib_Color_from(color));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__ImageTextEx (lean_obj_arg font, /* const char* */lean_obj_arg text, double fontSize, double spacing, uint32_t tint) {
//     Image result_ = ImageTextEx(lean_raylib_Font_from(font), lean_string_cstr(text), (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageFormat (/* Image* */lean_obj_arg image, uint32_t newFormat) {
//     ImageFormat(/*todo: ptr?*/image, newFormat);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageToPOT (/* Image* */lean_obj_arg image, uint32_t fill) {
//     ImageToPOT(/*todo: ptr?*/image, lean_raylib_Color_from(fill));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageCrop (/* Image* */lean_obj_arg image, lean_obj_arg crop) {
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

// LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaMask (/* Image* */lean_obj_arg image, lean_obj_arg alphaMask) {
//     ImageAlphaMask(/*todo: ptr?*/image, lean_raylib_Image_from(alphaMask));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageAlphaPremultiply (/* Image* */lean_obj_arg image) {
//     ImageAlphaPremultiply(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageBlurGaussian (/* Image* */lean_obj_arg image, uint32_t blurSize) {
//     ImageBlurGaussian(/*todo: ptr?*/image, blurSize);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageResize (/* Image* */lean_obj_arg image, uint32_t newWidth, uint32_t newHeight) {
//     ImageResize(/*todo: ptr?*/image, newWidth, newHeight);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageResizeNN (/* Image* */lean_obj_arg image, uint32_t newWidth, uint32_t newHeight) {
//     ImageResizeNN(/*todo: ptr?*/image, newWidth, newHeight);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageResizeCanvas (/* Image* */lean_obj_arg image, uint32_t newWidth, uint32_t newHeight, uint32_t offsetX, uint32_t offsetY, uint32_t fill) {
//     ImageResizeCanvas(/*todo: ptr?*/image, newWidth, newHeight, offsetX, offsetY, lean_raylib_Color_from(fill));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageMipmaps (/* Image* */lean_obj_arg image) {
//     ImageMipmaps(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDither (/* Image* */lean_obj_arg image, uint32_t rBpp, uint32_t gBpp, uint32_t bBpp, uint32_t aBpp) {
//     ImageDither(/*todo: ptr?*/image, rBpp, gBpp, bBpp, aBpp);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageFlipVertical (/* Image* */lean_obj_arg image) {
//     ImageFlipVertical(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageFlipHorizontal (/* Image* */lean_obj_arg image) {
//     ImageFlipHorizontal(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageRotateCW (/* Image* */lean_obj_arg image) {
//     ImageRotateCW(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageRotateCCW (/* Image* */lean_obj_arg image) {
//     ImageRotateCCW(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorTint (/* Image* */lean_obj_arg image, uint32_t color) {
//     ImageColorTint(/*todo: ptr?*/image, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorInvert (/* Image* */lean_obj_arg image) {
//     ImageColorInvert(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorGrayscale (/* Image* */lean_obj_arg image) {
//     ImageColorGrayscale(/*todo: ptr?*/image);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorContrast (/* Image* */lean_obj_arg image, double contrast) {
//     ImageColorContrast(/*todo: ptr?*/image, (float)contrast);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorBrightness (/* Image* */lean_obj_arg image, uint32_t brightness) {
//     ImageColorBrightness(/*todo: ptr?*/image, brightness);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageColorReplace (/* Image* */lean_obj_arg image, uint32_t color, uint32_t replace) {
//     ImageColorReplace(/*todo: ptr?*/image, lean_raylib_Color_from(color), lean_raylib_Color_from(replace));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* Color* */lean_obj_arg lean_raylib__LoadImageColors (lean_obj_arg image) {
//     Color * result_ = LoadImageColors(lean_raylib_Image_from(image));
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* Color* */lean_obj_arg lean_raylib__LoadImagePalette (lean_obj_arg image, uint32_t maxPaletteSize, /* int* */lean_obj_arg colorCount) {
//     Color * result_ = LoadImagePalette(lean_raylib_Image_from(image), maxPaletteSize, /*todo: ptr?*/colorCount);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadImageColors (/* Color* */lean_obj_arg colors) {
//     UnloadImageColors(/*todo: ptr?*/colors);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadImagePalette (/* Color* */lean_obj_arg colors) {
//     UnloadImagePalette(/*todo: ptr?*/colors);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetImageAlphaBorder (lean_obj_arg image, double threshold) {
//     Rectangle result_ = GetImageAlphaBorder(lean_raylib_Image_from(image), (float)threshold);
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GetImageColor (lean_obj_arg image, uint32_t x, uint32_t y) {
//     Color result_ = GetImageColor(lean_raylib_Image_from(image), x, y);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageClearBackground (/* Image* */lean_obj_arg dst, uint32_t color) {
//     ImageClearBackground(/*todo: ptr?*/dst, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawPixel (/* Image* */lean_obj_arg dst, uint32_t posX, uint32_t posY, uint32_t color) {
//     ImageDrawPixel(/*todo: ptr?*/dst, posX, posY, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawPixelV (/* Image* */lean_obj_arg dst, lean_obj_arg position, uint32_t color) {
//     ImageDrawPixelV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(position), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawLine (/* Image* */lean_obj_arg dst, uint32_t startPosX, uint32_t startPosY, uint32_t endPosX, uint32_t endPosY, uint32_t color) {
//     ImageDrawLine(/*todo: ptr?*/dst, startPosX, startPosY, endPosX, endPosY, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawLineV (/* Image* */lean_obj_arg dst, lean_obj_arg start, lean_obj_arg end, uint32_t color) {
//     ImageDrawLineV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(start), lean_raylib_Vector2_from(end), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircle (/* Image* */lean_obj_arg dst, uint32_t centerX, uint32_t centerY, uint32_t radius, uint32_t color) {
//     ImageDrawCircle(/*todo: ptr?*/dst, centerX, centerY, radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleV (/* Image* */lean_obj_arg dst, lean_obj_arg center, uint32_t radius, uint32_t color) {
//     ImageDrawCircleV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(center), radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleLines (/* Image* */lean_obj_arg dst, uint32_t centerX, uint32_t centerY, uint32_t radius, uint32_t color) {
//     ImageDrawCircleLines(/*todo: ptr?*/dst, centerX, centerY, radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawCircleLinesV (/* Image* */lean_obj_arg dst, lean_obj_arg center, uint32_t radius, uint32_t color) {
//     ImageDrawCircleLinesV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(center), radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangle (/* Image* */lean_obj_arg dst, uint32_t posX, uint32_t posY, uint32_t width, uint32_t height, uint32_t color) {
//     ImageDrawRectangle(/*todo: ptr?*/dst, posX, posY, width, height, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleV (/* Image* */lean_obj_arg dst, lean_obj_arg position, lean_obj_arg size, uint32_t color) {
//     ImageDrawRectangleV(/*todo: ptr?*/dst, lean_raylib_Vector2_from(position), lean_raylib_Vector2_from(size), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleRec (/* Image* */lean_obj_arg dst, lean_obj_arg rec, uint32_t color) {
//     ImageDrawRectangleRec(/*todo: ptr?*/dst, lean_raylib_Rectangle_from(rec), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawRectangleLines (/* Image* */lean_obj_arg dst, lean_obj_arg rec, uint32_t thick, uint32_t color) {
//     ImageDrawRectangleLines(/*todo: ptr?*/dst, lean_raylib_Rectangle_from(rec), thick, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDraw (/* Image* */lean_obj_arg dst, lean_obj_arg src, lean_obj_arg srcRec, lean_obj_arg dstRec, uint32_t tint) {
//     ImageDraw(/*todo: ptr?*/dst, lean_raylib_Image_from(src), lean_raylib_Rectangle_from(srcRec), lean_raylib_Rectangle_from(dstRec), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawText (/* Image* */lean_obj_arg dst, /* const char* */lean_obj_arg text, uint32_t posX, uint32_t posY, uint32_t fontSize, uint32_t color) {
//     ImageDrawText(/*todo: ptr?*/dst, lean_string_cstr(text), posX, posY, fontSize, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ImageDrawTextEx (/* Image* */lean_obj_arg dst, lean_obj_arg font, /* const char* */lean_obj_arg text, lean_obj_arg position, double fontSize, double spacing, uint32_t tint) {
//     ImageDrawTextEx(/*todo: ptr?*/dst, lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadTexture (/* const char* */lean_obj_arg fileName) {
//     Texture2D result_ = LoadTexture(lean_string_cstr(fileName));
//     return /*cast Texture2D to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadTextureFromImage (lean_obj_arg image) {
//     Texture2D result_ = LoadTextureFromImage(lean_raylib_Image_from(image));
//     return /*cast Texture2D to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadTextureCubemap (lean_obj_arg image, uint32_t layout) {
//     TextureCubemap result_ = LoadTextureCubemap(lean_raylib_Image_from(image), layout);
//     return /*cast TextureCubemap to_lean?true*/(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadRenderTexture (uint32_t width, uint32_t height) {
//     RenderTexture2D result_ = LoadRenderTexture(width, height);
//     return /*cast RenderTexture2D to_lean?true*/(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsTextureReady (lean_obj_arg texture) {
//     bool result_ = IsTextureReady(/*cast Texture2D to_lean?false*/(texture));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadTexture (lean_obj_arg texture) {
//     UnloadTexture(/*cast Texture2D to_lean?false*/(texture));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsRenderTextureReady (lean_obj_arg target) {
//     bool result_ = IsRenderTextureReady(/*cast RenderTexture2D to_lean?false*/(target));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadRenderTexture (lean_obj_arg target) {
//     UnloadRenderTexture(/*cast RenderTexture2D to_lean?false*/(target));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateTexture (lean_obj_arg texture, /* const void* */lean_obj_arg pixels) {
//     UpdateTexture(/*cast Texture2D to_lean?false*/(texture), /*todo: ptr?*/pixels);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateTextureRec (lean_obj_arg texture, lean_obj_arg rec, /* const void* */lean_obj_arg pixels) {
//     UpdateTextureRec(/*cast Texture2D to_lean?false*/(texture), lean_raylib_Rectangle_from(rec), /*todo: ptr?*/pixels);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenTextureMipmaps (/* Texture2D* */lean_obj_arg texture) {
//     GenTextureMipmaps(/*todo: ptr?*/texture);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetTextureFilter (lean_obj_arg texture, uint32_t filter) {
//     SetTextureFilter(/*cast Texture2D to_lean?false*/(texture), filter);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetTextureWrap (lean_obj_arg texture, uint32_t wrap) {
//     SetTextureWrap(/*cast Texture2D to_lean?false*/(texture), wrap);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTexture (lean_obj_arg texture, uint32_t posX, uint32_t posY, uint32_t tint) {
//     DrawTexture(/*cast Texture2D to_lean?false*/(texture), posX, posY, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureV (lean_obj_arg texture, lean_obj_arg position, uint32_t tint) {
//     DrawTextureV(/*cast Texture2D to_lean?false*/(texture), lean_raylib_Vector2_from(position), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureEx (lean_obj_arg texture, lean_obj_arg position, double rotation, double scale, uint32_t tint) {
//     DrawTextureEx(/*cast Texture2D to_lean?false*/(texture), lean_raylib_Vector2_from(position), (float)rotation, (float)scale, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureRec (lean_obj_arg texture, lean_obj_arg source, lean_obj_arg position, uint32_t tint) {
//     DrawTextureRec(/*cast Texture2D to_lean?false*/(texture), lean_raylib_Rectangle_from(source), lean_raylib_Vector2_from(position), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTexturePro (lean_obj_arg texture, lean_obj_arg source, lean_obj_arg dest, lean_obj_arg origin, double rotation, uint32_t tint) {
//     DrawTexturePro(/*cast Texture2D to_lean?false*/(texture), lean_raylib_Rectangle_from(source), lean_raylib_Rectangle_from(dest), lean_raylib_Vector2_from(origin), (float)rotation, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextureNPatch (lean_obj_arg texture, lean_obj_arg nPatchInfo, lean_obj_arg dest, lean_obj_arg origin, double rotation, uint32_t tint) {
//     DrawTextureNPatch(/*cast Texture2D to_lean?false*/(texture), lean_raylib_NPatchInfo_from(nPatchInfo), lean_raylib_Rectangle_from(dest), lean_raylib_Vector2_from(origin), (float)rotation, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__Fade (uint32_t color, double alpha) {
//     Color result_ = Fade(lean_raylib_Color_from(color), (float)alpha);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ColorToInt (uint32_t color) {
//     int result_ = ColorToInt(lean_raylib_Color_from(color));
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__ColorNormalize (uint32_t color) {
//     Vector4 result_ = ColorNormalize(lean_raylib_Color_from(color));
//     return lean_raylib_Vector4_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ColorFromNormalized (lean_obj_arg normalized) {
//     Color result_ = ColorFromNormalized(lean_raylib_Vector4_from(normalized));
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__ColorToHSV (uint32_t color) {
//     Vector3 result_ = ColorToHSV(lean_raylib_Color_from(color));
//     return lean_raylib_Vector3_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ColorFromHSV (double hue, double saturation, double value) {
//     Color result_ = ColorFromHSV((float)hue, (float)saturation, (float)value);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ColorTint (uint32_t color, uint32_t tint) {
//     Color result_ = ColorTint(lean_raylib_Color_from(color), lean_raylib_Color_from(tint));
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ColorBrightness (uint32_t color, double factor) {
//     Color result_ = ColorBrightness(lean_raylib_Color_from(color), (float)factor);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ColorContrast (uint32_t color, double contrast) {
//     Color result_ = ColorContrast(lean_raylib_Color_from(color), (float)contrast);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ColorAlpha (uint32_t color, double alpha) {
//     Color result_ = ColorAlpha(lean_raylib_Color_from(color), (float)alpha);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__ColorAlphaBlend (uint32_t dst, uint32_t src, uint32_t tint) {
//     Color result_ = ColorAlphaBlend(lean_raylib_Color_from(dst), lean_raylib_Color_from(src), lean_raylib_Color_from(tint));
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GetColor (uint32_t hexValue) {
//     Color result_ = GetColor(hexValue);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GetPixelColor (/* void* */lean_obj_arg srcPtr, uint32_t format) {
//     Color result_ = GetPixelColor(/*todo: ptr?*/srcPtr, format);
//     return lean_raylib_Color_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetPixelColor (/* void* */lean_obj_arg dstPtr, uint32_t color, uint32_t format) {
//     SetPixelColor(/*todo: ptr?*/dstPtr, lean_raylib_Color_from(color), format);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__GetPixelDataSize (uint32_t width, uint32_t height, uint32_t format) {
//     int result_ = GetPixelDataSize(width, height, format);
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetFontDefault () {
//     Font result_ = GetFontDefault();
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadFont (/* const char* */lean_obj_arg fileName) {
//     Font result_ = LoadFont(lean_string_cstr(fileName));
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadFontEx (/* const char* */lean_obj_arg fileName, uint32_t fontSize, /* int* */lean_obj_arg fontChars, uint32_t glyphCount) {
//     Font result_ = LoadFontEx(lean_string_cstr(fileName), fontSize, /*todo: ptr?*/fontChars, glyphCount);
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadFontFromImage (lean_obj_arg image, uint32_t key, uint32_t firstChar) {
//     Font result_ = LoadFontFromImage(lean_raylib_Image_from(image), lean_raylib_Color_from(key), firstChar);
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadFontFromMemory (/* const char* */lean_obj_arg fileType, /* const unsigned char* */lean_obj_arg fileData, uint32_t dataSize, uint32_t fontSize, /* int* */lean_obj_arg fontChars, uint32_t glyphCount) {
//     Font result_ = LoadFontFromMemory(lean_string_cstr(fileType), /*todo: ptr?*/fileData, dataSize, fontSize, /*todo: ptr?*/fontChars, glyphCount);
//     return lean_raylib_Font_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsFontReady (lean_obj_arg font) {
//     bool result_ = IsFontReady(lean_raylib_Font_from(font));
//     return result_;
// }

// LEAN_EXPORT /* GlyphInfo* */lean_obj_arg lean_raylib__LoadFontData (/* const unsigned char* */lean_obj_arg fileData, uint32_t dataSize, uint32_t fontSize, /* int* */lean_obj_arg fontChars, uint32_t glyphCount, uint32_t type) {
//     GlyphInfo * result_ = LoadFontData(/*todo: ptr?*/fileData, dataSize, fontSize, /*todo: ptr?*/fontChars, glyphCount, type);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenImageFontAtlas (/* const GlyphInfo* */lean_obj_arg chars, /* Rectangle ** */lean_obj_arg recs, uint32_t glyphCount, uint32_t fontSize, uint32_t padding, uint32_t packMethod) {
//     Image result_ = GenImageFontAtlas(/*todo: ptr?*/chars, /*todo: ptr?*/recs, glyphCount, fontSize, padding, packMethod);
//     return lean_raylib_Image_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadFontData (/* GlyphInfo* */lean_obj_arg chars, uint32_t glyphCount) {
//     UnloadFontData(/*todo: ptr?*/chars, glyphCount);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadFont (lean_obj_arg font) {
//     UnloadFont(lean_raylib_Font_from(font));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportFontAsCode (lean_obj_arg font, /* const char* */lean_obj_arg fileName) {
//     bool result_ = ExportFontAsCode(lean_raylib_Font_from(font), lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawFPS (uint32_t posX, uint32_t posY) {
//     DrawFPS(posX, posY);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawText (/* const char* */lean_obj_arg text, uint32_t posX, uint32_t posY, uint32_t fontSize, uint32_t color) {
//     DrawText(lean_string_cstr(text), posX, posY, fontSize, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextEx (lean_obj_arg font, /* const char* */lean_obj_arg text, lean_obj_arg position, double fontSize, double spacing, uint32_t tint) {
//     DrawTextEx(lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextPro (lean_obj_arg font, /* const char* */lean_obj_arg text, lean_obj_arg position, lean_obj_arg origin, double rotation, double fontSize, double spacing, uint32_t tint) {
//     DrawTextPro(lean_raylib_Font_from(font), lean_string_cstr(text), lean_raylib_Vector2_from(position), lean_raylib_Vector2_from(origin), (float)rotation, (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextCodepoint (lean_obj_arg font, uint32_t codepoint, lean_obj_arg position, double fontSize, uint32_t tint) {
//     DrawTextCodepoint(lean_raylib_Font_from(font), codepoint, lean_raylib_Vector2_from(position), (float)fontSize, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTextCodepoints (lean_obj_arg font, /* const int* */lean_obj_arg codepoints, uint32_t count, lean_obj_arg position, double fontSize, double spacing, uint32_t tint) {
//     DrawTextCodepoints(lean_raylib_Font_from(font), /*todo: ptr?*/codepoints, count, lean_raylib_Vector2_from(position), (float)fontSize, (float)spacing, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__MeasureText (/* const char* */lean_obj_arg text, uint32_t fontSize) {
//     int result_ = MeasureText(lean_string_cstr(text), fontSize);
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__MeasureTextEx (lean_obj_arg font, /* const char* */lean_obj_arg text, double fontSize, double spacing) {
//     Vector2 result_ = MeasureTextEx(lean_raylib_Font_from(font), lean_string_cstr(text), (float)fontSize, (float)spacing);
//     return lean_raylib_Vector2_to(result_);
// }

// LEAN_EXPORT uint32_t lean_raylib__GetGlyphIndex (lean_obj_arg font, uint32_t codepoint) {
//     int result_ = GetGlyphIndex(lean_raylib_Font_from(font), codepoint);
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetGlyphInfo (lean_obj_arg font, uint32_t codepoint) {
//     GlyphInfo result_ = GetGlyphInfo(lean_raylib_Font_from(font), codepoint);
//     return lean_raylib_GlyphInfo_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetGlyphAtlasRec (lean_obj_arg font, uint32_t codepoint) {
//     Rectangle result_ = GetGlyphAtlasRec(lean_raylib_Font_from(font), codepoint);
//     return lean_raylib_Rectangle_to(result_);
// }

// LEAN_EXPORT /* char* */lean_obj_arg lean_raylib__LoadUTF8 (/* const int* */lean_obj_arg codepoints, uint32_t length) {
//     char * result_ = LoadUTF8(/*todo: ptr?*/codepoints, length);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadUTF8 (/* char* */lean_obj_arg text) {
//     UnloadUTF8(/*todo: ptr?*/text);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* int* */lean_obj_arg lean_raylib__LoadCodepoints (/* const char* */lean_obj_arg text, /* int* */lean_obj_arg count) {
//     int * result_ = LoadCodepoints(lean_string_cstr(text), /*todo: ptr?*/count);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadCodepoints (/* int* */lean_obj_arg codepoints) {
//     UnloadCodepoints(/*todo: ptr?*/codepoints);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCodepointCount (/* const char* */lean_obj_arg text) {
//     int result_ = GetCodepointCount(lean_string_cstr(text));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCodepoint (/* const char* */lean_obj_arg text, /* int* */lean_obj_arg codepointSize) {
//     int result_ = GetCodepoint(lean_string_cstr(text), /*todo: ptr?*/codepointSize);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCodepointNext (/* const char* */lean_obj_arg text, /* int* */lean_obj_arg codepointSize) {
//     int result_ = GetCodepointNext(lean_string_cstr(text), /*todo: ptr?*/codepointSize);
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__GetCodepointPrevious (/* const char* */lean_obj_arg text, /* int* */lean_obj_arg codepointSize) {
//     int result_ = GetCodepointPrevious(lean_string_cstr(text), /*todo: ptr?*/codepointSize);
//     return result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__CodepointToUTF8 (uint32_t codepoint, /* int* */lean_obj_arg utf8Size) {
//     const char * result_ = CodepointToUTF8(codepoint, /*todo: ptr?*/utf8Size);
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT uint32_t lean_raylib__TextCopy (/* char* */lean_obj_arg dst, /* const char* */lean_obj_arg src) {
//     int result_ = TextCopy(/*todo: ptr?*/dst, lean_string_cstr(src));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__TextIsEqual (/* const char* */lean_obj_arg text1, /* const char* */lean_obj_arg text2) {
//     bool result_ = TextIsEqual(lean_string_cstr(text1), lean_string_cstr(text2));
//     return result_;
// }

// LEAN_EXPORT uint32_t lean_raylib__TextLength (/* const char* */lean_obj_arg text) {
//     unsigned int result_ = TextLength(lean_string_cstr(text));
//     return result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextFormat (/* const char* */lean_obj_arg text, /* variadic */ ... args) {
//     const char * result_ = TextFormat(lean_string_cstr(text), /*todo: variadic*/args);
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextSubtext (/* const char* */lean_obj_arg text, uint32_t position, uint32_t length) {
//     const char * result_ = TextSubtext(lean_string_cstr(text), position, length);
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* char* */lean_obj_arg lean_raylib__TextReplace (/* char* */lean_obj_arg text, /* const char* */lean_obj_arg replace, /* const char* */lean_obj_arg by) {
//     char * result_ = TextReplace(/*todo: ptr?*/text, lean_string_cstr(replace), lean_string_cstr(by));
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* char* */lean_obj_arg lean_raylib__TextInsert (/* const char* */lean_obj_arg text, /* const char* */lean_obj_arg insert, uint32_t position) {
//     char * result_ = TextInsert(lean_string_cstr(text), lean_string_cstr(insert), position);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextJoin (/* const char ** */lean_obj_arg textList, uint32_t count, /* const char* */lean_obj_arg delimiter) {
//     const char * result_ = TextJoin(/*todo: ptr?*/textList, count, lean_string_cstr(delimiter));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char ** */lean_obj_arg lean_raylib__TextSplit (/* const char* */lean_obj_arg text, char delimiter, /* int* */lean_obj_arg count) {
//     const char * * result_ = TextSplit(lean_string_cstr(text), /*todo: char?*/delimiter, /*todo: ptr?*/count);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__TextAppend (/* char* */lean_obj_arg text, /* const char* */lean_obj_arg append, /* int* */lean_obj_arg position) {
//     TextAppend(/*todo: ptr?*/text, lean_string_cstr(append), /*todo: ptr?*/position);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__TextFindIndex (/* const char* */lean_obj_arg text, /* const char* */lean_obj_arg find) {
//     int result_ = TextFindIndex(lean_string_cstr(text), lean_string_cstr(find));
//     return result_;
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextToUpper (/* const char* */lean_obj_arg text) {
//     const char * result_ = TextToUpper(lean_string_cstr(text));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextToLower (/* const char* */lean_obj_arg text) {
//     const char * result_ = TextToLower(lean_string_cstr(text));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT /* const char* */lean_obj_arg lean_raylib__TextToPascal (/* const char* */lean_obj_arg text) {
//     const char * result_ = TextToPascal(lean_string_cstr(text));
//     return lean_mk_string_from_bytes(result_, lean_utf8_strlen(result_));
// }

// LEAN_EXPORT uint32_t lean_raylib__TextToInteger (/* const char* */lean_obj_arg text) {
//     int result_ = TextToInteger(lean_string_cstr(text));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawLine3D (lean_obj_arg startPos, lean_obj_arg endPos, uint32_t color) {
//     DrawLine3D(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPoint3D (lean_obj_arg position, uint32_t color) {
//     DrawPoint3D(lean_raylib_Vector3_from(position), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCircle3D (lean_obj_arg center, double radius, lean_obj_arg rotationAxis, double rotationAngle, uint32_t color) {
//     DrawCircle3D(lean_raylib_Vector3_from(center), (float)radius, lean_raylib_Vector3_from(rotationAxis), (float)rotationAngle, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangle3D (lean_obj_arg v1, lean_obj_arg v2, lean_obj_arg v3, uint32_t color) {
//     DrawTriangle3D(lean_raylib_Vector3_from(v1), lean_raylib_Vector3_from(v2), lean_raylib_Vector3_from(v3), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawTriangleStrip3D (/* Vector3* */lean_obj_arg points, uint32_t pointCount, uint32_t color) {
//     DrawTriangleStrip3D(/*todo: ptr?*/points, pointCount, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCube (lean_obj_arg position, double width, double height, double length, uint32_t color) {
//     DrawCube(lean_raylib_Vector3_from(position), (float)width, (float)height, (float)length, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeV (lean_obj_arg position, lean_obj_arg size, uint32_t color) {
//     DrawCubeV(lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(size), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeWires (lean_obj_arg position, double width, double height, double length, uint32_t color) {
//     DrawCubeWires(lean_raylib_Vector3_from(position), (float)width, (float)height, (float)length, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCubeWiresV (lean_obj_arg position, lean_obj_arg size, uint32_t color) {
//     DrawCubeWiresV(lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(size), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawSphere (lean_obj_arg centerPos, double radius, uint32_t color) {
//     DrawSphere(lean_raylib_Vector3_from(centerPos), (float)radius, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawSphereEx (lean_obj_arg centerPos, double radius, uint32_t rings, uint32_t slices, uint32_t color) {
//     DrawSphereEx(lean_raylib_Vector3_from(centerPos), (float)radius, rings, slices, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawSphereWires (lean_obj_arg centerPos, double radius, uint32_t rings, uint32_t slices, uint32_t color) {
//     DrawSphereWires(lean_raylib_Vector3_from(centerPos), (float)radius, rings, slices, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinder (lean_obj_arg position, double radiusTop, double radiusBottom, double height, uint32_t slices, uint32_t color) {
//     DrawCylinder(lean_raylib_Vector3_from(position), (float)radiusTop, (float)radiusBottom, (float)height, slices, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderEx (lean_obj_arg startPos, lean_obj_arg endPos, double startRadius, double endRadius, uint32_t sides, uint32_t color) {
//     DrawCylinderEx(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), (float)startRadius, (float)endRadius, sides, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderWires (lean_obj_arg position, double radiusTop, double radiusBottom, double height, uint32_t slices, uint32_t color) {
//     DrawCylinderWires(lean_raylib_Vector3_from(position), (float)radiusTop, (float)radiusBottom, (float)height, slices, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCylinderWiresEx (lean_obj_arg startPos, lean_obj_arg endPos, double startRadius, double endRadius, uint32_t sides, uint32_t color) {
//     DrawCylinderWiresEx(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), (float)startRadius, (float)endRadius, sides, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCapsule (lean_obj_arg startPos, lean_obj_arg endPos, double radius, uint32_t slices, uint32_t rings, uint32_t color) {
//     DrawCapsule(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), (float)radius, slices, rings, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawCapsuleWires (lean_obj_arg startPos, lean_obj_arg endPos, double radius, uint32_t slices, uint32_t rings, uint32_t color) {
//     DrawCapsuleWires(lean_raylib_Vector3_from(startPos), lean_raylib_Vector3_from(endPos), (float)radius, slices, rings, lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawPlane (lean_obj_arg centerPos, lean_obj_arg size, uint32_t color) {
//     DrawPlane(lean_raylib_Vector3_from(centerPos), lean_raylib_Vector2_from(size), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawRay (lean_obj_arg ray, uint32_t color) {
//     DrawRay(lean_raylib_Ray_from(ray), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawGrid (uint32_t slices, double spacing) {
//     DrawGrid(slices, (float)spacing);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadModel (/* const char* */lean_obj_arg fileName) {
//     Model result_ = LoadModel(lean_string_cstr(fileName));
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadModelFromMesh (lean_obj_arg mesh) {
//     Model result_ = LoadModelFromMesh(lean_raylib_Mesh_from(mesh));
//     return lean_raylib_Model_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsModelReady (lean_obj_arg model) {
//     bool result_ = IsModelReady(lean_raylib_Model_from(model));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadModel (lean_obj_arg model) {
//     UnloadModel(lean_raylib_Model_from(model));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadModelKeepMeshes (lean_obj_arg model) {
//     UnloadModelKeepMeshes(lean_raylib_Model_from(model));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetModelBoundingBox (lean_obj_arg model) {
//     BoundingBox result_ = GetModelBoundingBox(lean_raylib_Model_from(model));
//     return lean_raylib_BoundingBox_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawModel (lean_obj_arg model, lean_obj_arg position, double scale, uint32_t tint) {
//     DrawModel(lean_raylib_Model_from(model), lean_raylib_Vector3_from(position), (float)scale, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawModelEx (lean_obj_arg model, lean_obj_arg position, lean_obj_arg rotationAxis, double rotationAngle, lean_obj_arg scale, uint32_t tint) {
//     DrawModelEx(lean_raylib_Model_from(model), lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(rotationAxis), (float)rotationAngle, lean_raylib_Vector3_from(scale), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawModelWires (lean_obj_arg model, lean_obj_arg position, double scale, uint32_t tint) {
//     DrawModelWires(lean_raylib_Model_from(model), lean_raylib_Vector3_from(position), (float)scale, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawModelWiresEx (lean_obj_arg model, lean_obj_arg position, lean_obj_arg rotationAxis, double rotationAngle, lean_obj_arg scale, uint32_t tint) {
//     DrawModelWiresEx(lean_raylib_Model_from(model), lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(rotationAxis), (float)rotationAngle, lean_raylib_Vector3_from(scale), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawBoundingBox (lean_obj_arg box, uint32_t color) {
//     DrawBoundingBox(lean_raylib_BoundingBox_from(box), lean_raylib_Color_from(color));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboard (lean_obj_arg camera, lean_obj_arg texture, lean_obj_arg position, double size, uint32_t tint) {
//     DrawBillboard(/*cast Camera to_lean?false*/(camera), /*cast Texture2D to_lean?false*/(texture), lean_raylib_Vector3_from(position), (float)size, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboardRec (lean_obj_arg camera, lean_obj_arg texture, lean_obj_arg source, lean_obj_arg position, lean_obj_arg size, uint32_t tint) {
//     DrawBillboardRec(/*cast Camera to_lean?false*/(camera), /*cast Texture2D to_lean?false*/(texture), lean_raylib_Rectangle_from(source), lean_raylib_Vector3_from(position), lean_raylib_Vector2_from(size), lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawBillboardPro (lean_obj_arg camera, lean_obj_arg texture, lean_obj_arg source, lean_obj_arg position, lean_obj_arg up, lean_obj_arg size, lean_obj_arg origin, double rotation, uint32_t tint) {
//     DrawBillboardPro(/*cast Camera to_lean?false*/(camera), /*cast Texture2D to_lean?false*/(texture), lean_raylib_Rectangle_from(source), lean_raylib_Vector3_from(position), lean_raylib_Vector3_from(up), lean_raylib_Vector2_from(size), lean_raylib_Vector2_from(origin), (float)rotation, lean_raylib_Color_from(tint));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UploadMesh (/* Mesh* */lean_obj_arg mesh, uint8_t dynamic) {
//     UploadMesh(/*todo: ptr?*/mesh, dynamic);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateMeshBuffer (lean_obj_arg mesh, uint32_t index, /* const void* */lean_obj_arg data, uint32_t dataSize, uint32_t offset) {
//     UpdateMeshBuffer(lean_raylib_Mesh_from(mesh), index, /*todo: ptr?*/data, dataSize, offset);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadMesh (lean_obj_arg mesh) {
//     UnloadMesh(lean_raylib_Mesh_from(mesh));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawMesh (lean_obj_arg mesh, lean_obj_arg material, lean_obj_arg transform) {
//     DrawMesh(lean_raylib_Mesh_from(mesh), lean_raylib_Material_from(material), lean_raylib_Matrix_from(transform));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DrawMeshInstanced (lean_obj_arg mesh, lean_obj_arg material, /* const Matrix* */lean_obj_arg transforms, uint32_t instances) {
//     DrawMeshInstanced(lean_raylib_Mesh_from(mesh), lean_raylib_Material_from(material), /*todo: ptr?*/transforms, instances);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportMesh (lean_obj_arg mesh, /* const char* */lean_obj_arg fileName) {
//     bool result_ = ExportMesh(lean_raylib_Mesh_from(mesh), lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetMeshBoundingBox (lean_obj_arg mesh) {
//     BoundingBox result_ = GetMeshBoundingBox(lean_raylib_Mesh_from(mesh));
//     return lean_raylib_BoundingBox_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__GenMeshTangents (/* Mesh* */lean_obj_arg mesh) {
//     GenMeshTangents(/*todo: ptr?*/mesh);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshPoly (uint32_t sides, double radius) {
//     Mesh result_ = GenMeshPoly(sides, (float)radius);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshPlane (double width, double length, uint32_t resX, uint32_t resZ) {
//     Mesh result_ = GenMeshPlane((float)width, (float)length, resX, resZ);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshCube (double width, double height, double length) {
//     Mesh result_ = GenMeshCube((float)width, (float)height, (float)length);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshSphere (double radius, uint32_t rings, uint32_t slices) {
//     Mesh result_ = GenMeshSphere((float)radius, rings, slices);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshHemiSphere (double radius, uint32_t rings, uint32_t slices) {
//     Mesh result_ = GenMeshHemiSphere((float)radius, rings, slices);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshCylinder (double radius, double height, uint32_t slices) {
//     Mesh result_ = GenMeshCylinder((float)radius, (float)height, slices);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshCone (double radius, double height, uint32_t slices) {
//     Mesh result_ = GenMeshCone((float)radius, (float)height, slices);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshTorus (double radius, double size, uint32_t radSeg, uint32_t sides) {
//     Mesh result_ = GenMeshTorus((float)radius, (float)size, radSeg, sides);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshKnot (double radius, double size, uint32_t radSeg, uint32_t sides) {
//     Mesh result_ = GenMeshKnot((float)radius, (float)size, radSeg, sides);
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshHeightmap (lean_obj_arg heightmap, lean_obj_arg size) {
//     Mesh result_ = GenMeshHeightmap(lean_raylib_Image_from(heightmap), lean_raylib_Vector3_from(size));
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GenMeshCubicmap (lean_obj_arg cubicmap, lean_obj_arg cubeSize) {
//     Mesh result_ = GenMeshCubicmap(lean_raylib_Image_from(cubicmap), lean_raylib_Vector3_from(cubeSize));
//     return lean_raylib_Mesh_to(result_);
// }

// LEAN_EXPORT /* Material* */lean_obj_arg lean_raylib__LoadMaterials (/* const char* */lean_obj_arg fileName, /* int* */lean_obj_arg materialCount) {
//     Material * result_ = LoadMaterials(lean_string_cstr(fileName), /*todo: ptr?*/materialCount);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadMaterialDefault () {
//     Material result_ = LoadMaterialDefault();
//     return lean_raylib_Material_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsMaterialReady (lean_obj_arg material) {
//     bool result_ = IsMaterialReady(lean_raylib_Material_from(material));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadMaterial (lean_obj_arg material) {
//     UnloadMaterial(lean_raylib_Material_from(material));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMaterialTexture (/* Material* */lean_obj_arg material, uint32_t mapType, lean_obj_arg texture) {
//     SetMaterialTexture(/*todo: ptr?*/material, mapType, /*cast Texture2D to_lean?false*/(texture));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetModelMeshMaterial (/* Model* */lean_obj_arg model, uint32_t meshId, uint32_t materialId) {
//     SetModelMeshMaterial(/*todo: ptr?*/model, meshId, materialId);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* ModelAnimation* */lean_obj_arg lean_raylib__LoadModelAnimations (/* const char* */lean_obj_arg fileName, /* unsigned int* */lean_obj_arg animCount) {
//     ModelAnimation * result_ = LoadModelAnimations(lean_string_cstr(fileName), /*todo: ptr?*/animCount);
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateModelAnimation (lean_obj_arg model, lean_obj_arg anim, uint32_t frame) {
//     UpdateModelAnimation(lean_raylib_Model_from(model), lean_raylib_ModelAnimation_from(anim), frame);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadModelAnimation (lean_obj_arg anim) {
//     UnloadModelAnimation(lean_raylib_ModelAnimation_from(anim));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadModelAnimations (/* ModelAnimation* */lean_obj_arg animations, uint32_t count) {
//     UnloadModelAnimations(/*todo: ptr?*/animations, count);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsModelAnimationValid (lean_obj_arg model, lean_obj_arg anim) {
//     bool result_ = IsModelAnimationValid(lean_raylib_Model_from(model), lean_raylib_ModelAnimation_from(anim));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionSpheres (lean_obj_arg center1, double radius1, lean_obj_arg center2, double radius2) {
//     bool result_ = CheckCollisionSpheres(lean_raylib_Vector3_from(center1), (float)radius1, lean_raylib_Vector3_from(center2), (float)radius2);
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionBoxes (lean_obj_arg box1, lean_obj_arg box2) {
//     bool result_ = CheckCollisionBoxes(lean_raylib_BoundingBox_from(box1), lean_raylib_BoundingBox_from(box2));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__CheckCollisionBoxSphere (lean_obj_arg box, lean_obj_arg center, double radius) {
//     bool result_ = CheckCollisionBoxSphere(lean_raylib_BoundingBox_from(box), lean_raylib_Vector3_from(center), (float)radius);
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetRayCollisionSphere (lean_obj_arg ray, lean_obj_arg center, double radius) {
//     RayCollision result_ = GetRayCollisionSphere(lean_raylib_Ray_from(ray), lean_raylib_Vector3_from(center), (float)radius);
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetRayCollisionBox (lean_obj_arg ray, lean_obj_arg box) {
//     RayCollision result_ = GetRayCollisionBox(lean_raylib_Ray_from(ray), lean_raylib_BoundingBox_from(box));
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetRayCollisionMesh (lean_obj_arg ray, lean_obj_arg mesh, lean_obj_arg transform) {
//     RayCollision result_ = GetRayCollisionMesh(lean_raylib_Ray_from(ray), lean_raylib_Mesh_from(mesh), lean_raylib_Matrix_from(transform));
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetRayCollisionTriangle (lean_obj_arg ray, lean_obj_arg p1, lean_obj_arg p2, lean_obj_arg p3) {
//     RayCollision result_ = GetRayCollisionTriangle(lean_raylib_Ray_from(ray), lean_raylib_Vector3_from(p1), lean_raylib_Vector3_from(p2), lean_raylib_Vector3_from(p3));
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__GetRayCollisionQuad (lean_obj_arg ray, lean_obj_arg p1, lean_obj_arg p2, lean_obj_arg p3, lean_obj_arg p4) {
//     RayCollision result_ = GetRayCollisionQuad(lean_raylib_Ray_from(ray), lean_raylib_Vector3_from(p1), lean_raylib_Vector3_from(p2), lean_raylib_Vector3_from(p3), lean_raylib_Vector3_from(p4));
//     return lean_raylib_RayCollision_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__InitAudioDevice () {
//     InitAudioDevice();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__CloseAudioDevice () {
//     CloseAudioDevice();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsAudioDeviceReady () {
//     bool result_ = IsAudioDeviceReady();
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMasterVolume (double volume) {
//     SetMasterVolume((float)volume);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadWave (/* const char* */lean_obj_arg fileName) {
//     Wave result_ = LoadWave(lean_string_cstr(fileName));
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadWaveFromMemory (/* const char* */lean_obj_arg fileType, /* const unsigned char* */lean_obj_arg fileData, uint32_t dataSize) {
//     Wave result_ = LoadWaveFromMemory(lean_string_cstr(fileType), /*todo: ptr?*/fileData, dataSize);
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsWaveReady (lean_obj_arg wave) {
//     bool result_ = IsWaveReady(lean_raylib_Wave_from(wave));
//     return result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadSound (/* const char* */lean_obj_arg fileName) {
//     Sound result_ = LoadSound(lean_string_cstr(fileName));
//     return lean_raylib_Sound_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadSoundFromWave (lean_obj_arg wave) {
//     Sound result_ = LoadSoundFromWave(lean_raylib_Wave_from(wave));
//     return lean_raylib_Sound_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsSoundReady (lean_obj_arg sound) {
//     bool result_ = IsSoundReady(lean_raylib_Sound_from(sound));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateSound (lean_obj_arg sound, /* const void* */lean_obj_arg data, uint32_t sampleCount) {
//     UpdateSound(lean_raylib_Sound_from(sound), /*todo: ptr?*/data, sampleCount);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadWave (lean_obj_arg wave) {
//     UnloadWave(lean_raylib_Wave_from(wave));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadSound (lean_obj_arg sound) {
//     UnloadSound(lean_raylib_Sound_from(sound));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportWave (lean_obj_arg wave, /* const char* */lean_obj_arg fileName) {
//     bool result_ = ExportWave(lean_raylib_Wave_from(wave), lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__ExportWaveAsCode (lean_obj_arg wave, /* const char* */lean_obj_arg fileName) {
//     bool result_ = ExportWaveAsCode(lean_raylib_Wave_from(wave), lean_string_cstr(fileName));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__PlaySound (lean_obj_arg sound) {
//     PlaySound(lean_raylib_Sound_from(sound));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__StopSound (lean_obj_arg sound) {
//     StopSound(lean_raylib_Sound_from(sound));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__PauseSound (lean_obj_arg sound) {
//     PauseSound(lean_raylib_Sound_from(sound));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ResumeSound (lean_obj_arg sound) {
//     ResumeSound(lean_raylib_Sound_from(sound));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__PlaySoundMulti (lean_obj_arg sound) {
//     PlaySoundMulti(lean_raylib_Sound_from(sound));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__StopSoundMulti () {
//     StopSoundMulti();
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint32_t lean_raylib__GetSoundsPlaying () {
//     int result_ = GetSoundsPlaying();
//     return result_;
// }

// LEAN_EXPORT uint8_t lean_raylib__IsSoundPlaying (lean_obj_arg sound) {
//     bool result_ = IsSoundPlaying(lean_raylib_Sound_from(sound));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetSoundVolume (lean_obj_arg sound, double volume) {
//     SetSoundVolume(lean_raylib_Sound_from(sound), (float)volume);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetSoundPitch (lean_obj_arg sound, double pitch) {
//     SetSoundPitch(lean_raylib_Sound_from(sound), (float)pitch);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetSoundPan (lean_obj_arg sound, double pan) {
//     SetSoundPan(lean_raylib_Sound_from(sound), (float)pan);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__WaveCopy (lean_obj_arg wave) {
//     Wave result_ = WaveCopy(lean_raylib_Wave_from(wave));
//     return lean_raylib_Wave_to(result_);
// }

// LEAN_EXPORT lean_obj_res lean_raylib__WaveCrop (/* Wave* */lean_obj_arg wave, uint32_t initSample, uint32_t finalSample) {
//     WaveCrop(/*todo: ptr?*/wave, initSample, finalSample);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__WaveFormat (/* Wave* */lean_obj_arg wave, uint32_t sampleRate, uint32_t sampleSize, uint32_t channels) {
//     WaveFormat(/*todo: ptr?*/wave, sampleRate, sampleSize, channels);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT /* float* */lean_obj_arg lean_raylib__LoadWaveSamples (lean_obj_arg wave) {
//     float * result_ = LoadWaveSamples(lean_raylib_Wave_from(wave));
//     return /*todo: ptr?*/result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadWaveSamples (/* float* */lean_obj_arg samples) {
//     UnloadWaveSamples(/*todo: ptr?*/samples);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadMusicStream (/* const char* */lean_obj_arg fileName) {
//     Music result_ = LoadMusicStream(lean_string_cstr(fileName));
//     return lean_raylib_Music_to(result_);
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadMusicStreamFromMemory (/* const char* */lean_obj_arg fileType, /* const unsigned char* */lean_obj_arg data, uint32_t dataSize) {
//     Music result_ = LoadMusicStreamFromMemory(lean_string_cstr(fileType), /*todo: ptr?*/data, dataSize);
//     return lean_raylib_Music_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsMusicReady (lean_obj_arg music) {
//     bool result_ = IsMusicReady(lean_raylib_Music_from(music));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadMusicStream (lean_obj_arg music) {
//     UnloadMusicStream(lean_raylib_Music_from(music));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__PlayMusicStream (lean_obj_arg music) {
//     PlayMusicStream(lean_raylib_Music_from(music));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsMusicStreamPlaying (lean_obj_arg music) {
//     bool result_ = IsMusicStreamPlaying(lean_raylib_Music_from(music));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateMusicStream (lean_obj_arg music) {
//     UpdateMusicStream(lean_raylib_Music_from(music));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__StopMusicStream (lean_obj_arg music) {
//     StopMusicStream(lean_raylib_Music_from(music));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__PauseMusicStream (lean_obj_arg music) {
//     PauseMusicStream(lean_raylib_Music_from(music));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ResumeMusicStream (lean_obj_arg music) {
//     ResumeMusicStream(lean_raylib_Music_from(music));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SeekMusicStream (lean_obj_arg music, double position) {
//     SeekMusicStream(lean_raylib_Music_from(music), (float)position);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMusicVolume (lean_obj_arg music, double volume) {
//     SetMusicVolume(lean_raylib_Music_from(music), (float)volume);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMusicPitch (lean_obj_arg music, double pitch) {
//     SetMusicPitch(lean_raylib_Music_from(music), (float)pitch);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetMusicPan (lean_obj_arg music, double pan) {
//     SetMusicPan(lean_raylib_Music_from(music), (float)pan);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT double lean_raylib__GetMusicTimeLength (lean_obj_arg music) {
//     float result_ = GetMusicTimeLength(lean_raylib_Music_from(music));
//     return (float)result_;
// }

// LEAN_EXPORT double lean_raylib__GetMusicTimePlayed (lean_obj_arg music) {
//     float result_ = GetMusicTimePlayed(lean_raylib_Music_from(music));
//     return (float)result_;
// }

// LEAN_EXPORT lean_obj_arg lean_raylib__LoadAudioStream (uint32_t sampleRate, uint32_t sampleSize, uint32_t channels) {
//     AudioStream result_ = LoadAudioStream(sampleRate, sampleSize, channels);
//     return lean_raylib_AudioStream_to(result_);
// }

// LEAN_EXPORT uint8_t lean_raylib__IsAudioStreamReady (lean_obj_arg stream) {
//     bool result_ = IsAudioStreamReady(lean_raylib_AudioStream_from(stream));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UnloadAudioStream (lean_obj_arg stream) {
//     UnloadAudioStream(lean_raylib_AudioStream_from(stream));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__UpdateAudioStream (lean_obj_arg stream, /* const void* */lean_obj_arg data, uint32_t frameCount) {
//     UpdateAudioStream(lean_raylib_AudioStream_from(stream), /*todo: ptr?*/data, frameCount);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsAudioStreamProcessed (lean_obj_arg stream) {
//     bool result_ = IsAudioStreamProcessed(lean_raylib_AudioStream_from(stream));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__PlayAudioStream (lean_obj_arg stream) {
//     PlayAudioStream(lean_raylib_AudioStream_from(stream));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__PauseAudioStream (lean_obj_arg stream) {
//     PauseAudioStream(lean_raylib_AudioStream_from(stream));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__ResumeAudioStream (lean_obj_arg stream) {
//     ResumeAudioStream(lean_raylib_AudioStream_from(stream));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT uint8_t lean_raylib__IsAudioStreamPlaying (lean_obj_arg stream) {
//     bool result_ = IsAudioStreamPlaying(lean_raylib_AudioStream_from(stream));
//     return result_;
// }

// LEAN_EXPORT lean_obj_res lean_raylib__StopAudioStream (lean_obj_arg stream) {
//     StopAudioStream(lean_raylib_AudioStream_from(stream));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamVolume (lean_obj_arg stream, double volume) {
//     SetAudioStreamVolume(lean_raylib_AudioStream_from(stream), (float)volume);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamPitch (lean_obj_arg stream, double pitch) {
//     SetAudioStreamPitch(lean_raylib_AudioStream_from(stream), (float)pitch);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamPan (lean_obj_arg stream, double pan) {
//     SetAudioStreamPan(lean_raylib_AudioStream_from(stream), (float)pan);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamBufferSizeDefault (uint32_t size) {
//     SetAudioStreamBufferSizeDefault(size);
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__SetAudioStreamCallback (lean_obj_arg stream, lean_obj_arg callback) {
//     SetAudioStreamCallback(lean_raylib_AudioStream_from(stream), /*cast AudioCallback to_lean?false*/(callback));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__AttachAudioStreamProcessor (lean_obj_arg stream, lean_obj_arg processor) {
//     AttachAudioStreamProcessor(lean_raylib_AudioStream_from(stream), /*cast AudioCallback to_lean?false*/(processor));
//     return lean_io_result_mk_ok(lean_box(0));
// }

// LEAN_EXPORT lean_obj_res lean_raylib__DetachAudioStreamProcessor (lean_obj_arg stream, lean_obj_arg processor) {
//     DetachAudioStreamProcessor(lean_raylib_AudioStream_from(stream), /*cast AudioCallback to_lean?false*/(processor));
//     return lean_io_result_mk_ok(lean_box(0));
// }
