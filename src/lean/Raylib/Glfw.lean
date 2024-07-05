import Pod.Meta
import Pod.Int

open Pod (Int32)

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
-/
@[extern "lean_raylib_glfw_setWindowMonitor"]
opaque setWindowMonitor
  (window : @& Window) (monitor : @& (Option Monitor))
  (xpos ypos : Int32) (width height refreshRate : UInt32) : GlfwIO Unit

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
