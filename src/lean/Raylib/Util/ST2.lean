namespace Raylib

inductive EST2.Result (ε σ₁ σ₂ α : Type) where
  | ok : α → σ₁ → σ₂ → EST2.Result ε σ₁ σ₂ α
  | error : ε → σ₁ → σ₂ → EST2.Result ε σ₁ σ₂ α

def EST2 (ε σ₁ σ₂ α : Type) : Type := σ₁ → σ₂ → EST2.Result ε σ₁ σ₂ α

abbrev ST2 (σ₁ σ₂ : Type) := EST2 Empty σ₁ σ₂

namespace EST2

def lift₁ {ε σ₁ σ₂ α} (x : EST ε σ₁ α) : EST2 ε σ₁ σ₂ α := λ s₁ s₂ ↦ match x s₁ with
  | EStateM.Result.ok a s₁ => EST2.Result.ok a s₁ s₂
  | EStateM.Result.error e s₁ => EST2.Result.error e s₁ s₂

def lift₂ {ε σ₁ σ₂ α} (x : EST ε σ₂ α) : EST2 ε σ₁ σ₂ α := λ s₁ s₂ ↦ match x s₂ with
  | EStateM.Result.ok a s₂ => EST2.Result.ok a s₁ s₂
  | EStateM.Result.error e s₂ => EST2.Result.error e s₁ s₂

@[noinline, nospecialize]
def run₁ {ε σ₂ α} (x : (σ₁ : Type) → EST2 ε σ₁ σ₂ α) : EST ε σ₂ α := λ s₂ ↦ match x Unit () s₂ with
  | EST2.Result.ok a _ s₂ => EStateM.Result.ok a s₂
  | EST2.Result.error e _ s₂ => EStateM.Result.error e s₂

@[noinline, nospecialize]
def run₂ {ε σ₁ α} (x : (σ₂ : Type) → EST2 ε σ₁ σ₂ α) : EST ε σ₁ α := λ s₁ ↦ match x Unit s₁ () with
  | EST2.Result.ok a s₁ _ => EStateM.Result.ok a s₁
  | EST2.Result.error e s₁ _ => EStateM.Result.error e s₁

@[always_inline, inline]
def pure {ε σ₁ σ₂ α} (a : α) : EST2 ε σ₁ σ₂ α := EST2.Result.ok a

@[always_inline, inline]
def throw {ε σ₁ σ₂ α} (e : ε) : EST2 ε σ₁ σ₂ α := EST2.Result.error e

@[always_inline, inline]
def map {ε σ₁ σ₂ α β} (f : α → β) (x : EST2 ε σ₁ σ₂ α) : EST2 ε σ₁ σ₂ β := λ s₁ s₂ ↦
  match x s₁ s₂ with
  | EST2.Result.ok a s₁ s₂ => EST2.Result.ok (f a) s₁ s₂
  | EST2.Result.error e s₁ s₂ => EST2.Result.error e s₁ s₂

@[always_inline, inline]
def bind {ε σ₁ σ₂ α β} (x : EST2 ε σ₁ σ₂ α) (f : α → EST2 ε σ₁ σ₂ β) : EST2 ε σ₁ σ₂ β := λ s₁ s₂ ↦
  match x s₁ s₂ with
  | EST2.Result.ok a s₁ s₂ => f a s₁ s₂
  | EST2.Result.error e s₁ s₂ => EST2.Result.error e s₁ s₂

@[always_inline, inline]
def seqRight {ε σ₁ σ₂ α β} (x : EST2 ε σ₁ σ₂ α) (y : Unit → EST2 ε σ₁ σ₂ β) : EST2 ε σ₁ σ₂ β :=
  λ s₁ s₂ ↦ match x s₁ s₂ with
  | EST2.Result.ok _ s₁ s₂ => y () s₁ s₂
  | EST2.Result.error e s₁ s₂ => EST2.Result.error e s₁ s₂

instance (ε σ₁ σ₂ : Type) : Monad (EST2 ε σ₁ σ₂) := { pure, bind, map, seqRight }

instance {ε σ₁ σ₂} : MonadLift (EST ε σ₁) (EST2 ε σ₁ σ₂) where
  monadLift x := EST2.lift₁ x

instance {ε σ₁ σ₂} : MonadLift (EST ε σ₂) (EST2 ε σ₁ σ₂) where
  monadLift x := EST2.lift₂ x

def toExcept {ε σ₁ σ₂ α} (x : EST2 ε σ₁ σ₂ α) : EST2 Empty σ₁ σ₂ (Except ε α) := λ s₁ s₂ ↦
  match x s₁ s₂ with
  | .ok x s₁ s₂ => .ok (.ok x) s₁ s₂
  | .error e s₁ s₂ => .ok (.error e) s₁ s₂

def ignoreErrors {ε σ₁ σ₂} (x : EST2 ε σ₁ σ₂ Unit) : EST2 Empty σ₁ σ₂ Unit := λ s₁ s₂ ↦
  match x s₁ s₂ with
  | .ok x s₁ s₂ => .ok x s₁ s₂
  | .error _ s₁ s₂ => .ok () s₁ s₂

def ignoreErrors? {ε σ₁ σ₂ α} (x : EST2 ε σ₁ σ₂ α) : EST2 Empty σ₁ σ₂ (Option α) := λ s₁ s₂ ↦
  match x s₁ s₂ with
  | .ok x s₁ s₂ => .ok (some x) s₁ s₂
  | .error _ s₁ s₂ => .ok none s₁ s₂

def ignoreErrorsD {ε σ₁ σ₂ α} (default : α) (x : EST2 ε σ₁ σ₂ α) : EST2 Empty σ₁ σ₂ α := λ s₁ s₂ ↦
  match x s₁ s₂ with
  | .ok x s₁ s₂ => .ok x s₁ s₂
  | .error _ s₁ s₂ => .ok default s₁ s₂
