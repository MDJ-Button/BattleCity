#include "Data.hpp"
#include "Game.hpp"

void Game::Play_SoundFx(int LoopNumber)
{
    Data data;

    for(int i = 0; i < data.Fx_To_Play_Vector[LoopNumber].Sound.size(); i++)
    {
        data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].timer
        = data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].clock.getElapsedTime();

        if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[0].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(100);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[1].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(90);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[2].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(80);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[3].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(70);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[4].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(60);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[5].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(50);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[6].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(40);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[7].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(30);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[8].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(20);
        }

        else if(data.Level_Vector[0].Objects[Player_Number].sprite.getGlobalBounds().intersects(data.Fx_To_Play_Vector[LoopNumber].Sound[i].Sound_Area[9].getGlobalBounds()))
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(10);
        }

        else
        {
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.setVolume(0);
        }

        if(data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].Play)
        {
            //std::cout << "\nIF";
            /*if(data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].timer.asSeconds()
            >= data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].start_time
            && data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].timer.asSeconds()
            <= data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].end_time
            &&!data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].Playing)*/
            if(data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].timer.asSeconds()
            >= data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].start_time
            && data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].timer.asSeconds()
            <= data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].buffer.getDuration().asSeconds()
            &&!data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].Playing)
            {
                //std::cout << " SUB_IF";
                data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].Playing = true;
                data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.play();
            }
        }

        else
        {
            //std::cout << "\nELSE";
            if(data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].Playing)
            {
                //std::cout << " SUB_ELSE";
                data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].Playing = false;
                data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].sound.stop();
            }
        }

        if(data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].timer.asSeconds()
        >= data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].buffer.getDuration().asSeconds())//.end_time)
        {
            //std::cout << "\nRESET";
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].Playing = false;
            data.Fx_To_Play_Vector[LoopNumber].Sound[Load(__func__, __LINE__, "Fx_Sounds", data.Fx_To_Play_Vector[LoopNumber].SoundFx)].clock.restart();
        }
    }
}
