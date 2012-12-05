#include "UpgradeMenu.h"
#define UPPGMENUSTARTX 660
#define UPPGMENUSTARTY 10

#define SELLBUTTONX 35
#define SELLBUTTONY 42
#define SELLBUTTONWIDTH 66
#define SELLBUTTONHEIGHT 66
#define SELLBUTTONIMG "button.png"
#define CLICK "CLICK.WAv"
#define SIDE 50

using namespace std;
UpgradeMenu::UpgradeMenu(Player& inPlayer)
: Menu(UPPGMENUSTARTX, UPPGMENUSTARTY, "TowerMenu_BG.png"), player(inPlayer), selectedTower(NULL)
{
    invisible = true;
    addButton(new Button(UPPGMENUSTARTX, UPPGMENUSTARTY, SELLBUTTONX, SELLBUTTONY, SELLBUTTONWIDTH, SELLBUTTONHEIGHT,
                      SELLBUTTONIMG, CLICK, "Sell", ""));
	towerMarker.setSize(sf::Vector2f(SIDE, SIDE));
	towerMarker.setFillColor(sf::Color(255, 255, 255, 0)); // transp
	towerMarker.setOutlineColor(sf::Color::Black);
	towerMarker.setOutlineThickness(2);
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
    towerMarker.setPosition(selectedTower->getPosX()-SIDE/2,selectedTower->getPosY()-SIDE/2);
}
void UpgradeMenu::deselectTower()
{
    selectedTower = NULL;
    sleep();
    invisible = true;
}
