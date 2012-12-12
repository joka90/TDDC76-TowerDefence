/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    BuyMenu.h
 * Enhetsnamn: BuyMenu
 * Typ:        definition
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hjälper clickManager med köp av olika torn
 *
 */

#ifndef BUYMENU_H
#define BUYMENU_H

#include "Menu.h"
#include "../../ClickManager/Player.h"
#include <iostream>


class BuyMenu : public Menu
{
    public:
        /**
        * Konstruktor
        * @param player spelaren som skall kunna köpa av denna menyn
        */
        BuyMenu(Player& player);
        /**
        * dtor
        */
        virtual ~BuyMenu();
        /**
        * ändrar state för om man har markerat något torn att köpa
        */
        bool update();
        /**
        * slutför ett köp av torn
        */
        bool purchase();
    protected:
    private:
        int currentTowerCost;
        Player& player;
        std::vector<int> priceVector;
        std::vector<std::string> IDvector;
};

#endif // BUYMENU_H
