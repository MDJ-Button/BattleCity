#ifndef EVENTS_H
#define EVENTS_H

#include "Data.hpp"
#include "Game.hpp"

#include <iostream>

#include <SFML/Window.hpp>

class Events
{
    public:

    static bool KeyDown;
    static bool Mouse_ButtonDown;
    static std::string Key;

    class Keyboard
    {
        public:

        void Escape()
        {
            Game game;
            game.Print(false, false, "Key = Escape");
            Key = "Escape";
        }

        void Tilde()
        {
            Game game;
            game.Print(false, false, "Key = ~");
            Key = "~";
        }

        void Num0()
        {
            Game game;
            game.Print(false, false, "Key = )");
            Key = ")";
        }

        void Num1()
        {
            Game game;
            game.Print(false, false, "Key = !");
            Key = "!";
        }

        void Num2()
        {
            Game game;
            game.Print(false, false, "Key = @");
            Key = "@";
        }

        void Num3()
        {
            Game game;
            game.Print(false, false, "Key = #");
            Key = "#";
        }

        void Num4()
        {
            Game game;
            game.Print(false, false, "Key = $");
            Key = "$";
        }

        void Num5()
        {
            Game game;
            game.Print(false, false, "Key = %");
            Key = "%";
        }

        void Num6()
        {
            Game game;
            game.Print(false, false, "Key = ^");
            Key = "^";
        }

        void Num7()
        {
            Game game;
            game.Print(false, false, "Key = &");
            Key = "&";
        }

        void Num8()
        {
            Game game;
            game.Print(false, false, "Key = *");
            Key = "*";
        }

        void Num9()
        {
            Game game;
            game.Print(false, false, "Key = (");
            Key = "(";
        }

        void Equal()
        {
            Game game;
            game.Print(false, false, "Key = Equal");
            Key = "=";
        }

        void Hyphen()
        {
            Game game;
            game.Print(false, false, "Key = -");
            Key = "-";
        }

        void BackSpace()
        {
            Game game;
            game.Print(false, false, "Key = BackSpace");
            Key = "Backspace";
        }

        void Tab()
        {
            Game game;
            game.Print(false, false, "Key = Tab");
            Key = "Tab";
        }

        void Q()
        {
            Game game;
            game.Print(false, false, "Key = Q");
            Key = "Q";
        }

        void W()
        {
            Game game;
            game.Print(false, false, "Key = W");
            Key = "W";
        }

        void E()
        {
            Game game;
            game.Print(false, false, "Key = E");
            Key = "E";
        }

        void R()
        {
            Game game;
            game.Print(false, false, "Key = R");
            Key = "R";
        }

        void T()
        {
            Game game;
            game.Print(false, false, "Key = T");
            Key = "T";
        }

        void Y()
        {
            Game game;
            game.Print(false, false, "Key = Y");
            Key = "Y";
        }

        void U()
        {
            Game game;
            game.Print(false, false, "Key = U");
            Key = "U";
        }

        void I()
        {
            Game game;
            game.Print(false, false, "Key = I");
            Key = "I";
        }

        void O()
        {
            Game game;
            game.Print(false, false, "Key = O");
            Key = "O";
        }

        void P()
        {
            Game game;
            game.Print(false, false, "Key = P");
            Key = "P";
        }

        void LBracket()
        {
            Game game;
            game.Print(false, false, "Key = LBracket");
            Key = "[";
        }

        void RBracket()
        {
            Game game;
            game.Print(false, false, "Key = RBracket");
            Key = "]";
        }

        void Backslash()
        {
            Game game;
            game.Print(false, false, "Key = Backslash");
            Key = "\n";
        }

        void A()
        {
            Game game;
            game.Print(false, false, "Key = A");
            Key = "A";
        }

        void S()
        {
            Game game;
            game.Print(false, false, "Key = S");
            Key = "S";
        }

        void D()
        {
            Game game;
            game.Print(false, false, "Key = D");
            Key = "D";
        }

        void F()
        {
            Game game;
            game.Print(false, false, "Key = F");
            Key = "F";
        }

        void G()
        {
            Game game;
            game.Print(false, false, "Key = G");
            Key = "G";
        }

        void H()
        {
            Game game;
            game.Print(false, false, "Key = H");
            Key = "H";
        }

        void J()
        {
            Game game;
            game.Print(false, false, "Key = J");
            Key = "J";
        }

        void K()
        {
            Game game;
            game.Print(false, false, "Key = K");
            Key = "K";
        }

        void L()
        {
            Game game;
            game.Print(false, false, "Key = L");
            Key = "L";
        }

        void SemiColon()
        {
            Game game;
            game.Print(false, false, "Key = ;");
            Key = ";";
        }

        void Quote()
        {
            Game game;
            game.Print(false, false, "Key = \"");
            Key = "\"";
        }

        void Enter()
        {
            Game game;
            game.Print(false, false, "Key = Enter");
            Key = "Enter";
        }

