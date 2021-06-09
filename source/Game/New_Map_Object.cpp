/*************************************************************************************************************
* MDJ PROJECTS                                                                                               *
* Programmed by Martin De Jonge                                                                              *
* Last Modified - 8 June 2021                                                                                *
*                                                                                                            *
* Purpose:                                                                                                   *
* To create new copies of Data::Map_Objects and add it to the Data::Level_Vector                             *
*************************************************************************************************************/

#include "Game.hpp"
#include "Data.hpp"
#include <string>

void Game::New_Map_Object(std::string Copy_From)
{
    Data data;
    Data::Map_Objects mobj;
    data.Level_Vector[0].Map_Objects.push_back(mobj);
    int index = data.Level_Vector[0].Map_Objects.size() - 1;

    data.Level_Vector[0].Map_Objects[index].VariableName = "Copy object from " + Copy_From;
    data.Level_Vector[0].Map_Objects[index].VariableData = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].VariableData;

    data.Level_Vector[0].Map_Objects[index].Name = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].Name + "_" + std::to_string(index);
    data.Level_Vector[0].Map_Objects[index].Texture = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].Texture;
    data.Level_Vector[0].Map_Objects[index].Death_Fx = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].Death_Fx;
    data.Level_Vector[0].Map_Objects[index].SoundIdle = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].SoundIdle;
    data.Level_Vector[0].Map_Objects[index].ScaleX = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].ScaleX;
    data.Level_Vector[0].Map_Objects[index].ScaleY = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].ScaleY;

    data.Level_Vector[0].Map_Objects[index].texture.loadFromFile(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Level_Vector[0].Map_Objects[index].Texture)].texture_Path);
    data.Level_Vector[0].Map_Objects[index].sprite.setTexture(data.Level_Vector[0].Map_Objects[index].texture);

    data.Level_Vector[0].Map_Objects[index].sprite_IntRect.left = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].sprite_IntRect.left;
    data.Level_Vector[0].Map_Objects[index].sprite_IntRect.top = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].sprite_IntRect.top;
    data.Level_Vector[0].Map_Objects[index].sprite_IntRect.width = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].sprite_IntRect.width;
    data.Level_Vector[0].Map_Objects[index].sprite_IntRect.height = data.Map_Objects_Vector[Load(__func__, __LINE__, "Map_Objects", Copy_From)].sprite_IntRect.height;
    data.Level_Vector[0].Map_Objects[index].sprite.setTextureRect(data.Level_Vector[0].Map_Objects[index].sprite_IntRect);

    data.Level_Vector[0].Map_Objects[index].sprite.setScale(data.Level_Vector[0].Map_Objects[index].ScaleX, data.Level_Vector[0].Map_Objects[index].ScaleY);

    //idle

    Data::Sound new_sound;
    data.Level_Vector[0].Map_Objects[index].Sound.push_back(new_sound);

    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].VariableName
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].VariableName;

    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].VariableData
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].VariableData;

    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].Name
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].Name;

    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].sound_Path
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].sound_Path;

    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].start_time
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].start_time;

    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].end_time
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].end_time;

    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].Sound_Radius
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].Sound_Radius;

    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].buffer.loadFromFile(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].sound_Path);
    data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].sound.setBuffer(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].buffer);

    for(int x = 0; x < 10; x++)
    {
        int Sound_Radius_half = data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].Sound_Radius / 2;

        sf::RectangleShape _SoundBox;
        _SoundBox.setFillColor(sf::Color::Transparent);
        _SoundBox.setOutlineThickness(1);

        _SoundBox.setSize(sf::Vector2f(data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].Sound_Radius + (Sound_Radius_half * x),
                                       data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].Sound_Radius + (Sound_Radius_half * x)));

        if(Game_Show_Sound_Boxes) _SoundBox.setOutlineColor(sf::Color(0 + (10 * x), 100, 0 + (10 * x),255));
        else _SoundBox.setOutlineColor(sf::Color::Transparent);;

        data.Level_Vector[0].Map_Objects[index].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Level_Vector[0].Map_Objects[index].SoundIdle)].Sound_Area.push_back(_SoundBox);
    }
}
