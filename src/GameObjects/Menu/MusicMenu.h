#ifndef MUSICBARMENU_H
#define MUSICBARMENU_H

#include <SFML/Graphics.hpp>
#include <sstream>

#include "Menu.h"
#include "../../Loader/FontLoader.h"
#include "../../ClickManager/Player.h"

class MusicMenu : public Menu
{
    public:
        MusicMenu();
        virtual ~MusicMenu();
        void drawMenu(sf::RenderWindow&);
        bool update();
    protected:
    private:
        AnimatedSprite soundIcon;
		int soundVolume;
};

#endif // MUSICBARMENU_H
