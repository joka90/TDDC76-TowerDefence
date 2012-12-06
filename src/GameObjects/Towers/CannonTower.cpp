#include "CannonTower.h"
#include <iostream>
#include "../Projectiles/CannonProjectile.h"

#define SCALE 0.3
CannonTower::CannonTower(int newX, int newY, int upgradePack)
: Tower(newX, newY, 80, 20, 400, 50, "Sprites/Bunny/Original/tower_bunnies_small.png")
{
	towerType="CannonTower";

    // Upgrade if it should be upgraded
	currentUpgradePack = 0;
	upgradePrice = 100;
    while(currentUpgradePack < upgradePack){
        upgrade();
    }

}

CannonTower::~CannonTower()
{
    //dtor
}
CannonProjectile* CannonTower::update(std::vector<Enemy*>& enemies)
{
    Enemy* enemy = getClosestEnemy(enemies);
    if(counter >= counterMax)
    {
        if(!(enemy == NULL))
        {
            counter = 0;
            CannonProjectile* cannonProjectile = new CannonProjectile(xPos, yPos, damage, enemy);
            return cannonProjectile;
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
void CannonTower::upgrade(){

    ++currentUpgradePack;

    if(currentUpgradePack == 1){
        upgradePrice = 200;
        range = 300;
    }

}