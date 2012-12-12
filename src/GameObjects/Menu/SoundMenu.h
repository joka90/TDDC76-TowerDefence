#ifndef SOUNDMENU_H
#define SOUNDMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>

#include "Menu.h"
#include "../../MusicHandler.h"

class SoundMenu : public Menu
{
    public:
        /**
        * Konstruktor
        * skapar en meny för att kunna ändra ljudvolym
        */
        SoundMenu();
        /**
        * dtor
        */
        virtual ~SoundMenu();
       	/**
		* drawMenu
		* @param sf::RenderWindow& Fönster att rita på. Överlagrad för att rita ut bild för ljudvolym.
		*/
        void drawMenu(sf::RenderWindow&);
       	/**
		* update
		* @param MusicHandler& Om vi vill kunna pausa musiken från menyn.
		*/
        bool update(MusicHandler&);
    protected:
    private:
        AnimatedSprite soundIcon;
		int soundVolume;
		int soundVolumeBeforeMute;
};

#endif // SOUNDMENU_H
