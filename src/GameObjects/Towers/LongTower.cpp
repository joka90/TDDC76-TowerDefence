#include "LongTower.h"
#include "../Projectiles/LongProjectile.h"

#define SCALE 0.3

LongTower::LongTower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax)
: Tower(newX, newY, newPrice, newDamage, newRange, newCounterMax,"Sprites/Bunny/tower_bunnies.png")
{
	towerType="LongTower";
	sprite.scale(0.4,0.4);
}

LongTower::LongTower(std::string parms)
: Tower(parms,"Sprites/Bunny/tower_bunnies.png")
{
	towerType="LongTower";
	sprite.scale(0.4,0.4);
}


LongTower::~LongTower()
{

}




LongProjectile* LongTower::update(std::vector<Enemy*>& enemies)
{
    if(counter >= counterMax)
    {
        Enemy* enemy = getClosestEnemy(enemies);
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
        return NULL;
    }
}
