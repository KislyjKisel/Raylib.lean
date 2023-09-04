import Pod.UInt
import Pod.Int
import Pod.Float
import Raymath.Core
import Raylib.Util

open Pod (Int32)

namespace Raylib

/-! # Config flags -/

/-- System/Window config flags -/
structure ConfigFlags where
  val : UInt32
deriving Inhabited, Repr

instance : OrOp ConfigFlags where
  or := λ a b ↦ ConfigFlags.mk (a.val ||| b.val)

instance : AndOp ConfigFlags where
  and := λ a b ↦ ConfigFlags.mk (a.val &&& b.val)

namespace ConfigFlags

/-- Set to try enabling V-Sync on GPU -/
def vsyncHint : ConfigFlags := ConfigFlags.mk 64

/-- Set to run program in fullscreen -/
def fullscreenMode : ConfigFlags := ConfigFlags.mk 2

/-- Set to allow resizable window -/
def windowResizable : ConfigFlags := ConfigFlags.mk 4

/-- Set to disable window decoration (frame and buttons) -/
def windowUndecorated : ConfigFlags := ConfigFlags.mk 8

/-- Set to hide window -/
def windowHidden : ConfigFlags := ConfigFlags.mk 128

/-- Set to minimize window (iconify) -/
def windowMinimized : ConfigFlags := ConfigFlags.mk 512

/-- Set to maximize window (expanded to monitor) -/
def windowMaximized : ConfigFlags := ConfigFlags.mk 1024

/-- Set to window non focused -/
def windowUnfocused : ConfigFlags := ConfigFlags.mk 2048

/-- Set to window always on top -/
def windowTopmost : ConfigFlags := ConfigFlags.mk 4096

/-- Set to allow windows running while minimized -/
def windowAlwaysRun : ConfigFlags := ConfigFlags.mk 256

/-- Set to allow transparent framebuffer -/
def windowTransparent : ConfigFlags := ConfigFlags.mk 16

/-- Set to support HighDPI -/
def windowHighdpi : ConfigFlags := ConfigFlags.mk 8192

/-- Set to support mouse passthrough, only supported when `windowUndecorated` -/
def windowMousePassthrough : ConfigFlags := ConfigFlags.mk 16384

/-- Set to try enabling MSAA 4X -/
def msaa4xHint : ConfigFlags := ConfigFlags.mk 32

/-- Set to try enabling interlaced video format (for V3D) -/
def interlacedHint : ConfigFlags := ConfigFlags.mk 65536

end ConfigFlags


/-! # TraceLogLevel -/

inductive TraceLogLevel.Is : UInt32 -> Prop where
  | all : TraceLogLevel.Is 0
  | trace : TraceLogLevel.Is 1
  | debug : TraceLogLevel.Is 2
  | info : TraceLogLevel.Is 3
  | warning : TraceLogLevel.Is 4
  | error : TraceLogLevel.Is 5
  | fatal : TraceLogLevel.Is 6
  | none : TraceLogLevel.Is 7

def TraceLogLevel : Type := Subtype TraceLogLevel.Is

namespace TraceLogLevel

/-- Display all logs -/
def all : TraceLogLevel := Subtype.mk 0 TraceLogLevel.Is.all

/-- Trace logging, intended for internal use only -/
def trace : TraceLogLevel := Subtype.mk 1 TraceLogLevel.Is.trace

/-- Debug logging, used for internal debugging, it should be disabled on release builds -/
def debug : TraceLogLevel := Subtype.mk 2 TraceLogLevel.Is.debug

/-- Info logging, used for program execution info -/
def info : TraceLogLevel := Subtype.mk 3 TraceLogLevel.Is.info

/-- Warning logging, used on recoverable failures -/
def warning : TraceLogLevel := Subtype.mk 4 TraceLogLevel.Is.warning

/-- Error logging, used on unrecoverable failures -/
def error : TraceLogLevel := Subtype.mk 5 TraceLogLevel.Is.error

/-- Fatal logging, used to abort program: exit(EXIT_FAILURE) -/
def fatal : TraceLogLevel := Subtype.mk 6 TraceLogLevel.Is.fatal

/-- Disable logging -/
def none : TraceLogLevel := Subtype.mk 7 TraceLogLevel.Is.none

end TraceLogLevel

instance : Inhabited TraceLogLevel := ⟨TraceLogLevel.all⟩


/-! # Keyboard keys -/

inductive KeyboardKey.Is : UInt32 -> Prop where
  | null : KeyboardKey.Is 0
  | apostrophe : KeyboardKey.Is 39
  | comma : KeyboardKey.Is 44
  | minus : KeyboardKey.Is 45
  | period : KeyboardKey.Is 46
  | slash : KeyboardKey.Is 47
  | zero : KeyboardKey.Is 48
  | one : KeyboardKey.Is 49
  | two : KeyboardKey.Is 50
  | three : KeyboardKey.Is 51
  | four : KeyboardKey.Is 52
  | five : KeyboardKey.Is 53
  | six : KeyboardKey.Is 54
  | seven : KeyboardKey.Is 55
  | eight : KeyboardKey.Is 56
  | nine : KeyboardKey.Is 57
  | semicolon : KeyboardKey.Is 59
  | equal : KeyboardKey.Is 61
  | a : KeyboardKey.Is 65
  | b : KeyboardKey.Is 66
  | c : KeyboardKey.Is 67
  | d : KeyboardKey.Is 68
  | e : KeyboardKey.Is 69
  | f : KeyboardKey.Is 70
  | g : KeyboardKey.Is 71
  | h : KeyboardKey.Is 72
  | i : KeyboardKey.Is 73
  | j : KeyboardKey.Is 74
  | k : KeyboardKey.Is 75
  | l : KeyboardKey.Is 76
  | m : KeyboardKey.Is 77
  | n : KeyboardKey.Is 78
  | o : KeyboardKey.Is 79
  | p : KeyboardKey.Is 80
  | q : KeyboardKey.Is 81
  | r : KeyboardKey.Is 82
  | s : KeyboardKey.Is 83
  | t : KeyboardKey.Is 84
  | u : KeyboardKey.Is 85
  | v : KeyboardKey.Is 86
  | w : KeyboardKey.Is 87
  | x : KeyboardKey.Is 88
  | y : KeyboardKey.Is 89
  | z : KeyboardKey.Is 90
  | leftBracket : KeyboardKey.Is 91
  | backslash : KeyboardKey.Is 92
  | rightBracket : KeyboardKey.Is 93
  | grave : KeyboardKey.Is 96
  | space : KeyboardKey.Is 32
  | escape : KeyboardKey.Is 256
  | enter : KeyboardKey.Is 257
  | tab : KeyboardKey.Is 258
  | backspace : KeyboardKey.Is 259
  | insert : KeyboardKey.Is 260
  | delete : KeyboardKey.Is 261
  | right : KeyboardKey.Is 262
  | left : KeyboardKey.Is 263
  | down : KeyboardKey.Is 264
  | up : KeyboardKey.Is 265
  | pageUp : KeyboardKey.Is 266
  | pageDown : KeyboardKey.Is 267
  | home : KeyboardKey.Is 268
  | «end» : KeyboardKey.Is 269
  | capsLock : KeyboardKey.Is 280
  | scrollLock : KeyboardKey.Is 281
  | numLock : KeyboardKey.Is 282
  | printScreen : KeyboardKey.Is 283
  | pause : KeyboardKey.Is 284
  | f1 : KeyboardKey.Is 290
  | f2 : KeyboardKey.Is 291
  | f3 : KeyboardKey.Is 292
  | f4 : KeyboardKey.Is 293
  | f5 : KeyboardKey.Is 294
  | f6 : KeyboardKey.Is 295
  | f7 : KeyboardKey.Is 296
  | f8 : KeyboardKey.Is 297
  | f9 : KeyboardKey.Is 298
  | f10 : KeyboardKey.Is 299
  | f11 : KeyboardKey.Is 300
  | f12 : KeyboardKey.Is 301
  | leftShift : KeyboardKey.Is 340
  | leftControl : KeyboardKey.Is 341
  | leftAlt : KeyboardKey.Is 342
  | leftSuper : KeyboardKey.Is 343
  | rightShift : KeyboardKey.Is 344
  | rightControl : KeyboardKey.Is 345
  | rightAlt : KeyboardKey.Is 346
  | rightSuper : KeyboardKey.Is 347
  | kbMenu : KeyboardKey.Is 348
  | kp0 : KeyboardKey.Is 320
  | kp1 : KeyboardKey.Is 321
  | kp2 : KeyboardKey.Is 322
  | kp3 : KeyboardKey.Is 323
  | kp4 : KeyboardKey.Is 324
  | kp5 : KeyboardKey.Is 325
  | kp6 : KeyboardKey.Is 326
  | kp7 : KeyboardKey.Is 327
  | kp8 : KeyboardKey.Is 328
  | kp9 : KeyboardKey.Is 329
  | kpDecimal : KeyboardKey.Is 330
  | kpDivide : KeyboardKey.Is 331
  | kpMultiply : KeyboardKey.Is 332
  | kpSubtract : KeyboardKey.Is 333
  | kpAdd : KeyboardKey.Is 334
  | kpEnter : KeyboardKey.Is 335
  | kpEqual : KeyboardKey.Is 336
  | back : KeyboardKey.Is 4
  | menu : KeyboardKey.Is 82
  | volumeUp : KeyboardKey.Is 24
  | volumeDown : KeyboardKey.Is 25

