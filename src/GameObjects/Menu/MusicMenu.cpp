#include "MusicMenu.h"
#define MENUSTARTX 650
#define MENUSTARTY 560
#define MOREX 64
#define MOREY 0
#define LESSX 0
#define LESSY 0
#define MUTEX 32
#define MUTEY 0
#define BUTTONWIDTH 32
#define BUTTONHEIGHT 32
#define CLICK "thozi_daClick.ogg"
#define BUTTON "statusbarButton.png"
#include <iostream>

using namespace std;

MusicMenu::MusicMenu()
 : Menu(MENUSTARTX,MENUSTARTY, "statusbar.png"), soundIcon(TextureLoader::getTexture("Sound-32.png"), 32, 32, 4, 1, false), soundVolume(100)
{
    addButton(new Button(MENUSTARTX, MENUSTARTY, MOREX, MOREY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, " + ", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, LESSX, LESSY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, " - ", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, " Mute ", ""));
	soundIcon.setPosition(MENUSTARTX+MUTEX,MENUSTARTY+MUTEY);
	soundIcon.setFrame(3);//3=max volyme
}

MusicMenu::~MusicMenu()
{

}
void MusicMenu::drawMenu(sf::RenderWindow& canvas)
{
    canvas.draw(sprite);
    for(int i = 0; i < (int)buttons.size(); ++i)
    {
        buttons[i]->drawButton(canvas, getPosX(), getPosY());
    }
	canvas.draw(soundIcon);
    return;
}
bool MusicMenu::update()
{
    if(buttons[0]->gotPressed())
    {
        //state = "MORE";
		soundVolume += 20;
        return true;
    }
    if(buttons[1]->gotPressed())
    {
        soundVolume -= 20;
        return true;
    }
    if(buttons[1]->gotPressed())
    {
        soundVolume = 0;
        return true;
    }

	//fix volyme
	if(soundVolume<0)
	{
		soundVolume = 0;
	}
	else if(soundVolume>100)
	{
		soundVolume = 100;
	}
	//update sprite
	soundIcon.setFrame(soundVolume/30);//hope this works ok
    newIteration();//TODO
    return false;
}
