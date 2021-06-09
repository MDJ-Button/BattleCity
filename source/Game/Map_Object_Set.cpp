#include "Game.hpp"
#include "Data.hpp"

void Game::Map_Object_Set()
{
    Data data;
    for(int i = 0; i < data.Map_Objects_Vector.size(); i++)
    {
        if(!TerminateApplication) data.Map_Objects_Vector[i].texture.loadFromFile(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Map_Objects_Vector[i].Texture)].texture_Path);
        if(!TerminateApplication) data.Map_Objects_Vector[i].sprite.setTexture(data.Map_Objects_Vector[i].texture);

        if(!TerminateApplication) data.Map_Objects_Vector[i].sprite_IntRect.left   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Map_Objects_Vector[i].Texture)].TextureRect_L;
        if(!TerminateApplication) data.Map_Objects_Vector[i].sprite_IntRect.top    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Map_Objects_Vector[i].Texture)].TextureRect_T;
        if(!TerminateApplication) data.Map_Objects_Vector[i].sprite_IntRect.width  = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Map_Objects_Vector[i].Texture)].TextureRect_W;
        if(!TerminateApplication) data.Map_Objects_Vector[i].sprite_IntRect.height = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Map_Objects_Vector[i].Texture)].TextureRect_H;
        if(!TerminateApplication) data.Map_Objects_Vector[i].sprite.setTextureRect(data.Map_Objects_Vector[i].sprite_IntRect);

        if(!TerminateApplication) data.Map_Objects_Vector[i].sprite.setScale(data.Map_Objects_Vector[i].ScaleX, data.Map_Objects_Vector[i].ScaleY);

        //Sound------------------------------------------------------------


        //idle

        data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].VariableName
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Map_Objects_Vector[i].SoundIdle)].VariableName;

        data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].VariableData
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Map_Objects_Vector[i].SoundIdle)].VariableData;

        data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].sound_Path
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Map_Objects_Vector[i].SoundIdle)].sound_Path;

        data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].start_time
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Map_Objects_Vector[i].SoundIdle)].start_time;

        data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].end_time
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Map_Objects_Vector[i].SoundIdle)].end_time;

        data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].Sound_Radius
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Map_Objects_Vector[i].SoundIdle)].Sound_Radius;

        data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].buffer.loadFromFile(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Map_Objects_Vector[i].SoundIdle)].sound_Path);
        data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].sound.setBuffer(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Map_Objects_Vector[i].SoundIdle)].buffer);

        for(int x = 0; x < 10; x++)
        {
            int Sound_Radius_half = data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].Sound_Radius / 2;

            sf::RectangleShape _SoundBox;
            _SoundBox.setFillColor(sf::Color::Transparent);
            _SoundBox.setOutlineThickness(1);

            _SoundBox.setSize(sf::Vector2f(data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].Sound_Radius + (Sound_Radius_half * x),
                                           data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].Sound_Radius + (Sound_Radius_half * x)));

            if(Game_Show_Sound_Boxes) _SoundBox.setOutlineColor(sf::Color(0 + (10 * x), 100, 0 + (10 * x),255));
            else _SoundBox.setOutlineColor(sf::Color::Transparent);;

            data.Map_Objects_Vector[i].Sound[Load(__func__, __LINE__, "Map_Objects_Sounds", data.Map_Objects_Vector[i].SoundIdle)].Sound_Area.push_back(_SoundBox);
        }
    }
}
