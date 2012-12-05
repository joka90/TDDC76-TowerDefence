#include "CanonTower.h"
#include <iostream>
#include "../Projectiles/LongProjectile.h"

#define SCALE 0.3
CanonTower::CanonTower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax)
: Tower(newX, newY, newPrice, newDamage, newRange, newCounterMax,"Sprites/Bunny/TowerBunnie/tower_bunnies_small")
{
	towerType="CanonTower";
	counter = newCounterMax;
}

CanonTower::~CanonTower()
{
    //dtor
}
LongProjectile* CanonTower::update(std::vector<Enemy*>& enemies)
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
