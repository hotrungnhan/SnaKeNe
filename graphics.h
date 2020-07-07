#pragma once
#include <cstdlib>
#include <windows.h>
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
enum key
{
    KEY_UP = 72,
    KEY_DOWN = 80,
    KEY_LEFT = 75,
    KEY_RIGHT = 77
};
void gotoXY(int x, int y)
{
    CursorPosition.X = x;                              // Locates column
    CursorPosition.Y = y;                              // Locates Row
    SetConsoleCursorPosition(console, CursorPosition); // Sets position for next thing to be printed
}