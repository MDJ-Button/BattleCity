#include "File.hpp"
#include "Game.hpp"
#include "Controls.hpp"

#include <windows.h>

void File::Read_Config(std::string _line)
{
    if(_line.find("#") == 0)
    {
        std::cout << " - comment";
    }

    else if(_line.find("Debug_DisplayConsole") == 0)
    {
        _line = _line.substr(_line.find(' ')+1);
        if(_line.find("true;") == 0) ShowWindow(GetConsoleWindow(), SW_SHOW);
        else if(_line.find("false;") == 0) ShowWindow(GetConsoleWindow(), SW_HIDE);
        else MessageBoxA(NULL,"In Config.txt - DisplayConsole true;/false; undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Debug_DoPrint") == 0)
    {
        Game game;
        _line = _line.substr(_line.find(' ')+1);
        if(_line.find("true;") == 0) game.DoPrint = true;
        else if(_line.find("false;") == 0) game.DoPrint = false;
        else MessageBoxA(NULL,"In Config.txt - DoPrint true;/false; undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Debug_PrintVectors") == 0)
    {
        Game game;
        _line = _line.substr(_line.find(' ')+1);
        if(_line.find("true;") == 0) game.PrintVectors = true;
        else if(_line.find("false;") == 0) game.PrintVectors = false;
        else MessageBoxA(NULL,"In Config.txt - PrintVectors true;/false; undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Window_ShowFPS") == 0)
    {
        Game game;
        if(_line.find(":") !=std::string::npos)
        {
            game.Window_ShowFPS_Top_OR_Bottom = PraseLine_Str_Array(_line, 0);
            game.Window_ShowFPS_Left_OR_Right = PraseLine_Str_Array(_line, 1);
            game.Window_ShowFPS               = PraseLine_Bool_Array(_line, 3);
        }
        else MessageBoxA(NULL,"In Config.txt - Grid_Color undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Window_FPSLimit") == 0)
    {
        Game game;
        if(_line.find(":") !=std::string::npos)
        {
            Game game;
            if(_line.find(":") !=std::string::npos) game.FPS_Limit = PraseLine_Int(_line, "Data");
            else MessageBoxA(NULL,"In Config.txt - Window_FPSLimit undefined.","Variable Undefined",MB_OK);
        }
        else MessageBoxA(NULL,"In Config.txt - Window_FPSLimit undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Window_Size") == 0)
    {
        Game game;
        if(_line.find(":") !=std::string::npos)
        {
            game.Window_Size_X = PraseLine_Int_Array(_line, 0);
            game.Window_Size_Y = PraseLine_Int_Array(_line, 1);
        }
        else MessageBoxA(NULL,"In Config.txt - Window_Size undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Window_Fullscreen") == 0)
    {
        Game game;
        _line = _line.substr(_line.find(' ')+1);
        if(_line.find("true;") == 0) game.Window_Fullscreen = true;
        else if(_line.find("false;") == 0) game.Window_Fullscreen = false;
        else MessageBoxA(NULL,"In Config.txt - Window_Fullscreen true;/false; undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Builder_Enable") == 0)
    {
        Game game;
        _line = _line.substr(_line.find(' ')+1);
        if(_line.find("true;") == 0) game.Builder_Enable = true;
        else if(_line.find("false;") == 0) game.Builder_Enable = false;
        else MessageBoxA(NULL,"In Config.txt - Builder_Enable true;/false; undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Game_Show_Sound_Boxes") == 0)
    {
        Game game;
        _line = _line.substr(_line.find(' ')+1);
        if(_line.find("true;") == 0) game.Game_Show_Sound_Boxes = true;
        else if(_line.find("false;") == 0) game.Game_Show_Sound_Boxes = false;
        else MessageBoxA(NULL,"In Config.txt - Game_Show_Sound_Boxes true;/false; undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Grid_Draw") == 0)
    {
        Game game;
        _line = _line.substr(_line.find(' ')+1);
        if(_line.find("true;") == 0) game.Grid_Draw = true;
        else if(_line.find("false;") == 0) game.Grid_Draw = false;
        else MessageBoxA(NULL,"In Config.txt - Grid_Draw true;/false; undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Grid_Size_X") == 0)
    {
        Game game;
        if(_line.find(":") !=std::string::npos) game.Grid_Size_X = PraseLine_Int(_line, "Data");
        else MessageBoxA(NULL,"In Config.txt - Grid_Size_X undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Grid_Size_Y") == 0)
    {
        Game game;
        if(_line.find(":") !=std::string::npos) game.Grid_Size_Y = PraseLine_Int(_line, "Data");
        else MessageBoxA(NULL,"In Config.txt - Grid_Size_Y undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Grid_Color") == 0)
    {
        Game game;
        if(_line.find(":") !=std::string::npos)
        {
            game.Grid_Color.r = PraseLine_Int_Array(_line, 0);
            game.Grid_Color.g = PraseLine_Int_Array(_line, 1);
            game.Grid_Color.b = PraseLine_Int_Array(_line, 2);
            game.Grid_Color.a = PraseLine_Int_Array(_line, 3);
        }
        else MessageBoxA(NULL,"In Config.txt - Grid_Color undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Control_Up") == 0)
    {
        Game game;
        Controls controls;
        if(_line.find(":") !=std::string::npos) controls.Up = PraseLine(_line, "Data");
        else MessageBoxA(NULL,"In Config.txt - Control_Up undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.find("Control_Down") == 0)
    {
        Game game;
        Controls controls;
        if(_line.find(":") !=std::string::npos) controls.Down = PraseLine(_line, "Data");
        else MessageBoxA(NULL,"In Config.txt - Control_Up undefined.","Variable Undefined",MB_OK);
    }
    else if(_line.find("Control_Left") == 0)
    {
        Game game;
        Controls controls;
        if(_line.find(":") !=std::string::npos) controls.Left = PraseLine(_line, "Data");
        else MessageBoxA(NULL,"In Config.txt - Control_Up undefined.","Variable Undefined",MB_OK);
    }
    else if(_line.find("Control_Right") == 0)
    {
        Game game;
        Controls controls;
        if(_line.find(":") !=std::string::npos) controls.Right = PraseLine(_line, "Data");
        else MessageBoxA(NULL,"In Config.txt - Control_Up undefined.","Variable Undefined",MB_OK);
    }
    else if(_line.find("Control_Shoot") == 0)
    {
        Game game;
        Controls controls;
        if(_line.find(":") !=std::string::npos) controls.Shoot = PraseLine(_line, "Data");
        else MessageBoxA(NULL,"In Config.txt - Control_Up undefined.","Variable Undefined",MB_OK);
    }
    else if(_line.find("Control_Accelerate") == 0)
    {
        Game game;
        Controls controls;
        if(_line.find(":") !=std::string::npos) controls.Accelerate = PraseLine(_line, "Data");
        else MessageBoxA(NULL,"In Config.txt - Control_Up undefined.","Variable Undefined",MB_OK);
    }

    else if(_line.empty())
    {
        std::cout << " - empty";
    }

    else std::cout << " - undefined";
}


