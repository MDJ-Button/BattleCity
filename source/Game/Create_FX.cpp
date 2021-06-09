#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <string>
#include <windows.h>

void Game::Create_FX(bool Game_Show_Sound_Boxes, std::string unique_name, std::string fx_name, float object_width, float object_height, int at_x, int at_y)
{
    Data data;
    Data::Fx fx;

    fx.VariableName = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].VariableName;
    fx.VariableData = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].VariableData;

    fx.Name = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].Name + "_" + unique_name;
    fx.texture_Path = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].texture_Path;

    fx.ScaleX = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].ScaleX;
    fx.ScaleY = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].ScaleY;

    fx.texture.loadFromFile(fx.texture_Path);
    fx.sprite.setTexture(fx.texture);
    fx.sprite.setScale(fx.ScaleX, fx.ScaleY);

    for(int i = 0; i < data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist.size(); i++)
    {
        Data::Fx::List new_list;

        new_list.data = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist[i].data;
        new_list.number = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist[i].number;
        new_list.rect_left = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist[i].rect_left;
        new_list.rect_top = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist[i].rect_top;
        new_list.rect_width = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist[i].rect_width;
        new_list.rect_height = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist[i].rect_height;
        new_list.start_time = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist[i].start_time;
        new_list.end_time = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].vlist[i].end_time;

        new_list.rect.left = new_list.rect_left;
        new_list.rect.top = new_list.rect_top;
        new_list.rect.width = new_list.rect_width;
        new_list.rect.height = new_list.rect_height;

        fx.vlist.push_back(new_list);
    }

    fx.sprite.setPosition(at_x, at_y);

    //

    fx.SoundFx = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].SoundFx;

    fx.Sound = data.Fx_Vector[Load(__func__, __LINE__, "Fx", fx_name)].Sound;

    fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].VariableName
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", fx.SoundFx)].VariableName;

    fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].VariableData
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", fx.SoundFx)].VariableData;

    fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].sound_Path
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", fx.SoundFx)].sound_Path;

    fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].start_time
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", fx.SoundFx)].start_time;

    fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].end_time
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", fx.SoundFx)].end_time;

    fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].Sound_Radius
    = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", fx.SoundFx)].Sound_Radius;

    fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].buffer.loadFromFile(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", fx.SoundFx)].sound_Path);
    fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].sound.setBuffer(data.Sound_Vector[Load(__func__, __LINE__, "Sounds", fx.SoundFx)].buffer);

    for(int x = 0; x < 10; x++)
    {
        int Sound_Radius_half = fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].Sound_Radius / 2;

        sf::RectangleShape _SoundBox;
        _SoundBox.setFillColor(sf::Color::Transparent);
        _SoundBox.setOutlineThickness(1);

        _SoundBox.setSize(sf::Vector2f(fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].Sound_Radius + (Sound_Radius_half * x),
                                       fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].Sound_Radius + (Sound_Radius_half * x)));

        if(Game_Show_Sound_Boxes) _SoundBox.setOutlineColor(sf::Color(100,0 + (10 * x),0 + (10 * x),255));
        else _SoundBox.setOutlineColor(sf::Color::Transparent);

        _SoundBox.setPosition(fx.sprite.getPosition().x
                                  - fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].Sound_Radius / 2
                                  + object_width / 2
                                  - Sound_Radius_half / 2 * x,
                                  fx.sprite.getPosition().y
                                  - fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].Sound_Radius / 2
                                  + object_height / 2
                                  - Sound_Radius_half / 2 * x);


        fx.Sound[Load(__func__, __LINE__, "Fx_Sounds", fx.SoundFx)].Sound_Area.push_back(_SoundBox);
    }

    data.Fx_To_Play_Vector.push_back(fx);
}
