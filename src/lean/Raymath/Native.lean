import Pod.Float
import Raymath.Core

open Pod (Float32)

namespace Raymath.Native

abbrev Vector2 : Type := Raymath.Vector2
abbrev Vector3 : Type := Raymath.Vector3
abbrev Vector4 : Type := Raymath.Vector4
abbrev Matrix : Type := Raymath.Matrix
abbrev Quaternion : Type := Raymath.Quaternion

namespace Vector2

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
  (p.x - q.x).abs <= epsilon * Float32.one.max (p.x.abs.max q.x.abs) &&
  (p.y - q.y).abs <= epsilon * Float32.one.max (p.y.abs.max q.y.abs)


def beq (v1 v2 : Vector2) : Bool :=
  v1.x == v2.x && v1.y == v2.y

end Vector2


namespace Vector3

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
  (p.x - q.x).abs <= epsilon * Float32.one.max (p.x.abs.max q.x.abs) &&
  (p.y - q.y).abs <= epsilon * Float32.one.max (p.y.abs.max q.y.abs) &&
  (p.z - q.z).abs <= epsilon * Float32.one.max (p.z.abs.max q.z.abs)

def beq (v1 v2 : Vector3) : Bool :=
  v1.x == v2.x && v1.y == v2.y && v1.z == v2.z

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

end Vector3


namespace Vector4

/-- Vector with components value 0.0 -/
def zero : Vector4 := Vector4.mk Float32.zero Float32.zero Float32.zero Float32.zero

/-- Vector with components value 1.0 -/
def one : Vector4 := Vector4.mk Float32.one Float32.one Float32.one Float32.one

/-- Add two vectors -/
def add (v1 v2 : Vector4) : Vector4 := Vector4.mk (v1.x + v2.x) (v1.y + v2.y) (v1.z + v2.z) (v1.w + v2.w)

/-- Add vector and float value -/
def addValue (v : Vector4) (add : Float32) : Vector4 := Vector4.mk (v.x + add) (v.y + add) (v.z + add) (v.w + add)

/-- Subtract two vectors -/
def sub (v1 v2 : Vector4) : Vector4 := Vector4.mk (v1.x - v2.x) (v1.y - v2.y) (v1.z - v2.z) (v1.w - v2.w)

/-- Subtract vector by float value -/
def subValue (v : Vector4) (sub : Float32) : Vector4 := Vector4.mk (v.x - sub) (v.y - sub) (v.z - sub) (v.w - sub)

/-- Multiply vector by scalar -/
def scale (v : Vector4) (scalar : Float32) : Vector4 := Vector4.mk (v.x * scalar) (v.y * scalar) (v.z * scalar) (v.w * scalar)

/-- Multiply vector by vector -/
def mul (v1 v2 : Vector4) : Vector4 := Vector4.mk (v1.x * v2.x) (v1.y * v2.y) (v1.z * v2.z) (v1.w * v2.w)

/-- Calculate vector length -/
def length (v : Vector4) : Float32 := (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w).sqrt

/-- Calculate vector square length -/
def lengthSqr (v : Vector4) : Float32 := v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w

/-- Calculate two vectors dot product -/
def dot (v1 v2 : Vector4) : Float32 := v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w

/-- Calculate distance between two vectors -/
def distance (v1 v2 : Vector4) : Float32 :=
  let dx := v2.x - v1.x
  let dy := v2.y - v1.y
  let dz := v2.z - v1.z
  let dw := v2.w - v1.w
  (dx * dx + dy * dy + dz * dz + dw * dw).sqrt

/-- Calculate square distance between two vectors -/
def distanceSqr (v1 v2 : Vector4) : Float32 :=
  let dx := v2.x - v1.x
  let dy := v2.y - v1.y
  let dz := v2.z - v1.z
  let dw := v2.w - v1.w
  dx * dx + dy * dy + dz * dz + dw * dw

/-- Negate provided vector (invert direction) -/
def neg (v : Vector4) : Vector4 := Vector4.mk v.x.neg v.y.neg v.z.neg v.w.neg

