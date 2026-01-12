#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include "Globals.h"

using namespace std;

/*
    Rotate a 3D point (i, j, k) around the X/Y/Z axes
    using Euler angles A, B, C.
*/

double calculateX(double i, double j, double k)
{
    return j * sin(A) * sin(B) * cos(C)
         - k * cos(A) * sin(B) * cos(C)
         + j * cos(A) * sin(C)
         + k * sin(A) * sin(C)
         + i * cos(B) * cos(C);
}

double calculateY(double i, double j, double k)
{
    return j * cos(A) * cos(C)
         + k * sin(A) * cos(C)
         - j * sin(A) * sin(B) * sin(C)
         + k * cos(A) * sin(B) * sin(C)
         - i * cos(B) * sin(C);
}

double calculateZ(double i, double j, double k)
{
    return k * cos(A) * cos(B)
         - j * sin(A) * cos(B)
         + i * sin(B);
}

/*
    Projects a 3D point onto the 2D screen and writes
    it into the frame buffer using Z-buffering.
*/

void calculateForPoint(double i, double j, double k, char ch)
{
    // Rotate point in 3D space
    double x = calculateX(i, j, k);
    double y = calculateY(i, j, k);
    double z = calculateZ(i, j, k) + camDistance;

    // Perspective projection
    double ooz = 1.0 / z; // one over z

    int xp = static_cast<int>(width / 2 + K1 * ooz * x * 2);
    int yp = static_cast<int>(height / 2 + K1 * ooz * y);

    // Screen bounds check
    if (xp < 0 || xp >= width || yp < 0 || yp >= height)
        return;

    size_t idx = xp + yp * width;

    // Z-buffer test
    if (ooz > zBuffer[idx])
    {
        zBuffer[idx] = ooz;
        buffer[idx] = ch;
    }
}

int main()
{
    // Clear terminal
    cout << "\x1b[2J";

    while (true)
    {
        // Clear frame buffer and depth buffer
        memset(buffer, backgroundASCIICode, width * height);
        memset(zBuffer, 0, width * height * sizeof(double));

        double halfHeight = pyramidHeight / 2.0;

        // Generate pyramid surface
        for (double i = -halfHeight; i <= halfHeight; i += 0.10)
        {
            double span = pyramidBaseWidth * (halfHeight - i) / pyramidHeight;

            for (double j = -span; j <= span; j += 0.10)
            {
                // Four pyramid faces
                calculateForPoint(i, j, -span, ';');
                calculateForPoint(i, j,  span, '!');
                calculateForPoint(i,  span, j, '&');
                calculateForPoint(i, -span, j, '%');
            }
        }

        // Move cursor to top-left
        cout << "\x1b[H";

        // Draw frame buffer
        for (int k = 0; k < width * height; ++k)
            putchar(k % width ? buffer[k] : '\n');

        // Rotate pyramid
        A += 0.2;
    }
}
