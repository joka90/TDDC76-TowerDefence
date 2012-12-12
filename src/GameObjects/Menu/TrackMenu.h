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
 * Denna modul hanterar menyn som l�ter spelaren v�lja bana
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
        * returnerar true om man f�rs�ker starta ett nytt spel, och �ndrar state till filens namn
        */
        bool update();
    protected:
    private:
        std::vector<LoadPair> trackVectorData;
        int scrollLenght;

        void updateLoadButtons();
};

#endif // TRACKMENU_H
