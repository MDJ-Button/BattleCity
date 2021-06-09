#include "File.hpp"
#include "Game.hpp"
#include "Data.hpp"

#include <fstream>
#include <windows.h>

void File::Read(std::string FilePath, std::string Type, bool Running_In_Loop, int LoopNumber)
{
    Game game;
    game.Print(false, true, game.Func_Open("File", "Read"));

    std::string line;
    std::ifstream File;
    File.open(FilePath);
    if(File)
    {
        while(getline(File, line))
        {
            std::cout << line;

            if(Type == "Config")
            {
                Read_Config(line);
            }

            else if(Type == "Gamedata_Textures" || Type == "Gamedata_Music"   || Type == "Gamedata_Sounds" ||
                    Type == "Gamedata_Objects"  || Type == "Gamedata_Text"    || Type == "Gamedata_Map_Objects" ||
                    Type == "Gamedata_Level"    || Type == "Gamedata_Fx"      || Type == "Metadata")
            {
                Store_Data(FilePath, line, Type, Running_In_Loop, LoopNumber);
            }

            else
            {
                std::string error; error = "The type " + Type + " is undefined the application will now close.";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
                game.TerminateApplication = true;
            }

            std::cout << std::endl;
        }
        File.close();
    }

    else
    {
        std::string error; error = "Cannot find the file " + FilePath + " the application will now close.";
        LPCSTR char_error = error.c_str();
        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        game.TerminateApplication = true;
    }

    game.Print(false, true, game.Func_Close("File", "Read"));
}
