#include "Game.hpp"
#include "Data.hpp"
#include <windows.h>

void Game::Text_Set()
{
    Data data;

    for(signed int i = 2; i < data.Text_Vector.size(); i++)
    {
        data.Text_Vector[i].font.loadFromFile(data.Text_Vector[i].Font_Path);
        data.Text_Vector[i].text.setFont(data.Text_Vector[i].font);
        data.Text_Vector[i].text.setString(data.Text_Vector[i].Message);
        data.Text_Vector[i].text.setCharacterSize(data.Text_Vector[i].CharacterSize);
        data.Text_Vector[i].TextColor.r = data.Text_Vector[i].TextColor_r;
        data.Text_Vector[i].TextColor.g = data.Text_Vector[i].TextColor_g;
        data.Text_Vector[i].TextColor.b = data.Text_Vector[i].TextColor_b;
        data.Text_Vector[i].TextColor.a = data.Text_Vector[i].TextColor_a;
        data.Text_Vector[i].text.setFillColor(data.Text_Vector[i].TextColor);

        data.Text_Vector[i].text.setStyle(data.Text_Vector[i].fBold(data.Text_Vector[i].isBold) |
                                                                    data.Text_Vector[i].fItalic(data.Text_Vector[i].isItalic) |
                                                                    data.Text_Vector[i].fStrikeThrough(data.Text_Vector[i].isStrikeThrough) |
                                                                    data.Text_Vector[i].fUnderlined(data.Text_Vector[i].isUnderlined));

        data.Text_Vector[i].text.setScale(sf::Vector2f(data.Text_Vector[i].ScaleX,
                                                       data.Text_Vector[i].ScaleY));

        data.Text_Vector[i].text.setPosition(sf::Vector2f(data.Text_Vector[i].Position_X, data.Text_Vector[i].Position_Y));
    }
}
