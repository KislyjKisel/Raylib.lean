# Raylib.lean

Partial [raylib](https://github.com/raysan5/raylib) `4.5.0` bindings for Lean4.

## Not implemented

* Meshes, models
* Data array manip (ex. `UpdateSound`)
* GlyphInfo
* TraceLog

## Usage

Add this to `lakefile.lean`:
```
require Raylib from git
  "https://github.com/KislyjKisel/Raylib.lean.git" @ "main"
```

Then run `lake update`.

### Options

Options can be specified by appending `with $opts` (where `$opts` is a `NameMap`) to the `require` statement

* `raylib`:
  `"submodule"` (default) to compile from source using git submodules.
  `"system"` to find using `pkg-config` (uses hardcoded paths for the test executable).
  `"custom"` to not pass library or header directories to the compiler.
* `cc`: c compiler invoked to compile ffi; `"cc"` by default.
* `cflags`: additional flags passed to `cc`.
* `lflags`: additional flags used to link test executable.
* `cmdout`: if present, print output of commands used when building submodule.
* `libffi`: use `libffi`, required for some things to work, e.g, audio callback
  (note: audio callback always segfaults with small allocator enabled which is the case by default)

### Scripts

* `buildRL`: build only raylib submodule, useful for updating headers when changing C code.

## Example

To run the example:
```
lake update
lake build
./build/bin/test
```
