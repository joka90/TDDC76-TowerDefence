#ifndef STARTMENU_H
#define STARTMENU_H

#include "Menu.h"

class StartMenu : public Menu
{
    public:
        StartMenu(TextureLoader& textures, SoundLoader& sounds, FontLoader& fonts);
        virtual ~StartMenu();
        bool update();
    protected:
    private:
};

#endif // STARTMENU_H
