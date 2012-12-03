#include "UpgradeMenu.h"

#define UPPGMENUSTARTX 600
#define UPPGMENUSTARTY 0

#define UPPGWIDTH 50
#define UPPGHEIGHT 50
#define UPPGBUTTON "BuyButton.png"
#define CLICKSOUND "CLICK.WAW"

UpgradeMenu::UpgradeMenu(Player& inPlayer)
 : Menu(UPPGMENUSTARTX, UPPGMENUSTARTY, "StartMenu.png"), player(inPlayer)
{
    //TODO
}

UpgradeMenu::~UpgradeMenu()
{
    //dtor
}

bool UpgradeMenu::update()
{
    //TODO
    newIteration();
    return false;
}
