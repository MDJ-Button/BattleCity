/*************************************************************************************************************
* MDJ PROJECTS                                                                                               *
* Programmed by Martin De Jonge                                                                              *
* Last Modified - 8 June 2021                                                                                *
*                                                                                                            *
* Purpose:                                                                                                   *
* Updates the Data::Level::Objects positions                                                                 *
*************************************************************************************************************/

#include "Game.hpp"
#include "Data.hpp"
#include "Events.hpp"
#include <windows.h>

#include <iostream>

#include <SFML/Graphics.hpp>

void Game::Update_ObjectsPositions(int LoopNumber)
{
    Data data;

    Print(true, true, Func_Open("Game", "Update_ObjectsPositions"));

    if(data.Level_Vector[0].Objects[Player_Number].State == Data::Objects::enumState::alive)
    {
        Player(Player_Number);
    }
    else Player_Number = data.Level_Vector[0].Objects.size() + 1;

    /*if(data.Level_Vector[0].Objects[0].State == Data::Objects::enumState::alive)
    {
        AI(0, 200, 60);
    }*/

    /*if(data.Level_Vector[0].Objects[1].State == Data::Objects::enumState::alive)
    {
        AI(1, 500, 300);
    }
    //else std::cout << "\n\n1 State = dead";

    if(data.Level_Vector[0].Objects[2].State == Data::Objects::enumState::alive)
    {
        AI(2, 150, 50);
    }
    //else std::cout << "\n\n2 State = dead";

    if(data.Level_Vector[0].Objects[3].State == Data::Objects::enumState::alive)
    {
        AI(3, 200, 50);
    }
    //else std::cout << "\n\n2 State = dead";*/

    for(signed int i = 0; i < data.Projectile_Vector.size(); i++)
    {
        data.Projectile_Vector[i].sprite.move(data.Projectile_Vector[i].MovementSpeedX,
                                              data.Projectile_Vector[i].MovementSpeedY);
    }

    //---------------------
    for(int i = 0; i < data.Level_Vector[0].Objects.size(); i++)
    {
        for(int x = 0; x < data.Level_Vector[0].Objects[i].Sound.size(); x++)
        {
            for(int y = 0; y < data.Level_Vector[0].Objects[i].Sound[x].Sound_Area.size(); y++)
            {
                int Sound_Radius_half = data.Level_Vector[0].Objects[i].Sound[x].Sound_Radius / 2;

                data.Level_Vector[0].Objects[i].Sound[x].Sound_Area[y].setPosition(data.Level_Vector[0].Objects[i].sprite.getPosition().x
                                                                          - data.Level_Vector[0].Objects[i].Sound[x].Sound_Radius / 2
                                                                          + data.Level_Vector[0].Objects[i].sprite.getGlobalBounds().width / 2
                                                                          - Sound_Radius_half / 2 * y,

                                                                          data.Level_Vector[0].Objects[i].sprite.getPosition().y
                                                                          - data.Level_Vector[0].Objects[i].Sound[x].Sound_Radius / 2
                                                                          + data.Level_Vector[0].Objects[i].sprite.getGlobalBounds().height / 2
                                                                          - Sound_Radius_half / 2 * y);
            }
        }
    }
    //---------------------

    Print(true, true, Func_Close("Game", "Update_ObjectsPositions"));
}