/-- Divide vector by vector -/
def div (v1 v2 : Vector4) : Vector4 := Vector4.mk (v1.x / v2.x) (v1.y / v2.y) (v1.z / v2.z) (v1.w / v2.w)

/-- Normalize provided vector -/
def normalize (v : Vector4) : Vector4 :=
  let length := Vector4.length v
  if length > .zero then Vector4.scale v (1 / length) else Vector4.zero

/-- Multiply a `Vector4` by a given `Matrix` -/
def mulMatrix (v : Vector4) (m : Matrix) : Vector4 := Vector4.mk
  (m.m0 * v.x + m.m1 * v.y + m.m2 * v.z + m.m3 * v.w)
  (m.m4 * v.x + m.m5 * v.y + m.m6 * v.z + m.m7 * v.w)
  (m.m8 * v.x + m.m9 * v.y + m.m10 * v.z + m.m11 * v.w)
  (m.m12 * v.x + m.m13 * v.y + m.m14 * v.z + m.m15 * v.w)

/-- Calculate linear interpolation between two vectors -/
def lerp (v1 v2 : Vector4) (amount : Float32) : Vector4 := Vector4.mk
  (v1.x + amount * (v2.x - v1.x))
  (v1.y + amount * (v2.y - v1.y))
  (v1.z + amount * (v2.z - v1.z))
  (v1.w + amount * (v2.w - v1.w))

/-- Get min value for each pair of components -/
def min (v1 v2 : Vector4) : Vector4 :=
  Vector4.mk (v1.x.min v2.x) (v1.y.min v2.y) (v1.z.min v2.z) (v1.w.min v2.w)

/-- Get max value for each pair of components -/
def max (v1 v2 : Vector4) : Vector4 :=
  Vector4.mk (v1.x.max v2.x) (v1.y.max v2.y) (v1.z.max v2.z) (v1.w.max v2.w)

/-- Invert the given vector -/
def invert (v : Vector4) : Vector4 :=
  Vector4.mk (.one / v.x) (.one / v.y) (.one / v.z) (.one / v.w)

/--
Clamp the components of the vector between
min and max values specified by the given vectors
-/
def clamp (v min max : Vector4) : Vector4 := Vector4.mk
  (max.x.min $ min.x.max v.x)
  (max.y.min $ min.y.max v.y)
  (max.z.min $ min.z.max v.z)
  (max.w.min $ min.w.max v.w)

/-- Clamp the magnitude of the vector between two and values -/
def clampValue (v : Vector4) (min max : Float32) : Vector4 :=
  let lengthSqr := Vector4.lengthSqr v
  if lengthSqr > .zero
    then
      let length := lengthSqr.sqrt
      if length < min
        then
          Vector4.scale v (min / length)
        else if length > max
          then
            Vector4.scale v (max / length)
          else v
    else v

/-- Check whether two given vectors are almost equal -/
def equals (p q : Vector4) : Bool :=
  (p.x - q.x).abs <= epsilon * Float32.one.max (p.x.abs.max q.x.abs) &&
  (p.y - q.y).abs <= epsilon * Float32.one.max (p.y.abs.max q.y.abs) &&
  (p.z - q.z).abs <= epsilon * Float32.one.max (p.z.abs.max q.z.abs) &&
  (p.w - q.w).abs <= epsilon * Float32.one.max (p.w.abs.max q.w.abs)

def beq (v1 v2 : Vector4) : Bool :=
  v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w

end Vector4


namespace Matrix

