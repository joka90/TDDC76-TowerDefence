#ifndef LOADMENU_H
#define LOADMENU_H
#include <string>
#include <vector>

#include "Menu.h"

class LoadMenu : public Menu
{
    public:
        LoadMenu(TextureLoader& textures, SoundLoader& sounds, FontLoader& fonts);
        virtual ~LoadMenu();
        bool update();
    protected:
    private:
        std::vector<LoadPair> loadVectorData;
        int scrollLenght;

        TextureLoader& textures;
        SoundLoader& sounds;
        FontLoader& fonts;

        void updateLoadButtons();
};

#endif // LOADMENU_H