        void LShift()
        {
            Game game;
            game.Print(false, false, "Key = LShift");
            Key = "LShift";
        }

        void Z()
        {
            Game game;
            game.Print(false, false, "Key = Z");
            Key = "Z";
        }

        void X()
        {
            Game game;
            game.Print(false, false, "Key = X");
            Key = "X";
        }

        void C()
        {
            Game game;
            game.Print(false, false, "Key = C");
            Key = "C";
        }

        void V()
        {
            Game game;
            game.Print(false, false, "Key = V");
            Key = "V";
        }

        void B()
        {
            Game game;
            game.Print(false, false, "Key = B");
            Key = "B";
        }

        void N()
        {
            Game game;
            game.Print(false, false, "Key = N");
            Key = "N";
        }

        void M()
        {
            Game game;
            game.Print(false, false, "Key = M");
            Key = "M";
        }

        void Comma()
        {
            Game game;
            game.Print(false, false, "Key = ,");
            Key = ",";
        }

        void Period()
        {
            Game game;
            game.Print(false, false, "Key = .");
            Key = ".";
        }

        void Slash()
        {
            Game game;
            game.Print(false, false, "Key = /");
            Key = "/";
        }

        void RShift()
        {
            Game game;
            game.Print(false, false, "Key = RShift");
            Key = "RShift";
        }

        void LControl()
        {
            Game game;
            game.Print(false, false, "Key = RControl");
            Key = "RControl";
        }

        void LAlt()
        {
            Game game;
            game.Print(false, false, "Key = LAlt");
            Key = "LAlt";
        }

        void Space()
        {
            Game game;
            game.Print(false, false, "Key = Space");
            Key = "Space";
        }

        void RAlt()
        {
            Game game;
            game.Print(false, false, "Key = RAlt");
            Key = "RAlt";
        }

        void RControl()
        {
            Game game;
            game.Print(false, false, "Key = RControl");
            Key = "RControl";
        }

        void Insert()
        {
            Game game;
            game.Print(false, false, "Key = Insert");
            Key = "Insert";
        }

        void Home()
        {
            Game game;
            game.Print(false, false, "Key = Home");
            Key = "Home";
        }

        void PageUp()
        {
            Game game;
            game.Print(false, false, "Key = PageUp");
            Key = "PageUp";
        }

        void Delete()
        {
            Game game;
            game.Print(false, false, "Key = Delete");
            Key = "Delete";
        }

        void End()
        {
            Game game;
            game.Print(false, false, "Key = End");
            Key = "End";
        }

        void PageDown()
        {
            Game game;
            game.Print(false, false, "Key = PageDown");
            Key = "PageDown";
        }

        void Up()
        {
            Game game;
            game.Print(false, false, "Key = Up");
            Key = "Up";
        }

        void Left()
        {
            Game game;
            game.Print(false, false, "Key = Left");
            Key = "Left";
        }

        void Down()
        {
            Game game;
            game.Print(false, false, "Key = Down");
            Key = "Down";
        }

        void Right()
        {
            Game game;
            game.Print(false, false, "Key = Right");
            Key = "Right";
        }

        void Numpad0()
        {
            Game game;
            game.Print(false, false, "Key = Numpad0");
            Key = "0";
        }

        void Numpad1()
        {
            Game game;
            game.Print(false, false, "Key = Numpad1");
            Key = "1";
        }

        void Numpad2()
        {
            Game game;
            game.Print(false, false, "Key = Numpad2");
            Key = "2";
        }

        void Numpad3()
        {
            Game game;
            game.Print(false, false, "Key = Numpad3");
            Key = "3";
        }

        void Numpad4()
        {
            Game game;
            game.Print(false, false, "Key = Numpad4");
            Key = "4";
        }

        void Numpad5()
        {
            Game game;
            game.Print(false, false, "Key = Numpad5");
            Key = "5";
        }

        void Numpad6()
        {
            Game game;
            game.Print(false, false, "Key = Numpad6");
            Key = "6";
        }

        void Numpad7()
        {
            Game game;
            game.Print(false, false, "Key = Numpad7");
            Key = "7";
        }

        void Numpad8()
        {
            Game game;
            game.Print(false, false, "Key = Numpad8");
            Key = "8";
        }

        void Numpad9()
        {
            Game game;
            game.Print(false, false, "Key = Numpad9");
            Key = "9";
        }
    };

    class Mouse
    {
        public:

        void Left()
        {
            Game game;
            game.Print(false, false, "Key = MouseLeft");
            Key = "MouseLeft";
        }

        void Middle()
        {
            Game game;
            game.Print(false, false, "Key = MouseMiddle");
            Key = "MouseMiddle";
        }

        void Right()
        {
            Game game;
            game.Print(false, false, "Key = MouseRight");
            Key = "MouseRight";
        }
    };
};

#endif // EVENTS_H
