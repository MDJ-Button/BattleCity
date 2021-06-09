/*************************************************************************************************************
* MDJ PROJECTS                                                                                               *
* Programmed by Martin De Jonge                                                                              *
* Last Modified - 8 June 2021                                                                                *
*                                                                                                            *
* Purpose:                                                                                                   *
* Function to check all collusions between one Data::Level::Objects and another                              *
*************************************************************************************************************/

#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <iomanip>

void Game::Collision_Detection_Obj_Obj(int LoopNumber, bool Debug, int DebugObjects_1, int DebugObjects_2)
{
    Data data;

    if(Debug)
    {
        if(DebugObjects_1 >= 0)
        {
            std::cout << "DebugObjects_1 = "
                      << "MovementSpeedX " << data.Level_Vector[0].Objects[DebugObjects_1].MovementSpeedX << ","
                      << "MovementSpeedY " << data.Level_Vector[0].Objects[DebugObjects_1].MovementSpeedY << ","
                      << "MovementSpeed "  << data.Level_Vector[0].Objects[DebugObjects_1].MovementSpeed << ","
                      << "Collided_Up "    << data.Level_Vector[0].Objects[LoopNumber].Collided << "\n";
        }

        if(DebugObjects_2 >= 0)
        {
            std::cout << "DebugObjects_2 = "
                      << "MovementSpeedX " << data.Level_Vector[0].Objects[DebugObjects_2].MovementSpeedX << ","
                      << "MovementSpeedY " << data.Level_Vector[0].Objects[DebugObjects_2].MovementSpeedY << ","
                      << "MovementSpeed "  << data.Level_Vector[0].Objects[DebugObjects_2].MovementSpeed << ","
                      << "Collided "       << data.Level_Vector[0].Objects[LoopNumber].Collided << "\n";
        }
    }

    for(int i = 0; i < data.Level_Vector[0].Objects.size(); i++)
    {
        if(LoopNumber > i || LoopNumber < i)
        {
            if(data.Level_Vector[0].Objects[LoopNumber].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[i].sprite.getGlobalBounds()))
            {
                if(Debug) std::cout << LoopNumber << " HIT " << i << "\n";

                if(data.Level_Vector[0].Objects[LoopNumber].MovementSpeedY < 0)
                {
                    data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_up;
                    data.Level_Vector[0].Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x,
                                                                                data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y + 5);
                }
                else if(data.Level_Vector[0].Objects[LoopNumber].MovementSpeedY > 0)
                {
                    data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_down;
                    data.Level_Vector[0].Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x,
                                                                                data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y - 5);
                }
                else if(data.Level_Vector[0].Objects[LoopNumber].MovementSpeedX > 0)
                {
                    data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_left;
                    data.Level_Vector[0].Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x - 5,
                                                                                data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y);
                }
                else if(data.Level_Vector[0].Objects[LoopNumber].MovementSpeedX < 0)
                {
                    data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_right;
                    data.Level_Vector[0].Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x + 5,
                                                                                data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y);
                }
            }

            else
            {
                data.Level_Vector[0].Objects[LoopNumber].Collided = Data::Objects::enumCollided::Collided_none;
            }
        }
    }
}
