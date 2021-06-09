#include "Game.hpp"

#include <iostream>

void Game::Print(bool _PrintOnce, bool IsFunc, std::string _Print)
{
    if(DoPrint)
    {
        if(_PrintOnce) PrintOnce(IsFunc, _Print);

        else
        {
            if(IsFunc) std::cout << "\n\n" << _Print << " -------------------------------------------------" << "\n\n";
            else std::cout << _Print << "\n";
        }
    }
}
