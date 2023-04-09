import Pod.Float32

set_option autoImplicit false

/-! # Constants -/

namespace Raymath

def pi : Float32 := 3.141592653589793
def epsilon : Float32 := 0.000001
def deg2Rad : Float32 := pi / 180
def rad2Deg : Float32 := 180 / pi

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

namespace Pod.Float32

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

end Pod.Float32


/-! ## Vector2 math -/

namespace Raymath.Vector2

/-- Vector with components value 0.0 -/
def zero : Vector2 := Vector2.mk Float32.zero Float32.zero

/-- Vector with components value 1.0 -/
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

/-- Transforms a `Vector2` by a given `Matrix` -/
def transform (v : Vector2) (mat : Matrix) : Vector2 := Vector2.mk
  (mat.m0 * v.x + mat.m4 * v.y + mat.m8 * .zero + mat.m12)
  (mat.m1 * v.x + mat.m5 * v.y + mat.m9 * .zero + mat.m13)

/-- Calculate linear interpolation between two vectors -/
def lerp (v1 v2 : Vector2) (amount : Float32) : Vector2 :=
  Vector2.mk (v1.x + amount * (v2.x - v1.x)) (v1.y + amount * (v2.y - v1.y))

/-- Calculate reflected vector to normal -/
def reflect (v normal : Vector2) : Vector2 :=
  let dot := v.x * normal.x + v.y * normal.y
  Vector2.mk (v.x - .two * normal.x * dot) (v.y - .two * normal.y * dot)

/-- Get min value for each pair of components -/
def min (v1 v2 : Vector2) : Vector2 :=
  Vector2.mk (v1.x.min v2.x) (v1.y.min v2.y)

/-- Get max value for each pair of components -/
def max (v1 v2 : Vector2) : Vector2 :=
  Vector2.mk (v1.x.max v2.x) (v1.y.max v2.y)

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


/-! ## Vector3 math -/

namespace Raymath.Vector3

/-- Vector with components value 0.0 -/
def zero : Vector3 := Vector3.mk Float32.zero Float32.zero Float32.zero

/-- Vector with components value 1.0 -/
def one : Vector3 := Vector3.mk Float32.one Float32.one Float32.one

/-- Add two vectors -/
def add (v1 v2 : Vector3) : Vector3 := Vector3.mk (v1.x + v2.x) (v1.y + v2.y) (v1.z + v2.z)

/-- Add vector and float value -/
def addValue (v : Vector3) (add : Float32) : Vector3 := Vector3.mk (v.x + add) (v.y + add) (v.z + add)

/-- Subtract two vectors -/
def sub (v1 v2 : Vector3) : Vector3 := Vector3.mk (v1.x - v2.x) (v1.y - v2.y) (v1.z - v2.z)

/-- Subtract vector by float value -/
def subValue (v : Vector3) (sub : Float32) : Vector3 := Vector3.mk (v.x - sub) (v.y - sub) (v.z - sub)

/-- Multiply vector by scalar -/
def scale (v : Vector3) (scalar : Float32) : Vector3 := Vector3.mk (v.x * scalar) (v.y * scalar) (v.z * scalar)

/-- Multiply vector by vector -/
def mul (v1 v2 : Vector3) : Vector3 := Vector3.mk (v1.x * v2.x) (v1.y * v2.y) (v1.z * v2.z)

/-- Calculate two vectors cross product -/
def cross (v1 v2 : Vector3) : Vector3 := Vector3.mk
  (v1.y * v2.z - v1.z * v2.y)
  (v1.z * v2.x - v1.x * v2.z)
  (v1.x * v2.y - v1.y * v2.x)

/-- Calculate one vector perpendicular vector -/
def perpendicular (v : Vector3) : Vector3 :=
  let min := v.x.toFloat.abs.toFloat32
  let cardinalAxis := Vector3.mk .one .zero .zero
  let (min, cardinalAxis) := if v.y.abs < min
    then (v.y.toFloat.abs.toFloat32, Vector3.mk .zero .one .zero)
    else (min, cardinalAxis)
  let cardinalAxis := if v.z.abs < min
    then Vector3.mk .zero .zero .one
    else cardinalAxis
  Vector3.mk
    (v.y * cardinalAxis.z - v.z * cardinalAxis.y)
    (v.z * cardinalAxis.x - v.x * cardinalAxis.z)
    (v.x * cardinalAxis.y - v.y * cardinalAxis.x)

/-- Calculate vector length -/
def length (v : Vector3) : Float32 := (v.x * v.x + v.y * v.y + v.z * v.z).sqrt

