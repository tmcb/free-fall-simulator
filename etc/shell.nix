{ nixpkgs ? import <nixpkgs> {} }:

nixpkgs.mkShell.override {stdenv = nixpkgs.clangStdenv; } {
  buildInputs = [
    nixpkgs.boost
    nixpkgs.cmake
    nixpkgs.glfw
    nixpkgs.gtest
  ];
}
