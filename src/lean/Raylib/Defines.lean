import Raylib.Structures

namespace Raylib

def versionMajor := 5
def versionMinor := 5
def versionPatch := 0
def version := "5.5-dev"


namespace Color

def lightgray : Color := Color.fromRgba 200 200 200 255
def gray : Color := Color.fromRgba 130 130 130 255
def darkgray : Color := Color.fromRgba 80 80 80 255
def yellow : Color := Color.fromRgba 253 249 0 255
def gold : Color := Color.fromRgba 255 203 0 255
def orange : Color := Color.fromRgba 255 161 0 255
def pink : Color := Color.fromRgba 255 109 194 255
def red : Color := Color.fromRgba 230 41 55 255
def maroon : Color := Color.fromRgba 190 33 55 255
def green : Color := Color.fromRgba 0 228 48 255
def lime : Color := Color.fromRgba 0 158 47 255
def darkgreen : Color := Color.fromRgba 0 117 44 255
def skyblue : Color := Color.fromRgba 102 191 255 255
def blue : Color := Color.fromRgba 0 121 241 255
def darkblue : Color := Color.fromRgba 0 82 172 255
def purple : Color := Color.fromRgba 200 122 255 255
def violet : Color := Color.fromRgba 135 60 190 255
def darkpurple : Color := Color.fromRgba 112 31 126 255
def beige : Color := Color.fromRgba 211 176 131 255
def brown : Color := Color.fromRgba 127 106 79 255
def darkbrown : Color := Color.fromRgba 76 63 47 255
def white : Color := Color.fromRgba 255 255 255 255
def black : Color := Color.fromRgba 0 0 0 255
def magenta : Color := Color.fromRgba 255 0 255 255

/-- Transparent (black) -/
def blank : Color := Color.fromRgba 0 0 0 0

/-- Raylib White (logo) -/
def raywhite : Color := Color.fromRgba 245 245 245 255

end Color


end Raylib
