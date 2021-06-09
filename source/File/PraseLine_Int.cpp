#include "File.hpp"
#include "Game.hpp"

#include <string>

int File::PraseLine_Int(std::string _line, std::string Type)
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

    int s_int = std::stoi(_line);

    return s_int;
}
