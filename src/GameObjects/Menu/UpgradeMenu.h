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
 * Denna modul hanterar menyn som l�ter spelaren s�lja och uppgradera torn, samverkar med ClickManager
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
        * sk�ter uppdatering av tornen, returnerar true om man f�rs�ker s�lja tornet
        */
        bool update();
        /**
        * ritar ut menyn
        * @param canvas f�nstret som man skall rita ut p�
        */
        void drawMenu(sf::RenderWindow& canvas);
        /**
        * markerar ett torn s� att man kan upgradera det tornet
        * @param inTower tornet som man skall merkera
        */
        void selectTower(Tower* inTower);
        /**
        * avmarkerar tornet som �r markerat
        */
        void deselectTower();
        /**
        * returnerar vilket torn som �r markerat
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
