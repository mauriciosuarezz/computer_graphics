// graphics.h for WinBGIm
#ifndef _GRAPHICS_H
#define _GRAPHICS_H

#include <windows.h>
#include <limits.h>
#include <sstream>

enum graphics_errors {
    grOk = 0,
    grNoInitGraph = -1,
    grNotDetected = -2,
    grFileNotFound = -3,
    grInvalidDriver = -4,
    grNoLoadMem = -5,
    grNoScanMem = -6,
    grNoFloodMem = -7,
    grFontNotFound = -8,
    grNoFontMem = -9,
    grInvalidMode = -10,
    grError = -11,
    grIOerror = -12,
    grInvalidFont = -13,
    grInvalidFontNum = -14,
    grInvalidDeviceNum = -15,
    grInvalidFontHeight = -16
};

enum colors {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
    LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE
};

#define DETECT 0

#ifdef __cplusplus
extern "C" {
#endif

void initgraph(int *graphdriver, int *graphmode, const char *pathtodriver);
void initwindow(int width, int height, const char* title = "Windows BGI", int left = 0, int top = 0, bool dbflag = false, bool closeflag = true);
void closegraph();
void putpixel(int x, int y, int color);
void bar(int left, int top, int right, int bottom);
void delay(int msec);
int getmaxx();
int getmaxy();
int getmaxwidth();
int getmaxheight();

#ifdef __cplusplus
}
#endif

#endif