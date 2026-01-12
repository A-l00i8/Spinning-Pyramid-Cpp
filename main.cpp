#include <iostream>
#include <cmath>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

double A, B, C; // angle rotations 
const int pyramidHeight = 35, pyramidBase = 30;
const int width = 100, height = 55;

int backgroundASCIICode = ' ';
char buffer[width * height];
double zBuffer[width * height];

double x, y, z;
int camDistance = 130;
int K1 = 70;
double ooz;

int xp, yp;
int idx;

double calculateX(double i, double j, double k)
{
    return j*sin(A)*sin(B)*cos(C) 
           - k*cos(A)*sin(B)*cos(C) 
           + j*cos(A)*sin(C) 
           + k*sin(A)*sin(C) 
           + i*cos(B)*cos(C); 
}

double calculateY(double i, double j, double k)
{
    return j*cos(A)*cos(C) 
           + k*sin(A)*cos(C) 
           - j*sin(A)*sin(B)*sin(C) 
           + k*cos(A)*sin(B)*sin(C) 
           - i*cos(B)*sin(C);   
}

double calculateZ(double i, double j, double k)
{
    return k*cos(A)*cos(B) 
           - j*sin(A)*cos(B) 
           + i*sin(B);
}

void calculateForPoint(double i, double j, double k, int ch) 
{
    x = calculateX(i, j, k);
    y = calculateY(i, j, k);
    z = calculateZ(i, j, k) + camDistance;
    ooz = 1 / z; // efficient

    xp = (width / 2  + K1 * ooz * x * 2);
    yp = (height / 2 + K1 * ooz * y);

    idx = xp + (yp * width);
    if (idx >= 0 && idx < width * height)
    {
        if (ooz > zBuffer[idx])
        {
            zBuffer[idx] = ooz;
            buffer[idx]  = ch; 
        }
    }
}

int main() {
    cout << "\x1b[2J"; // clear the terminal
    while (true)
    {
        memset(buffer, backgroundASCIICode, width * height * sizeof(char));
        memset(zBuffer, 0, width * height * sizeof(double));
        
        double axisYCoord = pyramidHeight/2;
        double axisXCoord = pyramidBase/2;

        for (double i = -axisYCoord; i <= axisYCoord; i += 0.15)
        {
            double span = (axisXCoord * (axisYCoord - i ) / pyramidHeight);
            for (double j = -span; j <= span; j += 0.15)
            {
                calculateForPoint(i, j, -span, '@');
                calculateForPoint(i, j, span, '$');
                calculateForPoint(i, -span, j, '&');
                calculateForPoint(i, span, j, '!');
            }
        }

        for (double j = -axisXCoord; j <= axisXCoord; j += 0.15)
        {
            for (double k = -axisXCoord; k < axisXCoord; k += 0.15)
            {
                calculateForPoint(-axisYCoord, j, k, '#');
            }
        }


        cout << "\x1b[H";
        for (int k = 0; k < width * height; ++k)
        {
            putchar(k % width ? buffer[k] : 10); // prints new line when end of row
        }
        cout << endl; // flush the buffer

        A += 0.05;
        B += 0.05;
        C += 0.01;
        this_thread::sleep_for(chrono::microseconds(8000 * 2));
    }
    
    return 0;
}