# Short-term

* Check if dependent `extern_lib` may not be passed to `lean_exe` link flags.
* Add scaling in an example and test it with wayland.
  See highdpi functions in raylib.
  ```
  Raylib.Glfw.initHint .platform .platformX11 |>.toIO -- helps by avoiding wayland
  Raylib.setConfigFlags .windowHighdpi -- doesn't help, but is recommended?
  ```
* Test videomodes on NixOS/Wayland, make a workaround.
* Test using external glfw/raylib on windows/nixos. Is using nix on windows possible?
* Use pod's macros for structure layouts/field offsets for all Lean-side structures passing ffi


# Long-term

* Platform libraries bindings (e.g. when not GLFW; GLFW may be removed from platform=Web in raylib and in that case glfw bindings and link args should be disabled, and web-specific stuff enabled instead).


# Waiting for toolchain updates

* Declare all lake options at the top, validate them and enforce specific values instead of "isSome" where appropriate.
* Separate `extern_lib` for the raylib when interdependent single-package `extern_lib`s will be possible
* Test if VS Code + precompilation (Raymath/pod) + `cc` config work on Nix OS
* Abstract lakefile helpers into a library (parsing options, running tools)


# Probably never

* Flat external objects for FFI.
  Change
  `lean_object { .., -> Image { ..header, -> data } }`
  to
  `lean_object { .., -> BoxedImage { ..header, ..data } }`
                                  data ptr = ^ = this + sizeof(Header)
  (benchmark!)
* ST without result box allocation via custom no-error variant (-> EST, <-> ST)
  (does ST/IO allocate on every call? is it bad?
  IIRC there was a note somewhere saying that Lean devs want to fix it)
