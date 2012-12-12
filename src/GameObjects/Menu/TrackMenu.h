/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    TrackMenu.h
 * Enhetsnamn: TrackMenu
 * Typ:        defnition
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar menyn som låter spelaren välja bana
 *
 */

#ifndef TRACKMENU_H
#define TRACKMENU_H
#include <string>
#include <vector>

#include "Menu.h"

class TrackMenu : public Menu
{
    public:
        /**
        * Konstruktor
        * skapar en meny som visar vilka banor som finns
        */
        TrackMenu();
        /**
        * dtor
        */
        virtual ~TrackMenu();
         /**
        * returnerar true om man försöker starta ett nytt spel, och ändrar state till filens namn
        */
        bool update();
    protected:
    private:
        std::vector<LoadPair> trackVectorData;
        int scrollLenght;

        void updateLoadButtons();
};

#endif // TRACKMENU_H
