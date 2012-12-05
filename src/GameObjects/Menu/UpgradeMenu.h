#ifndef UPGRADEMENU_H
#define UPGRADEMENU_H
#include "../../ClickManager/Player.h"
#include "../Towers/Tower.h"
#include "Menu.h"


class UpgradeMenu : public Menu
{
    public:
        UpgradeMenu(Player& inPlayer);
        virtual ~UpgradeMenu();
        bool update();
        void drawMenu(sf::RenderWindow& canvas);
        void selectTower(Tower* inTower);
        void deselectTower();
        Tower* getSelected();
    protected:
    private:
        Player& player;
        Tower* selectedTower;
		sf::RectangleShape towerMarker;
		sf::CircleShape towerRange;
};

#endif // UPGRADEMENU_H
