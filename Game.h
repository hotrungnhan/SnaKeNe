#include "Wall.h"
#include "Food.h"
#include "Scoreboard.h"
#include "Snake.h"
#include <conio.h>

class Game
{
    Wall *wall;
    Snake *snake;
    Food *food;
    Scoreboard *scoreboard;
    int speed = 100;

public:
    Game()
    {
        wall = new Wall();
        snake = new Snake(*wall);
        food = new Food(*wall);
        scoreboard = new Scoreboard(*wall);
    };
    ~Game()
    {
        delete wall;
        delete snake;
        delete food;
        delete scoreboard;
    };
    bool run()
    {
        char t;
        wall->draw();
        scoreboard->drawborder();
        while (true)
        {
            if (kbhit())
            {
                t = getch();
                snake->keypress(t);
            }
            if (snake->eat(*food))
            {
                //spawn food
                (*scoreboard)++;
                scoreboard->drawPoint();
                delete food;
                food = new Food(*wall);
                speed = speed - (int)*scoreboard;
            }
            snake->update();
            snake->draw();
            food->draw();
            if (snake->die(*wall))
            {
                return true;
            }
            Sleep(speed);
        }
    }
};