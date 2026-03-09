#include <graphics.h>
#include <math.h>
#include <stdio.h>

// DDA Function for line generation
void DDA(int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
        putpixel((int)(X + 0.5), (int)(Y + 0.5), RED);
        
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
        delay(10); // reduced delay for single pixels
    }
}

// Driver program
int main()
{
    initwindow(getmaxwidth(), getmaxheight(), "DDA Line Generation");

    // Revert to larger coordinates for original pixel view
    int X0 = 100, Y0 = 100, X1 = 500, Y1 = 400;

    // Function call
    DDA(X0, Y0, X1, Y1);
    
    printf("Line drawing complete.\n");
    system("pause");
    return 0;
}