#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <thread>
#include <chrono>

using namespace std;


double A, B, C = 1.57;
const int pyramidBaseWidth = 40, pyramidHeight = 45;
const int width = 70, height = 33;

char buffer[width * height];
double zBuffer[width * height];
const int backgroundASCIICode = ' ';

double x, y, z;

const int K1 = 60;
const int camDistance = 200;
int xp, yp;
double ooz;
size_t idx;


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
    ooz = 1/z;

    xp = (width/2 + K1 * ooz * x * 2);
    yp = (height/2 + K1 * ooz * y);
    idx = xp + (yp * width);

    if ( ooz > zBuffer[idx] )
    {
        zBuffer[idx] = ooz;
        buffer[idx] = ch;
    }
}



int main()     
{
    cout << "\x1b[2J";
    while (true)
    {
        memset(buffer, backgroundASCIICode, width * height);
        memset(zBuffer, 0.0, width * height * sizeof(double));
        
        double yCoord = pyramidHeight/2;
        double xCoord = pyramidBaseWidth/2;

        for (double i = -yCoord; i <= yCoord; i += 0.10)
        {
            double span = pyramidBaseWidth * (yCoord - i) / pyramidHeight;
            for (double j = -span; j <= span; j += 0.10)
            {
                calculateForPoint(i, j, -span, ';');
                calculateForPoint(i, j, span, '!');
                calculateForPoint(i, span, j, '&');
                calculateForPoint(i, -span, j, '%');
            }
        }

        cout << "\x1b[H";
        for (int k = 0; k < width * height; ++k)
        {
            putchar(k % width ? buffer[k] : 10);
        }

        A += 0.2;
        B += 0.0;
        C += 0.0;

        // this_thread::sleep_for(chrono::microseconds(1));

    }
    

}