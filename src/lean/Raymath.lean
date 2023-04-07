import Pod.Float32

set_option autoImplicit false

/-! # Constants -/

namespace Raymath

def pi : Float32 := 3.141592653589793
def epsilon : Float32 := 0.000001
def deg2rad : Float32 := pi / 180
def rad2deg : Float32 := 180 / pi

end Raymath

/-! # Types and Structures Definition -/

namespace Raymath

structure Vector2 where
  x : Float32
  y : Float32
deriving Inhabited, Repr

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

/-- Matrix type (OpenGL style 4x4 - right handed, column major) -/
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


/-! # Functions Definition -/

/-! ## Utils math -/

namespace Float32

/-- Clamp Float32 value -/
def clamp (value min max : Float32) : Float32 :=
  let x := if value < min then min else value
  if x > max then max else x

/-- Calculate linear interpolation between two Float32s -/
def lerp (start finish amount : Float32) : Float32 :=
  start + amount * (finish - start)

/-- Normalize input value within input range -/
def normalize (value start finish : Float32) : Float32 :=
  (value - start) / (finish - start)

/-- Remap input value within input range to output range -/
def remap (value inputStart inputEnd outputStart outputEnd : Float32) : Float32 :=
  (value - inputStart) / (inputEnd - inputStart) * (outputEnd - outputStart) + outputStart

/-- Wrap input value from min to max -/
def wrap (value min max : Float32) : Float32 :=
  value - (max - min) * ((value - min) / (max - min)).floor

/-- Check whether two given floats are almost equal -/
def equals (x y : Float32) : Bool :=
  (x - y).abs <= Raymath.epsilon * Float32.one.max (x.abs.max y.abs)

end Float32


/-! ## Vector2 math -/

namespace Raymath.Vector2

/-- Vector with components value 0.0f -/
def zero : Vector2 := Vector2.mk Float32.zero Float32.zero

/-- Vector with components value 1.0f -/
def one : Vector2 := Vector2.mk Float32.one Float32.one

/-- Add two vectors (v1 + v2) -/
def add (v1 v2 : Vector2) : Vector2 := Vector2.mk (v1.x + v2.x) (v1.y + v2.y)

/-- Add vector and float value -/
def addValue (v : Vector2) (add : Float32) : Vector2 := Vector2.mk (v.x + add) (v.y + add)

/-- Subtract two vectors (v1 - v2) -/
def sub (v1 v2 : Vector2) : Vector2 := Vector2.mk (v1.x - v2.x) (v1.y - v2.y)

/-- Subtract vector by float value -/
def subValue (v : Vector2) (sub : Float32) : Vector2 := Vector2.mk (v.x - sub) (v.y - sub)

/-- Calculate vector length -/
def length (v : Vector2) : Float32 := (v.x * v.x + v.y * v.y).sqrt

/-- Calculate vector square length -/
def lengthSqr (v : Vector2) : Float32 := v.x * v.x + v.y * v.y

/-- Calculate two vectors dot product -/
def dot (v1 v2 : Vector2) : Float32 := v1.x * v2.x + v1.y * v2.y

/-- Calculate distance between two vectors -/
def distance (v1 v2 : Vector2) : Float32 :=
  ((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)).sqrt

/-- Calculate square distance between two vectors -/
def distanceSqr (v1 v2 : Vector2) : Float32 :=
  (v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)

/--
Calculate angle between two vectors.
NOTE: Angle is calculated from origin point (0, 0).
-/
def angle (v1 v2 : Vector2) : Float32 := Float32.atan2 (v2.y - v1.y) (v2.x - v1.x)

/--
Calculate angle defined by a two vectors line.
NOTE: Parameters need to be normalized.
Current implementation should be aligned with glm::angle.
-/
def lineAngle (start finish : Vector2) : Float32 :=
  let dot := start.x * finish.x + start.y * finish.y
  let dotClamp := if dot < .negOne then .negOne else dot
  let dotClamp := if dotClamp > .one then .one else dotClamp
  dotClamp.acos

