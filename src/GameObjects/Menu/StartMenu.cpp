#include "StartMenu.h"
#include <iostream>

#define MENUSTARTX 0
#define MENUSTARTY 0
#define TRACKX 100
#define TRACKY 100
#define LOADX 100
#define LOADY 200
#define QUITX 100
#define QUITY 400
#define BUTTONWIDTH 100
#define BUTTONHEIGHT 70
#define CLICK "CLICK.WAV"
#define BUTTON "button.png"
#define MENUSBACKGROUND "StartMenu.png"
using namespace std;
StartMenu::StartMenu()
:Menu(MENUSTARTX,MENUSTARTY, "StartMenu.png")
{
    addButton(new Button(MENUSTARTX, MENUSTARTY, TRACKX, TRACKY, BUTTONWIDTH, BUTTONHEIGHT,
                      BUTTON, CLICK, "Tracks", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, LOADX, LOADY, BUTTONWIDTH, BUTTONHEIGHT,
                      BUTTON, CLICK, "Load", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT,
                      BUTTON, CLICK, "Quit", ""));
}

StartMenu::~StartMenu()
{
    //dtor
}

using namespace std;

bool StartMenu::update()
{
    if(buttons[0]->gotPressed())
    {
        state = "TRACK";
        newIteration();
        return true;
    }
    else if(buttons[1]->gotPressed())
    {
        state = "LOAD";
        newIteration();
        return true;
    }
    else if(buttons[2]->gotPressed())
    {
        state = "QUIT";
        newIteration();
        return true;
    }
    else
    {
        newIteration();
        return false;
    }
}
