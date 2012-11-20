#ifndef STARTMENU_H
#define STARTMENU_H

#include "Menu.h"

class StartMenu : public Menu
{
    public:
        StartMenu(class TextureLoader* textures, class SoundLoader* sounds, class FontLoader* fonts);
        virtual ~StartMenu();
        bool update();
    	void draw(sf::RenderWindow& canvas);
    protected:
    private:
};

#endif // STARTMENU_H
