# Raylib.lean

Lean4 bindings to [raylib](https://github.com/raysan5/raylib) `4.5.0`, including Raymath and Raygui.

## Usage

Add this to `lakefile.lean`:
```
require raylib from git
  "https://github.com/KislyjKisel/Raylib.lean" @ "main"
```

To the `lean_exe` target add:
```
moreLinkArgs := #["-Llake-packages/raylib/raylib/build/raylib", "-lraylib"]
```

Then run `lake update`.

### Options

Options can be specified by appending `with $opts` (where `$opts` is a `NameMap`) to the `require` statement

* `raylib`:
  `"submodule"` (default) to compile from source using git submodules.
  `"system"` to find using `pkg-config` (uses hardcoded paths for the test executable).
  `"custom"` to not pass library or header directories to the compiler.
* `cc`: c compiler invoked used to build native code.
  By default uses (ordered by priority) `LEAN_CC`, the compiler provided by Lean toolchain or `cc`.
* `cflags`: additional flags passed to the native code compiler.
* `lflags`: additional flags used to link test executable.
* `cmdout`: if present, print output of commands used when building submodule.
* `libffi`: use `libffi`, required for some things to work, e.g, audio callback
  (note: audio callback always segfaults with small allocator enabled which is the case by default)
* `alloc`: allocator for external (opaque ffi) objects.
  `"lean"` (default) means using the allocator Lean uses.
  `"native"` to use `malloc` and `free` instead.
* `git`, `cmake`: git and cmake used to build raylib submodule, or `""` (empty string) to skip their respective steps.

There are also [options to customize raylib build](options.md).

### Scripts

* `buildSubmodule`: (re)build raylib submodule.

## Example

To run the example:
```
lake update
lake build
./build/bin/test
```
