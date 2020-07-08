#pragma once
#include <stdio.h>
#include <conio.h>
#include <vector>
#include "Point.h"
#include "graphics.h"
#include "Wall.h"
#include "Food.h"
using namespace std;
enum snakeMoveState
{
    up,
    down,
    left,
    right
};
class Snake
{
    vector<Point> body;
    Point speed;
    int state;
    Point Prevlast;

private:
    Point getHead()
    {
        return body[0];
    };

public:
    Snake(Wall wall)
    {
        Point temp;
        temp.set((wall.bottomright.x + wall.topleft.x) / 2, (wall.bottomright.y + wall.topleft.y) / 2);
        this->speed.set(0, 0);
        body.push_back(temp);
        body.push_back(temp - Point(1, 0));
        body.push_back(temp - Point(2, 0));
        this->keypress('d');
    }
    void keypress(char t)
    {
        if ((state != right && state != left) && (t == 'd' || t == KEY_RIGHT))
        {
            this->speed.set(1, 0);
            state = right;
        }
        if ((state != down && state != up) && (t == 's' || t == KEY_DOWN))
        {
            this->speed.set(0, .5);
            state = down;
        }
        if ((state != right && state != left) && (t == 'a' || t == KEY_LEFT))
        {
            this->speed.set(-1, 0);
            state = left;
        }
        if ((state != down && state != up) && (t == 'w' || t == KEY_UP))
        {
            this->speed.set(0, -.5);
            state = up;
        }
    }
    void draw()
    {
        gotoXY((int)body[0].x, (int)body[0].y);
        printf("%c", '$'); //176
        gotoXY(0, 0);
        for (int i = 1; i < body.size(); i++)
        {
            gotoXY((int)body[i].x, (int)body[i].y);
            printf("%c", 176); //176
        }
        gotoXY(Prevlast.x, Prevlast.y);
        printf("%c", ' ');
        gotoXY(0, 0);
    }
    void update()
    {
        if (!(speed == Point(0, 0)))
        {
            Prevlast = body[body.size() - 1];
            for (int i = body.size() - 1; i > 0; i--)
            { // duong la huong xuong am huong len
                body[i] = body[i - 1];
            }
        }
        body[0] = body[0] + speed;
    }
    bool die(Wall wall)
    {
        if (!(body[0].x > wall.topleft.x && body[0].y - 1 > wall.topleft.y && body[0].x < wall.bottomright.x && body[0].y < wall.bottomright.y))
            return true;
        if (checkCollsionItSelf())
            return true;
        return false;
    }
    bool eat(Food food)
    {
        if (body[0].toInt() == food.pos.toInt())
        {
            Point temp;
            temp = body.back() - speed;
            body.push_back(temp);
            return true;
        }
        return false;
    }
    bool checkCollsionItSelf()
    {
        for (int i = 1; i < body.size(); i++)
        { // duong la huong xuong am huong len
            if (getHead() == body[i])
            {
                return true;
            }
        }
        return false;
    }
};