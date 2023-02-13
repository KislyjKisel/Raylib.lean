set_option autoImplicit false

namespace Raylib

structure Int32 where
  val: UInt32
deriving Inhabited, Repr

instance {n} [n' : OfNat UInt32 n] : OfNat Int32 n := OfNat.mk (Int32.mk n'.ofNat)

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
