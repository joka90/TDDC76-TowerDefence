#include "SoundMenu.h"
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
#define BUTTON "transp-1px.png"
#include <iostream>

using namespace std;

SoundMenu::SoundMenu()
 : Menu(MENUSTARTX,MENUSTARTY, "transp-1px.png"), soundIcon(TextureLoader::getTexture("Sound-32.png"), 32, 4, 1, false), soundVolume(100), soundVolumeBeforeMute(100)
{
    addButton(new Button(MENUSTARTX, MENUSTARTY, MOREX, MOREY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, "+ ", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, LESSX, LESSY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, " -", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, MUTEX, MUTEY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, " ", ""));
	soundIcon.setPosition(MENUSTARTX+MUTEX,MENUSTARTY+MUTEY);
	soundIcon.setFrame(3);//3=max volume
}

SoundMenu::~SoundMenu()
{

}
void SoundMenu::drawMenu(sf::RenderWindow& canvas)
{
    //canvas.draw(sprite);//NO BG
    for(int i = 0; i < (int)buttons.size(); ++i)
    {
        buttons[i]->drawButton(canvas, getPosX(), getPosY());
    }
	canvas.draw(soundIcon);
    return;
}
bool SoundMenu::update(MusicHandler& musicHandler)
{
	bool updated = false;
    if(buttons[0]->gotPressed())
    {
        //state = "MORE";
		soundVolume += 20;
		updated = true;
    }
    if(buttons[1]->gotPressed())
    {
        soundVolume -= 20;
		updated = true;
    }
    if(buttons[2]->gotPressed())
    {
		if(soundVolume != 0)//Toggle mute
        {
			soundVolumeBeforeMute=soundVolume;
			soundVolume = 0;
		}
		else
		{
			soundVolume=soundVolumeBeforeMute;
		}
		updated = true;
    }
	if(updated)
	{
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
		soundIcon.setFrame(soundVolume/30);//TODO fix to not show mute sound 10-30 
		/* TODO put code here to update music(Maybe pause if muted) */
 		sf::Listener::setGlobalVolume(soundVolume);//set global volume

	}
    newIteration();
    return false;
}
