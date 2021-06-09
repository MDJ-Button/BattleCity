#include "File.hpp"
#include "Game.hpp"

#include <string>

std::string File::PraseLine(std::string _line, std::string Type)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", __func__));

    if(Type == "Title")
    {
        _line = _line.substr(_line.find("-")+1);
    }
    else if(Type == "Name")
    {
        _line = _line.substr(_line.find(' ')+1);
        _line = _line.erase(_line.find(":"));
    }
    else if(Type == "Data")
    {
        _line = _line.substr(_line.find("\"")+1);
        _line = _line.erase(_line.find(";")-1);
    }
    else game.Print(false, false, game.Statement("if", "Type == \"#\"", "false"));

    game.Print(false, true, game.Func_Close("File", __func__));

    return _line;
}
