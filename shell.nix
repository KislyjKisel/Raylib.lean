{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell rec {
  packages = with pkgs; [
    elan
    cmake
    git
    clang
    gcc
    wayland-scanner
    pkg-config
  ];
  buildInputs = with pkgs; [
    xorg.libX11 xorg.libXcursor xorg.libXi xorg.libXrandr xorg.libXinerama
    libxkbcommon
    wayland
    libGL
  ];
  LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath buildInputs;
}

# To run an example:
# Disable precompilation for Raymath
# (cc may be either gcc or clang, both work)
# Add `cc = "cc"` to `[require.options]`
# Run `LEAN_CC=cc lake -d=examples exe Minimal`
