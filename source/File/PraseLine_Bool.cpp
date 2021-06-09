#include "File.hpp"
#include "Game.hpp"

#include <string>

bool File::PraseLine_Bool(std::string _line, std::string Type)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", __func__));

    if(Type == "Title") _line = _line.substr(_line.find("-")+1);
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
    else std::cout << Type << " is not a type of string.\n";

    game.Print(false, true, game.Func_Close("File", __func__));

    bool s_bool;

    if(_line == "true") s_bool = true;
    else if(_line == "false") s_bool = false;

    return s_bool;
}
