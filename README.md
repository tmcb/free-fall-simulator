# Free Fall Simulator

## Description

This free fall simulation models a spherical ball falling through the air under the influence of gravity and aerodynamic drag. 

## Setup

In all cases, ensure that you have the proper permissions.  You might need to use `sudo` or equivalent tools at some point.

### Linux (Debian 11)

A list containing the required packages is available at `etc/debian-packages.txt`.  In order to install these packages, run

    xargs -a ./etc/debian-packages.txt -d '\n' apt-get install -y

### MacOS (Ventura + Homebrew)

Assuming [XCode Command Line Tools](https://developer.apple.com/xcode/resources/) are already installed, there are other dependencies required.  [Homebrew](https://brew.sh) is the only package manager supported at the moment.

A list containing the required packages is available at `etc/macos-brew-packages.txt`.  In order to install these packages, run

    xargs -J@ brew install @ < ./etc/macos-brew-packages.txt

### Nix (NixOS 23.05 & MacOS Ventura + Nix)

This project supports `nix-shell`.  If you wish to start a development shell, run

    nix-shell ./etc/shell.nix

## Build

The commands below were tested on `bash`.  Please adapt them to your shell accordingly.

In order to set up the build directory, run

    (mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=Release ..)

### Full build

To build the simulator and the test suite, run

    make -C build

### Simulator build

If you wish to build the simulator only, run

    make -C build free_fall_sim

### Test suite build

If you wish to build the test suite only, run

    make -C build free_fall_sim_test

## Run

To run the simulator with the default settings, run

    build/free_fall_sim

To list all available settings, run

    build/free_fall_sim --help

## Test

Make sure that [the tests have been built successfully](#test-suite-build).  To run the test suite, run

    make -C build test 

## To-do & limitations

* Only 1D simulations are supported at the moment;
* Proper dimensional analysis (default values are based on MKS units but are not validated);
* Parameter validation is implemented in the application itself, not in the simulation logic;
* The GUI is non-interactive and only supports a hard-coded visualization of the simulation;
* Encapsulate simulation in an object;
* A base-object/interface for generic bodies (only the `SphericalBody1D` class is supported at the moment);
* Support callbacks to the simulation to integrate it with the application (it is currently done the other way around);
* Better test coverage;
* More comments and integration with online documentation generators (e.g. doxygen).

## Author

Tadeu Bastos <[tadeu@ondular.net](mailto:tadeu@ondular.net)>
