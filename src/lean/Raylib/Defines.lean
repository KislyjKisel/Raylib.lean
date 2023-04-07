import Raylib.Structures

namespace Raylib

def RAYLIB_VERSION_MAJOR := 4
def RAYLIB_VERSION_MINOR := 5
def RAYLIB_VERSION_PATCH := 0
def RAYLIB_VERSION := "4.5"

/-- Light Gray -/
def LIGHTGRAY : Color := Color.fromRgba 200 200 200 255
/-- Gray -/
def GRAY : Color := Color.fromRgba 130 130 130 255
/-- Dark Gray -/
def DARKGRAY : Color := Color.fromRgba 80 80 80 255
/-- Yellow -/
def YELLOW : Color := Color.fromRgba 253 249 0 255
/-- Gold -/
def GOLD : Color := Color.fromRgba 255 203 0 255
/-- Orange -/
def ORANGE : Color := Color.fromRgba 255 161 0 255
/-- Pink -/
def PINK : Color := Color.fromRgba 255 109 194 255
/-- Red -/
def RED : Color := Color.fromRgba 230 41 55 255
/-- Maroon -/
def MAROON : Color := Color.fromRgba 190 33 55 255
/-- Green -/
def GREEN : Color := Color.fromRgba 0 228 48 255
/-- Lime -/
def LIME : Color := Color.fromRgba 0 158 47 255
/-- Dark Green -/
def DARKGREEN : Color := Color.fromRgba 0 117 44 255
/-- Sky Blue -/
def SKYBLUE : Color := Color.fromRgba 102 191 255 255
/-- Blue -/
def BLUE : Color := Color.fromRgba 0 121 241 255
/-- Dark Blue -/
def DARKBLUE : Color := Color.fromRgba 0 82 172 255
/-- Purple -/
def PURPLE : Color := Color.fromRgba 200 122 255 255
/-- Violet -/
def VIOLET : Color := Color.fromRgba 135 60 190 255
/-- Dark Purple -/
def DARKPURPLE : Color := Color.fromRgba 112 31 126 255
/-- Beige -/
def BEIGE : Color := Color.fromRgba 211 176 131 255
/-- Brown -/
def BROWN : Color := Color.fromRgba 127 106 79 255
/-- Dark Brown -/
def DARKBROWN : Color := Color.fromRgba 76 63 47 255
/-- White -/
def WHITE : Color := Color.fromRgba 255 255 255 255
/-- Black -/
def BLACK : Color := Color.fromRgba 0 0 0 255
/-- Blank (Transparent) -/
def BLANK : Color := Color.fromRgba 0 0 0 0
/-- Magenta -/
def MAGENTA : Color := Color.fromRgba 255 0 255 255
/-- My own White (raylib logo) -/
def RAYWHITE : Color := Color.fromRgba 245 245 245 255

end Raylib
