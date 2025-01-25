import Pod.Meta
import Raylib.Structures

namespace Raylib.Glfw

open scoped Pod

/-- Error codes. -/
inductive ErrorCode where
/-- No error has occurred. Yay. -/
| noError
/-- GLFW has not been initialized. -/
| notInitialized
/-- No context is current for this thread. -/
| noCurrentContext
/-- One of the arguments to the function was an invalid enum value. -/
| invalidEnum
/-- One of the arguments to the function was an invalid value. -/
| invalidValue
/-- A memory allocation failed. -/
| outOfMemory
/-- GLFW could not find support for the requested API on the system. -/
| apiUnavailable
/-- The requested OpenGL or OpenGL ES version is not available. -/
| versionUnavailable
/-- A platform-specific error occurred that does not match any of the more specific categories. -/
| platformError
/-- The requested format is not supported or available. -/
| formatUnavailable
/-- The specified window does not have an OpenGL or OpenGL ES context. -/
| noWindowContext
/-- The specified cursor shape is not available. -/
| cursorUnavailable
/-- The requested feature is not provided by the platform. -/
| featureUnavailable
/-- The requested feature is not implemented for the platform. -/
| featureUnimplemented
/-- Platform unavailable or no matching platform was found. -/
| platformUnavailable
/-- Bindings are out of sync with GLFW and could not recognize the error's code. -/
| unknown
deriving Repr, Inhabited, BEq, DecidableEq

structure Error where
  code : ErrorCode
  description : String
deriving Repr, Inhabited

abbrev GlfwIO := EIO Error

def GlfwIO.toIO {α} (x : GlfwIO α) : IO α :=
  EIO.toIO (λ e ↦ IO.userError (toString $ repr e)) x

/-- Opaque window object. -/
define_foreign_type Window

/-- Handle must be `GLFWwindow*` (created via Raylib with GLFW backend) -/
@[extern "lean_raylib_glfw_Window_mk"]
opaque Window.mk (handle : WindowBackendHandle) : Window

-- NOTE: Constructor indices are used in native code, synchronize changes!
inductive Platform where
| win32 : Platform
| cocoa : Platform
| wayland : Platform
| x11 : Platform
| null : Platform
deriving Inhabited, Repr, BEq

