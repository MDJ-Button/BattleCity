#include "Game.hpp"
#include "Events.hpp"
#include "Controls.hpp"

void Game::Player(int Player_Number)
{
    Data data;
    Events key_event;
    Controls movement;
    if(key_event.KeyDown)
    {
        /**Move**/

        if(key_event.Key == movement.Up)
        {
            //std::cout << "\nP UP";
            data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundMove)].Play = true;
            data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundIdle)].Play = false;
            data.Level_Vector[0].Objects[Player_Number].Direction = Data::Objects::enumDirection::up;
            data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeedY = -data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeed;
        }
        else if(key_event.Key == movement.Down)
        {
            //std::cout << "\nP DOWN";
            data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundMove)].Play = true;
            data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundIdle)].Play = false;
            data.Level_Vector[0].Objects[Player_Number].Direction = Data::Objects::enumDirection::down;
            data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeedY = +data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeed;
        }
        else if(key_event.Key == movement.Left)
        {
            //std::cout << "\nP LEFT";
            data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundMove)].Play = true;
            data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundIdle)].Play = false;
            data.Level_Vector[0].Objects[Player_Number].Direction = Data::Objects::enumDirection::left;
            data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeedX = -data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeed;
        }
        else if(key_event.Key == movement.Right)
        {
            //std::cout << "\nP RIGHT";
            data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundMove)].Play = true;
            data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundIdle)].Play = false;
            data.Level_Vector[0].Objects[Player_Number].Direction = Data::Objects::enumDirection::right;
            data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeedX = +data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeed;
        }
    }

    else
    {
        data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundMove)].Play = false;
        data.Level_Vector[0].Objects[Player_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Level_Vector[0].Objects[Player_Number].SoundIdle)].Play = true;
        data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeedY = 0;
        data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeedX = 0;
    }

    data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].sprite.move(data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeedX,
                                                                                                                                          data.Level_Vector[0].Objects[Load(__func__, __LINE__, "Level_Objects", data.Level_Vector[0].Objects[Player_Number].Name)].MovementSpeedY);

    /**Shoot**/


}