/-- Keyboard keys (US keyboard layout) -/
def KeyboardKey : Type := Subtype KeyboardKey.Is

namespace KeyboardKey

/-- Used for no key pressed -/
def null : KeyboardKey := Subtype.mk 0 KeyboardKey.Is.null

/-- `'` -/
def apostrophe : KeyboardKey := Subtype.mk 39 KeyboardKey.Is.apostrophe

/-- `,` -/
def comma : KeyboardKey := Subtype.mk 44 KeyboardKey.Is.comma

/-- `-` -/
def minus : KeyboardKey := Subtype.mk 45 KeyboardKey.Is.minus

/-- `.` -/
def period : KeyboardKey := Subtype.mk 46 KeyboardKey.Is.period

/-- `/` -/
def slash : KeyboardKey := Subtype.mk 47 KeyboardKey.Is.slash

/-- `0` -/
def zero : KeyboardKey := Subtype.mk 48 KeyboardKey.Is.zero

/-- `1` -/
def one : KeyboardKey := Subtype.mk 49 KeyboardKey.Is.one

/-- `2` -/
def two : KeyboardKey := Subtype.mk 50 KeyboardKey.Is.two

/-- `3` -/
def three : KeyboardKey := Subtype.mk 51 KeyboardKey.Is.three

/-- `4` -/
def four : KeyboardKey := Subtype.mk 52 KeyboardKey.Is.four

/-- `5` -/
def five : KeyboardKey := Subtype.mk 53 KeyboardKey.Is.five

/-- `6` -/
def six : KeyboardKey := Subtype.mk 54 KeyboardKey.Is.six

/-- `7` -/
def seven : KeyboardKey := Subtype.mk 55 KeyboardKey.Is.seven

/-- `8` -/
def eight : KeyboardKey := Subtype.mk 56 KeyboardKey.Is.eight

/-- `9` -/
def nine : KeyboardKey := Subtype.mk 57 KeyboardKey.Is.nine

/-- `;` -/
def semicolon : KeyboardKey := Subtype.mk 59 KeyboardKey.Is.semicolon

/-- `=` -/
def equal : KeyboardKey := Subtype.mk 61 KeyboardKey.Is.equal

/-- `A` or `a` -/
def a : KeyboardKey := Subtype.mk 65 KeyboardKey.Is.a

/-- `B` or `b` -/
def b : KeyboardKey := Subtype.mk 66 KeyboardKey.Is.b

/-- `C` or `c` -/
def c : KeyboardKey := Subtype.mk 67 KeyboardKey.Is.c

/-- `D` or `d` -/
def d : KeyboardKey := Subtype.mk 68 KeyboardKey.Is.d

/-- `E` or `e` -/
def e : KeyboardKey := Subtype.mk 69 KeyboardKey.Is.e

/-- `F` or `f` -/
def f : KeyboardKey := Subtype.mk 70 KeyboardKey.Is.f

/-- `G` or `g` -/
def g : KeyboardKey := Subtype.mk 71 KeyboardKey.Is.g

/-- `H` or `h` -/
def h : KeyboardKey := Subtype.mk 72 KeyboardKey.Is.h

/-- `I` or `i` -/
def i : KeyboardKey := Subtype.mk 73 KeyboardKey.Is.i

/-- `J` or `j` -/
def j : KeyboardKey := Subtype.mk 74 KeyboardKey.Is.j

/-- `K` or `k` -/
def k : KeyboardKey := Subtype.mk 75 KeyboardKey.Is.k

/-- `L` or `l` -/
def l : KeyboardKey := Subtype.mk 76 KeyboardKey.Is.l

/-- `M` or `m` -/
def m : KeyboardKey := Subtype.mk 77 KeyboardKey.Is.m

/-- `N` or `n` -/
def n : KeyboardKey := Subtype.mk 78 KeyboardKey.Is.n

/-- `O` or `o` -/
def o : KeyboardKey := Subtype.mk 79 KeyboardKey.Is.o

/-- `P` or `p` -/
def p : KeyboardKey := Subtype.mk 80 KeyboardKey.Is.p

/-- `Q` or `q` -/
def q : KeyboardKey := Subtype.mk 81 KeyboardKey.Is.q

/-- `R` or `r` -/
def r : KeyboardKey := Subtype.mk 82 KeyboardKey.Is.r

/-- `S` or `s` -/
def s : KeyboardKey := Subtype.mk 83 KeyboardKey.Is.s

/-- `T` or `t` -/
def t : KeyboardKey := Subtype.mk 84 KeyboardKey.Is.t

/-- `U` or `u` -/
def u : KeyboardKey := Subtype.mk 85 KeyboardKey.Is.u

/-- `V` or `v` -/
def v : KeyboardKey := Subtype.mk 86 KeyboardKey.Is.v

/-- `W` or `w` -/
def w : KeyboardKey := Subtype.mk 87 KeyboardKey.Is.w

/-- `X` or `x` -/
def x : KeyboardKey := Subtype.mk 88 KeyboardKey.Is.x

/-- `Y` or `y` -/
def y : KeyboardKey := Subtype.mk 89 KeyboardKey.Is.y

/-- `Z` or `z` -/
def z : KeyboardKey := Subtype.mk 90 KeyboardKey.Is.z

/-- `[` -/
def leftBracket : KeyboardKey := Subtype.mk 91 KeyboardKey.Is.leftBracket

/-- `\` -/
def backslash : KeyboardKey := Subtype.mk 92 KeyboardKey.Is.backslash

/-- `]` -/
def rightBracket : KeyboardKey := Subtype.mk 93 KeyboardKey.Is.rightBracket

/-- `` ` ``-/
def grave : KeyboardKey := Subtype.mk 96 KeyboardKey.Is.grave

/-- Space -/
def space : KeyboardKey := Subtype.mk 32 KeyboardKey.Is.space

/-- Esc -/
def escape : KeyboardKey := Subtype.mk 256 KeyboardKey.Is.escape

/-- Enter -/
def enter : KeyboardKey := Subtype.mk 257 KeyboardKey.Is.enter

/-- Tab -/
def tab : KeyboardKey := Subtype.mk 258 KeyboardKey.Is.tab

/-- Backspace -/
def backspace : KeyboardKey := Subtype.mk 259 KeyboardKey.Is.backspace

/-- Ins -/
def insert : KeyboardKey := Subtype.mk 260 KeyboardKey.Is.insert

/-- Del -/
def delete : KeyboardKey := Subtype.mk 261 KeyboardKey.Is.delete

/-- Cursor right -/
def right : KeyboardKey := Subtype.mk 262 KeyboardKey.Is.right

