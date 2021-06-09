#include "File.hpp"

bool File::PraseLine_Bool_Array(std::string _line, int return_this)
{
    _line.erase(remove(_line.begin(), _line.end(), ' '), _line.end());
    _line.erase(remove(_line.begin(), _line.end(), '\"'), _line.end());
    _line.erase(remove(_line.begin(), _line.end(), ';'), _line.end());
    _line = _line.substr(_line.find(":")+1);
    std::string delimiter = ",";

    bool return_bool;

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
    while(pos < _line.length() && prev < _line.length());

    for(int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i].find("true") == 0) return_bool = true;
        else if(tokens[i].find("false") == 0) return_bool = false;
    }

    return return_bool;
}
