#include "StartMenu.h"

#DEFINE MENUSTARTX 0
#DEFINE MENUSTARTY 0
#DEFINE TRACKX 100
#DEFINE TRACKY 100
#DEFINE LOADX 100
#DEFINE LOADY 200
#DEFINE QUITX 100
#DEFINE QUITY 300
#DEFINE BUTTONWIDTH 100
#DEFINE BUTTONHEIGHT 70
#DEFINE CLICK "CLICK.WAW"

StartMenu::StartMenu(class TextureLoader* textures, class SoundLoader* sounds, class FontLoader* fonts)
:Menu(MENUSTARTX,MENUSTARTY, textures, "StartMenu.bmp")
{
    addButton(Button(MENUSTARTX, MENUSTARTY, TRACKX, TRACKY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, "TRACK.BMP", CLICK, ""));
    addButton(Button(MENUSTARTX, MENUSTARTY, LOADX, LOADY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, "LOAD.BMP", CLICK, ""));
    addButton(Button(MENUSTARTX, MENUSTARTY, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, "QUIT.BMP", CLICK, ""));
}

StartMenu::~StartMenu()
{
    //dtor
}

bool update()
{
    if(buttons[0].gotPressed())
    {
        state = "TRACK";
        newIteration();
        return true;
    }
    else if(buttons[1].gotPressed())
    {
        state = "LOAD";
        newIteration();
        return true;
    }
    else if(buttons[2].gotPressed())
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
