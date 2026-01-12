# ASCII Rotating Pyramid Renderer (C++)

This is a small C++ project that draws a rotating 3D pyramid in the terminal using ASCII characters. I wrote it mostly as an experiment to understand 3D rotations, perspective projection, and how to do a simple Z-buffer without any graphics library.

---

## What it does

* Rotates a 3D pyramid in real-time
* Projects 3D points onto a 2D terminal screen
* Handles depth using a simple Z-buffer
* Uses ASCII characters to show different faces of the pyramid
* Runs entirely in the terminal with no external graphics libraries

---

## How it works

Basically, each frame I:

1. Clear the screen and Z-buffer
2. Loop through the points on the pyramid's faces
3. Rotate each point in 3D using Euler angles (A, B, C)
4. Project the point to 2D coordinates on the terminal
5. Use a Z-buffer to make sure closer points overwrite farther points
6. Draw the result in the terminal
7. Increment the rotation angles for the next frame

It repeats this forever to make it look like the pyramid is spinning.

---

## Project files

```
main.cpp        # The rendering loop and math logic
Globals.h       # Shared constants and buffers
Globals.cpp     # Global definitions
README.md       # This file
```

---

## How to run

### Compile

```bash
g++ -std=c++11 -O2 main.cpp Globals.cpp -o pyramid
```

### Run

```bash
./pyramid
```

Press Ctrl+C to stop it.

---

## Notes

* Most of the math is done manually (no OpenGL or anything).
* I kept global variables only for things that need to persist, like buffers and rotation angles.
* Temporary variables like x, y, z, ooz, and indices are local to the functions now, which makes the code cleaner.

---

## Ideas for improving it

* Add simple ASCII lighting/shading to make it look more 3D
* Make it possible to control the camera or rotation with the keyboard
* Limit the frame rate to make it smoother
* Try rendering other 3D shapes like a cube or sphere
* Wrap the whole thing in a class to make it more organized

---

I wrote this mostly for fun and to practice low-level 3D math in C++. It's simple but it taught me a lot about how 3D graphics work under the hood.
