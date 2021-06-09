#include "Game.hpp"
#include "Events.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

void Game::Update_Event()
{
    Events              events;
    Events::Keyboard    key_event;
    Events::Mouse       mouse_key_event;

    Game game;
    Data data;

    Print(true, true, Func_Open("Game", "Update_Event"));

    Print(true, false, Loop_Start("while", "(window.pollEvent(event)"));
    while (window.pollEvent(event))
    {
        if(event.type == sf::Event::KeyPressed && !events.KeyDown)
        {
            events.KeyDown = true;

            //std::cout << "\nHERE"; Create_Projectile(1, "Up", 0, 0);

            if(event.key.code == sf::Keyboard::Escape)
            {
                TerminateApplication = true;
                key_event.Escape();
            }

            else if(event.key.code == sf::Keyboard::Tilde)      key_event.Tilde();
            else if(event.key.code == sf::Keyboard::Num0)       key_event.Num0();
            else if(event.key.code == sf::Keyboard::Num1)       key_event.Num1();
            else if(event.key.code == sf::Keyboard::Num2)       key_event.Num2();
            else if(event.key.code == sf::Keyboard::Num3)       key_event.Num3();
            else if(event.key.code == sf::Keyboard::Num4)       key_event.Num4();
            else if(event.key.code == sf::Keyboard::Num5)       key_event.Num5();
            else if(event.key.code == sf::Keyboard::Num6)       key_event.Num6();
            else if(event.key.code == sf::Keyboard::Num7)       key_event.Num7();
            else if(event.key.code == sf::Keyboard::Num8)       key_event.Num8();
            else if(event.key.code == sf::Keyboard::Num9)       key_event.Num9();
            else if(event.key.code == sf::Keyboard::Hyphen)     key_event.Hyphen();
            else if(event.key.code == sf::Keyboard::Equal)      key_event.Equal();
            else if(event.key.code == sf::Keyboard::BackSpace)  key_event.BackSpace();

            else if(event.key.code == sf::Keyboard::Tab)        key_event.Tab();
            else if(event.key.code == sf::Keyboard::Q)          key_event.Q();
            else if(event.key.code == sf::Keyboard::W)          key_event.W();
            else if(event.key.code == sf::Keyboard::E)          key_event.E();
            else if(event.key.code == sf::Keyboard::R)          key_event.R();
            else if(event.key.code == sf::Keyboard::T)          key_event.T();
            else if(event.key.code == sf::Keyboard::Y)          key_event.Y();
            else if(event.key.code == sf::Keyboard::U)          key_event.U();
            else if(event.key.code == sf::Keyboard::I)          key_event.I();
            else if(event.key.code == sf::Keyboard::O)          key_event.O();
            else if(event.key.code == sf::Keyboard::P)          key_event.P();
            else if(event.key.code == sf::Keyboard::LBracket)   key_event.LBracket();
            else if(event.key.code == sf::Keyboard::RBracket)   key_event.RBracket();
            else if(event.key.code == sf::Keyboard::Backslash)  key_event.Backslash();

            else if(event.key.code == sf::Keyboard::A)          key_event.A();
            else if(event.key.code == sf::Keyboard::S)          key_event.S();
            else if(event.key.code == sf::Keyboard::D)          key_event.D();
            else if(event.key.code == sf::Keyboard::F)          key_event.F();
            else if(event.key.code == sf::Keyboard::G)          key_event.G();
            else if(event.key.code == sf::Keyboard::H)          key_event.H();
            else if(event.key.code == sf::Keyboard::J)          key_event.J();
            else if(event.key.code == sf::Keyboard::K)          key_event.K();
            else if(event.key.code == sf::Keyboard::L)          key_event.L();
            else if(event.key.code == sf::Keyboard::SemiColon)  key_event.SemiColon();
            else if(event.key.code == sf::Keyboard::Quote)      key_event.Quote();
            else if(event.key.code == sf::Keyboard::Enter)      key_event.Enter();

            else if(event.key.code == sf::Keyboard::LShift)     key_event.LShift();
            else if(event.key.code == sf::Keyboard::Z)          key_event.Z();
            else if(event.key.code == sf::Keyboard::X)          key_event.X();
            else if(event.key.code == sf::Keyboard::C)          key_event.C();
            else if(event.key.code == sf::Keyboard::V)          key_event.V();
            else if(event.key.code == sf::Keyboard::B)          key_event.B();
            else if(event.key.code == sf::Keyboard::N)          key_event.N();
            else if(event.key.code == sf::Keyboard::M)          key_event.M();
            else if(event.key.code == sf::Keyboard::Comma)      key_event.Comma();
            else if(event.key.code == sf::Keyboard::Period)     key_event.Period();
            else if(event.key.code == sf::Keyboard::Slash)      key_event.Slash();
            else if(event.key.code == sf::Keyboard::RShift)     key_event.RShift();

            else if(event.key.code == sf::Keyboard::LControl)   key_event.LControl();
            else if(event.key.code == sf::Keyboard::LAlt)       key_event.LAlt();
            else if(event.key.code == sf::Keyboard::Space)
            {
                key_event.Space();
                std::cout << "\nBANG " << data.Level_Vector[0].Objects[Player_Number].Direction << "\n";

                game.Create_Projectile(Player_Number, 10, data.Level_Vector[0].Objects[Player_Number].Direction, data.Level_Vector[0].Objects[Player_Number].sprite.getPosition().x,
                                                                                                                data.Level_Vector[0].Objects[Player_Number].sprite.getPosition().y);
            }
            else if(event.key.code == sf::Keyboard::RAlt)       key_event.RAlt();
            else if(event.key.code == sf::Keyboard::RControl)   key_event.RControl();

            else if(event.key.code == sf::Keyboard::Insert)     key_event.Insert();
            else if(event.key.code == sf::Keyboard::Home)       key_event.Home();
            else if(event.key.code == sf::Keyboard::PageUp)     key_event.PageUp();

            else if(event.key.code == sf::Keyboard::Delete)     key_event.Delete();
            else if(event.key.code == sf::Keyboard::End)        key_event.End();
            else if(event.key.code == sf::Keyboard::PageDown)   key_event.PageDown();

            else if(event.key.code == sf::Keyboard::Up)         key_event.Up();
            else if(event.key.code == sf::Keyboard::Left)       key_event.Left();
            else if(event.key.code == sf::Keyboard::Down)       key_event.Down();
            else if(event.key.code == sf::Keyboard::Right)      key_event.Right();

            else if(event.key.code == sf::Keyboard::Numpad0)    key_event.Numpad0();
            else if(event.key.code == sf::Keyboard::Numpad1)    key_event.Numpad1();
            else if(event.key.code == sf::Keyboard::Numpad2)    key_event.Numpad2();
            else if(event.key.code == sf::Keyboard::Numpad3)    key_event.Numpad3();
            else if(event.key.code == sf::Keyboard::Numpad4)    key_event.Numpad4();
            else if(event.key.code == sf::Keyboard::Numpad5)    key_event.Numpad5();
            else if(event.key.code == sf::Keyboard::Numpad6)    key_event.Numpad6();
            else if(event.key.code == sf::Keyboard::Numpad7)    key_event.Numpad7();
            else if(event.key.code == sf::Keyboard::Numpad8)    key_event.Numpad8();
            else if(event.key.code == sf::Keyboard::Numpad9)    key_event.Numpad9();
        }

        else if(event.type == sf::Event::KeyReleased && events.KeyDown)
        {
            events.Key.clear();
            events.KeyDown = false;
        }

        else if(event.type == sf::Event::MouseButtonPressed && !events.Mouse_ButtonDown)
        {
            events.Mouse_ButtonDown = true;

            if(event.mouseButton.button == sf::Mouse::Left)           mouse_key_event.Left();
            else if(event.mouseButton.button == sf::Mouse::Middle)    mouse_key_event.Middle();
            else if(event.mouseButton.button == sf::Mouse::Right)     mouse_key_event.Right();
        }

        else if(event.type == sf::Event::MouseButtonReleased && events.Mouse_ButtonDown)
        {
            events.Key.clear();
            events.Mouse_ButtonDown = false;
        }

        else if(event.type == sf::Event::Closed)
        {
            Print(true, false, Statement("if", "event.type == sf::Event::Closed", "true"));

            window.close();
            Print(true, false, DataType_Updated("sf::RenderWindow", "window", "close()"));
        }
        else if(event.type == sf::Event::Resized)
        {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
            if(Grid_Draw) Grid_Set(true);
            if(Window_ShowFPS) Window_ShowFPS_Set(true);
        }

        else Print(true, false, Statement("else", "event.type == sf::Event::Closed", "false"));
    }
    Print(true, false, Loop_Stop("while", "(window.pollEvent(event)"));

    Print(true, true, Func_Close("Game", "Update_Event"));
}


