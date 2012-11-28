#ifndef BUYMENU_H
#define BUYMENU_H

#include "Menu.h"


class BuyMenu : public Menu
{
    public:
        BuyMenu(TextureLoader& textures, SoundLoader& sounds, FontLoader& fonts);
        virtual ~BuyMenu();
        bool update();
    protected:
    private:
        int currentTowerCost;
        std::vector<int> priceVector;
        std::vector<std::string> IDvector;
};

#endif // BUYMENU_H