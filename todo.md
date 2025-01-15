# Short-term

* ! Fix pod/raylib assumption about SInt representations (they are actually UInt* wrappers, not special).
* See if passing lake config options to lakefiles in a subdir is disabled by design.
* Check if dependent `extern_lib` may not be passed to `lean_exe` link flags.
* Fix `__dir__` in `olean` to allow running examples from a subdir.
* Fix `Raymath` precompilation on NixOS.
* Fix `pod` precompilation producing errors in VS Code on NixOS (clang crashes, which should be because wrong CC is set, but it seems to ignore `cc` option?)
* Move examples to the main lakefile.
  Allow configuration of `lflags` for examples and check if `cc` works (it should).
* Add scaling in an example and test it with wayland.
  See highdpi functions in raylib.
  ```
  Raylib.Glfw.initHint .platform .platformX11 |>.toIO -- helps by avoiding wayland
  Raylib.setConfigFlags .windowHighdpi -- doesn't help, but is recommended?
  ```
* Test videomodes on NixOS/Wayland, make a workaround.
* Why wayland is not enabled by default in raylib? (it is default in glfw)
* Test using external glfw/raylib on windows/nixos. Is using nix on windows possible?
* Is `getLeanTrace` required for `buildO`?
  Docstring: only when using builtin `leanc`.
  Example in lake repo: uses despite compiling with `c++`.


# Waiting for toolchain updates

* Declare all lake options at the top, validate them and enforce specific values instead of "isSome" where appropriate.

* Separate `extern_lib` for the raylib when interdependent single-package `extern_lib`s will be possible


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