/-- Cursor left -/
def left : KeyboardKey := Subtype.mk 263 KeyboardKey.Is.left

/-- Cursor down -/
def down : KeyboardKey := Subtype.mk 264 KeyboardKey.Is.down

/-- Cursor up -/
def up : KeyboardKey := Subtype.mk 265 KeyboardKey.Is.up

/-- Page up -/
def pageUp : KeyboardKey := Subtype.mk 266 KeyboardKey.Is.pageUp

/-- Page down -/
def pageDown : KeyboardKey := Subtype.mk 267 KeyboardKey.Is.pageDown

/-- Home -/
def home : KeyboardKey := Subtype.mk 268 KeyboardKey.Is.home

/-- End -/
def «end» : KeyboardKey := Subtype.mk 269 KeyboardKey.Is.end

/-- Caps lock -/
def capsLock : KeyboardKey := Subtype.mk 280 KeyboardKey.Is.capsLock

/-- Scroll down -/
def scrollLock : KeyboardKey := Subtype.mk 281 KeyboardKey.Is.scrollLock

/-- Num lock -/
def numLock : KeyboardKey := Subtype.mk 282 KeyboardKey.Is.numLock

/-- Print screen -/
def printScreen : KeyboardKey := Subtype.mk 283 KeyboardKey.Is.printScreen

/-- Pause -/
def pause : KeyboardKey := Subtype.mk 284 KeyboardKey.Is.pause

/-- `F1` -/
def f1 : KeyboardKey := Subtype.mk 290 KeyboardKey.Is.f1

/-- `F2` -/
def f2 : KeyboardKey := Subtype.mk 291 KeyboardKey.Is.f2

/-- `F3` -/
def f3 : KeyboardKey := Subtype.mk 292 KeyboardKey.Is.f3

/-- `F4` -/
def f4 : KeyboardKey := Subtype.mk 293 KeyboardKey.Is.f4

/-- `F5` -/
def f5 : KeyboardKey := Subtype.mk 294 KeyboardKey.Is.f5

/-- `F6` -/
def f6 : KeyboardKey := Subtype.mk 295 KeyboardKey.Is.f6

/-- `F7` -/
def f7 : KeyboardKey := Subtype.mk 296 KeyboardKey.Is.f7

/-- `F8` -/
def f8 : KeyboardKey := Subtype.mk 297 KeyboardKey.Is.f8

/-- `F9` -/
def f9 : KeyboardKey := Subtype.mk 298 KeyboardKey.Is.f9

/-- `F10` -/
def f10 : KeyboardKey := Subtype.mk 299 KeyboardKey.Is.f10

/-- `F11` -/
def f11 : KeyboardKey := Subtype.mk 300 KeyboardKey.Is.f11

/-- `F12` -/
def f12 : KeyboardKey := Subtype.mk 301 KeyboardKey.Is.f12

/-- Left Shift -/
def leftShift : KeyboardKey := Subtype.mk 340 KeyboardKey.Is.leftShift

/-- Left Control -/
def leftControl : KeyboardKey := Subtype.mk 341 KeyboardKey.Is.leftControl

/-- Left Alt -/
def leftAlt : KeyboardKey := Subtype.mk 342 KeyboardKey.Is.leftAlt

/-- Left Super -/
def leftSuper : KeyboardKey := Subtype.mk 343 KeyboardKey.Is.leftSuper

/-- Right Shift -/
def rightShift : KeyboardKey := Subtype.mk 344 KeyboardKey.Is.rightShift

/-- Right Control -/
def rightControl : KeyboardKey := Subtype.mk 345 KeyboardKey.Is.rightControl

/-- Right Alt -/
def rightAlt : KeyboardKey := Subtype.mk 346 KeyboardKey.Is.rightAlt

/-- Right Super -/
def rightSuper : KeyboardKey := Subtype.mk 347 KeyboardKey.Is.rightSuper

/-- KB menu -/
def kbMenu : KeyboardKey := Subtype.mk 348 KeyboardKey.Is.kbMenu

/-- Keypad `0` -/
def kp0 : KeyboardKey := Subtype.mk 320 KeyboardKey.Is.kp0

/-- Keypad `1` -/
def kp1 : KeyboardKey := Subtype.mk 321 KeyboardKey.Is.kp1

/-- Keypad `2` -/
def kp2 : KeyboardKey := Subtype.mk 322 KeyboardKey.Is.kp2

/-- Keypad `3` -/
def kp3 : KeyboardKey := Subtype.mk 323 KeyboardKey.Is.kp3

/-- Keypad `4` -/
def kp4 : KeyboardKey := Subtype.mk 324 KeyboardKey.Is.kp4

/-- Keypad `5` -/
def kp5 : KeyboardKey := Subtype.mk 325 KeyboardKey.Is.kp5

/-- Keypad `6` -/
def kp6 : KeyboardKey := Subtype.mk 326 KeyboardKey.Is.kp6

/-- Keypad `7` -/
def kp7 : KeyboardKey := Subtype.mk 327 KeyboardKey.Is.kp7

/-- Keypad `8` -/
def kp8 : KeyboardKey := Subtype.mk 328 KeyboardKey.Is.kp8

/-- Keypad `9` -/
def kp9 : KeyboardKey := Subtype.mk 329 KeyboardKey.Is.kp9

/-- Keypad `.` -/
def kpDecimal : KeyboardKey := Subtype.mk 330 KeyboardKey.Is.kpDecimal

/-- Keypad `/` -/
def kpDivide : KeyboardKey := Subtype.mk 331 KeyboardKey.Is.kpDivide

/-- Keypad `*` -/
def kpMultiply : KeyboardKey := Subtype.mk 332 KeyboardKey.Is.kpMultiply

/-- Keypad `-` -/
def kpSubtract : KeyboardKey := Subtype.mk 333 KeyboardKey.Is.kpSubtract

/-- Keypad `+` -/
def kpAdd : KeyboardKey := Subtype.mk 334 KeyboardKey.Is.kpAdd

/-- Keypad Enter -/
def kpEnter : KeyboardKey := Subtype.mk 335 KeyboardKey.Is.kpEnter

/-- Keypad `=` -/
def kpEqual : KeyboardKey := Subtype.mk 336 KeyboardKey.Is.kpEqual

/-- Android back button -/
def back : KeyboardKey := Subtype.mk 4 KeyboardKey.Is.back

/-- Android menu button -/
def menu : KeyboardKey := Subtype.mk 82 KeyboardKey.Is.menu

/-- Android volume up button -/
def volumeUp : KeyboardKey := Subtype.mk 24 KeyboardKey.Is.volumeUp

/-- Android volume down button -/
def volumeDown : KeyboardKey := Subtype.mk 25 KeyboardKey.Is.volumeDown

end KeyboardKey

instance : Inhabited KeyboardKey := ⟨KeyboardKey.null⟩


/-! # Mouse buttons -/

inductive MouseButton.Is : UInt32 -> Prop where
  | left : MouseButton.Is 0
  | right : MouseButton.Is 1
  | middle : MouseButton.Is 2
  | side : MouseButton.Is 3
  | extra : MouseButton.Is 4
  | forward : MouseButton.Is 5
  | back : MouseButton.Is 6

/-- Mouse buttons -/
def MouseButton : Type := Subtype MouseButton.Is

namespace MouseButton

/-- Mouse button left -/
def left : MouseButton := Subtype.mk 0 MouseButton.Is.left
/-- Mouse button right -/
def Right : MouseButton := Subtype.mk 1 MouseButton.Is.right
/-- Mouse button middle (pressed wheel) -/
def middle : MouseButton := Subtype.mk 2 MouseButton.Is.middle
/-- Mouse button side (advanced mouse device) -/
def side : MouseButton := Subtype.mk 3 MouseButton.Is.side
/-- Mouse button extra (advanced mouse device) -/
def extra : MouseButton := Subtype.mk 4 MouseButton.Is.extra
/-- Mouse button forward (advanced mouse device) -/
def forward : MouseButton := Subtype.mk 5 MouseButton.Is.forward
/-- Mouse button back (advanced mouse device) -/
def back : MouseButton := Subtype.mk 6 MouseButton.Is.back

