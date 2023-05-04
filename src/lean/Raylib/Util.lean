namespace Raylib

structure Int32 where
  val: UInt32
deriving Inhabited, Repr

-- todo: negative Int32 literals; OfNat Int32 != OfNat UInt32 (UInt32.size > Int32 max)
instance {n} [n' : OfNat UInt32 n] : OfNat Int32 n := OfNat.mk (Int32.mk n'.ofNat)


/-! # Logic -/

instance {α} {β} [h1 : Nonempty α] [h2 : Nonempty β] : Nonempty (α × β) :=
  Nonempty.intro (Classical.choice h1, Classical.choice h2)

end Raylib
