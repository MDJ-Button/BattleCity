#include "Game.hpp"

void Game::Set_Game_Data(bool Game_Show_Sound_Boxes)
{
    Sound_Set();
    SoundFx_Set();
    Text_Set();
    Object_Set(Game_Show_Sound_Boxes);
    Map_Object_Set();
}
