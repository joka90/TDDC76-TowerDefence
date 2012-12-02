#ifndef UPGRADEMENU_H
#define UPGRADEMENU_H

#include "Menu.h"
#include "../../ClickManager/Player.h"

class UpgradeMenu : public Menu
{
    public:
        UpgradeMenu(Player& inPlayer);
        virtual ~UpgradeMenu();
        bool update();
    protected:
    private:
        Player& player;
};

#endif // UPGRADEMENU_H