end MouseButton

instance : Inhabited MouseButton := ⟨MouseButton.left⟩


/-! # Mouse cursors -/

inductive MouseCursor.Is : UInt32 -> Prop where
  | default : MouseCursor.Is 0
  | arrow : MouseCursor.Is 1
  | ibeam : MouseCursor.Is 2
  | crosshair : MouseCursor.Is 3
  | pointingHand : MouseCursor.Is 4
  | resizeEw : MouseCursor.Is 5
  | resizeNs : MouseCursor.Is 6
  | resizeNwse : MouseCursor.Is 7
  | resizeNesw : MouseCursor.Is 8
  | resizeAll : MouseCursor.Is 9
  | notAllowed : MouseCursor.Is 10

def MouseCursor : Type := Subtype MouseCursor.Is

namespace MouseCursor

/-- Default pointer shape -/
def default : MouseCursor := Subtype.mk 0 MouseCursor.Is.default
/-- Arrow shape -/
def arrow : MouseCursor := Subtype.mk 1 MouseCursor.Is.arrow
/-- Text writing cursor shape -/
def ibeam : MouseCursor := Subtype.mk 2 MouseCursor.Is.ibeam
/-- Cross shape -/
def crosshair : MouseCursor := Subtype.mk 3 MouseCursor.Is.crosshair
/-- Pointing hand cursor -/
def pointingHand : MouseCursor := Subtype.mk 4 MouseCursor.Is.pointingHand
/-- Horizontal resize/move arrow shape -/
def resizeEw : MouseCursor := Subtype.mk 5 MouseCursor.Is.resizeEw
/-- Vertical resize/move arrow shape -/
def resizeNs : MouseCursor := Subtype.mk 6 MouseCursor.Is.resizeNs
/-- Top-left to bottom-right diagonal resize/move arrow shape -/
def resizeNwse : MouseCursor := Subtype.mk 7 MouseCursor.Is.resizeNwse
/-- The top-right to bottom-left diagonal resize/move arrow shape -/
def resizeNesw : MouseCursor := Subtype.mk 8 MouseCursor.Is.resizeNesw
/-- The omnidirectional resize/move cursor shape -/
def resizeAll : MouseCursor := Subtype.mk 9 MouseCursor.Is.resizeAll
/-- The operation-not-allowed shape -/
def notAllowed : MouseCursor := Subtype.mk 10 MouseCursor.Is.notAllowed

end MouseCursor

instance : Inhabited MouseCursor := ⟨MouseCursor.default⟩


/-! # Gamepad buttons -/

inductive GamepadButton.Is : UInt32 -> Prop where
  | unknown : GamepadButton.Is 0
  | leftFaceUp : GamepadButton.Is 1
  | leftFaceRight : GamepadButton.Is 2
  | leftFaceDown : GamepadButton.Is 3
  | leftFaceLeft : GamepadButton.Is 4
  | rightFaceUp : GamepadButton.Is 5
  | rightFaceRight : GamepadButton.Is 6
  | rightFaceDown : GamepadButton.Is 7
  | rightFaceLeft : GamepadButton.Is 8
  | leftTrigger1 : GamepadButton.Is 9
  | leftTrigger2 : GamepadButton.Is 10
  | rightTrigger1 : GamepadButton.Is 11
  | rightTrigger2 : GamepadButton.Is 12
  | middleLeft : GamepadButton.Is 13
  | middle : GamepadButton.Is 14
  | middleRight : GamepadButton.Is 15
  | leftThumb : GamepadButton.Is 16
  | rightThumb : GamepadButton.Is 17

/-- Gamepad buttons -/
def GamepadButton : Type := Subtype GamepadButton.Is

namespace GamepadButton

/-- Unknown button, just for error checking -/
def unknown : GamepadButton := Subtype.mk 0 GamepadButton.Is.unknown
/-- Gamepad left DPAD up button -/
def leftFaceUp : GamepadButton := Subtype.mk 1 GamepadButton.Is.leftFaceUp
/-- Gamepad left DPAD right button -/
def leftFaceRight : GamepadButton := Subtype.mk 2 GamepadButton.Is.leftFaceRight
/-- Gamepad left DPAD down button -/
def leftFaceDown : GamepadButton := Subtype.mk 3 GamepadButton.Is.leftFaceDown
/-- Gamepad left DPAD left button -/
def leftFaceLeft : GamepadButton := Subtype.mk 4 GamepadButton.Is.leftFaceLeft
/-- Gamepad right button up (i.e. PS3: Triangle, Xbox: Y) -/
def rightFaceUp : GamepadButton := Subtype.mk 5 GamepadButton.Is.rightFaceUp
/-- Gamepad right button right (i.e. PS3: Square, Xbox: X) -/
def rightFaceRight : GamepadButton := Subtype.mk 6 GamepadButton.Is.rightFaceRight
/-- Gamepad right button down (i.e. PS3: Cross, Xbox: A) -/
def rightFaceDown : GamepadButton := Subtype.mk 7 GamepadButton.Is.rightFaceDown
/-- Gamepad right button left (i.e. PS3: Circle, Xbox: B) -/
def rightFaceLeft : GamepadButton := Subtype.mk 8 GamepadButton.Is.rightFaceLeft
/-- Gamepad top/back trigger left (first), it could be a trailing button -/
def leftTrigger1 : GamepadButton := Subtype.mk 9 GamepadButton.Is.leftTrigger1
/-- Gamepad top/back trigger left (second), it could be a trailing button -/
def leftTrigger2 : GamepadButton := Subtype.mk 10 GamepadButton.Is.leftTrigger2
/-- Gamepad top/back trigger right (one), it could be a trailing button -/
def rightTrigger1 : GamepadButton := Subtype.mk 11 GamepadButton.Is.rightTrigger1
/-- Gamepad top/back trigger right (second), it could be a trailing button -/
def rightTrigger2 : GamepadButton := Subtype.mk 12 GamepadButton.Is.rightTrigger2
/-- Gamepad center buttons, left one (i.e. PS3: Select) -/
def middleLeft : GamepadButton := Subtype.mk 13 GamepadButton.Is.middleLeft
/-- Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX) -/
def middle : GamepadButton := Subtype.mk 14 GamepadButton.Is.middle
/-- Gamepad center buttons, right one (i.e. PS3: Start) -/
def middleRight : GamepadButton := Subtype.mk 15 GamepadButton.Is.middleRight
/-- Gamepad joystick pressed button left -/
def leftThumb : GamepadButton := Subtype.mk 16 GamepadButton.Is.leftThumb
/-- Gamepad joystick pressed button right -/
def rightThumb : GamepadButton := Subtype.mk 17 GamepadButton.Is.rightThumb

end GamepadButton

instance : Inhabited GamepadButton := ⟨GamepadButton.unknown⟩


/-! # Gamepad axis -/

inductive GamepadAxis.Is : UInt32 -> Prop where
  | leftX : GamepadAxis.Is 0
  | leftY : GamepadAxis.Is 1
  | rightX : GamepadAxis.Is 2
  | rightY : GamepadAxis.Is 3
  | leftTrigger : GamepadAxis.Is 4
  | rightTrigger : GamepadAxis.Is 5

/-- Gamepad axis -/
def GamepadAxis : Type := Subtype GamepadAxis.Is

/-- Gamepad left stick X axis -/
def leftX : GamepadAxis := Subtype.mk 0 GamepadAxis.Is.leftX
/-- Gamepad left stick Y axis -/
def leftY : GamepadAxis := Subtype.mk 1 GamepadAxis.Is.leftY
/-- Gamepad right stick X axis -/
def rightX : GamepadAxis := Subtype.mk 2 GamepadAxis.Is.rightX
/-- Gamepad right stick Y axis -/
def rightY : GamepadAxis := Subtype.mk 3 GamepadAxis.Is.rightY
/-- Gamepad back trigger left, pressure level: [1..-1] -/
def leftTrigger : GamepadAxis := Subtype.mk 4 GamepadAxis.Is.leftTrigger
/-- Gamepad back trigger right, pressure level: [1..-1] -/
def rightTrigger : GamepadAxis := Subtype.mk 5 GamepadAxis.Is.rightTrigger


