#pragma once
#include "Point.h"
#include "Wall.h"
#include "graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
class Food
{
    Point pos;
    friend class Snake;

public:
    Food(const Wall &wall)
    {
        srand(time(NULL));
        pos.set(rand() % int(wall.bottomright.x + wall.topleft.x - 1) + 1, rand() % int(wall.bottomright.y + wall.topleft.y - 1) + 1);
    }
    void draw()
    {
        gotoXY(pos.x, pos.y);
        // printf("O");
    }
};