# Extra config options to customize raylib cmake build

Description: [Cmake Build Options](https://github.com/raysan5/raylib/wiki/CMake-Build-Options) on raylib's wiki.

Note: raylib must be rebuilt after changing these options.
To do this run lake script `buildSubmodule`.

| **Config Key**     | **CMake Option**             |
|:------------------:|:----------------------------:|
| `externalGlfw`     | `USE_EXTERNAL_GLFW`          |
| `platform`         | `PLATFORM`                   |
| `opengl`           | `OPENGL_VERSION`             |
| `wayland`          | `USE_WAYLAND`                |
| `macosFatlib`      | `MACOS_FATLIB`               |
| `audio`            | `USE_AUDIO`                  |
| `busyWaitLoop`     | `SUPPORT_BUSY_WAIT_LOOP`     |
| `cameraSystem`     | `SUPPORT_CAMERA_SYSTEM`      |
| `defaultFont`      | `SUPPORT_DEFAULT_FONT`       |
| `screenCapture`    | `SUPPORT_SCREEN_CAPTURE`     |
| `gifRecording`     | `SUPPORT_GIF_RECORDING`      |
| `gestures`         | `SUPPORT_GESTURES_SYSTEM`    |
| `mouseGestures`    | `SUPPORT_MOUSE_GESTURES`     |
| `vrSimulator`      | `SUPPORT_VR_SIMULATOR`       |
| `distortionShader` | `SUPPORT_DISTORTION_SHADER`  |
| `fontTexture`      | `SUPPORT_FONT_TEXTURE`       |
| `quadsDrawMode`    | `SUPPORT_QUAD_DRAW_MODE`     |
| `imageGen`         | `SUPPORT_IMAGE_GENERATION`   |
| `meshGen`          | `SUPPORT_MESH_GENERATION`    |
| `imageManip`       | `SUPPORT_IMAGE_MANIPULATION` |
| `tracelog`         | `SUPPORT_TRACELOG`           |
| `savePng`          | `SUPPORT_SAVE_PNG`           |
| `saveBmp`          | `SUPPORT_SAVE_BMP`           |
| `formatPng`        | `SUPPORT_FILEFORMAT_PNG`     |
| `formatDds`        | `SUPPORT_FILEFORMAT_DDS`     |
| `formatHdr`        | `SUPPORT_FILEFORMAT_HDR`     |
| `formatKtx`        | `SUPPORT_FILEFORMAT_KTX`     |
| `formatAstc`       | `SUPPORT_FILEFORMAT_ASTC`    |
| `formatBmp`        | `SUPPORT_FILEFORMAT_BMP`     |
| `formatTga`        | `SUPPORT_FILEFORMAT_TGA`     |
| `formatJpg`        | `SUPPORT_FILEFORMAT_JPG`     |
| `formatGif`        | `SUPPORT_FILEFORMAT_GIF`     |
| `formatPsd`        | `SUPPORT_FILEFORMAT_PSD`     |
| `formatPkm`        | `SUPPORT_FILEFORMAT_PKM`     |
| `formatPvr`        | `SUPPORT_FILEFORMAT_PVR`     |
| `formatObj`        | `SUPPORT_FILEFORMAT_OBJ`     |
| `formatMtl`        | `SUPPORT_FILEFORMAT_MTL`     |
| `formatWav`        | `SUPPORT_FILEFORMAT_WAV`     |
| `formatOgg`        | `SUPPORT_FILEFORMAT_OGG`     |
| `formatXm`         | `SUPPORT_FILEFORMAT_XM`      |
| `formatMod`        | `SUPPORT_FILEFORMAT_MOD`     |
| `formatFlac`       | `SUPPORT_FILEFORMAT_FLAC`    |
| `formatFnt`        | `SUPPORT_FILEFORMAT_FNT`     |
| `formatTtf`        | `SUPPORT_FILEFORMAT_TTF`     |
