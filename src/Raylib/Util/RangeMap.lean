import Pod.Lemmas

namespace Raylib

universe u
variable {min max : UInt32} {α : Type u}

/-- `RangeMap min max α` is `u32 ∩ [min; max) → α` represented as an `Array` of length `max - min`. -/
def RangeMap (min max : UInt32) (α : Type u) : Type u := Subtype
  λ (vs : Array α) ↦ vs.size = max.toNat - min.toNat

instance [instNonemptyAlpha : Nonempty α] : Nonempty (RangeMap min max α) :=
  Nonempty.intro $ Subtype.mk
    (Array.mkArray (max.toNat - min.toNat) (Classical.choice instNonemptyAlpha))
    (Array.size_mkArray _ _)

namespace RangeMap

private
theorem i_lt_max_of_not_eq_max (i : UInt32)
  (hi : min ≤ i ∧ i ≤ max) (i_ne_max : ¬ i = max) : i < max := by
    apply Nat.lt_of_le_of_ne hi.2
    intro i_eq_max
    apply i_ne_max
    apply UInt32.eq_of_toBitVec_eq
    apply BitVec.eq_of_toNat_eq
    exact i_eq_max

private
theorem i_add_1_toNat_eq (i : UInt32)
  (hi : min ≤ i ∧ i ≤ max) (i_ne_max : ¬ i = max) :
    (i + 1).toNat = i.toNat + 1 := by
      show (i.toNat + 1 % UInt32.size) % UInt32.size = _
      rewrite [Nat.mod_eq_of_lt (a := 1) (by decide)]
      exact Nat.mod_eq_of_lt $ Nat.lt_of_le_of_lt
        (Nat.succ_le_of_lt $ i_lt_max_of_not_eq_max i hi i_ne_max) max.toNat_lt

def ofFn (mm : min ≤ max) (f : (i : UInt32) → min ≤ i ∧ i < max → α) :
  RangeMap min max α :=
    go min (Array.mkEmpty (max - min).toNat)
      ⟨Nat.le_refl _, mm⟩
      (Nat.sub_eq_zero_of_le (Nat.le_of_eq rfl)).symm
where
  go (i : UInt32) (vs : Array α)
    (hi : min ≤ i ∧ i ≤ max) (hl : vs.size = i.toNat - min.toNat) :
      RangeMap min max α :=
        if him : i = max
          then .mk vs (by apply hl.trans; rw [him])
          else
            go (i + 1)
              (vs.push $ f i ⟨hi.1, i_lt_max_of_not_eq_max i hi him⟩)
              (And.intro
                (by
                  apply Nat.le_trans hi.1
                  show i.toNat ≤ (i + 1).toNat
                  rewrite [i_add_1_toNat_eq i hi him]
                  apply Nat.le_succ
                )
                (by
                  show (i + 1).toNat ≤ max.toNat
                  rewrite [i_add_1_toNat_eq i hi him]
                  exact Nat.succ_le_of_lt (i_lt_max_of_not_eq_max i hi him)
                )
              )
              (by
                show (vs.toList.concat _).length = (i + 1).toNat - _
                rewrite [
                  i_add_1_toNat_eq i hi him,
                  List.length_concat _ _,
                  Nat.add_comm _ 1,
                  Nat.add_comm _ 1
                ]
                show _ = 1 + i.toNat - min.toNat
                rewrite [Array.size] at hl
                rewrite [hl, Nat.add_sub_assoc _ _]
                rfl
                exact hi.1
              )
  termination_by max - i
  decreasing_by
    simp_wf
    have i_lt_max : i < max := by
      apply Nat.lt_of_le_of_ne hi.2
      intro h
      apply him
      apply UInt32.eq_of_toFin_eq
      apply Fin.eq_of_val_eq
      exact h
    have i_succ_lt_u32 : i.toFin + 1 < UInt32.size := by
      apply Nat.lt_of_le_of_lt
      apply Nat.succ_le_of_lt i_lt_max
      exact max.toFin.isLt
    have i_succ_eq : i + 1 = UInt32.ofNatLT (i.toNat + 1) i_succ_lt_u32 := by
      apply UInt32.eq_of_toFin_eq
      apply Fin.eq_of_val_eq
      show (i.toNat + 1) % _ = i.toNat + 1
      apply Nat.mod_eq_of_lt
      apply Nat.lt_of_le_of_lt
      exact i_lt_max
      exact max.toNat_lt_size
    have i_succ_le_max : i + 1 ≤ max := by
      rewrite [i_succ_eq]
      show i.toNat + 1 ≤ _
      exact i_lt_max
    rewrite [
      UInt32.toNat_sub_of_le _ _ i_succ_le_max,
      UInt32.toNat_sub_of_le _ _ hi.2
    ]
    rewrite [i_succ_eq]
    show max.toNat - (i.toNat + 1) < max.toNat - i.toNat
    apply Nat.sub_add_lt_sub _ Nat.zero_lt_one
    exact Nat.succ_le_of_lt i_lt_max

private
theorem USize_ofNat32_toNat (x : Nat) (h : x < 2^32) : (USize.ofNat32 x h).toNat = x := by
  rfl

private
theorem i_sub_min_lt_max_sub_min (i : UInt32) (h : min ≤ i ∧ i < max) :
  (i - min).toUSize.toNat < max.toNat - min.toNat := by
    rewrite [
      UInt32.toUSize,
      USize_ofNat32_toNat,
      ← UInt32.toNat,
      UInt32.toNat_sub_of_le i min h.1,
    ]
    apply Nat.sub_lt_sub_right h.1 h.2

def get (rm : RangeMap min max α) (i : UInt32) (h : min ≤ i ∧ i < max) : α :=
  rm.val.uget (i - min).toUSize $ by
    rewrite [rm.property]
    exact i_sub_min_lt_max_sub_min i h

def set (rm : RangeMap min max α) (i : UInt32) (a : α) (h : min ≤ i ∧ i < max) :
  RangeMap min max α := Subtype.mk
    (rm.val.uset (i - min).toUSize a $ by
      rewrite [rm.property]
      exact i_sub_min_lt_max_sub_min i h
    )
    (by
      show List.length (List.set _ _ _) = _
      rewrite [List.length_set]
      show rm.val.size = _
      exact rm.property
    )

end RangeMap