/-! # Material map indices -/

def maxMaterialMaps := 12

def MaterialMapIndex : Type := Subtype (· < maxMaterialMaps.toUInt32)

namespace MaterialMapIndex

/-- Albedo material (same as: diffuse) -/
def albedo : MaterialMapIndex := Subtype.mk 0 (by decide)
/-- Diffuse material (same as: albedo) -/
abbrev diffuse : MaterialMapIndex := albedo
/-- Metalness material (same as: specular) -/
def metalness : MaterialMapIndex := Subtype.mk 1 (by decide)
/-- Specular material (same as: metalness) -/
abbrev specular : MaterialMapIndex := metalness
/-- Normal material -/
def normal : MaterialMapIndex := Subtype.mk 2 (by decide)
/-- Roughness material -/
def roughness : MaterialMapIndex := Subtype.mk 3 (by decide)
/-- Ambient occlusion material -/
def occlusion : MaterialMapIndex := Subtype.mk 4 (by decide)
/-- Emission material -/
def emission : MaterialMapIndex := Subtype.mk 5 (by decide)
/-- Heightmap material -/
def height : MaterialMapIndex := Subtype.mk 6 (by decide)
/-- Cubemap material (NOTE: Uses `GL_TEXTURE_CUBE_MAP`) -/
def cubemap : MaterialMapIndex := Subtype.mk 7 (by decide)
/-- Irradiance material (NOTE: Uses `GL_TEXTURE_CUBE_MAP`) -/
def irradiance : MaterialMapIndex := Subtype.mk 8 (by decide)
/-- Prefilter material (NOTE: Uses `GL_TEXTURE_CUBE_MAP`) -/
def prefilter : MaterialMapIndex := Subtype.mk 9 (by decide)
/-- Brdf material -/
def brdf : MaterialMapIndex := Subtype.mk 10 (by decide)
/-- Custom material -/
def custom : MaterialMapIndex := Subtype.mk 11 (by decide)

end MaterialMapIndex

instance : Inhabited MaterialMapIndex := ⟨MaterialMapIndex.albedo⟩


/-! # Shader location index -/

inductive ShaderLocationIndex.Is : UInt32 -> Prop where
  | vertexPosition : ShaderLocationIndex.Is 0
  | vertexTexcoord01 : ShaderLocationIndex.Is 1
  | vertexTexcoord02 : ShaderLocationIndex.Is 2
  | vertexNormal : ShaderLocationIndex.Is 3
  | vertexTangent : ShaderLocationIndex.Is 4
  | vertexColor : ShaderLocationIndex.Is 5
  | matrixMvp : ShaderLocationIndex.Is 6
  | matrixView : ShaderLocationIndex.Is 7
  | matrixProjection : ShaderLocationIndex.Is 8
  | matrixModel : ShaderLocationIndex.Is 9
  | matrixNormal : ShaderLocationIndex.Is 10
  | vectorView : ShaderLocationIndex.Is 11
  | colorDiffuse : ShaderLocationIndex.Is 12
  | colorSpecular : ShaderLocationIndex.Is 13
  | colorAmbient : ShaderLocationIndex.Is 14
  | mapAlbedo : ShaderLocationIndex.Is 15
  | mapMetalness : ShaderLocationIndex.Is 16
  | mapNormal : ShaderLocationIndex.Is 17
  | mapRoughness : ShaderLocationIndex.Is 18
  | mapOcclusion : ShaderLocationIndex.Is 19
  | mapEmission : ShaderLocationIndex.Is 20
  | mapHeight : ShaderLocationIndex.Is 21
  | mapCubemap : ShaderLocationIndex.Is 22
  | mapIrradiance : ShaderLocationIndex.Is 23
  | mapPrefilter : ShaderLocationIndex.Is 24
  | mapBrdf : ShaderLocationIndex.Is 25

def ShaderLocationIndex : Type := Subtype ShaderLocationIndex.Is

namespace ShaderLocationIndex

/-- Shader location: vertex attribute: position -/
def vertexPosition : ShaderLocationIndex := Subtype.mk 0 ShaderLocationIndex.Is.vertexPosition
/-- Shader location: vertex attribute: texcoord01 -/
def vertexTexcoord01 : ShaderLocationIndex := Subtype.mk 1 ShaderLocationIndex.Is.vertexTexcoord01
/-- Shader location: vertex attribute: texcoord02 -/
def vertexTexcoord02 : ShaderLocationIndex := Subtype.mk 2 ShaderLocationIndex.Is.vertexTexcoord02
/-- Shader location: vertex attribute: normal -/
def vertexNormal : ShaderLocationIndex := Subtype.mk 3 ShaderLocationIndex.Is.vertexNormal
/-- Shader location: vertex attribute: tangent -/
def vertexTangent : ShaderLocationIndex := Subtype.mk 4 ShaderLocationIndex.Is.vertexTangent
/-- Shader location: vertex attribute: color -/
def vertexColor : ShaderLocationIndex := Subtype.mk 5 ShaderLocationIndex.Is.vertexColor
/-- Shader location: matrix uniform: model-view-projection -/
def matrixMvp : ShaderLocationIndex := Subtype.mk 6 ShaderLocationIndex.Is.matrixMvp
/-- Shader location: matrix uniform: view (camera transform) -/
def matrixView : ShaderLocationIndex := Subtype.mk 7 ShaderLocationIndex.Is.matrixView
/-- Shader location: matrix uniform: projection -/
def matrixProjection : ShaderLocationIndex := Subtype.mk 8 ShaderLocationIndex.Is.matrixProjection
/-- Shader location: matrix uniform: model (transform) -/
def matrixModel : ShaderLocationIndex := Subtype.mk 9 ShaderLocationIndex.Is.matrixModel
/-- Shader location: matrix uniform: normal -/
def matrixNormal : ShaderLocationIndex := Subtype.mk 10 ShaderLocationIndex.Is.matrixNormal
/-- Shader location: vector uniform: view -/
def vectorView : ShaderLocationIndex := Subtype.mk 11 ShaderLocationIndex.Is.vectorView
/-- Shader location: vector uniform: diffuse color -/
def colorDiffuse : ShaderLocationIndex := Subtype.mk 12 ShaderLocationIndex.Is.colorDiffuse
/-- Shader location: vector uniform: specular color -/
def colorSpecular : ShaderLocationIndex := Subtype.mk 13 ShaderLocationIndex.Is.colorSpecular
/-- Shader location: vector uniform: ambient color -/
def colorAmbient : ShaderLocationIndex := Subtype.mk 14 ShaderLocationIndex.Is.colorAmbient
/-- Shader location: sampler2d texture: albedo (same as: mapDiffuse) -/
def mapAlbedo : ShaderLocationIndex := Subtype.mk 15 ShaderLocationIndex.Is.mapAlbedo
/-- Shader location: sampler2d texture: metalness (same as: mapSpecular) -/
def mapMetalness : ShaderLocationIndex := Subtype.mk 16 ShaderLocationIndex.Is.mapMetalness
/-- Shader location: sampler2d texture: normal -/
def mapNormal : ShaderLocationIndex := Subtype.mk 17 ShaderLocationIndex.Is.mapNormal
/-- Shader location: sampler2d texture: roughness -/
def mapRoughness : ShaderLocationIndex := Subtype.mk 18 ShaderLocationIndex.Is.mapRoughness
/-- Shader location: sampler2d texture: occlusion -/
def mapOcclusion : ShaderLocationIndex := Subtype.mk 19 ShaderLocationIndex.Is.mapOcclusion
/-- Shader location: sampler2d texture: emission -/
def mapEmission : ShaderLocationIndex := Subtype.mk 20 ShaderLocationIndex.Is.mapEmission
/-- Shader location: sampler2d texture: height -/
def mapHeight : ShaderLocationIndex := Subtype.mk 21 ShaderLocationIndex.Is.mapHeight
/-- Shader location: samplerCube texture: cubemap -/
def mapCubemap : ShaderLocationIndex := Subtype.mk 22 ShaderLocationIndex.Is.mapCubemap
/-- Shader location: samplerCube texture: irradiance -/
def mapIrradiance : ShaderLocationIndex := Subtype.mk 23 ShaderLocationIndex.Is.mapIrradiance
/-- Shader location: samplerCube texture: prefilter -/
def mapPrefilter : ShaderLocationIndex := Subtype.mk 24 ShaderLocationIndex.Is.mapPrefilter
/-- Shader location: sampler2d texture: brdf -/
def mapBrdf : ShaderLocationIndex := Subtype.mk 25 ShaderLocationIndex.Is.mapBrdf

