#include "CannonTower.h"
#include <iostream>
#include "../Projectiles/LongProjectile.h"

#define SCALE 0.3
CannonTower::CannonTower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax)
: Tower(newX, newY, newPrice, newDamage, newRange, newCounterMax,"Sprites/Bunny/TowerBunnie/tower_bunnies_small")
{
	towerType="CannonTower";
	counter = newCounterMax;
}

CannonTower::~CannonTower()
{
    //dtor
}
LongProjectile* CannonTower::update(std::vector<Enemy*>& enemies)
{
    Enemy* enemy = getClosestEnemy(enemies);
    if(counter >= counterMax)
    {
        if(!(enemy == NULL))
        {
            counter = 0;
            LongProjectile* longProjectile = new LongProjectile(xPos, yPos, damage, enemy);
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
