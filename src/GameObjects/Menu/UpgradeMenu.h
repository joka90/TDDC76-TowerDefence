/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    UppgradeMenu.h
 * Enhetsnamn: UppgradeMenu
 * Typ:        definiton
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar menyn som låter spelaren sälja och uppgradera torn, samverkar med ClickManager
 *
 */

#ifndef UPGRADEMENU_H
#define UPGRADEMENU_H
#include "../../ClickManager/Player.h"
#include "../Towers/Tower.h"
#include "Menu.h"


class UpgradeMenu : public Menu
{
    public:
         /**
        * Konstruktor
        * @param inPlayer spelaren som kan uppdatera tornen
        */
        UpgradeMenu(Player& inPlayer);
        /**
        * dtor
        */
        virtual ~UpgradeMenu();
        /**
        * sköter uppdatering av tornen, returnerar true om man försöker sälja tornet
        */
        bool update();
        /**
        * ritar ut menyn
        * @param canvas fönstret som man skall rita ut på
        */
        void drawMenu(sf::RenderWindow& canvas);
        /**
        * markerar ett torn så att man kan upgradera det tornet
        * @param inTower tornet som man skall merkera
        */
        void selectTower(Tower* inTower);
        /**
        * avmarkerar tornet som är markerat
        */
        void deselectTower();
        /**
        * returnerar vilket torn som är markerat
        */
        Tower* getSelected();
    protected:
    private:
        Player& player;
        Tower* selectedTower;
		sf::RectangleShape towerMarker;
		sf::CircleShape towerRange;
};

#endif // UPGRADEMENU_H
