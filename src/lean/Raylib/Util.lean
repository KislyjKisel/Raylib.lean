set_option autoImplicit false

namespace Raylib

structure Int32 where
  val: UInt32
deriving Inhabited, Repr

-- todo: negative Int32 literals; OfNat Int32 != OfNat UInt32 (UInt32.size > Int32 max)
instance {n} [n' : OfNat UInt32 n] : OfNat Int32 n := OfNat.mk (Int32.mk n'.ofNat)


/-! # Logic -/

instance {α} {β} [h1 : Nonempty α] [h2 : Nonempty β] : Nonempty (α × β) :=
  Nonempty.intro (Classical.choice h1, Classical.choice h2)


/-! # Arrays -/

opaque floatX2Pointed : NonemptyType
/-- 2 x float -/
def floatX2 : Type := floatX2Pointed.type
instance : Nonempty floatX2 := floatX2Pointed.property

opaque floatX3Pointed : NonemptyType
/-- 3 x float -/
def floatX3 : Type := floatX3Pointed.type
instance : Nonempty floatX3 := floatX3Pointed.property

opaque floatX4Pointed : NonemptyType
/-- 4 x float -/
def floatX4 : Type := floatX4Pointed.type
instance : Nonempty floatX4 := floatX4Pointed.property

opaque MatrixX2Pointed : NonemptyType
/-- 2 x Matrix -/
def MatrixX2 : Type := MatrixX2Pointed.type
instance : Nonempty MatrixX2 := MatrixX2Pointed.property

end Raylib
