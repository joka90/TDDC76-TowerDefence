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
        SoundMenu();
        virtual ~SoundMenu();
        void drawMenu(sf::RenderWindow&);
        bool update(MusicHandler&);
    protected:
    private:
        AnimatedSprite soundIcon;
		int soundVolume;
		int soundVolumeBeforeMute;
};

#endif // SOUNDMENU_H
