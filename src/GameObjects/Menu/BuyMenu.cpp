#include "BuyMenu.h"
#include <iostream>

#define BUYMENUSTARTX 100
#define BUYMENUSTARTY 400

#define TOWERDRAWSTARTX 40
#define TOWERDRAWSTARTY 40
#define TOWERWIDTH 100
#define TOWERHEIGHT 100
#define TOWERDRAWSPACEX 160
#define TOWERBUTTON "BuyButton.png"
#define CLICKSOUND "CLICK.WAW"

#define BASTORN "Sprites/Bunny/Blue/bunny_1.png"
#define ANNATTORN "Sprites/Bunny/TowerBunnie/tower_bunnies.png"

using namespace std;
BuyMenu::BuyMenu()
 : Menu(BUYMENUSTARTX, BUYMENUSTARTY, "StartMenu.png")
{
    //HÅRDKODAT VILKAT TORN SOM FINNS ATT KÖPA
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX, TOWERDRAWSTARTY, TOWERWIDTH, TOWERHEIGHT,
                       TOWERBUTTON, CLICKSOUND, "", "ett billigt och bra torn"));
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX+TOWERDRAWSPACEX, TOWERDRAWSTARTY, TOWERWIDTH, TOWERHEIGHT,
                       TOWERBUTTON, CLICKSOUND, "", "ett annat torn"));

    //lägg till låsatsknappar för utritandet
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX, TOWERDRAWSTARTY, 0, 0,
                       BASTORN, CLICKSOUND, "", ""));
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX+TOWERDRAWSPACEX, TOWERDRAWSTARTY, 0, 0,
                       ANNATTORN, CLICKSOUND, "", ""));
    // lägg till priserna på tornen
    priceVector.push_back(100);
    priceVector.push_back(300);
    //lägg till tornen i IDvector
    IDvector.push_back("BASIC");
    IDvector.push_back("OTHER");
}

BuyMenu::~BuyMenu()
{
    //dtor
}

bool BuyMenu::update()
{
    for(unsigned int i = 0; i < priceVector.size(); ++i)
    {
        if(buttons[i]->gotPressed())
        {
            state = IDvector[i];
            currentTowerCost = priceVector[i];
            return true;
        }
    }
    return false;
}
