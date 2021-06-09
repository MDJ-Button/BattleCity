#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Data.hpp"

class File
{
    friend class Game;

    public:

    void Read(std::string FilePath, std::string Type, bool Running_In_Loop, int LoopNumber);

    protected:

    void Read_Config(std::string _line);

    bool Store_Data(std::string filename, std::string _line, std::string Type, bool Running_In_Loop, int LoopNumber);
    bool Vector_Data_Exists(std::string _Metadata_Name, std::string _Type, std::string _line, bool Running_In_Loop, int LoopNumber);

    std::string GetExtension(std::string _line);
    std::string PraseLine(std::string _line, std::string Type);
    std::string PraseLine_Str_Array(std::string _line, int return_this);
    int         PraseLine_Int(std::string _line, std::string Type);
    int         PraseLine_Int_Array(std::string _line, int return_this);
    bool        PraseLine_Bool(std::string _line, std::string Type);
    bool        PraseLine_Bool_Array(std::string _line, int return_this);
    float       PraseLine_Float(std::string _line, std::string Type);
    float       PraseLine_Float_Array(std::string _line, int return_this);

    private:

    std::string String_Holder;
    std::string Type_Holder;
};

#endif // FILE_H
