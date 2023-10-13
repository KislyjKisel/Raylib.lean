import Pod.BytesView
import Pod.Buffer
import Raymath.Core
import Raylib.Aliases
import Raylib.Callbacks
import Raylib.Enumerations
import Raylib.Structures
import Raylib.Util

open Pod (Float32 Int32)
open Raymath (Vector2 Vector3 Vector4 Matrix)

namespace Raylib

/-- Initialize window and OpenGL context -/
@[extern "lean_raylib__InitWindow"]
opaque initWindow (width : UInt32) (height : UInt32) (title : String) : IO Context

/-- Check if `KeyboardKey.escape` pressed or Close icon pressed -/
@[extern "lean_raylib__WindowShouldClose"]
opaque windowShouldClose : BaseIO Bool

/--
Close window and unload OpenGL context.
If there are any values that need the context to be destroyed,
nothing happens until their finalization.
-/
@[extern "lean_raylib__CloseWindow"]
opaque closeWindow (ctx : Context) : BaseIO Unit

/-- Check if window has been initialized successfully -/
@[extern "lean_raylib__IsWindowReady"]
opaque isWindowReady : BaseIO Bool

/-- Check if window is currently fullscreen -/
@[extern "lean_raylib__IsWindowFullscreen"]
opaque isWindowFullscreen : BaseIO Bool

