#include "Game.hpp"
#include "Data.hpp"

void Game::Remove_Obj_From_Vector(std::string FromVector, int IndexNumber)
{
    Data data;
    std::string Name;

    if(FromVector == "Objects_Vector")
    {
        Name = data.Objects_Vector[IndexNumber].Name;
        data.Objects_Vector.erase(std::remove_if(data.Objects_Vector.begin(), data.Objects_Vector.end(), [&Name](const Data::Objects& myclass)->bool
        {
            return myclass.Name == Name;
        }), data.Objects_Vector.end());
    }

    else if(FromVector == "Map_Objects_Vector")
    {
        Name = data.Map_Objects_Vector[IndexNumber].Name;
        data.Map_Objects_Vector.erase(std::remove_if(data.Map_Objects_Vector.begin(), data.Map_Objects_Vector.end(), [&Name](const Data::Map_Objects& myclass)->bool
        {
            return myclass.Name == Name;
        }), data.Map_Objects_Vector.end());
    }

    else if(FromVector == "Projectile_Vector")
    {
        Name = data.Projectile_Vector[IndexNumber].Name;
        data.Projectile_Vector.erase(std::remove_if(data.Projectile_Vector.begin(), data.Projectile_Vector.end(), [&Name](const Data::Projectile& myclass)->bool
        {
            return myclass.Name == Name;
        }), data.Projectile_Vector.end());
    }

    else if(FromVector == "FX_Vector")
    {
        Name = data.Fx_To_Play_Vector[IndexNumber].Name;
        data.Fx_To_Play_Vector.erase(std::remove_if(data.Fx_To_Play_Vector.begin(), data.Fx_To_Play_Vector.end(), [&Name](const Data::Fx& myclass)->bool
        {
            return myclass.Name == Name;
        }), data.Fx_To_Play_Vector.end());
    }
}
