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

TrackMenu::TrackMenu(class TextureLoader* textures, class SoundLoader* sounds, class FontLoader* fonts)
:Menu(MENUSTARTX,MENUSTARTY, textures, "TrackMenu.bmp")
{
    addButton(Button(MENUSTARTX, MENUSTARTY, TRACKX, TRACKY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, BUTTON, CLICK, "Tracks", ""));
    addButton(Button(MENUSTARTX, MENUSTARTY, LOADX, LOADY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, BUTTON, CLICK, "Load", ""));
    addButton(Button(MENUSTARTX, MENUSTARTY, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT,
                      textures, sounds, fonts, BUTTON, CLICK, "Quit", ""));
}

TrackMenu::~TrackMenu()
{
    //dtor
}

bool TrackMenu::update()
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

void TrackMenu::draw(sf::RenderWindow& canvas)
{

}
