#pragma once
#include <stdio.h>
#include <conio.h>
#include <vector>
#include "Point.h"
#include "graphics.h"
#include "Wall.h"
#include "Food.h"
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
class Snake
{
    vector<Point> body;
    Point speed;

public:
    Snake(Wall wall)
    {
        Point temp;
        temp.set((wall.bottomright.x + wall.topleft.x) / 2, (wall.bottomright.y + wall.topleft.y) / 2);
        this->speed.set(0, 0);
        body.push_back(temp);
    }
    void keypress(char t)
    {
        if (t == 'd' || t == KEY_RIGHT) //&& !(lastkey == KEY_LEFT || lastkey == 'a'))
            this->speed.set(0.4, 0);
        if (t == 's' || t == KEY_DOWN) //&& !(lastkey == KEY_UP || lastkey == 'w'))
            this->speed.set(0, 0.2);
        if (t == 'a' || t == KEY_LEFT) //&& !(lastkey == KEY_RIGHT || lastkey == 'd'))
            this->speed.set(-0.4, 0);
        if (t == 'w' || t == KEY_UP) // && !(lastkey == KEY_DOWN || lastkey == 's'))
            this->speed.set(0, -0.2);
    }
    void draw()
    {
        for (int i = 0; i < body.size(); i++)
        {
            gotoXY(body[i].x, body[i].y);
            printf("%c", 176);
        }
    }
    void update()
    {
        for (int i = body.size() - 1; i > 0; i--)
        { // duong la huong xuong am huong len
            body[i] = body[i - 1];
        }
        body[0] = body[0] + speed;
    }
    bool die(Wall wall)
    {
        if (!(body[0].x > wall.topleft.x && body[0].y > wall.topleft.x && body[0].x < wall.bottomright.x && body[0].y < wall.bottomright.y))
            return true;
        return false;
    }
    bool eat(Food food)
    {
        if (body[0] == food.pos)
        {
            Point temp;
            temp = body.back() - speed;
            body.push_back(temp);
            return true;
        }
        return false;
    }
};