end ShaderLocationIndex

instance : Inhabited ShaderLocationIndex := ⟨ShaderLocationIndex.vertexPosition⟩


/-! # Shader uniform data type -/

inductive ShaderUniformDataType.Is : UInt32 -> Prop where
  | float : ShaderUniformDataType.Is 0
  | vec2 : ShaderUniformDataType.Is 1
  | vec3 : ShaderUniformDataType.Is 2
  | vec4 : ShaderUniformDataType.Is 3
  | int : ShaderUniformDataType.Is 4
  | ivec2 : ShaderUniformDataType.Is 5
  | ivec3 : ShaderUniformDataType.Is 6
  | ivec4 : ShaderUniformDataType.Is 7
  | sampler2d : ShaderUniformDataType.Is 8

def ShaderUniformDataType : Type := Subtype ShaderUniformDataType.Is

namespace ShaderUniformDataType

/-- Shader uniform type: float -/
def float : ShaderUniformDataType := Subtype.mk 0 ShaderUniformDataType.Is.float
/-- Shader uniform type: vec2 (2 float) -/
def vec2 : ShaderUniformDataType := Subtype.mk 1 ShaderUniformDataType.Is.vec2
/-- Shader uniform type: vec3 (3 float) -/
def vec3 : ShaderUniformDataType := Subtype.mk 2 ShaderUniformDataType.Is.vec3
/-- Shader uniform type: vec4 (4 float) -/
def vec4 : ShaderUniformDataType := Subtype.mk 3 ShaderUniformDataType.Is.vec4
/-- Shader uniform type: int -/
def int : ShaderUniformDataType := Subtype.mk 4 ShaderUniformDataType.Is.int
/-- Shader uniform type: ivec2 (2 int) -/
def ivec2 : ShaderUniformDataType := Subtype.mk 5 ShaderUniformDataType.Is.ivec2
/-- Shader uniform type: ivec3 (3 int) -/
def ivec3 : ShaderUniformDataType := Subtype.mk 6 ShaderUniformDataType.Is.ivec3
/-- Shader uniform type: ivec4 (4 int) -/
def ivec4 : ShaderUniformDataType := Subtype.mk 7 ShaderUniformDataType.Is.ivec4
/-- Shader uniform type: sampler2d -/
def sampler2d : ShaderUniformDataType := Subtype.mk 8 ShaderUniformDataType.Is.sampler2d

end ShaderUniformDataType

instance : Inhabited ShaderUniformDataType := ⟨ShaderUniformDataType.float⟩

def ShaderUniformDataType.lift : ShaderUniformDataType → Type
    | ⟨⟨0, _⟩, _⟩ => Pod.Float32
    | ⟨⟨1, _⟩, _⟩ => Raymath.Vector2
    | ⟨⟨2, _⟩, _⟩ => Raymath.Vector3
    | ⟨⟨3, _⟩, _⟩ => Raymath.Vector4
    | ⟨⟨4, _⟩, _⟩ => Int32
    | ⟨⟨5, _⟩, _⟩ => Int32 × Int32
    | ⟨⟨6, _⟩, _⟩ => Int32 × Int32 × Int32
    | ⟨⟨7, _⟩, _⟩ => Int32 × Int32 × Int32 × Int32
    | ⟨⟨8, _⟩, _⟩ => UInt32


/-! # Shader attribute data type -/

inductive ShaderAttributeDataType.Is : UInt32 -> Prop where
  | float : ShaderAttributeDataType.Is 0
  | vec2 : ShaderAttributeDataType.Is 1
  | vec3 : ShaderAttributeDataType.Is 2
  | vec4 : ShaderAttributeDataType.Is 3

def ShaderAttributeDataType : Type := Subtype ShaderAttributeDataType.Is

namespace ShaderAttributeDataType

/-- Shader attribute type: float -/
def float : ShaderAttributeDataType := Subtype.mk 0 ShaderAttributeDataType.Is.float
/-- Shader attribute type: vec2 (2 float) -/
def vec2 : ShaderAttributeDataType := Subtype.mk 1 ShaderAttributeDataType.Is.vec2
/-- Shader attribute type: vec3 (3 float) -/
def vec3 : ShaderAttributeDataType := Subtype.mk 2 ShaderAttributeDataType.Is.vec3
/-- Shader attribute type: vec4 (4 float) -/
def vec4 : ShaderAttributeDataType := Subtype.mk 3 ShaderAttributeDataType.Is.vec4

end ShaderAttributeDataType

instance : Inhabited ShaderAttributeDataType := ⟨ShaderAttributeDataType.float⟩ 


/-! # Pixel format -/

inductive PixelFormat.Is : UInt32 -> Prop where
  | uncompressedGrayscale : PixelFormat.Is 1
  | uncompressedGrayAlpha : PixelFormat.Is 2
  | uncompressedR5g6b5 : PixelFormat.Is 3
  | uncompressedR8g8b8 : PixelFormat.Is 4
  | uncompressedR5g5b5a1 : PixelFormat.Is 5
  | uncompressedR4g4b4a4 : PixelFormat.Is 6
  | uncompressedR8g8b8a8 : PixelFormat.Is 7
  | uncompressedR32 : PixelFormat.Is 8
  | uncompressedR32g32b32 : PixelFormat.Is 9
  | uncompressedR32g32b32a32 : PixelFormat.Is 10
  | compressedDxt1Rgb : PixelFormat.Is 11
  | compressedDxt1Rgba : PixelFormat.Is 12
  | compressedDxt3Rgba : PixelFormat.Is 13
  | compressedDxt5Rgba : PixelFormat.Is 14
  | compressedEtc1Rgb : PixelFormat.Is 15
  | compressedEtc2Rgb : PixelFormat.Is 16
  | compressedEtc2EacRgba : PixelFormat.Is 17
  | compressedPvrtRgb : PixelFormat.Is 18
  | compressedPvrtRgba : PixelFormat.Is 19
  | compressedAstc4x4Rgba : PixelFormat.Is 20
  | compressedAstc8x8Rgba : PixelFormat.Is 21

def PixelFormat : Type := Subtype PixelFormat.Is

namespace PixelFormat

