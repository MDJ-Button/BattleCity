#ifndef DATA_TEXTURE_H
#define DATA_TEXTURE_H

#include "Data.h"

class Data
{
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

            std::string Animation_Move_Up;
            std::string Animation_Move_Up_Direction;
            int Animation_Move_Up_Row;
            int Animation_Move_Up_Reset;
            int Animation_Move_Up_Add;
            int Animation_Move_Up_Restart;
            int Animation_Move_Up_Width;
            int Animation_Move_Up_Height;

            std::string Animation_Move_Down;
            std::string Animation_Move_Down_Direction;
            int Animation_Move_Down_Row;
            int Animation_Move_Down_Reset;
            int Animation_Move_Down_Add;
            int Animation_Move_Down_Restart;
            int Animation_Move_Down_Width;
            int Animation_Move_Down_Height;

            std::string Animation_Move_Left;
            std::string Animation_Move_Left_Direction;
            int Animation_Move_Left_Row;
            int Animation_Move_Left_Reset;
            int Animation_Move_Left_Add;
            int Animation_Move_Left_Restart;
            int Animation_Move_Left_Width;
            int Animation_Move_Left_Height;

            std::string Animation_Move_Right;
            std::string Animation_Move_Right_Direction;
            int Animation_Move_Right_Row;
            int Animation_Move_Right_Reset;
            int Animation_Move_Right_Add;
            int Animation_Move_Right_Restart;
            int Animation_Move_Right_Width;
            int Animation_Move_Right_Height;
    };
};

#endif // DATA_TEXTURE_H