/-- Compute matrix determinant -/
def determinant (mat : Matrix) : Float32 :=
  let (Matrix.mk
    a00 a10 a20 a30
    a01 a11 a21 a31
    a02 a12 a22 a32
    a03 a13 a23 a33) := mat
  a30 * a21 * a12 * a03 - a20 * a31 * a12 * a03 - a30 * a11 * a22 * a03 + a10 * a31 * a22 * a03 +
    a20 * a11 * a32 * a03 - a10 * a21 * a32 * a03 - a30 * a21 * a02 * a13 + a20 * a31 * a02 * a13 +
    a30 * a01 * a22 * a13 - a00 * a31 * a22 * a13 - a20 * a01 * a32 * a13 + a00 * a21 * a32 * a13 +
    a30 * a11 * a02 * a23 - a10 * a31 * a02 * a23 - a30 * a01 * a12 * a23 + a00 * a31 * a12 * a23 +
    a10 * a01 * a32 * a23 - a00 * a11 * a32 * a23 - a20 * a11 * a02 * a33 + a10 * a21 * a02 * a33 +
    a20 * a01 * a12 * a33 - a00 * a21 * a12 * a33 - a10 * a01 * a22 * a33 + a00 * a11 * a22 * a33

/-- Get the trace of the matrix (sum of the values along the diagonal) -/
def trace (mat : Matrix) : Float32 := mat.m0 + mat.m5 + mat.m10 + mat.m15

/-- Transposes provided matrix -/
def transpose (mat : Matrix) : Matrix := Matrix.mk
  mat.m0  mat.m1  mat.m2  mat.m3
  mat.m4  mat.m5  mat.m6  mat.m7
  mat.m8  mat.m9  mat.m10 mat.m11
  mat.m12 mat.m13 mat.m14 mat.m15

/-- Invert provided matrix -/
def invert (mat : Matrix) : Matrix :=
  let (Matrix.mk
    a00 a10 a20 a30
    a01 a11 a21 a31
    a02 a12 a22 a32
    a03 a13 a23 a33) := mat
  let b00 := a00 * a11 - a01 * a10
  let b01 := a00 * a12 - a02 * a10
  let b02 := a00 * a13 - a03 * a10
  let b03 := a01 * a12 - a02 * a11
  let b04 := a01 * a13 - a03 * a11
  let b05 := a02 * a13 - a03 * a12
  let b06 := a20 * a31 - a21 * a30
  let b07 := a20 * a32 - a22 * a30
  let b08 := a20 * a33 - a23 * a30
  let b09 := a21 * a32 - a22 * a31
  let b10 := a21 * a33 - a23 * a31
  let b11 := a22 * a33 - a23 * a32
  let invDet := 1 / (b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06)
  let m0 := (a11 * b11 - a12 * b10 + a13 * b09) * invDet
  let m1 := (-a01 * b11 + a02 * b10 - a03 * b09) * invDet
  let m2 := (a31 * b05 - a32 * b04 + a33 * b03) * invDet
  let m3 := (-a21 * b05 + a22 * b04 - a23 * b03) * invDet
  let m4 := (-a10 * b11 + a12 * b08 - a13 * b07) * invDet
  let m5 := (a00 * b11 - a02 * b08 + a03 * b07) * invDet
  let m6 := (-a30 * b05 + a32 * b02 - a33 * b01) * invDet
  let m7 := (a20 * b05 - a22 * b02 + a23 * b01) * invDet
  let m8 := (a10 * b10 - a11 * b08 + a13 * b06) * invDet
  let m9 := (-a00 * b10 + a01 * b08 - a03 * b06) * invDet
  let m10 := (a30 * b04 - a31 * b02 + a33 * b00) * invDet
  let m11 := (-a20 * b04 + a21 * b02 - a23 * b00) * invDet
  let m12 := (-a10 * b09 + a11 * b07 - a12 * b06) * invDet
  let m13 := (a00 * b09 - a01 * b07 + a02 * b06) * invDet
  let m14 := (-a30 * b03 + a31 * b01 - a32 * b00) * invDet
  let m15 := (a20 * b03 - a21 * b01 + a22 * b00) * invDet
  Matrix.mk
    m0 m4 m8  m12
    m1 m5 m9  m13
    m2 m6 m10 m14
    m3 m7 m11 m15

/-- Get identity matrix -/
def identity : Matrix := Matrix.mk
  1 0 0 0
  0 1 0 0
  0 0 1 0
  0 0 0 1

