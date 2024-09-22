import Pod.Float
import Pod.Instances
import Raymath.Core

open Pod (Float32)

namespace Raymath

#pod_c_rwbytes_instance Raymath.Vector2
#pod_c_rwbytes_instance Raymath.Vector3
#pod_c_rwbytes_instance Raymath.Vector4
#pod_c_rwbytes_instance Raymath.Matrix

namespace Vector3

/-- Projects a Vector3 from screen space into object space -/
@[extern "lean_raymath_Vector3_unproject"]
opaque unproject (source : @& Vector3) (projection view : @& Matrix) : Vector3

end Vector3


namespace Matrix

/-- Returns translation, rotation and scale. Foreign implementation. -/
@[extern "lean_raymath_Matrix_decompose"]
opaque decompose' (mat : @& Matrix) : Vector3 × Quaternion × Vector3

end Matrix


namespace Quaternion

/-- Get a quaternion for a given rotation matrix. Foreign implementation. -/
@[extern "lean_raymath_Quaternion_fromMatrix"]
opaque fromMatrix' (mat : @& Matrix) : Quaternion

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

end Raymath
