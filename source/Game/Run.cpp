#include "Game.hpp"

#include <iostream>

void Game::Run(bool _Run)
{
    Print(false, true, Func_Open("Game", "Run"));

    if(_Run)
    {
        Print(false, false, Statement("if", "_Run", "true"));
        Loop(Builder_Enable);
    }
    else Print(false, false,Statement("else", "_Run", "false"));

    if(!TerminateApplication && PrintVectors)
    {
        Print(false, false, Statement("if", "PrintVectors", "true"));
        PrintVector("PrintOnceList");
        PrintVector("Data");
    }
    else Print(false, false,Statement("else", "PrintVectors", "false"));

    Print(false, true, Func_Close("Game", "Run"));
}