/-- Scale vector (multiply by value) -/
def scale (v : Vector2) (scale : Float32) : Vector2 := Vector2.mk (v.x * scale) (v.y * scale)

/-- Multiply vector by vector -/
def mul (v1 v2 : Vector2) : Vector2 := Vector2.mk (v1.x * v2.x) (v1.y * v2.y)

/-- Negate vector -/
def neg (v : Vector2) : Vector2 := Vector2.mk (- v.x) (- v.y)

/-- Divide vector by vector -/
def div (v1 v2 : Vector2) : Vector2 := Vector2.mk (v1.x / v2.x) (v1.y / v2.y)

/-- Normalize provided vector -/
def normalize (v : Vector2) : Vector2 :=
  let length := (v.x * v.x + v.y * v.y).sqrt
  if length > .zero
    then
      let ilength := .one / length
      Vector2.mk (v.x * ilength) (v.y * ilength)
    else Vector2.zero

/-- Transforms a Vector2 by a given Matrix -/
def transform (v : Vector2) (mat : Matrix) : Vector2 := Vector2.mk
  (mat.m0 * v.x + mat.m4 * v.y + mat.m8 * .zero + mat.m12)
  (mat.m1 * v.x + mat.m5 * v.y + mat.m9 * .zero + mat.m13)

/-- Calculate linear interpolation between two vectors -/
def lerp (v1 v2 : Vector2) (amount : Float32) : Vector2 :=
  Vector2.mk (v1.x + amount * (v2.x - v1.x)) (v1.y + amount * (v2.y - v1.y))

/-- Calculate reflected vector to normal -/
def reflect (v normal : Vector2) : Vector2 :=
  let dot := (v.x * normal.x + v.y * normal.y)
  Vector2.mk (v.x - .two * normal.x * dot) (v.y - .two * normal.y * dot)

/-- Rotate vector by angle -/
def rotate (v : Vector2) (angle : Float32) : Vector2 :=
  let cosres := angle.cos
  let sinres := angle.sin
  Vector2.mk (v.x * cosres - v.y * sinres) (v.x * sinres + v.y * cosres)

/-- Move Vector towards target -/
def moveTowards (v target : Vector2) (maxDistance : Float32) : Vector2 :=
  let dx := target.x - v.x
  let dy := target.y - v.y
  let value := dx * dx + dy * dy
  if value == .zero || (maxDistance >= 0 && value <= maxDistance * maxDistance)
    then target
    else
      let dist := value.sqrt
      Vector2.mk (v.x + dx / dist * maxDistance) (v.y + dy / dist * maxDistance)

/-- Invert the given vector -/
def invert (v : Vector2) : Vector2 := Vector2.mk (.one / v.x) (.one / v.y)

/--
Clamp the components of the vector between
min and max values specified by the given vectors
-/
def clamp (v min max : Vector2) : Vector2 :=
  Vector2.mk (max.x.min $ min.x.max v.x) (max.y.min $ min.y.max v.y)

/-- Clamp the magnitude of the vector between two min and max values -/
def clampValue (v : Vector2) (min max : Float32) : Vector2 :=
  let length := v.x * v.x + v.y * v.y
  if length > .zero
    then
      let length := length.sqrt
      if length < min
        then
          let scale := min / length
          Vector2.mk (v.x * scale) (v.y * scale)
        else if length > max
          then
            let scale := max / length
            Vector2.mk (v.x * scale) (v.y * scale)
          else v
    else v

/-- Check whether two given vectors are almost equal -/
def equals (p q : Vector2) : Bool :=
  (p.x - q.x).abs <= Raymath.epsilon * Float32.one.max (p.x.abs.max q.x.abs) &&
  (p.y - q.y).abs <= Raymath.epsilon * Float32.one.max (p.y.abs.max q.y.abs)

end Vector2
