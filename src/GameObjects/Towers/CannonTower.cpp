/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    CannonTower.cpp
 * Enhetsnamn: CannonTower
 * Typ:        implementering
 * Skriven av: C. Karlsson Schmidt, D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den de olika kanontornen i spelet
 *
 */

#include "CannonTower.h"
#include <iostream>
#include "../Projectiles/CannonProjectile.h"

#define SCALE 0.3
CannonTower::CannonTower(int newX, int newY, int upgradePack)
: Tower(newX, newY, 200, 20, 200, 140, "Sprites/Bunny/Original/tower_bunnies_small.png")
{
	towerType="CannonTower";
	firingSound = new sf::Sound(SoundLoader::getSoundBuffer("canon_fire.wav"));
	firingSound->setVolume(80);

    // Upgrade if it should be upgraded
	currentUpgradePack = 0;
	upgradeText = "+Damage\nCost: 90";
	upgradePrice = 90;
    while(currentUpgradePack < upgradePack){
        upgrade();
    }

}

CannonTower::CannonTower(std::string parms)
: Tower(parms,50,"Sprites/Bunny/Original/tower_bunnies_small.png")
{
	towerType="CannonTower";
    firingSound = new sf::Sound(SoundLoader::getSoundBuffer("canon_fire.wav"));
	firingSound->setVolume(80);

    int upgradePack = currentUpgradePack;
    currentUpgradePack = 0;
    while(currentUpgradePack < upgradePack){
        upgrade();
    }
}

CannonTower::~CannonTower()
{
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
        price = 250; // Sell price
        damage = 30;

        upgradePrice = 0;
        upgradeText = "+";
    }

}
