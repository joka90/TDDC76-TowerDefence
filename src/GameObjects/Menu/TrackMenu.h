#ifndef TRACKMENU_H
#define TRACKMENU_H
#include <string>
#include <vector>

#include "Menu.h"

class TrackMenu : public Menu
{
    public:
        TrackMenu(TextureLoader& textures, SoundLoader& sounds, FontLoader& fonts);
        virtual ~TrackMenu();
        bool update();
    protected:
    private:
        std::vector<LoadPair> trackVectorData;
        int scrollLenght;

        TextureLoader& textures;
        SoundLoader& sounds;
        FontLoader& fonts;

        void updateLoadButtons();
};

#endif // TRACKMENU_H
