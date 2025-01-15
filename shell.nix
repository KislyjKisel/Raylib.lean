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
    # glfw-wayland # glfw
    libGL
  ];
  LD_LIBRARY_PATH = pkgs.lib.makeLibraryPath buildInputs;
}
