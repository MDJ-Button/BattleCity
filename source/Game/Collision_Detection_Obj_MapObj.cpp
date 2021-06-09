/*************************************************************************************************************
* MDJ PROJECTS                                                                                               *
* Programmed by Martin De Jonge                                                                              *
* Last Modified - 8 June 2021                                                                                *
*                                                                                                            *
* Purpose:                                                                                                   *
* To check if a object collided with a map object, note it only counts toward the level vector's map object  *
* and the level vector's object, Data::Map_Objects and Data::Objects is only used for storing single copies  *
* to be added to the level.                                                                                  *
*************************************************************************************************************/

#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <iomanip>

void Game::Collision_Detection_Obj_MapObj(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2)
{
    Data data;

    if(Debug)
    {
        if(DebugObject_1 >= 0)
        {
            std::cout << "DebugObject_1 = "
                      << "MovementSpeedX " << data.Objects_Vector[DebugObject_1].MovementSpeedX << ","
                      << "MovementSpeedY " << data.Objects_Vector[DebugObject_1].MovementSpeedY << ","
                      << "MovementSpeed "  << data.Objects_Vector[DebugObject_1].MovementSpeed << ","
                      << "Collided "       << data.Level_Vector[0].Objects[LoopNumber].Collided << "\n";
        }

        if(DebugObject_2 >= 0)
        {
            std::cout << "DebugObject_2 = "
                      << "MovementSpeedX " << data.Objects_Vector[DebugObject_2].MovementSpeedX << ","
                      << "MovementSpeedY " << data.Objects_Vector[DebugObject_2].MovementSpeedY << ","
                      << "MovementSpeed "  << data.Objects_Vector[DebugObject_2].MovementSpeed << ","
                      << "Collided_Up "    << data.Level_Vector[0].Objects[LoopNumber].Collided << "\n";
        }
    }

    for(int x = 0; x < data.Level_Vector[0].Map_Objects.size(); x++)
    {
        if(data.Level_Vector[0].Objects[LoopNumber].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Map_Objects[x].sprite.getGlobalBounds()))
        {
            if(Debug) std::cout << " HIT BLOCK\n";

            if(data.Level_Vector[0].Objects[LoopNumber].MovementSpeedY < 0)
            {
                data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_up;
                data.Level_Vector[0].Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x,
                                                                            data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y + 4);
            }
            else if(data.Level_Vector[0].Objects[LoopNumber].MovementSpeedY > 0)
            {
                data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_down;
                data.Level_Vector[0].Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x,
                                                                            data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y - 4);
            }
            else if(data.Level_Vector[0].Objects[LoopNumber].MovementSpeedX > 0)
            {
                data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_left;
                data.Level_Vector[0].Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x - 4,
                                                                            data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y);
            }
            else if(data.Level_Vector[0].Objects[LoopNumber].MovementSpeedX < 0)
            {
                data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_right;
                data.Level_Vector[0].Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x + 4,
                                                                            data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y);
            }
        }

        else
        {
            data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_none;
        }
    }
}