/-- Add two matrices -/
def add (left right : Matrix) : Matrix := Matrix.mk
  (left.m0.add right.m0) (left.m4.add right.m4) (left.m8.add right.m8) (left.m12.add right.m12)
  (left.m1.add right.m1) (left.m5.add right.m5) (left.m9.add right.m9) (left.m13.add right.m13)
  (left.m2.add right.m2) (left.m6.add right.m6) (left.m10.add right.m10) (left.m14.add right.m14)
  (left.m3.add right.m3) (left.m7.add right.m7) (left.m11.add right.m11) (left.m15.add right.m15)

/-- Subtract two matrices (left - right) -/
def sub (left right : Matrix) : Matrix := Matrix.mk
  (left.m0.sub right.m0) (left.m4.sub right.m4) (left.m8.sub right.m8) (left.m12.sub right.m12)
  (left.m1.sub right.m1) (left.m5.sub right.m5) (left.m9.sub right.m9) (left.m13.sub right.m13)
  (left.m2.sub right.m2) (left.m6.sub right.m6) (left.m10.sub right.m10) (left.m14.sub right.m14)
  (left.m3.sub right.m3) (left.m7.sub right.m7) (left.m11.sub right.m11) (left.m15.sub right.m15)


/--
Get two matrix multiplication.
NOTE: When multiplying matrices... the order matters!
-/
def mul (left right : Matrix) : Matrix := Matrix.mk
  (left.m0 * right.m0 + left.m1 * right.m4 + left.m2 * right.m8 + left.m3 * right.m12)
  (left.m4 * right.m0 + left.m5 * right.m4 + left.m6 * right.m8 + left.m7 * right.m12)
  (left.m8 * right.m0 + left.m9 * right.m4 + left.m10 * right.m8 + left.m11 * right.m12)
  (left.m12 * right.m0 + left.m13 * right.m4 + left.m14 * right.m8 + left.m15 * right.m12)
  (left.m0 * right.m1 + left.m1 * right.m5 + left.m2 * right.m9 + left.m3 * right.m13)
  (left.m4 * right.m1 + left.m5 * right.m5 + left.m6 * right.m9 + left.m7 * right.m13)
  (left.m8 * right.m1 + left.m9 * right.m5 + left.m10 * right.m9 + left.m11 * right.m13)
  (left.m12 * right.m1 + left.m13 * right.m5 + left.m14 * right.m9 + left.m15 * right.m13)
  (left.m0 * right.m2 + left.m1 * right.m6 + left.m2 * right.m10 + left.m3 * right.m14)
  (left.m4 * right.m2 + left.m5 * right.m6 + left.m6 * right.m10 + left.m7 * right.m14)
  (left.m8 * right.m2 + left.m9 * right.m6 + left.m10 * right.m10 + left.m11 * right.m14)
  (left.m12 * right.m2 + left.m13 * right.m6 + left.m14 * right.m10 + left.m15 * right.m14)
  (left.m0 * right.m3 + left.m1 * right.m7 + left.m2 * right.m11 + left.m3 * right.m15)
  (left.m4 * right.m3 + left.m5 * right.m7 + left.m6 * right.m11 + left.m7 * right.m15)
  (left.m8 * right.m3 + left.m9 * right.m7 + left.m10 * right.m11 + left.m11 * right.m15)
  (left.m12 * right.m3 + left.m13 * right.m7 + left.m14 * right.m11 + left.m15 * right.m15)


/-- Multiply a `Matrix` by a given `Vector4` -/
def mulVector (m : Matrix) (v : Vector4) : Vector4 := Vector4.mk
  (m.m0 * v.x + m.m4 * v.y + m.m8 * v.z + m.m12 * v.w)
  (m.m1 * v.x + m.m5 * v.y + m.m9 * v.z + m.m13 * v.w)
  (m.m2 * v.x + m.m6 * v.y + m.m10 * v.z + m.m14 * v.w)
  (m.m3 * v.x + m.m7 * v.y + m.m11 * v.z + m.m15 * v.w)

