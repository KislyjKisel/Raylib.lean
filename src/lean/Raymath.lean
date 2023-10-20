import Raymath.Core
import Raymath.Foreign
import Raymath.Native

open Pod (Float32)

namespace Raymath

def toUSizeInj {m} (n : Nat) (h₁ : n < m) (h₂ : m ≤ 2 ^ 32 := by decide) : USize :=
  ⟨n, Nat.lt_of_lt_of_le h₁ $ Nat.le_trans h₂ Pod.usize_size_ge_2_pow_32⟩

theorem toUSizeInj_lt {m} (n : Nat) (h₁ : n < m) (h₂ : m < 2 ^ 32 := by decide) :
  toUSizeInj n h₁ (Nat.le_of_lt h₂) < m.toUSize :=
  (Nat.lt_of_lt_of_eq h₁ $ Eq.symm $ Pod.mod_usize_size_eq m h₂)

end Raymath

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

namespace Vector2

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


namespace Vector3

@[extern "lean_raymath_Vector_uget"]
def uget (v : @& Vector3) (i : USize) («i<3uz» : i < 3) : Float32 :=
  let «↑i<3» := Nat.lt_of_lt_of_eq «i<3uz» $ Pod.mod_usize_size_eq 3 (by decide)
  match i, «↑i<3» with
    | ⟨0, _⟩, _ => v.x
    | ⟨1, _⟩, _ => v.y
    | ⟨2, _⟩, _ => v.z
    | ⟨n+3, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 3 n

def get (v : @& Vector3) (i : Fin 3) : Float32 :=
  v.uget (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt)

@[extern "lean_raymath_Vector3_uset"]
def uset (v : Vector3) (i : USize) («i<3uz» : i < 3) (value : Float32) : Vector3 :=
  let «↑i<3» := Nat.lt_of_lt_of_eq «i<3uz» $ Pod.mod_usize_size_eq 3 (by decide)
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
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ Pod.mod_usize_size_eq 4 (by decide)
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
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ Pod.mod_usize_size_eq 4 (by decide)
  match i, «↑i<4» with
    | ⟨0, _⟩, _ => { v with x := value }
    | ⟨1, _⟩, _ => { v with y := value }
    | ⟨2, _⟩, _ => { v with z := value }
    | ⟨3, _⟩, _ => { v with w := value }
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def set (v : Vector4) (i : Fin 4) (value : Float32) : Vector4 :=
  v.uset (toUSizeInj i.val i.isLt) (toUSizeInj_lt i.val i.isLt) value

end Vector4

instance : Add Vector4 := ⟨Vector4.add⟩
instance : Sub Vector4 := ⟨Vector4.sub⟩
instance : Mul Vector4 := ⟨Vector4.mul⟩
instance : Div Vector4 := ⟨Vector4.div⟩
instance : BEq Vector4 := ⟨Vector4.beq⟩
instance : Neg Vector4 := ⟨Vector4.neg⟩
instance : Min Vector4 := ⟨Vector4.min⟩
instance : Max Vector4 := ⟨Vector4.max⟩
instance : GetElem Vector4 USize Float32 (λ _ i ↦ i < 4) := ⟨Vector4.uget⟩
instance : GetElem Vector4 Nat Float32 (λ _ i ↦ i < 4) where
  getElem v i h := v.get $ .mk i h


namespace Matrix

@[extern "lean_raymath_Matrix_urow"]
def urow (m : @& Matrix) (i : USize) («i<4uz» : i < 4) : Vector4 :=
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ Pod.mod_usize_size_eq 4 (by decide)
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
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ Pod.mod_usize_size_eq 4 (by decide)
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
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ Pod.mod_usize_size_eq 4 (by decide)
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
  let «↑i<4» := Nat.lt_of_lt_of_eq «i<4uz» $ Pod.mod_usize_size_eq 4 (by decide)
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

instance : Add Matrix := ⟨Matrix.add⟩
instance : Sub Matrix := ⟨Matrix.sub⟩
instance : Mul Matrix := ⟨Matrix.mul⟩
instance : GetElem Matrix USize Vector4 (λ _ i ↦ i < 4) := ⟨Matrix.urow⟩
instance : GetElem Matrix Nat Vector4 (λ _ i ↦ i < 4) := ⟨Matrix.row⟩

end Raymath
