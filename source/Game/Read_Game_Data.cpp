#include "Game.hpp"
#include "File.hpp"
#include "Data.hpp"

void Game::Read_Game_Data()
{
    //Read data from the metadata file.
    File file;
    file.Read("Data\\metadata.txt", "Metadata", false, 0);

    //Read data from the data files gotten from the metadata.
    Data data;
    for(int i = 0; i < data.Textures_Vector.size(); i++)
        file.Read(data.Textures_Vector[i].VariableData, "Gamedata_Textures", true, i);

    for(int i = 0; i < data.Music_Vector.size(); i++)
        file.Read(data.Music_Vector[i].VariableData, "Gamedata_Music", true, i);

    for(int i = 0; i < data.Sound_Vector.size(); i++)
        file.Read(data.Sound_Vector[i].VariableData, "Gamedata_Sounds", true, i);

    for(int i = 0; i < data.Objects_Vector.size(); i++)
        file.Read(data.Objects_Vector[i].VariableData, "Gamedata_Objects", true, i);

    for(int i = 0; i < data.Text_Vector.size(); i++)
        file.Read(data.Text_Vector[i].VariableData, "Gamedata_Text", true, i);

    for(int i = 0; i < data.Map_Objects_Vector.size(); i++)
        file.Read(data.Map_Objects_Vector[i].VariableData, "Gamedata_Map_Objects", true, i);

    for(int i = 0; i < data.Level_Vector.size(); i++)
        file.Read(data.Level_Vector[i].VariableData, "Gamedata_Level", true, i);

    for(int i = 0; i < data.Fx_Vector.size(); i++)
        file.Read(data.Fx_Vector[i].VariableData, "Gamedata_Fx", true, i);
}
