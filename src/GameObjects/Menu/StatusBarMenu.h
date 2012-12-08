#ifndef STATUSBARMENU_H
#define STATUSBARMENU_H

#include <SFML/Graphics.hpp>
#include <sstream>

#include "Menu.h"
#include "../../Loader/FontLoader.h"
#include "../../ClickManager/Player.h"

class StatusBarMenu : public Menu
{
    public:
        StatusBarMenu();
        virtual ~StatusBarMenu();
        void drawMenu(sf::RenderWindow&, Player&);
        bool update(bool waveDone);
    protected:
    private:
    sf::Text playerMoney;
	sf::Text playerLife;
};

#endif // STATUSBARMENU_H
