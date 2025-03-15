# Extra config options to customize raylib cmake build

Description: [Cmake Build Options](https://github.com/raysan5/raylib/wiki/CMake-Build-Options) on raylib's wiki.

Note: raylib must be rebuilt after changing these options.
To do this run lake script `buildSubmodule`.

| **Config Key**     | **CMake Option**             |
|:------------------:|:----------------------------:|
| `externalGlfw`     | `USE_EXTERNAL_GLFW`          |
| `platform`         | `PLATFORM`                   |
| `opengl`           | `OPENGL_VERSION`             |
| `wayland`          | `GLFW_BUILD_WAYLAND`         |
| `x11`              | `GLFW_BUILD_X11`             |
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
| `formatGif`        | `SUPPORT_FILEFORMAT_GIF`     |
| `formatQoi`        | `SUPPORT_FILEFORMAT_QOI`     |
| `formatDds`        | `SUPPORT_FILEFORMAT_DDS`     |
| `formatBmp`        | `SUPPORT_FILEFORMAT_BMP`     |
| `formatTga`        | `SUPPORT_FILEFORMAT_TGA`     |
| `formatJpg`        | `SUPPORT_FILEFORMAT_JPG`     |
| `formatPsd`        | `SUPPORT_FILEFORMAT_PSD`     |
| `formatHdr`        | `SUPPORT_FILEFORMAT_HDR`     |
| `formatPic`        | `SUPPORT_FILEFORMAT_PIC`     |
| `formatKtx`        | `SUPPORT_FILEFORMAT_KTX`     |
| `formatAstc`       | `SUPPORT_FILEFORMAT_ASTC`    |
| `formatPkm`        | `SUPPORT_FILEFORMAT_PKM`     |
| `formatPvr`        | `SUPPORT_FILEFORMAT_PVR`     |
| `formatSvg`        | `SUPPORT_FILEFORMAT_SVG`     |
| `formatObj`        | `SUPPORT_FILEFORMAT_OBJ`     |
| `formatMtl`        | `SUPPORT_FILEFORMAT_MTL`     |
| `formatIqm`        | `SUPPORT_FILEFORMAT_IQM`     |
| `formatGltf`       | `SUPPORT_FILEFORMAT_GLTF`    |
| `formatVox`        | `SUPPORT_FILEFORMAT_VOX`     |
| `formatM3d`        | `SUPPORT_FILEFORMAT_M3D`     |
| `formatWav`        | `SUPPORT_FILEFORMAT_WAV`     |
| `formatOgg`        | `SUPPORT_FILEFORMAT_OGG`     |
| `formatXm`         | `SUPPORT_FILEFORMAT_XM`      |
| `formatMod`        | `SUPPORT_FILEFORMAT_MOD`     |
| `formatFlac`       | `SUPPORT_FILEFORMAT_FLAC`    |
| `formatFnt`        | `SUPPORT_FILEFORMAT_FNT`     |
| `formatTtf`        | `SUPPORT_FILEFORMAT_TTF`     |
| `formatBdf`        | `SUPPORT_FILEFORMAT_BDF`     |
