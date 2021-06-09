#include "Game.hpp"
#include "Data.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

void Game::Update_Window()
{
    Data data;
    Print(true, true, Func_Open("Game", "Update_Window"));

    window.clear();
    Print(true, false, DataType_Updated("sf::RenderWindow", "window", "clear()"));

    if(Grid_Draw)
    {
        for(signed int i = 0; i < Grid_Vector.size(); i++)
        {
            window.draw(Grid_Vector[i]);
            window.draw(Grid_Text_Vector[i].GetText());
        }

        Print(true, false, DataType_Updated("sf::RenderWindow", "window", "draw(Grid_Vector[i])"));
        Print(true, false, DataType_Updated("sf::RenderWindow", "window", "draw(Grid_Text_Vector[i].GetText())"));
    }

    if(Window_ShowFPS)
    {
        window.draw(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].GetText());
        Print(true, false, DataType_Updated("sf::RenderWindow", "window", "draw(data.Text_Vector[Load(__func__, __LINE__, \"Text\", \"FPS_Counter\")].GetText())"));
    }

    for(signed int i = 0; i < data.Text_Vector.size(); i++) window.draw(data.Text_Vector[i].GetText());
    Print(true, false, DataType_Updated("sf::RenderWindow", "window", "draw(data.Text_Vector[i].GetText())"));

    for(signed int i = 0; i < data.Level_Vector.size(); i++)
    {
        for(signed int x = 0; x < data.Level_Vector[i].Map_Objects.size() - 1; x++)
        {
            window.draw(data.Level_Vector[i].Map_Objects[x].GetSprite());
        }
    }
    Print(true, false, DataType_Updated("sf::RenderWindow", "window", "draw(data.Map_Objects_Vector[i].GetSprite())"));

    for(signed int i = 0; i < data.Level_Vector.size(); i++)
    {
        for(signed int x = 0; x < data.Level_Vector[i].Objects.size(); x++)
        {
            if(data.Level_Vector[i].Objects[x].State == Data::Objects::enumState::alive)
            {
                window.draw(data.Level_Vector[i].Objects[x].GetSprite());
                Print(true, false, DataType_Updated("sf::RenderWindow", "window", "draw(data.Level_Vector[i].Objects[x].GetSprite())"));

                if(data.Level_Vector[i].Objects[x].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[i].Objects[x].SoundIdle)].Play)
                {
                    for(int y = 0; y < data.Level_Vector[i].Objects[x].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[i].Objects[x].SoundIdle)].Sound_Area.size(); y++)
                    {
                        window.draw(data.Level_Vector[i].Objects[x].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[i].Objects[x].SoundIdle)].Sound_Area[y]);
                    }
                }

                else if(data.Level_Vector[i].Objects[x].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[i].Objects[x].SoundMove)].Play)
                {
                    for(int y = 0; y < data.Level_Vector[i].Objects[x].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[i].Objects[x].SoundMove)].Sound_Area.size(); y++)
                    {
                        window.draw(data.Level_Vector[i].Objects[x].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[i].Objects[x].SoundMove)].Sound_Area[y]);
                    }
                }
            }
        }
    }

    for(signed int i = 0; i < data.Projectile_Vector.size(); i++)
    {
        window.draw(data.Projectile_Vector[i].GetSprite());
        Print(true, false, DataType_Updated("sf::RenderWindow", "window", "draw(data.Projectile_Vector[i].GetSprite())"));
    }

    for(signed int i = 0; i < data.Fx_To_Play_Vector.size(); i++)
    {
        if(data.Fx_To_Play_Vector[i].vlist[0].played)
        {
            window.draw(data.Fx_To_Play_Vector[i].GetSprite());
            Print(true, false, DataType_Updated("sf::RenderWindow", "window", "draw(data.Fx_Vector[i].GetSprite())"));
            data.Fx_To_Play_Vector[i].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[i].SoundFx)].Play = true;
        }

        for(int x = 0; x < data.Fx_To_Play_Vector[i].Sound.size(); x++)
        {
            for(int y = 0; y < data.Fx_To_Play_Vector[i].Sound[x].Sound_Area.size(); y++)
            {
                window.draw(data.Fx_To_Play_Vector[i].Sound[x].Sound_Area[y]);
            }
        }
    }

    window.display();
    Print(true, false, DataType_Updated("sf::RenderWindow", "window", "display()"));

    Print(true, true, Func_Close("Game", "Update_Window"));
}


