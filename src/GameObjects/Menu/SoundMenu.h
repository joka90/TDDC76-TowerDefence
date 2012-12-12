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
        * ritar ut menyn
        * @param canvas fönstret som man ska rita ut på
        */
        void drawMenu(sf::RenderWindow& canvas);
        /**
        * ändrar ljudvolymen
        */
        bool update(MusicHandler&);
    protected:
    private:
        AnimatedSprite soundIcon;
		int soundVolume;
		int soundVolumeBeforeMute;
};

#endif // SOUNDMENU_H
