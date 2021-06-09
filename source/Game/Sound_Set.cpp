#include "Data.hpp"
#include "Game.hpp"

void Game::Sound_Set()
{
    Data data;

    for(int i = 0; i < data.Sound_Vector.size(); i++)
    {
        data.Sound_Vector[i].buffer.loadFromFile(data.Sound_Vector[i].sound_Path);
        data.Sound_Vector[i].sound.setBuffer(data.Sound_Vector[i].buffer);
    }
}


