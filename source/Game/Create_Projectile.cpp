#include "Game.hpp"
#include "Data.hpp"

#include <iostream>
#include <string>
#include <windows.h>

void Game::Create_Projectile(int FromObject, float Speed, int Direction, float x, float y)
{
    Data data;
    Data::Projectile new_Projectile;

    new_Projectile.VariableName = "Projectile_" + std::to_string(data.Projectile_Vector.size());
    new_Projectile.VariableData = "Test";
    new_Projectile.Name = "Projectile_" + std::to_string(data.Projectile_Vector.size());
    new_Projectile.Texture = "bullet.png";
    new_Projectile.MovementSpeed = Speed;

    if(Direction == new_Projectile.up) new_Projectile.MovementSpeedY = -Speed;
    else if(Direction == new_Projectile.down) new_Projectile.MovementSpeedY = +Speed;
    else if(Direction == new_Projectile.left) new_Projectile.MovementSpeedX = -Speed;
    else if(Direction == new_Projectile.right) new_Projectile.MovementSpeedX = +Speed;

    new_Projectile.ScaleX = 1;
    new_Projectile.ScaleY = 1;

    new_Projectile.texture.loadFromFile(new_Projectile.Texture);
    new_Projectile.sprite.setTexture(new_Projectile.texture);
    new_Projectile.sprite.setScale(new_Projectile.ScaleX,
                                   new_Projectile.ScaleY);

    if(Direction == new_Projectile.up)
    {
        new_Projectile.Direction = new_Projectile.up;

        new_Projectile.sprite_IntRect.top = 1;
        new_Projectile.sprite_IntRect.left = 2;
        new_Projectile.sprite_IntRect.width = 3;
        new_Projectile.sprite_IntRect.height = 4;

        new_Projectile.sprite.setPosition(x + (data.Level_Vector[0].Objects[FromObject].sprite_IntRect.width
                                            *  data.Level_Vector[0].Objects[FromObject].ScaleX / 2
                                            -  new_Projectile.ScaleX),

                                          y - (new_Projectile.sprite_IntRect.height
                                            *  new_Projectile.ScaleY));
    }

    else if(Direction == new_Projectile.down)
    {
        new_Projectile.Direction = new_Projectile.down;

        new_Projectile.sprite_IntRect.top = 10;
        new_Projectile.sprite_IntRect.left = 2;
        new_Projectile.sprite_IntRect.width = 3;
        new_Projectile.sprite_IntRect.height = 4;

        new_Projectile.sprite.setPosition(x + (data.Level_Vector[0].Objects[FromObject].sprite_IntRect.width
                                            *  data.Level_Vector[0].Objects[FromObject].ScaleX / 2
                                            -  new_Projectile.ScaleX),

                                          y + (data.Level_Vector[0].Objects[FromObject].sprite_IntRect.height
                                            *  data.Level_Vector[0].Objects[FromObject].ScaleY));
    }

    else if(Direction == new_Projectile.left)
    {
        new_Projectile.Direction = new_Projectile.left;

        new_Projectile.sprite_IntRect.top = 6;
        new_Projectile.sprite_IntRect.left = 1;
        new_Projectile.sprite_IntRect.width = 4;
        new_Projectile.sprite_IntRect.height = 3;

        new_Projectile.sprite.setPosition(x - (new_Projectile.sprite_IntRect.width
                                            +  new_Projectile.ScaleX),

                                          y + (data.Level_Vector[0].Objects[FromObject].sprite_IntRect.height
                                            *  data.Level_Vector[0].Objects[FromObject].ScaleY / 2
                                            -  new_Projectile.ScaleY));
    }

    else if(Direction == new_Projectile.right)
    {
        new_Projectile.Direction = new_Projectile.right;

        new_Projectile.sprite_IntRect.top = 15;
        new_Projectile.sprite_IntRect.left = 1;
        new_Projectile.sprite_IntRect.width = 4;
        new_Projectile.sprite_IntRect.height = 3;

        new_Projectile.sprite.setPosition(x + (data.Level_Vector[0].Objects[FromObject].sprite_IntRect.width
                                            *  data.Level_Vector[0].Objects[FromObject].ScaleX
                                            +  new_Projectile.ScaleX),

                                          y + (data.Level_Vector[0].Objects[FromObject].sprite_IntRect.height
                                            *  data.Level_Vector[0].Objects[FromObject].ScaleY / 2
                                            -  new_Projectile.ScaleY));
    }

    new_Projectile.sprite.setTextureRect(new_Projectile.sprite_IntRect);

    data.Projectile_Vector.push_back(new_Projectile);
}
