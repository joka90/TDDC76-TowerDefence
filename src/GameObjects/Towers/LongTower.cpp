/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    CannonTower.cpp
 * Enhetsnamn: CannonTower
 * Typ:        implementering
 * Skriven av: M. Karlsson, C. Karlsson Schmidt
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
	upgradeText = "+Range\nCost: 80";
	upgradePrice = 80;
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

    int upgradePack = currentUpgradePack;
    currentUpgradePack = 0;
    while(currentUpgradePack < upgradePack){
        upgrade();
    }
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
