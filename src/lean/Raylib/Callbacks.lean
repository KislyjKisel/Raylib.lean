import Pod.UInt
import Pod.BytesRef
import Raylib.Util.ST2
import Raylib.Structures

namespace Raylib

/-- Logging: Redirect trace log messages -/
def TraceLogCallback : Type 1 := {σ : Type} → TraceLogLevel → String → VaList σ → EST2 IO.Error σ IO.RealWorld Unit

/-- FileIO: Load binary data -/
def LoadFileDataCallback : Type := System.FilePath → IO ByteArray

/-- FileIO: Save binary data -/
def SaveFileDataCallback : Type 1 := {σ : Type} →
  System.FilePath → {size : Nat} → Pod.BytesRefImm σ size 1 → EST2 IO.Error σ IO.RealWorld Bool

/-- FileIO: Load text data -/
def LoadFileTextCallback : Type := System.FilePath → IO String

/-- FileIO: Save text data -/
def SaveFileTextCallback : Type := System.FilePath → String → IO Bool

def AudioCallback (st : AudioSampleType) := {σ : Type} →
  (frames : Nat) → Pod.BytesRefMut σ (frames * st.size.toNat) st.alignment → EST2 IO.Error σ IO.RealWorld Unit

end Raylib
