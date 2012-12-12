#ifndef STARTMENU_H
#define STARTMENU_H

#include "Menu.h"

class StartMenu : public Menu
{
    public:
        /**
        * Konstruktor
        * skapar en startmeny
        */
        StartMenu();
        /**
        * dtor
        */
        virtual ~StartMenu();
        /**
        * returnerar true om man försöker avsluta spelet eller försöker byta meny, sättar state till "QUIT" "TRACKS" respektive "LOAD"
        */
        bool update();
    protected:
    private:
};

#endif // STARTMENU_H
