## Linux Build Instructions

Install 'code' from snap store or any other method.

You'll be installing a bunch of packages.

`sudo apt install g++`

`sudo apt install cmake`

`sudo apt install git`

`sudo apt install libgl1-mesa-dev libxss-dev libxxf86vm-dev libxkbfile-dev libxv-dev`

`sudo apt install libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev`

`sudo apt install libwayland-dev libxkbcommon-dev xorg-dev`

In vs code install the "C/C++ Extension Pack" from the store and then open the project folder and run:

`git submodule init` and `git submodule update`

Finally Ctrl-Shift-P and run `Cmake: Configure` and then do it again and run `Cmake: Build` and it should work.

One of these days pebble will learn how to deploy a build for convenience.
