#include "Data.hpp"
#include "Game.hpp"

void Game::Play_SoundMove(int LoopNumber)
{
    Data data;

    for(int i = 0; i < data.Level_Vector[0].Objects[LoopNumber].Sound.size(); i++)
    {
        //std::cout << "\r" << "time move = " << 0 << " " << data.Level_Vector[0].Objects[0].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[0].SoundMove)].timer.asSeconds();

        data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundMove)].sound.setVolume(25);

        data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].timer
        = data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].clock.getElapsedTime();

        if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[0].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(100);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[1].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(90);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[2].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(80);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[3].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(70);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[4].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(60);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[5].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(50);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[6].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(40);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[7].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(30);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[8].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(20);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Level_Vector[0].Objects[LoopNumber].Sound[i].Sound_Area[9].getGlobalBounds()))
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(10);
        }

        else
        {
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.setVolume(0);
        }

        if(data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].Play)
        {
            //std::cout << "\nIF";
            if(data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].timer.asSeconds()
            >= data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].start_time
            && data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].timer.asSeconds()
            <= data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].buffer.getDuration().asSeconds()//.end_time
            &&!data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].Playing)
            {
                //std::cout << " SUB_IF";
                data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].Playing = true;
                data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.play();
            }
        }

        else
        {
            //std::cout << "\nELSE";
            if(data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].Playing)
            {
                //std::cout << " SUB_ELSE";
                data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].Playing = false;
                data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].sound.stop();
            }
        }

        if(data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].timer.asSeconds()
        >= data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].buffer.getDuration().asSeconds())//.end_time)
        {
            //std::cout << "\nRESET";
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].Playing = false;
            data.Level_Vector[0].Objects[LoopNumber].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[LoopNumber].SoundMove)].clock.restart();
        }
    }
}
