import Pod.Float32

open Pod (Float32)

set_option autoImplicit false


namespace Raymath

/-! # Constants -/

def pi : Float32 := 3.141592653589793
def epsilon : Float32 := 0.000001
def deg2Rad : Float32 := pi / 180
def rad2Deg : Float32 := 180 / pi

/-! # Util -/

theorem usize_size_ge_2_pow_32 : USize.size ≥ 2 ^ 32 :=
  match usize_size_eq with
    | Or.inl p => Nat.le_of_eq p.symm
    | Or.inr p => Nat.le_of_lt $ Nat.lt_of_lt_of_eq (by decide) p.symm

theorem mod_usize_size_refl (i : Nat) (h : i < 2^32) : i % USize.size = i :=
  Nat.mod_eq_of_lt (Nat.lt_of_lt_of_le h usize_size_ge_2_pow_32)

def toUSizeInj {m} (n : Nat) (h₁ : n < m) (h₂ : m ≤ 2 ^ 32 := by decide) : USize :=
  ⟨n, Nat.lt_of_lt_of_le h₁ $ Nat.le_trans h₂ usize_size_ge_2_pow_32⟩

theorem toUSizeInj_lt {m} (n : Nat) (h₁ : n < m) (h₂ : m < 2 ^ 32 := by decide) :
  toUSizeInj n h₁ (Nat.le_of_lt h₂) < m.toUSize :=
  (Nat.lt_of_lt_of_eq h₁ $ Eq.symm $ mod_usize_size_refl m h₂)

/-! # Types and Structures Definition -/

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


namespace Raymath

/-! ## Vector2 math -/

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

@[extern "lean_raymath_Vector_uget"]
def uget (v : @& Vector2) (i : USize) (h : i < 2) : Float32 := ite (i = 0) v.x v.y

def get (v : @& Vector2) (i : Fin 2) : Float32 :=
  v.uget (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt)

@[extern "lean_raymath_Vector2_uset"]
def uset (v : Vector2) (i : USize) (h : i < 2) (value : Float32) : Vector2 :=
  ite (i = 0) { v with x := value } { v with y := value }

def set (v : Vector2) (i : Fin 2) (value : Float32) : Vector2 :=
  v.uset (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt) value

end Vector2

instance : Add Vector2 := ⟨Vector2.add⟩
instance : Sub Vector2 := ⟨Vector2.sub⟩
instance : Mul Vector2 := ⟨Vector2.mul⟩
instance : Div Vector2 := ⟨Vector2.div⟩
instance : BEq Vector2 := ⟨Vector2.beq⟩
instance : Neg Vector2 := ⟨Vector2.neg⟩
instance : Min Vector2 := ⟨Vector2.min⟩
instance : Max Vector2 := ⟨Vector2.max⟩
instance : GetElem Vector2 USize Float32 (λ _ i ↦ i < 2) := ⟨Vector2.uget⟩
instance : GetElem Vector2 Nat Float32 (λ _ i ↦ i < 2) where
  getElem v i h := v.get $ .mk i h


/-! ## Vector3 math -/

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

@[extern "lean_raymath_Vector_uget"]
def uget (v : @& Vector3) (i : USize) («i<3uz» : i < 3) : Float32 :=
  let «↑i<3» := Nat.lt_of_lt_of_eq «i<3uz» $ mod_usize_size_refl 3 (by decide)
  match i, «↑i<3» with
    | ⟨0, _⟩, _ => v.x
    | ⟨1, _⟩, _ => v.y
    | ⟨2, _⟩, _ => v.z
    | ⟨n+3, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 3 n

def get (v : @& Vector3) (i : Fin 3) : Float32 :=
  v.uget (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt)

@[extern "lean_raymath_Vector3_uset"]
def uset (v : Vector3) (i : USize) («i<3uz» : i < 3) (value : Float32) : Vector3 :=
  let «↑i<3» := Nat.lt_of_lt_of_eq «i<3uz» $ mod_usize_size_refl 3 (by decide)
  match i, «↑i<3» with
    | ⟨0, _⟩, _ => { v with x := value }
    | ⟨1, _⟩, _ => { v with y := value }
    | ⟨2, _⟩, _ => { v with z := value }
    | ⟨n+3, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 3 n

def set (v : Vector3) (i : Fin 3) (value : Float32) : Vector3 :=
  v.uset (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt) value

end Vector3

instance : Add Vector3 := ⟨Vector3.add⟩
instance : Sub Vector3 := ⟨Vector3.sub⟩
instance : Mul Vector3 := ⟨Vector3.mul⟩
instance : Div Vector3 := ⟨Vector3.div⟩
instance : BEq Vector3 := ⟨Vector3.beq⟩
instance : Neg Vector3 := ⟨Vector3.neg⟩
instance : Min Vector3 := ⟨Vector3.min⟩
instance : Max Vector3 := ⟨Vector3.max⟩
instance : GetElem Vector3 USize Float32 (λ _ i ↦ i < 3) := ⟨Vector3.uget⟩
instance : GetElem Vector3 Nat Float32 (λ _ i ↦ i < 3) where
  getElem v i h := v.get $ .mk i h


namespace Vector4

@[extern "lean_raymath_Vector_uget"]
def uget (v : @& Vector4) (i : USize) («i<4uz» : i < 4) : Float32 :=
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ mod_usize_size_refl 4 (by decide)
  match i, «↑i<4» with
    | ⟨0, _⟩, _ => v.x
    | ⟨1, _⟩, _ => v.y
    | ⟨2, _⟩, _ => v.z
    | ⟨3, _⟩, _ => v.w
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def get (v : @& Vector4) (i : Fin 4) : Float32 :=
  v.uget (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt)

