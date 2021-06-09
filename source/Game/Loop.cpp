#include "Game.hpp"
#include "File.hpp"
#include "Data.hpp"

#include <iostream>
#include <cmath>
#include <windows.h>
#include <iomanip>
#include <algorithm>

#include <chrono>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void Game::Loop(bool builder_enabled)
{
    Print(false, true, Func_Open("Game", "Loop"));

    Read_Game_Data();

    if(!TerminateApplication)
    {
        Set_Game_Data(Game_Show_Sound_Boxes);

        Data data;

        if(Window_Fullscreen) window.create(sf::VideoMode(Window_Size_X, Window_Size_Y), "SFML Window", sf::Style::Fullscreen);
        else                  window.create(sf::VideoMode(Window_Size_X, Window_Size_Y), "SFML window");
        Print(false, false, DataType_Updated("sf::RenderWindow", "window", std::string("create(sf::VideoMode(") + std::to_string(Window_Size_X) + ", " + std::to_string(Window_Size_Y) + "), \"SFML window\")"));

        window.setFramerateLimit(FPS_Limit);
        Print(true, false, DataType_Updated("sf::RenderWindow", "window", "setFramerateLimit(60)"));

        if(Grid_Draw) Grid_Set(false);
        if(Window_ShowFPS) Window_ShowFPS_Set(false);

        //MAP-------------------------------------------------------------------

        for(int i = 0; i < 10; i++)
        {
            New_Map_Object(data.Map_Objects_Vector[0].Name);
        }

        data.Level_Vector[0].Map_Objects[0].sprite.setPosition(400, 200);
        data.Level_Vector[0].Map_Objects[1].sprite.setPosition(0, 0);
        data.Level_Vector[0].Map_Objects[1].sprite.setPosition(450-2, 200);
        data.Level_Vector[0].Map_Objects[2].sprite.setPosition(500-4, 200);
        data.Level_Vector[0].Map_Objects[3].sprite.setPosition(400, 250-2);
        data.Level_Vector[0].Map_Objects[4].sprite.setPosition(400, 300-4);
        data.Level_Vector[0].Map_Objects[5].sprite.setPosition(400, 350-6);
        data.Level_Vector[0].Map_Objects[6].sprite.setPosition(500-4, 300-4);
        data.Level_Vector[0].Map_Objects[7].sprite.setPosition(500-4, 350-6);
        data.Level_Vector[0].Map_Objects[8].sprite.setPosition(500-4, 400-8);
        data.Level_Vector[0].Map_Objects[9].sprite.setPosition(500-4, 400-8);

        //MAP-------------------------------------------------------------------

        //MAP-------------------------------------------------------------------

        for(int i = 0; i < 1; i++)
        {
            New_Object(data.Objects_Vector[0].Name);
        }

        data.Level_Vector[0].Objects[0].sprite.setPosition(0, 0);

        //MAP-------------------------------------------------------------------

        Player_Number = 0;

        //
        Remove_Obj_From_Map("Map_Objects_Vector", 0, 0, 0);

        Remove_Obj_From_Map("Objects_Vector", 0, 0, 0);
        Remove_Obj_From_Map("Objects_Vector", 1, 0, 0);
        Remove_Obj_From_Map("Objects_Vector", 2, 0, 0);
        Remove_Obj_From_Map("Objects_Vector", 3, 0, 0);
        //

        Print(false, false, Loop_Start("while", "window.isOpen()"));
        while(!TerminateApplication && window.isOpen())
        {
            SetFPS();
            Update_Event();

            //for(int i = 0; i < data.Map_Objects_Vector.size(); i++) Collision_Detection_MapObj_Projectile(i, false, -1, -1);

            //for(int i = 0; i < data.Objects_Vector.size(); i++)     Collision_Detection(i, false, -1, -1);
            //for(int i = 0; i < data.Objects_Vector.size(); i++)     Update_ObjectsPositions(i);
            //for(int i = 0; i < data.Objects_Vector.size(); i++)     Update_Textures(i);
            //for(int i = 0; i < data.Objects_Vector.size(); i++)     Play_SoundIdle(i);
            //for(int i = 0; i < data.Objects_Vector.size(); i++)     Play_SoundMove(i);

            for(int i = 0; i < data.Level_Vector[0].Map_Objects.size(); i++) Collision_Detection_MapObj_Projectile(i, false, -1, -1);

            for(int i = 0; i < data.Level_Vector[0].Objects.size(); i++)     Collision_Detection(i, false, -1, -1);
            for(int i = 0; i < data.Level_Vector[0].Objects.size(); i++)     Update_ObjectsPositions(i);
            for(int i = 0; i < data.Level_Vector[0].Objects.size(); i++)     Update_Textures(i);
            for(int i = 0; i < data.Level_Vector[0].Objects.size(); i++)     Play_SoundIdle(i);
            for(int i = 0; i < data.Level_Vector[0].Objects.size(); i++)     Play_SoundMove(i);

            for(int i = 0; i < data.Fx_To_Play_Vector.size(); i++)  Play_Fx(i);
            for(int i = 0; i < data.Fx_To_Play_Vector.size(); i++)  Play_SoundFx(i);

            Update_Window();
        }
    }

    Print(false, false, Loop_Stop("while", "window.isOpen()"));

    Print(false, true, Func_Close("Game", "Loop"));
}
