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
 * Denna modul hj�lper clickManager med k�p av olika torn
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
        * @param player spelaren som skall kunna k�pa av denna menyn
        */
        BuyMenu(Player& player);
        /**
        * dtor
        */
        virtual ~BuyMenu();
        /**
        * �ndrar state f�r om man har markerat n�got torn att k�pa
        */
        bool update();
        /**
        * slutf�r ett k�p av torn
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