/--
Initialization hints are set before `glfwInit` (called by raylib's `InitWindow`) and
affect how the library behaves until termination.

Some hints are platform specific.
These may be set on any platform but they will only affect their specific platform.
Other platforms will ignore them.

Allows to pass any value to use with an out-of-sync GLFW version.
Passing invalid values will cause a harmless error that can be ignored.
-/
structure InitHint where
  val : Int32
deriving Inhabited, BEq

namespace InitHint

def platform : InitHint := ⟨0x00050003⟩

/--
Whether to also expose joystick hats as buttons, for compatibility with earlier
versions of GLFW that did not have `glfwGetJoystickHats`.
Default `true`.
-/
def joystickHatButtons : InitHint := ⟨0x00050001⟩

/--
Specifies the platform type (rendering backend) to request when using OpenGL ES and EGL via ANGLE.
If the requested platform type is unavailable, ANGLE will use its default.
-/
def anglePlatformType : InitHint := ⟨0x00050002⟩

/--
Whether to set the current directory to the application to the Contents/Resources
subdirectory of the application's bundle, if present.
Default `true`.
-/
def cocoaChdirResources : InitHint := ⟨0x00051001⟩

/--
Whether to create the menu bar and dock icon when GLFW is initialized.
Default `true`.
-/
def cocoaMenubar : InitHint := ⟨0x00051002⟩

/--
Whether to use libdecor for window decorations where available.
-/
def waylandLibdecor : InitHint := ⟨0x00053001⟩

/--
whether to prefer the `VK_KHR_xcb_surface` extension for creating Vulkan surfaces,
or whether to use the `VK_KHR_xlib_surface` extension.
Default `true`.
-/
def x11XcbVulkanSurface : InitHint := ⟨0x00052001⟩

-- NOTE: Constructor indices are used in native code, synchronize changes!
inductive Value : InitHint -> Type where
/-- Allows to pass any value to use with an out-of-sync GLFW version. -/
| unknown {hint} (value : Int32) : Value hint -- 0
| bool (x : Bool) {hint} -- 1
  (h : hint == joystickHatButtons ||
    hint == cocoaChdirResources ||
    hint == cocoaMenubar ||
    hint == x11XcbVulkanSurface := by decide) : Value hint
| anyPlatform : Value .platform -- 2
| platform (platform : Platform) : Value .platform -- 3
| anglePlatformTypeNone : Value .anglePlatformType -- 4
| anglePlatformTypeOpengl : Value .anglePlatformType -- 5
| anglePlatformTypeOpengles : Value .anglePlatformType -- 6
| anglePlatformTypeD3d9 : Value .anglePlatformType -- 7
| anglePlatformTypeD3d11 : Value .anglePlatformType -- 8
| anglePlatformTypeVulkan : Value .anglePlatformType -- 9
| anglePlatformTypeMetal : Value .anglePlatformType -- 10
| waylandDisableLibdecor : Value .waylandLibdecor -- 11
| waylandPreferLibdecor : Value .waylandLibdecor -- 12

end InitHint

@[extern "lean_raylib_glfw_initHint", inherit_doc InitHint]
opaque initHint (hint : InitHint) (value : @& hint.Value) : GlfwIO Unit

/-- This function returns the platform that was selected during initialization. -/
@[extern "lean_raylib_glfw_getPlatform"]
opaque getPlatform : GlfwIO Platform

/--
This function returns whether the library was compiled with support for the specified platform.
This function may be called before `glfwInit` (`Raylib.initWindow`).
-/
@[extern "lean_raylib_glfw_platformSupported"]
opaque platformSupported (platform : Platform) : GlfwIO Bool

/-- Opaque monitor object. -/
define_foreign_type Monitor

/--
This function returns the primary monitor.
This is usually the monitor where elements like the task bar or global menu bar are located.
-/
@[extern "lean_raylib_glfw_getPrimaryMonitor"]
opaque getPrimaryMonitor : GlfwIO Monitor

/--
This function sets the monitor that the window uses for full screen mode or,
if the monitor is `none`, makes it windowed mode.
When setting a monitor, this function updates the width, height and refresh rate
of the desired video mode and switches to the video mode closest to it.
The window position is ignored when setting a monitor.
Setting refresh rate to `none` is equivalent to passing `GLFW_DONT_CARE`.
-/
@[extern "lean_raylib_glfw_setWindowMonitor"]
opaque setWindowMonitor
  (window : @& Window) (monitor : @& (Option Monitor))
  (xpos ypos : Int32) (width height : UInt32)
  (refreshRate : @& Option UInt32) : GlfwIO Unit

/-- This describes a single video mode. -/
structure VideoMode where
  /-- The width, in screen coordinates, of the video mode. -/
  width : UInt32
  /-- The height, in screen coordinates, of the video mode. -/
  height : UInt32
  /-- The bit depth of the red channel of the video mode. -/
  redBits : UInt32
  /-- The bit depth of the green channel of the video mode. -/
  greenBits : UInt32
  /-- The bit depth of the blue channel of the video mode. -/
  blueBits : UInt32
  /-- The refresh rate, in Hz, of the video mode. -/
  refreshRate : UInt32
deriving Repr, Inhabited, BEq

/--
Returns the available video modes for the specified monitor.
The returned array is sorted in ascending order, first by color bit depth (the sum of all channel depths),
then by resolution area (the product of width and height), then resolution width and finally by refresh rate.
-/
@[extern "lean_raylib_glfw_getVideoModes"]
opaque getVideoModes (monitor : @& Monitor) : GlfwIO (Array VideoMode)

/--
Returns the current mode of the specified monitor.
If you have created a full screen window for that monitor,
the return value will depend on whether that window is iconified.
-/
@[extern "lean_raylib_glfw_getVideoMode"]
opaque getVideoMode (monitor : @& Monitor) : GlfwIO VideoMode

/--
This function sets the swap interval for the current OpenGL or OpenGL ES context,
i.e. the number of screen updates to wait from the time swap buffers was called
before swapping the buffers and returning.
This is sometimes called _vertical synchronization_, _vertical retrace synchronization_ or just _vsync_.

A context that supports either of the `WGL_EXT_swap_control_tear` and `GLX_EXT_swap_control_tear`
extensions also accepts _negative_ swap intervals, which allows the driver to swap immediately
even if a frame arrives a little bit late.
You can check for these extensions with `extensionSupported`.

A context must be current on the calling thread.
Calling this function without a current context will cause a `noCurrentContext` error.
-/
@[extern "lean_raylib_glfw_swapInterval"]
opaque swapInterval (interval : Int32) : GlfwIO Unit

/--
This function returns whether the specified extension is supported
by the current OpenGL or OpenGL ES context.
It searches both for client API extension and context creation API extensions.

A context must be current on the calling thread.
Calling this function without a current context will cause a `noCurrentContext` error.
-/
@[extern "lean_raylib_glfw_extensionSupported"]
opaque extensionSupported (extension : @& String) : GlfwIO Bool
