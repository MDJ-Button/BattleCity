#include <vector>
#include <iostream>

#include "Game.hpp"
#include "File.hpp"
#include "Data.hpp"
#include "Events.hpp"
#include "Controls.hpp"

#include <SFML/Graphics.hpp>

bool                                                 Game::Grid_Draw;
std::vector<sf::RectangleShape>                      Game::Grid_Vector;
std::vector<Data::Text>                              Game::Grid_Text_Vector;
int                                                  Game::Grid_Size_X;
int                                                  Game::Grid_Size_Y;
sf::Color                                            Game::Grid_Color;
bool                                                 Game::PrintVectors;
bool                                                 Game::DoPrint;
std::vector<std::string>                             Game::PrintOnceList;
bool                                                 Game::TerminateApplication;
int                                                  Game::Player_Number;
bool                                                 Game::Window_ShowFPS;
std::string                                          Game::Window_ShowFPS_Top_OR_Bottom;
std::string                                          Game::Window_ShowFPS_Left_OR_Right;
bool                                                 Game::Builder_Enable;
std::vector<std::string>                             Game::DontDraw;
int                                                  Game::FPS_Limit;
int                                                  Game::Window_Size_X;
int                                                  Game::Window_Size_Y;
bool                                                 Game::Window_Fullscreen = false;
bool                                                 Game::bSetFPS = false;
bool                                                 Game::Game_Show_Sound_Boxes;

std::vector<Data::Textures>                          Data::Textures_Vector;
std::vector<Data::Music>                             Data::Music_Vector;
std::vector<Data::Sound>                             Data::Sound_Vector;
std::vector<Data::Objects>                           Data::Objects_Vector;
std::vector<Data::Text>                              Data::Text_Vector;
std::vector<Data::Text>                              Data::Grid_Text_Vector;
std::vector<Data::Map_Objects>                       Data::Map_Objects_Vector;
std::vector<Data::Level>                             Data::Level_Vector;
std::vector<Data::Projectile>                        Data::Projectile_Vector;
std::vector<Data::Fx>                                Data::Fx_Vector;
std::vector<Data::Fx>                                Data::Fx_To_Play_Vector;

bool                                                 Events::KeyDown;
bool                                                 Events::Mouse_ButtonDown;
std::string                                          Events::Key;

std::string                                          Controls::Up;
std::string                                          Controls::Down;
std::string                                          Controls::Left;
std::string                                          Controls::Right;
std::string                                          Controls::Shoot;
std::string                                          Controls::Accelerate;
