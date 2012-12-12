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
        * skapar en meny f�r att kunna �ndra ljudvolym
        */
        SoundMenu();
        /**
        * dtor
        */
        virtual ~SoundMenu();
       	/**
		* drawMenu
		* @param sf::RenderWindow& F�nster att rita p�. �verlagrad f�r att rita ut bild f�r ljudvolym.
		*/
        void drawMenu(sf::RenderWindow&);
       	/**
		* update
		* @param MusicHandler& Om vi vill kunna pausa musiken fr�n menyn.
		*/
        bool update(MusicHandler&);
    protected:
    private:
        AnimatedSprite soundIcon;
		int soundVolume;
		int soundVolumeBeforeMute;
};

#endif // SOUNDMENU_H
