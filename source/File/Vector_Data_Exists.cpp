#include "File.hpp"
#include "Game.hpp"
#include "Data.hpp"

#include <string>
#include <limits>
#include <windows.h>

bool File::Vector_Data_Exists(std::string _Metadata_Name, std::string _Type, std::string _line,  bool Running_In_Loop, int LoopNumber)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", "Vector_Data_Exists"));

    bool Exists = false;
    game.Print(false, false, game.DataType_Created("bool", "Exists", ""));

    Data C_Data;

    if(_Metadata_Name == "Textures_Vector")
    {
        if(C_Data.Textures_Vector.size() == 0)
        {
            game.Print(false, false, game.Statement("if", "(C_Data.Textures_Vector.size() == 0)", "true"));
            Exists = false;
        }

        else
        {
            if(_Type == "Metadata_Name")
            {
                for(int i = 0; i < C_Data.Textures_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Textures_Vector[i].VariableName << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[i].VariableName) Exists = true;
                }
            }

            else if(_Type == "Metadata_Data")
            {
                for(int i = 0; i < C_Data.Textures_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Textures_Vector[i].VariableData << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[i].VariableData) Exists = true;
                }
            }

            else if(Running_In_Loop)
            {
                if(_Type == "Name")
                {
                    std::cout << LoopNumber << "." << C_Data.Textures_Vector[LoopNumber].Name << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[LoopNumber].Name) Exists = true;
                }

                else if(_Type == "Path")
                {
                    std::cout << LoopNumber << "." << C_Data.Textures_Vector[LoopNumber].texture_Path << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[LoopNumber].texture_Path) Exists = true;
                }

                else if(_Type == "TextureRect_L")
                {
                    std::string s_int = std::to_string(C_Data.Textures_Vector[LoopNumber].TextureRect_L);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "TextureRect_T")
                {
                    std::string s_int = std::to_string(C_Data.Textures_Vector[LoopNumber].TextureRect_T);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "TextureRect_W")
                {
                    std::string s_int = std::to_string(C_Data.Textures_Vector[LoopNumber].TextureRect_W);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "TextureRect_H")
                {
                    std::string s_int = std::to_string(C_Data.Textures_Vector[LoopNumber].TextureRect_H);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "Animation_Move_Up")
                {
                    std::cout << LoopNumber << "." << C_Data.Textures_Vector[LoopNumber].Animation_Move_Up << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[LoopNumber].Animation_Move_Up) Exists = true;
                }

                else if(_Type == "Animation_Move_Down")
                {
                    std::cout << LoopNumber << "." << C_Data.Textures_Vector[LoopNumber].Animation_Move_Down << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[LoopNumber].Animation_Move_Down) Exists = true;
                }

                else if(_Type == "Animation_Move_Left")
                {
                    std::cout << LoopNumber << "." << C_Data.Textures_Vector[LoopNumber].Animation_Move_Left << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[LoopNumber].Animation_Move_Left) Exists = true;
                }

                else if(_Type == "Animation_Move_Right")
                {
                    std::cout << LoopNumber << "." << C_Data.Textures_Vector[LoopNumber].Animation_Move_Right << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[LoopNumber].Animation_Move_Right) Exists = true;
                }

                else if(_Type == "mAnimation")
                {
                    std::cout << LoopNumber << "." << C_Data.Textures_Vector[LoopNumber].mAnimation << " = " << _line << "\n";
                    if(_line == C_Data.Textures_Vector[LoopNumber].mAnimation) Exists = true;
                }

                else game.Print(false, false, game.Statement("else", "(_Type)", "false"));
            }

            else game.Print(false, false, game.Statement("else", "(_Type) || (Running_In_Loop)", "false"));
        }
    }//Textures

    else if(_Metadata_Name == "Music_Vector")
    {
        if(C_Data.Music_Vector.size() == 0)
        {
            game.Print(false, false, game.Statement("if", "(C_Data.Music_Vector.size() == 0)", "true"));
            Exists = false;
        }

        else
        {
            if(_Type == "Metadata_Name")
            {
                for(int i = 0; i < C_Data.Music_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Music_Vector[i].VariableName << " = " << _line << "\n";
                    if(_line == C_Data.Music_Vector[i].VariableName) Exists = true;
                }
            }

            else if(_Type == "Metadata_Data")
            {
                for(int i = 0; i < C_Data.Music_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Music_Vector[i].VariableData << " = " << _line << "\n";
                    if(_line == C_Data.Music_Vector[i].VariableData) Exists = true;
                }
            }

            else if(Running_In_Loop)
            {
                if(_Type == "Name")
                {
                    std::cout << LoopNumber << "." << C_Data.Music_Vector[LoopNumber].Name << " = " << _line << "\n";
                    if(_line == C_Data.Music_Vector[LoopNumber].Name) Exists = true;
                }

                else if(_Type == "Path")
                {
                    std::cout << LoopNumber << "." << C_Data.Music_Vector[LoopNumber].track_Path << " = " << _line << "\n";
                    if(_line == C_Data.Music_Vector[LoopNumber].track_Path) Exists = true;
                }

                else game.Print(false, false, game.Statement("else", "(_Type)", "false"));
            }


            else game.Print(false, false, game.Statement("else", "(_Type) || (Running_In_Loop)", "false"));
        }
    }//Music

    else if(_Metadata_Name == "Sound_Vector")
    {
        if(C_Data.Sound_Vector.size() == 0)
        {
            game.Print(false, false, game.Statement("if", "(C_Data.Sound_Vector.size() == 0)", "true"));
            Exists = false;
        }

        else
        {
            if(_Type == "Metadata_Name")
            {
                for(int i = 0; i < C_Data.Sound_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Sound_Vector[i].VariableName << " = " << _line << "\n";
                    if(_line == C_Data.Sound_Vector[i].VariableName) Exists = true;
                }
            }

            else if(_Type == "Metadata_Data")
            {
                for(int i = 0; i < C_Data.Sound_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Sound_Vector[i].VariableData << " = " << _line << "\n";
                    if(_line == C_Data.Sound_Vector[i].VariableData) Exists = true;
                }
            }

            else if(Running_In_Loop)
            {
                if(_Type == "Name")
                {
                    std::cout << LoopNumber << "." << C_Data.Sound_Vector[LoopNumber].Name << " = " << _line << "\n";
                    if(_line == C_Data.Sound_Vector[LoopNumber].Name) Exists = true;
                }

                else if(_Type == "Path")
                {
                    std::cout << LoopNumber << "." << C_Data.Sound_Vector[LoopNumber].sound_Path << " = " << _line << "\n";
                    if(_line == C_Data.Sound_Vector[LoopNumber].sound_Path) Exists = true;
                }

                else if(_Type == "Start_Time")
                {
                    std::cout << LoopNumber << "." << C_Data.Sound_Vector[LoopNumber].start_time << " = " << _line << "\n";
                    if(_line == std::to_string(C_Data.Sound_Vector[LoopNumber].start_time)) Exists = true;
                }

                else if(_Type == "End_Time")
                {
                    std::cout << LoopNumber << "." << C_Data.Sound_Vector[LoopNumber].end_time << " = " << _line << "\n";
                    if(_line == std::to_string(C_Data.Sound_Vector[LoopNumber].end_time)) Exists = true;
                }

                else if(_Type == "Sound_Radius")
                {
                    std::string s_int = std::to_string(C_Data.Sound_Vector[LoopNumber].Sound_Radius);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else game.Print(false, false, game.Statement("else", "(_Type)", "false"));
            }

            else game.Print(false, false, game.Statement("else", "(_Type) || (Running_In_Loop)", "false"));
        }
    }//Sound

    else if(_Metadata_Name == "Objects_Vector")
    {
        if(C_Data.Objects_Vector.size() == 0)
        {
            game.Print(false, false, game.Statement("if", "(C_Data.Objects_Vector.size() == 0)", "true"));
            Exists = false;
        }

        else
        {
            if(_Type == "Metadata_Name")
            {
                for(int i = 0; i < C_Data.Objects_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Objects_Vector[i].VariableName << " = " << _line << "\n";
                    if(_line == C_Data.Objects_Vector[i].VariableName) Exists = true;
                }
            }

            else if(_Type == "Metadata_Data")
            {
                for(int i = 0; i < C_Data.Objects_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Objects_Vector[i].VariableData << " = " << _line << "\n";
                    if(_line == C_Data.Objects_Vector[i].VariableData) Exists = true;
                }
            }

            else if(Running_In_Loop)
            {
                if(_Type == "Name")
                {
                    std::cout << LoopNumber << "." << C_Data.Objects_Vector[LoopNumber].Name << " = " << _line << "\n";
                    if(_line == C_Data.Objects_Vector[LoopNumber].Name) Exists = true;
                }

                else if(_Type == "Texture")
                {
                    std::cout << LoopNumber << "." << C_Data.Objects_Vector[LoopNumber].Texture << " = " << _line << "\n";
                    if(_line == C_Data.Objects_Vector[LoopNumber].Texture) Exists = true;
                }

                else if(_Type == "ScaleX")
                {
                    std::string s_int = std::to_string(C_Data.Objects_Vector[LoopNumber].ScaleX);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "ScaleY")
                {
                    std::string s_int = std::to_string(C_Data.Objects_Vector[LoopNumber].ScaleY);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "MovementSpeed")
                {
                    std::string s_int = std::to_string(C_Data.Objects_Vector[LoopNumber].MovementSpeed);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "SoundIdle")
                {
                    std::cout << LoopNumber << "." << C_Data.Objects_Vector[LoopNumber].SoundIdle << " = " << _line << "\n";
                    if(_line == C_Data.Objects_Vector[LoopNumber].SoundIdle) Exists = true;
                }

                else if(_Type == "SoundMove")
                {
                    std::cout << LoopNumber << "." << C_Data.Objects_Vector[LoopNumber].SoundMove << " = " << _line << "\n";
                    if(_line == C_Data.Objects_Vector[LoopNumber].SoundMove) Exists = true;
                }

                else if(_Type == "Death_Fx")
                {
                    std::cout << LoopNumber << "." << C_Data.Objects_Vector[LoopNumber].Death_Fx << " = " << _line << "\n";
                    if(_line == C_Data.Objects_Vector[LoopNumber].Death_Fx) Exists = true;
                }

                else game.Print(false, false, game.Statement("else", "(_Type)", "false"));
            }

            else game.Print(false, false, game.Statement("else", "(_Type) || (Running_In_Loop)", "false"));
        }
    }//Objects

    else if(_Metadata_Name == "Text_Vector")
    {
        if(C_Data.Text_Vector.size() == 0)
        {
            game.Print(false, false, game.Statement("if", "(C_Data.Text_Vector.size() == 0)", "true"));
            Exists = false;
        }

        else
        {
            if(_Type == "Metadata_Name")
            {
                for(int i = 0; i < C_Data.Text_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Text_Vector[i].VariableName << " = " << _line << "\n";
                    if(_line == C_Data.Text_Vector[i].VariableName) Exists = true;
                }
            }

            else if(_Type == "Metadata_Data")
            {
                for(int i = 0; i < C_Data.Text_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Text_Vector[i].VariableData << " = " << _line << "\n";
                    if(_line == C_Data.Text_Vector[i].VariableData) Exists = true;
                }
            }

            else if(Running_In_Loop)
            {
                if(_Type == "Name")
                {
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].Name << " = " << _line << "\n";
                    if(_line == C_Data.Text_Vector[LoopNumber].Name) Exists = true;
                }

                else if(_Type == "Font")
                {
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].Font_Path << " = " << _line << "\n";
                    if(_line == C_Data.Text_Vector[LoopNumber].Font_Path) Exists = true;
                }

                else if(_Type == "Message")
                {
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].Message << " = " << _line << "\n";
                    if(_line == C_Data.Text_Vector[LoopNumber].Message) Exists = true;
                }

                else if(_Type == "CharacterSize")
                {
                    std::string s_int = std::to_string(C_Data.Text_Vector[LoopNumber].CharacterSize);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "TextColor")
                {
                    File file;

                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].TextColor_r << " = " << file.PraseLine_Str_Array(_line, 0) << "\n";
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].TextColor_g << " = " << file.PraseLine_Str_Array(_line, 1) << "\n";
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].TextColor_b << " = " << file.PraseLine_Str_Array(_line, 2) << "\n";
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].TextColor_a << " = " << file.PraseLine_Str_Array(_line, 3) << "\n";

                    if(file.PraseLine_Int_Array(_line, 0) == C_Data.Text_Vector[LoopNumber].TextColor_r)
                    {
                        if(file.PraseLine_Int_Array(_line, 1) == C_Data.Text_Vector[LoopNumber].TextColor_g)
                        {
                            if(file.PraseLine_Int_Array(_line, 2) == C_Data.Text_Vector[LoopNumber].TextColor_b)
                            {
                                if(file.PraseLine_Int_Array(_line, 3) == C_Data.Text_Vector[LoopNumber].TextColor_a)
                                {
                                    Exists = true;
                                }
                            }
                        }
                    }
                }

                else if(_Type == "Bold")
                {
                    std::string s_bool;
                    if(C_Data.Text_Vector[LoopNumber].isBold) s_bool = "true";
                    else if(!C_Data.Text_Vector[LoopNumber].isBold) s_bool = "false";
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].isBold << " = " << _line << "\n";
                    if(_line == s_bool) Exists = true;
                }

                else if(_Type == "Italic")
                {
                    std::string s_bool;
                    if(C_Data.Text_Vector[LoopNumber].isItalic) s_bool = "true";
                    else if(!C_Data.Text_Vector[LoopNumber].isItalic) s_bool = "false";
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].isItalic << " = " << _line << "\n";
                    if(_line == s_bool) Exists = true;
                }

                else if(_Type == "StrikeThrough")
                {
                    std::string s_bool;
                    if(C_Data.Text_Vector[LoopNumber].isStrikeThrough) s_bool = "true";
                    else if(!C_Data.Text_Vector[LoopNumber].isStrikeThrough) s_bool = "false";
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].isStrikeThrough << " = " << _line << "\n";
                    if(_line == s_bool) Exists = true;
                }

                else if(_Type == "Underlined")
                {
                    std::string s_bool;
                    if(C_Data.Text_Vector[LoopNumber].isUnderlined) s_bool = "true";
                    else if(!C_Data.Text_Vector[LoopNumber].isUnderlined) s_bool = "false";
                    std::cout << LoopNumber << "." << C_Data.Text_Vector[LoopNumber].isUnderlined << " = " << _line << "\n";
                    if(_line == s_bool) Exists = true;
                }

                else if(_Type == "ScaleX")
                {
                    std::string s_int = std::to_string(C_Data.Text_Vector[LoopNumber].ScaleX);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "ScaleY")
                {
                    std::string s_int = std::to_string(C_Data.Text_Vector[LoopNumber].ScaleY);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "Position_X")
                {
                    std::string s_float = std::to_string(C_Data.Text_Vector[LoopNumber].Position_X);

                    std::cout << LoopNumber << "." << s_float << " = " << _line << "\n";
                    if(_line == s_float) Exists = true;
                }

                else if(_Type == "Position_Y")
                {
                    std::string s_float = std::to_string(C_Data.Text_Vector[LoopNumber].Position_Y);

                    std::cout << LoopNumber << "." << s_float << " = " << _line << "\n";
                    if(_line == s_float) Exists = true;
                }

                else game.Print(false, false, game.Statement("else", "(_Type)", "false"));
            }

            else game.Print(false, false, game.Statement("else", "(_Type) || (Running_In_Loop)", "false"));
        }
    }//Text

    else if(_Metadata_Name == "Map_Objects_Vector")
    {
        if(C_Data.Map_Objects_Vector.size() == 0)
        {
            game.Print(false, false, game.Statement("if", "(C_Data.Map_Objects_Vector.size() == 0)", "true"));
            Exists = false;
        }

        else
        {
            if(_Type == "Metadata_Name")
            {
                for(int i = 0; i < C_Data.Map_Objects_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Map_Objects_Vector[i].VariableName << " = " << _line << "\n";
                    if(_line == C_Data.Map_Objects_Vector[i].VariableName) Exists = true;
                }
            }

            else if(_Type == "Metadata_Data")
            {
                for(int i = 0; i < C_Data.Map_Objects_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Map_Objects_Vector[i].VariableData << " = " << _line << "\n";
                    if(_line == C_Data.Map_Objects_Vector[i].VariableData) Exists = true;
                }
            }

            else if(Running_In_Loop)
            {
                if(_Type == "Name")
                {
                    std::cout << LoopNumber << "." << C_Data.Map_Objects_Vector[LoopNumber].Name << " = " << _line << "\n";
                    if(_line == C_Data.Map_Objects_Vector[LoopNumber].Name) Exists = true;
                }

                else if(_Type == "Texture")
                {
                    std::cout << LoopNumber << "." << C_Data.Map_Objects_Vector[LoopNumber].Texture << " = " << _line << "\n";
                    if(_line == C_Data.Map_Objects_Vector[LoopNumber].Texture) Exists = true;
                }

                else if(_Type == "ScaleX")
                {
                    std::string s_int = std::to_string(C_Data.Map_Objects_Vector[LoopNumber].ScaleX);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "ScaleY")
                {
                    std::string s_int = std::to_string(C_Data.Map_Objects_Vector[LoopNumber].ScaleY);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "SoundIdle")
                {
                    std::cout << LoopNumber << "." << C_Data.Map_Objects_Vector[LoopNumber].SoundIdle << " = " << _line << "\n";
                    if(_line == C_Data.Map_Objects_Vector[LoopNumber].SoundIdle) Exists = true;
                }

                else if(_Type == "Death_Fx")
                {
                    std::cout << LoopNumber << "." << C_Data.Map_Objects_Vector[LoopNumber].Death_Fx << " = " << _line << "\n";
                    if(_line == C_Data.Map_Objects_Vector[LoopNumber].Death_Fx) Exists = true;
                }

                else game.Print(false, false, game.Statement("else", "(_Type)", "false"));
            }

            else game.Print(false, false, game.Statement("else", "(_Type) || (Running_In_Loop)", "false"));
        }
    }//Map Objects

    else if(_Metadata_Name == "Level_Vector")
    {
        if(C_Data.Level_Vector.size() == 0)
        {
            game.Print(false, false, game.Statement("if", "(C_Data.Level_Vector.size() == 0)", "true"));
            Exists = false;
        }

        else
        {
            if(_Type == "Metadata_Name")
            {
                for(int i = 0; i < C_Data.Level_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Level_Vector[i].VariableName << " = " << _line << "\n";
                    if(_line == C_Data.Level_Vector[i].VariableName) Exists = true;
                }
            }

            else if(_Type == "Metadata_Data")
            {
                for(int i = 0; i < C_Data.Level_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Level_Vector[i].VariableData << " = " << _line << "\n";
                    if(_line == C_Data.Level_Vector[i].VariableData) Exists = true;
                }
            }

            else if(Running_In_Loop)
            {
                if(_Type == "Name")
                {
                    std::cout << LoopNumber << "." << C_Data.Level_Vector[LoopNumber].Name << " = " << _line << "\n";
                    if(_line == C_Data.Level_Vector[LoopNumber].Name) Exists = true;
                }
                else game.Print(false, false, game.Statement("else", "(_Type)", "false"));
            }
            else game.Print(false, false, game.Statement("else", "(_Type) || (Running_In_Loop)", "false"));
        }
    }//Level

    else if(_Metadata_Name == "Fx_Vector")
    {
        if(C_Data.Fx_Vector.size() == 0)
        {
            game.Print(false, false, game.Statement("if", "(C_Data.Fx_Vector.size() == 0)", "true"));
            Exists = false;
        }

        else
        {
            if(_Type == "Metadata_Name")
            {
                for(int i = 0; i < C_Data.Fx_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Fx_Vector[i].VariableName << " = " << _line << "\n";
                    if(_line == C_Data.Fx_Vector[i].VariableName) Exists = true;
                }
            }

            else if(_Type == "Metadata_Data")
            {
                for(int i = 0; i < C_Data.Fx_Vector.size(); i++)
                {
                    std::cout << i << "." << C_Data.Fx_Vector[i].VariableData << " = " << _line << "\n";
                    if(_line == C_Data.Fx_Vector[i].VariableData) Exists = true;
                }
            }

            else if(Running_In_Loop)
            {
                if(_Type == "Name")
                {
                    std::cout << LoopNumber << "." << C_Data.Fx_Vector[LoopNumber].Name << " = " << _line << "\n";
                    if(_line == C_Data.Fx_Vector[LoopNumber].Name) Exists = true;
                }

                else if(_Type == "Path")
                {
                    std::cout << LoopNumber << "." << C_Data.Fx_Vector[LoopNumber].texture_Path << " = " << _line << "\n";
                    if(_line == C_Data.Fx_Vector[LoopNumber].texture_Path) Exists = true;
                }

                else if(_Type == "ScaleX")
                {
                    std::string s_int = std::to_string(C_Data.Fx_Vector[LoopNumber].ScaleX);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "ScaleY")
                {
                    std::string s_int = std::to_string(C_Data.Fx_Vector[LoopNumber].ScaleY);

                    std::cout << LoopNumber << "." << s_int << " = " << _line << "\n";
                    if(_line == s_int) Exists = true;
                }

                else if(_Type == "Fx")
                {
                    if(C_Data.Fx_Vector[LoopNumber].vlist.size() >= 1)
                    {
                        for(int i = 0; i < C_Data.Fx_Vector[LoopNumber].vlist.size(); i++)
                        {
                            std::cout << C_Data.Fx_Vector[LoopNumber].vlist[i].data << " = " << _line << "\n";
                            if(_line == C_Data.Fx_Vector[LoopNumber].vlist[i].data) {Exists = true; break;}
                        }
                    }
                }

                else if(_Type == "SoundFx")
                {
                    std::cout << LoopNumber << "." << C_Data.Fx_Vector[LoopNumber].SoundFx << " = " << _line << "\n";
                    if(_line == C_Data.Fx_Vector[LoopNumber].SoundFx) Exists = true;
                }

                else game.Print(false, false, game.Statement("else", "(_Type)", "false"));
            }

            else game.Print(false, false, game.Statement("else", "(_Type) || (Running_In_Loop)", "false"));
        }
    }//Fx

    else
    {
        std::string error = std::string("Error from ") + __func__ +  " metadata name " + _Metadata_Name + " is undefined";
        LPCSTR char_error = error.c_str();
        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
    }

    //else game.Print(false, false, game.Statement("else", "(_Metadata_Name.size() == 0)", "false"));

    game.Print(false, true, game.Func_Close("File", "Vector_Data_Exists"));
    return Exists;
}
