#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstddef> // for size_t

// Screen dimensions
extern const int width;
extern const int height;

// Pyramid dimensions
extern const int pyramidBaseWidth;
extern const int pyramidHeight;

// Rendering buffers
extern char buffer[];
extern double zBuffer[];
extern const int backgroundASCIICode;

// Camera & projection
extern const int K1;
extern const int camDistance;

// Rotation angles (animated each frame)
extern double A;
extern double B;
extern double C;

#endif
