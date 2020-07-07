#pragma once
#include <stdio.h>
#include "Point.h"
#include "graphics.h"
using namespace std;
class Wall
{
    Point topleft;
    Point bottomright;
    friend class Snake;
    friend class Food;
    friend class Scoreboard;

public:
    Wall()
    {
        topleft.set(0, 0);
        bottomright.set(40, 20);
    }
    void draw()
    {
        //top left conor
        gotoXY(topleft.x, topleft.y);
        printf("%c", 201);
        //top right conor
        gotoXY(bottomright.x, topleft.y);
        printf("%c", 187);
        //bottom right conor
        gotoXY(bottomright.x, bottomright.y);
        printf("%c", 188);
        //bottom left conor
        gotoXY(topleft.x, bottomright.y);
        printf("%c", 200);
        //vertical side
        for (int i = topleft.x + 1; i < bottomright.x; i++)
        {
            gotoXY(i, topleft.y);
            printf("%c", 205);
            gotoXY(i, bottomright.y);
            printf("%c", 205);
        }
        //horizaltal side
        for (int i = topleft.y + 1; i < bottomright.y; i++)
        {
            gotoXY(topleft.x, i);
            printf("%c", 186);
            gotoXY(bottomright.x, i);
            printf("%c", 186);
        }
    }
};