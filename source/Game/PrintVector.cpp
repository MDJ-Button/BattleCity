#include "Game.hpp"

#include <iostream>
#include <vector>

#include "File.hpp"
#include "Data.hpp"

void Game::PrintVector(std::string _VectorName)
{
    Print(false, true, Func_Open("Game", "PrintVectors"));

    if(PrintVectors)
    {
        Print(false, false, Statement("if", "(DoPrint && PrintVectors)", "true"));
        std::cout << "Vector::" << _VectorName << " ---------------------------------------------------\n";

        if(_VectorName == "PrintOnceList") for(signed int i = 0; i < PrintOnceList.size(); i++) std::cout << PrintOnceList[i] << "\n";

        else if(_VectorName == "Data")
        {
            Data C_Data;
            File C_File;

            std::cout << "-Textures " << C_Data.Textures_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Textures_Vector.size(); i++)
            {
                std::cout << "Metadata = "              << C_Data.Textures_Vector[i].VariableName << " = " << C_Data.Textures_Vector[i].VariableData << "\n"
                          << "Name = "                  << C_Data.Textures_Vector[i].Name << "\n"
                          << "texture_Path = "          << C_Data.Textures_Vector[i].texture_Path << "\n";

                if(C_File.GetExtension(C_Data.Textures_Vector[i].VariableData) == ".texture")
                {
                    std::cout << "TextureRect = "           << C_Data.Textures_Vector[i].TextureRect_L << ", "
                                                            << C_Data.Textures_Vector[i].TextureRect_T << ", "
                                                            << C_Data.Textures_Vector[i].TextureRect_W << ", "
                                                            << C_Data.Textures_Vector[i].TextureRect_H << "\n"
                              << "Animation_Move_Up = "     << C_Data.Textures_Vector[i].Animation_Move_Up_Direction << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Up_Row << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Up_Reset << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Up_Add << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Up_Restart << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Up_Width << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Up_Height << "\n"
                              << "Animation_Move_Down = "   << C_Data.Textures_Vector[i].Animation_Move_Down_Direction << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Down_Row << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Down_Reset << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Down_Add << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Down_Restart << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Down_Width << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Down_Height << "\n"
                              << "Animation_Move_Left = "   << C_Data.Textures_Vector[i].Animation_Move_Left_Direction << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Left_Row << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Left_Reset << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Left_Add << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Left_Restart << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Left_Width << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Left_Height << "\n"
                              << "Animation_Move_Right = "  << C_Data.Textures_Vector[i].Animation_Move_Right_Direction << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Right_Row << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Right_Reset << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Right_Add << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Right_Restart << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Right_Width << ", "
                                                            << C_Data.Textures_Vector[i].Animation_Move_Right_Height << "\n"
                                                            << "\n\n";
                }
                else
                {
                    std::cout << "mAnimation = "            << C_Data.Textures_Vector[i].mAnimation_Direction << ", "
                                                            << C_Data.Textures_Vector[i].mAnimation_Row << ", "
                                                            << C_Data.Textures_Vector[i].mAnimation_Reset << ", "
                                                            << C_Data.Textures_Vector[i].mAnimation_Add << ", "
                                                            << C_Data.Textures_Vector[i].mAnimation_Restart << ", "
                                                            << C_Data.Textures_Vector[i].mAnimation_Width << ", "
                                                            << C_Data.Textures_Vector[i].mAnimation_Height << ", "
                                                            << C_Data.Textures_Vector[i].mAnimationSpeed << ", "
                                                            << C_Data.Textures_Vector[i].mAnimation_Repeat << "\n"
                                                            << "\n\n";
                }
            }

            std::cout << "-Music " << C_Data.Music_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Music_Vector.size(); i++)
                std::cout << "Metadata = "          << C_Data.Music_Vector[i].VariableName << " = " << C_Data.Music_Vector[i].VariableData << "\n"
                          << "Name = "              << C_Data.Music_Vector[i].Name << "\n"
                          << "track_Path = "        << C_Data.Music_Vector[i].track_Path
                          << "\n\n";

            std::cout << "-Sound " << C_Data.Sound_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Sound_Vector.size(); i++)
                std::cout << "Metadata = "          << C_Data.Sound_Vector[i].VariableName << " = " << C_Data.Sound_Vector[i].VariableData << "\n"
                          << "Name = "              << C_Data.Sound_Vector[i].Name << "\n"
                          << "sound_Path = "        << C_Data.Sound_Vector[i].sound_Path << "\n"
                          << "Start_Time = "        << C_Data.Sound_Vector[i].start_time << "\n"
                          << "End_Time = "          << C_Data.Sound_Vector[i].end_time << "\n"
                          << "Sound_Radius = "      << C_Data.Sound_Vector[i].Sound_Radius << "\n"
                          << "\n\n";

            std::cout << "-Objects " << C_Data.Objects_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Objects_Vector.size(); i++)
            {
                std::cout << "Metadata = "          << C_Data.Objects_Vector[i].VariableName << " = " << C_Data.Objects_Vector[i].VariableData << "\n"
                          << "Name = "              << C_Data.Objects_Vector[i].Name << "\n"
                          << "Texture = "           << C_Data.Objects_Vector[i].Texture << "\n"
                          << "Death_Fx = "          << C_Data.Objects_Vector[i].Death_Fx << "\n"
                          << "Position = "          << C_Data.Objects_Vector[i].Position.x << ", " << C_Data.Objects_Vector[i].Position.y << "\n"
                          << "ScaleX = "            << C_Data.Objects_Vector[i].ScaleX << "\n"
                          << "ScaleY = "            << C_Data.Objects_Vector[i].ScaleY << "\n"
                          << "MovementSpeed = "     << C_Data.Objects_Vector[i].MovementSpeed << "\n"
                          << "SoundIdle = "         << C_Data.Objects_Vector[i].SoundIdle << "\n"
                          << "SoundMove = "         << C_Data.Objects_Vector[i].SoundMove << "\n\n";

                for(signed int x = 0; x < C_Data.Objects_Vector[i].Sound.size(); x++)
                {
                    std::cout << "  Metadata = "          << C_Data.Objects_Vector[i].Sound[x].VariableName << " = " << C_Data.Objects_Vector[i].Sound[x].VariableData << "\n"
                              << "  Name = "              << C_Data.Objects_Vector[i].Sound[x].Name << "\n"
                              << "  sound_Path = "        << C_Data.Objects_Vector[i].Sound[x].sound_Path << "\n"
                              << "  Start_Time = "        << C_Data.Objects_Vector[i].Sound[x].start_time << "\n"
                              << "  End_Time = "          << C_Data.Objects_Vector[i].Sound[x].end_time << "\n"
                              << "  Sound_Radius = "      << C_Data.Objects_Vector[i].Sound[x].Sound_Radius << "\n"
                              << "\n";
                }

                std::cout << "\n\n";
            }

            std::cout << "-Text " << C_Data.Text_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Text_Vector.size(); i++)
                std::cout << "Metadata = "          << C_Data.Text_Vector[i].VariableName << " = " << C_Data.Text_Vector[i].VariableData << "\n"
                          << "Name = "              << C_Data.Text_Vector[i].Name << "\n"
                          << "Font_Path = "         << C_Data.Text_Vector[i].Font_Path << "\n"
                          << "Message = "           << C_Data.Text_Vector[i].Message << "\n"
                          << "CharacterSize = "     << C_Data.Text_Vector[i].CharacterSize << "\n"
                          << "TextColor.r = "       << C_Data.Text_Vector[i].TextColor_r << "\n"
                          << "TextColor.g = "       << C_Data.Text_Vector[i].TextColor_g << "\n"
                          << "TextColor.b = "       << C_Data.Text_Vector[i].TextColor_b << "\n"
                          << "TextColor.a = "       << C_Data.Text_Vector[i].TextColor_a << "\n"
                          << "Bold = "              << C_Data.Text_Vector[i].isBold << "\n"
                          << "Italic = "            << C_Data.Text_Vector[i].isItalic << "\n"
                          << "StrikeThrough = "     << C_Data.Text_Vector[i].isStrikeThrough << "\n"
                          << "Underlined = "        << C_Data.Text_Vector[i].isUnderlined << "\n"
                          << "ScaleX = "            << C_Data.Text_Vector[i].ScaleX << "\n"
                          << "ScaleY = "            << C_Data.Text_Vector[i].ScaleY << "\n"
                          << "Position_X = "        << C_Data.Text_Vector[i].Position_X << "\n"
                          << "Position_Y = "        << C_Data.Text_Vector[i].Position_Y << "\n"
                          << "\n\n";

            std::cout << "-Grid_Text " << Grid_Text_Vector.size() << "\n";
            for(signed int i = 0; i < Grid_Text_Vector.size(); i++)
                std::cout << "Metadata = "          << Grid_Text_Vector[i].VariableName << " = " << Grid_Text_Vector[i].VariableData << "\n"
                          << "Name = "              << Grid_Text_Vector[i].Name << "\n"
                          << "Font_Path = "         << Grid_Text_Vector[i].Font_Path << "\n"
                          << "Message = "           << Grid_Text_Vector[i].Message << "\n"
                          << "CharacterSize = "     << Grid_Text_Vector[i].CharacterSize << "\n"
                          << "TextColor.r = "       << Grid_Text_Vector[i].TextColor_r << "\n"
                          << "TextColor.g = "       << Grid_Text_Vector[i].TextColor_g << "\n"
                          << "TextColor.b = "       << Grid_Text_Vector[i].TextColor_b << "\n"
                          << "TextColor.a = "       << Grid_Text_Vector[i].TextColor_a << "\n"
                          << "Bold = "              << Grid_Text_Vector[i].isBold << "\n"
                          << "Italic = "            << Grid_Text_Vector[i].isItalic << "\n"
                          << "StrikeThrough = "     << Grid_Text_Vector[i].isStrikeThrough << "\n"
                          << "Underlined = "        << Grid_Text_Vector[i].isUnderlined << "\n"
                          << "ScaleX = "            << Grid_Text_Vector[i].ScaleX << "\n"
                          << "ScaleY = "            << Grid_Text_Vector[i].ScaleY << "\n"
                          << "Position_X = "        << Grid_Text_Vector[i].Position_X << "\n"
                          << "Position_Y = "        << Grid_Text_Vector[i].Position_Y << "\n"
                          << "\n\n";




            std::cout << "-Map_Objects " << C_Data.Map_Objects_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Map_Objects_Vector.size(); i++)
            {
                std::cout << "Metadata = "          << C_Data.Map_Objects_Vector[i].VariableName << " = " << C_Data.Map_Objects_Vector[i].VariableData << "\n"
                          << "Name = "              << C_Data.Map_Objects_Vector[i].Name << "\n"
                          << "Texture = "           << C_Data.Map_Objects_Vector[i].Texture << "\n"
                          << "Death_Fx = "          << C_Data.Map_Objects_Vector[i].Death_Fx << "\n"
                          << "Position = "          << C_Data.Map_Objects_Vector[i].Position.x << ", " << C_Data.Map_Objects_Vector[i].Position.y << "\n"
                          << "SoundIdle = "         << C_Data.Map_Objects_Vector[i].SoundIdle << "\n"
                          << "ScaleX = "            << C_Data.Map_Objects_Vector[i].ScaleX << "\n"
                          << "ScaleY = "            << C_Data.Map_Objects_Vector[i].ScaleY << "\n\n";

                for(signed int x = 0; x < C_Data.Map_Objects_Vector[i].Sound.size(); x++)
                {
                    std::cout << "  Metadata = "          << C_Data.Map_Objects_Vector[i].Sound[x].VariableName << " = " << C_Data.Objects_Vector[i].Sound[x].VariableData << "\n"
                              << "  Name = "              << C_Data.Map_Objects_Vector[i].Sound[x].Name << "\n"
                              << "  sound_Path = "        << C_Data.Map_Objects_Vector[i].Sound[x].sound_Path << "\n"
                              << "  Start_Time = "        << C_Data.Map_Objects_Vector[i].Sound[x].start_time << "\n"
                              << "  End_Time = "          << C_Data.Map_Objects_Vector[i].Sound[x].end_time << "\n"
                              << "  Sound_Radius = "      << C_Data.Map_Objects_Vector[i].Sound[x].Sound_Radius << "\n"
                              << "\n";
                }

                std::cout << "\n\n";
            }

            std::cout << "-Level " << C_Data.Level_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Level_Vector.size(); i++)
            {
                std::cout << "Metadata = "          << C_Data.Level_Vector[i].VariableName << " = " << C_Data.Level_Vector[i].VariableData << "\n"
                          << "Name = "              << C_Data.Level_Vector[i].Name << "\n\n";
                for(signed int x = 0; x < C_Data.Level_Vector[i].Map_Objects.size(); x++)
                {
                    std::cout << "  Metadata = "          << C_Data.Level_Vector[i].Map_Objects[x].VariableName << " = " << C_Data.Level_Vector[i].Map_Objects[x].VariableData << "\n"
                              << "  Name = "              << C_Data.Level_Vector[i].Map_Objects[x].Name << "\n"
                              << "  Texture = "           << C_Data.Level_Vector[i].Map_Objects[x].Texture << "\n"
                              << "  Death_Fx = "          << C_Data.Level_Vector[i].Map_Objects[x].Death_Fx << "\n"
                              << "  Position = "          << C_Data.Level_Vector[i].Map_Objects[x].Position.x << ", " << C_Data.Level_Vector[i].Map_Objects[x].Position.y << "\n"
                              << "  SoundIdle = "         << C_Data.Level_Vector[i].Map_Objects[x].SoundIdle << "\n"
                              << "  ScaleX = "            << C_Data.Level_Vector[i].Map_Objects[x].ScaleX << "\n"
                              << "  ScaleY = "            << C_Data.Level_Vector[i].Map_Objects[x].ScaleY << "\n\n";

                    for(signed int x_s = 0; x_s < C_Data.Level_Vector[i].Map_Objects[x].Sound.size(); x_s++)
                    {
                        std::cout << "  Metadata = "          << C_Data.Level_Vector[i].Map_Objects[x].Sound[x_s].VariableName << " = " << C_Data.Level_Vector[i].Map_Objects[x].Sound[x_s].VariableData << "\n"
                                  << "  Name = "              << C_Data.Level_Vector[i].Map_Objects[x].Sound[x_s].Name << "\n"
                                  << "  sound_Path = "        << C_Data.Level_Vector[i].Map_Objects[x].Sound[x_s].sound_Path << "\n"
                                  << "  Start_Time = "        << C_Data.Level_Vector[i].Map_Objects[x].Sound[x_s].start_time << "\n"
                                  << "  End_Time = "          << C_Data.Level_Vector[i].Map_Objects[x].Sound[x_s].end_time << "\n"
                                  << "  Sound_Radius = "      << C_Data.Level_Vector[i].Map_Objects[x].Sound[x_s].Sound_Radius << "\n"
                                  << "\n";
                    }
                    std::cout << "\n\n";
                }
                std::cout << "\n\n";
            }

            std::cout << "-Projectile " << C_Data.Projectile_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Projectile_Vector.size(); i++)
                std::cout << "Metadata = "          << C_Data.Projectile_Vector[i].VariableName << " = " << C_Data.Projectile_Vector[i].VariableData << "\n"
                          << "Name = "              << C_Data.Projectile_Vector[i].Name << "\n"
                          << "Texture = "           << C_Data.Projectile_Vector[i].Texture << "\n"
                          << "Position = "          << C_Data.Projectile_Vector[i].Position.x << ", " << C_Data.Projectile_Vector[i].Position.y << "\n"
                          << "ScaleX = "            << C_Data.Projectile_Vector[i].ScaleX << "\n"
                          << "ScaleY = "            << C_Data.Projectile_Vector[i].ScaleY << "\n"
                          << "\n\n";

            std::cout << "-Fx " << C_Data.Fx_Vector.size() << "\n";
            for(signed int i = 0; i < C_Data.Fx_Vector.size(); i++)
            {
                std::cout << "Metadata = "          << C_Data.Fx_Vector[i].VariableName << " = " << C_Data.Fx_Vector[i].VariableData << "\n"
                          << "Name = "              << C_Data.Fx_Vector[i].Name << "\n"
                          << "Texture = "           << C_Data.Fx_Vector[i].texture_Path << "\n"
                          << "SoundFx = "           << C_Data.Fx_Vector[i].SoundFx << "\n"
                          << "\n\n";

                for(signed int x = 0; x < C_Data.Fx_Vector[i].Sound.size(); x++)
                {
                    std::cout << "  Metadata = "          << C_Data.Fx_Vector[i].Sound[x].VariableName << " = " << C_Data.Fx_Vector[i].Sound[x].VariableData << "\n"
                              << "  Name = "              << C_Data.Fx_Vector[i].Sound[x].Name << "\n"
                              << "  sound_Path = "        << C_Data.Fx_Vector[i].Sound[x].sound_Path << "\n"
                              << "  Start_Time = "        << C_Data.Fx_Vector[i].Sound[x].start_time << "\n"
                              << "  End_Time = "          << C_Data.Fx_Vector[i].Sound[x].end_time << "\n"
                              << "  Sound_Radius = "      << C_Data.Fx_Vector[i].Sound[x].Sound_Radius << "\n"
                              << "\n";
                }
            }
        }

        else std::cout << "Cannot find a vector by the name of " << _VectorName << "\n";

        std::cout << "Vector::" << _VectorName << " ---------------------------------------------------\n";
    }

    else Print(false, false,Statement("else", "(DoPrint && PrintVectors)", "false"));
}
