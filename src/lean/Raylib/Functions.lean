import Raylib.Util
import Raylib.Enumerations
import Raylib.Structures
import Raylib.Aliases

set_option autoImplicit false

namespace Raylib

/-- Initialize window and OpenGL context -/
@[extern "lean_raylib__InitWindow"]
opaque InitWindow (width : UInt32) (height : UInt32) (title : String) : BaseIO Unit
/-- Check if KEY_ESCAPE pressed or Close icon pressed -/
@[extern "lean_raylib__WindowShouldClose"]
opaque WindowShouldClose : BaseIO Bool
/-- Close window and unload OpenGL context -/
@[extern "lean_raylib__CloseWindow"]
opaque CloseWindow : BaseIO Unit
/-- Check if window has been initialized successfully -/
@[extern "lean_raylib__IsWindowReady"]
opaque IsWindowReady : BaseIO Bool
/-- Check if window is currently fullscreen -/
@[extern "lean_raylib__IsWindowFullscreen"]
opaque IsWindowFullscreen : BaseIO Bool
/-- Check if window is currently hidden (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__IsWindowHidden"]
opaque IsWindowHidden : BaseIO Bool
/-- Check if window is currently minimized (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__IsWindowMinimized"]
opaque IsWindowMinimized : BaseIO Bool
/-- Check if window is currently maximized (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__IsWindowMaximized"]
opaque IsWindowMaximized : BaseIO Bool
/-- Check if window is currently focused (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__IsWindowFocused"]
opaque IsWindowFocused : BaseIO Bool
/-- Check if window has been resized last frame -/
@[extern "lean_raylib__IsWindowResized"]
opaque IsWindowResized : BaseIO Bool
/-- Check if one specific window flag is enabled -/
@[extern "lean_raylib__IsWindowState"]
opaque IsWindowState (flag : ConfigFlags) : BaseIO Bool
/-- Set window configuration state using flags (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowState"]
opaque SetWindowState (flags : ConfigFlags) : BaseIO Unit
/-- Clear window configuration state flags -/
@[extern "lean_raylib__ClearWindowState"]
opaque ClearWindowState (flags : ConfigFlags) : BaseIO Unit
/-- Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__ToggleFullscreen"]
opaque ToggleFullscreen : BaseIO Unit
/-- Set window state: maximized, if resizable (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__MaximizeWindow"]
opaque MaximizeWindow : BaseIO Unit
/-- Set window state: minimized, if resizable (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__MinimizeWindow"]
opaque MinimizeWindow : BaseIO Unit
/-- Set window state: not minimized/maximized (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__RestoreWindow"]
opaque RestoreWindow : BaseIO Unit
/--
Set icon for window (only PLATFORM_DESKTOP).
Does nothing if the image's format is not `PIXELFORMAT_UNCOMPRESSED_R8G8B8A8`.
-/
@[extern "lean_raylib__SetWindowIcon"]
opaque SetWindowIcon (image : Image) : BaseIO Unit
/-- Set title for window (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowTitle"]
opaque SetWindowTitle (title : String) : BaseIO Unit
/-- Set window position on screen (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowPosition"]
opaque SetWindowPosition (x : Int32) (y : Int32) : BaseIO Unit
/-- Set monitor for the current window (fullscreen mode) -/
@[extern "lean_raylib__SetWindowMonitor"]
opaque SetWindowMonitor (monitor : Int32) : BaseIO Unit
/-- Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE) -/
@[extern "lean_raylib__SetWindowMinSize"]
opaque SetWindowMinSize (width : UInt32) (height : UInt32) : BaseIO Unit
/-- Set window dimensions -/
@[extern "lean_raylib__SetWindowSize"]
opaque SetWindowSize (width : UInt32) (height : UInt32) : BaseIO Unit
/-- Set window opacity [0.0f..1.0f] (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowOpacity"]
opaque SetWindowOpacity (opacity : Float) : BaseIO Unit
-- /-- Get native window handle -/
-- @[extern "lean_raylib__GetWindowHandle"]
-- opaque GetWindowHandle : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void *
--   params:
-- -/
/-- Get current screen width -/
@[extern "lean_raylib__GetScreenWidth"]
opaque GetScreenWidth : BaseIO UInt32
/-- Get current screen height -/
@[extern "lean_raylib__GetScreenHeight"]
opaque GetScreenHeight : BaseIO UInt32
/-- Get current render width (it considers HiDPI) -/
@[extern "lean_raylib__GetRenderWidth"]
opaque GetRenderWidth : BaseIO UInt32
/-- Get current render height (it considers HiDPI) -/
@[extern "lean_raylib__GetRenderHeight"]
opaque GetRenderHeight : BaseIO UInt32
/-- Get number of connected monitors -/
@[extern "lean_raylib__GetMonitorCount"]
opaque GetMonitorCount : BaseIO UInt32
/-- Get current connected monitor -/
@[extern "lean_raylib__GetCurrentMonitor"]
opaque GetCurrentMonitor : BaseIO UInt32
/-- Get specified monitor position -/
@[extern "lean_raylib__GetMonitorPosition"]
opaque GetMonitorPosition (monitor : UInt32) : BaseIO Vector2
/-- Get specified monitor width (current video mode used by monitor) -/
@[extern "lean_raylib__GetMonitorWidth"]
opaque GetMonitorWidth (monitor : UInt32) : BaseIO UInt32
/-- Get specified monitor height (current video mode used by monitor) -/
@[extern "lean_raylib__GetMonitorHeight"]
opaque GetMonitorHeight (monitor : UInt32) : BaseIO UInt32
/-- Get specified monitor physical width in millimetres -/
@[extern "lean_raylib__GetMonitorPhysicalWidth"]
opaque GetMonitorPhysicalWidth (monitor : UInt32) : BaseIO UInt32
/-- Get specified monitor physical height in millimetres -/
@[extern "lean_raylib__GetMonitorPhysicalHeight"]
opaque GetMonitorPhysicalHeight (monitor : UInt32) : BaseIO UInt32
/-- Get specified monitor refresh rate -/
@[extern "lean_raylib__GetMonitorRefreshRate"]
opaque GetMonitorRefreshRate (monitor : UInt32) : BaseIO UInt32
/-- Get window position XY on monitor -/
@[extern "lean_raylib__GetWindowPosition"]
opaque GetWindowPosition : BaseIO Vector2
/-- Get window scale DPI factor -/
@[extern "lean_raylib__GetWindowScaleDPI"]
opaque GetWindowScaleDPI : BaseIO Vector2
/-- Get the human-readable, UTF-8 encoded name of the primary monitor -/
@[extern "lean_raylib__GetMonitorName"]
opaque GetMonitorName (monitor : Int32) : BaseIO String
/-- Set clipboard text content -/
@[extern "lean_raylib__SetClipboardText"]
opaque SetClipboardText (text : String) : BaseIO Unit
/-- Get clipboard text content -/
@[extern "lean_raylib__GetClipboardText"]
opaque GetClipboardText : BaseIO String
/-- Enable waiting for events on EndDrawing(), no automatic event polling -/
@[extern "lean_raylib__EnableEventWaiting"]
opaque EnableEventWaiting : BaseIO Unit
/-- Disable waiting for events on EndDrawing(), automatic events polling -/
@[extern "lean_raylib__DisableEventWaiting"]
opaque DisableEventWaiting : BaseIO Unit
/-- Swap back buffer with front buffer (screen drawing) -/
@[extern "lean_raylib__SwapScreenBuffer"]
opaque SwapScreenBuffer : BaseIO Unit
/-- Register all input events -/
@[extern "lean_raylib__PollInputEvents"]
opaque PollInputEvents : BaseIO Unit
/-- Wait for some time (halt program execution) -/
@[extern "lean_raylib__WaitTime"]
opaque WaitTime (seconds : Float) : BaseIO Unit
/-- Shows cursor -/
@[extern "lean_raylib__ShowCursor"]
opaque ShowCursor : BaseIO Unit
/-- Hides cursor -/
@[extern "lean_raylib__HideCursor"]
opaque HideCursor : BaseIO Unit
/-- Check if cursor is not visible -/
@[extern "lean_raylib__IsCursorHidden"]
opaque IsCursorHidden : BaseIO Bool
/-- Enables cursor (unlock cursor) -/
@[extern "lean_raylib__EnableCursor"]
opaque EnableCursor : BaseIO Unit
/-- Disables cursor (lock cursor) -/
@[extern "lean_raylib__DisableCursor"]
opaque DisableCursor : BaseIO Unit
/-- Check if cursor is on the screen -/
@[extern "lean_raylib__IsCursorOnScreen"]
opaque IsCursorOnScreen : BaseIO Bool
/-- Set background color (framebuffer clear color) -/
@[extern "lean_raylib__ClearBackground"]
opaque ClearBackground (color : Color) : BaseIO Unit
/-- Setup canvas (framebuffer) to start drawing -/
@[extern "lean_raylib__BeginDrawing"]
opaque BeginDrawing : BaseIO Unit
/-- End canvas drawing and swap buffers (double buffering) -/
@[extern "lean_raylib__EndDrawing"]
opaque EndDrawing : BaseIO Unit
/-- Begin 2D mode with custom camera (2D) -/
@[extern "lean_raylib__BeginMode2D"]
opaque BeginMode2D (camera : @& Camera2D) : BaseIO Unit
/-- Ends 2D mode with custom camera -/
@[extern "lean_raylib__EndMode2D"]
opaque EndMode2D : BaseIO Unit
/-- Begin 3D mode with custom camera (3D) -/
@[extern "lean_raylib__BeginMode3D"]
opaque BeginMode3D (camera : @& Camera3D) : BaseIO Unit
/-- Ends 3D mode and returns to default 2D orthographic mode -/
@[extern "lean_raylib__EndMode3D"]
opaque EndMode3D : BaseIO Unit
-- /-- Begin drawing to render texture -/
-- @[extern "lean_raylib__BeginTextureMode"]
-- opaque BeginTextureMode (target : RenderTexture2D) : Unit
-- /-- Ends drawing to render texture -/
-- @[extern "lean_raylib__EndTextureMode"]
-- opaque EndTextureMode (_ : Unit) : Unit
-- /-- Begin custom shader drawing -/
-- @[extern "lean_raylib__BeginShaderMode"]
-- opaque BeginShaderMode (shader : Shader) : Unit
-- /-- End custom shader drawing (use default shader) -/
-- @[extern "lean_raylib__EndShaderMode"]
-- opaque EndShaderMode (_ : Unit) : Unit
/-- Begin blending mode (alpha, additive, multiplied, subtract, custom) -/
@[extern "lean_raylib__BeginBlendMode"]
opaque BeginBlendMode (mode : BlendMode) : BaseIO Unit
/-- End blending mode (reset to default: alpha blending) -/
@[extern "lean_raylib__EndBlendMode"]
opaque EndBlendMode : BaseIO Unit
/-- Begin scissor mode (define screen area for following drawing) -/
@[extern "lean_raylib__BeginScissorMode"]
opaque BeginScissorMode (x y width height : UInt32) : BaseIO Unit
/-- End scissor mode -/
@[extern "lean_raylib__EndScissorMode"]
opaque EndScissorMode : BaseIO Unit
-- /-- Begin stereo rendering (requires VR simulator) -/
-- @[extern "lean_raylib__BeginVrStereoMode"]
-- opaque BeginVrStereoMode (config : VrStereoConfig) : Unit
-- /-- End stereo rendering (requires VR simulator) -/
-- @[extern "lean_raylib__EndVrStereoMode"]
-- opaque EndVrStereoMode (_ : Unit) : Unit
-- /-- Load VR stereo config for VR simulator device parameters -/
-- @[extern "lean_raylib__LoadVrStereoConfig"]
-- opaque LoadVrStereoConfig (device : VrDeviceInfo) : VrStereoConfig
-- /-- Unload VR stereo config -/
-- @[extern "lean_raylib__UnloadVrStereoConfig"]
-- opaque UnloadVrStereoConfig (config : VrStereoConfig) : Unit
-- /-- Load shader from files and bind default locations -/
-- @[extern "lean_raylib__LoadShader"]
-- opaque LoadShader (vsFileName : String) (fsFileName : String) : Shader
-- /-- Load shader from code strings and bind default locations -/
-- @[extern "lean_raylib__LoadShaderFromMemory"]
-- opaque LoadShaderFromMemory (vsCode : String) (fsCode : String) : Shader
-- /-- Check if a shader is ready -/
-- @[extern "lean_raylib__IsShaderReady"]
-- opaque IsShaderReady (shader : Shader) : Bool
-- /-- Get shader uniform location -/
-- @[extern "lean_raylib__GetShaderLocation"]
-- opaque GetShaderLocation (shader : Shader) (uniformName : String) : Int32
-- /-- Get shader attribute location -/
-- @[extern "lean_raylib__GetShaderLocationAttrib"]
-- opaque GetShaderLocationAttrib (shader : Shader) (attribName : String) : Int32
-- /-- Set shader uniform value -/
-- @[extern "lean_raylib__SetShaderValue"]
-- opaque SetShaderValue : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | shader : Shader
--   | locIndex : int
--   | value : const void *
--   | uniformType : int
-- -/
-- /-- Set shader uniform value vector -/
-- @[extern "lean_raylib__SetShaderValueV"]
-- opaque SetShaderValueV : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | shader : Shader
--   | locIndex : int
--   | value : const void *
--   | uniformType : int
--   | count : int
-- -/
-- /-- Set shader uniform value (matrix 4x4) -/
-- @[extern "lean_raylib__SetShaderValueMatrix"]
-- opaque SetShaderValueMatrix (shader : Shader) (locIndex : Int32) (mat : Matrix) : Unit
-- /-- Set shader uniform value for texture (sampler2d) -/
-- @[extern "lean_raylib__SetShaderValueTexture"]
-- opaque SetShaderValueTexture (shader : Shader) (locIndex : Int32) (texture : Texture2D) : Unit
-- /-- Unload shader from GPU memory (VRAM) -/
-- @[extern "lean_raylib__UnloadShader"]
-- opaque UnloadShader (shader : Shader) : Unit
/-- Get a ray trace from mouse position -/
-- IO: uses screen size
@[extern "lean_raylib__GetMouseRay"]
opaque GetMouseRay (mousePosition : @& Vector2) (camera : @& Camera) : BaseIO Ray
/-- Get camera transform matrix (view matrix) -/
@[extern "lean_raylib__GetCameraMatrix"]
opaque GetCameraMatrix (camera : @& Camera) : Matrix
/-- Get camera 2d transform matrix -/
@[extern "lean_raylib__GetCameraMatrix2D"]
opaque GetCameraMatrix2D (camera : @& Camera2D) : Matrix
/-- Get the screen space position for a 3d world space position -/
-- IO: uses screen size
@[extern "lean_raylib__GetWorldToScreen"]
opaque GetWorldToScreen (position : @& Vector3) (camera : @& Camera) : BaseIO Vector2
/-- Get the world space position for a 2d camera screen space position -/
@[extern "lean_raylib__GetScreenToWorld2D"]
opaque GetScreenToWorld2D (position : @& Vector2) (camera : @& Camera2D) : Vector2
/-- Get size position for a 3d world space position -/
-- IO: uses screen size
@[extern "lean_raylib__GetWorldToScreenEx"]
opaque GetWorldToScreenEx (position : @& Vector3) (camera : @& Camera) (width : UInt32) (height : UInt32) : BaseIO Vector2
/-- Get the screen space position for a 2d camera world space position -/
@[extern "lean_raylib__GetWorldToScreen2D"]
opaque GetWorldToScreen2D (position : @& Vector2) (camera : @& Camera2D) : Vector2
/-- Set target FPS (maximum) -/
@[extern "lean_raylib__SetTargetFPS"]
opaque SetTargetFPS (fps : UInt32) : BaseIO Unit
/-- Get current FPS -/
@[extern "lean_raylib__GetFPS"]
opaque GetFPS : BaseIO UInt32
/-- Get time in seconds for last frame drawn (delta time) -/
@[extern "lean_raylib__GetFrameTime"]
opaque GetFrameTime : BaseIO Float
/-- Get elapsed time in seconds since InitWindow() -/
@[extern "lean_raylib__GetTime"]
opaque GetTime : BaseIO Float
/-- Get a random value between min and max (both included) -/
@[extern "lean_raylib__GetRandomValue"]
opaque GetRandomValue (min : Int32) (max : Int32) : BaseIO Int32
/-- Set the seed for the random number generator -/
@[extern "lean_raylib__SetRandomSeed"]
opaque SetRandomSeed (seed : UInt32) : BaseIO Unit
/-- Takes a screenshot of current screen (filename extension defines format) -/
@[extern "lean_raylib__TakeScreenshot"]
opaque TakeScreenshot (fileName : String) : BaseIO Unit
/-- Setup init configuration flags (view FLAGS) -/
@[extern "lean_raylib__SetConfigFlags"]
opaque SetConfigFlags (flags : ConfigFlags) : BaseIO Unit
-- todo: Variadic/formatted TraceLog (note: impossible to forward C variadic safely)
/-- Show trace log messages (LOG_DEBUG, LOG_INFO, LOG_WARNING, LOG_ERROR...) -/
@[extern "lean_raylib__TraceLog_s"]
opaque TraceLog' (logLevel : TraceLogLevel) (text : @& String) : BaseIO Unit
/-- Set the current threshold (minimum) log level -/
@[extern "lean_raylib__SetTraceLogLevel"]
opaque SetTraceLogLevel (logLevel : TraceLogLevel) : BaseIO Unit
-- /-- Internal memory allocator -/
-- @[extern "lean_raylib__MemAlloc"]
-- opaque MemAlloc : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void *
--   params:
--   | size : unsigned int
-- -/
-- /-- Internal memory reallocator -/
-- @[extern "lean_raylib__MemRealloc"]
-- opaque MemRealloc : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void *
--   params:
--   | ptr : void *
--   | size : unsigned int
-- -/
-- /-- Internal memory free -/
-- @[extern "lean_raylib__MemFree"]
-- opaque MemFree : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | ptr : void *
-- -/
/-- Open URL with default system browser (if available) -/
@[extern "lean_raylib__OpenURL"]
opaque OpenURL (url : @& String) : BaseIO Unit
-- /-- Set custom trace log -/
-- @[extern "lean_raylib__SetTraceLogCallback"]
-- opaque SetTraceLogCallback : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | callback : TraceLogCallback
-- -/
-- /-- Set custom file binary data loader -/
-- @[extern "lean_raylib__SetLoadFileDataCallback"]
-- opaque SetLoadFileDataCallback : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | callback : LoadFileDataCallback
-- -/
-- /-- Set custom file binary data saver -/
-- @[extern "lean_raylib__SetSaveFileDataCallback"]
-- opaque SetSaveFileDataCallback : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | callback : SaveFileDataCallback
-- -/
-- /-- Set custom file text data loader -/
-- @[extern "lean_raylib__SetLoadFileTextCallback"]
-- opaque SetLoadFileTextCallback : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | callback : LoadFileTextCallback
-- -/
-- /-- Set custom file text data saver -/
-- @[extern "lean_raylib__SetSaveFileTextCallback"]
-- opaque SetSaveFileTextCallback : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | callback : SaveFileTextCallback
-- -/
/-- Load file data as byte array (read) -/
@[extern "lean_raylib__LoadFileData"]
opaque LoadFileData (fileName : @& String) : BaseIO ByteArray
/-- Unload file data allocated by LoadFileData() -/
@[extern "lean_raylib__UnloadFileData", deprecated]
opaque UnloadFileData (data : @& ByteArray) : Unit
/-- Save data to file from byte array (write), returns true on success -/
@[extern "lean_raylib__SaveFileData"]
opaque SaveFileData (fileName : @& String) (data : @& ByteArray) (offset : USize := 0) (bytesToWrite : UInt32) : IO Bool
/-- Export data to code (.h), returns true on success -/
@[extern "lean_raylib__ExportDataAsCode"]
opaque ExportDataAsCode (data : @& ByteArray) (offset : USize := 0) (size : UInt32) (fileName : @& String) : IO Bool
/-- Load text data from file (read), returns a ~~'\0' terminated~~ string -/
@[extern "lean_raylib__LoadFileText"]
opaque LoadFileText (fileName : @& String) : BaseIO String
/-- Unload file text data allocated by LoadFileText() -/
@[extern "lean_raylib__UnloadFileText", deprecated]
opaque UnloadFileText (text : @& String) : Unit
/-- Save text data to file (write), ~~string must be '\0' terminated~~, returns true on success -/
@[extern "lean_raylib__SaveFileText"]
opaque SaveFileText (fileName : @& String) (text : @& String) : BaseIO Bool
/-- Check if file exists -/
@[extern "lean_raylib__FileExists"]
opaque FileExists (fileName : @& String) : BaseIO Bool
/-- Check if a directory path exists -/
@[extern "lean_raylib__DirectoryExists"]
opaque DirectoryExists (dirPath : @& String) : BaseIO Bool
/--
Check file extension (including point: .png, .wav)
NOTE: Extensions checking is not case-sensitive.
-/
@[extern "lean_raylib__IsFileExtension"]
opaque IsFileExtension (fileName : @& String) (ext : @& String) : Bool
/--
Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h).
Returns `0` on error (ex. file doesn't exist).
-/
@[extern "lean_raylib__GetFileLength"]
opaque GetFileLength (fileName : @& String) : BaseIO UInt32

/-- Get pointer to extension for a filename string (includes dot: '.png') -/
@[extern "lean_raylib__GetFileExtension"]
opaque GetFileExtension (fileName : @& String) : Option USize
/-- Get pointer to filename for a path string -/
@[extern "lean_raylib__GetFileName"]
opaque GetFileName (filePath : @& String) : USize
/--
Get filename string without extension (uses static string).
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetFileNameWithoutExt"]
opaque GetFileNameWithoutExt (filePath : @& String) : String
/--
Get full path for a given fileName with path (uses static string).
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetDirectoryPath"]
opaque GetDirectoryPath (filePath : @& String) : String
/--
Get previous directory path for a given path (uses static string).
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetPrevDirectoryPath"]
opaque GetPrevDirectoryPath (dirPath : @& String) : String
/--
Get current working directory (uses static string)
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetWorkingDirectory"]
opaque GetWorkingDirectory : BaseIO String
/--
Get the directory if the running application (uses static string).
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetApplicationDirectory"]
opaque GetApplicationDirectory : BaseIO String
/-- Change working directory, return true on success -/
@[extern "lean_raylib__ChangeDirectory"]
opaque ChangeDirectory (dir : @& String) : BaseIO Bool
/-- Check if a given path is a file or a directory -/
@[extern "lean_raylib__IsPathFile"]
opaque IsPathFile (path : @& String) : BaseIO Bool
/-- Load directory filepaths -/
@[extern "lean_raylib__LoadDirectoryFiles"]
opaque LoadDirectoryFiles (dirPath : @& String) : BaseIO $ Array String
-- /-- Load directory filepaths with extension filtering and recursive directory scan -/
-- @[extern "lean_raylib__LoadDirectoryFilesEx"]
-- opaque LoadDirectoryFilesEx (basePath : String) (filter : String) (scanSubdirs : Bool) : FilePathList
-- /-- Unload filepaths -/
-- @[extern "lean_raylib__UnloadDirectoryFiles"]
-- opaque UnloadDirectoryFiles (files : FilePathList) : Unit
/-- Check if a file has been dropped into window -/
@[extern "lean_raylib__IsFileDropped"]
opaque IsFileDropped : BaseIO Bool
-- /-- Load dropped filepaths -/
-- @[extern "lean_raylib__LoadDroppedFiles"]
-- opaque LoadDroppedFiles (_ : Unit) : FilePathList
-- /-- Unload dropped filepaths -/
-- @[extern "lean_raylib__UnloadDroppedFiles"]
-- opaque UnloadDroppedFiles (files : FilePathList) : Unit
/--
Get file modification time (last write time).
Returns `0` on error (ex. file doesn't exist).
-/
@[extern "lean_raylib__GetFileModTime"]
opaque GetFileModTime (fileName : @& String) : BaseIO UInt64
/-- Compress data (DEFLATE algorithm), ~~memory must be MemFree()~~ -/
@[extern "lean_raylib__CompressData"]
opaque CompressData (data : @& ByteArray) : ByteArray
/-- Decompress data (DEFLATE algorithm), ~~memory must be MemFree()~~ -/
@[extern "lean_raylib__DecompressData"]
opaque DecompressData (compData : @& ByteArray) : ByteArray
/-- Encode data to Base64 string, ~~memory must be MemFree()~~ -/
@[extern "lean_raylib__EncodeDataBase64"]
opaque EncodeDataBase64 (data : @& ByteArray) : String
/-- Decode Base64 string data, ~~memory must be MemFree()~~ -/
@[extern "lean_raylib__DecodeDataBase64"]
opaque DecodeDataBase64 (code : @& String) : ByteArray
/-- Check if a key has been pressed once -/
@[extern "lean_raylib__IsKeyPressed"]
opaque IsKeyPressed (key : KeyboardKey) : BaseIO Bool
/-- Check if a key is being pressed -/
@[extern "lean_raylib__IsKeyDown"]
opaque IsKeyDown (key : KeyboardKey) : BaseIO Bool
/-- Check if a key has been released once -/
@[extern "lean_raylib__IsKeyReleased"]
opaque IsKeyReleased (key : KeyboardKey) : BaseIO Bool
/-- Check if a key is NOT being pressed -/
@[extern "lean_raylib__IsKeyUp"]
opaque IsKeyUp (key : KeyboardKey) : BaseIO Bool
/-- Set a custom key to exit program (default is ESC) -/
@[extern "lean_raylib__SetExitKey"]
opaque SetExitKey (key : KeyboardKey) : BaseIO Unit
/-- Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty -/
@[extern "lean_raylib__GetKeyPressed"]
opaque GetKeyPressed : BaseIO KeyboardKey
/-- Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty -/
@[extern "lean_raylib__GetCharPressed"]
opaque GetCharPressed : BaseIO Char
/-- Check if a gamepad is available -/
@[extern "lean_raylib__IsGamepadAvailable"]
opaque IsGamepadAvailable (gamepad : UInt32) : BaseIO Bool
/-- Get gamepad internal name id -/
@[extern "lean_raylib__GetGamepadName"]
opaque GetGamepadName (gamepad : UInt32) : BaseIO String
/-- Check if a gamepad button has been pressed once -/
@[extern "lean_raylib__IsGamepadButtonPressed"]
opaque IsGamepadButtonPressed (gamepad : UInt32) (button : GamepadButton) : BaseIO Bool
/-- Check if a gamepad button is being pressed -/
@[extern "lean_raylib__IsGamepadButtonDown"]
opaque IsGamepadButtonDown (gamepad : UInt32) (button : GamepadButton) : BaseIO Bool
/-- Check if a gamepad button has been released once -/
@[extern "lean_raylib__IsGamepadButtonReleased"]
opaque IsGamepadButtonReleased (gamepad : UInt32) (button : GamepadButton) : BaseIO Bool
/-- Check if a gamepad button is NOT being pressed -/
@[extern "lean_raylib__IsGamepadButtonUp"]
opaque IsGamepadButtonUp (gamepad : UInt32) (button : GamepadButton) : BaseIO Bool
/-- Get the last gamepad button pressed -/
@[extern "lean_raylib__GetGamepadButtonPressed"]
opaque GetGamepadButtonPressed : BaseIO GamepadButton
/-- Get gamepad axis count for a gamepad -/
@[extern "lean_raylib__GetGamepadAxisCount"]
opaque GetGamepadAxisCount (gamepad : UInt32) : BaseIO UInt32
/-- Get axis movement value for a gamepad axis -/
@[extern "lean_raylib__GetGamepadAxisMovement"]
opaque GetGamepadAxisMovement (gamepad : UInt32) (axis : UInt32) : BaseIO Float
/-- Set internal gamepad mappings (SDL_GameControllerDB) -/
@[extern "lean_raylib__SetGamepadMappings"]
opaque SetGamepadMappings (mappings : String) : BaseIO Bool
/-- Check if a mouse button has been pressed once -/
@[extern "lean_raylib__IsMouseButtonPressed"]
opaque IsMouseButtonPressed (button : MouseButton) : BaseIO Bool
/-- Check if a mouse button is being pressed -/
@[extern "lean_raylib__IsMouseButtonDown"]
opaque IsMouseButtonDown (button : MouseButton) : BaseIO Bool
/-- Check if a mouse button has been released once -/
@[extern "lean_raylib__IsMouseButtonReleased"]
opaque IsMouseButtonReleased (button : MouseButton) : BaseIO Bool
/-- Check if a mouse button is NOT being pressed -/
@[extern "lean_raylib__IsMouseButtonUp"]
opaque IsMouseButtonUp (button : MouseButton) : BaseIO Bool
/-- Get mouse position X -/
@[extern "lean_raylib__GetMouseX"]
opaque GetMouseX : BaseIO Int32
/-- Get mouse position Y -/
@[extern "lean_raylib__GetMouseY"]
opaque GetMouseY : BaseIO Int32
/-- Get mouse position XY -/
@[extern "lean_raylib__GetMousePosition"]
opaque GetMousePosition : BaseIO Vector2
/-- Get mouse delta between frames -/
@[extern "lean_raylib__GetMouseDelta"]
opaque GetMouseDelta : BaseIO Vector2
/-- Set mouse position XY -/
@[extern "lean_raylib__SetMousePosition"]
opaque SetMousePosition (x : Int32) (y : Int32) : BaseIO Unit
/-- Set mouse offset -/
@[extern "lean_raylib__SetMouseOffset"]
opaque SetMouseOffset (offsetX : Int32) (offsetY : Int32) : BaseIO Unit
/-- Set mouse scaling -/
@[extern "lean_raylib__SetMouseScale"]
opaque SetMouseScale (scaleX : Float) (scaleY : Float) : BaseIO Unit
/-- Get mouse wheel movement for X or Y, whichever is larger -/
@[extern "lean_raylib__GetMouseWheelMove"]
opaque GetMouseWheelMove : BaseIO Float
/-- Get mouse wheel movement for both X and Y -/
@[extern "lean_raylib__GetMouseWheelMoveV"]
opaque GetMouseWheelMoveV : BaseIO Vector2
/-- Set mouse cursor -/
@[extern "lean_raylib__SetMouseCursor"]
opaque SetMouseCursor (cursor : MouseCursor) : BaseIO Unit
/-- Get touch position X for touch point 0 (relative to screen size) -/
@[extern "lean_raylib__GetTouchX"]
opaque GetTouchX : BaseIO Int32
/-- Get touch position Y for touch point 0 (relative to screen size) -/
@[extern "lean_raylib__GetTouchY"]
opaque GetTouchY : BaseIO Int32
/-- Get touch position XY for a touch point index (relative to screen size) -/
@[extern "lean_raylib__GetTouchPosition"]
opaque GetTouchPosition (index : UInt32) : BaseIO Vector2
/-- Get touch point identifier for given index -/
@[extern "lean_raylib__GetTouchPointId"]
opaque GetTouchPointId (index : UInt32) : BaseIO Int32
/-- Get number of touch points -/
@[extern "lean_raylib__GetTouchPointCount"]
opaque GetTouchPointCount : BaseIO UInt32
/-- Enable a set of gestures using flags -/
@[extern "lean_raylib__SetGesturesEnabled"]
opaque SetGesturesEnabled (flags : GestureFlags) : BaseIO Unit
/-- Check if a gesture have been detected -/
@[extern "lean_raylib__IsGestureDetected"]
opaque IsGestureDetected (gesture : Gesture) : BaseIO Bool
/-- Get latest detected gesture -/
@[extern "lean_raylib__GetGestureDetected"]
opaque GetGestureDetected : BaseIO Gesture
/-- Get gesture hold time in milliseconds -/
@[extern "lean_raylib__GetGestureHoldDuration"]
opaque GetGestureHoldDuration : BaseIO Float
/-- Get gesture drag vector -/
@[extern "lean_raylib__GetGestureDragVector"]
opaque GetGestureDragVector : BaseIO Vector2
/-- Get gesture drag angle -/
@[extern "lean_raylib__GetGestureDragAngle"]
opaque GetGestureDragAngle : BaseIO Float
/-- Get gesture pinch delta -/
@[extern "lean_raylib__GetGesturePinchVector"]
opaque GetGesturePinchVector : BaseIO Vector2
/-- Get gesture pinch angle -/
@[extern "lean_raylib__GetGesturePinchAngle"]
opaque GetGesturePinchAngle : BaseIO Float
/-- Update camera position for selected mode -/
@[extern "lean_raylib__UpdateCamera"]
opaque UpdateCamera (cam : Camera) (mode : CameraMode) : BaseIO Camera
-- /-- Set texture and rectangle to be used on shapes drawing -/
-- @[extern "lean_raylib__SetShapesTexture"]
-- opaque SetShapesTexture (texture : Texture2D) (source : Rectangle) : Unit
/-- Draw a pixel -/
@[extern "lean_raylib__DrawPixel"]
opaque DrawPixel (posX : Int32) (posY : Int32) (color : Color) : BaseIO Unit
/-- Draw a pixel (Vector version) -/
@[extern "lean_raylib__DrawPixelV"]
opaque DrawPixelV (position : Vector2) (color : Color) : BaseIO Unit
/-- Draw a line -/
@[extern "lean_raylib__DrawLine"]
opaque DrawLine (startPosX : Int32) (startPosY : Int32) (endPosX : Int32) (endPosY : Int32) (color : Color) : BaseIO Unit
/-- Draw a line (Vector version) -/
@[extern "lean_raylib__DrawLineV"]
opaque DrawLineV (startPos : Vector2) (endPos : Vector2) (color : Color) : BaseIO Unit
/-- Draw a line defining thickness -/
@[extern "lean_raylib__DrawLineEx"]
opaque DrawLineEx (startPos : Vector2) (endPos : Vector2) (thick : Float) (color : Color) : BaseIO Unit
/-- Draw a line using cubic-bezier curves in-out -/
@[extern "lean_raylib__DrawLineBezier"]
opaque DrawLineBezier (startPos : Vector2) (endPos : Vector2) (thick : Float) (color : Color) : BaseIO Unit
/-- Draw line using quadratic bezier curves with a control point -/
@[extern "lean_raylib__DrawLineBezierQuad"]
opaque DrawLineBezierQuad (startPos : Vector2) (endPos : Vector2) (controlPos : Vector2) (thick : Float) (color : Color) : BaseIO Unit
/-- Draw line using cubic bezier curves with 2 control points -/
@[extern "lean_raylib__DrawLineBezierCubic"]
opaque DrawLineBezierCubic (startPos : Vector2) (endPos : Vector2) (startControlPos : Vector2) (endControlPos : Vector2) (thick : Float) (color : Color) : BaseIO Unit
-- /-- Draw lines sequence -/
-- @[extern "lean_raylib__DrawLineStrip"]
-- opaque DrawLineStrip : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | points : Vector2 *
--   | pointCount : int
--   | color : Color
-- -/
/-- Draw a color-filled circle -/
@[extern "lean_raylib__DrawCircle"]
opaque DrawCircle (centerX : Int32) (centerY : Int32) (radius : Float) (color : Color) : BaseIO Unit
/-- Draw a piece of a circle -/
@[extern "lean_raylib__DrawCircleSector"]
opaque DrawCircleSector (center : @& Vector2) (radius : Float) (startAngle : Float) (endAngle : Float) (segments : UInt32) (color : Color) : BaseIO Unit
/-- Draw circle sector outline -/
@[extern "lean_raylib__DrawCircleSectorLines"]
opaque DrawCircleSectorLines (center : @& Vector2) (radius : Float) (startAngle : Float) (endAngle : Float) (segments : UInt32) (color : Color) : BaseIO Unit
/-- Draw a gradient-filled circle -/
@[extern "lean_raylib__DrawCircleGradient"]
opaque DrawCircleGradient (centerX : Int32) (centerY : Int32) (radius : Float) (color1 : Color) (color2 : Color) : BaseIO Unit
/-- Draw a color-filled circle (Vector version) -/
@[extern "lean_raylib__DrawCircleV"]
opaque DrawCircleV (center : @& Vector2) (radius : Float) (color : Color) : BaseIO Unit
/-- Draw circle outline -/
@[extern "lean_raylib__DrawCircleLines"]
opaque DrawCircleLines (centerX : Int32) (centerY : Int32) (radius : Float) (color : Color) : BaseIO Unit
/-- Draw ellipse -/
@[extern "lean_raylib__DrawEllipse"]
opaque DrawEllipse (centerX : Int32) (centerY : Int32) (radiusH : Float) (radiusV : Float) (color : Color) : BaseIO Unit
/-- Draw ellipse outline -/
@[extern "lean_raylib__DrawEllipseLines"]
opaque DrawEllipseLines (centerX : Int32) (centerY : Int32) (radiusH : Float) (radiusV : Float) (color : Color) : BaseIO Unit
/-- Draw ring -/
@[extern "lean_raylib__DrawRing"]
opaque DrawRing (center : @& Vector2) (innerRadius : Float) (outerRadius : Float) (startAngle : Float) (endAngle : Float) (segments : UInt32) (color : Color) : BaseIO Unit
/-- Draw ring outline -/
@[extern "lean_raylib__DrawRingLines"]
opaque DrawRingLines (center : @& Vector2) (innerRadius : Float) (outerRadius : Float) (startAngle : Float) (endAngle : Float) (segments : UInt32) (color : Color) : BaseIO Unit
/-- Draw a color-filled rectangle -/
@[extern "lean_raylib__DrawRectangle"]
opaque DrawRectangle (posX : Int32) (posY : Int32) (width : Int32) (height : Int32) (color : Color) : BaseIO Unit
/-- Draw a color-filled rectangle (Vector version) -/
@[extern "lean_raylib__DrawRectangleV"]
opaque DrawRectangleV (position : @& Vector2) (size : @& Vector2) (color : Color) : BaseIO Unit
/-- Draw a color-filled rectangle -/
@[extern "lean_raylib__DrawRectangleRec"]
opaque DrawRectangleRec (rec : @& Rectangle) (color : Color) : BaseIO Unit
/-- Draw a color-filled rectangle with pro parameters -/
@[extern "lean_raylib__DrawRectanglePro"]
opaque DrawRectanglePro (rec : @& Rectangle) (origin : @& Vector2) (rotation : Float) (color : Color) : BaseIO Unit
/-- Draw a vertical-gradient-filled rectangle -/
@[extern "lean_raylib__DrawRectangleGradientV"]
opaque DrawRectangleGradientV (posX : Int32) (posY : Int32) (width : Int32) (height : Int32) (color1 : Color) (color2 : Color) : BaseIO Unit
/-- Draw a horizontal-gradient-filled rectangle -/
@[extern "lean_raylib__DrawRectangleGradientH"]
opaque DrawRectangleGradientH (posX : Int32) (posY : Int32) (width : Int32) (height : Int32) (color1 : Color) (color2 : Color) : BaseIO Unit
/-- Draw a gradient-filled rectangle with custom vertex colors -/
@[extern "lean_raylib__DrawRectangleGradientEx"]
opaque DrawRectangleGradientEx (rec : @& Rectangle) (col1 : Color) (col2 : Color) (col3 : Color) (col4 : Color) : BaseIO Unit
/-- Draw rectangle outline -/
@[extern "lean_raylib__DrawRectangleLines"]
opaque DrawRectangleLines (posX : Int32) (posY : Int32) (width : Int32) (height : Int32) (color : Color) : BaseIO Unit
/-- Draw rectangle outline with extended parameters -/
@[extern "lean_raylib__DrawRectangleLinesEx"]
opaque DrawRectangleLinesEx (rec : @& Rectangle) (lineThick : Float) (color : Color) : BaseIO Unit
/-- Draw rectangle with rounded edges -/
@[extern "lean_raylib__DrawRectangleRounded"]
opaque DrawRectangleRounded (rec : @& Rectangle) (roundness : Float) (segments : UInt32) (color : Color) : BaseIO Unit
/-- Draw rectangle with rounded edges outline -/
@[extern "lean_raylib__DrawRectangleRoundedLines"]
opaque DrawRectangleRoundedLines (rec : @& Rectangle) (roundness : Float) (segments : UInt32) (lineThick : Float) (color : Color) : BaseIO Unit
/-- Draw a color-filled triangle (vertex in counter-clockwise order!) -/
@[extern "lean_raylib__DrawTriangle"]
opaque DrawTriangle (v1 : @& Vector2) (v2 : @& Vector2) (v3 : @& Vector2) (color : Color) : BaseIO Unit
/-- Draw triangle outline (vertex in counter-clockwise order!) -/
@[extern "lean_raylib__DrawTriangleLines"]
opaque DrawTriangleLines (v1 : @& Vector2) (v2 : @& Vector2) (v3 : @& Vector2) (color : Color) : BaseIO Unit
-- /-- Draw a triangle fan defined by points (first vertex is the center) -/
-- @[extern "lean_raylib__DrawTriangleFan"]
-- opaque DrawTriangleFan : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | points : Vector2 *
--   | pointCount : int
--   | color : Color
-- -/
-- /-- Draw a triangle strip defined by points -/
-- @[extern "lean_raylib__DrawTriangleStrip"]
-- opaque DrawTriangleStrip : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | points : Vector2 *
--   | pointCount : int
--   | color : Color
-- -/
-- /-- Draw a regular polygon (Vector version) -/
-- @[extern "lean_raylib__DrawPoly"]
-- opaque DrawPoly (center : Vector2) (sides : Int32) (radius : Float) (rotation : Float) (color : Color) : Unit
-- /-- Draw a polygon outline of n sides -/
-- @[extern "lean_raylib__DrawPolyLines"]
-- opaque DrawPolyLines (center : Vector2) (sides : Int32) (radius : Float) (rotation : Float) (color : Color) : Unit
-- /-- Draw a polygon outline of n sides with extended parameters -/
-- @[extern "lean_raylib__DrawPolyLinesEx"]
-- opaque DrawPolyLinesEx (center : Vector2) (sides : Int32) (radius : Float) (rotation : Float) (lineThick : Float) (color : Color) : Unit
-- /-- Check collision between two rectangles -/
-- @[extern "lean_raylib__CheckCollisionRecs"]
-- opaque CheckCollisionRecs (rec1 : Rectangle) (rec2 : Rectangle) : Bool
-- /-- Check collision between two circles -/
-- @[extern "lean_raylib__CheckCollisionCircles"]
-- opaque CheckCollisionCircles (center1 : Vector2) (radius1 : Float) (center2 : Vector2) (radius2 : Float) : Bool
-- /-- Check collision between circle and rectangle -/
-- @[extern "lean_raylib__CheckCollisionCircleRec"]
-- opaque CheckCollisionCircleRec (center : Vector2) (radius : Float) (rec : Rectangle) : Bool
-- /-- Check if point is inside rectangle -/
-- @[extern "lean_raylib__CheckCollisionPointRec"]
-- opaque CheckCollisionPointRec (point : Vector2) (rec : Rectangle) : Bool
-- /-- Check if point is inside circle -/
-- @[extern "lean_raylib__CheckCollisionPointCircle"]
-- opaque CheckCollisionPointCircle (point : Vector2) (center : Vector2) (radius : Float) : Bool
-- /-- Check if point is inside a triangle -/
-- @[extern "lean_raylib__CheckCollisionPointTriangle"]
-- opaque CheckCollisionPointTriangle (point : Vector2) (p1 : Vector2) (p2 : Vector2) (p3 : Vector2) : Bool
-- /-- Check if point is within a polygon described by array of vertices -/
-- @[extern "lean_raylib__CheckCollisionPointPoly"]
-- opaque CheckCollisionPointPoly : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: bool
--   params:
--   | point : Vector2
--   | points : Vector2 *
--   | pointCount : int
-- -/
-- /-- Check the collision between two lines defined by two points each, returns collision point by reference -/
-- @[extern "lean_raylib__CheckCollisionLines"]
-- opaque CheckCollisionLines : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: bool
--   params:
--   | startPos1 : Vector2
--   | endPos1 : Vector2
--   | startPos2 : Vector2
--   | endPos2 : Vector2
--   | collisionPoint : Vector2 *
-- -/
-- /-- Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold] -/
-- @[extern "lean_raylib__CheckCollisionPointLine"]
-- opaque CheckCollisionPointLine (point : Vector2) (p1 : Vector2) (p2 : Vector2) (threshold : Int32) : Bool
-- /-- Get collision rectangle for two rectangles collision -/
-- @[extern "lean_raylib__GetCollisionRec"]
-- opaque GetCollisionRec (rec1 : Rectangle) (rec2 : Rectangle) : Rectangle
/-- Load image from file into CPU memory (RAM) -/
@[extern "lean_raylib__LoadImage"]
opaque LoadImage (fileName : @& String) : BaseIO Image
/-- Load image from RAW file data -/
@[extern "lean_raylib__LoadImageRaw"]
opaque LoadImageRaw
  (fileName : @& String) (width : UInt32) (height : UInt32)
  (format : PixelFormat) (headerSize : UInt32)
  : BaseIO Image
/-- Load image sequence from file (frames appended to image.data) -/
@[extern "lean_raylib__LoadImageAnim"]
opaque LoadImageAnim (fileName : @& String) : BaseIO (Image × UInt32)
/-- Load image from memory buffer, fileType refers to extension: i.e. '.png' -/
@[extern "lean_raylib__LoadImageFromMemory"]
opaque LoadImageFromMemory (fileType : @& String) (fileData : @& ByteArray) : BaseIO Image
-- /-- Load image from GPU texture data -/
-- @[extern "lean_raylib__LoadImageFromTexture"]
-- opaque LoadImageFromTexture (texture : Texture2D) : Image
/-- Load image from screen buffer and (screenshot) -/
@[extern "lean_raylib__LoadImageFromScreen"]
opaque LoadImageFromScreen : BaseIO Image
/-- Check if an image is ready -/
@[extern "lean_raylib__IsImageReady"]
opaque IsImageReady (image : @& Image) : Bool
/--
Unload image from CPU memory (RAM)
DEPRECATED: The image will be freed only when its RC becomes zero.
-/
@[extern "lean_raylib__UnloadImage", deprecated]
opaque UnloadImage (image : @& Image) : Unit
/-- Export image data to file, returns true on success -/
@[extern "lean_raylib__ExportImage"]
opaque ExportImage (image : @& Image) (fileName : @& String) : BaseIO Bool
/-- Export image as code file defining an array of bytes, returns true on success -/
@[extern "lean_raylib__ExportImageAsCode"]
opaque ExportImageAsCode (image : @& Image) (fileName : @& String) : BaseIO Bool
/-- Generate image: plain color -/
@[extern "lean_raylib__GenImageColor"]
opaque GenImageColor (width height : UInt32) (color : Color) : Image
-- /-- Generate image: vertical gradient -/
-- @[extern "lean_raylib__GenImageGradientV"]
-- opaque GenImageGradientV (width : Int32) (height : Int32) (top : Color) (bottom : Color) : Image
-- /-- Generate image: horizontal gradient -/
-- @[extern "lean_raylib__GenImageGradientH"]
-- opaque GenImageGradientH (width : Int32) (height : Int32) (left : Color) (right : Color) : Image
-- /-- Generate image: radial gradient -/
-- @[extern "lean_raylib__GenImageGradientRadial"]
-- opaque GenImageGradientRadial (width : Int32) (height : Int32) (density : Float) (inner : Color) (outer : Color) : Image
-- /-- Generate image: checked -/
-- @[extern "lean_raylib__GenImageChecked"]
-- opaque GenImageChecked (width : Int32) (height : Int32) (checksX : Int32) (checksY : Int32) (col1 : Color) (col2 : Color) : Image
-- /-- Generate image: white noise -/
-- @[extern "lean_raylib__GenImageWhiteNoise"]
-- opaque GenImageWhiteNoise (width : Int32) (height : Int32) (factor : Float) : Image
-- /-- Generate image: perlin noise -/
-- @[extern "lean_raylib__GenImagePerlinNoise"]
-- opaque GenImagePerlinNoise (width : Int32) (height : Int32) (offsetX : Int32) (offsetY : Int32) (scale : Float) : Image
-- /-- Generate image: cellular algorithm, bigger tileSize means bigger cells -/
-- @[extern "lean_raylib__GenImageCellular"]
-- opaque GenImageCellular (width : Int32) (height : Int32) (tileSize : Int32) : Image
-- /-- Generate image: grayscale image from text data -/
-- @[extern "lean_raylib__GenImageText"]
-- opaque GenImageText (width : Int32) (height : Int32) (text : String) : Image
/-- Create an image duplicate (useful for transformations) -/
@[extern "lean_raylib__ImageCopy"]
opaque ImageCopy (image : @& Image) : Image
/-- Create an image from another image piece -/
@[extern "lean_raylib__ImageFromImage"]
opaque ImageFromImage (image : @& Image) (rec : @& Rectangle) : Image
-- /-- Create an image from text (default font) -/
-- @[extern "lean_raylib__ImageText"]
-- opaque ImageText (text : String) (fontSize : Int32) (color : Color) : Image
-- /-- Create an image from text (custom sprite font) -/
-- @[extern "lean_raylib__ImageTextEx"]
-- opaque ImageTextEx (font : Font) (text : String) (fontSize : Float) (spacing : Float) (tint : Color) : Image
-- /-- Convert image data to desired format -/
-- @[extern "lean_raylib__ImageFormat"]
-- opaque ImageFormat : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | newFormat : int
-- -/
-- /-- Convert image to POT (power-of-two) -/
-- @[extern "lean_raylib__ImageToPOT"]
-- opaque ImageToPOT : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | fill : Color
-- -/
-- /-- Crop an image to a defined rectangle -/
-- @[extern "lean_raylib__ImageCrop"]
-- opaque ImageCrop : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | crop : Rectangle
-- -/
-- /-- Crop image depending on alpha value -/
-- @[extern "lean_raylib__ImageAlphaCrop"]
-- opaque ImageAlphaCrop : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | threshold : float
-- -/
-- /-- Clear alpha channel to desired color -/
-- @[extern "lean_raylib__ImageAlphaClear"]
-- opaque ImageAlphaClear : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | color : Color
--   | threshold : float
-- -/
-- /-- Apply alpha mask to image -/
-- @[extern "lean_raylib__ImageAlphaMask"]
-- opaque ImageAlphaMask : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | alphaMask : Image
-- -/
-- /-- Premultiply alpha channel -/
-- @[extern "lean_raylib__ImageAlphaPremultiply"]
-- opaque ImageAlphaPremultiply : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
-- -/
-- /-- Apply Gaussian blur using a box blur approximation -/
-- @[extern "lean_raylib__ImageBlurGaussian"]
-- opaque ImageBlurGaussian : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | blurSize : int
-- -/
-- /-- Resize image (Bicubic scaling algorithm) -/
-- @[extern "lean_raylib__ImageResize"]
-- opaque ImageResize : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | newWidth : int
--   | newHeight : int
-- -/
-- /-- Resize image (Nearest-Neighbor scaling algorithm) -/
-- @[extern "lean_raylib__ImageResizeNN"]
-- opaque ImageResizeNN : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | newWidth : int
--   | newHeight : int
-- -/
-- /-- Resize canvas and fill with color -/
-- @[extern "lean_raylib__ImageResizeCanvas"]
-- opaque ImageResizeCanvas : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | newWidth : int
--   | newHeight : int
--   | offsetX : int
--   | offsetY : int
--   | fill : Color
-- -/
-- /-- Compute all mipmap levels for a provided image -/
-- @[extern "lean_raylib__ImageMipmaps"]
-- opaque ImageMipmaps : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
-- -/
-- /-- Dither image data to 16bpp or lower (Floyd-Steinberg dithering) -/
-- @[extern "lean_raylib__ImageDither"]
-- opaque ImageDither : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | rBpp : int
--   | gBpp : int
--   | bBpp : int
--   | aBpp : int
-- -/
-- /-- Flip image vertically -/
-- @[extern "lean_raylib__ImageFlipVertical"]
-- opaque ImageFlipVertical : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
-- -/
-- /-- Flip image horizontally -/
-- @[extern "lean_raylib__ImageFlipHorizontal"]
-- opaque ImageFlipHorizontal : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
-- -/
-- /-- Rotate image clockwise 90deg -/
-- @[extern "lean_raylib__ImageRotateCW"]
-- opaque ImageRotateCW : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
-- -/
-- /-- Rotate image counter-clockwise 90deg -/
-- @[extern "lean_raylib__ImageRotateCCW"]
-- opaque ImageRotateCCW : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
-- -/
-- /-- Modify image color: tint -/
-- @[extern "lean_raylib__ImageColorTint"]
-- opaque ImageColorTint : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | color : Color
-- -/
-- /-- Modify image color: invert -/
-- @[extern "lean_raylib__ImageColorInvert"]
-- opaque ImageColorInvert : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
-- -/
-- /-- Modify image color: grayscale -/
-- @[extern "lean_raylib__ImageColorGrayscale"]
-- opaque ImageColorGrayscale : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
-- -/
-- /-- Modify image color: contrast (-100 to 100) -/
-- @[extern "lean_raylib__ImageColorContrast"]
-- opaque ImageColorContrast : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | contrast : float
-- -/
-- /-- Modify image color: brightness (-255 to 255) -/
-- @[extern "lean_raylib__ImageColorBrightness"]
-- opaque ImageColorBrightness : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | brightness : int
-- -/
-- /-- Modify image color: replace color -/
-- @[extern "lean_raylib__ImageColorReplace"]
-- opaque ImageColorReplace : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | image : Image *
--   | color : Color
--   | replace : Color
-- -/
-- /-- Load color data from image as a Color array (RGBA - 32bit) -/
-- @[extern "lean_raylib__LoadImageColors"]
-- opaque LoadImageColors : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: Color *
--   params:
--   | image : Image
-- -/
-- /-- Load colors palette from image as a Color array (RGBA - 32bit) -/
-- @[extern "lean_raylib__LoadImagePalette"]
-- opaque LoadImagePalette : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: Color *
--   params:
--   | image : Image
--   | maxPaletteSize : int
--   | colorCount : int *
-- -/
-- /-- Unload color data loaded with LoadImageColors() -/
-- @[extern "lean_raylib__UnloadImageColors"]
-- opaque UnloadImageColors : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | colors : Color *
-- -/
-- /-- Unload colors palette loaded with LoadImagePalette() -/
-- @[extern "lean_raylib__UnloadImagePalette"]
-- opaque UnloadImagePalette : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | colors : Color *
-- -/
-- /-- Get image alpha border rectangle -/
-- @[extern "lean_raylib__GetImageAlphaBorder"]
-- opaque GetImageAlphaBorder (image : Image) (threshold : Float) : Rectangle
-- /-- Get image pixel color at (x, y) position -/
-- @[extern "lean_raylib__GetImageColor"]
-- opaque GetImageColor (image : Image) (x : Int32) (y : Int32) : Color
-- /-- Clear image background with given color -/
-- @[extern "lean_raylib__ImageClearBackground"]
-- opaque ImageClearBackground : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | color : Color
-- -/
-- /-- Draw pixel within an image -/
-- @[extern "lean_raylib__ImageDrawPixel"]
-- opaque ImageDrawPixel : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | posX : int
--   | posY : int
--   | color : Color
-- -/
-- /-- Draw pixel within an image (Vector version) -/
-- @[extern "lean_raylib__ImageDrawPixelV"]
-- opaque ImageDrawPixelV : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | position : Vector2
--   | color : Color
-- -/
-- /-- Draw line within an image -/
-- @[extern "lean_raylib__ImageDrawLine"]
-- opaque ImageDrawLine : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | startPosX : int
--   | startPosY : int
--   | endPosX : int
--   | endPosY : int
--   | color : Color
-- -/
-- /-- Draw line within an image (Vector version) -/
-- @[extern "lean_raylib__ImageDrawLineV"]
-- opaque ImageDrawLineV : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | start : Vector2
--   | end : Vector2
--   | color : Color
-- -/
-- /-- Draw a filled circle within an image -/
-- @[extern "lean_raylib__ImageDrawCircle"]
-- opaque ImageDrawCircle : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | centerX : int
--   | centerY : int
--   | radius : int
--   | color : Color
-- -/
-- /-- Draw a filled circle within an image (Vector version) -/
-- @[extern "lean_raylib__ImageDrawCircleV"]
-- opaque ImageDrawCircleV : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | center : Vector2
--   | radius : int
--   | color : Color
-- -/
-- /-- Draw circle outline within an image -/
-- @[extern "lean_raylib__ImageDrawCircleLines"]
-- opaque ImageDrawCircleLines : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | centerX : int
--   | centerY : int
--   | radius : int
--   | color : Color
-- -/
-- /-- Draw circle outline within an image (Vector version) -/
-- @[extern "lean_raylib__ImageDrawCircleLinesV"]
-- opaque ImageDrawCircleLinesV : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | center : Vector2
--   | radius : int
--   | color : Color
-- -/
-- /-- Draw rectangle within an image -/
-- @[extern "lean_raylib__ImageDrawRectangle"]
-- opaque ImageDrawRectangle : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | posX : int
--   | posY : int
--   | width : int
--   | height : int
--   | color : Color
-- -/
-- /-- Draw rectangle within an image (Vector version) -/
-- @[extern "lean_raylib__ImageDrawRectangleV"]
-- opaque ImageDrawRectangleV : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | position : Vector2
--   | size : Vector2
--   | color : Color
-- -/
-- /-- Draw rectangle within an image -/
-- @[extern "lean_raylib__ImageDrawRectangleRec"]
-- opaque ImageDrawRectangleRec : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | rec : Rectangle
--   | color : Color
-- -/
-- /-- Draw rectangle lines within an image -/
-- @[extern "lean_raylib__ImageDrawRectangleLines"]
-- opaque ImageDrawRectangleLines : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | rec : Rectangle
--   | thick : int
--   | color : Color
-- -/
-- /-- Draw a source image within a destination image (tint applied to source) -/
-- @[extern "lean_raylib__ImageDraw"]
-- opaque ImageDraw : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | src : Image
--   | srcRec : Rectangle
--   | dstRec : Rectangle
--   | tint : Color
-- -/
-- /-- Draw text (using default font) within an image (destination) -/
-- @[extern "lean_raylib__ImageDrawText"]
-- opaque ImageDrawText : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | text : const char *
--   | posX : int
--   | posY : int
--   | fontSize : int
--   | color : Color
-- -/
-- /-- Draw text (custom sprite font) within an image (destination) -/
-- @[extern "lean_raylib__ImageDrawTextEx"]
-- opaque ImageDrawTextEx : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dst : Image *
--   | font : Font
--   | text : const char *
--   | position : Vector2
--   | fontSize : float
--   | spacing : float
--   | tint : Color
-- -/
-- /-- Load texture from file into GPU memory (VRAM) -/
-- @[extern "lean_raylib__LoadTexture"]
-- opaque LoadTexture (fileName : String) : Texture2D
-- /-- Load texture from image data -/
-- @[extern "lean_raylib__LoadTextureFromImage"]
-- opaque LoadTextureFromImage (image : Image) : Texture2D
-- /-- Load cubemap from image, multiple image cubemap layouts supported -/
-- @[extern "lean_raylib__LoadTextureCubemap"]
-- opaque LoadTextureCubemap (image : Image) (layout : Int32) : TextureCubemap
-- /-- Load texture for rendering (framebuffer) -/
-- @[extern "lean_raylib__LoadRenderTexture"]
-- opaque LoadRenderTexture (width : Int32) (height : Int32) : RenderTexture2D
-- /-- Check if a texture is ready -/
-- @[extern "lean_raylib__IsTextureReady"]
-- opaque IsTextureReady (texture : Texture2D) : Bool
-- /-- Unload texture from GPU memory (VRAM) -/
-- @[extern "lean_raylib__UnloadTexture"]
-- opaque UnloadTexture (texture : Texture2D) : Unit
-- /-- Check if a render texture is ready -/
-- @[extern "lean_raylib__IsRenderTextureReady"]
-- opaque IsRenderTextureReady (target : RenderTexture2D) : Bool
-- /-- Unload render texture from GPU memory (VRAM) -/
-- @[extern "lean_raylib__UnloadRenderTexture"]
-- opaque UnloadRenderTexture (target : RenderTexture2D) : Unit
-- /-- Update GPU texture with new data -/
-- @[extern "lean_raylib__UpdateTexture"]
-- opaque UpdateTexture : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | texture : Texture2D
--   | pixels : const void *
-- -/
-- /-- Update GPU texture rectangle with new data -/
-- @[extern "lean_raylib__UpdateTextureRec"]
-- opaque UpdateTextureRec : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | texture : Texture2D
--   | rec : Rectangle
--   | pixels : const void *
-- -/
-- /-- Generate GPU mipmaps for a texture -/
-- @[extern "lean_raylib__GenTextureMipmaps"]
-- opaque GenTextureMipmaps : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | texture : Texture2D *
-- -/
-- /-- Set texture scaling filter mode -/
-- @[extern "lean_raylib__SetTextureFilter"]
-- opaque SetTextureFilter (texture : Texture2D) (filter : Int32) : Unit
-- /-- Set texture wrapping mode -/
-- @[extern "lean_raylib__SetTextureWrap"]
-- opaque SetTextureWrap (texture : Texture2D) (wrap : Int32) : Unit
-- /-- Draw a Texture2D -/
-- @[extern "lean_raylib__DrawTexture"]
-- opaque DrawTexture (texture : Texture2D) (posX : Int32) (posY : Int32) (tint : Color) : Unit
-- /-- Draw a Texture2D with position defined as Vector2 -/
-- @[extern "lean_raylib__DrawTextureV"]
-- opaque DrawTextureV (texture : Texture2D) (position : Vector2) (tint : Color) : Unit
-- /-- Draw a Texture2D with extended parameters -/
-- @[extern "lean_raylib__DrawTextureEx"]
-- opaque DrawTextureEx (texture : Texture2D) (position : Vector2) (rotation : Float) (scale : Float) (tint : Color) : Unit
-- /-- Draw a part of a texture defined by a rectangle -/
-- @[extern "lean_raylib__DrawTextureRec"]
-- opaque DrawTextureRec (texture : Texture2D) (source : Rectangle) (position : Vector2) (tint : Color) : Unit
-- /-- Draw a part of a texture defined by a rectangle with 'pro' parameters -/
-- @[extern "lean_raylib__DrawTexturePro"]
-- opaque DrawTexturePro (texture : Texture2D) (source : Rectangle) (dest : Rectangle) (origin : Vector2) (rotation : Float) (tint : Color) : Unit
-- /-- Draws a texture (or part of it) that stretches or shrinks nicely -/
-- @[extern "lean_raylib__DrawTextureNPatch"]
-- opaque DrawTextureNPatch (texture : Texture2D) (nPatchInfo : NPatchInfo) (dest : Rectangle) (origin : Vector2) (rotation : Float) (tint : Color) : Unit
/-- Get color with alpha applied, alpha goes from 0.0f to 1.0f -/
@[extern "lean_raylib__Fade"]
opaque Fade (color : Color) (alpha : Float) : Color
/-- Get hexadecimal value for a Color -/
@[extern "lean_raylib__ColorToInt", deprecated Color.rgba]
opaque ColorToInt (color : Color) : UInt32
/-- Get Color normalized as float [0..1] -/
@[extern "lean_raylib__ColorNormalize"]
opaque ColorNormalize (color : Color) : Vector4
/-- Get Color from normalized values [0..1] -/
@[extern "lean_raylib__ColorFromNormalized"]
opaque ColorFromNormalized (normalized : Vector4) : Color
/-- Get HSV values for a Color, hue [0..360], saturation/value [0..1] -/
@[extern "lean_raylib__ColorToHSV"]
opaque ColorToHSV (color : Color) : Vector3
/-- Get a Color from HSV values, hue [0..360], saturation/value [0..1] -/
@[extern "lean_raylib__ColorFromHSV"]
opaque ColorFromHSV (hue : Float) (saturation : Float) (value : Float) : Color
/-- Get color multiplied with another color -/
@[extern "lean_raylib__ColorTint"]
opaque ColorTint (color : Color) (tint : Color) : Color
/-- Get color with brightness correction, brightness factor goes from -1.0f to 1.0f -/
@[extern "lean_raylib__ColorBrightness"]
opaque ColorBrightness (color : Color) (factor : Float) : Color
/-- Get color with contrast correction, contrast values between -1.0f and 1.0f -/
@[extern "lean_raylib__ColorContrast"]
opaque ColorContrast (color : Color) (contrast : Float) : Color
/-- Get color with alpha applied, alpha goes from 0.0f to 1.0f -/
@[extern "lean_raylib__ColorAlpha"]
opaque ColorAlpha (color : Color) (alpha : Float) : Color
/-- Get src alpha-blended into dst color with tint -/
@[extern "lean_raylib__ColorAlphaBlend"]
opaque ColorAlphaBlend (dst : Color) (src : Color) (tint : Color) : Color
/-- Get Color structure from hexadecimal value -/
@[extern "lean_raylib__GetColor", deprecated Color.mk]
opaque GetColor (hexValue : UInt32) : Color
-- /-- Get Color from a source pixel pointer of certain format -/
-- @[extern "lean_raylib__GetPixelColor"]
-- opaque GetPixelColor : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: Color
--   params:
--   | srcPtr : void *
--   | format : int
-- -/
-- /-- Set color formatted into destination pixel pointer -/
-- @[extern "lean_raylib__SetPixelColor"]
-- opaque SetPixelColor : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | dstPtr : void *
--   | color : Color
--   | format : int
-- -/
-- /-- Get pixel data size in bytes for certain format -/
-- @[extern "lean_raylib__GetPixelDataSize"]
-- opaque GetPixelDataSize (width : Int32) (height : Int32) (format : Int32) : Int32
-- /-- Get the default Font -/
-- @[extern "lean_raylib__GetFontDefault"]
-- opaque GetFontDefault (_ : Unit) : Font
-- /-- Load font from file into GPU memory (VRAM) -/
-- @[extern "lean_raylib__LoadFont"]
-- opaque LoadFont (fileName : String) : Font
-- /-- Load font from file with extended parameters, use NULL for fontChars and 0 for glyphCount to load the default character set -/
-- @[extern "lean_raylib__LoadFontEx"]
-- opaque LoadFontEx : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: Font
--   params:
--   | fileName : const char *
--   | fontSize : int
--   | fontChars : int *
--   | glyphCount : int
-- -/
-- /-- Load font from Image (XNA style) -/
-- @[extern "lean_raylib__LoadFontFromImage"]
-- opaque LoadFontFromImage (image : Image) (key : Color) (firstChar : Int32) : Font
-- /-- Load font from memory buffer, fileType refers to extension: i.e. '.ttf' -/
-- @[extern "lean_raylib__LoadFontFromMemory"]
-- opaque LoadFontFromMemory : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: Font
--   params:
--   | fileType : const char *
--   | fileData : const unsigned char *
--   | dataSize : int
--   | fontSize : int
--   | fontChars : int *
--   | glyphCount : int
-- -/
-- /-- Check if a font is ready -/
-- @[extern "lean_raylib__IsFontReady"]
-- opaque IsFontReady (font : Font) : Bool
-- /-- Load font data for further use -/
-- @[extern "lean_raylib__LoadFontData"]
-- opaque LoadFontData : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: GlyphInfo *
--   params:
--   | fileData : const unsigned char *
--   | dataSize : int
--   | fontSize : int
--   | fontChars : int *
--   | glyphCount : int
--   | type : int
-- -/
-- /-- Generate image font atlas using chars info -/
-- @[extern "lean_raylib__GenImageFontAtlas"]
-- opaque GenImageFontAtlas : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: Image
--   params:
--   | chars : const GlyphInfo *
--   | recs : Rectangle * *
--   | glyphCount : int
--   | fontSize : int
--   | padding : int
--   | packMethod : int
-- -/
-- /-- Unload font chars info data (RAM) -/
-- @[extern "lean_raylib__UnloadFontData"]
-- opaque UnloadFontData : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | chars : GlyphInfo *
--   | glyphCount : int
-- -/
-- /-- Unload font from GPU memory (VRAM) -/
-- @[extern "lean_raylib__UnloadFont"]
-- opaque UnloadFont (font : Font) : Unit
-- /-- Export font as code file, returns true on success -/
-- @[extern "lean_raylib__ExportFontAsCode"]
-- opaque ExportFontAsCode (font : Font) (fileName : String) : Bool
/-- Draw current FPS -/
@[extern "lean_raylib__DrawFPS"]
opaque DrawFPS (posX : Int32) (posY : Int32) : BaseIO Unit
/-- Draw text (using default font) -/
@[extern "lean_raylib__DrawText"]
opaque DrawText (text : String) (posX : Int32) (posY : Int32) (fontSize : Int32) (color : Color) : BaseIO Unit
-- /-- Draw text using font and additional parameters -/
-- @[extern "lean_raylib__DrawTextEx"]
-- opaque DrawTextEx (font : Font) (text : String) (position : Vector2) (fontSize : Float) (spacing : Float) (tint : Color) : Unit
-- /-- Draw text using Font and pro parameters (rotation) -/
-- @[extern "lean_raylib__DrawTextPro"]
-- opaque DrawTextPro (font : Font) (text : String) (position : Vector2) (origin : Vector2) (rotation : Float) (fontSize : Float) (spacing : Float) (tint : Color) : Unit
-- /-- Draw one character (codepoint) -/
-- @[extern "lean_raylib__DrawTextCodepoint"]
-- opaque DrawTextCodepoint (font : Font) (codepoint : Int32) (position : Vector2) (fontSize : Float) (tint : Color) : Unit
-- /-- Draw multiple character (codepoint) -/
-- @[extern "lean_raylib__DrawTextCodepoints"]
-- opaque DrawTextCodepoints : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | font : Font
--   | codepoints : const int *
--   | count : int
--   | position : Vector2
--   | fontSize : float
--   | spacing : float
--   | tint : Color
-- -/
-- /-- Measure string width for default font -/
-- @[extern "lean_raylib__MeasureText"]
-- opaque MeasureText (text : String) (fontSize : Int32) : Int32
-- /-- Measure string size for Font -/
-- @[extern "lean_raylib__MeasureTextEx"]
-- opaque MeasureTextEx (font : Font) (text : String) (fontSize : Float) (spacing : Float) : Vector2
-- /-- Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found -/
-- @[extern "lean_raylib__GetGlyphIndex"]
-- opaque GetGlyphIndex (font : Font) (codepoint : Int32) : Int32
-- /-- Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found -/
-- @[extern "lean_raylib__GetGlyphInfo"]
-- opaque GetGlyphInfo (font : Font) (codepoint : Int32) : GlyphInfo
-- /-- Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found -/
-- @[extern "lean_raylib__GetGlyphAtlasRec"]
-- opaque GetGlyphAtlasRec (font : Font) (codepoint : Int32) : Rectangle
-- /-- Load UTF-8 text encoded from codepoints array -/
-- @[extern "lean_raylib__LoadUTF8"]
-- opaque LoadUTF8 : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: char *
--   params:
--   | codepoints : const int *
--   | length : int
-- -/
-- /-- Unload UTF-8 text encoded from codepoints array -/
-- @[extern "lean_raylib__UnloadUTF8"]
-- opaque UnloadUTF8 : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | text : char *
-- -/
-- /-- Load all codepoints from a UTF-8 text string, codepoints count returned by parameter -/
-- @[extern "lean_raylib__LoadCodepoints"]
-- opaque LoadCodepoints : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: int *
--   params:
--   | text : const char *
--   | count : int *
-- -/
-- /-- Unload codepoints data from memory -/
-- @[extern "lean_raylib__UnloadCodepoints"]
-- opaque UnloadCodepoints : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | codepoints : int *
-- -/
-- /-- Get total number of codepoints in a UTF-8 encoded string -/
-- @[extern "lean_raylib__GetCodepointCount"]
-- opaque GetCodepointCount (text : String) : Int32
-- /-- Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure -/
-- @[extern "lean_raylib__GetCodepoint"]
-- opaque GetCodepoint : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: int
--   params:
--   | text : const char *
--   | codepointSize : int *
-- -/
-- /-- Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure -/
-- @[extern "lean_raylib__GetCodepointNext"]
-- opaque GetCodepointNext : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: int
--   params:
--   | text : const char *
--   | codepointSize : int *
-- -/
-- /-- Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure -/
-- @[extern "lean_raylib__GetCodepointPrevious"]
-- opaque GetCodepointPrevious : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: int
--   params:
--   | text : const char *
--   | codepointSize : int *
-- -/
-- /-- Encode one codepoint into UTF-8 byte array (array length returned as parameter) -/
-- @[extern "lean_raylib__CodepointToUTF8"]
-- opaque CodepointToUTF8 : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: const char *
--   params:
--   | codepoint : int
--   | utf8Size : int *
-- -/
-- /-- Copy one string to another, returns bytes copied -/
-- @[extern "lean_raylib__TextCopy"]
-- opaque TextCopy : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: int
--   params:
--   | dst : char *
--   | src : const char *
-- -/
-- /-- Check if two text string are equal -/
-- @[extern "lean_raylib__TextIsEqual"]
-- opaque TextIsEqual (text1 : String) (text2 : String) : Bool
-- /-- Get text length, checks for '\0' ending -/
-- @[extern "lean_raylib__TextLength"]
-- opaque TextLength (text : String) : UInt32
-- /-- Text formatting with variables (sprintf() style) -/
-- @[extern "lean_raylib__TextFormat"]
-- opaque TextFormat : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: const char *
--   params:
--   | text : const char *
--   | args : /*variadic*/ ...
-- -/
-- /-- Get a piece of a text string -/
-- @[extern "lean_raylib__TextSubtext"]
-- opaque TextSubtext (text : String) (position : Int32) (length : Int32) : String
-- /-- Replace text string (WARNING: memory must be freed!) -/
-- @[extern "lean_raylib__TextReplace"]
-- opaque TextReplace : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: char *
--   params:
--   | text : char *
--   | replace : const char *
--   | by : const char *
-- -/
-- /-- Insert text in a position (WARNING: memory must be freed!) -/
-- @[extern "lean_raylib__TextInsert"]
-- opaque TextInsert : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: char *
--   params:
--   | text : const char *
--   | insert : const char *
--   | position : int
-- -/
-- /-- Join text strings with delimiter -/
-- @[extern "lean_raylib__TextJoin"]
-- opaque TextJoin : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: const char *
--   params:
--   | textList : const char * *
--   | count : int
--   | delimiter : const char *
-- -/
-- /-- Split text into multiple strings -/
-- @[extern "lean_raylib__TextSplit"]
-- opaque TextSplit : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: const char * *
--   params:
--   | text : const char *
--   | delimiter : char
--   | count : int *
-- -/
-- /-- Append text at specific position and move cursor! -/
-- @[extern "lean_raylib__TextAppend"]
-- opaque TextAppend : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | text : char *
--   | append : const char *
--   | position : int *
-- -/
-- /-- Find first text occurrence within a string -/
-- @[extern "lean_raylib__TextFindIndex"]
-- opaque TextFindIndex (text : String) (find : String) : Int32
-- /-- Get upper case version of provided string -/
-- @[extern "lean_raylib__TextToUpper"]
-- opaque TextToUpper (text : String) : String
-- /-- Get lower case version of provided string -/
-- @[extern "lean_raylib__TextToLower"]
-- opaque TextToLower (text : String) : String
-- /-- Get Pascal case notation version of provided string -/
-- @[extern "lean_raylib__TextToPascal"]
-- opaque TextToPascal (text : String) : String
-- /-- Get integer value from text (negative values not supported) -/
-- @[extern "lean_raylib__TextToInteger"]
-- opaque TextToInteger (text : String) : Int32
-- /-- Draw a line in 3D world space -/
-- @[extern "lean_raylib__DrawLine3D"]
-- opaque DrawLine3D (startPos : Vector3) (endPos : Vector3) (color : Color) : Unit
-- /-- Draw a point in 3D space, actually a small line -/
-- @[extern "lean_raylib__DrawPoint3D"]
-- opaque DrawPoint3D (position : Vector3) (color : Color) : Unit
-- /-- Draw a circle in 3D world space -/
-- @[extern "lean_raylib__DrawCircle3D"]
-- opaque DrawCircle3D (center : Vector3) (radius : Float) (rotationAxis : Vector3) (rotationAngle : Float) (color : Color) : Unit
-- /-- Draw a color-filled triangle (vertex in counter-clockwise order!) -/
-- @[extern "lean_raylib__DrawTriangle3D"]
-- opaque DrawTriangle3D (v1 : Vector3) (v2 : Vector3) (v3 : Vector3) (color : Color) : Unit
-- /-- Draw a triangle strip defined by points -/
-- @[extern "lean_raylib__DrawTriangleStrip3D"]
-- opaque DrawTriangleStrip3D : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | points : Vector3 *
--   | pointCount : int
--   | color : Color
-- -/
-- /-- Draw cube -/
-- @[extern "lean_raylib__DrawCube"]
-- opaque DrawCube (position : Vector3) (width : Float) (height : Float) (length : Float) (color : Color) : Unit
-- /-- Draw cube (Vector version) -/
-- @[extern "lean_raylib__DrawCubeV"]
-- opaque DrawCubeV (position : Vector3) (size : Vector3) (color : Color) : Unit
-- /-- Draw cube wires -/
-- @[extern "lean_raylib__DrawCubeWires"]
-- opaque DrawCubeWires (position : Vector3) (width : Float) (height : Float) (length : Float) (color : Color) : Unit
-- /-- Draw cube wires (Vector version) -/
-- @[extern "lean_raylib__DrawCubeWiresV"]
-- opaque DrawCubeWiresV (position : Vector3) (size : Vector3) (color : Color) : Unit
-- /-- Draw sphere -/
-- @[extern "lean_raylib__DrawSphere"]
-- opaque DrawSphere (centerPos : Vector3) (radius : Float) (color : Color) : Unit
-- /-- Draw sphere with extended parameters -/
-- @[extern "lean_raylib__DrawSphereEx"]
-- opaque DrawSphereEx (centerPos : Vector3) (radius : Float) (rings : Int32) (slices : Int32) (color : Color) : Unit
-- /-- Draw sphere wires -/
-- @[extern "lean_raylib__DrawSphereWires"]
-- opaque DrawSphereWires (centerPos : Vector3) (radius : Float) (rings : Int32) (slices : Int32) (color : Color) : Unit
-- /-- Draw a cylinder/cone -/
-- @[extern "lean_raylib__DrawCylinder"]
-- opaque DrawCylinder (position : Vector3) (radiusTop : Float) (radiusBottom : Float) (height : Float) (slices : Int32) (color : Color) : Unit
-- /-- Draw a cylinder with base at startPos and top at endPos -/
-- @[extern "lean_raylib__DrawCylinderEx"]
-- opaque DrawCylinderEx (startPos : Vector3) (endPos : Vector3) (startRadius : Float) (endRadius : Float) (sides : Int32) (color : Color) : Unit
-- /-- Draw a cylinder/cone wires -/
-- @[extern "lean_raylib__DrawCylinderWires"]
-- opaque DrawCylinderWires (position : Vector3) (radiusTop : Float) (radiusBottom : Float) (height : Float) (slices : Int32) (color : Color) : Unit
-- /-- Draw a cylinder wires with base at startPos and top at endPos -/
-- @[extern "lean_raylib__DrawCylinderWiresEx"]
-- opaque DrawCylinderWiresEx (startPos : Vector3) (endPos : Vector3) (startRadius : Float) (endRadius : Float) (sides : Int32) (color : Color) : Unit
-- /-- Draw a capsule with the center of its sphere caps at startPos and endPos -/
-- @[extern "lean_raylib__DrawCapsule"]
-- opaque DrawCapsule (startPos : Vector3) (endPos : Vector3) (radius : Float) (slices : Int32) (rings : Int32) (color : Color) : Unit
-- /-- Draw capsule wireframe with the center of its sphere caps at startPos and endPos -/
-- @[extern "lean_raylib__DrawCapsuleWires"]
-- opaque DrawCapsuleWires (startPos : Vector3) (endPos : Vector3) (radius : Float) (slices : Int32) (rings : Int32) (color : Color) : Unit
-- /-- Draw a plane XZ -/
-- @[extern "lean_raylib__DrawPlane"]
-- opaque DrawPlane (centerPos : Vector3) (size : Vector2) (color : Color) : Unit
-- /-- Draw a ray line -/
-- @[extern "lean_raylib__DrawRay"]
-- opaque DrawRay (ray : Ray) (color : Color) : Unit
-- /-- Draw a grid (centered at (0, 0, 0)) -/
-- @[extern "lean_raylib__DrawGrid"]
-- opaque DrawGrid (slices : Int32) (spacing : Float) : Unit
-- /-- Load model from files (meshes and materials) -/
-- @[extern "lean_raylib__LoadModel"]
-- opaque LoadModel (fileName : String) : Model
-- /-- Load model from generated mesh (default material) -/
-- @[extern "lean_raylib__LoadModelFromMesh"]
-- opaque LoadModelFromMesh (mesh : Mesh) : Model
-- /-- Check if a model is ready -/
-- @[extern "lean_raylib__IsModelReady"]
-- opaque IsModelReady (model : Model) : Bool
-- /-- Unload model (including meshes) from memory (RAM and/or VRAM) -/
-- @[extern "lean_raylib__UnloadModel"]
-- opaque UnloadModel (model : Model) : Unit
-- /-- Unload model (but not meshes) from memory (RAM and/or VRAM) -/
-- @[extern "lean_raylib__UnloadModelKeepMeshes"]
-- opaque UnloadModelKeepMeshes (model : Model) : Unit
-- /-- Compute model bounding box limits (considers all meshes) -/
-- @[extern "lean_raylib__GetModelBoundingBox"]
-- opaque GetModelBoundingBox (model : Model) : BoundingBox
-- /-- Draw a model (with texture if set) -/
-- @[extern "lean_raylib__DrawModel"]
-- opaque DrawModel (model : Model) (position : Vector3) (scale : Float) (tint : Color) : Unit
-- /-- Draw a model with extended parameters -/
-- @[extern "lean_raylib__DrawModelEx"]
-- opaque DrawModelEx (model : Model) (position : Vector3) (rotationAxis : Vector3) (rotationAngle : Float) (scale : Vector3) (tint : Color) : Unit
-- /-- Draw a model wires (with texture if set) -/
-- @[extern "lean_raylib__DrawModelWires"]
-- opaque DrawModelWires (model : Model) (position : Vector3) (scale : Float) (tint : Color) : Unit
-- /-- Draw a model wires (with texture if set) with extended parameters -/
-- @[extern "lean_raylib__DrawModelWiresEx"]
-- opaque DrawModelWiresEx (model : Model) (position : Vector3) (rotationAxis : Vector3) (rotationAngle : Float) (scale : Vector3) (tint : Color) : Unit
-- /-- Draw bounding box (wires) -/
-- @[extern "lean_raylib__DrawBoundingBox"]
-- opaque DrawBoundingBox (box : BoundingBox) (color : Color) : Unit
-- /-- Draw a billboard texture -/
-- @[extern "lean_raylib__DrawBillboard"]
-- opaque DrawBillboard (camera : Camera) (texture : Texture2D) (position : Vector3) (size : Float) (tint : Color) : Unit
-- /-- Draw a billboard texture defined by source -/
-- @[extern "lean_raylib__DrawBillboardRec"]
-- opaque DrawBillboardRec (camera : Camera) (texture : Texture2D) (source : Rectangle) (position : Vector3) (size : Vector2) (tint : Color) : Unit
-- /-- Draw a billboard texture defined by source and rotation -/
-- @[extern "lean_raylib__DrawBillboardPro"]
-- opaque DrawBillboardPro (camera : Camera) (texture : Texture2D) (source : Rectangle) (position : Vector3) (up : Vector3) (size : Vector2) (origin : Vector2) (rotation : Float) (tint : Color) : Unit
-- /-- Upload mesh vertex data in GPU and provide VAO/VBO ids -/
-- @[extern "lean_raylib__UploadMesh"]
-- opaque UploadMesh : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | mesh : Mesh *
--   | dynamic : bool
-- -/
-- /-- Update mesh vertex data in GPU for a specific buffer index -/
-- @[extern "lean_raylib__UpdateMeshBuffer"]
-- opaque UpdateMeshBuffer : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | mesh : Mesh
--   | index : int
--   | data : const void *
--   | dataSize : int
--   | offset : int
-- -/
-- /-- Unload mesh data from CPU and GPU -/
-- @[extern "lean_raylib__UnloadMesh"]
-- opaque UnloadMesh (mesh : Mesh) : Unit
-- /-- Draw a 3d mesh with material and transform -/
-- @[extern "lean_raylib__DrawMesh"]
-- opaque DrawMesh (mesh : Mesh) (material : Material) (transform : Matrix) : Unit
-- /-- Draw multiple mesh instances with material and different transforms -/
-- @[extern "lean_raylib__DrawMeshInstanced"]
-- opaque DrawMeshInstanced : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | mesh : Mesh
--   | material : Material
--   | transforms : const Matrix *
--   | instances : int
-- -/
-- /-- Export mesh data to file, returns true on success -/
-- @[extern "lean_raylib__ExportMesh"]
-- opaque ExportMesh (mesh : Mesh) (fileName : String) : Bool
-- /-- Compute mesh bounding box limits -/
-- @[extern "lean_raylib__GetMeshBoundingBox"]
-- opaque GetMeshBoundingBox (mesh : Mesh) : BoundingBox
-- /-- Compute mesh tangents -/
-- @[extern "lean_raylib__GenMeshTangents"]
-- opaque GenMeshTangents : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | mesh : Mesh *
-- -/
-- /-- Generate polygonal mesh -/
-- @[extern "lean_raylib__GenMeshPoly"]
-- opaque GenMeshPoly (sides : Int32) (radius : Float) : Mesh
-- /-- Generate plane mesh (with subdivisions) -/
-- @[extern "lean_raylib__GenMeshPlane"]
-- opaque GenMeshPlane (width : Float) (length : Float) (resX : Int32) (resZ : Int32) : Mesh
-- /-- Generate cuboid mesh -/
-- @[extern "lean_raylib__GenMeshCube"]
-- opaque GenMeshCube (width : Float) (height : Float) (length : Float) : Mesh
-- /-- Generate sphere mesh (standard sphere) -/
-- @[extern "lean_raylib__GenMeshSphere"]
-- opaque GenMeshSphere (radius : Float) (rings : Int32) (slices : Int32) : Mesh
-- /-- Generate half-sphere mesh (no bottom cap) -/
-- @[extern "lean_raylib__GenMeshHemiSphere"]
-- opaque GenMeshHemiSphere (radius : Float) (rings : Int32) (slices : Int32) : Mesh
-- /-- Generate cylinder mesh -/
-- @[extern "lean_raylib__GenMeshCylinder"]
-- opaque GenMeshCylinder (radius : Float) (height : Float) (slices : Int32) : Mesh
-- /-- Generate cone/pyramid mesh -/
-- @[extern "lean_raylib__GenMeshCone"]
-- opaque GenMeshCone (radius : Float) (height : Float) (slices : Int32) : Mesh
-- /-- Generate torus mesh -/
-- @[extern "lean_raylib__GenMeshTorus"]
-- opaque GenMeshTorus (radius : Float) (size : Float) (radSeg : Int32) (sides : Int32) : Mesh
-- /-- Generate trefoil knot mesh -/
-- @[extern "lean_raylib__GenMeshKnot"]
-- opaque GenMeshKnot (radius : Float) (size : Float) (radSeg : Int32) (sides : Int32) : Mesh
-- /-- Generate heightmap mesh from image data -/
-- @[extern "lean_raylib__GenMeshHeightmap"]
-- opaque GenMeshHeightmap (heightmap : Image) (size : Vector3) : Mesh
-- /-- Generate cubes-based map mesh from image data -/
-- @[extern "lean_raylib__GenMeshCubicmap"]
-- opaque GenMeshCubicmap (cubicmap : Image) (cubeSize : Vector3) : Mesh
-- /-- Load materials from model file -/
-- @[extern "lean_raylib__LoadMaterials"]
-- opaque LoadMaterials : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: Material *
--   params:
--   | fileName : const char *
--   | materialCount : int *
-- -/
-- /-- Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps) -/
-- @[extern "lean_raylib__LoadMaterialDefault"]
-- opaque LoadMaterialDefault (_ : Unit) : Material
-- /-- Check if a material is ready -/
-- @[extern "lean_raylib__IsMaterialReady"]
-- opaque IsMaterialReady (material : Material) : Bool
-- /-- Unload material from GPU memory (VRAM) -/
-- @[extern "lean_raylib__UnloadMaterial"]
-- opaque UnloadMaterial (material : Material) : Unit
-- /-- Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...) -/
-- @[extern "lean_raylib__SetMaterialTexture"]
-- opaque SetMaterialTexture : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | material : Material *
--   | mapType : int
--   | texture : Texture2D
-- -/
-- /-- Set material for a mesh -/
-- @[extern "lean_raylib__SetModelMeshMaterial"]
-- opaque SetModelMeshMaterial : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | model : Model *
--   | meshId : int
--   | materialId : int
-- -/
-- /-- Load model animations from file -/
-- @[extern "lean_raylib__LoadModelAnimations"]
-- opaque LoadModelAnimations : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: ModelAnimation *
--   params:
--   | fileName : const char *
--   | animCount : unsigned int *
-- -/
-- /-- Update model animation pose -/
-- @[extern "lean_raylib__UpdateModelAnimation"]
-- opaque UpdateModelAnimation (model : Model) (anim : ModelAnimation) (frame : Int32) : Unit
-- /-- Unload animation data -/
-- @[extern "lean_raylib__UnloadModelAnimation"]
-- opaque UnloadModelAnimation (anim : ModelAnimation) : Unit
-- /-- Unload animation array data -/
-- @[extern "lean_raylib__UnloadModelAnimations"]
-- opaque UnloadModelAnimations : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | animations : ModelAnimation *
--   | count : unsigned int
-- -/
-- /-- Check model animation skeleton match -/
-- @[extern "lean_raylib__IsModelAnimationValid"]
-- opaque IsModelAnimationValid (model : Model) (anim : ModelAnimation) : Bool
-- /-- Check collision between two spheres -/
-- @[extern "lean_raylib__CheckCollisionSpheres"]
-- opaque CheckCollisionSpheres (center1 : Vector3) (radius1 : Float) (center2 : Vector3) (radius2 : Float) : Bool
-- /-- Check collision between two bounding boxes -/
-- @[extern "lean_raylib__CheckCollisionBoxes"]
-- opaque CheckCollisionBoxes (box1 : BoundingBox) (box2 : BoundingBox) : Bool
-- /-- Check collision between box and sphere -/
-- @[extern "lean_raylib__CheckCollisionBoxSphere"]
-- opaque CheckCollisionBoxSphere (box : BoundingBox) (center : Vector3) (radius : Float) : Bool
-- /-- Get collision info between ray and sphere -/
-- @[extern "lean_raylib__GetRayCollisionSphere"]
-- opaque GetRayCollisionSphere (ray : Ray) (center : Vector3) (radius : Float) : RayCollision
-- /-- Get collision info between ray and box -/
-- @[extern "lean_raylib__GetRayCollisionBox"]
-- opaque GetRayCollisionBox (ray : Ray) (box : BoundingBox) : RayCollision
-- /-- Get collision info between ray and mesh -/
-- @[extern "lean_raylib__GetRayCollisionMesh"]
-- opaque GetRayCollisionMesh (ray : Ray) (mesh : Mesh) (transform : Matrix) : RayCollision
-- /-- Get collision info between ray and triangle -/
-- @[extern "lean_raylib__GetRayCollisionTriangle"]
-- opaque GetRayCollisionTriangle (ray : Ray) (p1 : Vector3) (p2 : Vector3) (p3 : Vector3) : RayCollision
-- /-- Get collision info between ray and quad -/
-- @[extern "lean_raylib__GetRayCollisionQuad"]
-- opaque GetRayCollisionQuad (ray : Ray) (p1 : Vector3) (p2 : Vector3) (p3 : Vector3) (p4 : Vector3) : RayCollision
/-- Initialize audio device and context -/
@[extern "lean_raylib__InitAudioDevice"]
opaque InitAudioDevice : BaseIO Unit
/-- Close the audio device and context -/
@[extern "lean_raylib__CloseAudioDevice"]
opaque CloseAudioDevice : BaseIO Unit
/-- Check if audio device has been initialized successfully -/
@[extern "lean_raylib__IsAudioDeviceReady"]
opaque IsAudioDeviceReady : BaseIO Bool
/-- Set master volume (listener) -/
@[extern "lean_raylib__SetMasterVolume"]
opaque SetMasterVolume (volume : Float) : BaseIO Unit
-- /-- Load wave data from file -/
-- @[extern "lean_raylib__LoadWave"]
-- opaque LoadWave (fileName : String) : Wave
-- /-- Load wave from memory buffer, fileType refers to extension: i.e. '.wav' -/
-- @[extern "lean_raylib__LoadWaveFromMemory"]
-- opaque LoadWaveFromMemory : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: Wave
--   params:
--   | fileType : const char *
--   | fileData : const unsigned char *
--   | dataSize : int
-- -/
-- /-- Checks if wave data is ready -/
-- @[extern "lean_raylib__IsWaveReady"]
-- opaque IsWaveReady (wave : Wave) : Bool
-- /-- Load sound from file -/
-- @[extern "lean_raylib__LoadSound"]
-- opaque LoadSound (fileName : String) : Sound
-- /-- Load sound from wave data -/
-- @[extern "lean_raylib__LoadSoundFromWave"]
-- opaque LoadSoundFromWave (wave : Wave) : Sound
-- /-- Checks if a sound is ready -/
-- @[extern "lean_raylib__IsSoundReady"]
-- opaque IsSoundReady (sound : Sound) : Bool
-- /-- Update sound buffer with new data -/
-- @[extern "lean_raylib__UpdateSound"]
-- opaque UpdateSound : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | sound : Sound
--   | data : const void *
--   | sampleCount : int
-- -/
-- /-- Unload wave data -/
-- @[extern "lean_raylib__UnloadWave"]
-- opaque UnloadWave (wave : Wave) : Unit
-- /-- Unload sound -/
-- @[extern "lean_raylib__UnloadSound"]
-- opaque UnloadSound (sound : Sound) : Unit
-- /-- Export wave data to file, returns true on success -/
-- @[extern "lean_raylib__ExportWave"]
-- opaque ExportWave (wave : Wave) (fileName : String) : Bool
-- /-- Export wave sample data to code (.h), returns true on success -/
-- @[extern "lean_raylib__ExportWaveAsCode"]
-- opaque ExportWaveAsCode (wave : Wave) (fileName : String) : Bool
-- /-- Play a sound -/
-- @[extern "lean_raylib__PlaySound"]
-- opaque PlaySound (sound : Sound) : Unit
-- /-- Stop playing a sound -/
-- @[extern "lean_raylib__StopSound"]
-- opaque StopSound (sound : Sound) : Unit
-- /-- Pause a sound -/
-- @[extern "lean_raylib__PauseSound"]
-- opaque PauseSound (sound : Sound) : Unit
-- /-- Resume a paused sound -/
-- @[extern "lean_raylib__ResumeSound"]
-- opaque ResumeSound (sound : Sound) : Unit
-- /-- Play a sound (using multichannel buffer pool) -/
-- @[extern "lean_raylib__PlaySoundMulti"]
-- opaque PlaySoundMulti (sound : Sound) : Unit
-- /-- Stop any sound playing (using multichannel buffer pool) -/
-- @[extern "lean_raylib__StopSoundMulti"]
-- opaque StopSoundMulti (_ : Unit) : Unit
-- /-- Get number of sounds playing in the multichannel -/
-- @[extern "lean_raylib__GetSoundsPlaying"]
-- opaque GetSoundsPlaying (_ : Unit) : Int32
-- /-- Check if a sound is currently playing -/
-- @[extern "lean_raylib__IsSoundPlaying"]
-- opaque IsSoundPlaying (sound : Sound) : Bool
-- /-- Set volume for a sound (1.0 is max level) -/
-- @[extern "lean_raylib__SetSoundVolume"]
-- opaque SetSoundVolume (sound : Sound) (volume : Float) : Unit
-- /-- Set pitch for a sound (1.0 is base level) -/
-- @[extern "lean_raylib__SetSoundPitch"]
-- opaque SetSoundPitch (sound : Sound) (pitch : Float) : Unit
-- /-- Set pan for a sound (0.5 is center) -/
-- @[extern "lean_raylib__SetSoundPan"]
-- opaque SetSoundPan (sound : Sound) (pan : Float) : Unit
-- /-- Copy a wave to a new wave -/
-- @[extern "lean_raylib__WaveCopy"]
-- opaque WaveCopy (wave : Wave) : Wave
-- /-- Crop a wave to defined samples range -/
-- @[extern "lean_raylib__WaveCrop"]
-- opaque WaveCrop : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | wave : Wave *
--   | initSample : int
--   | finalSample : int
-- -/
-- /-- Convert wave data to desired format -/
-- @[extern "lean_raylib__WaveFormat"]
-- opaque WaveFormat : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | wave : Wave *
--   | sampleRate : int
--   | sampleSize : int
--   | channels : int
-- -/
-- /-- Load samples data from wave as a 32bit float data array -/
-- @[extern "lean_raylib__LoadWaveSamples"]
-- opaque LoadWaveSamples : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: float *
--   params:
--   | wave : Wave
-- -/
-- /-- Unload samples data loaded with LoadWaveSamples() -/
-- @[extern "lean_raylib__UnloadWaveSamples"]
-- opaque UnloadWaveSamples : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | samples : float *
-- -/
/-- Load music stream from file -/
@[extern "lean_raylib__LoadMusicStream"]
opaque LoadMusicStream (fileName : @& String) : BaseIO Music
/-- Load music stream from data -/
-- IO: calls TraceLog
@[extern "lean_raylib__LoadMusicStreamFromMemory"]
opaque LoadMusicStreamFromMemory (fileType : @& String) (data : @& ByteArray) : BaseIO Music
/-- Checks if a music stream is ready -/
@[extern "lean_raylib__IsMusicReady"]
opaque IsMusicReady (music : @& Music) : Bool
/--
Unload music stream.
DEPRECATED: Music will be unloaded only when its RC becomes zero.
-/
@[extern "lean_raylib__UnloadMusicStream", deprecated]
opaque UnloadMusicStream (music : @& Music) : Unit
/-- Start music playing -/
@[extern "lean_raylib__PlayMusicStream"]
opaque PlayMusicStream (music : @& Music) : BaseIO Unit
/-- Check if music is playing -/
@[extern "lean_raylib__IsMusicStreamPlaying"]
opaque IsMusicStreamPlaying (music : @& Music) : BaseIO Bool
/-- Updates buffers for music streaming -/
@[extern "lean_raylib__UpdateMusicStream"]
opaque UpdateMusicStream (music : @& Music) : BaseIO Unit
/-- Stop music playing -/
@[extern "lean_raylib__StopMusicStream"]
opaque StopMusicStream (music : @& Music) : BaseIO Unit
/-- Pause music playing -/
@[extern "lean_raylib__PauseMusicStream"]
opaque PauseMusicStream (music : @& Music) : BaseIO Unit
/-- Resume playing paused music -/
@[extern "lean_raylib__ResumeMusicStream"]
opaque ResumeMusicStream (music : @& Music) : BaseIO Unit
/-- Seek music to a position (in seconds) -/
@[extern "lean_raylib__SeekMusicStream"]
opaque SeekMusicStream (music : @& Music) (position : Float) : BaseIO Unit
/-- Set volume for music (1.0 is max level) -/
@[extern "lean_raylib__SetMusicVolume"]
opaque SetMusicVolume (music : @& Music) (volume : Float) : BaseIO Unit
/-- Set pitch for a music (1.0 is base level) -/
@[extern "lean_raylib__SetMusicPitch"]
opaque SetMusicPitch (music : @& Music) (pitch : Float) : BaseIO Unit
/-- Set pan for a music (0.5 is center) -/
@[extern "lean_raylib__SetMusicPan"]
opaque SetMusicPan (music : @& Music) (pan : Float) : BaseIO Unit
/-- Get music time length (in seconds) -/
@[extern "lean_raylib__GetMusicTimeLength"]
opaque GetMusicTimeLength (music : @& Music) : Float
/-- Get current music time played (in seconds) -/
@[extern "lean_raylib__GetMusicTimePlayed"]
opaque GetMusicTimePlayed (music : @& Music) : BaseIO Float
-- /-- Load audio stream (to stream raw audio pcm data) -/
-- @[extern "lean_raylib__LoadAudioStream"]
-- opaque LoadAudioStream (sampleRate : UInt32) (sampleSize : UInt32) (channels : UInt32) : AudioStream
-- /-- Checks if an audio stream is ready -/
-- @[extern "lean_raylib__IsAudioStreamReady"]
-- opaque IsAudioStreamReady (stream : AudioStream) : Bool
-- /-- Unload audio stream and free memory -/
-- @[extern "lean_raylib__UnloadAudioStream"]
-- opaque UnloadAudioStream (stream : AudioStream) : Unit
-- /-- Update audio stream buffers with data -/
-- @[extern "lean_raylib__UpdateAudioStream"]
-- opaque UpdateAudioStream : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | stream : AudioStream
--   | data : const void *
--   | frameCount : int
-- -/
-- /-- Check if any audio stream buffers requires refill -/
-- @[extern "lean_raylib__IsAudioStreamProcessed"]
-- opaque IsAudioStreamProcessed (stream : AudioStream) : Bool
-- /-- Play audio stream -/
-- @[extern "lean_raylib__PlayAudioStream"]
-- opaque PlayAudioStream (stream : AudioStream) : Unit
-- /-- Pause audio stream -/
-- @[extern "lean_raylib__PauseAudioStream"]
-- opaque PauseAudioStream (stream : AudioStream) : Unit
-- /-- Resume audio stream -/
-- @[extern "lean_raylib__ResumeAudioStream"]
-- opaque ResumeAudioStream (stream : AudioStream) : Unit
-- /-- Check if audio stream is playing -/
-- @[extern "lean_raylib__IsAudioStreamPlaying"]
-- opaque IsAudioStreamPlaying (stream : AudioStream) : Bool
-- /-- Stop audio stream -/
-- @[extern "lean_raylib__StopAudioStream"]
-- opaque StopAudioStream (stream : AudioStream) : Unit
-- /-- Set volume for audio stream (1.0 is max level) -/
-- @[extern "lean_raylib__SetAudioStreamVolume"]
-- opaque SetAudioStreamVolume (stream : AudioStream) (volume : Float) : Unit
-- /-- Set pitch for audio stream (1.0 is base level) -/
-- @[extern "lean_raylib__SetAudioStreamPitch"]
-- opaque SetAudioStreamPitch (stream : AudioStream) (pitch : Float) : Unit
-- /-- Set pan for audio stream (0.5 is centered) -/
-- @[extern "lean_raylib__SetAudioStreamPan"]
-- opaque SetAudioStreamPan (stream : AudioStream) (pan : Float) : Unit
-- /-- Default size for new audio streams -/
-- @[extern "lean_raylib__SetAudioStreamBufferSizeDefault"]
-- opaque SetAudioStreamBufferSizeDefault (size : Int32) : Unit
-- /-- Audio thread callback to request new data -/
-- @[extern "lean_raylib__SetAudioStreamCallback"]
-- opaque SetAudioStreamCallback : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | stream : AudioStream
--   | callback : AudioCallback
-- -/
-- /-- Attach audio stream processor to stream -/
-- @[extern "lean_raylib__AttachAudioStreamProcessor"]
-- opaque AttachAudioStreamProcessor : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | stream : AudioStream
--   | processor : AudioCallback
-- -/
-- /-- Detach audio stream processor from stream -/
-- @[extern "lean_raylib__DetachAudioStreamProcessor"]
-- opaque DetachAudioStreamProcessor : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | stream : AudioStream
--   | processor : AudioCallback
-- -/

end Raylib