/-- Get translation matrix -/
def translate (x y z : Float32) : Matrix := Matrix.mk
  1 0 0 x
  0 1 0 y
  0 0 1 z
  0 0 0 1

/-- Get translation matrix -/
def translateV (v : Vector3) : Matrix := Matrix.translate v.x v.y v.z

/--
Create rotation matrix from axis and angle
NOTE: Angle should be provided in radians
-/
def rotate (axis : Vector3) (angle : Float32) : Matrix :=
  let (Vector3.mk x y z) := Vector3.normalize axis
  let sinres := angle.sin
  let cosres := angle.cos
  let t := 1 - cosres
  Matrix.mk
    (x * x * t + cosres) (x * y * t - z * sinres) (x * z * t + y * sinres) 0
    (y * x * t + z * sinres) (y * y * t + cosres) (y * z * t - x * sinres) 0
    (z * x * t - y * sinres) (z * y * t + x * sinres) (z * z * t + cosres) 0
    0 0 0 1

/--
Get x-rotation matrix
NOTE: Angle must be provided in radians
-/
def rotateX (angle : Float32) : Matrix :=
  let cosres := angle.cos
  let sinres := angle.sin
  { Matrix.identity with
    m5 := cosres
    m6 := sinres
    m9 := -sinres
    m10 := cosres
  }

/--
Get y-rotation matrix
NOTE: Angle must be provided in radians
-/
def rotateY (angle : Float32) : Matrix :=
  let cosres := angle.cos
  let sinres := angle.sin
  { Matrix.identity with
    m0 := cosres
    m2 := -sinres
    m8 := sinres
    m10 := cosres
  }

/--
Get z-rotation matrix
NOTE: Angle must be provided in radians
-/
def rotateZ (angle : Float32) : Matrix :=
  let cosres := angle.cos
  let sinres := angle.sin
  { Matrix.identity with
    m0 := cosres
    m1 := sinres
    m4 := -sinres
    m5 := cosres
  }

/--
Get xyz-rotation matrix
NOTE: Angle must be provided in radians
-/
def rotateXYZ (angle : Vector3) : Matrix :=
  let cosz := angle.z.neg.cos
  let sinz := angle.z.neg.sin
  let cosy := angle.y.neg.cos
  let siny := angle.y.neg.sin
  let cosx := angle.x.neg.cos
  let sinx := angle.x.neg.sin
  { Matrix.identity with
    m0 := cosz * cosy
    m1 := cosz * siny * sinx - sinz * cosx
    m2 := cosz * siny * cosx + sinz * sinx
    m4 := sinz * cosy
    m5 := sinz * siny * sinx + cosz * cosx
    m6 := sinz * siny * cosx - cosz * sinx
    m8 := siny.neg
    m9 := cosy * sinx
    m10 := cosy * cosx
  }

/--
Get zyx-rotation matrix
NOTE: Angle must be provided in radians
-/
def rotateZYX (angle : Vector3) : Matrix :=
  let cz := angle.z.cos
  let sz := angle.z.sin
  let cy := angle.y.cos
  let sy := angle.y.sin
  let cx := angle.x.cos
  let sx := angle.x.sin
  let m0 := cz * cy
  let m1 := cy * sz
  let m2 := sy.neg
  let m4 := cz * sy * sx - cx * sz
  let m5 := cz * cx + sz * sy * sx
  let m8 := sz * sx + cz * cx * sy
  let m9 := cx * sz * sy - cz * sx
  let m6 := cy * sx
  let m10 := cy * cx
  Matrix.mk
    m0 m4 m8  0
    m1 m5 m9  0
    m2 m6 m10 0
    0  0  0   1

/-- Get scaling matrix -/
def scale (x y z : Float32) : Matrix := Matrix.mk
  x 0 0 0
  0 y 0 0
  0 0 z 0
  0 0 0 1

/-- Get scaling matrix -/
def scaleV (v : Vector3) : Matrix := Matrix.scale v.x v.y v.z

