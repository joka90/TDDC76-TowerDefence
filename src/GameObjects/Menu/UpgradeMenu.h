#ifndef UPGRADEMENU_H
#define UPGRADEMENU_H
#include "../../ClickManager/Player.h"
#include "../Towers/Tower.h"
#include "Menu.h"


class UpgradeMenu : public Menu
{
    public:
        UpgradeMenu(/*Player& inPlayer*/);
        virtual ~UpgradeMenu();
        bool upgrade();
        void selectTower(Tower* inTower);
        void deselectTower();
    protected:
    private:
        //Player& player;
        //Tower* selectedTower;
};

#endif // UPGRADEMENU_H
