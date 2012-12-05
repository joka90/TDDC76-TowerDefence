#include "UpgradeMenu.h"
#define UPPGMENUSTARTX 660
#define UPPGMENUSTARTY 10

#define SELLBUTTONX 35
#define SELLBUTTONY 42
#define SELLBUTTONWIDTH 66
#define SELLBUTTONHEIGHT 66
#define SELLBUTTONIMG "button.png"
#define CLICK "CLICK.WAW"

using namespace std;
UpgradeMenu::UpgradeMenu(Player& inPlayer)
: Menu(UPPGMENUSTARTX, UPPGMENUSTARTY, "TowerMenu_BG.png"), player(inPlayer), selectedTower(NULL)
{
    invisible = true;
    addButton(new Button(UPPGMENUSTARTX, UPPGMENUSTARTY, SELLBUTTONX, SELLBUTTONY, SELLBUTTONWIDTH, SELLBUTTONHEIGHT,
                      SELLBUTTONIMG, CLICK, "Sell", ""));
}

UpgradeMenu::~UpgradeMenu()
{
    //dtor
}

#define CLICKSOUND "CLICK.WAV"

bool UpgradeMenu::update()
{
    if(buttons[0]->gotPressed())
    {
        state = "SELL";
        invisible = true;
        sleep();
        newIteration();
        player.addMoney(selectedTower->getPrice());
        return true;
    }
    newIteration();
    return true;
}

Tower* UpgradeMenu::getSelected()
{
    return selectedTower;
}

void UpgradeMenu::selectTower(Tower* inTower)
{
    selectedTower = inTower;
    activate();
    invisible = false;
}
void UpgradeMenu::deselectTower()
{
    selectedTower = NULL;
    sleep();
    invisible = true;
}
