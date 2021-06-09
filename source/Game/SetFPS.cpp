#include "Game.hpp"
#include "Data.hpp"

void Game::SetFPS()
{
    Data data;

    if(!bSetFPS)
    {
        FPS_previousTime = clock.getElapsedTime();
        bSetFPS = true;
    }

    FPS_currentTime = clock.getElapsedTime();
    FPS = 1.0f / (FPS_currentTime.asSeconds() - FPS_previousTime.asSeconds());
    int ifps = FPS;
    data.Text_Vector[Load(__func__, __LINE__, "Text", "FPS_Counter")].text.setString(std::to_string(ifps));
    FPS_previousTime = FPS_currentTime;
}
