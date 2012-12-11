/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    NextWaveMenu.cpp
 * Enhetsnamn: NextWaveMenu
 * Typ:        implementering
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar knappen "next wave" under spelets gång
 *
 */

#include "NextWaveMenu.h"
#define MENUSTARTX 662
#define MENUSTARTY 425
#define NEWWAVEX 35
#define NEWWAVEY 32
#define BUTTONWIDTH 66
#define BUTTONHEIGHT 66
#define CLICK "thozi_daClick.ogg"
#define BUTTON "button.png"
#include <iostream>

using namespace std;

NextWaveMenu::NextWaveMenu()
 : Menu(MENUSTARTX,MENUSTARTY, "NextWaveMenu_BG.png")
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
        newIteration();
        return true;
    }
    return false;
}
