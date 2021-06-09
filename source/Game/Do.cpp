#include "Game.hpp"
#include "File.hpp"
#include "Data.hpp"

void Game::Do(std::string This)
{
    Print(false, true, Func_Open("Game", "Do"));

    std::cout << "This " << This;

    Print(false, true, Func_Close("Game", "Do"));
}


