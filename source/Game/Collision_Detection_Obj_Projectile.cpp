/*************************************************************************************************************
* MDJ PROJECTS                                                                                               *
* Programmed by Martin De Jonge                                                                              *
* Last Modified - 8 June 2021                                                                                *
*                                                                                                            *
* Purpose:                                                                                                   *
* To check if a projectile collided with a index from Data::Level::Objects                                   *
*************************************************************************************************************/

#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <iomanip>

void Game::Collision_Detection_Obj_Projectile(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2)
{
    Data data;

    if(Debug)
    {
        if(DebugObject_1 >= 0)
        {
            std::cout << "DebugObject_1 = "
                      << "MovementSpeedX " << data.Level_Vector[0].Objects[DebugObject_1].MovementSpeedX << ","
                      << "MovementSpeedY " << data.Level_Vector[0].Objects[DebugObject_1].MovementSpeedY << ","
                      << "MovementSpeed "  << data.Level_Vector[0].Objects[DebugObject_1].MovementSpeed << ","
                      << "Collided_Up "    << data.Level_Vector[0].Objects[LoopNumber].Collided << "\n";
        }

        if(DebugObject_2 >= 0)
        {
            std::cout << "DebugObject_2 = "
                      << "MovementSpeedX " << data.Level_Vector[0].Objects[DebugObject_2].MovementSpeedX << ","
                      << "MovementSpeedY " << data.Level_Vector[0].Objects[DebugObject_2].MovementSpeedY << ","
                      << "MovementSpeed "  << data.Level_Vector[0].Objects[DebugObject_2].MovementSpeed << ","
                      << "Collided "       << data.Level_Vector[0].Objects[LoopNumber].Collided << "\n";
        }
    }

    for(int i = 0; i < data.Projectile_Vector.size(); i++)
    {
        if(data.Level_Vector[0].Objects[LoopNumber].sprite.getGlobalBounds().intersects(data.Projectile_Vector[i].sprite.getGlobalBounds()))
        {
            Create_FX(Game_Show_Sound_Boxes,
                      data.Level_Vector[0].Objects[LoopNumber].Name,
                      data.Fx_Vector[Load(__func__, __LINE__, "Fx", data.Level_Vector[0].Objects[LoopNumber].Death_Fx)].Name,
                      data.Level_Vector[0].Objects[LoopNumber].sprite.getGlobalBounds().width,
                      data.Level_Vector[0].Objects[LoopNumber].sprite.getGlobalBounds().height,
                      data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().x,
                      data.Level_Vector[0].Objects[LoopNumber].sprite.getPosition().y);

            Remove_Obj_From_Map("Level_Objects", LoopNumber, -2000, -2000);
            Remove_Obj_From_Vector("Projectile_Vector", i);
        }
    }
}
