#include "TrackMenu.h"

#define MENUSTARTX 0
#define MENUSTARTY 0
#define TRACKX 100
#define TRACKY 100
#define LOADX 100
#define LOADY 200
#define QUITX 100
#define QUITY 300
#define BUTTONWIDTH 100
#define BUTTONHEIGHT 70
#define CLICK "CLICK.WAW"
#define BUTTON "MENUBUTTONBASE.BMP"

TrackMenu::TrackMenu(TextureLoader& textures, SoundLoader& sounds, FontLoader& fonts)
:Menu(MENUSTARTX,MENUSTARTY, textures, "TrackMenu.bmp")
{
    addButton(new Button(MENUSTARTX, MENUSTARTY, TRACKX, TRACKY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, BUTTON, CLICK, "YOU", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, LOADX, LOADY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, BUTTON, CLICK, "ARE", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, BUTTON, CLICK, "ON TRACK", ""));
}

TrackMenu::~TrackMenu()
{
    //dtor
}

bool TrackMenu::update()
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
        state = "START";
        newIteration();
        return true;
    }
    else
    {
        newIteration();
        return false;
    }
}
