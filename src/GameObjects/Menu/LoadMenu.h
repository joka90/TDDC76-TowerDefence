#ifndef LOADMENU_H
#define LOADMENU_H
#include <string>
#include <vector>

#include "Menu.h"

struct LoadPair
{
    std::string name;
    std::string file;
};

class LoadMenu : public Menu
{
    public:
        LoadMenu(class TextureLoader* textures, class SoundLoader* sounds, class FontLoader* fonts);
        virtual ~LoadMenu();
        bool update();
    protected:
    private:
        std::vector<LoadPair> loadVectorData;
        int scrollLenght;
};

#endif // LOADMENU_H
