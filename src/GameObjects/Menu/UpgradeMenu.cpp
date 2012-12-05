#include "UpgradeMenu.h"
#define UPPGMENUSTARTX 660
#define UPPGMENUSTARTY 10

#define SELLBUTTONX 35
#define SELLBUTTONY 42
#define UPGRADEBUTTONX 35
#define UPGRADEBUTTONY 112
#define BUTTONWIDTH 66
#define BUTTONHEIGHT 66
#define BUTTONIMG "button.png"
#define CLICK "thozi_daClick.ogg"
#define SIDE 50

using namespace std;
UpgradeMenu::UpgradeMenu(Player& inPlayer)
: Menu(UPPGMENUSTARTX, UPPGMENUSTARTY, "TowerMenu_BG.png"), player(inPlayer), selectedTower(NULL)
{
    invisible = true;
    addButton(new Button(UPPGMENUSTARTX, UPPGMENUSTARTY, SELLBUTTONX, SELLBUTTONY, BUTTONWIDTH, BUTTONHEIGHT,
                      BUTTONIMG, CLICK, "Sell", ""));

    addButton(new Button(UPPGMENUSTARTX, UPPGMENUSTARTY, UPGRADEBUTTONX, UPGRADEBUTTONY, BUTTONWIDTH, BUTTONHEIGHT,
                      BUTTONIMG, CLICK, "Upgrade", ""));

	towerMarker.setSize(sf::Vector2f(SIDE, SIDE));
	towerMarker.setFillColor(sf::Color(255, 255, 255, 0)); // transp
	towerMarker.setOutlineColor(sf::Color::Black);
	towerMarker.setOutlineThickness(2);
	towerRange.setOutlineThickness(2);
	towerRange.setOutlineColor(sf::Color::Red);
	towerRange.setFillColor(sf::Color(255, 255, 255, 0)); // transp
}

UpgradeMenu::~UpgradeMenu()
{
    //dtor
}

void UpgradeMenu::drawMenu(sf::RenderWindow& canvas)
{
    if(selectedTower!=NULL)
    {
    	canvas.draw(towerMarker);//Show selection
    	canvas.draw(towerRange);
    }
    if(invisible)
    {
        return;
    }
    this->drawSprite(canvas);
    for(int i = 0; i < (int)buttons.size(); ++i)
    {
        buttons[i]->drawButton(canvas, getPosX(), getPosY());
    }
    for(int i = 0; i < (int)buttons.size(); ++i)
    {
        buttons[i]->drawHooverText(canvas);
    }
    return;
}


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
    //update selector position
    towerMarker.setPosition((selectedTower->getPosX()-SIDE/2),(selectedTower->getPosY()-SIDE/2));
    towerRange.setRadius(selectedTower->getRange());
    towerRange.setOrigin(selectedTower->getRange(),selectedTower->getRange());
    towerRange.setPosition((selectedTower->getPosX()),(selectedTower->getPosY()));
}
void UpgradeMenu::deselectTower()
{
    selectedTower = NULL;
    sleep();
    invisible = true;
}
