import Pod.Float
import Raymath.Core

open Pod (Float32)

namespace Raymath.Foreign

abbrev Vector2 : Type := Raymath.Vector2
abbrev Vector3 : Type := Raymath.Vector3
abbrev Vector4 : Type := Raymath.Vector4
abbrev Matrix : Type := Raymath.Matrix
abbrev Quaternion : Type := Raymath.Quaternion

namespace Vector3

/-- Projects a Vector3 from screen space into object space -/
@[extern "lean_raymath_Vector3_unproject"]
opaque unproject (source : @& Vector3) (projection view : @& Matrix) : Vector3

end Vector3


namespace Quaternion

/-- Get a quaternion for a given rotation matrix -/
@[extern "lean_raymath_Quaternion_fromMatrix"]
opaque fromMatrix (mat : @& Matrix) : Quaternion

/--
Get rotation quaternion for an angle and axis.
NOTE: Angle must be provided in radians.
-/
@[extern "lean_raymath_Quaternion_fromAxisAngle"]
opaque fromAxisAngle (axis : @& Vector3) (angle : Float32) : Quaternion

/-- Get the rotation angle and axis for a given quaternion -/
@[extern "lean_raymath_Quaternion_toAxisAngle"]
opaque toAxisAngle (q : @& Quaternion) : Vector3 × Float32

/--
Get the Euler angles equivalent to quaternion (roll, pitch, yaw).
NOTE: Angles are returned in a Vector3 struct in radians.
-/
@[extern "lean_raymath_Quaternion_toEuler"]
opaque toEuler (q : @& Quaternion) : Vector3

/-- Check whether two given quaternions are almost equal -/
@[extern "lean_raymath_Quaternion_equals"]
opaque qequals (p q : @& Quaternion) : Bool

end Quaternion

end Raymath.Foreign
