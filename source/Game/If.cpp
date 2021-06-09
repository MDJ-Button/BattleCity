#include "Game.hpp"
#include "File.hpp"
#include "Data.hpp"

#include <string>
#include <algorithm>
#include <windows.h>

bool Game::If(std::string Condition)
{
    Print(false, true, Func_Open("Game", "If"));

    File file;

    bool Condition_Met;
    std::string copyof_Condition = Condition;

    std::vector<std::string> If_Left_Condition;
    std::vector<std::string> If_Right_Condition;
    std::vector<std::string> If_Compound_Assignment;

    copyof_Condition.erase(std::remove(copyof_Condition.begin(), copyof_Condition.end(), ' '), copyof_Condition.end());
    if(copyof_Condition.find("(")!=std::string::npos)
    {
        copyof_Condition = Condition;
        copyof_Condition.erase(std::remove(copyof_Condition.begin(), copyof_Condition.end(), ' '), copyof_Condition.end());
        copyof_Condition = copyof_Condition.substr(copyof_Condition.find("(") + 1);

        if(copyof_Condition.find(Compound_Assignment(copyof_Condition))!=std::string::npos)
        {
            copyof_Condition = Condition;
            copyof_Condition.erase(std::remove(copyof_Condition.begin(), copyof_Condition.end(), ' '), copyof_Condition.end());
            copyof_Condition = copyof_Condition.substr(copyof_Condition.find("(") + 1);
            copyof_Condition = copyof_Condition.erase(copyof_Condition.find(Compound_Assignment(copyof_Condition)));
            If_Left_Condition.push_back(copyof_Condition);

            copyof_Condition = Condition;
            copyof_Condition.erase(std::remove(copyof_Condition.begin(), copyof_Condition.end(), ' '), copyof_Condition.end());
            copyof_Condition = copyof_Condition.substr(copyof_Condition.find(Compound_Assignment(copyof_Condition)));
            copyof_Condition = copyof_Condition.erase(copyof_Condition.find(Compound_Assignment(copyof_Condition)) + size_of_Compound_Assignment);
            If_Compound_Assignment.push_back(copyof_Condition);

            copyof_Condition = Condition;
            copyof_Condition.erase(std::remove(copyof_Condition.begin(), copyof_Condition.end(), ' '), copyof_Condition.end());
            copyof_Condition = copyof_Condition.substr(copyof_Condition.find(Compound_Assignment(copyof_Condition)) + size_of_Compound_Assignment);

            if(copyof_Condition.find(")")!=std::string::npos)
            {
                copyof_Condition = copyof_Condition.erase(copyof_Condition.find(")"));
                If_Right_Condition.push_back(copyof_Condition);

                for(int i = 0; i < If_Compound_Assignment.size(); i++)
                {
                    if(If_Compound_Assignment[i] == "==")
                    {
                        if(Check_If_Number(If_Left_Condition[i]) && Check_If_Number(If_Right_Condition[i]))
                        {
                            int temp_If_Left_Condition  = std::stoi(If_Left_Condition[i]);
                            int temp_If_Right_Condition = std::stoi(If_Right_Condition[i]);

                            if(temp_If_Left_Condition == temp_If_Right_Condition)
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                        else
                        {
                            if(If_Left_Condition[i] == If_Right_Condition[i])
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                    }

                    else if(If_Compound_Assignment[i] == "!=")
                    {
                        if(Check_If_Number(If_Left_Condition[i]) && Check_If_Number(If_Right_Condition[i]))
                        {
                            int temp_If_Left_Condition  = std::stoi(If_Left_Condition[i]);
                            int temp_If_Right_Condition = std::stoi(If_Right_Condition[i]);

                            if(temp_If_Left_Condition != temp_If_Right_Condition)
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                        else
                        {
                            if(If_Left_Condition[i] != If_Right_Condition[i])
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                    }

                    else if(If_Compound_Assignment[i] == "<")
                    {
                        if(Check_If_Number(If_Left_Condition[i]) && Check_If_Number(If_Right_Condition[i]))
                        {
                            int temp_If_Left_Condition  = std::stoi(If_Left_Condition[i]);
                            int temp_If_Right_Condition = std::stoi(If_Right_Condition[i]);

                            if(temp_If_Left_Condition < temp_If_Right_Condition)
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                        else
                        {
                            if(If_Left_Condition[i] < If_Right_Condition[i])
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                    }

                    else if(If_Compound_Assignment[i] == ">")
                    {
                        if(Check_If_Number(If_Left_Condition[i]) && Check_If_Number(If_Right_Condition[i]))
                        {
                            int temp_If_Left_Condition  = std::stoi(If_Left_Condition[i]);
                            int temp_If_Right_Condition = std::stoi(If_Right_Condition[i]);

                            if(temp_If_Left_Condition > temp_If_Right_Condition)
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                        else
                        {
                            if(If_Left_Condition[i] > If_Right_Condition[i])
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                    }

                    else if(If_Compound_Assignment[i] == "<=")
                    {
                        if(Check_If_Number(If_Left_Condition[i]) && Check_If_Number(If_Right_Condition[i]))
                        {
                            int temp_If_Left_Condition  = std::stoi(If_Left_Condition[i]);
                            int temp_If_Right_Condition = std::stoi(If_Right_Condition[i]);

                            if(temp_If_Left_Condition <= temp_If_Right_Condition)
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                        else
                        {
                            if(If_Left_Condition[i] <= If_Right_Condition[i])
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                    }

                    else if(If_Compound_Assignment[i] == ">=")
                    {
                        if(Check_If_Number(If_Left_Condition[i]) && Check_If_Number(If_Right_Condition[i]))
                        {
                            int temp_If_Left_Condition  = std::stoi(If_Left_Condition[i]);
                            int temp_If_Right_Condition = std::stoi(If_Right_Condition[i]);

                            if(temp_If_Left_Condition >= temp_If_Right_Condition)
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                        else
                        {
                            if(If_Left_Condition[i] >= If_Right_Condition[i])
                            {
                                Condition_Met = true;
                            }
                            else Condition_Met = false;
                        }
                    }
                }

                If_Left_Condition.clear();
                If_Compound_Assignment.clear();
                If_Right_Condition.clear();
            }
            else
            {
                std::string error; error = "Expected ')' after condition " + Condition + " in file ";
                LPCSTR char_error = error.c_str();
                MessageBoxA(NULL, char_error, "Script Error",MB_OK);
            }
        }

        else
        {
            std::string error; error = "Expected a Compound Assignment " + Condition + " in file ";
            LPCSTR char_error = error.c_str();
            MessageBoxA(NULL, char_error, "Script Error",MB_OK);
        }
    }
    else
    {
        std::string error; error = "Expected '(' before condition " + Condition + " in file ";
        LPCSTR char_error = error.c_str();
        MessageBoxA(NULL, char_error, "Script Error",MB_OK);
    }

    Print(false, true, Func_Close("Game", "If"));

    return Condition_Met;
}

