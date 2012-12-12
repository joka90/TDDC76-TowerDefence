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
        * returnerar true om man f�rs�ker avsluta spelet eller f�rs�ker byta meny, s�ttar state till "QUIT" "TRACKS" respektive "LOAD"
        */
        bool update();
    protected:
    private:
};

#endif // STARTMENU_H
