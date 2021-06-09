#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Data.hpp"

class Game
{
    friend class File;

    public:

    static bool TerminateApplication;

    void Run(bool _Run);

    int  Load(std::string FromFunc, int Line, std::string Type, std::string Name);

    static bool DoPrint;
    static bool PrintVectors;
    void Print(bool _PrintOnce, bool IsFunc, std::string _Print);
    void PrintVector(std::string _VectorName);

    std::string Func_Open(std::string ClassName, std::string FuncName){return ClassName + "::" + FuncName + "::Opening Function";}
    std::string Func_Close(std::string ClassName, std::string FuncName){return ClassName + "::" + FuncName + "::Closing Function";}
    std::string Statement(std::string Type, std::string Condition, std::string Returned){return Type + "(" + Condition + ") returned " + Returned;}
    std::string Loop_Start(std::string Type, std::string Condition){return "Started " + Type + "(" + Condition + ")";}
    std::string Loop_Stop(std::string Type, std::string Condition){return "Stopped " + Type + "(" + Condition + ")";}
    std::string DataType_Created(std::string Type, std::string Name, std::string Value){return "Created " + Type + " With Name " + Name + " With Value " + Value;}
    std::string DataType_Updated(std::string Type, std::string Name, std::string Value){return "Updated " + Type + " With Name " + Name + " With Value " + Value;}
    std::string Message(std::string String){return String;}

    protected:

    static std::vector<std::string> PrintOnceList;
    void PrintOnce(bool IsFunc, std::string _Print);

    private:

    void Loop(bool builder_enabled);
    void Update_Window();
    void Update_ObjectsPositions(int LoopNumber);
    void Update_Textures(int LoopNumber);
    void Update_Event();
    void Collision_Detection(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2);
    void Collision_Detection_Obj_MapObj(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2);
    void Collision_Detection_Obj_Obj(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2);
    void Collision_Detection_Obj_Projectile(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2);
    void Collision_Detection_MapObj_Projectile(int LoopNumber, bool Debug, int DebugObject_1, int DebugObject_2);
    void Remove_Obj_From_Map(std::string FromVector, int IndexNumber, float MoveToX, float MoveToY);
    void Remove_Obj_From_Vector(std::string FromVector, int IndexNumber);


    static int Player_Number;
    void Player(int Player_Number);
    void AI(int Bot_Number, float Waypoint_X, float Waypoint_Y);

    bool If(std::string Condition);
    void Do(std::string This);

    sf::RenderWindow window;
    sf::Event event;
    sf::Clock clock;
    sf::Time time;

    int size_of_Compound_Assignment;
    std::string Compound_Assignment(std::string String)
    {
        std::string Equal_To = "==";
        std::string Not_Equal_To = "!=";
        std::string Less_Than = "<";
        std::string Greater_Than = ">";
        std::string Less_Than_Or_Equal_To = "<=";
        std::string Greater_Than_Or_Equal_To = ">=";

        if(String.find(Equal_To)!=std::string::npos)                       {size_of_Compound_Assignment = 2; return Equal_To;}
        else if(String.find(Not_Equal_To)!=std::string::npos)              {size_of_Compound_Assignment = 2; return Not_Equal_To;}
        else if(String.find(Less_Than_Or_Equal_To)!=std::string::npos)     {size_of_Compound_Assignment = 2; return Less_Than_Or_Equal_To;}
        else if(String.find(Greater_Than_Or_Equal_To)!=std::string::npos)  {size_of_Compound_Assignment = 2; return Greater_Than_Or_Equal_To;}
        else if(String.find(Less_Than)!=std::string::npos)                 {size_of_Compound_Assignment = 1; return Less_Than;}
        else if(String.find(Greater_Than)!=std::string::npos)              {size_of_Compound_Assignment = 1; return Greater_Than;}
        else                                                               {size_of_Compound_Assignment = 0; return "Undefined";}
    }

    bool Check_If_Number(std::string This)
    {
        return !This.empty() && std::all_of(This.begin(), This.end(), ::isdigit);
    }

    static std::vector<sf::RectangleShape> Grid_Vector;
    static bool                            Grid_Draw;
    static int                             Grid_Size_X;
    static int                             Grid_Size_Y;
    static sf::Color                       Grid_Color;
    void                                   Grid_Set(bool Reset);
    static std::vector<Data::Text>         Grid_Text_Vector;

    static bool                            Builder_Enable;

    static bool                            Window_ShowFPS;
    static std::string                     Window_ShowFPS_Top_OR_Bottom;
    static std::string                     Window_ShowFPS_Left_OR_Right;
    void                                   Window_ShowFPS_Set(bool Reset);

    static int FPS_Limit;
    static int Window_Size_X;
    static int Window_Size_Y;
    static bool Window_Fullscreen;

    void                                   Text_Set();

    std::string GetFPS(unsigned int _int, void(*function)(unsigned int))
    {
        //int i = &_int;
        return std::to_string(_int);
    }

    static std::vector<std::string>        DontDraw;

    void                                   Create_Projectile(int FromObject, float Speed, int Direction, float x, float y);
    void                                   Create_FX(bool Game_Show_Sound_Boxes, std::string unique_name, std::string fx_name, float object_width, float object_height, int at_x, int at_y);
    void                                   Play_Fx(int LoopNumber);
    void                                   Play_SoundFx(int LoopNumber);

    void                                   Set_Starting_Direction(int ForObject);

    void                                   Read_Game_Data();
    void                                   Set_Game_Data(bool Game_Show_Sound_Boxes);

    void                                   Object_Set(bool Game_Show_Sound_Boxes);
    void                                   Map_Object_Set();
    void                                   Sound_Set();
    void                                   SoundFx_Set();

    void                                   Play_SoundIdle(int LoopNumber);
    void                                   Play_SoundMove(int LoopNumber);

    void                                   New_Map_Object(std::string Copy_From);
    void                                   New_Object(std::string Copy_From);

    float FPS;
    sf::Time FPS_previousTime;
    sf::Time FPS_currentTime;

    static bool bSetFPS;
    void SetFPS();

    static bool Game_Show_Sound_Boxes;
};

#endif // GAME_H
