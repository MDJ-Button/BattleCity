#include "File.h"
#include "Game.h"

bool File::StoreTo_Metadata_Data_Vector(std::string _line)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", "StoreTo_Metadata_Data_Vector"));

    bool Added_To_Metadata;

if(_line.find("#") == 0)
    {
        game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0)", "true"));
    }

    else if(_line.find("@Textures") == 0)
    {
        if(_line.find(":") !=std::string::npos)
        {
            if(!Vector_Data_Exists(Metadata_Textures_Title, PraseLine(_line, "Metadata_Data")))
            {
                Metadata_Textures_Data.push_back(PraseLine(_line, "Metadata_Data"));
                Added_To_Metadata = true;
            }
        }
    }

    else if(_line.find("@Music") == 0)
    {
        if(_line.find(":") !=std::string::npos)
        {
            if(!Vector_Data_Exists(Metadata_Music_Title, PraseLine(_line, "Metadata_Data")))
            {
                Metadata_Music_Data.push_back(PraseLine(_line, "Metadata_Data"));
                Added_To_Metadata = true;
            }
        }
    }

    else if(_line.find("@Sounds") == 0)
    {
        if(_line.find(":") !=std::string::npos)
        {
            if(!Vector_Data_Exists(Metadata_Sounds_Title, PraseLine(_line, "Metadata_Data")))
            {
                Metadata_Sounds_Data.push_back(PraseLine(_line, "Metadata_Data"));
                Added_To_Metadata = true;
            }
        }
    }

    else if(_line.find("@Objects") == 0)
    {
        if(_line.find(":") !=std::string::npos)
        {
            if(!Vector_Data_Exists(Metadata_Objects_Title, PraseLine(_line, "Metadata_Data")))
            {
                Metadata_Objects_Data.push_back(PraseLine(_line, "Metadata_Data"));
                Added_To_Metadata = true;
            }
        }
    }

    else game.Print(false, false, game.Statement("else", "(_line.find(\"#\") == 0)", "false"));

    game.Print(false, true, game.Func_Close("File", "StoreTo_Metadata_Data_Vector"));
    return Added_To_Metadata;
}
