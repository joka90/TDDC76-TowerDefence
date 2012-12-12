#ifndef NEXTWAVEMENU_H
#define NEXTWAVEMENU_H

#include "Menu.h"


class NextWaveMenu : public Menu
{
    public:
        /**
        * Konstruktor
        * skapar en meny för att ha en knapp som skickar nästa våg
        */
        NextWaveMenu();
        /**
        * dtor
        */
        virtual ~NextWaveMenu();'
        /**
        * update returnerar true om man har tryckt på new wave knappen och ändrar state
        */
        bool update();
    protected:
    private:
};

#endif // NEXTWAVEMENU_H
