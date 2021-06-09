#include "Game.hpp"
#include "Events.hpp"
#include "Controls.hpp"

void Game::AI(int Bot_Number, float Waypoint_X, float Waypoint_Y)
{
    Data data;

    bool Moving_X = false;
    bool Moving_Y = false;

    if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].sprite.getPosition().x == Waypoint_X)
    {
        data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedX = 0;
        data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundMove)].Play = false;
        data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundIdle)].Play = true;
    }

    else
    {
        if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].sprite.getPosition().x > Waypoint_X
        && !Moving_Y)
        {
            //std::cout << "\nAI LEFT";
            data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedX = -data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeed;
            Moving_X = true;

            data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundMove)].Play = true;
            data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundIdle)].Play = false;
        }

        else if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].sprite.getPosition().x < Waypoint_X
             && !Moving_Y)
        {
            //std::cout << "\nAI RIGHT";
            data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedX = +data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeed;
            Moving_X = true;

            data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundMove)].Play = true;
            data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundIdle)].Play = false;
        }
    }

    if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].sprite.getPosition().y == Waypoint_Y)
    {
        data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedY = 0;
        data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundMove)].Play = false;
        data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundIdle)].Play = true;
    }

    else
    {
        if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].sprite.getPosition().y > Waypoint_Y
        && !Moving_X)
        {
            //std::cout << "\nAI UP";
            data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedY = -data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeed;
            Moving_Y = true;

            data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundMove)].Play = true;
            data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundIdle)].Play = false;
        }

        else if(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].sprite.getPosition().y < Waypoint_Y
             &&!Moving_X)
        {
            //std::cout << "\nAI DOWN";
            data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedY = +data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeed;
            Moving_Y = true;

            data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundMove)].Play = true;
            data.Objects_Vector[Bot_Number].Sound[Load(__func__, __LINE__, "Obj_Sounds", data.Objects_Vector[Bot_Number].SoundIdle)].Play = false;
        }
    }

    data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].sprite.move(data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedX,
                                                                                                     data.Objects_Vector[Load(__func__, __LINE__, "Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedY);

    //std::cout << " = " << data.Objects_Vector[Load("Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedX << ", " << data.Objects_Vector[Load("Objects", data.Objects_Vector[Bot_Number].Name)].MovementSpeedY;
}

