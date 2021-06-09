#include "File.hpp"
#include "Game.hpp"
#include "Data.hpp"

#include <windows.h>



bool File::Store_Data(std::string filename, std::string _line, std::string _Type, bool Running_In_Loop, int LoopNumber)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", "Store_Data"));

    bool Added_To_Metadata;

    Data              C_Data;
    Data::Textures    C_Textures;
    Data::Music       C_Music;
    Data::Sound       C_Sound;
    Data::Objects     C_Objects;
    Data::Text        C_Text;
    Data::Map_Objects C_Map_Objects;
    Data::Level       C_Level;
    Data::Fx          C_Fx;

    if(_Type == "Metadata")
    {
        if(_line.find("@Textures") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "Metadata_Name", PraseLine(_line, "Name"), false, 0))
                {
                    C_Textures.VariableName = PraseLine(_line, "Name");

                    if(!Vector_Data_Exists("Textures_Vector", "Metadata_Data", PraseLine(_line, "Data"), false, 0))
                    {
                        C_Textures.VariableData = PraseLine(_line, "Data");
                        C_Data.Textures_Vector.push_back(C_Textures);
                        Added_To_Metadata = true;
                    }
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Music") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Music_Vector", "Metadata_Name", PraseLine(_line, "Name"), false, 0))
                {
                    C_Music.VariableName = PraseLine(_line, "Name");

                    if(!Vector_Data_Exists("Music_Vector", "Metadata_Data", PraseLine(_line, "Data"), false, 0))
                    {
                        C_Music.VariableData = PraseLine(_line, "Data");
                        C_Data.Music_Vector.push_back(C_Music);
                        Added_To_Metadata = true;
                    }
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Sounds") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Sound_Vector", "Metadata_Name", PraseLine(_line, "Name"), false, 0))
                {
                    C_Sound.VariableName = PraseLine(_line, "Name");

                    if(!Vector_Data_Exists("Sound_Vector", "Metadata_Data", PraseLine(_line, "Data"), false, 0))
                    {
                        C_Sound.VariableData = PraseLine(_line, "Data");
                        C_Data.Sound_Vector.push_back(C_Sound);
                        Added_To_Metadata = true;
                    }
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Objects") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "Metadata_Name", PraseLine(_line, "Name"), false, 0))
                {
                    C_Objects.VariableName = PraseLine(_line, "Name");

                     if(!Vector_Data_Exists("Objects_Vector", "Metadata_Data", PraseLine(_line, "Data"), false, 0))
                    {
                        C_Objects.VariableData = PraseLine(_line, "Data");
                        C_Data.Objects_Vector.push_back(C_Objects);
                        Added_To_Metadata = true;
                    }
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Text") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Metadata_Name", PraseLine(_line, "Name"), false, 0))
                {
                    C_Text.VariableName = PraseLine(_line, "Name");

                    if(!Vector_Data_Exists("Text_Vector", "Metadata_Data", PraseLine(_line, "Data"), false, 0))
                    {
                        C_Text.VariableData = PraseLine(_line, "Data");
                        C_Data.Text_Vector.push_back(C_Text);
                        Added_To_Metadata = true;
                    }
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Map_Objects") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Map_Objects_Vector", "Metadata_Name", PraseLine(_line, "Name"), false, 0))
                {
                    C_Map_Objects.VariableName = PraseLine(_line, "Name");

                    if(!Vector_Data_Exists("Map_Objects_Vector", "Metadata_Data", PraseLine(_line, "Data"), false, 0))
                    {
                        C_Map_Objects.VariableData = PraseLine(_line, "Data");
                        C_Data.Map_Objects_Vector.push_back(C_Map_Objects);
                        Added_To_Metadata = true;
                    }
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Level") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Level_Vector", "Metadata_Name", PraseLine(_line, "Name"), false, 0))
                {
                    C_Text.VariableName = PraseLine(_line, "Name");

                    if(!Vector_Data_Exists("Level_Vector", "Metadata_Data", PraseLine(_line, "Data"), false, 0))
                    {
                        C_Level.VariableData = PraseLine(_line, "Data");
                        C_Data.Level_Vector.push_back(C_Level);
                        Added_To_Metadata = true;
                    }
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Fx") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Fx_Vector", "Metadata_Name", PraseLine(_line, "Name"), false, 0))
                {
                    C_Fx.VariableName = PraseLine(_line, "Name");

                    if(!Vector_Data_Exists("Fx_Vector", "Metadata_Data", PraseLine(_line, "Data"), false, 0))
                    {
                        C_Fx.VariableData = PraseLine(_line, "Data");
                        C_Data.Fx_Vector.push_back(C_Fx);
                        Added_To_Metadata = true;
                    }
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    } //Metadata

    else if(_Type == "Gamedata_Textures")
    {

        //std::cout << "\n\n>> " << GetExtension(C_Data.Textures_Vector[LoopNumber].VariableData) << " "; system("pause");

        //if()

        if(_line.find("@Name") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "Name", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].Name = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Path") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "Path", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].texture_Path = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@TextureRect_L") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "TextureRect_L", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].TextureRect_L = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@TextureRect_T") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "TextureRect_T", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].TextureRect_T = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@TextureRect_W") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "TextureRect_W", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].TextureRect_W = PraseLine_Int(_line, "Data");
                }
            }
        }

        else if(_line.find("@TextureRect_H") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "TextureRect_H", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].TextureRect_H = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Animation_Move_Up") == 0 && GetExtension(C_Data.Textures_Vector[LoopNumber].VariableData) == ".texture")
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "Animation_Move_Up", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up            = PraseLine(_line, "Data");
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Direction  = PraseLine_Str_Array(_line, 0);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Row        = PraseLine_Int_Array(_line, 1);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Reset      = PraseLine_Int_Array(_line, 2);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Add        = PraseLine_Int_Array(_line, 3);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Restart    = PraseLine_Int_Array(_line, 4);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Width      = PraseLine_Int_Array(_line, 5);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Height     = PraseLine_Int_Array(_line, 6);
                    C_Data.Textures_Vector[LoopNumber].AnimationSpeed_Up            = PraseLine_Float_Array(_line, 7);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Animation_Move_Down") == 0 && GetExtension(C_Data.Textures_Vector[LoopNumber].VariableData) == ".texture")
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "Animation_Move_Down", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down            = PraseLine(_line, "Data");
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Direction  = PraseLine_Str_Array(_line, 0);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Row        = PraseLine_Int_Array(_line, 1);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Reset      = PraseLine_Int_Array(_line, 2);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Add        = PraseLine_Int_Array(_line, 3);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Restart    = PraseLine_Int_Array(_line, 4);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Width      = PraseLine_Int_Array(_line, 5);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Height     = PraseLine_Int_Array(_line, 6);
                    C_Data.Textures_Vector[LoopNumber].AnimationSpeed_Down            = PraseLine_Float_Array(_line, 7);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Animation_Move_Left") == 0 && GetExtension(C_Data.Textures_Vector[LoopNumber].VariableData) == ".texture")
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "Animation_Move_Left", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left            = PraseLine(_line, "Data");
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Direction  = PraseLine_Str_Array(_line, 0);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Row        = PraseLine_Int_Array(_line, 1);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Reset      = PraseLine_Int_Array(_line, 2);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Add        = PraseLine_Int_Array(_line, 3);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Restart    = PraseLine_Int_Array(_line, 4);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Width      = PraseLine_Int_Array(_line, 5);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Height     = PraseLine_Int_Array(_line, 6);
                    C_Data.Textures_Vector[LoopNumber].AnimationSpeed_Left            = PraseLine_Float_Array(_line, 7);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Animation_Move_Right") == 0 && GetExtension(C_Data.Textures_Vector[LoopNumber].VariableData) == ".texture")
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "Animation_Move_Right", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right            = PraseLine(_line, "Data");
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Direction  = PraseLine_Str_Array(_line, 0);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Row        = PraseLine_Int_Array(_line, 1);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Reset      = PraseLine_Int_Array(_line, 2);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Add        = PraseLine_Int_Array(_line, 3);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Restart    = PraseLine_Int_Array(_line, 4);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Width      = PraseLine_Int_Array(_line, 5);
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Height     = PraseLine_Int_Array(_line, 6);
                    C_Data.Textures_Vector[LoopNumber].AnimationSpeed_Right            = PraseLine_Float_Array(_line, 7);

                    C_Data.Textures_Vector[LoopNumber].mAnimation            = "L, 0, 0, 0, 0, 0, 0, 0, false";
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Direction  = "L";
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Row        = 0;
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Reset      = 0;
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Add        = 0;
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Restart    = 0;
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Width      = 0;
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Height     = 0;
                    C_Data.Textures_Vector[LoopNumber].mAnimationSpeed       = 0;
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Repeat     = false;
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Animation") == 0 && GetExtension(C_Data.Textures_Vector[LoopNumber].VariableData) == ".mtexture")
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Textures_Vector", "mAnimation", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up                = "L, 0, 0, 0, 0, 0, 0, 0";
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Direction      = "L";
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Row            = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Reset          = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Add            = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Restart        = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Width          = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Up_Height         = 0;
                    C_Data.Textures_Vector[LoopNumber].AnimationSpeed_Up                = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down              = "L, 0, 0, 0, 0, 0, 0, 0";
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Direction    = "L";
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Row          = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Reset        = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Add          = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Restart      = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Width        = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Down_Height       = 0;
                    C_Data.Textures_Vector[LoopNumber].AnimationSpeed_Down              = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left              = "L, 0, 0, 0, 0, 0, 0, 0";
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Direction    = "L";
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Row          = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Reset        = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Add          = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Restart      = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Width        = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Left_Height       = 0;
                    C_Data.Textures_Vector[LoopNumber].AnimationSpeed_Left              = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right             = "L, 0, 0, 0, 0, 0, 0, 0";
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Direction   = "L";
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Row         = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Reset       = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Add         = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Restart     = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Width       = 0;
                    C_Data.Textures_Vector[LoopNumber].Animation_Move_Right_Height      = 0;
                    C_Data.Textures_Vector[LoopNumber].AnimationSpeed_Right             = 0;

                    C_Data.Textures_Vector[LoopNumber].mAnimation            = PraseLine(_line, "Data");
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Direction  = PraseLine_Str_Array(_line, 0);
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Row        = PraseLine_Int_Array(_line, 1);
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Reset      = PraseLine_Int_Array(_line, 2);
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Add        = PraseLine_Int_Array(_line, 3);
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Restart    = PraseLine_Int_Array(_line, 4);
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Width      = PraseLine_Int_Array(_line, 5);
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Height     = PraseLine_Int_Array(_line, 6);
                    C_Data.Textures_Vector[LoopNumber].mAnimationSpeed       = PraseLine_Float_Array(_line, 7);
                    C_Data.Textures_Vector[LoopNumber].mAnimation_Repeat     = PraseLine_Bool_Array(_line, 8);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }

    } //Gamedata_Textures

    else if(_Type == "Gamedata_Music")
    {
        if(_line.find("@Name") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Music_Vector", "Name", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Music_Vector[LoopNumber].Name = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Path") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Music_Vector", "Path", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Music_Vector[LoopNumber].track_Path = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    } //Gamedata_Music

    else if(_Type == "Gamedata_Sounds")
    {
        if(_line.find("@Name") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Sound_Vector", "Name", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Sound_Vector[LoopNumber].Name = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Path") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Sound_Vector", "Path", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Sound_Vector[LoopNumber].sound_Path = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Start_Time") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Sound_Vector", "Start_Time", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Sound_Vector[LoopNumber].start_time = PraseLine_Float(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@End_Time") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Sound_Vector", "End_Time", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Sound_Vector[LoopNumber].end_time = PraseLine_Float(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Sound_Radius") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Sound_Vector", "Sound_Radius", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Sound_Vector[LoopNumber].Sound_Radius = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    } //Gamedata_Sound

    else if(_Type == "Gamedata_Objects")
    {
        if(_line.find("@Name") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "Name", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Objects_Vector[LoopNumber].Name = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Texture") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "Path", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Objects_Vector[LoopNumber].Texture = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@ScaleX") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "ScaleX", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Objects_Vector[LoopNumber].ScaleX = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@ScaleY") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "ScaleY", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Objects_Vector[LoopNumber].ScaleY = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@MovementSpeed") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "MovementSpeed", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Objects_Vector[LoopNumber].MovementSpeed = PraseLine_Float(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@SoundIdle") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "SoundIdle", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    Data::Sound new_sound;
                    C_Data.Objects_Vector[LoopNumber].SoundIdle = PraseLine(_line, "Data");
                    new_sound.Name = C_Data.Objects_Vector[LoopNumber].SoundIdle;
                    C_Data.Objects_Vector[LoopNumber].Sound.push_back(new_sound);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@SoundMove") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "SoundMove", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    Data::Sound new_sound;
                    C_Data.Objects_Vector[LoopNumber].SoundMove = PraseLine(_line, "Data");
                    new_sound.Name = C_Data.Objects_Vector[LoopNumber].SoundMove;
                    C_Data.Objects_Vector[LoopNumber].Sound.push_back(new_sound);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@DeathFx") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Objects_Vector", "Death_Fx", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Objects_Vector[LoopNumber].Death_Fx = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    } //Gamedata_Objects

    else if(_Type == "Gamedata_Text")
    {
        if(_line.find("@Name") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Name", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].Name = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Font") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Font", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].Font_Path = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Message") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Message", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].Message = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@CharacterSize") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "CharacterSize", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].CharacterSize = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@TextColor") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "TextColor", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].TextColor_r = PraseLine_Float_Array(_line, 0);
                    C_Data.Text_Vector[LoopNumber].TextColor_g = PraseLine_Float_Array(_line, 1);
                    C_Data.Text_Vector[LoopNumber].TextColor_b = PraseLine_Float_Array(_line, 2);
                    C_Data.Text_Vector[LoopNumber].TextColor_a = PraseLine_Float_Array(_line, 3);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Bold") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Bold", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].isBold = PraseLine_Bool(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Italic") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Italic", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].isItalic = PraseLine_Bool(_line, "Data");
                }
            }
        }

        else if(_line.find("@StrikeThrough") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "StrikeThrough", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].isStrikeThrough = PraseLine_Bool(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Underlined") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Underlined", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].isUnderlined = PraseLine_Bool(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@ScaleX") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "ScaleX", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].ScaleX = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@ScaleY") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "ScaleY", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].ScaleY = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Position_X") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Position_X", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].Position_X = PraseLine_Float(_line, "Data");
                }
            }
        }

        else if(_line.find("@Position_Y") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Text_Vector", "Position_Y", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Text_Vector[LoopNumber].Position_Y = PraseLine_Float(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }
        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    } //Gamedata_Text

    else if(_Type == "Gamedata_Map_Objects")
    {
        if(_line.find("@Name") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Map_Objects_Vector", "Name", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Map_Objects_Vector[LoopNumber].Name = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Texture") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Map_Objects_Vector", "Path", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Map_Objects_Vector[LoopNumber].Texture = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@ScaleX") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Map_Objects_Vector", "ScaleX", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Map_Objects_Vector[LoopNumber].ScaleX = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@ScaleY") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Map_Objects_Vector", "ScaleY", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Map_Objects_Vector[LoopNumber].ScaleY = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@SoundIdle") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Map_Objects_Vector", "SoundIdle", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    Data::Sound new_sound;
                    C_Data.Map_Objects_Vector[LoopNumber].SoundIdle = PraseLine(_line, "Data");
                    new_sound.Name = C_Data.Map_Objects_Vector[LoopNumber].SoundIdle;
                    C_Data.Map_Objects_Vector[LoopNumber].Sound.push_back(new_sound);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@DeathFx") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Map_Objects_Vector", "Death_Fx", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Map_Objects_Vector[LoopNumber].Death_Fx = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    } //Gamedata_Map_Objects

    else if(_Type == "Gamedata_Level")
    {
        if(_line.find("@Name") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Level_Vector", "Name", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Level_Vector[LoopNumber].Name = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    } //Gamedata_Level

    else if(_Type == "Gamedata_Fx")
    {
        if(_line.find("@Name") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Fx_Vector", "Name", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Fx_Vector[LoopNumber].Name = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Path") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Fx_Vector", "Path", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Fx_Vector[LoopNumber].texture_Path = PraseLine(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@ScaleX") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Fx_Vector", "ScaleX", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Fx_Vector[LoopNumber].ScaleX = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@ScaleY") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Fx_Vector", "ScaleY", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    C_Data.Fx_Vector[LoopNumber].ScaleY = PraseLine_Int(_line, "Data");
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@Fx") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Fx_Vector", "Fx", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    Data::Fx::List new_list;
                    C_Data.Fx_Vector[LoopNumber].vlist.push_back(new_list);
                    int Index = C_Data.Fx_Vector[LoopNumber].vlist.size() - 1;

                    C_Data.Fx_Vector[LoopNumber].vlist[Index].data          = PraseLine(_line, "Data");
                    C_Data.Fx_Vector[LoopNumber].vlist[Index].number        = PraseLine_Int_Array(_line, 0);
                    C_Data.Fx_Vector[LoopNumber].vlist[Index].rect_left     = PraseLine_Int_Array(_line, 1);
                    C_Data.Fx_Vector[LoopNumber].vlist[Index].rect_top      = PraseLine_Int_Array(_line, 2);
                    C_Data.Fx_Vector[LoopNumber].vlist[Index].rect_width    = PraseLine_Int_Array(_line, 3);
                    C_Data.Fx_Vector[LoopNumber].vlist[Index].rect_height   = PraseLine_Int_Array(_line, 4);
                    C_Data.Fx_Vector[LoopNumber].vlist[Index].start_time    = PraseLine_Float_Array(_line, 5);
                    C_Data.Fx_Vector[LoopNumber].vlist[Index].end_time      = PraseLine_Float_Array(_line, 6);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("@SoundFx") == 0)
        {
            if(_line.find(":") !=std::string::npos)
            {
                if(!Vector_Data_Exists("Fx_Vector", "SoundFx", PraseLine(_line, "Data"), true, LoopNumber))
                {
                    Data::Sound new_sound;
                    C_Data.Fx_Vector[LoopNumber].SoundFx = PraseLine(_line, "Data");
                    new_sound.Name = C_Data.Fx_Vector[LoopNumber].SoundFx;
                    C_Data.Fx_Vector[LoopNumber].Sound.push_back(new_sound);
                }
            }

            else
            {
                std::string error; error = std::string("Error from ") + filename +  " expected : after @name in " + _line;
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else if(_line.find("#") == 0)
        {
            game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
        }

        else if(_line.empty())
        {
            game.Print(false, false, game.Statement("if", "(_line.empty() == 0)", "true"));
        }

        else
        {
            std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    } //Gamedata_Fx

    else
    {
        std::string error; error = "Error from " + filename +  " >" + _line + "< is undefined";
        LPCSTR char_error = error.c_str();
        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
    }

    game.Print(false, true, game.Func_Close("File", "Store_Data"));

    return Added_To_Metadata;
}


