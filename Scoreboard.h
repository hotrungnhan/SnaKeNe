#pragma once
#include <stdio.h>
#include "Point.h"
#include "graphics.h"
#include "Wall.h"
class Scoreboard
{
    Point topleft;
    Point bottomright;
    int point = 0;

public:
    Scoreboard(Wall wall, int hoz = 10)
    {
        topleft.set(wall.bottomright.x + 1, wall.topleft.y);
        bottomright.set(wall.bottomright.x + 1 + hoz, wall.bottomright.y);
    }
    Scoreboard operator++(int)
    {
        point++;
        return *this;
    }
    operator int()
    {
        return point;
    }
    void drawborder()
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
    void drawPoint()
    {
        //text;
        Point text;
        text = (topleft + bottomright) / 2;
        gotoXY(text.x, text.y);
        printf("%d", point);
        gotoXY(bottomright.x + 1, bottomright.y + 1);
    }
};