/-- Get perspective projection matrix -/
def frustum (left right bottom top near far : Float) : Matrix :=
  let rl := (right - left).toFloat32
  let tb := (top - bottom).toFloat32
  let fn := (far - near).toFloat32
  let m0 := near.toFloat32 * 2 / rl
  let m5 := near.toFloat32 * 2 / tb
  let m8 := (right.toFloat32 + left.toFloat32) / rl
  let m9 := (top.toFloat32 + bottom.toFloat32) / tb
  let m10 := ((far.toFloat32 + near.toFloat32) / fn).neg
  let m11 := -1
  let m14 := (far.toFloat32 * near.toFloat32 * 2).neg / fn
  Matrix.mk
    m0 0  m8  0
    0  m5 m9  0
    0  0  m10 m14
    0  0  m11 0

/--
Get perspective projection matrix
NOTE: Fovy angle must be provided in radians
-/
def perspective (fovy aspect near far : Float) : Matrix :=
  let top := near * (fovy * 0.5).tan
  let right := top * aspect
  Matrix.frustum (-right) right (-top) top near far

/-- Get orthographic projection matrix -/
def ortho (left right bottom top near far : Float) : Matrix :=
  let rl := (right - left).toFloat32
  let tb := (top - bottom).toFloat32
  let fn := (far - near).toFloat32
  let m0 := 2 / rl
  let m5 := 2 / tb
  let m10 := -2 / fn
  let m12 := -(left.toFloat32 + right.toFloat32)/rl
  let m13 := -(top.toFloat32 + bottom.toFloat32)/tb
  let m14 := -(far.toFloat32 + near.toFloat32)/fn
  Matrix.mk
    m0 0  0   m12
    0  m5 0   m13
    0  0  m10 m14
    0  0  0   1

/-- Get camera look-at matrix (view matrix) -/
def lookAt (eye target up : Vector3) : Matrix :=
  let vz := Vector3.normalize (Vector3.sub eye target)
  let vx := Vector3.normalize (Vector3.cross up vz)
  let vy := Vector3.cross vz vx
  Matrix.mk
    vx.x vx.y vx.z (Vector3.dot vx eye).neg
    vy.x vy.y vy.z (Vector3.dot vy eye).neg
    vz.x vz.y vz.z (Vector3.dot vz eye).neg
    0    0    0    1

/-- Get float array of matrix data (column-major layout: m0, m1, m2 ...) -/
def toArray (mat : Matrix) : Array Float32 :=
  (Array.mkEmpty 16)
    |> flip Array.push mat.m0
    |> flip Array.push mat.m1
    |> flip Array.push mat.m2
    |> flip Array.push mat.m3
    |> flip Array.push mat.m4
    |> flip Array.push mat.m5
    |> flip Array.push mat.m6
    |> flip Array.push mat.m7
    |> flip Array.push mat.m8
    |> flip Array.push mat.m9
    |> flip Array.push mat.m10
    |> flip Array.push mat.m11
    |> flip Array.push mat.m12
    |> flip Array.push mat.m13
    |> flip Array.push mat.m14
    |> flip Array.push mat.m15

end Matrix


namespace Quaternion

/-- Get identity quaternion -/
def identity : Quaternion := Vector4.mk 0 0 0 1

/-- Invert provided quaternion -/
def qinvert (q : Quaternion) : Quaternion :=
  let lengthSq := Vector4.lengthSqr q
  if lengthSq != 0
    then
      let invLength := 1 / lengthSq
      Vector4.mk
        (q.x * -invLength)
        (q.y * -invLength)
        (q.z * -invLength)
        (q.w * invLength)
    else q

/-- Calculate two quaternion multiplication -/
def qmul (q1 q2 : Quaternion) : Quaternion := Vector4.mk
  (q1.x * q2.w + q1.w * q2.x + q1.y * q2.z - q1.z * q2.y)
  (q1.y * q2.w + q1.w * q2.y + q1.z * q2.x - q1.x * q2.z)
  (q1.z * q2.w + q1.w * q2.z + q1.x * q2.y - q1.y * q2.x)
  (q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z)

