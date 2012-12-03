#include "UpgradeMenu.h"
#define UPPGMENUSTARTX 500
#define UPPGMENUSTARTY 0

using namespace std;
UpgradeMenu::UpgradeMenu(Player& inPlayer)
: Menu(UPPGMENUSTARTX, UPPGMENUSTARTY, "StartMenu.png"), selectedTower(NULL), player(inPlayer)
{
    //TODO
}

UpgradeMenu::~UpgradeMenu()
{
    //dtor
}
=======
#define CLICKSOUND "CLICK.WAW"

bool UpgradeMenu::upgrade()
{
    return true;
}

void UpgradeMenu::selectTower(Tower* inTower)
{
    //selectedTower = inTower;
}
void UpgradeMenu::deselectTower()
{
    //selectedTower = NULL;
}
