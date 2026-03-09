#include <graphics.h>
#include <math.h>
#include <stdio.h>

// Bresenham's Function for line generation
void bresenham(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    
    // Advancement directions
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    
    // Initial decision parameter
    int err = dx - dy;

    while (true) {
        putpixel(x0, y0, WHITE);

        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
        delay(10); // Visualization delay
    }
}

// Driver program
int main() {
    initwindow(getmaxwidth(), getmaxheight(), "Bresenham Line Generation Master");

    // Test coordinates
    int x0 = 500, y0 = 400, x1 = 100, y1 = 100;

    // Function call
    bresenham(x0, y0, x1, y1);

    printf("Bresenham line drawing complete.\n");
    system("pause");
    return 0;
}
