#pragma once
#include <cstdlib>
#include <windows.h>
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y)
{
    CursorPosition.X = x;                              // Locates column
    CursorPosition.Y = y;                              // Locates Row
    SetConsoleCursorPosition(console, CursorPosition); // Sets position for next thing to be printed
}