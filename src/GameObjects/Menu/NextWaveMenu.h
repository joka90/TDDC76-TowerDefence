/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    NextWaveMenu.h
 * Enhetsnamn: NextWaveMenu
 * Typ:        definition
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar knappen "next wave" under spelets g�ng
 *
 */

#ifndef NEXTWAVEMENU_H
#define NEXTWAVEMENU_H

#include "Menu.h"


class NextWaveMenu : public Menu
{
    public:
        /**
        * Konstruktor
        * skapar en meny f�r att ha en knapp som skickar n�sta v�g
        */
        NextWaveMenu();
        /**
        * dtor
        */
        virtual ~NextWaveMenu();
        /**
        * update returnerar true om man har tryckt p� new wave knappen och �ndrar state
        */
        bool update();
    protected:
    private:
};

#endif // NEXTWAVEMENU_H
