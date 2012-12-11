/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    CannonTower.cpp
 * Enhetsnamn: CannonTower
 * Typ:        implementering
 * Skriven av: C. Schmidt M. Karlsson
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den de olika piltornen i spelet
 *
 */

#include "LongTower.h"
#include <iostream>
#include "../Projectiles/LongProjectile.h"

LongTower::LongTower(int newX, int newY, int upgradePack)
: Tower(newX, newY, 80, 10, 140, 60, "Sprites/Bunny/Original/bunny_1_small.png")
{
	towerType="LongTower";
    firingSound = new sf::Sound(SoundLoader::getSoundBuffer("arrow_fire.wav"));
	firingSound->setVolume(80);

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
    firingSound = new sf::Sound(SoundLoader::getSoundBuffer("arrow_fire.wav"));
	firingSound->setVolume(80);
}


LongTower::~LongTower()
{
	if(firingSound!=NULL)
	{
		delete(firingSound);
	}
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
            firingSound->play();
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
        price = 140; // Sell price
        range = 300;

        upgradePrice = 90;
        upgradeText = "+Damage\nCost: 90";
    }else if(currentUpgradePack == 2){
        price = 180;// Sell price
        damage = 20;

        upgradePrice = 0;
        upgradeText = "Fully upgraded!";
    }

}
