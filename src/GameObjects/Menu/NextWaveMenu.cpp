#include "NextWaveMenu.h"
#define MENUSTARTX 600
#define MENUSTARTY 400
#define NEWWAVEX 50
#define NEWWAVEY 40
#define BUTTONWIDTH 100
#define BUTTONHEIGHT 70
#define CLICK "CLICK.WAW"
#define BUTTON "button.png"
#include <iostream>

using namespace std;

NextWaveMenu::NextWaveMenu()
 : Menu(MENUSTARTX,MENUSTARTY, "StartMenu.png")
{
    addButton(new Button(MENUSTARTX, MENUSTARTY, NEWWAVEX, NEWWAVEY, BUTTONWIDTH, BUTTONHEIGHT,
                       BUTTON, CLICK, "New Wave", ""));
    cout << "NEWWAVEDONE" << endl;
}

NextWaveMenu::~NextWaveMenu()
{

}

bool NextWaveMenu::update()
{
    if(buttons[0]->gotPressed())
    {
        state = "NEXTWAVE";
        return true;
    }
    return false;
}
