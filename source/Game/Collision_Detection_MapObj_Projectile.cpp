/*************************************************************************************************************
* MDJ PROJECTS                                                                                               *
* Programmed by Martin De Jonge                                                                              *
* Last Modified - 8 June 2021                                                                                *
*                                                                                                            *
* Purpose:                                                                                                   *
* To check if a project collided with a map object, note it only counts toward the level vector's map object,*
* Data::Map_Objects is only used for storing single copies to be added to the level.                         *
*************************************************************************************************************/

#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <iomanip>

void Game::Collision_Detection_MapObj_Projectile(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2)
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
                      << "Collided_Up "    << data.Objects_Vector[LoopNumber].Collided << "\n";
        }

        if(DebugObject_2 >= 0)
        {
            std::cout << "DebugObject_2 = "
                      << "MovementSpeedX " << data.Objects_Vector[DebugObject_2].MovementSpeedX << ","
                      << "MovementSpeedY " << data.Objects_Vector[DebugObject_2].MovementSpeedY << ","
                      << "MovementSpeed "  << data.Objects_Vector[DebugObject_2].MovementSpeed << ","
                      << "Collided "       << data.Objects_Vector[LoopNumber].Collided << "\n";
        }
    }

    for(int i = 0; i < data.Projectile_Vector.size(); i++)
    {
        if(data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getGlobalBounds().intersects(data.Projectile_Vector[i].sprite.getGlobalBounds()))
        {
            Create_FX(Game_Show_Sound_Boxes,
                      data.Level_Vector[0].Map_Objects[LoopNumber].Name,
                      data.Fx_Vector[Load(__func__, __LINE__, "Fx", data.Level_Vector[0].Map_Objects[LoopNumber].Death_Fx)].Name,
                      data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getGlobalBounds().width,
                      data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getGlobalBounds().height,
                      data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getPosition().x,
                     data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getPosition().y);



            if(data.Projectile_Vector[i].Direction == Data::Projectile::enumDirection::up)
            {
                data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.height = data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.height
                                                                                   - data.Level_Vector[0].Map_Objects[LoopNumber].Destroy;
            }

            else if(data.Projectile_Vector[i].Direction == Data::Projectile::enumDirection::down)
            {
                data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.top = data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.top
                                                                       + data.Level_Vector[0].Map_Objects[LoopNumber].Destroy;

                data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.height = data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.height
                                                                          - data.Level_Vector[0].Map_Objects[LoopNumber].Destroy;

                data.Level_Vector[0].Map_Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getPosition().x,
                                                                       data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getPosition().y
                                                                       + data.Level_Vector[0].Map_Objects[LoopNumber].Destroy *3);
            }

            else if(data.Projectile_Vector[i].Direction == Data::Projectile::enumDirection::left)
            {
                data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.width = data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.width
                                                                         - data.Level_Vector[0].Map_Objects[LoopNumber].Destroy;
            }

            else if(data.Projectile_Vector[i].Direction == Data::Projectile::enumDirection::right)
            {
                data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.left = data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.left
                                                                        + data.Level_Vector[0].Map_Objects[LoopNumber].Destroy;

                data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.width = data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect.width
                                                                         - data.Level_Vector[0].Map_Objects[LoopNumber].Destroy;

                data.Level_Vector[0].Map_Objects[LoopNumber].sprite.setPosition(data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getPosition().x
                                                                       + data.Level_Vector[0].Map_Objects[LoopNumber].Destroy *3,
                                                                       data.Level_Vector[0].Map_Objects[LoopNumber].sprite.getPosition().y);
            }

            data.Level_Vector[0].Map_Objects[LoopNumber].sprite.setTextureRect(data.Level_Vector[0].Map_Objects[LoopNumber].sprite_IntRect);

            //Remove_Obj_From_Map("Map_Objects_Vector", LoopNumber, -1000, -1000);
            Remove_Obj_From_Vector("Projectile_Vector", i);
        }
    }
}
