# cub3d
A small educational 3D rendering engine using raycasting (Wolfenstein-like) — implemented to learn raycasting, texture handling and realtime input.

## Description
This repository contains a simple first-person 3D engine using raycasting. The goal is to render a 2D map into a 3D perspective, handle collisions, wall textures and player movement.

## Requirements
- Linux
- gcc / clang
- make
- MiniLibX (or SDL2 depending on implementation)
- libXext, libX11 (for MiniLibX)
- (optional) valgrind for memory debugging

On Debian/Ubuntu you can install basic dependencies with:
sudo apt update && sudo apt install build-essential libx11-dev libxext-dev

## Build
Usually:
make

Or, if there is no Makefile, compile manually:
gcc -o cub3d src/*.c -lmlx -lX11 -lXext -lm

Adjust flags and libraries to your environment.

## Usage
./cub3d maps/example.cub

The program loads a map file (.cub) and opens a window displaying the 3D scene. Exit with ESC or by closing the window.

## Controls (default)
- W / Z: move forward
- S: move backward
- A / Q: move left
- D: move right
- Left / Right arrows: turn view
- ESC: quit

(Adapt keys to your project configuration if needed.)

## Map format
Map files are plain text describing:
- wall and floor layout
- initial player position and orientation
- paths to textures

See the maps/ folder or provided examples for the exact format used by this project.

## Testing & Debug
- valgrind ./cub3d maps/example.cub
- enable debug prints according to project macros
