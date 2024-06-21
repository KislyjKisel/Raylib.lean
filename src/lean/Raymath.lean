import Raymath.Core
import Raymath.Foreign
import Raymath.Native

open Pod (Float32)

namespace Raymath

def toUInt32Inj {m} (n : Nat) (h₁ : n < m) (h₂ : m ≤ 2 ^ 32 := by decide) : UInt32 :=
  ⟨n, Nat.lt_of_lt_of_le h₁ $ Nat.le_trans h₂ (Nat.le_refl _)⟩

theorem toUInt32Inj_lt {m} (n : Nat) (h₁ : n < m) (h₂ : m < 2 ^ 32 := by decide) :
  toUInt32Inj n h₁ (Nat.le_of_lt h₂) < m.toUInt32 :=
  (Nat.lt_of_lt_of_eq h₁ $ Eq.symm $ Nat.mod_eq_of_lt h₂)

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
def uget (v : @& Vector2) (i : UInt32) (h : i < 2) : Float32 := ite (i = 0) v.x v.y

def get (v : @& Vector2) (i : Fin 2) : Float32 :=
  v.uget (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt)

@[extern "lean_raymath_Vector2_uset"]
def uset (v : Vector2) (i : UInt32) (h : i < 2) (value : Float32) : Vector2 :=
  ite (i = 0) { v with x := value } { v with y := value }

def set (v : Vector2) (i : Fin 2) (value : Float32) : Vector2 :=
  v.uset (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt) value

end Vector2

instance : Add Vector2 := ⟨Vector2.add⟩
instance : HAdd Float32 Vector2 Vector2 := ⟨λ s v ↦ ⟨s + v.x, s + v.y⟩⟩
instance : HAdd Vector2 Float32 Vector2 := ⟨λ v s ↦ ⟨v.x + s, v.y + s⟩⟩
instance : Sub Vector2 := ⟨Vector2.sub⟩
instance : HSub Float32 Vector2 Vector2 := ⟨λ s v ↦ ⟨s - v.x, s - v.y⟩⟩
instance : HSub Vector2 Float32 Vector2 := ⟨λ v s ↦ ⟨v.x - s, v.y - s⟩⟩
instance : Mul Vector2 := ⟨Vector2.mul⟩
instance : HMul Vector2 Float32 Vector2 := ⟨Vector2.scale⟩
instance : HMul Float32 Vector2 Vector2 := ⟨λ s v ↦ v.scale s⟩
instance : Div Vector2 := ⟨Vector2.div⟩
instance : HDiv Vector2 Float32 Vector2 := ⟨λ v s ↦ v.scale (.one / s)⟩
instance : HDiv Float32 Vector2 Vector2 := ⟨λ s v ↦ ⟨s / v.x, s / v.y⟩⟩
instance : BEq Vector2 := ⟨Vector2.beq⟩
instance : Neg Vector2 := ⟨Vector2.neg⟩
instance : Min Vector2 := ⟨Vector2.min⟩
instance : Max Vector2 := ⟨Vector2.max⟩

instance : GetElem Vector2 UInt32 Float32 (λ _ i ↦ i < 2) where
  getElem := Vector2.uget
  getElem! v i := dite _ (v.uget i) (λ _ ↦ default) -- this line may be removed when lean4#4418 is fixed

instance : GetElem Vector2 Nat Float32 (λ _ i ↦ i < 2) where
  getElem v i h := v.get $ .mk i h

instance : ToString Vector2 where
  toString v := s!"({v.x} {v.y})"


namespace Vector3

@[extern "lean_raymath_Vector_uget"]
def uget (v : @& Vector3) (i : UInt32) («i<3uz» : i < 3) : Float32 :=
  let «↑i<3» := Nat.lt_of_lt_of_eq «i<3uz» rfl
  match i, «↑i<3» with
    | ⟨0, _⟩, _ => v.x
    | ⟨1, _⟩, _ => v.y
    | ⟨2, _⟩, _ => v.z
    | ⟨n+3, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 3 n

def get (v : @& Vector3) (i : Fin 3) : Float32 :=
  v.uget (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt)

@[extern "lean_raymath_Vector3_uset"]
def uset (v : Vector3) (i : UInt32) («i<3» : i < 3) (value : Float32) : Vector3 :=
  match i, «i<3» with
    | ⟨0, _⟩, _ => { v with x := value }
    | ⟨1, _⟩, _ => { v with y := value }
    | ⟨2, _⟩, _ => { v with z := value }
    | ⟨n+3, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 3 n