@[extern "lean_raymath_Vector4_uset"]
def uset (v : Vector4) (i : USize) («i<4uz» : i < 4) (value : Float32) : Vector4 :=
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ mod_usize_size_refl 4 (by decide)
  match i, «↑i<4» with
    | ⟨0, _⟩, _ => { v with x := value }
    | ⟨1, _⟩, _ => { v with y := value }
    | ⟨2, _⟩, _ => { v with z := value }
    | ⟨3, _⟩, _ => { v with w := value }
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def set (v : Vector4) (i : Fin 4) (value : Float32) : Vector4 :=
  v.uset (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt) value

end Vector4

instance : GetElem Vector4 USize Float32 (λ _ i ↦ i < 4) := ⟨Vector4.uget⟩
instance : GetElem Vector4 Nat Float32 (λ _ i ↦ i < 4) where
  getElem v i h := v.get $ .mk i h


namespace Matrix

@[extern "lean_raymath_Matrix_urow"]
def urow (m : @& Matrix) (i : USize) («i<4uz» : i < 4) : Vector4 :=
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ mod_usize_size_refl 4 (by decide)
  match i, «↑i<4» with
    | ⟨0, _⟩, _ => .mk m.m0 m.m4 m.m8 m.m12
    | ⟨1, _⟩, _ => .mk m.m1 m.m5 m.m9 m.m13
    | ⟨2, _⟩, _ => .mk m.m2 m.m6 m.m10 m.m14
    | ⟨3, _⟩, _ => .mk m.m3 m.m7 m.m11 m.m15
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def row (m : @& Matrix) (i : Nat) (h : i < 4) : Vector4 :=
  m.urow (toUSizeInj i h) (toUSizeInj_lt i h)

@[extern "lean_raymath_Matrix_ucolumn"]
def ucolumn (m : @& Matrix) (i : USize) («i<4uz» : i < 4) : Vector4 :=
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ mod_usize_size_refl 4 (by decide)
  match i, «↑i<4» with
    | ⟨0, _⟩, _ => .mk m.m0 m.m1 m.m2 m.m3
    | ⟨1, _⟩, _ => .mk m.m4 m.m5 m.m6 m.m7
    | ⟨2, _⟩, _ => .mk m.m8 m.m9 m.m10 m.m11
    | ⟨3, _⟩, _ => .mk m.m12 m.m13 m.m14 m.m15
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def column (m : @& Matrix) (i : Nat) (h : i < 4) : Vector4 :=
  m.ucolumn (toUSizeInj i h) (toUSizeInj_lt i h)

@[extern "lean_raymath_Matrix_uget"]
def uget (m : @& Matrix) (i : USize) (j : USize) (h₁ : i < 4) (h₂ : j < 4) : Float32 :=
  (m.urow i h₁).uget j h₂

def get (m : @& Matrix) (i : Fin 4) (j : Fin 4) : Float32 := m.uget
  (toUSizeInj i.val i.isLt) (toUSizeInj j.val j.isLt)
  (toUSizeInj_lt i.val i.isLt) (toUSizeInj_lt j.val j.isLt)

@[extern "lean_raymath_Matrix_usetRow"]
def usetRow (m : Matrix) (i : USize) («i<4uz» : i < 4) (value : @& Vector4) : Matrix :=
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ mod_usize_size_refl 4 (by decide)
  match i, «↑i<4» with
    | ⟨0, _⟩, _ => { m with m0 := value.x, m4 := value.y, m8 := value.z, m12 := value.w }
    | ⟨1, _⟩, _ => { m with m1 := value.x, m5 := value.y, m9 := value.z, m13 := value.w }
    | ⟨2, _⟩, _ => { m with m2 := value.x, m6 := value.y, m10 := value.z, m14 := value.w }
    | ⟨3, _⟩, _ => { m with m3 := value.x, m7 := value.y, m11 := value.z, m15 := value.w }
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def setRow (m : Matrix) (i : Fin 4) (value : @& Vector4) : Matrix :=
  m.usetRow (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt) value

@[extern "lean_raymath_Matrix_usetColumn"]
def usetColumn (m : Matrix) (i : USize) («i<4uz» : i < 4) (value : @& Vector4) : Matrix :=
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ mod_usize_size_refl 4 (by decide)
  match i, «↑i<4» with
    | ⟨0, _⟩, _ => { m with m0 := value.x, m1 := value.y, m2 := value.z, m3 := value.w }
    | ⟨1, _⟩, _ => { m with m4 := value.x, m5 := value.y, m6 := value.z, m7 := value.w }
    | ⟨2, _⟩, _ => { m with m8 := value.x, m9 := value.y, m10 := value.z, m11 := value.w }
    | ⟨3, _⟩, _ => { m with m12 := value.x, m13 := value.y, m14 := value.z, m15 := value.w }
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def setColumn (m : Matrix) (i : Fin 4) (value : @& Vector4) : Matrix :=
  m.usetColumn (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt) value

@[extern "lean_raymath_Matrix_uset"]
def uset (m : Matrix) (i : USize) (j : USize) (h₁ : i < 4) (h₂ : j < 4) (value : Float32) : Matrix :=
  let row := m.urow i h₁
  m.usetRow i h₁ (row.uset j h₂ value)

def set (m : Matrix) (i : Fin 4) (j : Fin 4) (value : Float32) : Matrix := m.uset
  (toUSizeInj i.val i.isLt) (toUSizeInj j.val j.isLt)
  (toUSizeInj_lt i.val i.isLt) (toUSizeInj_lt j.val j.isLt)
  value

end Matrix

instance : GetElem Matrix USize Vector4 (λ _ i ↦ i < 4) := ⟨Matrix.urow⟩
instance : GetElem Matrix Nat Vector4 (λ _ i ↦ i < 4) := ⟨Matrix.row⟩
