/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    BuyMenu.cpp
 * Enhetsnamn: BuyMenu
 * Typ:        implementering
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hjälper clickManager med köp av olika torn
 *
 */

#include "BuyMenu.h"
#include <iostream>

#define BUYMENUSTARTX 13
#define BUYMENUSTARTY 408

#define TOWERDRAWSTARTX 30
#define TOWERDRAWSTARTY 50
#define TOWERWIDTH 66
#define TOWERHEIGHT 66
#define TOWERDRAWSPACEX 80
#define TOWERBUTTON "button.png"
#define CLICKSOUND "thozi_daClick.ogg"

#define BASTORN "Sprites/Bunny/Original/bunny_1_small.png"
#define ANNATTORN "Sprites/Bunny/TowerBunnie/tower_bunnies_small.png"

using namespace std;
BuyMenu::BuyMenu(Player& inPlayer)
 : Menu(BUYMENUSTARTX, BUYMENUSTARTY, "BuyMenu_BG.png"), player(inPlayer)
{
    //HÅRDKODAT VILKAT TORN SOM FINNS ATT KÖPA
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX, TOWERDRAWSTARTY, TOWERWIDTH, TOWERHEIGHT,
                       TOWERBUTTON, CLICKSOUND, "", "Arrow Tower\nCost: 100"));
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX+TOWERDRAWSPACEX, TOWERDRAWSTARTY, TOWERWIDTH, TOWERHEIGHT,
                       TOWERBUTTON, CLICKSOUND, "", "Bunny Canon\nCost: 300"));

    //lägg till låsatsknappar för utritandet
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX+5, TOWERDRAWSTARTY+10, 0, 0,
                       BASTORN, CLICKSOUND, "", ""));
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX+TOWERDRAWSPACEX+1, TOWERDRAWSTARTY+1, 0, 0,
                       ANNATTORN, CLICKSOUND, "", ""));
    // lägg till priserna på tornen
    priceVector.push_back(100);
    priceVector.push_back(300);
    //lägg till tornen i IDvector
    IDvector.push_back("LONG");
    IDvector.push_back("CANNON");
}

BuyMenu::~BuyMenu()
{
    //dtor
}

bool BuyMenu::purchase()
{
    if(player.canAfford(currentTowerCost))
    {
        player.addMoney(- currentTowerCost);
        return true;
    }
    return false;
}

bool BuyMenu::update()
{
    for(unsigned int i = 0; i < priceVector.size(); ++i)
    {
        if(buttons[i]->gotPressed())
        {
            state = IDvector[i];
            currentTowerCost = priceVector[i];
            newIteration();
            return true;
        }
    }
    newIteration();
    return false;
}
