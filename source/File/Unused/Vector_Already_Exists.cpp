#include "File.h"
#include "Game.h"

bool File::Vector_Already_Exists(std::vector<std::vector<std::string>> _Metadata_Vector, std::string _line)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", "Vector_Already_Exists"));

    bool Exists;
    game.Print(false, false, game.DataType_Created("bool", "Exists", ""));

    if(_Metadata_Vector.size() == 0)
    {
        game.Print(false, false, game.Statement("if", "_Metadata_Vector.size() == 0", "true"));
        Exists = false;
    }

    else
    {
        game.Print(false, false, game.Statement("else", "_Metadata_Vector.size() == 0", "false"));
        for(int i = 0; i < _Metadata_Vector.size(); i++)
        {
            for(int y = 0; y < _Metadata_Vector[i].size(); y++)
            {
                std::cout << i << "." << y << " " << _Metadata_Vector[i][y] << " = " << _line << "\n";
                if(_line == _Metadata_Vector[i][y]) {Exists = true; break;}
            }
        }
    }

    game.Print(false, true, game.Func_Close("File", "Vector_Already_Exists"));
    return Exists;
}
