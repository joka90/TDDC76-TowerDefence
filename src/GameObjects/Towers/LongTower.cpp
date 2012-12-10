#include "LongTower.h"
#include <iostream>
#include "../Projectiles/LongProjectile.h"


LongTower::LongTower(int newX, int newY, int upgradePack)
: Tower(newX, newY, 80, 10, 200, 60, "Sprites/Bunny/Original/bunny_1_small.png")
{
	towerType="LongTower";

    // Upgrade if it should be upgraded
	currentUpgradePack = 0;
	upgradeText = "+Range\nCost: 100";
	upgradePrice = 100;
    while(currentUpgradePack < upgradePack){
        upgrade();
    }

}

LongTower::LongTower(std::string parms)
: Tower(parms,30,"Sprites/Bunny/Original/bunny_1_small.png")
{
	towerType="LongTower";
}


LongTower::~LongTower()
{

}
LongProjectile* LongTower::update(std::vector<Enemy*>& enemies)
{
    Enemy* enemy = getClosestEnemy(enemies);
    if(counter >= counterMax)
    {
        if(!(enemy == NULL))
        {
            counter = 0;
            LongProjectile* longProjectile = new LongProjectile(xPos, yPos, damage, range/PROJECTILESPEED, enemy);
            return longProjectile;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        counter++;
        return NULL;
    }
}


void LongTower::upgrade(){

    ++currentUpgradePack;

    if(currentUpgradePack == 1){
        upgradePrice = 0;
        upgradeText = "Fully upgraded!";
        range = 300;
    }

}