/-- Calculate vector square length -/
def lengthSqr (v : Vector3) : Float32 := v.x * v.x + v.y * v.y + v.z * v.z

/-- Calculate two vectors dot product -/
def dot (v1 v2 : Vector3) : Float32 := v1.x * v2.x + v1.y * v2.y + v1.z * v2.z

/-- Calculate distance between two vectors -/
def distance (v1 v2 : Vector3) : Float32 :=
  let dx := v2.x - v1.x
  let dy := v2.y - v1.y
  let dz := v2.z - v1.z
  (dx * dx + dy * dy + dz * dz).sqrt

/-- Calculate square distance between two vectors -/
def distanceSqr (v1 v2 : Vector3) : Float32 :=
  let dx := v2.x - v1.x
  let dy := v2.y - v1.y
  let dz := v2.z - v1.z
  dx * dx + dy * dy + dz * dz

/-- Calculate angle between two vectors -/
def angle (v1 v2 : Vector3) : Float32 :=
  let cross := Vector3.mk
    (v1.y * v2.z - v1.z * v2.y)
    (v1.z * v2.x - v1.x * v2.z)
    (v1.x * v2.y - v1.y * v2.x)
  let len := (cross.x * cross.x + cross.y * cross.y + cross.z * cross.z).sqrt
  let dot := v1.x * v2.x + v1.y * v2.y + v1.z * v2.z
  Float32.atan2 len dot

/-- Negate provided vector (invert direction) -/
def neg (v : Vector3) : Vector3 := Vector3.mk (- v.x) (- v.y) (- v.z)

/-- Divide vector by vector -/
def div (v1 v2 : Vector3) : Vector3 := Vector3.mk (v1.x / v2.x) (v1.y / v2.y) (v1.z / v2.z)

/-- Normalize provided vector -/
def normalize (v : Vector3) : Vector3 :=
  let length := (v.x * v.x + v.y * v.y + v.z * v.z).sqrt
  if length > .zero
    then
      let ilength := .one / length
      Vector3.mk (v.x * ilength) (v.y * ilength) (v.z * ilength)
    else Vector3.zero

/--
Orthonormalize provided vectors.
Makes vectors normalized and orthogonal to each other.
Gram-Schmidt function implementation.
-/
-- Without manual inlining, unlike og raymath
def orthoNormalize (v1 v2 : Vector3) : Vector3 × Vector3 :=
  let v1 := normalize v1
  let vn1 := normalize $ cross v1 v2
  let vn2 := cross vn1 v1
  (v1, vn2)

/-- Transforms a `Vector3` by a given `Matrix` -/
def transform (v : Vector3) (mat : Matrix) : Vector3 := Vector3.mk
  (mat.m0 * v.x + mat.m4 * v.y + mat.m8 * v.z + mat.m12)
  (mat.m1 * v.x + mat.m5 * v.y + mat.m9 * v.z + mat.m13)
  (mat.m2 * v.x + mat.m6 * v.y + mat.m10 * v.z + mat.m14)

/-- Transform a vector by quaternion rotation -/
def rotateByQuaternion (v : Vector3) (q : Quaternion) : Vector3 := Vector3.mk
  (v.x * (q.x * q.x + q.w * q.w - q.y * q.y - q.z * q.z) +
    v.y * (.two * q.x * q.y - .two * q.w * q.z) +
    v.z * (.two * q.x * q.z + .two * q.w * q.y))
  (v.x * (.two * q.w * q.z + .two * q.x * q.y) +
    v.y * (q.w * q.w - q.x * q.x + q.y * q.y - q.z * q.z) +
    v.z * (.negTwo * q.w * q.x + .two * q.y * q.z))
  (v.x * (.negTwo * q.w * q.y + .two * q.x * q.z) +
    v.y * (.two * q.w * q.x + .two * q.y * q.z) +
    v.z * (q.w * q.w - q.x * q.x - q.y * q.y + q.z * q.z))

/-- Rotates a vector around axis -/
-- Without manual inlining, unlike og raymath
def rotateByAxisAngle (v axis : Vector3) (angle : Float32) : Vector3 :=
  let axis := normalize axis
  let angle := angle / .two
  let a := angle.sin
  let b := axis.x * a
  let c := axis.y * a
  let d := axis.z * a
  let a := angle.cos
  let w := Vector3.mk b c d
  let wv := cross w v
  let wwv := cross w wv
  let wv := scale wv (a * .two)
  let wwv := scale wwv .two
  add (add v wv) wwv

