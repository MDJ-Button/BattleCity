/*************************************************************************************************************
* MDJ PROJECTS                                                                                               *
* Programmed by Martin De Jonge                                                                              *
* Last Modified - 8 June 2021                                                                                *
*                                                                                                            *
* Purpose:                                                                                                   *
* Function to check all Data::Level::Objects related collusions                                              *
*************************************************************************************************************/

#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <iomanip>

void Game::Collision_Detection(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2)
{
    Collision_Detection_Obj_Obj(LoopNumber, Debug, DebugObject_1, DebugObject_2);
    Collision_Detection_Obj_MapObj(LoopNumber, Debug, DebugObject_1, DebugObject_2);
    Collision_Detection_Obj_Projectile(LoopNumber, Debug, DebugObject_1, DebugObject_2);
}
