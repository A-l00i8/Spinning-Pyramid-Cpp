#include "Globals.h"

// Screen dimensions
const int width = 70;
const int height = 33;

// Pyramid dimensions
const int pyramidBaseWidth = 40;
const int pyramidHeight = 45;

// Rendering buffers
char buffer[width * height];
double zBuffer[width * height];
const int backgroundASCIICode = ' ';

// Camera & projection
const int K1 = 60;
const int camDistance = 200;

// Rotation angles
double A = 0.0;
double B = 0.0;
double C = 1.57;
