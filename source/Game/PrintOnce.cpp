#include "Game.hpp"

#include <iostream>
#include <vector>
#include <string>

void Game::PrintOnce(bool IsFunc, std::string _Print)
{
    if(PrintOnceList.size() == 0)
    {
        PrintOnceList.push_back(_Print);
        if(IsFunc) std::cout << "\n\n" << _Print << " -------------------------------------------------" << "\n\n";
        else std::cout << _Print << "\n";
    }
    else
    {
        for(signed int i = 0; i < PrintOnceList.size(); i++)
        {
            if(_Print == PrintOnceList[i])
            {
                break;
            }
            else
            {
                if(i + 1 == PrintOnceList.size())
                {
                    PrintOnceList.push_back(_Print);
                    if(IsFunc) std::cout << "\n\n" << _Print << " -------------------------------------------------" << "\n\n";
                    else std::cout << _Print << "\n";
                }
            }
        }
    }
}
