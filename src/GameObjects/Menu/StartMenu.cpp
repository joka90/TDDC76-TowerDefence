#include "StartMenu.h"
#include <iostream>

#define MENUSTARTX 0
#define MENUSTARTY 0
#define TRACKX 38
#define TRACKY 447
#define LOADX 38
#define LOADY 517
#define QUITX 200
#define QUITY 517
#define BUTTONWIDTH 141
#define BUTTONHEIGHT 51
#define CLICK "CLICK.WAV"
#define BUTTON "StartButton_BG.png"
#define MENUSBACKGROUND "StartMenu.png"
using namespace std;
StartMenu::StartMenu()
:Menu(MENUSTARTX,MENUSTARTY, "Start_BG.png")
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
