#include "UpgradeMenu.h"
#define UPPGMENUSTARTX 500
#define UPPGMENUSTARTY 0

#define SELLBUTTONX 50
#define SELLBUTTONY 50
#define SELLBUTTONWIDTH 50
#define SELLBUTTONHEIGHT 50
#define SELLBUTTONIMG "button.png"
#define CLICK "CLICK.WAW"

using namespace std;
UpgradeMenu::UpgradeMenu(Player& inPlayer)
: Menu(UPPGMENUSTARTX, UPPGMENUSTARTY, "StartMenu.png"), player(inPlayer), selectedTower(NULL)
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
