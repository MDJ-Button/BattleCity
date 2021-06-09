#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <string>
#include <windows.h>

void Game::Play_Fx(int LoopNumber)
{
    Data data;

    data.Fx_To_Play_Vector[LoopNumber].fx_timer = data.Fx_To_Play_Vector[LoopNumber].fx_clock.getElapsedTime();

    //std::cout << "Time = " << data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds();

    for(signed int i = 0; i < data.Fx_To_Play_Vector[LoopNumber].vlist.size(); i++)
    {
        //std::cout << " int = " << i << " = ";
        if(data.Fx_To_Play_Vector[LoopNumber].vlist.size() > 2)
        {
            //std::cout << "bigger than 2 ";

            if(!data.Fx_To_Play_Vector[LoopNumber].vlist[0].played
            && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[0].start_time
            && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() <= data.Fx_To_Play_Vector[LoopNumber].vlist[0].end_time)
            {
                //std::cout << "begining\n";
                data.Fx_To_Play_Vector[LoopNumber].vlist[0].played = true;
                data.Fx_To_Play_Vector[LoopNumber].sprite.setTextureRect(data.Fx_To_Play_Vector[LoopNumber].vlist[0].rect);
            }

            else if(data.Fx_To_Play_Vector[LoopNumber].vlist[0].played
                 && data.Fx_To_Play_Vector[LoopNumber].vlist[data.Fx_To_Play_Vector[LoopNumber].vlist.size() - 2].played
                 &&!data.Fx_To_Play_Vector[LoopNumber].vlist[data.Fx_To_Play_Vector[LoopNumber].vlist.size() - 1].played
                 && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[data.Fx_To_Play_Vector[LoopNumber].vlist.size() - 1].start_time
                 && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() <= data.Fx_To_Play_Vector[LoopNumber].vlist[data.Fx_To_Play_Vector[LoopNumber].vlist.size() - 1].end_time)
            {
                //std::cout << "end\n";
                data.Fx_To_Play_Vector[LoopNumber].vlist[data.Fx_To_Play_Vector[LoopNumber].vlist.size() - 1].played = true;
                data.Fx_To_Play_Vector[LoopNumber].sprite.setTextureRect(data.Fx_To_Play_Vector[LoopNumber].vlist[data.Fx_To_Play_Vector[LoopNumber].vlist.size() - 1].rect);
                Remove_Obj_From_Vector("FX_Vector", LoopNumber);
                break;
            }

            else if(data.Fx_To_Play_Vector[LoopNumber].vlist[0].played
                 &&!data.Fx_To_Play_Vector[LoopNumber].vlist[i].played
                 &&!data.Fx_To_Play_Vector[LoopNumber].vlist[data.Fx_To_Play_Vector[LoopNumber].vlist.size() - 1].played
                 && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[i].start_time
                 && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() <= data.Fx_To_Play_Vector[LoopNumber].vlist[i].end_time)
            {
                //std::cout << "middle\n";
                data.Fx_To_Play_Vector[LoopNumber].vlist[i].played = true;
                data.Fx_To_Play_Vector[LoopNumber].sprite.setTextureRect(data.Fx_To_Play_Vector[LoopNumber].vlist[i].rect);
            }
        }

        else if(data.Fx_To_Play_Vector[LoopNumber].vlist.size() == 2)
        {
            //std::cout << "is 2 ";

            if(!data.Fx_To_Play_Vector[LoopNumber].vlist[0].played
            && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[0].start_time
            && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() <= data.Fx_To_Play_Vector[LoopNumber].vlist[0].end_time)
            {
                //std::cout << "begining\n";
                data.Fx_To_Play_Vector[LoopNumber].vlist[0].played = true;
                data.Fx_To_Play_Vector[LoopNumber].sprite.setTextureRect(data.Fx_To_Play_Vector[LoopNumber].vlist[0].rect);
            }

            else if(data.Fx_To_Play_Vector[LoopNumber].vlist[0].played
                 &&!data.Fx_To_Play_Vector[LoopNumber].vlist[1].played
                 && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[1].start_time
                 && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() <= data.Fx_To_Play_Vector[LoopNumber].vlist[1].end_time)
            {
                //std::cout << "end\n";
                data.Fx_To_Play_Vector[LoopNumber].vlist[1].played = true;
                data.Fx_To_Play_Vector[LoopNumber].sprite.setTextureRect(data.Fx_To_Play_Vector[LoopNumber].vlist[1].rect);
                Remove_Obj_From_Vector("FX_Vector", LoopNumber);
                break;
            }
        }

        else if(data.Fx_To_Play_Vector[LoopNumber].vlist.size() == 1)
        {
            //std::cout << "smaller than 2 ";

            if(data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[0].start_time
            && data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() <= data.Fx_To_Play_Vector[LoopNumber].vlist[0].end_time)
            {
                //std::cout << "end\n";
                data.Fx_To_Play_Vector[LoopNumber].vlist[0].played = true;
                data.Fx_To_Play_Vector[LoopNumber].sprite.setTextureRect(data.Fx_To_Play_Vector[LoopNumber].vlist[0].rect);

                if(data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[0].end_time - 0.1)
                {
                    Remove_Obj_From_Vector("FX_Vector", LoopNumber);
                    break;
                }
            }
        }

        else
        {
            std::string error; error = "Expected @Fx:\"ID_Number, rect_left, rect_top, rect_width, rect_height, start time, end time\"; for FX, the application will now close.";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            TerminateApplication = true;
            Remove_Obj_From_Vector("FX_Vector", LoopNumber);
            break;
        }
    }



    if(data.Fx_To_Play_Vector[LoopNumber].vlist.size() > 2)
    {
        if(data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[data.Fx_To_Play_Vector[LoopNumber].vlist.size() - 1].end_time)
        {
            std::cout << " RESET > 2\n";
            data.Fx_To_Play_Vector[LoopNumber].fx_clock.restart();
        }
    }

    else if(data.Fx_To_Play_Vector[LoopNumber].vlist.size() == 2)
    {
        if(data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[1].end_time)
        {
            std::cout << " RESET == 2\n";
            data.Fx_To_Play_Vector[LoopNumber].fx_clock.restart();
        }
    }

    else if(data.Fx_To_Play_Vector[LoopNumber].vlist.size() == 1)
    {
        if(data.Fx_To_Play_Vector[LoopNumber].fx_timer.asSeconds() >= data.Fx_To_Play_Vector[LoopNumber].vlist[0].end_time)
        {
            std::cout << " RESET == 1\n";
            data.Fx_To_Play_Vector[LoopNumber].fx_clock.restart();
        }
    }

    else
    {
        std::string error; error = "Expected @Fx:\"ID_Number, rect_left, rect_top, rect_width, rect_height, start time, end time\"; for FX, the application will now close.";
        LPCSTR char_error = error.c_str();
        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        TerminateApplication = true;
        Remove_Obj_From_Vector("FX_Vector", LoopNumber);
    }
}
