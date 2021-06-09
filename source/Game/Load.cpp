#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <windows.h>
#include <string>

int Game::Load(std::string FromFunc, int Line, std::string Type, std::string Name)
{
    Data data;

    if(Type == "Textures")
    {
        for(int i = 0; i < data.Textures_Vector.size(); i++)
        {
            if(data.Textures_Vector[i].Name == Name) return i;
            else if(i + 1 == data.Textures_Vector.size())
            {
                std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the texture named " + Name + " the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                TerminateApplication = true;
                return -1;
            }
        }
    }

    else if(Type == "Music")
    {
        for(int i = 0; i < data.Music_Vector.size(); i++)
        {
            if(data.Music_Vector[i].Name == Name) return i;
            else if(i + 1 == data.Music_Vector.size())
            {
                std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the track named " + Name + " the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                TerminateApplication = true;
                return -1;
            }
        }
    }

    else if(Type == "Sounds")
    {
        for(int i = 0; i < data.Sound_Vector.size(); i++)
        {
            if(data.Sound_Vector[i].Name == Name) return i;
            else if(i + 1 == data.Sound_Vector.size())
            {
                std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the sound named " + Name + " the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                TerminateApplication = true;
                return -1;
            }
        }
    }

    else if(Type == "Obj_Sounds")
    {
        for(int i = 0; i < data.Objects_Vector.size(); i++)
        {
            for(int x = 0; x < data.Objects_Vector[i].Sound.size(); x++)
            {
                if(data.Objects_Vector[i].Sound[x].Name == Name) return x;
                else if(i + 1 == data.Objects_Vector.size())
                {
                    if(x + 1 == data.Objects_Vector[i].Sound.size())
                    {
                        std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the object_sound named " + Name + " the application will now close.";
                        LPCSTR char_error = error.c_str();
                        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                        TerminateApplication = true;
                        return -1;
                    }
                }
            }
        }
    }

    else if(Type == "Objects")
    {
        for(int i = 0; i < data.Objects_Vector.size(); i++)
        {
            if(data.Objects_Vector[i].Name == Name) return i;
            else if(i + 1 == data.Objects_Vector.size())
            {
                std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the object named " + Name + " the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                TerminateApplication = true;
                return -1;
            }
        }
    }

    else if(Type == "Text")
    {
        for(int i = 0; i < data.Text_Vector.size(); i++)
        {
            if(data.Text_Vector[i].Name == Name) return i;
            else if(i + 1 == data.Text_Vector.size())
            {
                std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the text named " + Name + " the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                TerminateApplication = true;
                return -1;
            }
        }
    }

    else if(Type == "Map_Objects")
    {
        for(int i = 0; i < data.Map_Objects_Vector.size(); i++)
        {
            if(data.Map_Objects_Vector[i].Name == Name) return i;
            else if(i + 1 == data.Map_Objects_Vector.size())
            {
                std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the map_object named " + Name + " the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                TerminateApplication = true;
                return -1;
            }
        }
    }

    else if(Type == "Map_Objects_Sounds")
    {
        for(int i = 0; i < data.Map_Objects_Vector.size(); i++)
        {
            for(int x = 0; x < data.Map_Objects_Vector[i].Sound.size(); x++)
            {
                if(data.Map_Objects_Vector[i].Sound[x].Name == Name) return x;
                else if(i + 1 == data.Map_Objects_Vector.size())
                {
                    if(x + 1 == data.Map_Objects_Vector[i].Sound.size())
                    {
                        std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the map_object_sound named " + Name + " the application will now close.";
                        LPCSTR char_error = error.c_str();
                        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                        TerminateApplication = true;
                        return -1;
                    }
                }
            }
        }
    }

    else if(Type == "Fx")
    {
        for(int i = 0; i < data.Fx_Vector.size(); i++)
        {
            if(data.Fx_Vector[i].Name == Name) return i;
            else if(i + 1 == data.Fx_Vector.size())
            {
                std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the fx named " + Name + " the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                TerminateApplication = true;
                return -1;
            }
        }
    }

    else if(Type == "Fx_Sounds")
    {
        for(int i = 0; i < data.Fx_Vector.size(); i++)
        {
            for(int x = 0; x < data.Fx_Vector[i].Sound.size(); x++)
            {
                if(data.Fx_Vector[i].Sound[x].Name == Name) return x;
                else if(i + 1 == data.Fx_Vector.size())
                {
                    if(x + 1 == data.Fx_Vector[i].Sound.size())
                    {
                        std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the fx_sound named " + Name + " the application will now close.";
                        LPCSTR char_error = error.c_str();
                        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                        TerminateApplication = true;
                        return -1;
                    }
                }
            }
        }
    }

    else if(Type == "Level_Objects")
    {
        for(int i = 0; i < data.Level_Vector[0].Objects.size(); i++)
        {
            if(data.Level_Vector[0].Objects[i].Name == Name) return i;
            else if(i + 1 == data.Level_Vector[0].Objects.size())
            {
                std::string error; error = "Calling Load from " + FromFunc + " at line:" + std::to_string(Line) + " cannot find the level_object named " + Name + " the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                TerminateApplication = true;
                return -1;
            }
        }
    }
}
