#include "File.h"
#include "Game.h"

bool File::StoreTo_Metadata_Vector(std::string _line)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", "StoreTo_Metadata_Vector"));

    bool Added_To_Metadata;
    game.Print(false, false, game.DataType_Created("bool", "Added_To_Metadata", ""));

    if(_line.find("#") == 0)
    {
        game.Print(false, false, game.Statement("if", "(_line.find(\"#\") == 0", "true"));
        std::cout << " - comment";
    }

    else if(_line.find("-Textures") == 0)
    {
        game.Print(false, false, game.Statement("else if", "(_line.find(\"-Textures\") == 0", "true"));
        std::cout << " - textures";
        if(!Vector_Already_Exists(Metadata_Vector, PraseLine(_line, "MetaTitle")))
        {
            Metadata_Title.push_back(PraseLine(_line, "MetaTitle"));
            Added_To_Metadata = true;
        }
    }

    else if(_line.find("-Music") == 0)
    {
        game.Print(false, false, game.Statement("else if", "(_line.find(\"-Music\") == 0", "true"));
        std::cout << " - music";
        if(!Vector_Already_Exists(Metadata_Vector, PraseLine(_line, "MetaTitle")))
        {
            Metadata_Title.push_back(PraseLine(_line, "MetaTitle"));
            Added_To_Metadata = true;
        }
    }

    else if(_line.find("-Sounds") == 0)
    {
        std::cout << " - sound";
        if(!Vector_Already_Exists(Metadata_Vector, PraseLine(_line, "MetaTitle")))
        {
            Metadata_Title.push_back(PraseLine(_line, "MetaTitle"));
            Added_To_Metadata = true;
        }
    }

    else if(_line.find("-Objects") == 0)
    {
        game.Print(false, false, game.Statement("else if", "(_line.find(\"-Objects\") == 0", "true"));
        std::cout << " - object";
        if(!Vector_Already_Exists(Metadata_Vector, PraseLine(_line, "MetaTitle")))
        {
            Metadata_Title.push_back(PraseLine(_line, "MetaTitle"));
            Added_To_Metadata = true;
        }
    }

    else if(_line.empty())
    {
        game.Print(false, false, game.Statement("else if", "(_line.empty()) == 0", "true"));
        std::cout << " - empty";
    }

    else
    {
        game.Print(false, false, game.Statement("else", "(_line.empty()) == 0", "false"));
        std::cout << " - undefined";
    }

    game.Print(false, true, game.Func_Close("File", "StoreTo_Metadata_Vector"));
    return Added_To_Metadata;
}
