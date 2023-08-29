import Pod.Float
import Pod.ReadBytes
import Pod.WriteBytes

open Pod (Float32 Storable ReadBytes WriteBytes byteSize alignment)

namespace Raymath

/-! # Constants -/

def pi : Float32 := 3.141592653589793
def epsilon : Float32 := 0.000001
def deg2Rad : Float32 := pi / 180
def rad2Deg : Float32 := 180 / pi

/-! # Types and Structures Definition -/

structure Vector2 where
  x : Float32
  y : Float32
deriving Inhabited, Repr

instance : Storable Vector2 where
  byteSize := 2 * byteSize Float32
  alignment := alignment Float32
  alignment_dvd_byteSize := by exists 2

structure Vector3 where
  x : Float32
  y : Float32
  z : Float32
deriving Inhabited, Repr

structure Vector4 where
  x : Float32
  y : Float32
  z : Float32
  w : Float32
deriving Inhabited, Repr

/-- Quaternion, 4 components (Vector4 alias) -/
abbrev Quaternion := Vector4

/--
Matrix type (OpenGL style 4x4 - right handed, column major).

Field names (`m.m14`):
```c
 0  4  8 12
 1  5  9 13
 2  6 10 14
 3  7 11 15
```
Field indices (`m.12`):
```c
 1  2  3  4
 5  6  7  8
 9 10 11 12
13 14 15 16
```
-/
structure Matrix where
  -- Matrix first row
  m0 : Float32
  m4 : Float32
  m8 : Float32
  m12 : Float32
  -- Matrix second row
  m1 : Float32
  m5 : Float32
  m9 : Float32
  m13 : Float32
  -- Matrix third row
  m2 : Float32
  m6 : Float32
  m10 : Float32
  m14 : Float32
  -- Matrix fourth row
  m3 : Float32
  m7 : Float32
  m11 : Float32
  m15 : Float32
deriving Inhabited, Repr

end Raymath
