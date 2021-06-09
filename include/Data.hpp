#ifndef DATA_H
#define DATA_H

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Data
{
    public:

    class Textures
    {
        public:
        std::string VariableName;
        std::string VariableData;

        std::string Name;
        std::string texture_Path;

        int TextureRect_L;
        int TextureRect_T;
        int TextureRect_W;
        int TextureRect_H;

        std::string mAnimation;
        std::string mAnimation_Direction;
        int mAnimation_Row;
        int mAnimation_Reset;
        int mAnimation_Add;
        int mAnimation_Restart;
        int mAnimation_Width;
        int mAnimation_Height;
        bool mAnimation_Repeat;
        bool mAnimation_Play = false;
        float mAnimationSpeed;
        float Previous_mTime;
        sf::Time mTime;

        std::string Animation_Move_Up;
        std::string Animation_Move_Up_Direction;
        int Animation_Move_Up_Row;
        int Animation_Move_Up_Reset;
        int Animation_Move_Up_Add;
        int Animation_Move_Up_Restart;
        int Animation_Move_Up_Width;
        int Animation_Move_Up_Height;
        bool Animation_Move_Up_Play = false;
        float AnimationSpeed_Up;
        float Previous_Time_Up;
        sf::Time Time_Up;

        std::string Animation_Move_Down;
        std::string Animation_Move_Down_Direction;
        int Animation_Move_Down_Row;
        int Animation_Move_Down_Reset;
        int Animation_Move_Down_Add;
        int Animation_Move_Down_Restart;
        int Animation_Move_Down_Width;
        int Animation_Move_Down_Height;
        bool Animation_Move_Down_Play = false;
        float AnimationSpeed_Down;
        float Previous_Time_Down;
        sf::Time Time_Down;

        std::string Animation_Move_Left;
        std::string Animation_Move_Left_Direction;
        int Animation_Move_Left_Row;
        int Animation_Move_Left_Reset;
        int Animation_Move_Left_Add;
        int Animation_Move_Left_Restart;
        int Animation_Move_Left_Width;
        int Animation_Move_Left_Height;
        bool Animation_Move_Left_Play = false;
        float AnimationSpeed_Left;
        float Previous_Time_Left;
        sf::Time Time_Left;

        std::string Animation_Move_Right;
        std::string Animation_Move_Right_Direction;
        int Animation_Move_Right_Row;
        int Animation_Move_Right_Reset;
        int Animation_Move_Right_Add;
        int Animation_Move_Right_Restart;
        int Animation_Move_Right_Width;
        int Animation_Move_Right_Height;
        bool Animation_Move_Right_Play = false;
        float AnimationSpeed_Right;
        float Previous_Time_Right;
        sf::Time Time_Right;
    };

    class Music
    {
        public:
        std::string VariableName;
        std::string VariableData;

        std::string Name;
        std::string track_Path;
    };

    class Sound
    {
        public:
        std::string VariableName;
        std::string VariableData;

        std::string Name;
        std::string sound_Path;

        float start_time;
        float end_time;

        int Sound_Radius;

        bool Playing = false;
        bool Play = false;

        sf::SoundBuffer buffer;
        sf::Sound sound;

        sf::Clock clock;
        sf::Time timer;

        std::vector<sf::RectangleShape> Sound_Area;
    };

    class Objects
    {
        public:

        std::string VariableName;
        std::string VariableData;

        std::string Name;
        std::string Texture;

        int ScaleX;
        int ScaleY;

        float MovementSpeed;
        float MovementSpeedX;
        float MovementSpeedY;

        sf::Texture  texture;
        sf::Sprite   sprite;
        sf::Sprite   GetSprite(){sprite.setTexture(texture); return sprite;}
        sf::IntRect  sprite_IntRect;
        sf::Vector2f Position;

        int Collided;
        enum enumCollided
        {
            Collided_up,
            Collided_down,
            Collided_left,
            Collided_right,
            Collided_none
        };

        int State;
        enum enumState
        {
            alive,
            dead,
            removed
        };

        std::string StartingDirection;

        int Direction;
        enum enumDirection
        {
            up,
            down,
            left,
            right
        };

        std::string Death_Fx;

        std::string SoundIdle;
        std::string SoundMove;

        std::vector<Sound> Sound;
    };

    class Text
    {
        public:
        sf::Text text;
        sf::Font font;
        sf::Color TextColor;
        sf::Text GetText()
        {
            text.setFont(font);
            return text;
        }

        std::string VariableName;
        std::string VariableData;
        std::string Name;
        std::string Font_Path;
        std::string Message;
        int CharacterSize;
        float TextColor_r;
        float TextColor_g;
        float TextColor_b;
        float TextColor_a;
        bool isBold = false;
        bool isItalic = false;
        bool isStrikeThrough = false;
        bool isUnderlined = false;
        uint32_t fBold(bool _bool){if(_bool) return sf::Text::Bold; else return sf::Text::Regular;}
        uint32_t fItalic(bool _bool){if(_bool) return sf::Text::Italic; else return sf::Text::Regular;}
        uint32_t fStrikeThrough(bool _bool){if(_bool) return sf::Text::StrikeThrough; else return sf::Text::Regular;}
        uint32_t fUnderlined(bool _bool){if(_bool) return sf::Text::Underlined; else return sf::Text::Regular;}
        int ScaleX;
        int ScaleY;
        float Position_X;
        float Position_Y;
    };

    class Map_Objects
    {
        public:
        std::string VariableName;
        std::string VariableData;

        std::string Name;
        std::string Texture;

        int ScaleX;
        int ScaleY;

        sf::Texture  texture;
        sf::Sprite   sprite;
        sf::Sprite   GetSprite(){sprite.setTexture(texture); return sprite;}
        sf::IntRect  sprite_IntRect;
        sf::Vector2f Position;

        std::string Death_Fx;

        int Destroy = 4;

        std::string SoundIdle;

        std::vector<Sound> Sound;

        //int size_x = sprite_IntRect.width;
        //int size_y = sprite_IntRect.height;
    };

    class Projectile
    {
        public:
        std::string VariableName;
        std::string VariableData;

        std::string Name;
        std::string Texture;

        int ScaleX;
        int ScaleY;

        float MovementSpeed;
        float MovementSpeedX;
        float MovementSpeedY;

        sf::Texture  texture;
        sf::Sprite   sprite;
        sf::Sprite   GetSprite(){sprite.setTexture(texture); return sprite;}
        sf::IntRect  sprite_IntRect;
        sf::Vector2f Position;

        int Direction;
        enum enumDirection
        {
            up,
            down,
            left,
            right
        };
    };

    class Fx
    {
        public:
        std::string VariableName;
        std::string VariableData;

        std::string Name;
        std::string texture_Path;

        int ScaleX;
        int ScaleY;

        sf::Texture  texture;
        sf::Sprite   sprite;
        sf::Sprite   GetSprite(){sprite.setTexture(texture); return sprite;}
        sf::IntRect  sprite_IntRect;

        class List
        {
            public:
            std::string data;
            int number;
            int rect_left;
            int rect_top;
            int rect_width;
            int rect_height;
            float start_time;
            float end_time;

            sf::IntRect rect;

            bool played = false;
        };
        std::vector<List> vlist;

        sf::Clock fx_clock;
        sf::Time fx_timer;

        std::string SoundFx;
        std::vector<Sound> Sound;
    };

    class Level
    {
        public:
        std::string VariableName;
        std::string VariableData;

        std::string Name;

        std::vector<Objects> Objects;
        std::vector<Map_Objects> Map_Objects;
    };

    static std::vector<Textures>      Textures_Vector;
    static std::vector<Music>         Music_Vector;
    static std::vector<Sound>         Sound_Vector;
    static std::vector<Objects>       Objects_Vector;
    static std::vector<Text>          Text_Vector;
    static std::vector<Text>          Grid_Text_Vector;
    static std::vector<Map_Objects>   Map_Objects_Vector;
    static std::vector<Projectile>    Projectile_Vector;
    static std::vector<Fx>            Fx_Vector;
    static std::vector<Fx>            Fx_To_Play_Vector;
    static std::vector<Level>         Level_Vector;
};

#endif // DATA_H
