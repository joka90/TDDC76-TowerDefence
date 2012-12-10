#include "CannonTower.h"
#include <iostream>
#include "../Projectiles/CannonProjectile.h"

#define SCALE 0.3
CannonTower::CannonTower(int newX, int newY, int upgradePack)
: Tower(newX, newY, 80, 20, 200, 140, "Sprites/Bunny/Original/tower_bunnies_small.png")
{
	towerType="CannonTower";
	firingSound = new sf::Sound(SoundLoader::getSoundBuffer("canon_fire.wav"));
	firingSound->setVolume(80);

    // Upgrade if it should be upgraded
	currentUpgradePack = 0;
	upgradePrice = 100;
    while(currentUpgradePack < upgradePack){
        upgrade();
    }

}

CannonTower::CannonTower(std::string parms)
: Tower(parms,50,"Sprites/Bunny/Original/tower_bunnies_small.png")
{
	towerType="CannonTower";
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
            CannonProjectile* cannonProjectile = new CannonProjectile(xPos, yPos, damage, range/CANONPROJECTILESPEED, 70, enemy);
            firingSound->setVolume(80);
            firingSound->play();
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
