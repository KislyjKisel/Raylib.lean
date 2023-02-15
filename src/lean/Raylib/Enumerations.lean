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

/-- Set to try enabling V-Sync on GPU -/
def FLAG_VSYNC_HINT : ConfigFlags := ConfigFlags.mk 64
/-- Set to run program in fullscreen -/
def FLAG_FULLSCREEN_MODE : ConfigFlags := ConfigFlags.mk 2
/-- Set to allow resizable window -/
def FLAG_WINDOW_RESIZABLE : ConfigFlags := ConfigFlags.mk 4
/-- Set to disable window decoration (frame and buttons) -/
def FLAG_WINDOW_UNDECORATED : ConfigFlags := ConfigFlags.mk 8
/-- Set to hide window -/
def FLAG_WINDOW_HIDDEN : ConfigFlags := ConfigFlags.mk 128
/-- Set to minimize window (iconify) -/
def FLAG_WINDOW_MINIMIZED : ConfigFlags := ConfigFlags.mk 512
/-- Set to maximize window (expanded to monitor) -/
def FLAG_WINDOW_MAXIMIZED : ConfigFlags := ConfigFlags.mk 1024
/-- Set to window non focused -/
def FLAG_WINDOW_UNFOCUSED : ConfigFlags := ConfigFlags.mk 2048
/-- Set to window always on top -/
def FLAG_WINDOW_TOPMOST : ConfigFlags := ConfigFlags.mk 4096
/-- Set to allow windows running while minimized -/
def FLAG_WINDOW_ALWAYS_RUN : ConfigFlags := ConfigFlags.mk 256
/-- Set to allow transparent framebuffer -/
def FLAG_WINDOW_TRANSPARENT : ConfigFlags := ConfigFlags.mk 16
/-- Set to support HighDPI -/
def FLAG_WINDOW_HIGHDPI : ConfigFlags := ConfigFlags.mk 8192
/-- Set to support mouse passthrough, only supported when FLAG_WINDOW_UNDECORATED -/
def FLAG_WINDOW_MOUSE_PASSTHROUGH : ConfigFlags := ConfigFlags.mk 16384
/-- Set to try enabling MSAA 4X -/
def FLAG_MSAA_4X_HINT : ConfigFlags := ConfigFlags.mk 32
/-- Set to try enabling interlaced video format (for V3D) -/
def FLAG_INTERLACED_HINT : ConfigFlags := ConfigFlags.mk 65536


/-! # TraceLogLevel -/

inductive TraceLogLevel.Is : UInt32 -> Prop where
  | LOG_ALL : TraceLogLevel.Is 0
  | LOG_TRACE : TraceLogLevel.Is 1
  | LOG_DEBUG : TraceLogLevel.Is 2
  | LOG_INFO : TraceLogLevel.Is 3
  | LOG_WARNING : TraceLogLevel.Is 4
  | LOG_ERROR : TraceLogLevel.Is 5
  | LOG_FATAL : TraceLogLevel.Is 6
  | LOG_NONE : TraceLogLevel.Is 7

/-- Trace log level -/
def TraceLogLevel : Type := Subtype TraceLogLevel.Is

/-- Display all logs -/
def LOG_ALL : TraceLogLevel := Subtype.mk 0 TraceLogLevel.Is.LOG_ALL
/-- Trace logging, intended for internal use only -/
def LOG_TRACE : TraceLogLevel := Subtype.mk 1 TraceLogLevel.Is.LOG_TRACE
/-- Debug logging, used for internal debugging, it should be disabled on release builds -/
def LOG_DEBUG : TraceLogLevel := Subtype.mk 2 TraceLogLevel.Is.LOG_DEBUG
/-- Info logging, used for program execution info -/
def LOG_INFO : TraceLogLevel := Subtype.mk 3 TraceLogLevel.Is.LOG_INFO
/-- Warning logging, used on recoverable failures -/
def LOG_WARNING : TraceLogLevel := Subtype.mk 4 TraceLogLevel.Is.LOG_WARNING
/-- Error logging, used on unrecoverable failures -/
def LOG_ERROR : TraceLogLevel := Subtype.mk 5 TraceLogLevel.Is.LOG_ERROR
/-- Fatal logging, used to abort program: exit(EXIT_FAILURE) -/
def LOG_FATAL : TraceLogLevel := Subtype.mk 6 TraceLogLevel.Is.LOG_FATAL
/-- Disable logging -/
def LOG_NONE : TraceLogLevel := Subtype.mk 7 TraceLogLevel.Is.LOG_NONE


/-! # Keyboard keys -/

inductive KeyboardKey.Is : UInt32 -> Prop where
  | KEY_NULL : KeyboardKey.Is 0
  | KEY_APOSTROPHE : KeyboardKey.Is 39
  | KEY_COMMA : KeyboardKey.Is 44
  | KEY_MINUS : KeyboardKey.Is 45
  | KEY_PERIOD : KeyboardKey.Is 46
  | KEY_SLASH : KeyboardKey.Is 47
  | KEY_ZERO : KeyboardKey.Is 48
  | KEY_ONE : KeyboardKey.Is 49
  | KEY_TWO : KeyboardKey.Is 50
  | KEY_THREE : KeyboardKey.Is 51
  | KEY_FOUR : KeyboardKey.Is 52
  | KEY_FIVE : KeyboardKey.Is 53
  | KEY_SIX : KeyboardKey.Is 54
  | KEY_SEVEN : KeyboardKey.Is 55
  | KEY_EIGHT : KeyboardKey.Is 56
  | KEY_NINE : KeyboardKey.Is 57
  | KEY_SEMICOLON : KeyboardKey.Is 59
  | KEY_EQUAL : KeyboardKey.Is 61
  | KEY_A : KeyboardKey.Is 65
  | KEY_B : KeyboardKey.Is 66
  | KEY_C : KeyboardKey.Is 67
  | KEY_D : KeyboardKey.Is 68
  | KEY_E : KeyboardKey.Is 69
  | KEY_F : KeyboardKey.Is 70
  | KEY_G : KeyboardKey.Is 71
  | KEY_H : KeyboardKey.Is 72
  | KEY_I : KeyboardKey.Is 73
  | KEY_J : KeyboardKey.Is 74
  | KEY_K : KeyboardKey.Is 75
  | KEY_L : KeyboardKey.Is 76
  | KEY_M : KeyboardKey.Is 77
  | KEY_N : KeyboardKey.Is 78
  | KEY_O : KeyboardKey.Is 79
  | KEY_P : KeyboardKey.Is 80
  | KEY_Q : KeyboardKey.Is 81
  | KEY_R : KeyboardKey.Is 82
  | KEY_S : KeyboardKey.Is 83
  | KEY_T : KeyboardKey.Is 84
  | KEY_U : KeyboardKey.Is 85
  | KEY_V : KeyboardKey.Is 86
  | KEY_W : KeyboardKey.Is 87
  | KEY_X : KeyboardKey.Is 88
  | KEY_Y : KeyboardKey.Is 89
  | KEY_Z : KeyboardKey.Is 90
  | KEY_LEFT_BRACKET : KeyboardKey.Is 91
  | KEY_BACKSLASH : KeyboardKey.Is 92
  | KEY_RIGHT_BRACKET : KeyboardKey.Is 93
  | KEY_GRAVE : KeyboardKey.Is 96
  | KEY_SPACE : KeyboardKey.Is 32
  | KEY_ESCAPE : KeyboardKey.Is 256
  | KEY_ENTER : KeyboardKey.Is 257
  | KEY_TAB : KeyboardKey.Is 258
  | KEY_BACKSPACE : KeyboardKey.Is 259
  | KEY_INSERT : KeyboardKey.Is 260
  | KEY_DELETE : KeyboardKey.Is 261
  | KEY_RIGHT : KeyboardKey.Is 262
  | KEY_LEFT : KeyboardKey.Is 263
  | KEY_DOWN : KeyboardKey.Is 264
  | KEY_UP : KeyboardKey.Is 265
  | KEY_PAGE_UP : KeyboardKey.Is 266
  | KEY_PAGE_DOWN : KeyboardKey.Is 267
  | KEY_HOME : KeyboardKey.Is 268
  | KEY_END : KeyboardKey.Is 269
  | KEY_CAPS_LOCK : KeyboardKey.Is 280
  | KEY_SCROLL_LOCK : KeyboardKey.Is 281
  | KEY_NUM_LOCK : KeyboardKey.Is 282
  | KEY_PRINT_SCREEN : KeyboardKey.Is 283
  | KEY_PAUSE : KeyboardKey.Is 284
  | KEY_F1 : KeyboardKey.Is 290
  | KEY_F2 : KeyboardKey.Is 291
  | KEY_F3 : KeyboardKey.Is 292
  | KEY_F4 : KeyboardKey.Is 293
  | KEY_F5 : KeyboardKey.Is 294
  | KEY_F6 : KeyboardKey.Is 295
  | KEY_F7 : KeyboardKey.Is 296
  | KEY_F8 : KeyboardKey.Is 297
  | KEY_F9 : KeyboardKey.Is 298
  | KEY_F10 : KeyboardKey.Is 299
  | KEY_F11 : KeyboardKey.Is 300
  | KEY_F12 : KeyboardKey.Is 301
  | KEY_LEFT_SHIFT : KeyboardKey.Is 340
  | KEY_LEFT_CONTROL : KeyboardKey.Is 341
  | KEY_LEFT_ALT : KeyboardKey.Is 342
  | KEY_LEFT_SUPER : KeyboardKey.Is 343
  | KEY_RIGHT_SHIFT : KeyboardKey.Is 344
  | KEY_RIGHT_CONTROL : KeyboardKey.Is 345
  | KEY_RIGHT_ALT : KeyboardKey.Is 346
  | KEY_RIGHT_SUPER : KeyboardKey.Is 347
  | KEY_KB_MENU : KeyboardKey.Is 348
  | KEY_KP_0 : KeyboardKey.Is 320
  | KEY_KP_1 : KeyboardKey.Is 321
  | KEY_KP_2 : KeyboardKey.Is 322
  | KEY_KP_3 : KeyboardKey.Is 323
  | KEY_KP_4 : KeyboardKey.Is 324
  | KEY_KP_5 : KeyboardKey.Is 325
  | KEY_KP_6 : KeyboardKey.Is 326
  | KEY_KP_7 : KeyboardKey.Is 327
  | KEY_KP_8 : KeyboardKey.Is 328
  | KEY_KP_9 : KeyboardKey.Is 329
  | KEY_KP_DECIMAL : KeyboardKey.Is 330
  | KEY_KP_DIVIDE : KeyboardKey.Is 331
  | KEY_KP_MULTIPLY : KeyboardKey.Is 332
  | KEY_KP_SUBTRACT : KeyboardKey.Is 333
  | KEY_KP_ADD : KeyboardKey.Is 334
  | KEY_KP_ENTER : KeyboardKey.Is 335
  | KEY_KP_EQUAL : KeyboardKey.Is 336
  | KEY_BACK : KeyboardKey.Is 4
  | KEY_MENU : KeyboardKey.Is 82
  | KEY_VOLUME_UP : KeyboardKey.Is 24
  | KEY_VOLUME_DOWN : KeyboardKey.Is 25