/-- Calculate linear interpolation between two vectors -/
def lerp (v1 v2 : Vector3) (amount : Float32) : Vector3 := Vector3.mk
  (v1.x + amount * (v2.x - v1.x))
  (v1.y + amount * (v2.y - v1.y))
  (v1.z + amount * (v2.z - v1.z))

/-- Calculate reflected vector to normal -/
def reflect (v normal : Vector3) : Vector3 :=
  let dot := v.x * normal.x + v.y * normal.y + v.z * normal.z
  Vector3.mk (v.x - .two * normal.x * dot) (v.y - .two * normal.y * dot) (v.z - .two * normal.z * dot)

/-- Get min value for each pair of components -/
def min (v1 v2 : Vector3) : Vector3 :=
  Vector3.mk (v1.x.min v2.x) (v1.y.min v2.y) (v1.z.min v2.z)

/-- Get max value for each pair of components -/
def max (v1 v2 : Vector3) : Vector3 :=
  Vector3.mk (v1.x.max v2.x) (v1.y.max v2.y) (v1.z.max v2.z)


/--
Compute barycenter coordinates (`u`, `v`, `w`) for point `p` with respect to triangle (`a`, `b`, `c`).
NOTE: Assumes `p` is on the plane of the triangle.
-/
-- Without manual inlining, unlike og raymath
def barycenter (p a b c : Vector3) : Vector3 :=
  let v0 := sub b a
  let v1 := sub c a
  let v2 := sub p a
  let d00 := dot v0 v0
  let d01 := dot v0 v1
  let d11 := dot v1 v1
  let d20 := dot v2 v0
  let d21 := dot v2 v1
  let denom := d00 * d11 - d01 * d01
  let resultY := (d11 * d20 - d01 * d21) / denom
  let resultZ := (d00 * d21 - d01 * d20) / denom
  Vector3.mk
    (.one - (resultZ + resultY))
    resultY
    resultZ

-- todo: unproject

/-- Get `Vector3` as float array -/
def toFloatArray (v : Vector3) : FloatArray :=
  let a := FloatArray.mkEmpty 3
  let a := a.push v.x.toFloat
  let a := a.push v.y.toFloat
  a.push v.z.toFloat

/-- Invert the given vector -/
def invert (v : Vector3) : Vector3 := Vector3.mk (.one / v.x) (.one / v.y) (.one / v.z)

/--
Clamp the components of the vector between
min and max values specified by the given vectors
-/
def clamp (v min max : Vector3) : Vector3 := Vector3.mk
  (max.x.min $ min.x.max v.x)
  (max.y.min $ min.y.max v.y)
  (max.z.min $ min.z.max v.z)

/-- Clamp the magnitude of the vector between two and values -/
def clampValue (v : Vector3) (min max : Float32) : Vector3 :=
  let length := v.x * v.x + v.y * v.y + v.z * v.z
  if length > .zero
    then
      let length := length.sqrt
      if length < min
        then
          let scale := min / length
          Vector3.mk (v.x * scale) (v.y * scale) (v.z * scale)
        else if length > max
          then
            let scale := max / length
            Vector3.mk (v.x * scale) (v.y * scale) (v.z * scale)
          else v
    else v

/-- Check whether two given vectors are almost equal -/
def equals (p q : Vector3) : Bool :=
  (p.x - q.x).abs <= Raymath.epsilon * Float32.one.max (p.x.abs.max q.x.abs) &&
  (p.y - q.y).abs <= Raymath.epsilon * Float32.one.max (p.y.abs.max q.y.abs) &&
  (p.z - q.z).abs <= Raymath.epsilon * Float32.one.max (p.z.abs.max q.z.abs)

/--
Compute the direction of a refracted ray where `v` specifies the
normalized direction of the incoming ray, `n` specifies the
normalized normal vector of the interface of two optical media,
and `r` specifies the ratio of the refractive index of the medium
from where the ray comes to the refractive index of the medium
on the other side of the surface
-/
def refract (v n : Vector3) (r : Float32) : Vector3 :=
  let dot := v.x * n.x + v.y * n.y + v.z * n.z
  let d := .one - r * r * (.one - dot * dot)
  if d >= .zero
    then
      let d := d.sqrt
      Vector3.mk
        (r * v.x - (r * dot + d) * n.x)
        (r * v.y - (r * dot + d) * n.y)
        (r * v.z - (r * dot + d) * n.z)
    else Vector3.zero

end Raymath.Vector3
