#ifndef LOADMENU_H
#define LOADMENU_H
#include <string>
#include <vector>

#include "Menu.h"

class LoadMenu : public Menu
{
    public:
        /**
        * Konstruktor
        * laddar in data om vilka sparfiler som finns
        */
        LoadMenu();
        /**
        * dtor
        */
        virtual ~LoadMenu();
         /**
        * returnerar true om man försöker ladda ett nytt spel, och ändrar state till filens namn
        */
        bool update();
        /**
        * laddar om vilka filer som finns
        */
		void loadSaveData();
    protected:
    private:
        std::vector<LoadPair> loadVectorData;
        int scrollLenght;

        /**
        * uppdaterar vilka knappar som skall visas soch var dessa är
        */
        void updateLoadButtons();
};

#endif // LOADMENU_H
