#include "Game.hpp"
#include "Data.hpp"

void Game::Object_Set(bool Game_Show_Sound_Boxes)
{
    Data data;
    for(int i = 0; i < data.Objects_Vector.size(); i++)
    {
        if(!TerminateApplication) data.Objects_Vector[i].texture.loadFromFile(data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[i].Texture)].texture_Path);
        if(!TerminateApplication) data.Objects_Vector[i].sprite.setTexture(data.Objects_Vector[i].texture);

        if(!TerminateApplication) data.Objects_Vector[i].sprite_IntRect.left   = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[i].Texture)].TextureRect_L;
        if(!TerminateApplication) data.Objects_Vector[i].sprite_IntRect.top    = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[i].Texture)].TextureRect_T;
        if(!TerminateApplication) data.Objects_Vector[i].sprite_IntRect.width  = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[i].Texture)].TextureRect_W;
        if(!TerminateApplication) data.Objects_Vector[i].sprite_IntRect.height = data.Textures_Vector[Load(__func__, __LINE__, "Textures", data.Objects_Vector[i].Texture)].TextureRect_H;
        if(!TerminateApplication) data.Objects_Vector[i].sprite.setTextureRect(data.Objects_Vector[i].sprite_IntRect);

        if(!TerminateApplication) data.Objects_Vector[i].sprite.setScale(data.Objects_Vector[i].ScaleX, data.Objects_Vector[i].ScaleY);

        if(!TerminateApplication) data.Objects_Vector[i].MovementSpeedX = 0;
        if(!TerminateApplication) data.Objects_Vector[i].MovementSpeedY = 0;

        //-----------------------------------------------------------------

        data.Objects_Vector[i].State = Data::Objects::enumState::alive;

        data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[i].Name)].StartingDirection = "RIGHT";

        Set_Starting_Direction(i);

        //Sound------------------------------------------------------------


        //idle

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].VariableName
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundIdle)].VariableName;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].VariableData
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundIdle)].VariableData;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].sound_Path
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundIdle)].sound_Path;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].start_time
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundIdle)].start_time;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].end_time
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundIdle)].end_time;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].Sound_Radius
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundIdle)].Sound_Radius;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].buffer.loadFromFile(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundIdle)].sound_Path);
        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].sound.setBuffer(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundIdle)].buffer);

        for(int x = 0; x < 10; x++)
        {
            int Sound_Radius_half = data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].Sound_Radius / 2;

            sf::RectangleShape _SoundBox;
            _SoundBox.setFillColor(sf::Color::Transparent);
            _SoundBox.setOutlineThickness(1);

            _SoundBox.setSize(sf::Vector2f(data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].Sound_Radius + (Sound_Radius_half * x),
                                           data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].Sound_Radius + (Sound_Radius_half * x)));

            if(Game_Show_Sound_Boxes) _SoundBox.setOutlineColor(sf::Color(0 + (10 * x), 100, 0 + (10 * x),255));
            else _SoundBox.setOutlineColor(sf::Color::Transparent);;

            data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundIdle)].Sound_Area.push_back(_SoundBox);
        }

        //move

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].VariableName
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundMove)].VariableName;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].VariableData
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundMove)].VariableData;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].sound_Path
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundMove)].sound_Path;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].start_time
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundMove)].start_time;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].end_time
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundMove)].end_time;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].Sound_Radius
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundMove)].Sound_Radius;

        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].buffer.loadFromFile(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundMove)].sound_Path);
        data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].sound.setBuffer(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Objects_Vector[i].SoundMove)].buffer);

        for(int x = 0; x < 10; x++)
        {
            int Sound_Radius_half = data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].Sound_Radius / 2;

            sf::RectangleShape _SoundBox;
            _SoundBox.setFillColor(sf::Color::Transparent);
            _SoundBox.setOutlineThickness(1);

            _SoundBox.setSize(sf::Vector2f(data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].Sound_Radius + (Sound_Radius_half * x),
                                           data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].Sound_Radius + (Sound_Radius_half * x)));

            if(Game_Show_Sound_Boxes) _SoundBox.setOutlineColor(sf::Color(0 + (10 * x), 0 + (10 * x), 100, 255));
            else _SoundBox.setOutlineColor(sf::Color::Transparent);


            data.Objects_Vector[i].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[i].SoundMove)].Sound_Area.push_back(_SoundBox);
        }

        //Sound------------------------------------------------------------

        //-----------------------------------------------------------------
    }
}
