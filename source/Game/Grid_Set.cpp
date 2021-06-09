#include "Game.hpp"
#include "Data.hpp"

#include <string>

void Game::Grid_Set(bool Reset)
{
    Data data;

    if(Reset)
    {
        Grid_Vector.clear();
        Grid_Text_Vector.clear();
    }

    for(int x = 0; x < window.getSize().x / Grid_Size_X; x++)
    {
        for(int y = 0; y < window.getSize().y / Grid_Size_Y; y++)
        {
            sf::RectangleShape Grid;
            Grid.setSize(sf::Vector2f(Grid_Size_X, Grid_Size_Y));
            Grid.setFillColor(sf::Color::Transparent);
            Grid.setOutlineColor(Grid_Color);
            Grid.setOutlineThickness(1);
            Grid.setPosition(Grid.getSize().x*x, Grid.getSize().y*y);
            Grid_Vector.push_back(Grid);
        }
    }

    for(int i = 0; i < Grid_Vector.size(); i++)
    {
        Data::Text text;

        text.VariableName = "Grid_Numbers_" + std::to_string(i);
        text.Name = "Grid_Numbers_" + std::to_string(data.Grid_Text_Vector.size() + 1);
        Grid_Text_Vector.push_back(text);

        Grid_Text_Vector[i].VariableData = data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].VariableData;
        Grid_Text_Vector[i].Font_Path = data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].Font_Path;
        Grid_Text_Vector[i].Message = data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].Message;
        Grid_Text_Vector[i].CharacterSize = data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].CharacterSize;

        Grid_Text_Vector[i].font.loadFromFile(data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].Font_Path);
        Grid_Text_Vector[i].text.setFont(data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].font);
        Grid_Text_Vector[i].text.setString(std::to_string(i));
        Grid_Text_Vector[i].text.setCharacterSize(data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].CharacterSize);

        Grid_Text_Vector[i].TextColor.r = data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].TextColor_r;
        Grid_Text_Vector[i].TextColor.g = data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].TextColor_g;
        Grid_Text_Vector[i].TextColor.b = data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].TextColor_b;
        Grid_Text_Vector[i].TextColor.a = data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].TextColor_a;
        Grid_Text_Vector[i].text.setFillColor(Grid_Text_Vector[i].TextColor);

        Grid_Text_Vector[i].text.setStyle(data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].fBold(data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].isBold) |
                                                                                                         data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].fItalic(data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].isItalic) |
                                                                                                         data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].fStrikeThrough(data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].isStrikeThrough) |
                                                                                                         data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].fUnderlined(data.Text_Vector[Load(__func__, __LINE__, "Text", "Grid_Numbers")].isUnderlined));
        Grid_Text_Vector[i].text.setPosition(sf::Vector2f(Grid_Vector[i].getPosition().x,
                                                          Grid_Vector[i].getPosition().y));
    }
}
