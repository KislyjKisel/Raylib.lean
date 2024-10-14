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
    show (UInt32.mk $ Fin.mk _ _) = _
    conv => pattern i.val.val; rw [i_eq_max]

private
theorem i_add_1_toNat_eq (i : UInt32)
  (hi : min ≤ i ∧ i ≤ max) (i_ne_max : ¬ i = max) :
    (i + 1).val.val = i.val.val + 1 := by
      show (i.val.val + 1 % UInt32.size) % UInt32.size = _
      rewrite [Nat.mod_eq_of_lt (a := 1) (by decide)]
      exact Nat.mod_eq_of_lt $ Nat.lt_of_le_of_lt
        (Nat.succ_le_of_lt $ i_lt_max_of_not_eq_max i hi i_ne_max) max.val.isLt

def ofFn (mm : min ≤ max) (f : (i : UInt32) → min ≤ i ∧ i < max → α) :
  RangeMap min max α :=
    go min (Array.mkEmpty (max - min).val.val)
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
                  show i.val.val ≤ (i + 1).val.val
                  rewrite [i_add_1_toNat_eq i hi him]
                  apply Nat.le_succ
                )
                (by
                  show (i + 1).val.val ≤ max.val.val
                  rewrite [i_add_1_toNat_eq i hi him]
                  exact Nat.succ_le_of_lt (i_lt_max_of_not_eq_max i hi him)
                )
              )
              (by
                show (vs.data.concat _).length = (i + 1).val.val - _
                rewrite [
                  i_add_1_toNat_eq i hi him,
                  List.length_concat _ _,
                  Nat.add_comm _ 1,
                  Nat.add_comm _ 1
                ]
                show _ = 1 + i.val.val - min.val.val
                rw [Nat.add_sub_assoc hi.1 _]
                apply congrArg _ hl
              )
  termination_by max - i
  decreasing_by
    simp_wf
    have i_lt_max : i < max := by
      apply Nat.lt_of_le_of_ne hi.2
      intro h
      apply him
      apply UInt32.eq_of_val_eq
      apply Fin.eq_of_val_eq
      exact h
    have i_succ_lt_u32 : i.val + 1 < UInt32.size := by
      apply Nat.lt_of_le_of_lt
      apply Nat.succ_le_of_lt i_lt_max
      exact max.val.isLt
    have i_succ_le_max : i + 1 ≤ max := by
      show _ % UInt32.size ≤ _
      rewrite [Nat.mod_eq_of_lt i_succ_lt_u32]
      exact Nat.succ_le_of_lt i_lt_max
    rewrite [
      UInt32.toNat_sub_of_le _ _ i_succ_le_max,
      UInt32.toNat_sub_of_le _ _ hi.2
    ]
    show _ - (_ % UInt32.size) < _
    rewrite [
      Nat.mod_eq_of_lt (a := 1) (by decide),
      Nat.mod_eq_of_lt i_succ_lt_u32
    ]
    apply Nat.sub_add_lt_sub _ Nat.zero_lt_one
    exact Nat.succ_le_of_lt i_lt_max

private
theorem i_minus_min_lt_size (i : UInt32) (h : min ≤ i ∧ i < max) :
  (i - min).toUSize.toNat < max.toNat - min.toNat := by
    show (_  % UInt32.size) < _
    rewrite [
      Nat.add_comm,
      ← Nat.add_sub_assoc (Nat.le_of_lt min.val.isLt),
      Nat.add_comm,
      Nat.add_sub_assoc h.1,
      Nat.add_mod_left,
      Nat.mod_eq_of_lt (Nat.lt_of_le_of_lt (Nat.sub_le _ _) i.val.isLt)
    ]
    apply Nat.lt_sub_of_add_lt
    show i.val.val - min.val.val + min.val.val < max.toNat
    rewrite [Nat.sub_add_cancel h.1]
    exact h.2

def get (rm : RangeMap min max α) (i : UInt32) (h : min ≤ i ∧ i < max) : α :=
  rm.val.uget (i - min).toUSize $ by
    rewrite [rm.property]
    exact i_minus_min_lt_size i h

def set (rm : RangeMap min max α) (i : UInt32) (a : α) (h : min ≤ i ∧ i < max) :
  RangeMap min max α := Subtype.mk
    (rm.val.uset (i - min).toUSize a $ by
      rewrite [rm.property]
      exact i_minus_min_lt_size i h
    )
    (by
      show List.length (List.set _ _ _) = _
      rewrite [List.length_set]
      show rm.val.size = _
      exact rm.property
    )

end RangeMap
