#ifndef BUYMENU_H
#define BUYMENU_H

#include "Menu.h"
#include "../../ClickManager/Player.h"
#include <iostream>


class BuyMenu : public Menu
{
    public:
        BuyMenu(Player& player);
        virtual ~BuyMenu();
        bool update();
        bool purchase();
    protected:
    private:
        int currentTowerCost;
        Player& player;
        std::vector<int> priceVector;
        std::vector<std::string> IDvector;
};

#endif // BUYMENU_H
