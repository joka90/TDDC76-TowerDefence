#ifndef BUYMENU_H
#define BUYMENU_H

#include "Menu.h"

#include <iostream>


class BuyMenu : public Menu
{
    public:
        BuyMenu();
        virtual ~BuyMenu();
        bool update();
    protected:
    private:
        int currentTowerCost;
        std::vector<int> priceVector;
        std::vector<std::string> IDvector;
};

#endif // BUYMENU_H