/-- Calculate slerp-optimized interpolation between two quaternions -/
def nlerp (q1 q2 : Quaternion) (amount : Float32) : Quaternion :=
  Vector4.normalize (Vector4.lerp q1 q2 amount)

/-- Calculates spherical linear interpolation between two quaternions -/
def slerp (q1 q2 : Quaternion) (amount : Float32) : Quaternion :=
  let cosHalfTheta := Vector4.dot q1 q2
  let (q2, cosHalfTheta) := if cosHalfTheta < 0
    then (Vector4.neg q2, -cosHalfTheta)
    else (q2, cosHalfTheta)
  if cosHalfTheta.abs >= 1
    then q1
    else if cosHalfTheta > 0.95
      then nlerp q1 q2 amount
      else
        let halfTheta := cosHalfTheta.acos
        let sinHalfTheta := (1 - cosHalfTheta.sqr).sqrt
        if sinHalfTheta.abs < 0.001
          then Vector4.mk
            (q1.x * 0.5 + q2.x * 0.5)
            (q1.y * 0.5 + q2.y * 0.5)
            (q1.z * 0.5 + q2.z * 0.5)
            (q1.w * 0.5 + q2.w * 0.5)
          else
            let ratioA := ((1 - amount) * halfTheta).sin / sinHalfTheta
            let ratioB := (amount * halfTheta).sin / sinHalfTheta
            Vector4.mk
              (q1.x * ratioA + q2.x * ratioB)
              (q1.y * ratioA + q2.y * ratioB)
              (q1.z * ratioA + q2.z * ratioB)
              (q1.w * ratioA + q2.w * ratioB)

/-- Calculate quaternion based on the rotation from one vector to another -/
def fromVector3ToVector3 («from» to : Vector3) : Quaternion :=
  let cos2Theta := Vector3.dot «from» to
  let cross := Vector3.cross «from» to
  Vector4.normalize (Vector4.mk cross.x cross.y cross.z (1 + cos2Theta))

/-- Get a matrix for a given quaternion -/
def toMatrix (q : Quaternion) : Matrix :=
  let a2 := q.x * q.x
  let b2 := q.y * q.y
  let c2 := q.z * q.z
  let ac := q.x * q.z
  let ab := q.x * q.y
  let bc := q.y * q.z
  let ad := q.w * q.x
  let bd := q.w * q.y
  let cd := q.w * q.z
  let m0 := 1 - 2 * (b2 + c2)
  let m1 := 2 * (ab + cd)
  let m2 := 2 * (ac - bd)
  let m4 := 2 * (ab - cd)
  let m5 := 1 - 2 * (a2 + c2)
  let m6 := 2 * (bc + ad)
  let m8 := 2 * (ac + bd)
  let m9 := 2 * (bc - ad)
  let m10 := 1 - 2 * (a2 + b2)
  Matrix.mk
    m0 m4 m8  0
    m1 m5 m9  0
    m2 m6 m10 0
    0  0  0   1

/--
Get the quaternion equivalent to Euler angles.
NOTE: Rotation order is ZYX.
-/
def fromEuler (pitch yaw roll : Float32) : Quaternion :=
  let x0 := (pitch * 0.5).cos
  let x1 := (pitch * 0.5).sin
  let y0 := (yaw * 0.5).cos
  let y1 := (yaw * 0.5).sin
  let z0 := (roll * 0.5).cos
  let z1 := (roll * 0.5).sin
  Vector4.mk
    (x1 *y0 * z0 - x0 * y1 * z1)
    (x0 *y1 * z0 + x1 * y0 * z1)
    (x0 *y0 * z1 - x1 * y1 * z0)
    (x0 *y0 * z0 + x1 * y1 * z1)

/-- Transform a quaternion given a transformation matrix -/
def transform (q : Quaternion) (mat : Matrix) : Quaternion := Matrix.mulVector mat q

end Quaternion
end Raymath.Native
