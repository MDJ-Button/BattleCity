#include "Game.hpp"
#include "Data.hpp"
#include <windows.h>
#include <string>

#define UNICODE
#pragma comment(lib,"user32.lib")

void Game::Window_ShowFPS_Set(bool Reset)
{
    Data data;

    if(Reset)
    {
        if(Window_ShowFPS_Top_OR_Bottom == "T") data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_Y = 0;
        else if(Window_ShowFPS_Top_OR_Bottom == "B") data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_Y = window.getSize().y - (data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].CharacterSize);
        else
        {
            std::string error; error = "In config.txt - Window_ShowFPS(*, #, bool) expected T or B at *.";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
        }

        if(Window_ShowFPS_Left_OR_Right == "L") data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_X = 0;
        else if(Window_ShowFPS_Left_OR_Right == "R") data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_X = window.getSize().x - (data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].CharacterSize);
        else
        {
            std::string error; error = "In config.txt - Window_ShowFPS(#, *, bool) expected L or R at *.";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
        }

        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setPosition(sf::Vector2f(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_X, data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_Y));
    }

    else
    {
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].font.loadFromFile(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Font_Path);
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setFont(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].font);
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setString(std::to_string(clock.getElapsedTime().asMilliseconds()));
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setCharacterSize(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].CharacterSize);
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor.r = data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor_r;
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor.g = data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor_g;
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor.b = data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor_b;
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor.a = data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor_a;
        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setFillColor(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].TextColor);

        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setStyle(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].fBold(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].isBold) |
                                                                    data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].fItalic(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].isItalic) |
                                                                    data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].fStrikeThrough(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].isStrikeThrough) |
                                                                    data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].fUnderlined(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].isUnderlined));

        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setScale(sf::Vector2f(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].ScaleX,
                                                                                 data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].ScaleY));

        if(Window_ShowFPS_Top_OR_Bottom == "T") data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_Y = 0;
        else if(Window_ShowFPS_Top_OR_Bottom == "B") data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_Y = window.getSize().y - (data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].CharacterSize + data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.getGlobalBounds().top);
        else
        {
            std::string error; error = "In config.txt - Window_ShowFPS(*, #, bool) expected T or B at *.";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
        }

        if(Window_ShowFPS_Left_OR_Right == "L") data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_X = 0;
        else if(Window_ShowFPS_Left_OR_Right == "R") data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_X = window.getSize().x - (data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.getGlobalBounds().width + data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.getGlobalBounds().left);
        else
        {
            std::string error; error = "In config.txt - Window_ShowFPS(#, *, bool) expected L or R at *.";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
        }

        data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setPosition(sf::Vector2f(data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_X, data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].Position_Y));
    }
}