/-- 8 bit per pixel (no alpha) -/
def uncompressedGrayscale : PixelFormat := Subtype.mk 1 PixelFormat.Is.uncompressedGrayscale
/-- 8*2 bpp (2 channels) -/
def uncompressedGrayAlpha : PixelFormat := Subtype.mk 2 PixelFormat.Is.uncompressedGrayAlpha
/-- 16 bpp -/
def uncompressedR5g6b5 : PixelFormat := Subtype.mk 3 PixelFormat.Is.uncompressedR5g6b5
/-- 24 bpp -/
def uncompressedR8g8b8 : PixelFormat := Subtype.mk 4 PixelFormat.Is.uncompressedR8g8b8
/-- 16 bpp (1 bit alpha) -/
def uncompressedR5g5b5a1 : PixelFormat := Subtype.mk 5 PixelFormat.Is.uncompressedR5g5b5a1
/-- 16 bpp (4 bit alpha) -/
def uncompressedR4g4b4a4 : PixelFormat := Subtype.mk 6 PixelFormat.Is.uncompressedR4g4b4a4
/-- 32 bpp -/
def uncompressedR8g8b8a8 : PixelFormat := Subtype.mk 7 PixelFormat.Is.uncompressedR8g8b8a8
/-- 32 bpp (1 channel - float) -/
def uncompressedR32 : PixelFormat := Subtype.mk 8 PixelFormat.Is.uncompressedR32
/-- 32*3 bpp (3 channels - float) -/
def uncompressedR32g32b32 : PixelFormat := Subtype.mk 9 PixelFormat.Is.uncompressedR32g32b32
/-- 32*4 bpp (4 channels - float) -/
def uncompressedR32g32b32a32 : PixelFormat := Subtype.mk 10 PixelFormat.Is.uncompressedR32g32b32a32
/-- 4 bpp (no alpha) -/
def compressedDxt1Rgb : PixelFormat := Subtype.mk 11 PixelFormat.Is.compressedDxt1Rgb
/-- 4 bpp (1 bit alpha) -/
def compressedDxt1Rgba : PixelFormat := Subtype.mk 12 PixelFormat.Is.compressedDxt1Rgba
/-- 8 bpp -/
def compressedDxt3Rgba : PixelFormat := Subtype.mk 13 PixelFormat.Is.compressedDxt3Rgba
/-- 8 bpp -/
def compressedDxt5Rgba : PixelFormat := Subtype.mk 14 PixelFormat.Is.compressedDxt5Rgba
/-- 4 bpp -/
def compressedEtc1Rgb : PixelFormat := Subtype.mk 15 PixelFormat.Is.compressedEtc1Rgb
/-- 4 bpp -/
def compressedEtc2Rgb : PixelFormat := Subtype.mk 16 PixelFormat.Is.compressedEtc2Rgb
/-- 8 bpp -/
def compressedEtc2EacRgba : PixelFormat := Subtype.mk 17 PixelFormat.Is.compressedEtc2EacRgba
/-- 4 bpp -/
def compressedPvrtRgb : PixelFormat := Subtype.mk 18 PixelFormat.Is.compressedPvrtRgb
/-- 4 bpp -/
def compressedPvrtRgba : PixelFormat := Subtype.mk 19 PixelFormat.Is.compressedPvrtRgba
/-- 8 bpp -/
def compressedAstc4x4Rgba : PixelFormat := Subtype.mk 20 PixelFormat.Is.compressedAstc4x4Rgba
/-- 2 bpp -/
def compressedAstc8x8Rgba : PixelFormat := Subtype.mk 21 PixelFormat.Is.compressedAstc8x8Rgba

end PixelFormat

instance : Inhabited PixelFormat := ⟨PixelFormat.uncompressedR8g8b8a8⟩

def PixelFormat.bpp : PixelFormat → Nat
  | ⟨⟨1, _⟩, _⟩ => 8
  | ⟨⟨2, _⟩, _⟩ => 16
  | ⟨⟨3, _⟩, _⟩ => 16
  | ⟨⟨4, _⟩, _⟩ => 24
  | ⟨⟨5, _⟩, _⟩ => 16
  | ⟨⟨6, _⟩, _⟩ => 16
  | ⟨⟨7, _⟩, _⟩ => 32
  | ⟨⟨8, _⟩, _⟩ => 32
  | ⟨⟨9, _⟩, _⟩ => 96
  | ⟨⟨10, _⟩, _⟩ => 128
  | ⟨⟨11, _⟩, _⟩ => 4
  | ⟨⟨12, _⟩, _⟩ => 4
  | ⟨⟨13, _⟩, _⟩ => 8
  | ⟨⟨14, _⟩, _⟩ => 8
  | ⟨⟨15, _⟩, _⟩ => 4
  | ⟨⟨16, _⟩, _⟩ => 4
  | ⟨⟨17, _⟩, _⟩ => 8
  | ⟨⟨18, _⟩, _⟩ => 4
  | ⟨⟨19, _⟩, _⟩ => 4
  | ⟨⟨20, _⟩, _⟩ => 8
  | ⟨⟨21, _⟩, _⟩ => 2

def PixelFormat.bytesPerPixel (format : PixelFormat) : Nat := (format.bpp + 7) / 8


/-! # Texture filter -/

inductive TextureFilter.Is : UInt32 -> Prop where
  | point : TextureFilter.Is 0
  | bilinear : TextureFilter.Is 1
  | trilinear : TextureFilter.Is 2
  | anisotropic4x : TextureFilter.Is 3
  | anisotropic8x : TextureFilter.Is 4
  | anisotropic16x : TextureFilter.Is 5

/-- Texture parameters: filter mode -/
def TextureFilter : Type := Subtype TextureFilter.Is

namespace TextureFilter

/-- No filter, just pixel approximation -/
def point : TextureFilter := Subtype.mk 0 TextureFilter.Is.point
/-- Linear filtering -/
def bilinear : TextureFilter := Subtype.mk 1 TextureFilter.Is.bilinear
/-- Trilinear filtering (linear with mipmaps) -/
def trilinear : TextureFilter := Subtype.mk 2 TextureFilter.Is.trilinear
/-- Anisotropic filtering 4x -/
def anisotropic4x : TextureFilter := Subtype.mk 3 TextureFilter.Is.anisotropic4x
/-- Anisotropic filtering 8x -/
def anisotropic8x : TextureFilter := Subtype.mk 4 TextureFilter.Is.anisotropic8x
/-- Anisotropic filtering 16x -/
def anisotropic16x : TextureFilter := Subtype.mk 5 TextureFilter.Is.anisotropic16x

end TextureFilter

instance : Inhabited TextureFilter := ⟨TextureFilter.point⟩


/-! # Texture wrap -/

inductive TextureWrap.Is : UInt32 -> Prop where
  | «repeat» : TextureWrap.Is 0
  | clamp : TextureWrap.Is 1
  | mirrorRepeat : TextureWrap.Is 2
  | mirrorClamp : TextureWrap.Is 3

/-- Texture parameters: wrap mode -/
def TextureWrap : Type := Subtype TextureWrap.Is

namespace TextureWrap

/-- Repeats texture in tiled mode -/
def «repeat» : TextureWrap := Subtype.mk 0 TextureWrap.Is.repeat
/-- Clamps texture to edge pixel in tiled mode -/
def clamp : TextureWrap := Subtype.mk 1 TextureWrap.Is.clamp
/-- Mirrors and repeats the texture in tiled mode -/
def mirrorRepeat : TextureWrap := Subtype.mk 2 TextureWrap.Is.mirrorRepeat
/-- Mirrors and clamps to border the texture in tiled mode -/
def mirrorClamp : TextureWrap := Subtype.mk 3 TextureWrap.Is.mirrorClamp

end TextureWrap

instance : Inhabited TextureWrap := ⟨TextureWrap.repeat⟩


/-! # Cubemap layout -/

inductive CubemapLayout.Is : UInt32 -> Prop where
  | autoDetect : CubemapLayout.Is 0
  | lineVertical : CubemapLayout.Is 1
  | lineHorizontal : CubemapLayout.Is 2
  | crossThreeByFour : CubemapLayout.Is 3
  | crossFourByThree : CubemapLayout.Is 4
  | panorama : CubemapLayout.Is 5

def CubemapLayout : Type := Subtype CubemapLayout.Is

namespace CubemapLayout

/-- Automatically detect layout type -/
def autoDetect : CubemapLayout := Subtype.mk 0 CubemapLayout.Is.autoDetect
/-- Layout is defined by a vertical line with faces -/
def lineVertical : CubemapLayout := Subtype.mk 1 CubemapLayout.Is.lineVertical
/-- Layout is defined by a horizontal line with faces -/
def lineHorizontal : CubemapLayout := Subtype.mk 2 CubemapLayout.Is.lineHorizontal
/-- Layout is defined by a 3x4 cross with cubemap faces -/
def crossThreeByFour : CubemapLayout := Subtype.mk 3 CubemapLayout.Is.crossThreeByFour
/-- Layout is defined by a 4x3 cross with cubemap faces -/
def crossFourByThree : CubemapLayout := Subtype.mk 4 CubemapLayout.Is.crossFourByThree
/-- Layout is defined by a panorama image (equirectangular map) -/
def panorama : CubemapLayout := Subtype.mk 5 CubemapLayout.Is.panorama

