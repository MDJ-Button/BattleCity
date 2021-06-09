#include "Data.hpp"
#include "Game.hpp"

void Game::SoundFx_Set()
{
    Data data;

    for(int i = 0; i < data.Fx_Vector.size(); i++)
    {
        data.Fx_Vector[i].Sound[0].VariableName
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Fx_Vector[i].SoundFx)].VariableName;

        data.Fx_Vector[i].Sound[0].VariableData
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Fx_Vector[i].SoundFx)].VariableData;

        data.Fx_Vector[i].Sound[0].sound_Path
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Fx_Vector[i].SoundFx)].sound_Path;

        data.Fx_Vector[i].Sound[0].start_time
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Fx_Vector[i].SoundFx)].start_time;

        data.Fx_Vector[i].Sound[0].end_time
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Fx_Vector[i].SoundFx)].end_time;

        data.Fx_Vector[i].Sound[0].Sound_Radius
        = data.Sound_Vector[Load(__func__, __LINE__, "Sounds", data.Fx_Vector[i].SoundFx)].Sound_Radius;
    }
}