def set (v : Vector3) (i : Fin 3) (value : Float32) : Vector3 :=
  v.uset (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt) value

end Vector3

instance : Add Vector3 := ⟨Vector3.add⟩
instance : HAdd Float32 Vector3 Vector3 := ⟨λ s v ↦ ⟨s + v.x, s + v.y, s + v.z⟩⟩
instance : HAdd Vector3 Float32 Vector3 := ⟨λ v s ↦ ⟨v.x + s, v.y + s, v.z + s⟩⟩
instance : Sub Vector3 := ⟨Vector3.sub⟩
instance : HSub Float32 Vector3 Vector3 := ⟨λ s v ↦ ⟨s - v.x, s - v.y, s - v.z⟩⟩
instance : HSub Vector3 Float32 Vector3 := ⟨λ v s ↦ ⟨v.x - s, v.y - s, v.z - s⟩⟩
instance : Mul Vector3 := ⟨Vector3.mul⟩
instance : HMul Vector3 Float32 Vector3 := ⟨Vector3.scale⟩
instance : HMul Float32 Vector3 Vector3 := ⟨λ s v ↦ v.scale s⟩
instance : Div Vector3 := ⟨Vector3.div⟩
instance : HDiv Vector3 Float32 Vector3 := ⟨λ v s ↦ v.scale (.one / s)⟩
instance : HDiv Float32 Vector3 Vector3 := ⟨λ s v ↦ ⟨s / v.x, s / v.y, s / v.z⟩⟩
instance : BEq Vector3 := ⟨Vector3.beq⟩
instance : Neg Vector3 := ⟨Vector3.neg⟩
instance : Min Vector3 := ⟨Vector3.min⟩
instance : Max Vector3 := ⟨Vector3.max⟩

instance : GetElem Vector3 UInt32 Float32 (λ _ i ↦ i < 3) where
  getElem := Vector3.uget
  getElem! v i := dite _ (v.uget i) (λ _ ↦ default) -- this line may be removed when lean4#4418 is fixed

instance : GetElem Vector3 Nat Float32 (λ _ i ↦ i < 3) where
  getElem v i h := v.get $ .mk i h

instance : ToString Vector3 where
  toString v := s!"({v.x} {v.y} {v.z})"


namespace Vector4

@[extern "lean_raymath_Vector_uget"]
def uget (v : @& Vector4) (i : UInt32) («i<4» : i < 4) : Float32 :=
  match i, «i<4» with
    | ⟨0, _⟩, _ => v.x
    | ⟨1, _⟩, _ => v.y
    | ⟨2, _⟩, _ => v.z
    | ⟨3, _⟩, _ => v.w
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def get (v : @& Vector4) (i : Fin 4) : Float32 :=
  v.uget (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt)

@[extern "lean_raymath_Vector4_uset"]
def uset (v : Vector4) (i : UInt32) («i<4» : i < 4) (value : Float32) : Vector4 :=
  match i, «i<4» with
    | ⟨0, _⟩, _ => { v with x := value }
    | ⟨1, _⟩, _ => { v with y := value }
    | ⟨2, _⟩, _ => { v with z := value }
    | ⟨3, _⟩, _ => { v with w := value }
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def set (v : Vector4) (i : Fin 4) (value : Float32) : Vector4 :=
  v.uset (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt) value

end Vector4

instance : Add Vector4 := ⟨Vector4.add⟩
instance : HAdd Float32 Vector4 Vector4 := ⟨λ s v ↦ ⟨s + v.x, s + v.y, s + v.z, s + v.w⟩⟩
instance : HAdd Vector4 Float32 Vector4 := ⟨λ v s ↦ ⟨v.x + s, v.y + s, v.z + s, v.w + s⟩⟩
instance : Sub Vector4 := ⟨Vector4.sub⟩
instance : HSub Float32 Vector4 Vector4 := ⟨λ s v ↦ ⟨s - v.x, s - v.y, s - v.z, s - v.w⟩⟩
instance : HSub Vector4 Float32 Vector4 := ⟨λ v s ↦ ⟨v.x - s, v.y - s, v.z - s, v.w - s⟩⟩
instance : Mul Vector4 := ⟨Vector4.mul⟩
instance : HMul Vector4 Float32 Vector4 := ⟨Vector4.scale⟩
instance : HMul Float32 Vector4 Vector4 := ⟨λ s v ↦ v.scale s⟩
instance : Div Vector4 := ⟨Vector4.div⟩
instance : HDiv Vector4 Float32 Vector4 := ⟨λ v s ↦ v.scale (.one / s)⟩
instance : HDiv Float32 Vector4 Vector4 := ⟨λ s v ↦ ⟨s / v.x, s / v.y, s / v.z, s / v.w⟩⟩
instance : BEq Vector4 := ⟨Vector4.beq⟩
instance : Neg Vector4 := ⟨Vector4.neg⟩
instance : Min Vector4 := ⟨Vector4.min⟩
instance : Max Vector4 := ⟨Vector4.max⟩

