/*************************************************************************************************************
* MDJ PROJECTS                                                                                               *
* Programmed by Martin De Jonge                                                                              *
* Last Modified - 8 June 2021                                                                                *
*                                                                                                            *
* Purpose:                                                                                                   *
* Updates the Data::Level::Objects textures / plays the animations, requires a overhaul with a new animation *
* system                                                                                                     *
*************************************************************************************************************/

#include "Game.hpp"
#include "Data.hpp"
#include "Events.hpp"

#include <iostream>
#include <windows.h>

#include <SFML/Graphics.hpp>

void Game::Update_Textures(int LoopNumber)
{
    Data data;

    Print(true, true, Func_Open("Game", "Update_Textures"));

    if(data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[LoopNumber].Name)].MovementSpeedY < 0)
    {
        //std::cout << "\n\nTexture Y < 0";
        if(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Direction == "L")
        {
            //std::cout << " L";
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top      = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Row;
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.width    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Width;
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.height   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Height;

            if(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left
            >= data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Reset)
            {
                data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Restart;
            }
            else data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left += data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Add;
        }

        else if(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Direction == "T")
        {
           //std::cout << " T";
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Row;

            if(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top
            >= data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Reset)
            {
                data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Restart;
            }
            else data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top += data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Add;
        }

        else
        {
            std::string error; error = "Expected 'L or T' in @Animation_Move_Up:\"(#, #, #, #);\" for texture " + data.Level_Vector[0].Objects[LoopNumber].Texture + " got " + data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Direction;
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
        }
    }

    else if(data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[LoopNumber].Name)].MovementSpeedY > 0)
    {
        //std::cout << "\n\nTexture Y > 0";
        if(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Direction == "L")
        {
            //std::cout << " L";
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top      = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Row;
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.width    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Width;
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.height   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Height;

            if(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left
            >= data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Reset)
            {
                data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Restart;
            }
            else data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left += data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Add;
        }

        else if(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Direction == "T")
        {
            //std::cout << " T";
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Row;

            if(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top
            >= data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Reset)
            {
                data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Restart;
            }
            else data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top += data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Down_Add;
        }

        else
        {
            std::string error; error = "Expected 'L or T' in @Animation_Move_Up:\"(#, #, #, #);\" for texture " + data.Level_Vector[0].Objects[LoopNumber].Texture + " got " + data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Direction;
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
        }
    }

    else if(data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[LoopNumber].Name)].MovementSpeedX < 0)
    {
        //std::cout << "\n\nTexture X < 0";
        if(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Direction == "L")
        {
            //std::cout << " L";
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top      = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Row;
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.width    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Width;
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.height   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Height;

            if(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left
            >= data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Reset)
            {
                data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Restart;
            }
            else data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left += data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Add;
        }

        else if(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Direction == "T")
        {
            //std::cout << " T";
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Row;

            if(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top
            >= data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Reset)
            {
                data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Restart;
            }
            else data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top += data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Left_Add;
        }

        else
        {
            std::string error; error = "Expected 'L or T' in @Animation_Move_Up:\"(#, #, #, #);\" for texture " + data.Level_Vector[0].Objects[LoopNumber].Texture + " got " + data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Direction;
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
        }
    }

    else if(data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[LoopNumber].Name)].MovementSpeedX > 0)
    {
        //std::cout << "\n\nTexture X > 0";
        if(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Direction == "L")
        {
            //std::cout << " L";
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top      = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Row;
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.width    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Width;
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.height   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Height;

            if(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left
            >= data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Reset)
            {
                data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Restart;
            }
            else data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.left += data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Add;
        }

        else if(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Direction == "T")
        {
            //std::cout << " T";
            data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Row;

            if(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top
            >= data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Reset)
            {
                data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Restart;
            }
            else data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect.top += data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Right_Add;
        }

        else
        {
            std::string error; error = "Expected 'L or T' in @Animation_Move_Up:\"(#, #, #, #);\" for texture " + data.Level_Vector[0].Objects[LoopNumber].Texture + " got " + data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Objects[LoopNumber].Texture)].Animation_Move_Up_Direction;
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
        }
    }

    data.Level_Vector[0].Objects[LoopNumber].sprite.setTextureRect(data.Level_Vector[0].Objects[LoopNumber].sprite_IntRect);

    Print(true, true, Func_Close("Game", "Update_Textures"));
}



