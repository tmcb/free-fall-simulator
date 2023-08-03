{ nixpkgs ? import <nixpkgs> {} }:


nixpkgs.mkShell.override {stdenv = nixpkgs.clangStdenv; } {
  buildInputs = if nixpkgs.stdenv.isLinux then [
    nixpkgs.boost
    nixpkgs.cmake
    nixpkgs.freeglut
    nixpkgs.glfw
    nixpkgs.gtest
    nixpkgs.libGLU
  ] else if nixpkgs.stdenv.isDarwin then [
    nixpkgs.boost
    nixpkgs.cmake
    nixpkgs.glfw
    nixpkgs.gtest
  ] else throw "Unsupported system: ${builtins.currentSystem}";
}