/-- Check if window is currently hidden (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__IsWindowHidden"]
opaque isWindowHidden : BaseIO Bool

/-- Check if window is currently minimized (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__IsWindowMinimized"]
opaque isWindowMinimized : BaseIO Bool

/-- Check if window is currently maximized (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__IsWindowMaximized"]
opaque isWindowMaximized : BaseIO Bool

/-- Check if window is currently focused (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__IsWindowFocused"]
opaque isWindowFocused : BaseIO Bool

/-- Check if window has been resized last frame -/
@[extern "lean_raylib__IsWindowResized"]
opaque isWindowResized : BaseIO Bool

/-- Check if one specific window flag is enabled -/
@[extern "lean_raylib__IsWindowState"]
opaque isWindowState (flag : ConfigFlags) : BaseIO Bool

/-- Set window configuration state using flags (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowState"]
opaque setWindowState (flags : ConfigFlags) : BaseIO Unit

/-- Clear window configuration state flags -/
@[extern "lean_raylib__ClearWindowState"]
opaque clearWindowState (flags : ConfigFlags) : BaseIO Unit

/-- Toggle window state: fullscreen/windowed (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__ToggleFullscreen"]
opaque toggleFullscreen : BaseIO Unit

/-- Set window state: maximized, if resizable (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__MaximizeWindow"]
opaque maximizeWindow : BaseIO Unit

/-- Set window state: minimized, if resizable (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__MinimizeWindow"]
opaque minimizeWindow : BaseIO Unit

/-- Set window state: not minimized/maximized (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__RestoreWindow"]
opaque restoreWindow : BaseIO Unit

/-- Set icon for window (single image, RGBA 32bit, only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowIcon"]
opaque setWindowIcon (image : @& Image) : BaseIO Unit

/-- Set icon for window (multiple images, RGBA 32bit, only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowIcons"]
opaque setWindowIcons (images : @& Array Image) : BaseIO Unit

/-- Set title for window (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowTitle"]
opaque setWindowTitle (title : String) : BaseIO Unit

/-- Set window position on screen (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowPosition"]
opaque setWindowPosition (x : Int32) (y : Int32) : BaseIO Unit

/-- Set monitor for the current window (fullscreen mode) -/
@[extern "lean_raylib__SetWindowMonitor"]
opaque setWindowMonitor (monitor : Int32) : BaseIO Unit

/-- Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE) -/
@[extern "lean_raylib__SetWindowMinSize"]
opaque setWindowMinSize (width : UInt32) (height : UInt32) : BaseIO Unit

/-- Set window dimensions -/
@[extern "lean_raylib__SetWindowSize"]
opaque setWindowSize (width : UInt32) (height : UInt32) : BaseIO Unit

/-- Set window opacity [0.0f..1.0f] (only PLATFORM_DESKTOP) -/
@[extern "lean_raylib__SetWindowOpacity"]
opaque setWindowOpacity (opacity : Float32) : BaseIO Unit

/-- Get native window handle -/
@[extern "lean_raylib__GetWindowHandle"]
opaque getWindowHandle : BaseIO WindowHandle

/-- Get current screen width -/
@[extern "lean_raylib__GetScreenWidth"]
opaque getScreenWidth : BaseIO UInt32

/-- Get current screen height -/
@[extern "lean_raylib__GetScreenHeight"]
opaque getScreenHeight : BaseIO UInt32

/-- Get current render width (it considers HiDPI) -/
@[extern "lean_raylib__GetRenderWidth"]
opaque getRenderWidth : BaseIO UInt32

/-- Get current render height (it considers HiDPI) -/
@[extern "lean_raylib__GetRenderHeight"]
opaque getRenderHeight : BaseIO UInt32

/-- Get number of connected monitors -/
@[extern "lean_raylib__GetMonitorCount"]
opaque getMonitorCount : BaseIO UInt32

/-- Get current connected monitor -/
@[extern "lean_raylib__GetCurrentMonitor"]
opaque getCurrentMonitor : BaseIO UInt32

/-- Get specified monitor position -/
@[extern "lean_raylib__GetMonitorPosition"]
opaque getMonitorPosition (monitor : UInt32) : BaseIO Vector2

/-- Get specified monitor width (current video mode used by monitor) -/
@[extern "lean_raylib__GetMonitorWidth"]
opaque getMonitorWidth (monitor : UInt32) : BaseIO UInt32

/-- Get specified monitor height (current video mode used by monitor) -/
@[extern "lean_raylib__GetMonitorHeight"]
opaque getMonitorHeight (monitor : UInt32) : BaseIO UInt32

/-- Get specified monitor physical width in millimetres -/
@[extern "lean_raylib__GetMonitorPhysicalWidth"]
opaque getMonitorPhysicalWidth (monitor : UInt32) : BaseIO UInt32

/-- Get specified monitor physical height in millimetres -/
@[extern "lean_raylib__GetMonitorPhysicalHeight"]
opaque getMonitorPhysicalHeight (monitor : UInt32) : BaseIO UInt32

/-- Get specified monitor refresh rate -/
@[extern "lean_raylib__GetMonitorRefreshRate"]
opaque getMonitorRefreshRate (monitor : UInt32) : BaseIO UInt32

/-- Get window position XY on monitor -/
@[extern "lean_raylib__GetWindowPosition"]
opaque getWindowPosition : BaseIO Vector2

/-- Get window scale DPI factor -/
@[extern "lean_raylib__GetWindowScaleDPI"]
opaque getWindowScaleDPI : BaseIO Vector2

/-- Get the human-readable, UTF-8 encoded name of the primary monitor -/
@[extern "lean_raylib__GetMonitorName"]
opaque getMonitorName (monitor : Int32) : BaseIO String

/-- Set clipboard text content -/
@[extern "lean_raylib__SetClipboardText"]
opaque setClipboardText (text : String) : BaseIO Unit

/-- Get clipboard text content -/
@[extern "lean_raylib__GetClipboardText"]
opaque getClipboardText : BaseIO String

/-- Enable waiting for events on EndDrawing(), no automatic event polling -/
@[extern "lean_raylib__EnableEventWaiting"]
opaque enableEventWaiting : BaseIO Unit

/-- Disable waiting for events on EndDrawing(), automatic events polling -/
@[extern "lean_raylib__DisableEventWaiting"]
opaque disableEventWaiting : BaseIO Unit

/-- Swap back buffer with front buffer (screen drawing) -/
@[extern "lean_raylib__SwapScreenBuffer"]
opaque swapScreenBuffer : BaseIO Unit

/-- Register all input events -/
@[extern "lean_raylib__PollInputEvents"]
opaque pollInputEvents : BaseIO Unit

/-- Wait for some time (halt program execution) -/
@[extern "lean_raylib__WaitTime"]
opaque waitTime (seconds : Float32) : BaseIO Unit

/-- Shows cursor -/
@[extern "lean_raylib__ShowCursor"]
opaque showCursor : BaseIO Unit

/-- Hides cursor -/
@[extern "lean_raylib__HideCursor"]
opaque hideCursor : BaseIO Unit

/-- Check if cursor is not visible -/
@[extern "lean_raylib__IsCursorHidden"]
opaque isCursorHidden : BaseIO Bool

/-- Enables cursor (unlock cursor) -/
@[extern "lean_raylib__EnableCursor"]
opaque enableCursor : BaseIO Unit

/-- Disables cursor (lock cursor) -/
@[extern "lean_raylib__DisableCursor"]
opaque disableCursor : BaseIO Unit

/-- Check if cursor is on the screen -/
@[extern "lean_raylib__IsCursorOnScreen"]
opaque isCursorOnScreen : BaseIO Bool

/-- Set background color (framebuffer clear color) -/
@[extern "lean_raylib__ClearBackground"]
opaque clearBackground (color : Color) : BaseIO Unit

/-- Setup canvas (framebuffer) to start drawing -/
@[extern "lean_raylib__BeginDrawing"]
opaque beginDrawing : BaseIO Unit

/-- End canvas drawing and swap buffers (double buffering) -/
@[extern "lean_raylib__EndDrawing"]
opaque endDrawing : BaseIO Unit

/-- Begin 2D mode with custom camera (2D) -/
@[extern "lean_raylib__BeginMode2D"]
opaque beginMode2D (camera : @& Camera2D) : BaseIO Unit

/-- Ends 2D mode with custom camera -/
@[extern "lean_raylib__EndMode2D"]
opaque endMode2D : BaseIO Unit

/-- Begin 3D mode with custom camera (3D) -/
@[extern "lean_raylib__BeginMode3D"]
opaque beginMode3D (camera : @& Camera3D) : BaseIO Unit

/-- Ends 3D mode and returns to default 2D orthographic mode -/
@[extern "lean_raylib__EndMode3D"]
opaque endMode3D : BaseIO Unit

/-- Begin drawing to render texture -/
@[extern "lean_raylib__BeginTextureMode"]
opaque beginTextureMode (target : RenderTexture2D) : BaseIO Unit

/-- Ends drawing to render texture -/
@[extern "lean_raylib__EndTextureMode"]
opaque endTextureMode : BaseIO Unit

/-- Begin custom shader drawing -/
@[extern "lean_raylib__BeginShaderMode"]
opaque beginShaderMode (shader : Shader) : BaseIO Unit

/-- End custom shader drawing (use default shader) -/
@[extern "lean_raylib__EndShaderMode"]
opaque endShaderMode : BaseIO Unit

/-- Begin blending mode (alpha, additive, multiplied, subtract, custom) -/
@[extern "lean_raylib__BeginBlendMode"]
opaque beginBlendMode (mode : BlendMode) : BaseIO Unit

/-- End blending mode (reset to default: alpha blending) -/
@[extern "lean_raylib__EndBlendMode"]
opaque endBlendMode : BaseIO Unit

/-- Begin scissor mode (define screen area for following drawing) -/
@[extern "lean_raylib__BeginScissorMode"]
opaque beginScissorMode (x y width height : UInt32) : BaseIO Unit

/-- End scissor mode -/
@[extern "lean_raylib__EndScissorMode"]
opaque endScissorMode : BaseIO Unit

/-- Begin stereo rendering (requires VR simulator) -/
@[extern "lean_raylib__BeginVrStereoMode"]
opaque beginVrStereoMode (config : @& VrStereoConfig) : BaseIO Unit

/-- End stereo rendering (requires VR simulator) -/
@[extern "lean_raylib__EndVrStereoMode"]
opaque endVrStereoMode : BaseIO Unit

/-- Load VR stereo config for VR simulator device parameters -/
@[extern "lean_raylib__LoadVrStereoConfig"]
opaque loadVrStereoConfig (device : @& VrDeviceInfo) : VrStereoConfig

/-- Unload VR stereo config (no-op) -/
@[extern "lean_raylib__UnloadVrStereoConfig"]
opaque unloadVrStereoConfig (config : @& VrStereoConfig) : BaseIO Unit

/-- Load shader from files and bind default locations -/
@[extern "lean_raylib__LoadShader"]
opaque loadShader (ctx : Context) (vsFileName : @& Option String) (fsFileName : @& Option String) : BaseIO Shader

/-- Load shader from code strings and bind default locations -/
@[extern "lean_raylib__LoadShaderFromMemory"]
opaque loadShaderFromMemory (ctx : Context) (vsCode : @& Option String) (fsCode : @& Option String) : BaseIO Shader

/-- Check if a shader is ready -/
@[extern "lean_raylib__IsShaderReady"]
opaque isShaderReady (shader : @& Shader) : Bool

/-- Get shader uniform location -/
@[extern "lean_raylib__GetShaderLocation"]
opaque getShaderLocation (shader : @& Shader) (uniformName : @& String) : Option UInt32

/-- Get shader attribute location -/
@[extern "lean_raylib__GetShaderLocationAttrib"]
opaque getShaderLocationAttrib (shader : @& Shader) (attribName : @& String) : Option UInt32

/-- Set shader uniform value -/
@[extern "lean_raylib__SetShaderValue"]
opaque setShaderValue (shader : @& Shader) (locIndex : UInt32) (type : ShaderUniformDataType) (value : @& type.lift) : BaseIO Unit

/-- Set shader uniform value vector -/
@[extern "lean_raylib__SetShaderValueV"]
opaque setShaderValueV (shader : @& Shader) (locIndex : UInt32) (type : ShaderUniformDataType) (values : @& Array type.lift) : BaseIO Unit

/-- Set shader uniform value (matrix 4x4) -/
@[extern "lean_raylib__SetShaderValueMatrix"]
opaque setShaderValueMatrix (shader : @& Shader) (locIndex : UInt32) (mat : @& Matrix) : BaseIO Unit

/-- Set shader uniform value for texture (sampler2d) -/
@[extern "lean_raylib__SetShaderValueTexture"]
opaque setShaderValueTexture (shader : @& Shader) (locIndex : UInt32) (texture : @& Texture2D) : BaseIO Unit

/-- Get a ray trace from mouse position -/
-- IO: uses screen size
@[extern "lean_raylib__GetMouseRay"]
opaque getMouseRay (mousePosition : @& Vector2) (camera : @& Camera) : BaseIO Ray

/-- Get camera transform matrix (view matrix) -/
@[extern "lean_raylib__GetCameraMatrix"]
opaque getCameraMatrix (camera : @& Camera) : Matrix

/-- Get camera 2d transform matrix -/
@[extern "lean_raylib__GetCameraMatrix2D"]
opaque getCameraMatrix2D (camera : @& Camera2D) : Matrix

/-- Get the screen space position for a 3d world space position -/
-- IO: uses screen size
@[extern "lean_raylib__GetWorldToScreen"]
opaque getWorldToScreen (position : @& Vector3) (camera : @& Camera) : BaseIO Vector2

/-- Get the world space position for a 2d camera screen space position -/
@[extern "lean_raylib__GetScreenToWorld2D"]
opaque getScreenToWorld2D (position : @& Vector2) (camera : @& Camera2D) : Vector2

/-- Get size position for a 3d world space position -/
-- IO: uses screen size
@[extern "lean_raylib__GetWorldToScreenEx"]
opaque getWorldToScreenEx (position : @& Vector3) (camera : @& Camera) (width : UInt32) (height : UInt32) : BaseIO Vector2

/-- Get the screen space position for a 2d camera world space position -/
@[extern "lean_raylib__GetWorldToScreen2D"]
opaque getWorldToScreen2D (position : @& Vector2) (camera : @& Camera2D) : Vector2

/-- Set target FPS (maximum) -/
@[extern "lean_raylib__SetTargetFPS"]
opaque setTargetFPS (fps : UInt32) : BaseIO Unit

/-- Get current FPS -/
@[extern "lean_raylib__GetFPS"]
opaque getFPS : BaseIO UInt32

/-- Get time in seconds for last frame drawn (delta time) -/
@[extern "lean_raylib__GetFrameTime"]
opaque getFrameTime : BaseIO Float32

/-- Get elapsed time in seconds since InitWindow() -/
@[extern "lean_raylib__GetTime"]
opaque getTime : BaseIO Float32

/-- Get a random value between min and max (both included) -/
@[extern "lean_raylib__GetRandomValue"]
opaque getRandomValue (min : Int32) (max : Int32) : BaseIO Int32

/-- Set the seed for the random number generator -/
@[extern "lean_raylib__SetRandomSeed"]
opaque setRandomSeed (seed : UInt32) : BaseIO Unit

/-- Takes a screenshot of current screen (filename extension defines format) -/
@[extern "lean_raylib__TakeScreenshot"]
opaque takeScreenshot (fileName : String) : BaseIO Unit

/-- Setup init configuration flags (view FLAGS) -/
@[extern "lean_raylib__SetConfigFlags"]
opaque setConfigFlags (flags : ConfigFlags) : BaseIO Unit

/--
Show trace log messages (`debug`, `info`, `warning`, `error`...).
Throws error on strings containing `%` not followed by another `%`.
May still cause UB when used with redirected TraceLog that uses variadic arguments.
-/
@[extern "lean_raylib__TraceLog"]
opaque traceLog (logLevel : TraceLogLevel) (text : @& String) : IO Unit

/-- Set the current threshold (minimum) log level -/
@[extern "lean_raylib__SetTraceLogLevel"]
opaque setTraceLogLevel (logLevel : TraceLogLevel) : BaseIO Unit

/--
Internal memory allocator.
NOTE: Initializes to zero by default.
-/
@[extern "lean_raylib__MemAlloc"]
opaque memAlloc (size : @& Nat) : Pod.Buffer size 1

/--
Internal memory reallocator.
NOTE: Clones the buffer using `memAlloc` if it wasn't allocated using the same allocator or if it's shared.
-/
@[extern "lean_raylib__MemRealloc"]
opaque memRealloc {size₁ : @& Nat} (buf : Pod.Buffer size₁ 1) (size : @& Nat) : Pod.Buffer size 1

/-- Open URL with default system browser (if available) -/
@[extern "lean_raylib__OpenURL"]
opaque openURL (url : @& String) : BaseIO Unit

/-- Set custom trace log -/
@[extern "lean_raylib__SetTraceLogCallback"]
opaque setTraceLogCallback (callback : TraceLogCallback) : BaseIO Unit

/-- Reset default trace log -/
@[extern "lean_raylib__ResetTraceLogCallback"]
opaque resetTraceLogCallback : BaseIO Unit

/-- Set custom file binary data loader -/
@[extern "lean_raylib__SetLoadFileDataCallback"]
opaque setLoadFileDataCallback (callback : LoadFileDataCallback) : BaseIO Unit

/-- Reset default file binary data loader -/
@[extern "lean_raylib__ResetLoadFileDataCallback"]
opaque resetLoadFileDataCallback : BaseIO Unit

/-- Set custom file binary data saver -/
@[extern "lean_raylib__SetSaveFileDataCallback"]
opaque setSaveFileDataCallback (callback : SaveFileDataCallback) : BaseIO Unit

/-- Reset default file binary data saver -/
@[extern "lean_raylib__ResetSaveFileDataCallback"]
opaque resetSaveFileDataCallback : BaseIO Unit

/-- Set custom file text data loader -/
@[extern "lean_raylib__SetLoadFileTextCallback"]
opaque setLoadFileTextCallback (callback : LoadFileTextCallback) : BaseIO Unit

/-- Reset default file text data loader -/
@[extern "lean_raylib__ResetLoadFileTextCallback"]
opaque resetLoadFileTextCallback : BaseIO Unit

/-- Set custom file text data saver -/
@[extern "lean_raylib__SetSaveFileTextCallback"]
opaque setSaveFileTextCallback (callback : SaveFileTextCallback) : BaseIO Unit

/-- Reset default file text data saver -/
@[extern "lean_raylib__ResetSaveFileTextCallback"]
opaque resetSaveFileTextCallback : BaseIO Unit

/-- Load file data as byte array (read) -/
@[extern "lean_raylib__LoadFileData"]
opaque loadFileData (fileName : @& String) : BaseIO ByteArray

/-- Save data to file from byte array (write), returns true on success -/
@[extern "lean_raylib__SaveFileData"]
opaque saveFileData (fileName : @& String) {size} (data : @& Pod.BytesView size 1) : BaseIO Bool

/-- Export data to code (.h), returns true on success -/
@[extern "lean_raylib__ExportDataAsCode"]
opaque exportDataAsCode {size} (data : @& Pod.BytesView size 1) (fileName : @& String) : BaseIO Bool

/-- Load text data from file (read), returns a ~~'\0' terminated~~ string -/
@[extern "lean_raylib__LoadFileText"]
opaque loadFileText (fileName : @& String) : BaseIO String

/-- Save text data to file (write), ~~string must be '\0' terminated~~, returns true on success -/
@[extern "lean_raylib__SaveFileText"]
opaque saveFileText (fileName : @& String) (text : @& String) : BaseIO Bool

/-- Check if file exists -/
@[extern "lean_raylib__FileExists"]
opaque fileExists (fileName : @& String) : BaseIO Bool

/-- Check if a directory path exists -/
@[extern "lean_raylib__DirectoryExists"]
opaque directoryExists (dirPath : @& String) : BaseIO Bool

/--
Check file extension (including point: .png, .wav)
NOTE: Extensions checking is not case-sensitive.
-/
@[extern "lean_raylib__IsFileExtension"]
opaque isFileExtension (fileName : @& String) (ext : @& String) : Bool

/--
Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h).
Returns `0` on error (ex. file doesn't exist).
-/
@[extern "lean_raylib__GetFileLength"]
opaque getFileLength (fileName : @& String) : BaseIO UInt32

/-- Get pointer to extension for a filename string (includes dot: '.png') -/
@[extern "lean_raylib__GetFileExtension"]
opaque getFileExtension (fileName : @& String) : Option USize

/-- Get pointer to filename for a path string -/
@[extern "lean_raylib__GetFileName"]
opaque getFileName (filePath : @& String) : USize

/--
Get filename string without extension (uses static string).
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetFileNameWithoutExt"]
opaque getFileNameWithoutExt (filePath : @& String) : String

/--
Get full path for a given fileName with path (uses static string).
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetDirectoryPath"]
opaque getDirectoryPath (filePath : @& String) : String

/--
Get previous directory path for a given path (uses static string).
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetPrevDirectoryPath"]
opaque getPrevDirectoryPath (dirPath : @& String) : String

/--
Get current working directory (uses static string)
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetWorkingDirectory"]
opaque getWorkingDirectory : BaseIO String

/--
Get the directory if the running application (uses static string).
THREAD-UNSAFE: static local
-/
@[extern "lean_raylib__GetApplicationDirectory"]
opaque getApplicationDirectory : BaseIO String

/-- Change working directory, return true on success -/
@[extern "lean_raylib__ChangeDirectory"]
opaque changeDirectory (dir : @& String) : BaseIO Bool

/-- Check if a given path is a file or a directory -/
@[extern "lean_raylib__IsPathFile"]
opaque isPathFile (path : @& String) : BaseIO Bool

/-- Load directory filepaths -/
@[extern "lean_raylib__LoadDirectoryFiles"]
opaque loadDirectoryFiles (dirPath : @& String) : BaseIO $ Array String

/-- Load directory filepaths with extension filtering and recursive directory scan -/
@[extern "lean_raylib__LoadDirectoryFilesEx"]
opaque loadDirectoryFilesEx (basePath : @& String) (filter : @& String) (scanSubdirs : Bool) : BaseIO $ Array String

/-- Check if a file has been dropped into window -/
@[extern "lean_raylib__IsFileDropped"]
opaque isFileDropped : BaseIO Bool

/-- Load dropped filepaths -/
@[extern "lean_raylib__LoadDroppedFiles"]
opaque loadDroppedFiles : BaseIO $ Array String

/--
Get file modification time (last write time).
Returns `0` on error (ex. file doesn't exist).
-/
@[extern "lean_raylib__GetFileModTime"]
opaque getFileModTime (fileName : @& String) : BaseIO UInt64

/-- Compress data (DEFLATE algorithm) -/
@[extern "lean_raylib__CompressData"]
opaque compressData {size} (data : @& Pod.BytesView size 1) : ByteArray

/-- Compress data (DEFLATE algorithm) -/
@[extern "lean_raylib__CompressDataST"]
opaque compressDataST {σ size} (data : @& Pod.BytesRefImm σ size 1) : ST σ ByteArray

/-- Decompress data (DEFLATE algorithm) -/
@[extern "lean_raylib__DecompressData"]
opaque decompressData {size} (compData : @& Pod.BytesView size 1) : ByteArray

/-- Encode data to Base64 string -/
@[extern "lean_raylib__EncodeDataBase64"]
opaque encodeDataBase64 {size} (data : @& Pod.BytesView size 1) : String

/-- Encode data to Base64 string -/
@[extern "lean_raylib__EncodeDataBase64ST"]
opaque encodeDataBase64ST {σ size} (data : @& Pod.BytesRefImm σ size 1) : ST σ String

/-- Decode Base64 string data -/
@[extern "lean_raylib__DecodeDataBase64"]
opaque decodeDataBase64 (code : @& String) : ByteArray

/-- Check if a key has been pressed once -/
@[extern "lean_raylib__IsKeyPressed"]
opaque isKeyPressed (key : KeyboardKey) : BaseIO Bool

/-- Check if a key is being pressed -/
@[extern "lean_raylib__IsKeyDown"]
opaque isKeyDown (key : KeyboardKey) : BaseIO Bool

/-- Check if a key has been released once -/
@[extern "lean_raylib__IsKeyReleased"]
opaque isKeyReleased (key : KeyboardKey) : BaseIO Bool

/-- Check if a key is NOT being pressed -/
@[extern "lean_raylib__IsKeyUp"]
opaque isKeyUp (key : KeyboardKey) : BaseIO Bool

/-- Set a custom key to exit program (default is ESC) -/
@[extern "lean_raylib__SetExitKey"]
opaque setExitKey (key : KeyboardKey) : BaseIO Unit

/-- Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty -/
@[extern "lean_raylib__GetKeyPressed"]
opaque getKeyPressed : BaseIO KeyboardKey

/-- Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty -/
@[extern "lean_raylib__GetCharPressed"]
opaque getCharPressed : BaseIO Char

/-- Check if a gamepad is available -/
@[extern "lean_raylib__IsGamepadAvailable"]
opaque isGamepadAvailable (gamepad : UInt32) : BaseIO Bool

/-- Get gamepad internal name id -/
@[extern "lean_raylib__GetGamepadName"]
opaque getGamepadName (gamepad : UInt32) : BaseIO String

/-- Check if a gamepad button has been pressed once -/
@[extern "lean_raylib__IsGamepadButtonPressed"]
opaque isGamepadButtonPressed (gamepad : UInt32) (button : GamepadButton) : BaseIO Bool

/-- Check if a gamepad button is being pressed -/
@[extern "lean_raylib__IsGamepadButtonDown"]
opaque isGamepadButtonDown (gamepad : UInt32) (button : GamepadButton) : BaseIO Bool

/-- Check if a gamepad button has been released once -/
@[extern "lean_raylib__IsGamepadButtonReleased"]
opaque isGamepadButtonReleased (gamepad : UInt32) (button : GamepadButton) : BaseIO Bool

/-- Check if a gamepad button is NOT being pressed -/
@[extern "lean_raylib__IsGamepadButtonUp"]
opaque isGamepadButtonUp (gamepad : UInt32) (button : GamepadButton) : BaseIO Bool

/-- Get the last gamepad button pressed -/
@[extern "lean_raylib__GetGamepadButtonPressed"]
opaque getGamepadButtonPressed : BaseIO GamepadButton

/-- Get gamepad axis count for a gamepad -/
@[extern "lean_raylib__GetGamepadAxisCount"]
opaque getGamepadAxisCount (gamepad : UInt32) : BaseIO UInt32

/-- Get axis movement value for a gamepad axis -/
@[extern "lean_raylib__GetGamepadAxisMovement"]
opaque getGamepadAxisMovement (gamepad : UInt32) (axis : UInt32) : BaseIO Float32

/-- Set internal gamepad mappings (SDL_GameControllerDB) -/
@[extern "lean_raylib__SetGamepadMappings"]
opaque setGamepadMappings (mappings : String) : BaseIO Bool

/-- Check if a mouse button has been pressed once -/
@[extern "lean_raylib__IsMouseButtonPressed"]
opaque isMouseButtonPressed (button : MouseButton) : BaseIO Bool

/-- Check if a mouse button is being pressed -/
@[extern "lean_raylib__IsMouseButtonDown"]
opaque isMouseButtonDown (button : MouseButton) : BaseIO Bool

/-- Check if a mouse button has been released once -/
@[extern "lean_raylib__IsMouseButtonReleased"]
opaque isMouseButtonReleased (button : MouseButton) : BaseIO Bool

/-- Check if a mouse button is NOT being pressed -/
@[extern "lean_raylib__IsMouseButtonUp"]
opaque isMouseButtonUp (button : MouseButton) : BaseIO Bool

/-- Get mouse position X -/
@[extern "lean_raylib__GetMouseX"]
opaque getMouseX : BaseIO Int32

/-- Get mouse position Y -/
@[extern "lean_raylib__GetMouseY"]
opaque getMouseY : BaseIO Int32

/-- Get mouse position XY -/
@[extern "lean_raylib__GetMousePosition"]
opaque getMousePosition : BaseIO Vector2

/-- Get mouse delta between frames -/
@[extern "lean_raylib__GetMouseDelta"]
opaque getMouseDelta : BaseIO Vector2

/-- Set mouse position XY -/
@[extern "lean_raylib__SetMousePosition"]
opaque setMousePosition (x : Int32) (y : Int32) : BaseIO Unit

/-- Set mouse offset -/
@[extern "lean_raylib__SetMouseOffset"]
opaque setMouseOffset (offsetX : Int32) (offsetY : Int32) : BaseIO Unit

/-- Set mouse scaling -/
@[extern "lean_raylib__SetMouseScale"]
opaque setMouseScale (scaleX : Float32) (scaleY : Float32) : BaseIO Unit

/-- Get mouse wheel movement for X or Y, whichever is larger -/
@[extern "lean_raylib__GetMouseWheelMove"]
opaque getMouseWheelMove : BaseIO Float32

/-- Get mouse wheel movement for both X and Y -/
@[extern "lean_raylib__GetMouseWheelMoveV"]
opaque getMouseWheelMoveV : BaseIO Vector2

/-- Set mouse cursor -/
@[extern "lean_raylib__SetMouseCursor"]
opaque setMouseCursor (cursor : MouseCursor) : BaseIO Unit

/-- Get touch position X for touch point 0 (relative to screen size) -/
@[extern "lean_raylib__GetTouchX"]
opaque getTouchX : BaseIO Int32

/-- Get touch position Y for touch point 0 (relative to screen size) -/
@[extern "lean_raylib__GetTouchY"]
opaque getTouchY : BaseIO Int32

/-- Get touch position XY for a touch point index (relative to screen size) -/
@[extern "lean_raylib__GetTouchPosition"]
opaque getTouchPosition (index : UInt32) : BaseIO Vector2

/-- Get touch point identifier for given index -/
@[extern "lean_raylib__GetTouchPointId"]
opaque getTouchPointId (index : UInt32) : BaseIO Int32

/-- Get number of touch points -/
@[extern "lean_raylib__GetTouchPointCount"]
opaque getTouchPointCount : BaseIO UInt32

/-- Enable a set of gestures using flags -/
@[extern "lean_raylib__SetGesturesEnabled"]
opaque setGesturesEnabled (flags : GestureFlags) : BaseIO Unit

/-- Check if a gesture have been detected -/
@[extern "lean_raylib__IsGestureDetected"]
opaque isGestureDetected (gesture : Gesture) : BaseIO Bool

/-- Get latest detected gesture -/
@[extern "lean_raylib__GetGestureDetected"]
opaque getGestureDetected : BaseIO Gesture

/-- Get gesture hold time in milliseconds -/
@[extern "lean_raylib__GetGestureHoldDuration"]
opaque getGestureHoldDuration : BaseIO Float32

/-- Get gesture drag vector -/
@[extern "lean_raylib__GetGestureDragVector"]
opaque getGestureDragVector : BaseIO Vector2

/-- Get gesture drag angle -/
@[extern "lean_raylib__GetGestureDragAngle"]
opaque getGestureDragAngle : BaseIO Float32

/-- Get gesture pinch delta -/
@[extern "lean_raylib__GetGesturePinchVector"]
opaque getGesturePinchVector : BaseIO Vector2

/-- Get gesture pinch angle -/
@[extern "lean_raylib__GetGesturePinchAngle"]
opaque getGesturePinchAngle : BaseIO Float32

/-- Update camera position for selected mode -/
@[extern "lean_raylib__UpdateCamera"]
opaque updateCamera (cam : Camera) (mode : CameraMode) : BaseIO Camera

/-- Update camera movement/rotation -/
@[extern "lean_raylib__UpdateCameraPro"]
opaque updateCameraPro (cam : Camera) (movement rotation : @& Vector3) (zoom : Float32) : BaseIO Camera

/-- Set texture and rectangle to be used on shapes drawing -/
@[extern "lean_raylib__SetShapesTexture"]
opaque setShapesTexture (texture : Texture2DRef) (source : @& Rectangle) : BaseIO Unit

/-- Draw a pixel -/
@[extern "lean_raylib__DrawPixel"]
opaque drawPixel (posX : Int32) (posY : Int32) (color : Color) : BaseIO Unit

/-- Draw a pixel (Vector version) -/
@[extern "lean_raylib__DrawPixelV"]
opaque drawPixelV (position : Vector2) (color : Color) : BaseIO Unit

/-- Draw a line -/
@[extern "lean_raylib__DrawLine"]
opaque drawLine (startPosX : Int32) (startPosY : Int32) (endPosX : Int32) (endPosY : Int32) (color : Color) : BaseIO Unit

/-- Draw a line (Vector version) -/
@[extern "lean_raylib__DrawLineV"]
opaque drawLineV (startPos : Vector2) (endPos : Vector2) (color : Color) : BaseIO Unit

/-- Draw a line defining thickness -/
@[extern "lean_raylib__DrawLineEx"]
opaque drawLineEx (startPos : Vector2) (endPos : Vector2) (thick : Float32) (color : Color) : BaseIO Unit

/-- Draw a line using cubic-bezier curves in-out -/
@[extern "lean_raylib__DrawLineBezier"]
opaque drawLineBezier (startPos : Vector2) (endPos : Vector2) (thick : Float32) (color : Color) : BaseIO Unit

/-- Draw line using quadratic bezier curves with a control point -/
@[extern "lean_raylib__DrawLineBezierQuad"]
opaque drawLineBezierQuad (startPos : Vector2) (endPos : Vector2) (controlPos : Vector2) (thick : Float32) (color : Color) : BaseIO Unit

/-- Draw line using cubic bezier curves with 2 control points -/
@[extern "lean_raylib__DrawLineBezierCubic"]
opaque drawLineBezierCubic (startPos : Vector2) (endPos : Vector2) (startControlPos : Vector2) (endControlPos : Vector2) (thick : Float32) (color : Color) : BaseIO Unit

/-- Draw lines sequence -/
@[extern "lean_raylib__DrawLineStrip"]
opaque drawLineStrip (points : @& Array Vector2) (color : Color) : BaseIO Unit

/-- Draw a color-filled circle -/
@[extern "lean_raylib__DrawCircle"]
opaque drawCircle (centerX : Int32) (centerY : Int32) (radius : Float32) (color : Color) : BaseIO Unit

/-- Draw a piece of a circle -/
@[extern "lean_raylib__DrawCircleSector"]
opaque drawCircleSector (center : @& Vector2) (radius : Float32) (startAngle : Float32) (endAngle : Float32) (segments : UInt32) (color : Color) : BaseIO Unit

/-- Draw circle sector outline -/
@[extern "lean_raylib__DrawCircleSectorLines"]
opaque drawCircleSectorLines (center : @& Vector2) (radius : Float32) (startAngle : Float32) (endAngle : Float32) (segments : UInt32) (color : Color) : BaseIO Unit

/-- Draw a gradient-filled circle -/
@[extern "lean_raylib__DrawCircleGradient"]
opaque drawCircleGradient (centerX : Int32) (centerY : Int32) (radius : Float32) (color1 : Color) (color2 : Color) : BaseIO Unit

/-- Draw a color-filled circle (Vector version) -/
@[extern "lean_raylib__DrawCircleV"]
opaque drawCircleV (center : @& Vector2) (radius : Float32) (color : Color) : BaseIO Unit

/-- Draw circle outline -/
@[extern "lean_raylib__DrawCircleLines"]
opaque drawCircleLines (centerX : Int32) (centerY : Int32) (radius : Float32) (color : Color) : BaseIO Unit

/-- Draw ellipse -/
@[extern "lean_raylib__DrawEllipse"]
opaque drawEllipse (centerX : Int32) (centerY : Int32) (radiusH : Float32) (radiusV : Float32) (color : Color) : BaseIO Unit

/-- Draw ellipse outline -/
@[extern "lean_raylib__DrawEllipseLines"]
opaque drawEllipseLines (centerX : Int32) (centerY : Int32) (radiusH : Float32) (radiusV : Float32) (color : Color) : BaseIO Unit

/-- Draw ring -/
@[extern "lean_raylib__DrawRing"]
opaque drawRing (center : @& Vector2) (innerRadius : Float32) (outerRadius : Float32) (startAngle : Float32) (endAngle : Float32) (segments : UInt32) (color : Color) : BaseIO Unit

/-- Draw ring outline -/
@[extern "lean_raylib__DrawRingLines"]
opaque drawRingLines (center : @& Vector2) (innerRadius : Float32) (outerRadius : Float32) (startAngle : Float32) (endAngle : Float32) (segments : UInt32) (color : Color) : BaseIO Unit

/-- Draw a color-filled rectangle -/
@[extern "lean_raylib__DrawRectangle"]
opaque drawRectangle (posX : Int32) (posY : Int32) (width : Int32) (height : Int32) (color : Color) : BaseIO Unit

/-- Draw a color-filled rectangle (Vector version) -/
@[extern "lean_raylib__DrawRectangleV"]
opaque drawRectangleV (position : @& Vector2) (size : @& Vector2) (color : Color) : BaseIO Unit

/-- Draw a color-filled rectangle -/
@[extern "lean_raylib__DrawRectangleRec"]
opaque drawRectangleRec (rec : @& Rectangle) (color : Color) : BaseIO Unit

/-- Draw a color-filled rectangle with pro parameters -/
@[extern "lean_raylib__DrawRectanglePro"]
opaque drawRectanglePro (rec : @& Rectangle) (origin : @& Vector2) (rotation : Float32) (color : Color) : BaseIO Unit

/-- Draw a vertical-gradient-filled rectangle -/
@[extern "lean_raylib__DrawRectangleGradientV"]
opaque drawRectangleGradientV (posX : Int32) (posY : Int32) (width : Int32) (height : Int32) (color1 : Color) (color2 : Color) : BaseIO Unit

/-- Draw a horizontal-gradient-filled rectangle -/
@[extern "lean_raylib__DrawRectangleGradientH"]
opaque drawRectangleGradientH (posX : Int32) (posY : Int32) (width : Int32) (height : Int32) (color1 : Color) (color2 : Color) : BaseIO Unit

/-- Draw a gradient-filled rectangle with custom vertex colors -/
@[extern "lean_raylib__DrawRectangleGradientEx"]
opaque drawRectangleGradientEx (rec : @& Rectangle) (col1 : Color) (col2 : Color) (col3 : Color) (col4 : Color) : BaseIO Unit

/-- Draw rectangle outline -/
@[extern "lean_raylib__DrawRectangleLines"]
opaque drawRectangleLines (posX : Int32) (posY : Int32) (width : Int32) (height : Int32) (color : Color) : BaseIO Unit

/-- Draw rectangle outline with extended parameters -/
@[extern "lean_raylib__DrawRectangleLinesEx"]
opaque drawRectangleLinesEx (rec : @& Rectangle) (lineThick : Float32) (color : Color) : BaseIO Unit

/-- Draw rectangle with rounded edges -/
@[extern "lean_raylib__DrawRectangleRounded"]
opaque drawRectangleRounded (rec : @& Rectangle) (roundness : Float32) (segments : UInt32) (color : Color) : BaseIO Unit

/-- Draw rectangle with rounded edges outline -/
@[extern "lean_raylib__DrawRectangleRoundedLines"]
opaque drawRectangleRoundedLines (rec : @& Rectangle) (roundness : Float32) (segments : UInt32) (lineThick : Float32) (color : Color) : BaseIO Unit

/-- Draw a color-filled triangle (vertex in counter-clockwise order!) -/
@[extern "lean_raylib__DrawTriangle"]
opaque drawTriangle (v1 : @& Vector2) (v2 : @& Vector2) (v3 : @& Vector2) (color : Color) : BaseIO Unit

/-- Draw triangle outline (vertex in counter-clockwise order!) -/
@[extern "lean_raylib__DrawTriangleLines"]
opaque drawTriangleLines (v1 : @& Vector2) (v2 : @& Vector2) (v3 : @& Vector2) (color : Color) : BaseIO Unit

/-- Draw a triangle fan defined by points (first vertex is the center) -/
@[extern "lean_raylib__DrawTriangleFan"]
opaque drawTriangleFan (points : @& Array Vector2) (color : Color) : BaseIO Unit

/-- Draw a triangle strip defined by points -/
@[extern "lean_raylib__DrawTriangleStrip"]
opaque drawTriangleStrip (points : @& Array Vector2) (color : Color) : BaseIO Unit

/-- Draw a regular polygon (Vector version) -/
@[extern "lean_raylib__DrawPoly"]
opaque drawPoly (center : @& Vector2) (sides : UInt32) (radius : Float32) (rotation : Float32) (color : Color) : BaseIO Unit

/-- Draw a polygon outline of n sides -/
@[extern "lean_raylib__DrawPolyLines"]
opaque drawPolyLines (center : @& Vector2) (sides : UInt32) (radius : Float32) (rotation : Float32) (color : Color) : BaseIO Unit

/-- Draw a polygon outline of n sides with extended parameters -/
@[extern "lean_raylib__DrawPolyLinesEx"]
opaque drawPolyLinesEx (center : @& Vector2) (sides : UInt32) (radius : Float32) (rotation : Float32) (lineThick : Float32) (color : Color) : BaseIO Unit

/-- Check collision between two rectangles -/
@[extern "lean_raylib__CheckCollisionRecs"]
opaque checkCollisionRecs (rec1 : @& Rectangle) (rec2 : @& Rectangle) : Bool

/-- Check collision between two circles -/
@[extern "lean_raylib__CheckCollisionCircles"]
opaque checkCollisionCircles (center1 : @& Vector2) (radius1 : Float32) (center2 : @& Vector2) (radius2 : Float32) : Bool

/-- Check collision between circle and rectangle -/
@[extern "lean_raylib__CheckCollisionCircleRec"]
opaque checkCollisionCircleRec (center : @& Vector2) (radius : Float32) (rec : @& Rectangle) : Bool

/-- Check if point is inside rectangle -/
@[extern "lean_raylib__CheckCollisionPointRec"]
opaque checkCollisionPointRec (point : @& Vector2) (rec : @& Rectangle) : Bool

/-- Check if point is inside circle -/
@[extern "lean_raylib__CheckCollisionPointCircle"]
opaque checkCollisionPointCircle (point : @& Vector2) (center : @& Vector2) (radius : Float32) : Bool

/-- Check if point is inside a triangle -/
@[extern "lean_raylib__CheckCollisionPointTriangle"]
opaque checkCollisionPointTriangle (point : @& Vector2) (p1 : @& Vector2) (p2 : @& Vector2) (p3 : @& Vector2) : Bool

/-- Check if point is within a polygon described by array of vertices -/
@[extern "lean_raylib__CheckCollisionPointPoly"]
opaque checkCollisionPointPoly (point : @& Vector2) (points : @& Array Vector2) : Bool

/-- Check the collision between two lines defined by two points each, returns collision point by reference -/
@[extern "lean_raylib__CheckCollisionLines"]
opaque checkCollisionLines (startPos1 : @& Vector2) (endPos1 : @& Vector2) (startPos2 : @& Vector2) (endPos2 : @& Vector2) : Option Vector2

/-- Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold] -/
@[extern "lean_raylib__CheckCollisionPointLine"]
opaque checkCollisionPointLine (point : @& Vector2) (p1 : @& Vector2) (p2 : @& Vector2) (threshold : UInt32) : Bool

/-- Get collision rectangle for two rectangles collision -/
@[extern "lean_raylib__GetCollisionRec"]
opaque getCollisionRec (rec1 : @& Rectangle) (rec2 : @& Rectangle) : Rectangle

/-- Load image from file into CPU memory (RAM) -/
@[extern "lean_raylib__LoadImage"]
opaque loadImage (fileName : @& String) : BaseIO Image

/-- Load image from RAW file data -/
@[extern "lean_raylib__LoadImageRaw"]
opaque loadImageRaw
  (fileName : @& String) (width : UInt32) (height : UInt32)
  (format : PixelFormat) (headerSize : UInt32)
  : BaseIO Image

/-- Load image sequence from file (frames appended to image.data) -/
@[extern "lean_raylib__LoadImageAnim"]
opaque loadImageAnim (fileName : @& String) : BaseIO (Image × UInt32)

/-- Load image from memory buffer, fileType refers to extension: i.e. '.png' -/
@[extern "lean_raylib__LoadImageFromMemory"]
opaque loadImageFromMemory {size} (fileType : @& String) (fileData : @& Pod.BytesView size 1) : Image

/--
Load image from GPU texture data.
NOTE: Compressed texture formats not supported.
-/
@[extern "lean_raylib__LoadImageFromTexture"]
opaque loadImageFromTexture (texture : @& Texture2DRef) : BaseIO Image

/-- Load image from screen buffer and (screenshot) -/
@[extern "lean_raylib__LoadImageFromScreen"]
opaque loadImageFromScreen : BaseIO Image

/-- Check if an image is ready -/
@[extern "lean_raylib__IsImageReady"]
opaque isImageReady (image : @& Image) : Bool

/-- Export image data to file, returns true on success -/
@[extern "lean_raylib__ExportImage"]
opaque exportImage (image : @& Image) (fileName : @& String) : BaseIO Bool

/-- Export image as code file defining an array of bytes, returns true on success -/
@[extern "lean_raylib__ExportImageAsCode"]
opaque exportImageAsCode (image : @& Image) (fileName : @& String) : BaseIO Bool

/-- Generate image: plain color -/
@[extern "lean_raylib__GenImageColor"]
opaque genImageColor (width height : UInt32) (color : Color) : Image

/-- Generate image: vertical gradient -/
@[extern "lean_raylib__GenImageGradientV"]
opaque genImageGradientV (width : UInt32) (height : UInt32) (top : Color) (bottom : Color) : Image

/-- Generate image: horizontal gradient -/
@[extern "lean_raylib__GenImageGradientH"]
opaque genImageGradientH (width : UInt32) (height : UInt32) (left : Color) (right : Color) : Image

/-- Generate image: radial gradient -/
@[extern "lean_raylib__GenImageGradientRadial"]
opaque genImageGradientRadial (width : UInt32) (height : UInt32) (density : Float32) (inner : Color) (outer : Color) : Image

/-- Generate image: checked -/
@[extern "lean_raylib__GenImageChecked"]
opaque genImageChecked (width : UInt32) (height : UInt32) (checksX : Int32) (checksY : Int32) (col1 : Color) (col2 : Color) : Image

/-- Generate image: white noise -/
-- IO: Random
@[extern "lean_raylib__GenImageWhiteNoise"]
opaque genImageWhiteNoise (width : UInt32) (height : UInt32) (factor : Float32) : BaseIO Image

/-- Generate image: perlin noise -/
@[extern "lean_raylib__GenImagePerlinNoise"]
opaque genImagePerlinNoise (width : UInt32) (height : UInt32) (offsetX : Int32) (offsetY : Int32) (scale : Float32) : Image

/-- Generate image: cellular algorithm, bigger tileSize means bigger cells -/
-- IO: Random
@[extern "lean_raylib__GenImageCellular"]
opaque genImageCellular (width : UInt32) (height : UInt32) (tileSize : UInt32) : BaseIO Image

/-- Generate image: grayscale image from text data -/
@[extern "lean_raylib__GenImageText"]
opaque genImageText (width : UInt32) (height : UInt32) (text : @& String) : Image

/-- Create an image duplicate (useful for transformations) -/
@[extern "lean_raylib__ImageCopy"]
opaque imageCopy (image : @& Image) : Image

/-- Create an image from another image piece -/
@[extern "lean_raylib__ImageFromImage"]
opaque imageFromImage (image : @& Image) (rec : @& Rectangle) : Image

/-- Create an image from text (default font) -/
@[extern "lean_raylib__ImageText"]
opaque imageText (text : @& String) (fontSize : UInt32) (color : Color) : Image

/-- Create an image from text (custom sprite font) -/
@[extern "lean_raylib__ImageTextEx"]
opaque imageTextEx (font : @& Font) (text : @& String) (fontSize : Float32) (spacing : Float32) (tint : Color) : Image

/-- Convert image data to desired format -/
@[extern "lean_raylib__ImageFormat"]
opaque imageFormat (image : Image) (newFormat : PixelFormat) : Image

/-- Convert image to POT (power-of-two) -/
@[extern "lean_raylib__ImageToPOT"]
opaque imageToPOT (image : Image) (fill : Color) : Image

/-- Crop an image to a defined rectangle -/
@[extern "lean_raylib__ImageCrop"]
opaque imageCrop (image : Image) (crop : @& Rectangle) : Image

/-- Crop image depending on alpha value -/
@[extern "lean_raylib__ImageAlphaCrop"]
opaque imageAlphaCrop (image : Image) (threshold : Float32) : Image

/-- Clear alpha channel to desired color -/
@[extern "lean_raylib__ImageAlphaClear"]
opaque imageAlphaClear (image : Image) (color : Color) (threshold : Float32) : Image

/-- Apply alpha mask to image -/
@[extern "lean_raylib__ImageAlphaMask"]
opaque imageAlphaMask (image : Image) (alphaMask : @& Image) : Image

/-- Premultiply alpha channel -/
@[extern "lean_raylib__ImageAlphaPremultiply"]
opaque imageAlphaPremultiply (image : Image) : Image

/-- Apply Gaussian blur using a box blur approximation -/
@[extern "lean_raylib__ImageBlurGaussian"]
opaque imageBlurGaussian (image : Image) (blurSize : UInt32) : Image

/-- Resize image (Bicubic scaling algorithm) -/
@[extern "lean_raylib__ImageResize"]
opaque imageResize (image : Image) (newWidth : UInt32) (newHeight : UInt32) : Image

/-- Resize image (Nearest-Neighbor scaling algorithm) -/
@[extern "lean_raylib__ImageResizeNN"]
opaque imageResizeNN (image : Image) (newWidth : UInt32) (newHeight : UInt32) : Image

/-- Resize canvas and fill with color -/
@[extern "lean_raylib__ImageResizeCanvas"]
opaque imageResizeCanvas
  (image : Image)
  (newWidth : UInt32)
  (newHeight : UInt32)
  (offsetX : Int32)
  (offsetY : Int32)
  (fill : Color)
  : Image

/-- Compute all mipmap levels for a provided image -/
@[extern "lean_raylib__ImageMipmaps"]
opaque imageMipmaps (image : Image) : Image

/--
Dither image data to 16bpp or lower (Floyd-Steinberg dithering).
NOTE: In case selected bpp do not represent a known 16bit format,
dithered data is stored in the LSB part of the `UInt16`.

`rBpp + gBpp + bBpp + aBpp ≤ 16`
-/
@[extern "lean_raylib__ImageDither"]
opaque imageDither (image : Image) (rBpp : UInt32) (gBpp : UInt32) (bBpp : UInt32) (aBpp : UInt32) : Image

/-- Flip image vertically -/
@[extern "lean_raylib__ImageFlipVertical"]
opaque imageFlipVertical (image : Image) : Image

/-- Flip image horizontally -/
@[extern "lean_raylib__ImageFlipHorizontal"]
opaque imageFlipHorizontal (image : Image) : Image

/-- Rotate image clockwise 90deg -/
@[extern "lean_raylib__ImageRotateCW"]
opaque imageRotateCW (image : Image) : Image

/-- Rotate image counter-clockwise 90deg -/
@[extern "lean_raylib__ImageRotateCCW"]
opaque imageRotateCCW (image : Image) : Image

/-- Modify image color: tint -/
@[extern "lean_raylib__ImageColorTint"]
opaque imageColorTint (image : Image) (color : Color) : Image

/-- Modify image color: invert -/
@[extern "lean_raylib__ImageColorInvert"]
opaque imageColorInvert (image : Image) : Image

/-- Modify image color: grayscale -/
@[extern "lean_raylib__ImageColorGrayscale"]
opaque imageColorGrayscale (image : Image) : Image

/-- Modify image color: contrast (clamped between -100 and 100) -/
@[extern "lean_raylib__ImageColorContrast"]
opaque imageColorContrast (image : Image) (contrast : Float32) : Image

/-- Modify image color: brightness (clamped between -255 and 255) -/
@[extern "lean_raylib__ImageColorBrightness"]
opaque imageColorBrightness (image : Image) (brightness : Int32) : Image

/-- Modify image color: replace color -/
@[extern "lean_raylib__ImageColorReplace"]
opaque imageColorReplace (image : Image) (color : Color) (replace : Color) : Image

/-- Load color data from image as a Color array (RGBA - 32bit) -/
@[extern "lean_raylib__LoadImageColors"]
opaque loadImageColors (image : @& Image) : Array Color

/-- Load colors palette from image as a Color array (RGBA - 32bit) -/
@[extern "lean_raylib__LoadImagePalette"]
opaque loadImagePalette (image : @& Image) (maxPaletteSize : UInt32) : Array Color

/-- Get image alpha border rectangle -/
@[extern "lean_raylib__GetImageAlphaBorder"]
opaque getImageAlphaBorder (image : @& Image) (threshold : Float32) : Rectangle

/-- Get image pixel color at (x, y) position -/
@[extern "lean_raylib__GetImageColor"]
opaque getImageColor (image : @& Image) (x : UInt32) (y : UInt32) : Color

/-- Clear image background with given color -/
@[extern "lean_raylib__ImageClearBackground"]
opaque imageClearBackground (image : Image) (color : Color) : Image

/-- Draw pixel within an image -/
@[extern "lean_raylib__ImageDrawPixel"]
opaque imageDrawPixel (image : Image) (posX : UInt32) (posY : UInt32) (color : Color) : Image

/-- Draw pixel within an image (Vector version) -/
@[extern "lean_raylib__ImageDrawPixelV"]
opaque imageDrawPixelV (image : Image) (position : @& Vector2) (color : Color) : Image

/-- Draw line within an image -/
@[extern "lean_raylib__ImageDrawLine"]
opaque imageDrawLine (image : Image) (startPosX : Int32) (startPosY : Int32) (endPosX : Int32) (endPosY : Int32) (color : Color) : Image

/-- Draw line within an image (Vector version) -/
@[extern "lean_raylib__ImageDrawLineV"]
opaque imageDrawLineV (image : Image) (start : @& Vector2) (finish : @& Vector2) (color : Color) : Image

/-- Draw a filled circle within an image -/
@[extern "lean_raylib__ImageDrawCircle"]
opaque imageDrawCircle (image : Image) (centerX : Int32) (centerY : Int32) (radius : UInt32) (color : Color) : Image

/-- Draw a filled circle within an image (Vector version) -/
@[extern "lean_raylib__ImageDrawCircleV"]
opaque imageDrawCircleV (dst : Image) (center : @& Vector2) (radius : UInt32) (color : Color) : Image

/-- Draw circle outline within an image -/
@[extern "lean_raylib__ImageDrawCircleLines"]
opaque imageDrawCircleLines (dst : Image) (centerX : Int32) (centerY : Int32) (radius : UInt32) (color : Color) : Image

/-- Draw circle outline within an image (Vector version) -/
@[extern "lean_raylib__ImageDrawCircleLinesV"]
opaque imageDrawCircleLinesV (dst : Image) (center : @& Vector2) (radius : UInt32) (color : Color) : Image

/-- Draw rectangle within an image -/
@[extern "lean_raylib__ImageDrawRectangle"]
opaque imageDrawRectangle (dst : Image) (posX : Int32) (posY : Int32) (width : UInt32) (height : UInt32) (color : Color) : Image

/-- Draw rectangle within an image (Vector version) -/
@[extern "lean_raylib__ImageDrawRectangleV"]
opaque imageDrawRectangleV (dst : Image) (position : @& Vector2) (size : @& Vector2) (color : Color) : Image

/-- Draw rectangle within an image -/
@[extern "lean_raylib__ImageDrawRectangleRec"]
opaque imageDrawRectangleRec (dst : Image) (rect : @& Rectangle) (color : Color) : Image

/-- Draw rectangle lines within an image -/
@[extern "lean_raylib__ImageDrawRectangleLines"]
opaque imageDrawRectangleLines (dst : Image) (rect : @& Rectangle) (thick : UInt32) (color : Color) : Image

/-- Draw a source image within a destination image (tint applied to source) -/
@[extern "lean_raylib__ImageDraw"]
opaque imageDraw (dst : Image) (src : @& Image) (srcRec : @& Rectangle) (dstRec : @& Rectangle) (tint : Color) : Image

/-- Draw text (using default font) within an image (destination) -/
@[extern "lean_raylib__ImageDrawText"]
opaque imageDrawText (dst : Image) (text : @& String) (posX : Int32) (posY : Int32) (fontSize : UInt32) (color : Color) : Image

/-- Draw text (custom sprite font) within an image (destination) -/
@[extern "lean_raylib__ImageDrawTextEx"]
opaque imageDrawTextEx (dst : Image) (font : @& Font) (text : @& String) (position : @& Vector2) (fontSize : Float32) (spacing : Float32) (tint : Color) : Image

/-- Load texture from file into GPU memory (VRAM) -/
@[extern "lean_raylib__LoadTexture"]
opaque loadTexture (ctx : Context) (fileName : @& String) : BaseIO Texture2D

/-- Load texture from image data -/
@[extern "lean_raylib__LoadTextureFromImage"]
opaque loadTextureFromImage (ctx : Context) (image : @& Image) : Texture2D

/-- Load cubemap from image, multiple image cubemap layouts supported -/
@[extern "lean_raylib__LoadTextureCubemap"]
opaque loadTextureCubemap (ctx : Context) (image : @& Image) (layout : CubemapLayout) : TextureCubemap

/-- Load texture for rendering (framebuffer) -/
@[extern "lean_raylib__LoadRenderTexture"]
opaque loadRenderTexture (ctx : Context) (width : UInt32) (height : UInt32) : BaseIO RenderTexture2D

/-- Check if a texture is ready -/
@[extern "lean_raylib__IsTextureReady"]
opaque isTextureReady (texture : @& Texture2DRef) : Bool

/-- Check if a render texture is ready -/
@[extern "lean_raylib__IsRenderTextureReady"]
opaque isRenderTextureReady (target : @& RenderTexture2D) : Bool

-- /-- Update GPU texture with new data -/
-- @[extern "lean_raylib__UpdateTexture"]
-- opaque updateTexture : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | texture : Texture2D
--   | pixels : const void *
-- -/
-- /-- Update GPU texture rectangle with new data -/
-- @[extern "lean_raylib__UpdateTextureRec"]
-- opaque updateTextureRec : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | texture : Texture2D
--   | rec : Rectangle
--   | pixels : const void *
-- -/

/-- Generate GPU mipmaps for a texture -/
@[extern "lean_raylib__GenTextureMipmaps"]
opaque genTextureMipmaps (texture : Texture2D) : Texture2D

/-- Set texture scaling filter mode -/
@[extern "lean_raylib__SetTextureFilter"]
opaque setTextureFilter (texture : @& Texture2DRef) (filter : TextureFilter) : BaseIO Unit

/-- Set texture wrapping mode -/
@[extern "lean_raylib__SetTextureWrap"]
opaque setTextureWrap (texture : @& Texture2DRef) (wrap : TextureWrap) : BaseIO Unit

/-- Draw a Texture2D -/
@[extern "lean_raylib__DrawTexture"]
opaque drawTexture (texture : @& Texture2DRef) (posX : Int32) (posY : Int32) (tint : Color) : BaseIO Unit

/-- Draw a Texture2D with position defined as Vector2 -/
@[extern "lean_raylib__DrawTextureV"]
opaque drawTextureV (texture : @& Texture2DRef) (position : @& Vector2) (tint : Color) : BaseIO Unit

/-- Draw a Texture2D with extended parameters -/
@[extern "lean_raylib__DrawTextureEx"]
opaque drawTextureEx (texture : @& Texture2DRef) (position : @& Vector2) (rotation : Float32) (scale : Float32) (tint : Color) : BaseIO Unit

/-- Draw a part of a texture defined by a rectangle -/
@[extern "lean_raylib__DrawTextureRec"]
opaque drawTextureRec (texture : @& Texture2DRef) (source : @& Rectangle) (position : @& Vector2) (tint : Color) : BaseIO Unit

/-- Draw a part of a texture defined by a rectangle with 'pro' parameters -/
@[extern "lean_raylib__DrawTexturePro"]
opaque drawTexturePro (texture : @& Texture2DRef) (source : @& Rectangle) (dest : @& Rectangle) (origin : @& Vector2) (rotation : Float32) (tint : Color) : BaseIO Unit

/-- Draws a texture (or part of it) that stretches or shrinks nicely -/
@[extern "lean_raylib__DrawTextureNPatch"]
opaque drawTextureNPatch (texture : @& Texture2D) (nPatchInfo : @& NPatchInfo) (dest : @& Rectangle) (origin : @& Vector2) (rotation : Float32) (tint : Color) : BaseIO Unit

/-- Get color with alpha applied, alpha goes from 0.0f to 1.0f -/
@[extern "lean_raylib__Fade"]
opaque fade (color : Color) (alpha : Float32) : Color

/-- Get hexadecimal value for a Color -/
@[extern "lean_raylib__ColorToInt", deprecated Color.rgba]
opaque colorToInt (color : Color) : UInt32

/-- Get Color normalized as float [0..1] -/
@[extern "lean_raylib__ColorNormalize"]
opaque colorNormalize (color : Color) : Vector4

/-- Get Color from normalized values [0..1] -/
@[extern "lean_raylib__ColorFromNormalized"]
opaque colorFromNormalized (normalized : Vector4) : Color

/-- Get HSV values for a Color, hue [0..360], saturation/value [0..1] -/
@[extern "lean_raylib__ColorToHSV"]
opaque colorToHSV (color : Color) : Vector3

/-- Get a Color from HSV values, hue [0..360], saturation/value [0..1] -/
@[extern "lean_raylib__ColorFromHSV"]
opaque colorFromHSV (hue : Float32) (saturation : Float32) (value : Float32) : Color

/-- Get color multiplied with another color -/
@[extern "lean_raylib__ColorTint"]
opaque colorTint (color : Color) (tint : Color) : Color

/-- Get color with brightness correction, brightness factor goes from -1.0f to 1.0f -/
@[extern "lean_raylib__ColorBrightness"]
opaque colorBrightness (color : Color) (factor : Float32) : Color

/-- Get color with contrast correction, contrast values between -1.0f and 1.0f -/
@[extern "lean_raylib__ColorContrast"]
opaque colorContrast (color : Color) (contrast : Float32) : Color

/-- Get color with alpha applied, alpha goes from 0.0f to 1.0f -/
@[extern "lean_raylib__ColorAlpha"]
opaque colorAlpha (color : Color) (alpha : Float32) : Color

/-- Get src alpha-blended into dst color with tint -/
@[extern "lean_raylib__ColorAlphaBlend"]
opaque colorAlphaBlend (dst : Color) (src : Color) (tint : Color) : Color

/-- Get Color structure from hexadecimal value -/
@[extern "lean_raylib__GetColor", deprecated Color.mk]
opaque getColor (hexValue : UInt32) : Color

/-- Get Color from a source pixel pointer of certain format -/
@[extern "lean_raylib__GetPixelColor"]
opaque getPixelColor (format : PixelFormat) (view : @& Pod.BytesView format.bytesPerPixel 1) : Color

/-- Get Color from a source pixel pointer of certain format -/
@[extern "lean_raylib__GetPixelColorST"]
opaque getPixelColorST {σ} (format : PixelFormat) (ref : @& Pod.BytesRefImm σ format.bytesPerPixel 1) : ST σ Color

/-- Set color formatted into destination pixel pointer -/
@[extern "lean_raylib__SetPixelColorST"]
opaque setPixelColorST {σ} (format : PixelFormat) (ref : @& Pod.BytesRefMut σ format.bytesPerPixel 1) (color : Color) : ST σ Unit

/-- Get pixel data size in bytes for certain format -/
@[extern "lean_raylib__GetPixelDataSize"]
opaque getPixelDataSize (width : UInt32) (height : UInt32) (format : PixelFormat) : UInt32

/-- Get the default Font -/
@[extern "lean_raylib__GetFontDefault"]
opaque getFontDefault (ctx : Context) : BaseIO Font

/-- Load font from file into GPU memory (VRAM) -/
@[extern "lean_raylib__LoadFont"]
opaque loadFont (ctx : Context) (fileName : @& String) : BaseIO Font

/-- Load font from file with extended parameters, use `none` for `fontChars` to load the default character set -/
@[extern "lean_raylib__LoadFontEx"]
opaque loadFontEx (ctx : Context) (fileName : @& String) (fontSize : UInt32) (fontChars : @& Option (Array Char)) : BaseIO Font

/-- Load font from Image (XNA style) -/
@[extern "lean_raylib__LoadFontFromImage"]
opaque loadFontFromImage (ctx : Context) (image : @& Image) (key : Color) (firstChar : Char) : Font

/--
Load font from memory buffer, fileType refers to extension: i.e. '.ttf'.
NOTE: data size isn't checked and may cause UB.
-/
@[extern "lean_raylib__LoadFontFromMemory"]
opaque loadFontFromMemory {size} (ctx : Context) (fileType : @& String) (data : @& Pod.BytesView size 1) (fontSize : UInt32) (fontChars : @& Option (Array Char)) : Font

/-- Check if a font is ready -/
@[extern "lean_raylib__IsFontReady"]
opaque isFontReady (font : @& Font) : Bool

-- /-- Load font data for further use -/
-- @[extern "lean_raylib__LoadFontData"]
-- opaque loadFontData : Unit -> Unit
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

/-- `0` - Default, `1` - Skyline -/
def FontAtlasPackMethod : Type := Subtype (α := UInt32) (· < 2)

-- /-- Generate image font atlas using chars info -/
-- @[extern "lean_raylib__GenImageFontAtlas"]
-- opaque genImageFontAtlas (chars : @& Option (Array GlyphInfo)) (fontSize : UInt32) (padding : UInt32) (packMethod : FontAtlasPackMethod) : Image × Array Rectangle

-- axiom : ∀ chars, (genImageFontAtlas chars _ _ _).snd.size = (chars.map Array.size).getD 95

/-- Export font as code file, returns true on success -/
@[extern "lean_raylib__ExportFontAsCode"]
opaque exportFontAsCode (font : @& Font) (fileName : @& String) : BaseIO Bool

/-- Draw current FPS -/
@[extern "lean_raylib__DrawFPS"]
opaque drawFPS (posX : Int32) (posY : Int32) : BaseIO Unit

/-- Draw text (using default font) -/
@[extern "lean_raylib__DrawText"]
opaque drawText (text : @& String) (posX : Int32) (posY : Int32) (fontSize : Int32) (color : Color) : BaseIO Unit

/-- Draw text using font and additional parameters -/
@[extern "lean_raylib__DrawTextEx"]
opaque drawTextEx (font : @& Font) (text : @& String) (position : @& Vector2) (fontSize : Float32) (spacing : Float32) (tint : Color) : BaseIO Unit

/-- Draw text using font and pro parameters (rotation) -/
@[extern "lean_raylib__DrawTextPro"]
opaque drawTextPro (font : @& Font) (text : @& String) (position : @& Vector2) (origin : @& Vector2) (rotation : Float32) (fontSize : Float32) (spacing : Float32) (tint : Color) : BaseIO Unit

/-- Draw one character (codepoint) -/
@[extern "lean_raylib__DrawTextCodepoint"]
opaque drawTextCodepoint (font : @& Font) (codepoint : Char) (position : @& Vector2) (fontSize : Float32) (tint : Color) : BaseIO Unit

/-- Draw utf-8 text using font and additional parameters. -/
@[extern "lean_raylib__DrawTextCodepoints"]
opaque drawTextCodepoints (font : @& Font) (text : @& String) (position : @& Vector2) (fontSize : Float32) (spacing : Float32) (tint : Color) : BaseIO Unit

/-- Measure string width for default font -/
@[extern "lean_raylib__MeasureText"]
opaque measureText (text : @& String) (fontSize : UInt32) : BaseIO UInt32

/-- Measure string size for `Font` -/
@[extern "lean_raylib__MeasureTextEx"]
opaque measureTextEx (font : @& Font) (text : @& String) (fontSize : Float32) (spacing : Float32) : Vector2

/-- Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found -/
@[extern "lean_raylib__GetGlyphIndex"]
opaque getGlyphIndex (font : @& Font) (codepoint : Char) : USize

-- /-- Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found -/
-- @[extern "lean_raylib__GetGlyphInfo"]
-- opaque getGlyphInfo (font : @& Font) (codepoint : Char) : GlyphInfo

/-- Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found -/
@[extern "lean_raylib__GetGlyphAtlasRec"]
opaque getGlyphAtlasRec (font : @& Font) (codepoint : Char) : Rectangle

/-- Draw a line in 3D world space -/
@[extern "lean_raylib__DrawLine3D"]
opaque drawLine3D (startPos : @& Vector3) (endPos : @& Vector3) (color : Color) : BaseIO Unit

/-- Draw a point in 3D space, actually a small line -/
@[extern "lean_raylib__DrawPoint3D"]
opaque drawPoint3D (position : @& Vector3) (color : Color) : BaseIO Unit

/-- Draw a circle in 3D world space -/
@[extern "lean_raylib__DrawCircle3D"]
opaque drawCircle3D (center : @& Vector3) (radius : Float32) (rotationAxis : @& Vector3) (rotationAngle : Float32) (color : Color) : BaseIO Unit

/-- Draw a color-filled triangle (vertex in counter-clockwise order!) -/
@[extern "lean_raylib__DrawTriangle3D"]
opaque drawTriangle3D (v1 : @& Vector3) (v2 : @& Vector3) (v3 : @& Vector3) (color : Color) : BaseIO Unit

/-- Draw a triangle strip defined by points -/
@[extern "lean_raylib__DrawTriangleStrip3D"]
opaque drawTriangleStrip3D (points : @& Array Vector3) (color : Color) : BaseIO Unit

/-- Draw cube -/
@[extern "lean_raylib__DrawCube"]
opaque drawCube (position : @& Vector3) (width : Float32) (height : Float32) (length : Float32) (color : Color) : BaseIO Unit

/-- Draw cube (Vector version) -/
@[extern "lean_raylib__DrawCubeV"]
opaque drawCubeV (position : @& Vector3) (size : @& Vector3) (color : Color) : BaseIO Unit

/-- Draw cube wires -/
@[extern "lean_raylib__DrawCubeWires"]
opaque drawCubeWires (position : @& Vector3) (width : Float32) (height : Float32) (length : Float32) (color : Color) : BaseIO Unit

/-- Draw cube wires (Vector version) -/
@[extern "lean_raylib__DrawCubeWiresV"]
opaque drawCubeWiresV (position : @& Vector3) (size : @& Vector3) (color : Color) : BaseIO Unit

/-- Draw sphere -/
@[extern "lean_raylib__DrawSphere"]
opaque drawSphere (centerPos : @& Vector3) (radius : Float32) (color : Color) : BaseIO Unit

/-- Draw sphere with extended parameters -/
@[extern "lean_raylib__DrawSphereEx"]
opaque drawSphereEx (centerPos : @& Vector3) (radius : Float32) (rings : UInt32) (slices : UInt32) (color : Color) : BaseIO Unit

/-- Draw sphere wires -/
@[extern "lean_raylib__DrawSphereWires"]
opaque drawSphereWires (centerPos : @& Vector3) (radius : Float32) (rings : UInt32) (slices : UInt32) (color : Color) : BaseIO Unit

/-- Draw a cylinder/cone -/
@[extern "lean_raylib__DrawCylinder"]
opaque drawCylinder (position : @& Vector3) (radiusTop : Float32) (radiusBottom : Float32) (height : Float32) (slices : UInt32) (color : Color) : BaseIO Unit

/-- Draw a cylinder with base at startPos and top at endPos -/
@[extern "lean_raylib__DrawCylinderEx"]
opaque drawCylinderEx (startPos : @& Vector3) (endPos : @& Vector3) (startRadius : Float32) (endRadius : Float32) (sides : UInt32) (color : Color) : BaseIO Unit

/-- Draw a cylinder/cone wires -/
@[extern "lean_raylib__DrawCylinderWires"]
opaque drawCylinderWires (position : @& Vector3) (radiusTop : Float32) (radiusBottom : Float32) (height : Float32) (slices : UInt32) (color : Color) : BaseIO Unit

/-- Draw a cylinder wires with base at startPos and top at endPos -/
@[extern "lean_raylib__DrawCylinderWiresEx"]
opaque drawCylinderWiresEx (startPos : @& Vector3) (endPos : @& Vector3) (startRadius : Float32) (endRadius : Float32) (sides : UInt32) (color : Color) : BaseIO Unit

/-- Draw a capsule with the center of its sphere caps at startPos and endPos -/
@[extern "lean_raylib__DrawCapsule"]
opaque drawCapsule (startPos : @& Vector3) (endPos : @& Vector3) (radius : Float32) (slices : UInt32) (rings : UInt32) (color : Color) : BaseIO Unit

/-- Draw capsule wireframe with the center of its sphere caps at startPos and endPos -/
@[extern "lean_raylib__DrawCapsuleWires"]
opaque drawCapsuleWires (startPos : @& Vector3) (endPos : @& Vector3) (radius : Float32) (slices : UInt32) (rings : UInt32) (color : Color) : BaseIO Unit

/-- Draw a plane XZ -/
@[extern "lean_raylib__DrawPlane"]
opaque drawPlane (centerPos : @& Vector3) (size : @& Vector2) (color : Color) : BaseIO Unit

/-- Draw a ray line -/
@[extern "lean_raylib__DrawRay"]
opaque drawRay (ray : @& Ray) (color : Color) : BaseIO Unit

/-- Draw a grid (centered at (0, 0, 0)) -/
@[extern "lean_raylib__DrawGrid"]
opaque drawGrid (slices : UInt32) (spacing : Float32) : BaseIO Unit

/-- Load model from files (meshes and materials) -/
@[extern "lean_raylib__LoadModel"]
opaque loadModel (ctx : @& Context) (fileName : @& String) : BaseIO Model

/-- Load model from generated mesh (default material) -/
@[extern "lean_raylib__LoadModelFromMesh"]
opaque loadModelFromMesh (mesh : Mesh) : Model

/-- Check if a model is ready -/
@[extern "lean_raylib__IsModelReady"]
opaque isModelReady (model : @& Model) : Bool

/-- Compute model bounding box limits (considers all meshes) -/
@[extern "lean_raylib__GetModelBoundingBox"]
opaque getModelBoundingBox (model : @& Model) : BoundingBox

/-- Draw a model (with texture if set) -/
@[extern "lean_raylib__DrawModel"]
opaque drawModel (model : @& Model) (position : @& Vector3) (scale : Float32) (tint : Color) : BaseIO Unit

/-- Draw a model with extended parameters -/
@[extern "lean_raylib__DrawModelEx"]
opaque drawModelEx (model : @& Model) (position : @& Vector3) (rotationAxis : @& Vector3) (rotationAngle : Float32) (scale : @& Vector3) (tint : Color) : BaseIO Unit

/-- Draw a model wires (with texture if set) -/
@[extern "lean_raylib__DrawModelWires"]
opaque drawModelWires (model : @& Model) (position : @& Vector3) (scale : Float32) (tint : Color) : BaseIO Unit

/-- Draw a model wires (with texture if set) with extended parameters -/
@[extern "lean_raylib__DrawModelWiresEx"]
opaque drawModelWiresEx (model : @& Model) (position : @& Vector3) (rotationAxis : @& Vector3) (rotationAngle : Float32) (scale : @& Vector3) (tint : Color) : BaseIO Unit

/-- Draw bounding box (wires) -/
@[extern "lean_raylib__DrawBoundingBox"]
opaque drawBoundingBox (box : @& BoundingBox) (color : Color) : BaseIO Unit

/-- Draw a billboard texture -/
@[extern "lean_raylib__DrawBillboard"]
opaque drawBillboard (camera : @& Camera) (texture : @& Texture2DRef) (position : @& Vector3) (size : Float32) (tint : Color) : BaseIO Unit

/-- Draw a billboard texture defined by source -/
@[extern "lean_raylib__DrawBillboardRec"]
opaque drawBillboardRec (camera : @& Camera) (texture : @& Texture2DRef) (source : @& Rectangle) (position : @& Vector3) (size : @& Vector2) (tint : Color) : BaseIO Unit

/-- Draw a billboard texture defined by source and rotation -/
@[extern "lean_raylib__DrawBillboardPro"]
opaque drawBillboardPro (camera : @& Camera) (texture : @& Texture2DRef) (source : @& Rectangle) (position : @& Vector3) (up : @& Vector3) (size : @& Vector2) (origin : @& Vector2) (rotation : Float32) (tint : Color) : BaseIO Unit

/-- Create a mesh duplicate. Doesn't upload its data to GPU. -/
@[extern "lean_raylib__MeshCopy"]
opaque meshCopy (mesh : @& Mesh) : Mesh

/-- Upload mesh vertex data in GPU and provide VAO/VBO ids -/
@[extern "lean_raylib__UploadMesh"]
opaque uploadMesh (mesh : Mesh) (dynamic : Bool) : BaseIO Mesh

-- /-- Update mesh vertex data in GPU for a specific buffer index -/
-- @[extern "lean_raylib__UpdateMeshBuffer"]
-- opaque updateMeshBuffer : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | mesh : Mesh
--   | index : int
--   | data : const void *
--   | dataSize : int
--   | offset : int
-- -/

/-- Draw a 3d mesh with material and transform -/
@[extern "lean_raylib__DrawMesh"]
opaque drawMesh (mesh : @& Mesh) (material : @& Material) (transform : @& Matrix) : BaseIO Unit

-- /-- Draw multiple mesh instances with material and different transforms -/
-- @[extern "lean_raylib__DrawMeshInstanced"]
-- opaque drawMeshInstanced : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | mesh : Mesh
--   | material : Material
--   | transforms : const Matrix *
--   | instances : int
-- -/

/-- Export mesh data to file, returns true on success -/
@[extern "lean_raylib__ExportMesh"]
opaque exportMesh (mesh : @& Mesh) (fileName : @& String) : BaseIO Bool

/-- Compute mesh bounding box limits -/
@[extern "lean_raylib__GetMeshBoundingBox"]
opaque getMeshBoundingBox (mesh : @& Mesh) : BoundingBox

/-- Compute mesh tangents -/
@[extern "lean_raylib__GenMeshTangents"]
opaque genMeshTangents (mesh : Mesh) : Mesh

/-- Generate polygonal mesh -/
@[extern "lean_raylib__GenMeshPoly"]
opaque genMeshPoly (ctx : Context) (sides : UInt32) (radius : Float32) : Mesh

/-- Generate plane mesh (with subdivisions) -/
@[extern "lean_raylib__GenMeshPlane"]
opaque genMeshPlane (ctx : Context) (width : Float32) (length : Float32) (resX : UInt32) (resZ : UInt32) : Mesh

/-- Generate cuboid mesh -/
@[extern "lean_raylib__GenMeshCube"]
opaque genMeshCube (ctx : Context) (width : Float32) (height : Float32) (length : Float32) : Mesh

/-- Generate sphere mesh (standard sphere) -/
@[extern "lean_raylib__GenMeshSphere"]
opaque genMeshSphere (ctx : Context) (radius : Float32) (rings : UInt32) (slices : UInt32) : Mesh

/-- Generate half-sphere mesh (no bottom cap) -/
@[extern "lean_raylib__GenMeshHemiSphere"]
opaque genMeshHemiSphere (ctx : Context) (radius : Float32) (rings : UInt32) (slices : UInt32) : Mesh

/-- Generate cylinder mesh -/
@[extern "lean_raylib__GenMeshCylinder"]
opaque genMeshCylinder (ctx : Context) (radius : Float32) (height : Float32) (slices : UInt32) : Mesh

/-- Generate cone/pyramid mesh -/
@[extern "lean_raylib__GenMeshCone"]
opaque genMeshCone (ctx : Context) (radius : Float32) (height : Float32) (slices : UInt32) : Mesh

/-- Generate torus mesh -/
@[extern "lean_raylib__GenMeshTorus"]
opaque genMeshTorus (ctx : Context) (radius : Float32) (size : Float32) (radSeg : UInt32) (sides : UInt32) : Mesh

/-- Generate trefoil knot mesh -/
@[extern "lean_raylib__GenMeshKnot"]
opaque genMeshKnot (ctx : Context) (radius : Float32) (size : Float32) (radSeg : UInt32) (sides : UInt32) : Mesh

/-- Generate heightmap mesh from image data -/
@[extern "lean_raylib__GenMeshHeightmap"]
opaque genMeshHeightmap (ctx : Context) (heightmap : @& Image) (size : @& Vector3) : Mesh

/-- Generate cubes-based map mesh from image data -/
@[extern "lean_raylib__GenMeshCubicmap"]
opaque genMeshCubicmap (ctx : Context) (cubicmap : @& Image) (cubeSize : @& Vector3) : Mesh

/-- Load materials from model file -/
@[extern "lean_raylib__LoadMaterials"]
opaque loadMaterials (ctx : @& Context) (fileName : @& String) : Array Material

/-- Check if a material is ready -/
def isMaterialReady (material : Material) : Bool := isShaderReady material.shader

-- /-- Load model animations from file -/
-- @[extern "lean_raylib__LoadModelAnimations"]
-- opaque loadModelAnimations : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: ModelAnimation *
--   params:
--   | fileName : const char *
--   | animCount : unsigned int *
-- -/
-- /-- Update model animation pose -/
-- @[extern "lean_raylib__UpdateModelAnimation"]
-- opaque updateModelAnimation (model : Model) (anim : ModelAnimation) (frame : Int32) : Unit
-- /-- Unload animation data -/
-- @[extern "lean_raylib__UnloadModelAnimation"]
-- opaque unloadModelAnimation (anim : ModelAnimation) : Unit
-- /-- Unload animation array data -/
-- @[extern "lean_raylib__UnloadModelAnimations"]
-- opaque unloadModelAnimations : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | animations : ModelAnimation *
--   | count : unsigned int
-- -/
-- /-- Check model animation skeleton match -/
-- @[extern "lean_raylib__IsModelAnimationValid"]
-- opaque isModelAnimationValid (model : Model) (anim : ModelAnimation) : Bool

/-- Check collision between two spheres -/
@[extern "lean_raylib__CheckCollisionSpheres"]
opaque checkCollisionSpheres (center1 : @& Vector3) (radius1 : Float32) (center2 : @& Vector3) (radius2 : Float32) : Bool

/-- Check collision between two bounding boxes -/
@[extern "lean_raylib__CheckCollisionBoxes"]
opaque checkCollisionBoxes (box1 : @& BoundingBox) (box2 : @& BoundingBox) : Bool

/-- Check collision between box and sphere -/
@[extern "lean_raylib__CheckCollisionBoxSphere"]
opaque checkCollisionBoxSphere (box : @& BoundingBox) (center : @& Vector3) (radius : Float32) : Bool

/-- Get collision info between ray and sphere -/
@[extern "lean_raylib__GetRayCollisionSphere"]
opaque getRayCollisionSphere (ray : @& Ray) (center : @& Vector3) (radius : Float32) : RayCollision

/-- Get collision info between ray and box -/
@[extern "lean_raylib__GetRayCollisionBox"]
opaque getRayCollisionBox (ray : @& Ray) (box : @& BoundingBox) : RayCollision

/-- Get collision info between ray and mesh -/
@[extern "lean_raylib__GetRayCollisionMesh"]
opaque getRayCollisionMesh (ray : @& Ray) (mesh : @& Mesh) (transform : @& Matrix) : RayCollision

/-- Get collision info between ray and triangle -/
@[extern "lean_raylib__GetRayCollisionTriangle"]
opaque getRayCollisionTriangle (ray : @& Ray) (p1 : @& Vector3) (p2 : @& Vector3) (p3 : @& Vector3) : RayCollision

/-- Get collision info between ray and quad -/
@[extern "lean_raylib__GetRayCollisionQuad"]
opaque getRayCollisionQuad (ray : @& Ray) (p1 : @& Vector3) (p2 : @& Vector3) (p3 : @& Vector3) (p4 : @& Vector3) : RayCollision

/-- Initialize audio device and context -/
@[extern "lean_raylib__InitAudioDevice"]
opaque initAudioDevice : BaseIO Unit

/-- Close the audio device and context -/
@[extern "lean_raylib__CloseAudioDevice"]
opaque closeAudioDevice : BaseIO Unit

/-- Check if audio device has been initialized successfully -/
@[extern "lean_raylib__IsAudioDeviceReady"]
opaque isAudioDeviceReady : BaseIO Bool

/-- Set master volume (listener) -/
@[extern "lean_raylib__SetMasterVolume"]
opaque setMasterVolume (volume : Float32) : BaseIO Unit

/-- Load wave data from file -/
@[extern "lean_raylib__LoadWave"]
opaque loadWave (fileName : @& String) : BaseIO Wave

/-- Load wave from memory buffer, fileType refers to extension: i.e. '.wav' -/
@[extern "lean_raylib__LoadWaveFromMemory"]
opaque loadWaveFromMemory {size} (fileType : @& String) (fileData : @& Pod.BytesView size 1) : Wave

/-- Checks if wave data is ready -/
@[extern "lean_raylib__IsWaveReady"]
opaque isWaveReady (wave : @& Wave) : Bool

/-- Load sound from file -/
@[extern "lean_raylib__LoadSound"]
opaque loadSound (ctx : Context) (fileName : @& String) : BaseIO Sound

/-- Load sound from wave data -/
@[extern "lean_raylib__LoadSoundFromWave"]
opaque loadSoundFromWave (ctx : Context) (wave : @& Wave) : Sound

/-- Checks if a sound is ready -/
@[extern "lean_raylib__IsSoundReady"]
opaque isSoundReady (sound : @& Sound) : Bool

-- /-- Update sound buffer with new data -/
-- @[extern "lean_raylib__UpdateSound"]
-- opaque updateSound : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | sound : Sound
--   | data : const void *
--   | sampleCount : int
-- -/

/-- Export wave data to file, returns true on success -/
@[extern "lean_raylib__ExportWave"]
opaque exportWave (wave : @& Wave) (fileName : @& String) : BaseIO Bool

/-- Export wave sample data to code (.h), returns true on success -/
@[extern "lean_raylib__ExportWaveAsCode"]
opaque exportWaveAsCode (wave : @& Wave) (fileName : @& String) : BaseIO Bool

/-- Play a sound -/
@[extern "lean_raylib__PlaySound"]
opaque playSound (sound : @& Sound) : BaseIO Unit

/-- Stop playing a sound -/
@[extern "lean_raylib__StopSound"]
opaque stopSound (sound : @& Sound) : BaseIO Unit

/-- Pause a sound -/
@[extern "lean_raylib__PauseSound"]
opaque pauseSound (sound : @& Sound) : BaseIO Unit

/-- Resume a paused sound -/
@[extern "lean_raylib__ResumeSound"]
opaque resumeSound (sound : @& Sound) : BaseIO Unit

/-- Check if a sound is currently playing -/
@[extern "lean_raylib__IsSoundPlaying"]
opaque isSoundPlaying (sound : @& Sound) : BaseIO Bool

/-- Set volume for a sound (1.0 is max level) -/
@[extern "lean_raylib__SetSoundVolume"]
opaque setSoundVolume (sound : @& Sound) (volume : Float32) : BaseIO Unit

/-- Set pitch for a sound (1.0 is base level) -/
@[extern "lean_raylib__SetSoundPitch"]
opaque setSoundPitch (sound : @& Sound) (pitch : Float32) : BaseIO Unit

/-- Set pan for a sound (0.5 is center) -/
@[extern "lean_raylib__SetSoundPan"]
opaque setSoundPan (sound : @& Sound) (pan : Float32) : BaseIO Unit

/-- Copy a wave to a new wave -/
@[extern "lean_raylib__WaveCopy"]
opaque waveCopy (wave : @& Wave) : Wave

/-- Crop a wave to defined samples range -/
@[extern "lean_raylib__WaveCrop"]
opaque waveCrop (wave : Wave) (initSample : UInt32) (finalSample : UInt32) : Wave

/-- Convert wave data to desired format -/
@[extern "lean_raylib__WaveFormat"]
opaque waveFormat (wave : Wave) (sampleRate : UInt32) (sampleSize : UInt32) (channels : UInt32) : Wave

/--
Load samples data from wave as a 32bit float data array.
NOTE: Returned sample values are normalized to range [-1..1].
-/
@[extern "lean_raylib__LoadWaveSamples"]
opaque loadWaveSamples (wave : @& Wave) : BaseIO (Array Float32)

/-- Load music stream from file -/
@[extern "lean_raylib__LoadMusicStream"]
opaque loadMusicStream (ctx : Context) (fileName : @& String) : BaseIO Music

/-- Load music stream from data -/
-- IO: calls TraceLog
@[extern "lean_raylib__LoadMusicStreamFromMemory"]
opaque loadMusicStreamFromMemory (ctx : Context) (fileType : @& String) (data : @& ByteArray) : BaseIO Music

/-- Checks if a music stream is ready -/
@[extern "lean_raylib__IsMusicReady"]
opaque isMusicReady (music : @& Music) : Bool

/-- Start music playing -/
@[extern "lean_raylib__PlayMusicStream"]
opaque playMusicStream (music : @& Music) : BaseIO Unit

/-- Check if music is playing -/
@[extern "lean_raylib__IsMusicStreamPlaying"]
opaque isMusicStreamPlaying (music : @& Music) : BaseIO Bool

/-- Updates buffers for music streaming -/
@[extern "lean_raylib__UpdateMusicStream"]
opaque updateMusicStream (music : @& Music) : BaseIO Unit

/-- Stop music playing -/
@[extern "lean_raylib__StopMusicStream"]
opaque stopMusicStream (music : @& Music) : BaseIO Unit

/-- Pause music playing -/
@[extern "lean_raylib__PauseMusicStream"]
opaque pauseMusicStream (music : @& Music) : BaseIO Unit

/-- Resume playing paused music -/
@[extern "lean_raylib__ResumeMusicStream"]
opaque resumeMusicStream (music : @& Music) : BaseIO Unit

/-- Seek music to a position (in seconds) -/
@[extern "lean_raylib__SeekMusicStream"]
opaque seekMusicStream (music : @& Music) (position : Float32) : BaseIO Unit

/-- Set volume for music (1.0 is max level) -/
@[extern "lean_raylib__SetMusicVolume"]
opaque setMusicVolume (music : @& Music) (volume : Float32) : BaseIO Unit

/-- Set pitch for a music (1.0 is base level) -/
@[extern "lean_raylib__SetMusicPitch"]
opaque setMusicPitch (music : @& Music) (pitch : Float32) : BaseIO Unit

/-- Set pan for a music (0.5 is center) -/
@[extern "lean_raylib__SetMusicPan"]
opaque setMusicPan (music : @& Music) (pan : Float32) : BaseIO Unit

/-- Get music time length (in seconds) -/
@[extern "lean_raylib__GetMusicTimeLength"]
opaque getMusicTimeLength (music : @& Music) : Float32

/-- Get current music time played (in seconds) -/
@[extern "lean_raylib__GetMusicTimePlayed"]
opaque getMusicTimePlayed (music : @& Music) : BaseIO Float

/-- Load audio stream (to stream raw audio pcm data) -/
@[extern "lean_raylib__LoadAudioStream"]
opaque loadAudioStream (ctx : Context) (sampleRate : UInt32) (sampleType : AudioSampleType) (channels : UInt32) : BaseIO (AudioStream sampleType)

/-- Checks if an audio stream is ready -/
@[extern "lean_raylib__IsAudioStreamReady"]
opaque isAudioStreamReady {st} (stream : @& AudioStream st) : Bool

/-- Update audio stream buffers with data. -/
@[extern "lean_raylib__UpdateAudioStream"]
opaque updateAudioStream {st}
  (stream : @& AudioStream st)
  (data : ByteArray)
  (frameCount : UInt32)
  (data_size : data.size = frameCount.toNat * stream.channels.toNat * stream.sampleSize.toNat / 8)
  : BaseIO Unit

/-- Check if any audio stream buffers requires refill -/
@[extern "lean_raylib__IsAudioStreamProcessed"]
opaque isAudioStreamProcessed {st} (stream : @& AudioStream st) : BaseIO Bool

/-- Play audio stream -/
@[extern "lean_raylib__PlayAudioStream"]
opaque playAudioStream {st} (stream : @& AudioStream st) : BaseIO Unit

/-- Pause audio stream -/
@[extern "lean_raylib__PauseAudioStream"]
opaque pauseAudioStream {st} (stream : @& AudioStream st) : BaseIO Unit

/-- Resume audio stream -/
@[extern "lean_raylib__ResumeAudioStream"]
opaque resumeAudioStream {st} (stream : @& AudioStream st) : BaseIO Unit

/-- Check if audio stream is playing -/
@[extern "lean_raylib__IsAudioStreamPlaying"]
opaque isAudioStreamPlaying {st} (stream : @& AudioStream st) : BaseIO Bool

/-- Stop audio stream -/
@[extern "lean_raylib__StopAudioStream"]
opaque stopAudioStream {st} (stream : @& AudioStream st) : BaseIO Unit

/-- Set volume for audio stream (1.0 is max level) -/
@[extern "lean_raylib__SetAudioStreamVolume"]
opaque setAudioStreamVolume {st} (stream : @& AudioStream st) (volume : Float32) : BaseIO Unit

/-- Set pitch for audio stream (1.0 is base level) -/
@[extern "lean_raylib__SetAudioStreamPitch"]
opaque setAudioStreamPitch {st} (stream : @& AudioStream st) (pitch : Float32) : BaseIO Unit

/-- Set pan for audio stream (0.5 is centered) -/
@[extern "lean_raylib__SetAudioStreamPan"]
opaque setAudioStreamPan {st} (stream : @& AudioStream st) (pan : Float32) : BaseIO Unit

/-- Default size for new audio streams -/
@[extern "lean_raylib__SetAudioStreamBufferSizeDefault"]
opaque setAudioStreamBufferSizeDefault (size : UInt32) : BaseIO Unit

/-- Audio thread callback to request new data -/
@[extern "lean_raylib__SetAudioStreamCallback"]
opaque setAudioStreamCallback {st} (stream : @& AudioStream st) (callback : AudioCallback st) : BaseIO Unit

-- /-- Attach audio stream processor to stream -/
-- @[extern "lean_raylib__AttachAudioStreamProcessor"]
-- opaque attachAudioStreamProcessor : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | stream : AudioStream
--   | processor : AudioCallback
-- -/
-- /-- Detach audio stream processor from stream -/
-- @[extern "lean_raylib__DetachAudioStreamProcessor"]
-- opaque detachAudioStreamProcessor : Unit -> Unit
-- /- todo: ^^ function ^^
--   returns: void
--   params:
--   | stream : AudioStream
--   | processor : AudioCallback
-- -/
-- /-- Attach audio stream processor to the entire audio pipeline -/
-- @[extern "lean_raylib__AttachAudioMixedProcessor"]
-- opaque attachAudioMixedProcessor (processor : AudioCallback) : BaseIO Unit
-- /-- Detach audio stream processor from the entire audio pipeline -/
-- @[extern "lean_raylib__DetachAudioMixedProcessor"]
-- opaque detachAudioMixedProcessor (processor : AudioCallback) : BaseIO Unit

end Raylib
