import Pod.UInt
import Pod.BytesRef
import Raylib.Structures
import Raylib.ST2

namespace Raylib
-- /-! # Callbacks -/
-- /-- Logging: Redirect trace log messages -/
-- def TraceLogCallback : Type := panic! "Untranslated"
-- /- todo: ^^ callback ^^
--   returns: void
--   params:
--   | logLevel : int
--   | text : const char *
--   | args : va_list
-- -/

/-- FileIO: Load binary data -/
def LoadFileDataCallback : Type := System.FilePath → IO ByteArray

/-- FileIO: Save binary data -/
def SaveFileDataCallback : Type 1 := {σ : Type} →
  System.FilePath → {size : USize} → Pod.BytesRefImm σ size 1 → EST2 IO.Error σ IO.RealWorld Bool

/-- FileIO: Load text data -/
def LoadFileTextCallback : Type := System.FilePath → IO String

/-- FileIO: Save text data -/
def SaveFileTextCallback : Type := System.FilePath → String → IO Bool

def AudioCallback (st : AudioSampleType) := {σ : Type} →
  (frames : USize) → Pod.BytesRefMut σ (frames * st.size.toUSize) st.alignment → EST2 IO.Error σ IO.RealWorld Unit

end Raylib
