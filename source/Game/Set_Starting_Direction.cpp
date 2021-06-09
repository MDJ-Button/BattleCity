#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <windows.h>

#include <SFML/Graphics.hpp>

void Game::Set_Starting_Direction(int ForObject)
{
    Data data;

    if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[ForObject].Name)].StartingDirection == "UP")
    {
        data.Objects_Vector[ForObject].sprite_IntRect.top      = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Up_Row;
        data.Objects_Vector[ForObject].sprite_IntRect.left     = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Up_Restart;
        data.Objects_Vector[ForObject].sprite_IntRect.width    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Up_Width;
        data.Objects_Vector[ForObject].sprite_IntRect.height   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Up_Height;
    }

    else if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[ForObject].Name)].StartingDirection == "DOWN")
    {
        data.Objects_Vector[ForObject].sprite_IntRect.top      = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Down_Row;
        data.Objects_Vector[ForObject].sprite_IntRect.left     = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Down_Restart;
        data.Objects_Vector[ForObject].sprite_IntRect.width    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Down_Width;
        data.Objects_Vector[ForObject].sprite_IntRect.height   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Down_Height;
    }

    else if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[ForObject].Name)].StartingDirection == "LEFT")
    {
        data.Objects_Vector[ForObject].sprite_IntRect.top      = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Left_Row;
        data.Objects_Vector[ForObject].sprite_IntRect.left     = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Left_Restart;
        data.Objects_Vector[ForObject].sprite_IntRect.width    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Left_Width;
        data.Objects_Vector[ForObject].sprite_IntRect.height   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Left_Height;
    }

    else if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[ForObject].Name)].StartingDirection == "RIGHT")
    {
        data.Objects_Vector[ForObject].sprite_IntRect.top      = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Right_Row;
        data.Objects_Vector[ForObject].sprite_IntRect.left     = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Right_Restart;
        data.Objects_Vector[ForObject].sprite_IntRect.width    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Right_Width;
        data.Objects_Vector[ForObject].sprite_IntRect.height   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[ForObject].Texture)].Animation_Move_Right_Height;
    }

    else
    {
        std::string error; error = "Error, could not set Starting Direction for objects";
        LPCSTR char_error = error.c_str();
        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        TerminateApplication = true;
    }

    data.Objects_Vector[ForObject].sprite.setTextureRect(data.Objects_Vector[ForObject].sprite_IntRect);
}
