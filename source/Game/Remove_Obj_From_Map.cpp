#include "Game.hpp"
#include "Data.hpp"

void Game::Remove_Obj_From_Map(std::string FromVector, int IndexNumber, float MoveToX, float MoveToY)
{
    Data data;

    if(FromVector == "Objects_Vector")
    {
        data.Objects_Vector[IndexNumber].State = Data::Objects::enumState::dead;
        data.Objects_Vector[IndexNumber].sprite.setPosition(MoveToX, MoveToY);

        data.Objects_Vector[IndexNumber].sprite_IntRect.top = 0;
        data.Objects_Vector[IndexNumber].sprite_IntRect.left = 0;
        data.Objects_Vector[IndexNumber].sprite_IntRect.width = 0;
        data.Objects_Vector[IndexNumber].sprite_IntRect.height = 0;
        data.Objects_Vector[IndexNumber].sprite.setTextureRect(data.Objects_Vector[IndexNumber].sprite_IntRect);
    }

    else if(FromVector == "Map_Objects_Vector")
    {
        data.Map_Objects_Vector[IndexNumber].sprite.setPosition(MoveToX, MoveToY);
    }

    else if(FromVector == "Projectile_Vector")
    {
        data.Projectile_Vector[IndexNumber].sprite.setPosition(MoveToX, MoveToY);
    }
}
