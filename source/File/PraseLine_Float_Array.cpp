#include "File.hpp"
#include "Game.hpp"

float File::PraseLine_Float_Array(std::string _line, int return_this)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", __func__));

    _line.erase(remove(_line.begin(), _line.end(), ' '), _line.end());
    _line.erase(remove(_line.begin(), _line.end(), '\"'), _line.end());
    _line.erase(remove(_line.begin(), _line.end(), ';'), _line.end());
    _line = _line.substr(_line.find(":")+1);
    std::string delimiter = ",";

    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = _line.find(delimiter, prev);
        if (pos == std::string::npos) pos = _line.length();
        std::string token = _line.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delimiter.length();
    }
    while (pos < _line.length() && prev < _line.length());

    game.Print(false, true, game.Func_Close("File", __func__));

    float return_this_f;

    return return_this_f = std::stof(tokens[return_this]);
}
