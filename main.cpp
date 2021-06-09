#include "Game.hpp"
#include "File.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    File file;
    file.Read("config.txt", "Config", false, 0);
    Game game;
    game.Print(false, true, __func__);
    game.Run(true);
    game.Print(false, true, __func__);
    return 0;
}