instance : GetElem Vector4 UInt32 Float32 (λ _ i ↦ i < 4) where
  getElem := Vector4.uget
  getElem! v i := dite _ (v.uget i) (λ _ ↦ default) -- this line may be removed when lean4#4418 is fixed

instance : GetElem Vector4 Nat Float32 (λ _ i ↦ i < 4) where
  getElem v i h := v.get $ .mk i h

instance : ToString Vector4 where
  toString v := s!"({v.x} {v.y} {v.z} {v.w})"


namespace Matrix

@[extern "lean_raymath_Matrix_urow"]
def urow (m : @& Matrix) (i : UInt32) («i<4» : i < 4) : Vector4 :=
  match i, «i<4» with
    | ⟨0, _⟩, _ => .mk m.m0 m.m4 m.m8 m.m12
    | ⟨1, _⟩, _ => .mk m.m1 m.m5 m.m9 m.m13
    | ⟨2, _⟩, _ => .mk m.m2 m.m6 m.m10 m.m14
    | ⟨3, _⟩, _ => .mk m.m3 m.m7 m.m11 m.m15
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def row (m : @& Matrix) (i : Nat) (h : i < 4) : Vector4 :=
  m.urow (toUInt32Inj i h) (toUInt32Inj_lt i h)

@[extern "lean_raymath_Matrix_ucolumn"]
def ucolumn (m : @& Matrix) (i : UInt32) («i<4» : i < 4) : Vector4 :=
  match i, «i<4» with
    | ⟨0, _⟩, _ => .mk m.m0 m.m1 m.m2 m.m3
    | ⟨1, _⟩, _ => .mk m.m4 m.m5 m.m6 m.m7
    | ⟨2, _⟩, _ => .mk m.m8 m.m9 m.m10 m.m11
    | ⟨3, _⟩, _ => .mk m.m12 m.m13 m.m14 m.m15
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def column (m : @& Matrix) (i : Nat) (h : i < 4) : Vector4 :=
  m.ucolumn (toUInt32Inj i h) (toUInt32Inj_lt i h)

@[extern "lean_raymath_Matrix_ugetLinear"]
def ugetLinear (m : @& Matrix) (i : UInt32) (h : i < 16) : Float32 :=
  match i, h with
  | ⟨0, _⟩, _ => m.m0
  | ⟨1, _⟩, _ => m.m4
  | ⟨2, _⟩, _ => m.m8
  | ⟨3, _⟩, _ => m.m12
  | ⟨4, _⟩, _ => m.m1
  | ⟨5, _⟩, _ => m.m5
  | ⟨6, _⟩, _ => m.m9
  | ⟨7, _⟩, _ => m.m13
  | ⟨8, _⟩, _ => m.m2
  | ⟨9, _⟩, _ => m.m6
  | ⟨10, _⟩, _ => m.m0
  | ⟨11, _⟩, _ => m.m14
  | ⟨12, _⟩, _ => m.m3
  | ⟨13, _⟩, _ => m.m7
  | ⟨14, _⟩, _ => m.m11
  | ⟨15, _⟩, _ => m.m15
  | ⟨n+16, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 16 n

def getLinear (m : @& Matrix) (i : Fin 16) : Float32 :=
  m.ugetLinear (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt)

@[extern "lean_raymath_Matrix_uget"]
def uget (m : @& Matrix) (i : UInt32) (j : UInt32) (h₁ : i < 4) (h₂ : j < 4) : Float32 :=
  (m.urow i h₁).uget j h₂

def get (m : @& Matrix) (i : Fin 4) (j : Fin 4) : Float32 := m.uget
  (toUInt32Inj i.val i.isLt) (toUInt32Inj j.val j.isLt)
  (toUInt32Inj_lt i.val i.isLt) (toUInt32Inj_lt j.val j.isLt)

