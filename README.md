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

Then run `lake update` and `lake run raylib/buildSubmodule`.

### Options

Options can be specified by appending `with $opts` (where `$opts` is a `NameMap`) to the `require` statement

* `raylib`:
  `"submodule"` (default) to compile from source using git submodules.
  `"system"` to find using `pkg-config` (uses hardcoded paths for the test executable).
  `"custom"` to not pass library or header directories to the compiler.
* `raygui`: allows using `Raygui`, downloads it as a submodule.
* `cc`: c compiler invoked used to build native code.
  By default uses (ordered by priority) `LEAN_CC`, the compiler provided by Lean toolchain or `cc`.
* `cflags`: additional flags passed to the native code compiler.
* `lflags`: additional flags used to link test executable.
* `cmdout`: if present, print output of commands used when building submodule.
* `libffi`: use `libffi`, required for some things to work, e.g, audio callback
  (note: audio callback always segfaults due to missing thread initialization)
* `alloc`: allocator for external (opaque ffi) objects.
  `"lean"` (default) means using the allocator Lean uses.
  `"native"` to use `malloc` and `free` instead.
* `git`, `cmake`: git and cmake used to build raylib submodule, or `""` (empty string) to skip their respective steps.

There are also [options to customize raylib build](options.md).

### Installation problems

* First build may take some time (around 10-20 minutes) to download raylib.
* On the first build git may return error 128.
  Usually restarting the build or re-cloning the raylib's repo helps.
* By default Lean's built-in C compiler is used to build ffi.
  On Windows it fails due to missing stdlib headers.
  You can use a different C compiler by passing the `cc` option
  with the compilers path (options are described above).
  To build raylib `cmake` and `git` from `PATH` are used.
  If you don't have them in PATH you can provide their paths with options `git` and `cmake`.
  If you want to clone and/or build raylib manually you can provide empty `git` and `cmake` options
  and then run required commands (which can be found in the [lakefile](/lakefile.lean) in `buildRaylibSubmodule`).
  You can also use `raylib` option set to `custom` and
  provide separately built raylib via `lflags` and `cflags` options.

## Example

To run the example:
```
lake update
lake run raylib/buildSubmodule
lake exe raylib-test
```