end CubemapLayout

instance : Inhabited CubemapLayout := ⟨CubemapLayout.autoDetect⟩


/-! # Font type -/

inductive FontType.Is : UInt32 -> Prop where
  | default : FontType.Is 0
  | bitmap : FontType.Is 1
  | sdf : FontType.Is 2

/-- Font type, defines generation method -/
def FontType : Type := Subtype FontType.Is

namespace FontType

/-- Default font generation, anti-aliased -/
def default : FontType := Subtype.mk 0 FontType.Is.default
/-- Bitmap font generation, no anti-aliasing -/
def bitmap : FontType := Subtype.mk 1 FontType.Is.bitmap
/-- SDF font generation, requires external shader -/
def sdf : FontType := Subtype.mk 2 FontType.Is.sdf

end FontType

instance : Inhabited FontType := ⟨FontType.default⟩


/-! # Color blending mode -/

inductive BlendMode.Is : UInt32 -> Prop where
  | alpha : BlendMode.Is 0
  | additive : BlendMode.Is 1
  | multiplied : BlendMode.Is 2
  | addColors : BlendMode.Is 3
  | subtractColors : BlendMode.Is 4
  | alphaPremultiply : BlendMode.Is 5
  | custom : BlendMode.Is 6
  | customSeparate : BlendMode.Is 7

/-- Color blending modes (pre-defined) -/
def BlendMode : Type := Subtype BlendMode.Is

namespace BlendMode

/-- Blend textures considering alpha (default) -/
def alpha : BlendMode := Subtype.mk 0 BlendMode.Is.alpha
/-- Blend textures adding colors -/
def additive : BlendMode := Subtype.mk 1 BlendMode.Is.additive
/-- Blend textures multiplying colors -/
def multiplied : BlendMode := Subtype.mk 2 BlendMode.Is.multiplied
/-- Blend textures adding colors (alternative) -/
def addColors : BlendMode := Subtype.mk 3 BlendMode.Is.addColors
/-- Blend textures subtracting colors (alternative) -/
def subtractColors : BlendMode := Subtype.mk 4 BlendMode.Is.subtractColors
/-- Blend premultiplied textures considering alpha -/
def alphaPremultiply : BlendMode := Subtype.mk 5 BlendMode.Is.alphaPremultiply
/-- Blend textures using custom src/dst factors (use rlSetBlendFactors()) -/
def custom : BlendMode := Subtype.mk 6 BlendMode.Is.custom
/-- Blend textures using custom rgb/alpha separate src/dst factors (use rlSetBlendFactorsSeparate()) -/
def customSeparate : BlendMode := Subtype.mk 7 BlendMode.Is.customSeparate

end BlendMode

instance : Inhabited BlendMode := ⟨BlendMode.alpha⟩


/-! # Gesture -/

structure Gesture where
  val : UInt32
deriving Repr

abbrev GestureFlags := Gesture

instance : OrOp Gesture where
  or a b := Gesture.mk (a.val ||| b.val)

instance : AndOp Gesture where
  and a b := Gesture.mk (a.val &&& b.val)

namespace Gesture

/-- No gesture -/
def none : Gesture := Gesture.mk 0

/-- Tap gesture -/
def tap : Gesture := Gesture.mk 1

/-- Double tap gesture -/
def doubletap : Gesture := Gesture.mk 2

/-- Hold gesture -/
def hold : Gesture := Gesture.mk 4

/-- Drag gesture -/
def drag : Gesture := Gesture.mk 8

/-- Swipe right gesture -/
def swipeRight : Gesture := Gesture.mk 16

/-- Swipe left gesture -/
def swipeLeft : Gesture := Gesture.mk 32

/-- Swipe up gesture -/
def swipeUp : Gesture := Gesture.mk 64

/-- Swipe down gesture -/
def swipeDown : Gesture := Gesture.mk 128

/-- Pinch in gesture -/
def pinchIn : Gesture := Gesture.mk 256

/-- Pinch out gesture -/
def pinchOut : Gesture := Gesture.mk 512

end Gesture

instance : Inhabited Gesture := ⟨Gesture.none⟩


/-! # Camera mode -/

inductive CameraMode.Is : UInt32 -> Prop where
  | custom : CameraMode.Is 0
  | free : CameraMode.Is 1
  | orbital : CameraMode.Is 2
  | firstPerson : CameraMode.Is 3
  | thirdPerson : CameraMode.Is 4

/-- Camera system modes -/
def CameraMode : Type := Subtype CameraMode.Is

namespace CameraMode

/-- Custom camera -/
def custom : CameraMode := Subtype.mk 0 CameraMode.Is.custom
/-- Free camera -/
def free : CameraMode := Subtype.mk 1 CameraMode.Is.free
/-- Orbital camera -/
def orbital : CameraMode := Subtype.mk 2 CameraMode.Is.orbital
/-- First person camera -/
def firstPerson : CameraMode := Subtype.mk 3 CameraMode.Is.firstPerson
/-- Third person camera -/
def thirdPerson : CameraMode := Subtype.mk 4 CameraMode.Is.thirdPerson

end CameraMode

instance : Inhabited CameraMode := ⟨CameraMode.custom⟩


/-! # Camera projection -/

inductive CameraProjection.Is : UInt32 -> Prop where
  | perspective : CameraProjection.Is 0
  | orthographic : CameraProjection.Is 1

def CameraProjection : Type := Subtype CameraProjection.Is

def CameraProjection.perspective : CameraProjection := Subtype.mk 0 CameraProjection.Is.perspective

def CameraProjection.orthographic : CameraProjection := Subtype.mk 1 CameraProjection.Is.orthographic

instance : Inhabited CameraProjection := ⟨CameraProjection.perspective⟩
instance : ReprAtom CameraProjection := ⟨⟩

instance : Repr CameraProjection := Repr.mk λ x _ ↦
  if x.val == 0
    then ".perspective"
    else ".orthographic"


/-! # NPatch layout -/

inductive NPatchLayout.Is : UInt32 -> Prop where
  | ninePatch : NPatchLayout.Is 0
  | threePatchVertical : NPatchLayout.Is 1
  | threePatchHorizontal : NPatchLayout.Is 2

def NPatchLayout : Type := Subtype NPatchLayout.Is

namespace NPatchLayout

/-- Npatch layout: 3x3 tiles -/
def ninePatch : NPatchLayout := Subtype.mk 0 NPatchLayout.Is.ninePatch
/-- Npatch layout: 1x3 tiles -/
def threePatchVertical : NPatchLayout := Subtype.mk 1 NPatchLayout.Is.threePatchVertical
/-- Npatch layout: 3x1 tiles -/
def threePatchHorizontal : NPatchLayout := Subtype.mk 2 NPatchLayout.Is.threePatchHorizontal

end NPatchLayout

instance : Inhabited NPatchLayout := ⟨NPatchLayout.ninePatch⟩


/-! # Audio sample type -/

inductive AudioSampleType.Is : UInt32 -> Prop where
  | u8 : AudioSampleType.Is 8
  | u16 : AudioSampleType.Is 16
  | u32 : AudioSampleType.Is 32

def AudioSampleType : Type := Subtype AudioSampleType.Is

def AudioSampleType.u8 := Subtype.mk 8 AudioSampleType.Is.u8
def AudioSampleType.u16 := Subtype.mk 16 AudioSampleType.Is.u16
def AudioSampleType.u32 := Subtype.mk 32 AudioSampleType.Is.u32

def AudioSampleType.size : AudioSampleType → UInt32 := Subtype.val

def AudioSampleType.alignment : AudioSampleType → Nat
  | ⟨⟨8, _⟩, _⟩ => Pod.alignment UInt8
  | ⟨⟨16, _⟩, _⟩ => Pod.alignment UInt16
  | ⟨⟨32, _⟩, _⟩ => Pod.alignment UInt32

end Raylib
