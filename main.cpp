#include "Game.h"
int main()
{
    Game *game = new Game;
    while (true)
    {
        if (game->run())
        {
            delete game;
            game = new Game;
            system("pause");
        }
    }
}