/-- Keyboard keys (US keyboard layout) -/
def KeyboardKey : Type := Subtype KeyboardKey.Is

/-- Key: NULL, used for no key pressed -/
def KEY_NULL : KeyboardKey := Subtype.mk 0 KeyboardKey.Is.KEY_NULL
/-- Key: ' -/
def KEY_APOSTROPHE : KeyboardKey := Subtype.mk 39 KeyboardKey.Is.KEY_APOSTROPHE
/-- Key: , -/
def KEY_COMMA : KeyboardKey := Subtype.mk 44 KeyboardKey.Is.KEY_COMMA
/-- Key: - -/
def KEY_MINUS : KeyboardKey := Subtype.mk 45 KeyboardKey.Is.KEY_MINUS
/-- Key: . -/
def KEY_PERIOD : KeyboardKey := Subtype.mk 46 KeyboardKey.Is.KEY_PERIOD
/-- Key: / -/
def KEY_SLASH : KeyboardKey := Subtype.mk 47 KeyboardKey.Is.KEY_SLASH
/-- Key: 0 -/
def KEY_ZERO : KeyboardKey := Subtype.mk 48 KeyboardKey.Is.KEY_ZERO
/-- Key: 1 -/
def KEY_ONE : KeyboardKey := Subtype.mk 49 KeyboardKey.Is.KEY_ONE
/-- Key: 2 -/
def KEY_TWO : KeyboardKey := Subtype.mk 50 KeyboardKey.Is.KEY_TWO
/-- Key: 3 -/
def KEY_THREE : KeyboardKey := Subtype.mk 51 KeyboardKey.Is.KEY_THREE
/-- Key: 4 -/
def KEY_FOUR : KeyboardKey := Subtype.mk 52 KeyboardKey.Is.KEY_FOUR
/-- Key: 5 -/
def KEY_FIVE : KeyboardKey := Subtype.mk 53 KeyboardKey.Is.KEY_FIVE
/-- Key: 6 -/
def KEY_SIX : KeyboardKey := Subtype.mk 54 KeyboardKey.Is.KEY_SIX
/-- Key: 7 -/
def KEY_SEVEN : KeyboardKey := Subtype.mk 55 KeyboardKey.Is.KEY_SEVEN
/-- Key: 8 -/
def KEY_EIGHT : KeyboardKey := Subtype.mk 56 KeyboardKey.Is.KEY_EIGHT
/-- Key: 9 -/
def KEY_NINE : KeyboardKey := Subtype.mk 57 KeyboardKey.Is.KEY_NINE
/-- Key: ; -/
def KEY_SEMICOLON : KeyboardKey := Subtype.mk 59 KeyboardKey.Is.KEY_SEMICOLON
/-- Key: = -/
def KEY_EQUAL : KeyboardKey := Subtype.mk 61 KeyboardKey.Is.KEY_EQUAL
/-- Key: A | a -/
def KEY_A : KeyboardKey := Subtype.mk 65 KeyboardKey.Is.KEY_A
/-- Key: B | b -/
def KEY_B : KeyboardKey := Subtype.mk 66 KeyboardKey.Is.KEY_B
/-- Key: C | c -/
def KEY_C : KeyboardKey := Subtype.mk 67 KeyboardKey.Is.KEY_C
/-- Key: D | d -/
def KEY_D : KeyboardKey := Subtype.mk 68 KeyboardKey.Is.KEY_D
/-- Key: E | e -/
def KEY_E : KeyboardKey := Subtype.mk 69 KeyboardKey.Is.KEY_E
/-- Key: F | f -/
def KEY_F : KeyboardKey := Subtype.mk 70 KeyboardKey.Is.KEY_F
/-- Key: G | g -/
def KEY_G : KeyboardKey := Subtype.mk 71 KeyboardKey.Is.KEY_G
/-- Key: H | h -/
def KEY_H : KeyboardKey := Subtype.mk 72 KeyboardKey.Is.KEY_H
/-- Key: I | i -/
def KEY_I : KeyboardKey := Subtype.mk 73 KeyboardKey.Is.KEY_I
/-- Key: J | j -/
def KEY_J : KeyboardKey := Subtype.mk 74 KeyboardKey.Is.KEY_J
/-- Key: K | k -/
def KEY_K : KeyboardKey := Subtype.mk 75 KeyboardKey.Is.KEY_K
/-- Key: L | l -/
def KEY_L : KeyboardKey := Subtype.mk 76 KeyboardKey.Is.KEY_L
/-- Key: M | m -/
def KEY_M : KeyboardKey := Subtype.mk 77 KeyboardKey.Is.KEY_M
/-- Key: N | n -/
def KEY_N : KeyboardKey := Subtype.mk 78 KeyboardKey.Is.KEY_N
/-- Key: O | o -/
def KEY_O : KeyboardKey := Subtype.mk 79 KeyboardKey.Is.KEY_O
/-- Key: P | p -/
def KEY_P : KeyboardKey := Subtype.mk 80 KeyboardKey.Is.KEY_P
/-- Key: Q | q -/
def KEY_Q : KeyboardKey := Subtype.mk 81 KeyboardKey.Is.KEY_Q
/-- Key: R | r -/
def KEY_R : KeyboardKey := Subtype.mk 82 KeyboardKey.Is.KEY_R
/-- Key: S | s -/
def KEY_S : KeyboardKey := Subtype.mk 83 KeyboardKey.Is.KEY_S
/-- Key: T | t -/
def KEY_T : KeyboardKey := Subtype.mk 84 KeyboardKey.Is.KEY_T
/-- Key: U | u -/
def KEY_U : KeyboardKey := Subtype.mk 85 KeyboardKey.Is.KEY_U
/-- Key: V | v -/
def KEY_V : KeyboardKey := Subtype.mk 86 KeyboardKey.Is.KEY_V
/-- Key: W | w -/
def KEY_W : KeyboardKey := Subtype.mk 87 KeyboardKey.Is.KEY_W
/-- Key: X | x -/
def KEY_X : KeyboardKey := Subtype.mk 88 KeyboardKey.Is.KEY_X
/-- Key: Y | y -/
def KEY_Y : KeyboardKey := Subtype.mk 89 KeyboardKey.Is.KEY_Y
/-- Key: Z | z -/
def KEY_Z : KeyboardKey := Subtype.mk 90 KeyboardKey.Is.KEY_Z
/-- Key: [ -/
def KEY_LEFT_BRACKET : KeyboardKey := Subtype.mk 91 KeyboardKey.Is.KEY_LEFT_BRACKET
/-- Key: '\' -/
def KEY_BACKSLASH : KeyboardKey := Subtype.mk 92 KeyboardKey.Is.KEY_BACKSLASH
/-- Key: ] -/
def KEY_RIGHT_BRACKET : KeyboardKey := Subtype.mk 93 KeyboardKey.Is.KEY_RIGHT_BRACKET
/-- Key: ` -/
def KEY_GRAVE : KeyboardKey := Subtype.mk 96 KeyboardKey.Is.KEY_GRAVE
/-- Key: Space -/
def KEY_SPACE : KeyboardKey := Subtype.mk 32 KeyboardKey.Is.KEY_SPACE
/-- Key: Esc -/
def KEY_ESCAPE : KeyboardKey := Subtype.mk 256 KeyboardKey.Is.KEY_ESCAPE
/-- Key: Enter -/
def KEY_ENTER : KeyboardKey := Subtype.mk 257 KeyboardKey.Is.KEY_ENTER
/-- Key: Tab -/
def KEY_TAB : KeyboardKey := Subtype.mk 258 KeyboardKey.Is.KEY_TAB
/-- Key: Backspace -/
def KEY_BACKSPACE : KeyboardKey := Subtype.mk 259 KeyboardKey.Is.KEY_BACKSPACE
/-- Key: Ins -/
def KEY_INSERT : KeyboardKey := Subtype.mk 260 KeyboardKey.Is.KEY_INSERT
/-- Key: Del -/
def KEY_DELETE : KeyboardKey := Subtype.mk 261 KeyboardKey.Is.KEY_DELETE
/-- Key: Cursor right -/
def KEY_RIGHT : KeyboardKey := Subtype.mk 262 KeyboardKey.Is.KEY_RIGHT
/-- Key: Cursor left -/
def KEY_LEFT : KeyboardKey := Subtype.mk 263 KeyboardKey.Is.KEY_LEFT
/-- Key: Cursor down -/
def KEY_DOWN : KeyboardKey := Subtype.mk 264 KeyboardKey.Is.KEY_DOWN
/-- Key: Cursor up -/
def KEY_UP : KeyboardKey := Subtype.mk 265 KeyboardKey.Is.KEY_UP
/-- Key: Page up -/
def KEY_PAGE_UP : KeyboardKey := Subtype.mk 266 KeyboardKey.Is.KEY_PAGE_UP
/-- Key: Page down -/
def KEY_PAGE_DOWN : KeyboardKey := Subtype.mk 267 KeyboardKey.Is.KEY_PAGE_DOWN
/-- Key: Home -/
def KEY_HOME : KeyboardKey := Subtype.mk 268 KeyboardKey.Is.KEY_HOME
/-- Key: End -/
def KEY_END : KeyboardKey := Subtype.mk 269 KeyboardKey.Is.KEY_END
/-- Key: Caps lock -/
def KEY_CAPS_LOCK : KeyboardKey := Subtype.mk 280 KeyboardKey.Is.KEY_CAPS_LOCK
/-- Key: Scroll down -/
def KEY_SCROLL_LOCK : KeyboardKey := Subtype.mk 281 KeyboardKey.Is.KEY_SCROLL_LOCK
/-- Key: Num lock -/
def KEY_NUM_LOCK : KeyboardKey := Subtype.mk 282 KeyboardKey.Is.KEY_NUM_LOCK
/-- Key: Print screen -/
def KEY_PRINT_SCREEN : KeyboardKey := Subtype.mk 283 KeyboardKey.Is.KEY_PRINT_SCREEN
/-- Key: Pause -/
def KEY_PAUSE : KeyboardKey := Subtype.mk 284 KeyboardKey.Is.KEY_PAUSE
/-- Key: F1 -/
def KEY_F1 : KeyboardKey := Subtype.mk 290 KeyboardKey.Is.KEY_F1
/-- Key: F2 -/
def KEY_F2 : KeyboardKey := Subtype.mk 291 KeyboardKey.Is.KEY_F2
/-- Key: F3 -/
def KEY_F3 : KeyboardKey := Subtype.mk 292 KeyboardKey.Is.KEY_F3
/-- Key: F4 -/
def KEY_F4 : KeyboardKey := Subtype.mk 293 KeyboardKey.Is.KEY_F4
/-- Key: F5 -/
def KEY_F5 : KeyboardKey := Subtype.mk 294 KeyboardKey.Is.KEY_F5
/-- Key: F6 -/
def KEY_F6 : KeyboardKey := Subtype.mk 295 KeyboardKey.Is.KEY_F6
/-- Key: F7 -/
def KEY_F7 : KeyboardKey := Subtype.mk 296 KeyboardKey.Is.KEY_F7
/-- Key: F8 -/
def KEY_F8 : KeyboardKey := Subtype.mk 297 KeyboardKey.Is.KEY_F8
/-- Key: F9 -/
def KEY_F9 : KeyboardKey := Subtype.mk 298 KeyboardKey.Is.KEY_F9
/-- Key: F10 -/
def KEY_F10 : KeyboardKey := Subtype.mk 299 KeyboardKey.Is.KEY_F10
/-- Key: F11 -/
def KEY_F11 : KeyboardKey := Subtype.mk 300 KeyboardKey.Is.KEY_F11
/-- Key: F12 -/
def KEY_F12 : KeyboardKey := Subtype.mk 301 KeyboardKey.Is.KEY_F12
/-- Key: Shift left -/
def KEY_LEFT_SHIFT : KeyboardKey := Subtype.mk 340 KeyboardKey.Is.KEY_LEFT_SHIFT
/-- Key: Control left -/
def KEY_LEFT_CONTROL : KeyboardKey := Subtype.mk 341 KeyboardKey.Is.KEY_LEFT_CONTROL
/-- Key: Alt left -/
def KEY_LEFT_ALT : KeyboardKey := Subtype.mk 342 KeyboardKey.Is.KEY_LEFT_ALT
/-- Key: Super left -/
def KEY_LEFT_SUPER : KeyboardKey := Subtype.mk 343 KeyboardKey.Is.KEY_LEFT_SUPER
/-- Key: Shift right -/
def KEY_RIGHT_SHIFT : KeyboardKey := Subtype.mk 344 KeyboardKey.Is.KEY_RIGHT_SHIFT
/-- Key: Control right -/
def KEY_RIGHT_CONTROL : KeyboardKey := Subtype.mk 345 KeyboardKey.Is.KEY_RIGHT_CONTROL
/-- Key: Alt right -/
def KEY_RIGHT_ALT : KeyboardKey := Subtype.mk 346 KeyboardKey.Is.KEY_RIGHT_ALT
/-- Key: Super right -/
def KEY_RIGHT_SUPER : KeyboardKey := Subtype.mk 347 KeyboardKey.Is.KEY_RIGHT_SUPER
/-- Key: KB menu -/
def KEY_KB_MENU : KeyboardKey := Subtype.mk 348 KeyboardKey.Is.KEY_KB_MENU
/-- Key: Keypad 0 -/
def KEY_KP_0 : KeyboardKey := Subtype.mk 320 KeyboardKey.Is.KEY_KP_0
/-- Key: Keypad 1 -/
def KEY_KP_1 : KeyboardKey := Subtype.mk 321 KeyboardKey.Is.KEY_KP_1
/-- Key: Keypad 2 -/
def KEY_KP_2 : KeyboardKey := Subtype.mk 322 KeyboardKey.Is.KEY_KP_2
/-- Key: Keypad 3 -/
def KEY_KP_3 : KeyboardKey := Subtype.mk 323 KeyboardKey.Is.KEY_KP_3
/-- Key: Keypad 4 -/
def KEY_KP_4 : KeyboardKey := Subtype.mk 324 KeyboardKey.Is.KEY_KP_4
/-- Key: Keypad 5 -/
def KEY_KP_5 : KeyboardKey := Subtype.mk 325 KeyboardKey.Is.KEY_KP_5
/-- Key: Keypad 6 -/
def KEY_KP_6 : KeyboardKey := Subtype.mk 326 KeyboardKey.Is.KEY_KP_6
/-- Key: Keypad 7 -/
def KEY_KP_7 : KeyboardKey := Subtype.mk 327 KeyboardKey.Is.KEY_KP_7
/-- Key: Keypad 8 -/
def KEY_KP_8 : KeyboardKey := Subtype.mk 328 KeyboardKey.Is.KEY_KP_8
/-- Key: Keypad 9 -/
def KEY_KP_9 : KeyboardKey := Subtype.mk 329 KeyboardKey.Is.KEY_KP_9
/-- Key: Keypad . -/
def KEY_KP_DECIMAL : KeyboardKey := Subtype.mk 330 KeyboardKey.Is.KEY_KP_DECIMAL
/-- Key: Keypad / -/
def KEY_KP_DIVIDE : KeyboardKey := Subtype.mk 331 KeyboardKey.Is.KEY_KP_DIVIDE
/-- Key: Keypad * -/
def KEY_KP_MULTIPLY : KeyboardKey := Subtype.mk 332 KeyboardKey.Is.KEY_KP_MULTIPLY
/-- Key: Keypad - -/
def KEY_KP_SUBTRACT : KeyboardKey := Subtype.mk 333 KeyboardKey.Is.KEY_KP_SUBTRACT
/-- Key: Keypad + -/
def KEY_KP_ADD : KeyboardKey := Subtype.mk 334 KeyboardKey.Is.KEY_KP_ADD
/-- Key: Keypad Enter -/
def KEY_KP_ENTER : KeyboardKey := Subtype.mk 335 KeyboardKey.Is.KEY_KP_ENTER
/-- Key: Keypad = -/
def KEY_KP_EQUAL : KeyboardKey := Subtype.mk 336 KeyboardKey.Is.KEY_KP_EQUAL
/-- Key: Android back button -/
def KEY_BACK : KeyboardKey := Subtype.mk 4 KeyboardKey.Is.KEY_BACK
/-- Key: Android menu button -/
def KEY_MENU : KeyboardKey := Subtype.mk 82 KeyboardKey.Is.KEY_MENU
/-- Key: Android volume up button -/
def KEY_VOLUME_UP : KeyboardKey := Subtype.mk 24 KeyboardKey.Is.KEY_VOLUME_UP
/-- Key: Android volume down button -/
def KEY_VOLUME_DOWN : KeyboardKey := Subtype.mk 25 KeyboardKey.Is.KEY_VOLUME_DOWN

instance instInhabitedKeyboardKey : Inhabited KeyboardKey where
  default := KEY_NULL


/-! # Mouse buttons -/

inductive MouseButton.Is : UInt32 -> Prop where
  | MOUSE_BUTTON_LEFT : MouseButton.Is 0
  | MOUSE_BUTTON_RIGHT : MouseButton.Is 1
  | MOUSE_BUTTON_MIDDLE : MouseButton.Is 2
  | MOUSE_BUTTON_SIDE : MouseButton.Is 3
  | MOUSE_BUTTON_EXTRA : MouseButton.Is 4
  | MOUSE_BUTTON_FORWARD : MouseButton.Is 5
  | MOUSE_BUTTON_BACK : MouseButton.Is 6

/-- Mouse buttons -/
def MouseButton : Type := Subtype MouseButton.Is

/-- Mouse button left -/
def MOUSE_BUTTON_LEFT : MouseButton := Subtype.mk 0 MouseButton.Is.MOUSE_BUTTON_LEFT
/-- Mouse button right -/
def MOUSE_BUTTON_RIGHT : MouseButton := Subtype.mk 1 MouseButton.Is.MOUSE_BUTTON_RIGHT
/-- Mouse button middle (pressed wheel) -/
def MOUSE_BUTTON_MIDDLE : MouseButton := Subtype.mk 2 MouseButton.Is.MOUSE_BUTTON_MIDDLE
/-- Mouse button side (advanced mouse device) -/
def MOUSE_BUTTON_SIDE : MouseButton := Subtype.mk 3 MouseButton.Is.MOUSE_BUTTON_SIDE
/-- Mouse button extra (advanced mouse device) -/
def MOUSE_BUTTON_EXTRA : MouseButton := Subtype.mk 4 MouseButton.Is.MOUSE_BUTTON_EXTRA
/-- Mouse button forward (advanced mouse device) -/
def MOUSE_BUTTON_FORWARD : MouseButton := Subtype.mk 5 MouseButton.Is.MOUSE_BUTTON_FORWARD
/-- Mouse button back (advanced mouse device) -/
def MOUSE_BUTTON_BACK : MouseButton := Subtype.mk 6 MouseButton.Is.MOUSE_BUTTON_BACK


/-! # Mouse cursors -/

inductive MouseCursor.Is : UInt32 -> Prop where
  | MOUSE_CURSOR_DEFAULT : MouseCursor.Is 0
  | MOUSE_CURSOR_ARROW : MouseCursor.Is 1
  | MOUSE_CURSOR_IBEAM : MouseCursor.Is 2
  | MOUSE_CURSOR_CROSSHAIR : MouseCursor.Is 3
  | MOUSE_CURSOR_POINTING_HAND : MouseCursor.Is 4
  | MOUSE_CURSOR_RESIZE_EW : MouseCursor.Is 5
  | MOUSE_CURSOR_RESIZE_NS : MouseCursor.Is 6
  | MOUSE_CURSOR_RESIZE_NWSE : MouseCursor.Is 7
  | MOUSE_CURSOR_RESIZE_NESW : MouseCursor.Is 8
  | MOUSE_CURSOR_RESIZE_ALL : MouseCursor.Is 9
  | MOUSE_CURSOR_NOT_ALLOWED : MouseCursor.Is 10

/-- Mouse cursor -/
def MouseCursor : Type := Subtype MouseCursor.Is

/-- Default pointer shape -/
def MOUSE_CURSOR_DEFAULT : MouseCursor := Subtype.mk 0 MouseCursor.Is.MOUSE_CURSOR_DEFAULT
/-- Arrow shape -/
def MOUSE_CURSOR_ARROW : MouseCursor := Subtype.mk 1 MouseCursor.Is.MOUSE_CURSOR_ARROW
/-- Text writing cursor shape -/
def MOUSE_CURSOR_IBEAM : MouseCursor := Subtype.mk 2 MouseCursor.Is.MOUSE_CURSOR_IBEAM
/-- Cross shape -/
def MOUSE_CURSOR_CROSSHAIR : MouseCursor := Subtype.mk 3 MouseCursor.Is.MOUSE_CURSOR_CROSSHAIR
/-- Pointing hand cursor -/
def MOUSE_CURSOR_POINTING_HAND : MouseCursor := Subtype.mk 4 MouseCursor.Is.MOUSE_CURSOR_POINTING_HAND
/-- Horizontal resize/move arrow shape -/
def MOUSE_CURSOR_RESIZE_EW : MouseCursor := Subtype.mk 5 MouseCursor.Is.MOUSE_CURSOR_RESIZE_EW
/-- Vertical resize/move arrow shape -/
def MOUSE_CURSOR_RESIZE_NS : MouseCursor := Subtype.mk 6 MouseCursor.Is.MOUSE_CURSOR_RESIZE_NS
/-- Top-left to bottom-right diagonal resize/move arrow shape -/
def MOUSE_CURSOR_RESIZE_NWSE : MouseCursor := Subtype.mk 7 MouseCursor.Is.MOUSE_CURSOR_RESIZE_NWSE
/-- The top-right to bottom-left diagonal resize/move arrow shape -/
def MOUSE_CURSOR_RESIZE_NESW : MouseCursor := Subtype.mk 8 MouseCursor.Is.MOUSE_CURSOR_RESIZE_NESW
/-- The omni-directional resize/move cursor shape -/
def MOUSE_CURSOR_RESIZE_ALL : MouseCursor := Subtype.mk 9 MouseCursor.Is.MOUSE_CURSOR_RESIZE_ALL
/-- The operation-not-allowed shape -/
def MOUSE_CURSOR_NOT_ALLOWED : MouseCursor := Subtype.mk 10 MouseCursor.Is.MOUSE_CURSOR_NOT_ALLOWED


/-! # Gamepad buttons -/

inductive GamepadButton.Is : UInt32 -> Prop where
  | GAMEPAD_BUTTON_UNKNOWN : GamepadButton.Is 0
  | GAMEPAD_BUTTON_LEFT_FACE_UP : GamepadButton.Is 1
  | GAMEPAD_BUTTON_LEFT_FACE_RIGHT : GamepadButton.Is 2
  | GAMEPAD_BUTTON_LEFT_FACE_DOWN : GamepadButton.Is 3
  | GAMEPAD_BUTTON_LEFT_FACE_LEFT : GamepadButton.Is 4
  | GAMEPAD_BUTTON_RIGHT_FACE_UP : GamepadButton.Is 5
  | GAMEPAD_BUTTON_RIGHT_FACE_RIGHT : GamepadButton.Is 6
  | GAMEPAD_BUTTON_RIGHT_FACE_DOWN : GamepadButton.Is 7
  | GAMEPAD_BUTTON_RIGHT_FACE_LEFT : GamepadButton.Is 8
  | GAMEPAD_BUTTON_LEFT_TRIGGER_1 : GamepadButton.Is 9
  | GAMEPAD_BUTTON_LEFT_TRIGGER_2 : GamepadButton.Is 10
  | GAMEPAD_BUTTON_RIGHT_TRIGGER_1 : GamepadButton.Is 11
  | GAMEPAD_BUTTON_RIGHT_TRIGGER_2 : GamepadButton.Is 12
  | GAMEPAD_BUTTON_MIDDLE_LEFT : GamepadButton.Is 13
  | GAMEPAD_BUTTON_MIDDLE : GamepadButton.Is 14
  | GAMEPAD_BUTTON_MIDDLE_RIGHT : GamepadButton.Is 15
  | GAMEPAD_BUTTON_LEFT_THUMB : GamepadButton.Is 16
  | GAMEPAD_BUTTON_RIGHT_THUMB : GamepadButton.Is 17

/-- Gamepad buttons -/
def GamepadButton : Type := Subtype GamepadButton.Is

/-- Unknown button, just for error checking -/
def GAMEPAD_BUTTON_UNKNOWN : GamepadButton := Subtype.mk 0 GamepadButton.Is.GAMEPAD_BUTTON_UNKNOWN
/-- Gamepad left DPAD up button -/
def GAMEPAD_BUTTON_LEFT_FACE_UP : GamepadButton := Subtype.mk 1 GamepadButton.Is.GAMEPAD_BUTTON_LEFT_FACE_UP
/-- Gamepad left DPAD right button -/
def GAMEPAD_BUTTON_LEFT_FACE_RIGHT : GamepadButton := Subtype.mk 2 GamepadButton.Is.GAMEPAD_BUTTON_LEFT_FACE_RIGHT
/-- Gamepad left DPAD down button -/
def GAMEPAD_BUTTON_LEFT_FACE_DOWN : GamepadButton := Subtype.mk 3 GamepadButton.Is.GAMEPAD_BUTTON_LEFT_FACE_DOWN
/-- Gamepad left DPAD left button -/
def GAMEPAD_BUTTON_LEFT_FACE_LEFT : GamepadButton := Subtype.mk 4 GamepadButton.Is.GAMEPAD_BUTTON_LEFT_FACE_LEFT
/-- Gamepad right button up (i.e. PS3: Triangle, Xbox: Y) -/
def GAMEPAD_BUTTON_RIGHT_FACE_UP : GamepadButton := Subtype.mk 5 GamepadButton.Is.GAMEPAD_BUTTON_RIGHT_FACE_UP
/-- Gamepad right button right (i.e. PS3: Square, Xbox: X) -/
def GAMEPAD_BUTTON_RIGHT_FACE_RIGHT : GamepadButton := Subtype.mk 6 GamepadButton.Is.GAMEPAD_BUTTON_RIGHT_FACE_RIGHT
/-- Gamepad right button down (i.e. PS3: Cross, Xbox: A) -/
def GAMEPAD_BUTTON_RIGHT_FACE_DOWN : GamepadButton := Subtype.mk 7 GamepadButton.Is.GAMEPAD_BUTTON_RIGHT_FACE_DOWN
/-- Gamepad right button left (i.e. PS3: Circle, Xbox: B) -/
def GAMEPAD_BUTTON_RIGHT_FACE_LEFT : GamepadButton := Subtype.mk 8 GamepadButton.Is.GAMEPAD_BUTTON_RIGHT_FACE_LEFT
/-- Gamepad top/back trigger left (first), it could be a trailing button -/
def GAMEPAD_BUTTON_LEFT_TRIGGER_1 : GamepadButton := Subtype.mk 9 GamepadButton.Is.GAMEPAD_BUTTON_LEFT_TRIGGER_1
/-- Gamepad top/back trigger left (second), it could be a trailing button -/
def GAMEPAD_BUTTON_LEFT_TRIGGER_2 : GamepadButton := Subtype.mk 10 GamepadButton.Is.GAMEPAD_BUTTON_LEFT_TRIGGER_2
/-- Gamepad top/back trigger right (one), it could be a trailing button -/
def GAMEPAD_BUTTON_RIGHT_TRIGGER_1 : GamepadButton := Subtype.mk 11 GamepadButton.Is.GAMEPAD_BUTTON_RIGHT_TRIGGER_1
/-- Gamepad top/back trigger right (second), it could be a trailing button -/
def GAMEPAD_BUTTON_RIGHT_TRIGGER_2 : GamepadButton := Subtype.mk 12 GamepadButton.Is.GAMEPAD_BUTTON_RIGHT_TRIGGER_2
/-- Gamepad center buttons, left one (i.e. PS3: Select) -/
def GAMEPAD_BUTTON_MIDDLE_LEFT : GamepadButton := Subtype.mk 13 GamepadButton.Is.GAMEPAD_BUTTON_MIDDLE_LEFT
/-- Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX) -/
def GAMEPAD_BUTTON_MIDDLE : GamepadButton := Subtype.mk 14 GamepadButton.Is.GAMEPAD_BUTTON_MIDDLE
/-- Gamepad center buttons, right one (i.e. PS3: Start) -/
def GAMEPAD_BUTTON_MIDDLE_RIGHT : GamepadButton := Subtype.mk 15 GamepadButton.Is.GAMEPAD_BUTTON_MIDDLE_RIGHT
/-- Gamepad joystick pressed button left -/
def GAMEPAD_BUTTON_LEFT_THUMB : GamepadButton := Subtype.mk 16 GamepadButton.Is.GAMEPAD_BUTTON_LEFT_THUMB
/-- Gamepad joystick pressed button right -/
def GAMEPAD_BUTTON_RIGHT_THUMB : GamepadButton := Subtype.mk 17 GamepadButton.Is.GAMEPAD_BUTTON_RIGHT_THUMB

instance instInhabitedGamepadButton : Inhabited GamepadButton where
  default := GAMEPAD_BUTTON_UNKNOWN


/-! # Gamepad axis -/

inductive GamepadAxis.Is : UInt32 -> Prop where
  | GAMEPAD_AXIS_LEFT_X : GamepadAxis.Is 0
  | GAMEPAD_AXIS_LEFT_Y : GamepadAxis.Is 1
  | GAMEPAD_AXIS_RIGHT_X : GamepadAxis.Is 2
  | GAMEPAD_AXIS_RIGHT_Y : GamepadAxis.Is 3
  | GAMEPAD_AXIS_LEFT_TRIGGER : GamepadAxis.Is 4
  | GAMEPAD_AXIS_RIGHT_TRIGGER : GamepadAxis.Is 5

/-- Gamepad axis -/
def GamepadAxis : Type := Subtype GamepadAxis.Is

/-- Gamepad left stick X axis -/
def GAMEPAD_AXIS_LEFT_X : GamepadAxis := Subtype.mk 0 GamepadAxis.Is.GAMEPAD_AXIS_LEFT_X
/-- Gamepad left stick Y axis -/
def GAMEPAD_AXIS_LEFT_Y : GamepadAxis := Subtype.mk 1 GamepadAxis.Is.GAMEPAD_AXIS_LEFT_Y
/-- Gamepad right stick X axis -/
def GAMEPAD_AXIS_RIGHT_X : GamepadAxis := Subtype.mk 2 GamepadAxis.Is.GAMEPAD_AXIS_RIGHT_X
/-- Gamepad right stick Y axis -/
def GAMEPAD_AXIS_RIGHT_Y : GamepadAxis := Subtype.mk 3 GamepadAxis.Is.GAMEPAD_AXIS_RIGHT_Y
/-- Gamepad back trigger left, pressure level: [1..-1] -/
def GAMEPAD_AXIS_LEFT_TRIGGER : GamepadAxis := Subtype.mk 4 GamepadAxis.Is.GAMEPAD_AXIS_LEFT_TRIGGER
/-- Gamepad back trigger right, pressure level: [1..-1] -/
def GAMEPAD_AXIS_RIGHT_TRIGGER : GamepadAxis := Subtype.mk 5 GamepadAxis.Is.GAMEPAD_AXIS_RIGHT_TRIGGER


/-! # Material map indices -/

inductive MaterialMapIndex.Is : UInt32 -> Prop where
  | MATERIAL_MAP_ALBEDO : MaterialMapIndex.Is 0
  | MATERIAL_MAP_METALNESS : MaterialMapIndex.Is 1
  | MATERIAL_MAP_NORMAL : MaterialMapIndex.Is 2
  | MATERIAL_MAP_ROUGHNESS : MaterialMapIndex.Is 3
  | MATERIAL_MAP_OCCLUSION : MaterialMapIndex.Is 4
  | MATERIAL_MAP_EMISSION : MaterialMapIndex.Is 5
  | MATERIAL_MAP_HEIGHT : MaterialMapIndex.Is 6
  | MATERIAL_MAP_CUBEMAP : MaterialMapIndex.Is 7
  | MATERIAL_MAP_IRRADIANCE : MaterialMapIndex.Is 8
  | MATERIAL_MAP_PREFILTER : MaterialMapIndex.Is 9
  | MATERIAL_MAP_BRDF : MaterialMapIndex.Is 10

/-- Material map index -/
def MaterialMapIndex : Type := Subtype MaterialMapIndex.Is

/-- Albedo material (same as: MATERIAL_MAP_DIFFUSE) -/
def MATERIAL_MAP_ALBEDO : MaterialMapIndex := Subtype.mk 0 MaterialMapIndex.Is.MATERIAL_MAP_ALBEDO
/-- Metalness material (same as: MATERIAL_MAP_SPECULAR) -/
def MATERIAL_MAP_METALNESS : MaterialMapIndex := Subtype.mk 1 MaterialMapIndex.Is.MATERIAL_MAP_METALNESS
/-- Normal material -/
def MATERIAL_MAP_NORMAL : MaterialMapIndex := Subtype.mk 2 MaterialMapIndex.Is.MATERIAL_MAP_NORMAL
/-- Roughness material -/
def MATERIAL_MAP_ROUGHNESS : MaterialMapIndex := Subtype.mk 3 MaterialMapIndex.Is.MATERIAL_MAP_ROUGHNESS
/-- Ambient occlusion material -/
def MATERIAL_MAP_OCCLUSION : MaterialMapIndex := Subtype.mk 4 MaterialMapIndex.Is.MATERIAL_MAP_OCCLUSION
/-- Emission material -/
def MATERIAL_MAP_EMISSION : MaterialMapIndex := Subtype.mk 5 MaterialMapIndex.Is.MATERIAL_MAP_EMISSION
/-- Heightmap material -/
def MATERIAL_MAP_HEIGHT : MaterialMapIndex := Subtype.mk 6 MaterialMapIndex.Is.MATERIAL_MAP_HEIGHT
/-- Cubemap material (NOTE: Uses GL_TEXTURE_CUBE_MAP) -/
def MATERIAL_MAP_CUBEMAP : MaterialMapIndex := Subtype.mk 7 MaterialMapIndex.Is.MATERIAL_MAP_CUBEMAP
/-- Irradiance material (NOTE: Uses GL_TEXTURE_CUBE_MAP) -/
def MATERIAL_MAP_IRRADIANCE : MaterialMapIndex := Subtype.mk 8 MaterialMapIndex.Is.MATERIAL_MAP_IRRADIANCE
/-- Prefilter material (NOTE: Uses GL_TEXTURE_CUBE_MAP) -/
def MATERIAL_MAP_PREFILTER : MaterialMapIndex := Subtype.mk 9 MaterialMapIndex.Is.MATERIAL_MAP_PREFILTER
/-- Brdf material -/
def MATERIAL_MAP_BRDF : MaterialMapIndex := Subtype.mk 10 MaterialMapIndex.Is.MATERIAL_MAP_BRDF


/-! # Shader location index -/

inductive ShaderLocationIndex.Is : UInt32 -> Prop where
  | SHADER_LOC_VERTEX_POSITION : ShaderLocationIndex.Is 0
  | SHADER_LOC_VERTEX_TEXCOORD01 : ShaderLocationIndex.Is 1
  | SHADER_LOC_VERTEX_TEXCOORD02 : ShaderLocationIndex.Is 2
  | SHADER_LOC_VERTEX_NORMAL : ShaderLocationIndex.Is 3
  | SHADER_LOC_VERTEX_TANGENT : ShaderLocationIndex.Is 4
  | SHADER_LOC_VERTEX_COLOR : ShaderLocationIndex.Is 5
  | SHADER_LOC_MATRIX_MVP : ShaderLocationIndex.Is 6
  | SHADER_LOC_MATRIX_VIEW : ShaderLocationIndex.Is 7
  | SHADER_LOC_MATRIX_PROJECTION : ShaderLocationIndex.Is 8
  | SHADER_LOC_MATRIX_MODEL : ShaderLocationIndex.Is 9
  | SHADER_LOC_MATRIX_NORMAL : ShaderLocationIndex.Is 10
  | SHADER_LOC_VECTOR_VIEW : ShaderLocationIndex.Is 11
  | SHADER_LOC_COLOR_DIFFUSE : ShaderLocationIndex.Is 12
  | SHADER_LOC_COLOR_SPECULAR : ShaderLocationIndex.Is 13
  | SHADER_LOC_COLOR_AMBIENT : ShaderLocationIndex.Is 14
  | SHADER_LOC_MAP_ALBEDO : ShaderLocationIndex.Is 15
  | SHADER_LOC_MAP_METALNESS : ShaderLocationIndex.Is 16
  | SHADER_LOC_MAP_NORMAL : ShaderLocationIndex.Is 17
  | SHADER_LOC_MAP_ROUGHNESS : ShaderLocationIndex.Is 18
  | SHADER_LOC_MAP_OCCLUSION : ShaderLocationIndex.Is 19
  | SHADER_LOC_MAP_EMISSION : ShaderLocationIndex.Is 20
  | SHADER_LOC_MAP_HEIGHT : ShaderLocationIndex.Is 21
  | SHADER_LOC_MAP_CUBEMAP : ShaderLocationIndex.Is 22
  | SHADER_LOC_MAP_IRRADIANCE : ShaderLocationIndex.Is 23
  | SHADER_LOC_MAP_PREFILTER : ShaderLocationIndex.Is 24
  | SHADER_LOC_MAP_BRDF : ShaderLocationIndex.Is 25

/-- Shader location index -/
def ShaderLocationIndex : Type := Subtype ShaderLocationIndex.Is

/-- Shader location: vertex attribute: position -/
def SHADER_LOC_VERTEX_POSITION : ShaderLocationIndex := Subtype.mk 0 ShaderLocationIndex.Is.SHADER_LOC_VERTEX_POSITION
/-- Shader location: vertex attribute: texcoord01 -/
def SHADER_LOC_VERTEX_TEXCOORD01 : ShaderLocationIndex := Subtype.mk 1 ShaderLocationIndex.Is.SHADER_LOC_VERTEX_TEXCOORD01
/-- Shader location: vertex attribute: texcoord02 -/
def SHADER_LOC_VERTEX_TEXCOORD02 : ShaderLocationIndex := Subtype.mk 2 ShaderLocationIndex.Is.SHADER_LOC_VERTEX_TEXCOORD02
/-- Shader location: vertex attribute: normal -/
def SHADER_LOC_VERTEX_NORMAL : ShaderLocationIndex := Subtype.mk 3 ShaderLocationIndex.Is.SHADER_LOC_VERTEX_NORMAL
/-- Shader location: vertex attribute: tangent -/
def SHADER_LOC_VERTEX_TANGENT : ShaderLocationIndex := Subtype.mk 4 ShaderLocationIndex.Is.SHADER_LOC_VERTEX_TANGENT
/-- Shader location: vertex attribute: color -/
def SHADER_LOC_VERTEX_COLOR : ShaderLocationIndex := Subtype.mk 5 ShaderLocationIndex.Is.SHADER_LOC_VERTEX_COLOR
/-- Shader location: matrix uniform: model-view-projection -/
def SHADER_LOC_MATRIX_MVP : ShaderLocationIndex := Subtype.mk 6 ShaderLocationIndex.Is.SHADER_LOC_MATRIX_MVP
/-- Shader location: matrix uniform: view (camera transform) -/
def SHADER_LOC_MATRIX_VIEW : ShaderLocationIndex := Subtype.mk 7 ShaderLocationIndex.Is.SHADER_LOC_MATRIX_VIEW
/-- Shader location: matrix uniform: projection -/
def SHADER_LOC_MATRIX_PROJECTION : ShaderLocationIndex := Subtype.mk 8 ShaderLocationIndex.Is.SHADER_LOC_MATRIX_PROJECTION
/-- Shader location: matrix uniform: model (transform) -/
def SHADER_LOC_MATRIX_MODEL : ShaderLocationIndex := Subtype.mk 9 ShaderLocationIndex.Is.SHADER_LOC_MATRIX_MODEL
/-- Shader location: matrix uniform: normal -/
def SHADER_LOC_MATRIX_NORMAL : ShaderLocationIndex := Subtype.mk 10 ShaderLocationIndex.Is.SHADER_LOC_MATRIX_NORMAL
/-- Shader location: vector uniform: view -/
def SHADER_LOC_VECTOR_VIEW : ShaderLocationIndex := Subtype.mk 11 ShaderLocationIndex.Is.SHADER_LOC_VECTOR_VIEW
/-- Shader location: vector uniform: diffuse color -/
def SHADER_LOC_COLOR_DIFFUSE : ShaderLocationIndex := Subtype.mk 12 ShaderLocationIndex.Is.SHADER_LOC_COLOR_DIFFUSE
/-- Shader location: vector uniform: specular color -/
def SHADER_LOC_COLOR_SPECULAR : ShaderLocationIndex := Subtype.mk 13 ShaderLocationIndex.Is.SHADER_LOC_COLOR_SPECULAR
/-- Shader location: vector uniform: ambient color -/
def SHADER_LOC_COLOR_AMBIENT : ShaderLocationIndex := Subtype.mk 14 ShaderLocationIndex.Is.SHADER_LOC_COLOR_AMBIENT
/-- Shader location: sampler2d texture: albedo (same as: SHADER_LOC_MAP_DIFFUSE) -/
def SHADER_LOC_MAP_ALBEDO : ShaderLocationIndex := Subtype.mk 15 ShaderLocationIndex.Is.SHADER_LOC_MAP_ALBEDO
/-- Shader location: sampler2d texture: metalness (same as: SHADER_LOC_MAP_SPECULAR) -/
def SHADER_LOC_MAP_METALNESS : ShaderLocationIndex := Subtype.mk 16 ShaderLocationIndex.Is.SHADER_LOC_MAP_METALNESS
/-- Shader location: sampler2d texture: normal -/
def SHADER_LOC_MAP_NORMAL : ShaderLocationIndex := Subtype.mk 17 ShaderLocationIndex.Is.SHADER_LOC_MAP_NORMAL
/-- Shader location: sampler2d texture: roughness -/
def SHADER_LOC_MAP_ROUGHNESS : ShaderLocationIndex := Subtype.mk 18 ShaderLocationIndex.Is.SHADER_LOC_MAP_ROUGHNESS
/-- Shader location: sampler2d texture: occlusion -/
def SHADER_LOC_MAP_OCCLUSION : ShaderLocationIndex := Subtype.mk 19 ShaderLocationIndex.Is.SHADER_LOC_MAP_OCCLUSION
/-- Shader location: sampler2d texture: emission -/
def SHADER_LOC_MAP_EMISSION : ShaderLocationIndex := Subtype.mk 20 ShaderLocationIndex.Is.SHADER_LOC_MAP_EMISSION
/-- Shader location: sampler2d texture: height -/
def SHADER_LOC_MAP_HEIGHT : ShaderLocationIndex := Subtype.mk 21 ShaderLocationIndex.Is.SHADER_LOC_MAP_HEIGHT
/-- Shader location: samplerCube texture: cubemap -/
def SHADER_LOC_MAP_CUBEMAP : ShaderLocationIndex := Subtype.mk 22 ShaderLocationIndex.Is.SHADER_LOC_MAP_CUBEMAP
/-- Shader location: samplerCube texture: irradiance -/
def SHADER_LOC_MAP_IRRADIANCE : ShaderLocationIndex := Subtype.mk 23 ShaderLocationIndex.Is.SHADER_LOC_MAP_IRRADIANCE
/-- Shader location: samplerCube texture: prefilter -/
def SHADER_LOC_MAP_PREFILTER : ShaderLocationIndex := Subtype.mk 24 ShaderLocationIndex.Is.SHADER_LOC_MAP_PREFILTER
/-- Shader location: sampler2d texture: brdf -/
def SHADER_LOC_MAP_BRDF : ShaderLocationIndex := Subtype.mk 25 ShaderLocationIndex.Is.SHADER_LOC_MAP_BRDF


/-! # Shader uniform data type -/

inductive ShaderUniformDataType.Is : UInt32 -> Prop where
  | SHADER_UNIFORM_FLOAT : ShaderUniformDataType.Is 0
  | SHADER_UNIFORM_VEC2 : ShaderUniformDataType.Is 1
  | SHADER_UNIFORM_VEC3 : ShaderUniformDataType.Is 2
  | SHADER_UNIFORM_VEC4 : ShaderUniformDataType.Is 3
  | SHADER_UNIFORM_INT : ShaderUniformDataType.Is 4
  | SHADER_UNIFORM_IVEC2 : ShaderUniformDataType.Is 5
  | SHADER_UNIFORM_IVEC3 : ShaderUniformDataType.Is 6
  | SHADER_UNIFORM_IVEC4 : ShaderUniformDataType.Is 7
  | SHADER_UNIFORM_SAMPLER2D : ShaderUniformDataType.Is 8

/-- Shader uniform data type -/
def ShaderUniformDataType : Type := Subtype ShaderUniformDataType.Is

/-- Shader uniform type: float -/
def SHADER_UNIFORM_FLOAT : ShaderUniformDataType := Subtype.mk 0 ShaderUniformDataType.Is.SHADER_UNIFORM_FLOAT
/-- Shader uniform type: vec2 (2 float) -/
def SHADER_UNIFORM_VEC2 : ShaderUniformDataType := Subtype.mk 1 ShaderUniformDataType.Is.SHADER_UNIFORM_VEC2
/-- Shader uniform type: vec3 (3 float) -/
def SHADER_UNIFORM_VEC3 : ShaderUniformDataType := Subtype.mk 2 ShaderUniformDataType.Is.SHADER_UNIFORM_VEC3
/-- Shader uniform type: vec4 (4 float) -/
def SHADER_UNIFORM_VEC4 : ShaderUniformDataType := Subtype.mk 3 ShaderUniformDataType.Is.SHADER_UNIFORM_VEC4
/-- Shader uniform type: int -/
def SHADER_UNIFORM_INT : ShaderUniformDataType := Subtype.mk 4 ShaderUniformDataType.Is.SHADER_UNIFORM_INT
/-- Shader uniform type: ivec2 (2 int) -/
def SHADER_UNIFORM_IVEC2 : ShaderUniformDataType := Subtype.mk 5 ShaderUniformDataType.Is.SHADER_UNIFORM_IVEC2
/-- Shader uniform type: ivec3 (3 int) -/
def SHADER_UNIFORM_IVEC3 : ShaderUniformDataType := Subtype.mk 6 ShaderUniformDataType.Is.SHADER_UNIFORM_IVEC3
/-- Shader uniform type: ivec4 (4 int) -/
def SHADER_UNIFORM_IVEC4 : ShaderUniformDataType := Subtype.mk 7 ShaderUniformDataType.Is.SHADER_UNIFORM_IVEC4
/-- Shader uniform type: sampler2d -/
def SHADER_UNIFORM_SAMPLER2D : ShaderUniformDataType := Subtype.mk 8 ShaderUniformDataType.Is.SHADER_UNIFORM_SAMPLER2D


/-! # Shader attribute data type -/

inductive ShaderAttributeDataType.Is : UInt32 -> Prop where
  | SHADER_ATTRIB_FLOAT : ShaderAttributeDataType.Is 0
  | SHADER_ATTRIB_VEC2 : ShaderAttributeDataType.Is 1
  | SHADER_ATTRIB_VEC3 : ShaderAttributeDataType.Is 2
  | SHADER_ATTRIB_VEC4 : ShaderAttributeDataType.Is 3

/-- Shader attribute data types -/
def ShaderAttributeDataType : Type := Subtype ShaderAttributeDataType.Is

/-- Shader attribute type: float -/
def SHADER_ATTRIB_FLOAT : ShaderAttributeDataType := Subtype.mk 0 ShaderAttributeDataType.Is.SHADER_ATTRIB_FLOAT
/-- Shader attribute type: vec2 (2 float) -/
def SHADER_ATTRIB_VEC2 : ShaderAttributeDataType := Subtype.mk 1 ShaderAttributeDataType.Is.SHADER_ATTRIB_VEC2
/-- Shader attribute type: vec3 (3 float) -/
def SHADER_ATTRIB_VEC3 : ShaderAttributeDataType := Subtype.mk 2 ShaderAttributeDataType.Is.SHADER_ATTRIB_VEC3
/-- Shader attribute type: vec4 (4 float) -/
def SHADER_ATTRIB_VEC4 : ShaderAttributeDataType := Subtype.mk 3 ShaderAttributeDataType.Is.SHADER_ATTRIB_VEC4


/-! # Pixel format -/

inductive PixelFormat.Is : UInt32 -> Prop where
  | PIXELFORMAT_UNCOMPRESSED_GRAYSCALE : PixelFormat.Is 1
  | PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA : PixelFormat.Is 2
  | PIXELFORMAT_UNCOMPRESSED_R5G6B5 : PixelFormat.Is 3
  | PIXELFORMAT_UNCOMPRESSED_R8G8B8 : PixelFormat.Is 4
  | PIXELFORMAT_UNCOMPRESSED_R5G5B5A1 : PixelFormat.Is 5
  | PIXELFORMAT_UNCOMPRESSED_R4G4B4A4 : PixelFormat.Is 6
  | PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 : PixelFormat.Is 7
  | PIXELFORMAT_UNCOMPRESSED_R32 : PixelFormat.Is 8
  | PIXELFORMAT_UNCOMPRESSED_R32G32B32 : PixelFormat.Is 9
  | PIXELFORMAT_UNCOMPRESSED_R32G32B32A32 : PixelFormat.Is 10
  | PIXELFORMAT_COMPRESSED_DXT1_RGB : PixelFormat.Is 11
  | PIXELFORMAT_COMPRESSED_DXT1_RGBA : PixelFormat.Is 12
  | PIXELFORMAT_COMPRESSED_DXT3_RGBA : PixelFormat.Is 13
  | PIXELFORMAT_COMPRESSED_DXT5_RGBA : PixelFormat.Is 14
  | PIXELFORMAT_COMPRESSED_ETC1_RGB : PixelFormat.Is 15
  | PIXELFORMAT_COMPRESSED_ETC2_RGB : PixelFormat.Is 16
  | PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA : PixelFormat.Is 17
  | PIXELFORMAT_COMPRESSED_PVRT_RGB : PixelFormat.Is 18
  | PIXELFORMAT_COMPRESSED_PVRT_RGBA : PixelFormat.Is 19
  | PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA : PixelFormat.Is 20
  | PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA : PixelFormat.Is 21

/-- Pixel formats -/
def PixelFormat : Type := Subtype PixelFormat.Is

/-- 8 bit per pixel (no alpha) -/
def PIXELFORMAT_UNCOMPRESSED_GRAYSCALE : PixelFormat := Subtype.mk 1 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_GRAYSCALE
/-- 8*2 bpp (2 channels) -/
def PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA : PixelFormat := Subtype.mk 2 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA
/-- 16 bpp -/
def PIXELFORMAT_UNCOMPRESSED_R5G6B5 : PixelFormat := Subtype.mk 3 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_R5G6B5
/-- 24 bpp -/
def PIXELFORMAT_UNCOMPRESSED_R8G8B8 : PixelFormat := Subtype.mk 4 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_R8G8B8
/-- 16 bpp (1 bit alpha) -/
def PIXELFORMAT_UNCOMPRESSED_R5G5B5A1 : PixelFormat := Subtype.mk 5 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_R5G5B5A1
/-- 16 bpp (4 bit alpha) -/
def PIXELFORMAT_UNCOMPRESSED_R4G4B4A4 : PixelFormat := Subtype.mk 6 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_R4G4B4A4
/-- 32 bpp -/
def PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 : PixelFormat := Subtype.mk 7 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
/-- 32 bpp (1 channel - float) -/
def PIXELFORMAT_UNCOMPRESSED_R32 : PixelFormat := Subtype.mk 8 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_R32
/-- 32*3 bpp (3 channels - float) -/
def PIXELFORMAT_UNCOMPRESSED_R32G32B32 : PixelFormat := Subtype.mk 9 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_R32G32B32
/-- 32*4 bpp (4 channels - float) -/
def PIXELFORMAT_UNCOMPRESSED_R32G32B32A32 : PixelFormat := Subtype.mk 10 PixelFormat.Is.PIXELFORMAT_UNCOMPRESSED_R32G32B32A32
/-- 4 bpp (no alpha) -/
def PIXELFORMAT_COMPRESSED_DXT1_RGB : PixelFormat := Subtype.mk 11 PixelFormat.Is.PIXELFORMAT_COMPRESSED_DXT1_RGB
/-- 4 bpp (1 bit alpha) -/
def PIXELFORMAT_COMPRESSED_DXT1_RGBA : PixelFormat := Subtype.mk 12 PixelFormat.Is.PIXELFORMAT_COMPRESSED_DXT1_RGBA
/-- 8 bpp -/
def PIXELFORMAT_COMPRESSED_DXT3_RGBA : PixelFormat := Subtype.mk 13 PixelFormat.Is.PIXELFORMAT_COMPRESSED_DXT3_RGBA
/-- 8 bpp -/
def PIXELFORMAT_COMPRESSED_DXT5_RGBA : PixelFormat := Subtype.mk 14 PixelFormat.Is.PIXELFORMAT_COMPRESSED_DXT5_RGBA
/-- 4 bpp -/
def PIXELFORMAT_COMPRESSED_ETC1_RGB : PixelFormat := Subtype.mk 15 PixelFormat.Is.PIXELFORMAT_COMPRESSED_ETC1_RGB
/-- 4 bpp -/
def PIXELFORMAT_COMPRESSED_ETC2_RGB : PixelFormat := Subtype.mk 16 PixelFormat.Is.PIXELFORMAT_COMPRESSED_ETC2_RGB
/-- 8 bpp -/
def PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA : PixelFormat := Subtype.mk 17 PixelFormat.Is.PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA
/-- 4 bpp -/
def PIXELFORMAT_COMPRESSED_PVRT_RGB : PixelFormat := Subtype.mk 18 PixelFormat.Is.PIXELFORMAT_COMPRESSED_PVRT_RGB
/-- 4 bpp -/
def PIXELFORMAT_COMPRESSED_PVRT_RGBA : PixelFormat := Subtype.mk 19 PixelFormat.Is.PIXELFORMAT_COMPRESSED_PVRT_RGBA
/-- 8 bpp -/
def PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA : PixelFormat := Subtype.mk 20 PixelFormat.Is.PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA
/-- 2 bpp -/
def PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA : PixelFormat := Subtype.mk 21 PixelFormat.Is.PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA

instance instInhabitedPixelFormat : Inhabited PixelFormat where
  default := PIXELFORMAT_UNCOMPRESSED_R8G8B8A8


/-! # Texture filter -/

inductive TextureFilter.Is : UInt32 -> Prop where
  | TEXTURE_FILTER_POINT : TextureFilter.Is 0
  | TEXTURE_FILTER_BILINEAR : TextureFilter.Is 1
  | TEXTURE_FILTER_TRILINEAR : TextureFilter.Is 2
  | TEXTURE_FILTER_ANISOTROPIC_4X : TextureFilter.Is 3
  | TEXTURE_FILTER_ANISOTROPIC_8X : TextureFilter.Is 4
  | TEXTURE_FILTER_ANISOTROPIC_16X : TextureFilter.Is 5

/-- Texture parameters: filter mode -/
def TextureFilter : Type := Subtype TextureFilter.Is

/-- No filter, just pixel approximation -/
def TEXTURE_FILTER_POINT : TextureFilter := Subtype.mk 0 TextureFilter.Is.TEXTURE_FILTER_POINT
/-- Linear filtering -/
def TEXTURE_FILTER_BILINEAR : TextureFilter := Subtype.mk 1 TextureFilter.Is.TEXTURE_FILTER_BILINEAR
/-- Trilinear filtering (linear with mipmaps) -/
def TEXTURE_FILTER_TRILINEAR : TextureFilter := Subtype.mk 2 TextureFilter.Is.TEXTURE_FILTER_TRILINEAR
/-- Anisotropic filtering 4x -/
def TEXTURE_FILTER_ANISOTROPIC_4X : TextureFilter := Subtype.mk 3 TextureFilter.Is.TEXTURE_FILTER_ANISOTROPIC_4X
/-- Anisotropic filtering 8x -/
def TEXTURE_FILTER_ANISOTROPIC_8X : TextureFilter := Subtype.mk 4 TextureFilter.Is.TEXTURE_FILTER_ANISOTROPIC_8X
/-- Anisotropic filtering 16x -/
def TEXTURE_FILTER_ANISOTROPIC_16X : TextureFilter := Subtype.mk 5 TextureFilter.Is.TEXTURE_FILTER_ANISOTROPIC_16X


/-! # Texture wrap -/

inductive TextureWrap.Is : UInt32 -> Prop where
  | TEXTURE_WRAP_REPEAT : TextureWrap.Is 0
  | TEXTURE_WRAP_CLAMP : TextureWrap.Is 1
  | TEXTURE_WRAP_MIRROR_REPEAT : TextureWrap.Is 2
  | TEXTURE_WRAP_MIRROR_CLAMP : TextureWrap.Is 3

/-- Texture parameters: wrap mode -/
def TextureWrap : Type := Subtype TextureWrap.Is

/-- Repeats texture in tiled mode -/
def TEXTURE_WRAP_REPEAT : TextureWrap := Subtype.mk 0 TextureWrap.Is.TEXTURE_WRAP_REPEAT
/-- Clamps texture to edge pixel in tiled mode -/
def TEXTURE_WRAP_CLAMP : TextureWrap := Subtype.mk 1 TextureWrap.Is.TEXTURE_WRAP_CLAMP
/-- Mirrors and repeats the texture in tiled mode -/
def TEXTURE_WRAP_MIRROR_REPEAT : TextureWrap := Subtype.mk 2 TextureWrap.Is.TEXTURE_WRAP_MIRROR_REPEAT
/-- Mirrors and clamps to border the texture in tiled mode -/
def TEXTURE_WRAP_MIRROR_CLAMP : TextureWrap := Subtype.mk 3 TextureWrap.Is.TEXTURE_WRAP_MIRROR_CLAMP


/-! # Cubemap layout -/

inductive CubemapLayout.Is : UInt32 -> Prop where
  | CUBEMAP_LAYOUT_AUTO_DETECT : CubemapLayout.Is 0
  | CUBEMAP_LAYOUT_LINE_VERTICAL : CubemapLayout.Is 1
  | CUBEMAP_LAYOUT_LINE_HORIZONTAL : CubemapLayout.Is 2
  | CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR : CubemapLayout.Is 3
  | CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE : CubemapLayout.Is 4
  | CUBEMAP_LAYOUT_PANORAMA : CubemapLayout.Is 5

/-- Cubemap layouts -/
def CubemapLayout : Type := Subtype CubemapLayout.Is

/-- Automatically detect layout type -/
def CUBEMAP_LAYOUT_AUTO_DETECT : CubemapLayout := Subtype.mk 0 CubemapLayout.Is.CUBEMAP_LAYOUT_AUTO_DETECT
/-- Layout is defined by a vertical line with faces -/
def CUBEMAP_LAYOUT_LINE_VERTICAL : CubemapLayout := Subtype.mk 1 CubemapLayout.Is.CUBEMAP_LAYOUT_LINE_VERTICAL
/-- Layout is defined by an horizontal line with faces -/
def CUBEMAP_LAYOUT_LINE_HORIZONTAL : CubemapLayout := Subtype.mk 2 CubemapLayout.Is.CUBEMAP_LAYOUT_LINE_HORIZONTAL
/-- Layout is defined by a 3x4 cross with cubemap faces -/
def CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR : CubemapLayout := Subtype.mk 3 CubemapLayout.Is.CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR
/-- Layout is defined by a 4x3 cross with cubemap faces -/
def CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE : CubemapLayout := Subtype.mk 4 CubemapLayout.Is.CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE
/-- Layout is defined by a panorama image (equirectangular map) -/
def CUBEMAP_LAYOUT_PANORAMA : CubemapLayout := Subtype.mk 5 CubemapLayout.Is.CUBEMAP_LAYOUT_PANORAMA


/-! # Font type -/

inductive FontType.Is : UInt32 -> Prop where
  | FONT_DEFAULT : FontType.Is 0
  | FONT_BITMAP : FontType.Is 1
  | FONT_SDF : FontType.Is 2

/-- Font type, defines generation method -/
def FontType : Type := Subtype FontType.Is

/-- Default font generation, anti-aliased -/
def FONT_DEFAULT : FontType := Subtype.mk 0 FontType.Is.FONT_DEFAULT
/-- Bitmap font generation, no anti-aliasing -/
def FONT_BITMAP : FontType := Subtype.mk 1 FontType.Is.FONT_BITMAP
/-- SDF font generation, requires external shader -/
def FONT_SDF : FontType := Subtype.mk 2 FontType.Is.FONT_SDF


/-! # Color blending mode -/

inductive BlendMode.Is : UInt32 -> Prop where
  | BLEND_ALPHA : BlendMode.Is 0
  | BLEND_ADDITIVE : BlendMode.Is 1
  | BLEND_MULTIPLIED : BlendMode.Is 2
  | BLEND_ADD_COLORS : BlendMode.Is 3
  | BLEND_SUBTRACT_COLORS : BlendMode.Is 4
  | BLEND_ALPHA_PREMULTIPLY : BlendMode.Is 5
  | BLEND_CUSTOM : BlendMode.Is 6
  | BLEND_CUSTOM_SEPARATE : BlendMode.Is 7

/-- Color blending modes (pre-defined) -/
def BlendMode : Type := Subtype BlendMode.Is

/-- Blend textures considering alpha (default) -/
def BLEND_ALPHA : BlendMode := Subtype.mk 0 BlendMode.Is.BLEND_ALPHA
/-- Blend textures adding colors -/
def BLEND_ADDITIVE : BlendMode := Subtype.mk 1 BlendMode.Is.BLEND_ADDITIVE
/-- Blend textures multiplying colors -/
def BLEND_MULTIPLIED : BlendMode := Subtype.mk 2 BlendMode.Is.BLEND_MULTIPLIED
/-- Blend textures adding colors (alternative) -/
def BLEND_ADD_COLORS : BlendMode := Subtype.mk 3 BlendMode.Is.BLEND_ADD_COLORS
/-- Blend textures subtracting colors (alternative) -/
def BLEND_SUBTRACT_COLORS : BlendMode := Subtype.mk 4 BlendMode.Is.BLEND_SUBTRACT_COLORS
/-- Blend premultiplied textures considering alpha -/
def BLEND_ALPHA_PREMULTIPLY : BlendMode := Subtype.mk 5 BlendMode.Is.BLEND_ALPHA_PREMULTIPLY
/-- Blend textures using custom src/dst factors (use rlSetBlendFactors()) -/
def BLEND_CUSTOM : BlendMode := Subtype.mk 6 BlendMode.Is.BLEND_CUSTOM
/-- Blend textures using custom rgb/alpha separate src/dst factors (use rlSetBlendFactorsSeparate()) -/
def BLEND_CUSTOM_SEPARATE : BlendMode := Subtype.mk 7 BlendMode.Is.BLEND_CUSTOM_SEPARATE


/-! # Gesture -/

/-- Gesture -/
structure Gesture where
  val : UInt32
deriving Inhabited, Repr

abbrev GestureFlags := Gesture

instance : OrOp Gesture where
  or := λ a b ↦ Gesture.mk (a.val ||| b.val)

instance : AndOp Gesture where
  and := λ a b ↦ Gesture.mk (a.val &&& b.val)

/-- No gesture -/
def GESTURE_NONE : Gesture := Gesture.mk 0
/-- Tap gesture -/
def GESTURE_TAP : Gesture := Gesture.mk 1
/-- Double tap gesture -/
def GESTURE_DOUBLETAP : Gesture := Gesture.mk 2
/-- Hold gesture -/
def GESTURE_HOLD : Gesture := Gesture.mk 4
/-- Drag gesture -/
def GESTURE_DRAG : Gesture := Gesture.mk 8
/-- Swipe right gesture -/
def GESTURE_SWIPE_RIGHT : Gesture := Gesture.mk 16
/-- Swipe left gesture -/
def GESTURE_SWIPE_LEFT : Gesture := Gesture.mk 32
/-- Swipe up gesture -/
def GESTURE_SWIPE_UP : Gesture := Gesture.mk 64
/-- Swipe down gesture -/
def GESTURE_SWIPE_DOWN : Gesture := Gesture.mk 128
/-- Pinch in gesture -/
def GESTURE_PINCH_IN : Gesture := Gesture.mk 256
/-- Pinch out gesture -/
def GESTURE_PINCH_OUT : Gesture := Gesture.mk 512


/-! # Camera mode -/

inductive CameraMode.Is : UInt32 -> Prop where
  | CAMERA_CUSTOM : CameraMode.Is 0
  | CAMERA_FREE : CameraMode.Is 1
  | CAMERA_ORBITAL : CameraMode.Is 2
  | CAMERA_FIRST_PERSON : CameraMode.Is 3
  | CAMERA_THIRD_PERSON : CameraMode.Is 4

/-- Camera system modes -/
def CameraMode : Type := Subtype CameraMode.Is

/-- Custom camera -/
def CAMERA_CUSTOM : CameraMode := Subtype.mk 0 CameraMode.Is.CAMERA_CUSTOM
/-- Free camera -/
def CAMERA_FREE : CameraMode := Subtype.mk 1 CameraMode.Is.CAMERA_FREE
/-- Orbital camera -/
def CAMERA_ORBITAL : CameraMode := Subtype.mk 2 CameraMode.Is.CAMERA_ORBITAL
/-- First person camera -/
def CAMERA_FIRST_PERSON : CameraMode := Subtype.mk 3 CameraMode.Is.CAMERA_FIRST_PERSON
/-- Third person camera -/
def CAMERA_THIRD_PERSON : CameraMode := Subtype.mk 4 CameraMode.Is.CAMERA_THIRD_PERSON


/-! # Camera projection -/

inductive CameraProjection.Is : UInt32 -> Prop where
  | CAMERA_PERSPECTIVE : CameraProjection.Is 0
  | CAMERA_ORTHOGRAPHIC : CameraProjection.Is 1

/-- Camera projection -/
def CameraProjection : Type := Subtype CameraProjection.Is

/-- Perspective projection -/
def CAMERA_PERSPECTIVE : CameraProjection := Subtype.mk 0 CameraProjection.Is.CAMERA_PERSPECTIVE
/-- Orthographic projection -/
def CAMERA_ORTHOGRAPHIC : CameraProjection := Subtype.mk 1 CameraProjection.Is.CAMERA_ORTHOGRAPHIC


/-! # NPatch layout -/

inductive NPatchLayout.Is : UInt32 -> Prop where
  | NPATCH_NINE_PATCH : NPatchLayout.Is 0
  | NPATCH_THREE_PATCH_VERTICAL : NPatchLayout.Is 1
  | NPATCH_THREE_PATCH_HORIZONTAL : NPatchLayout.Is 2

/-- N-patch layout -/
def NPatchLayout : Type := Subtype NPatchLayout.Is

/-- Npatch layout: 3x3 tiles -/
def NPATCH_NINE_PATCH : NPatchLayout := Subtype.mk 0 NPatchLayout.Is.NPATCH_NINE_PATCH
/-- Npatch layout: 1x3 tiles -/
def NPATCH_THREE_PATCH_VERTICAL : NPatchLayout := Subtype.mk 1 NPatchLayout.Is.NPATCH_THREE_PATCH_VERTICAL
/-- Npatch layout: 3x1 tiles -/
def NPATCH_THREE_PATCH_HORIZONTAL : NPatchLayout := Subtype.mk 2 NPatchLayout.Is.NPATCH_THREE_PATCH_HORIZONTAL

end Raylib
