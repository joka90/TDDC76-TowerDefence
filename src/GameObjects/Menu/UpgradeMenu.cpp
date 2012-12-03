#include "UpgradeMenu.h"

#define UPPGMENUSTARTX 600
#define UPPGMENUSTARTY 0

#define UPPGWIDTH 50
#define UPPGHEIGHT 50
#define UPPGBUTTON "BuyButton.png"
<<<<<<< HEAD
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
=======
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
>>>>>>> 92373cb6ee561863f2e3f71b1c513743f9651484

bool UpgradeMenu::update()
{
    //TODO
    newIteration();
    return false;
}