@[extern "lean_raymath_Matrix_usetRow"]
def usetRow (m : Matrix) (i : UInt32) («i<4» : i < 4) (value : @& Vector4) : Matrix :=
  match i, «i<4» with
    | ⟨0, _⟩, _ => { m with m0 := value.x, m4 := value.y, m8 := value.z, m12 := value.w }
    | ⟨1, _⟩, _ => { m with m1 := value.x, m5 := value.y, m9 := value.z, m13 := value.w }
    | ⟨2, _⟩, _ => { m with m2 := value.x, m6 := value.y, m10 := value.z, m14 := value.w }
    | ⟨3, _⟩, _ => { m with m3 := value.x, m7 := value.y, m11 := value.z, m15 := value.w }
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def setRow (m : Matrix) (i : Fin 4) (value : @& Vector4) : Matrix :=
  m.usetRow (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt) value

@[extern "lean_raymath_Matrix_usetColumn"]
def usetColumn (m : Matrix) (i : UInt32) («i<4» : i < 4) (value : @& Vector4) : Matrix :=
  match i, «i<4» with
    | ⟨0, _⟩, _ => { m with m0 := value.x, m1 := value.y, m2 := value.z, m3 := value.w }
    | ⟨1, _⟩, _ => { m with m4 := value.x, m5 := value.y, m6 := value.z, m7 := value.w }
    | ⟨2, _⟩, _ => { m with m8 := value.x, m9 := value.y, m10 := value.z, m11 := value.w }
    | ⟨3, _⟩, _ => { m with m12 := value.x, m13 := value.y, m14 := value.z, m15 := value.w }
    | ⟨n+4, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 4 n

def setColumn (m : Matrix) (i : Fin 4) (value : @& Vector4) : Matrix :=
  m.usetColumn (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt) value

@[extern "lean_raymath_Matrix_usetLinear"]
def usetLinear (m : Matrix) (i : UInt32) (h : i < 16) (value : Float32) : Matrix :=
  match i, h with
  | ⟨0, _⟩, _ => { m with m0 := value }
  | ⟨1, _⟩, _ => { m with m4 := value }
  | ⟨2, _⟩, _ => { m with m8 := value }
  | ⟨3, _⟩, _ => { m with m12 := value }
  | ⟨4, _⟩, _ => { m with m1 := value }
  | ⟨5, _⟩, _ => { m with m5 := value }
  | ⟨6, _⟩, _ => { m with m9 := value }
  | ⟨7, _⟩, _ => { m with m13 := value }
  | ⟨8, _⟩, _ => { m with m2 := value }
  | ⟨9, _⟩, _ => { m with m6 := value }
  | ⟨10, _⟩, _ => { m with m10 := value }
  | ⟨11, _⟩, _ => { m with m14 := value }
  | ⟨12, _⟩, _ => { m with m3 := value }
  | ⟨13, _⟩, _ => { m with m7 := value }
  | ⟨14, _⟩, _ => { m with m11 := value }
  | ⟨15, _⟩, _ => { m with m15 := value }
  | ⟨n+16, _⟩, h₂ => False.elim $ Nat.not_le_of_gt h₂ $ Nat.le_add_left 16 n

def setLinear (m : Matrix) (i : Fin 16) (value : Float32) : Matrix :=
  m.usetLinear (toUInt32Inj i.val i.isLt) (toUInt32Inj_lt i.val i.isLt) value

@[extern "lean_raymath_Matrix_uset"]
def uset (m : Matrix) (i : UInt32) (j : UInt32) (h₁ : i < 4) (h₂ : j < 4) (value : Float32) : Matrix :=
  let row := m.urow i h₁
  m.usetRow i h₁ (row.uset j h₂ value)

def set (m : Matrix) (i : Fin 4) (j : Fin 4) (value : Float32) : Matrix := m.uset
  (toUInt32Inj i.val i.isLt) (toUInt32Inj j.val j.isLt)
  (toUInt32Inj_lt i.val i.isLt) (toUInt32Inj_lt j.val j.isLt)
  value

end Matrix

instance : Add Matrix := ⟨Matrix.add⟩
instance : Sub Matrix := ⟨Matrix.sub⟩
instance : Mul Matrix := ⟨Matrix.mul⟩

instance : GetElem Matrix UInt32 Float32 (λ _ i ↦ i < 16) where
  getElem := Matrix.ugetLinear
  getElem! m i := dite _ (m.ugetLinear i) (λ _ ↦ default) -- this line may be removed when lean4#4418 is fixed

instance : GetElem Matrix Nat Float32 (λ _ i ↦ i < 16) where
  getElem m i h := m.getLinear ⟨i, h⟩
  getElem! m i := dite _ (m.getLinear ∘ Fin.mk i) (λ _ ↦ default) -- this line may be removed when lean4#4418 is fixed

end Raymath
