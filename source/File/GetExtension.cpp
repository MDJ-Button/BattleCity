#include "File.hpp"
#include <string>

std::string File::GetExtension(std::string _line)
{
    return _line.substr(_line.find("."));
}
