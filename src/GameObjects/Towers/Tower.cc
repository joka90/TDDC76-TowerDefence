/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Tower.cpp
 * Enhetsnamn: Tower
 * Typ:        implementering
 * Skriven av: M. Karlsson, C. Karlsson Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den generella funktionaltet som alla torn i spelet bör ha.
 *
 */

#include "Tower.h"
#include "../VisualEffects/VisualEffect.h"
#include <cmath>
#include <iostream>
using namespace std;

#define SIDE 50

//--------------- Public -----------------

Tower::Tower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax, std::string textureReference)
: GameObject(newX, newY, textureReference), //skall denna vara har, pure virtual senare?
  price(newPrice), damage(newDamage), range(newRange),counter(0), counterMax(newCounterMax), directionAngle(0)
{
	sprite.setOrigin(SIDE/2,SIDE/2);
    counter = newCounterMax;

}

Tower::Tower(std::string parms, int newCounterMax, std::string textureReference)
:GameObject(parms, textureReference),counter(0), counterMax(newCounterMax), directionAngle(0)
{
	int dummyInt;

	//How to scan parameters in towers an other stuff
	sscanf(parms.c_str(),"%i,%i,%i,%i,%i,%i",&dummyInt,&dummyInt,&price,&damage,&range,&currentUpgradePack);
    // Set counter
    counter = newCounterMax;
    sprite.setOrigin(SIDE/2,SIDE/2);
}

Tower::~Tower()
{
   if(firingSound!=NULL)
	{
		delete(firingSound);
	}
}

bool Tower::drawSprite(sf::RenderWindow& canvas)
{
   sprite.setPosition(xPos,yPos);
   canvas.draw(sprite);
   return true;
}

int Tower::getPrice() const
{
    return price;
}

int Tower::getUpgradePrice() const {
    return upgradePrice;
}

string Tower::getUpgradeText() const {
    return upgradeText;
}


void Tower::setPrice(int newPrice)
{
    price = newPrice;
    return;
}

int Tower::getDamage() const
{
    return damage;
}

void Tower::setDamage(int newDamage)
{
    damage = newDamage;
    return;
}

int Tower::getRange() const
{
    return range;
}

void Tower::setRange(int newRange)
{
    range = newRange;
    return;
}



std::string Tower::getSaveString()
{
    std::stringstream saveString;
    saveString <<  "T " << towerType << " " << getPosX() << "," << getPosY() << "," << price << "," << damage << "," << range << "," << currentUpgradePack;
	return saveString.str();
}



// -------------- Protected .----------------

Enemy* Tower::getClosestEnemy(std::vector<Enemy*>& enemyVector)
{
    Enemy* closestEnemy = NULL;
    double rangeToEnemy;
    bool done = false;

    //Skjuter alltid mot första fienden!
    if(!enemyVector.empty())
    {
        for(vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); ++it)
        {
            rangeToEnemy = sqrt(pow(((*it)->getPosX() - xPos),2) + pow(((*it)->getPosY() - yPos),2));
            if (rangeToEnemy < range)
            {
                if(closestEnemy == NULL)
                {
                    closestEnemy = (*it);
                }
                else if(closestEnemy->getSteps() < (*it)->getSteps())
                {
                    closestEnemy = (*it);
                }
            }
        }
    }

    //calculate tower rotation
    int enemyPosX;
    int enemyPosY;
    double PI = 3.1415;

    if((closestEnemy != NULL))
    {
        enemyPosX = closestEnemy->getPosX();
        enemyPosY = closestEnemy->getPosY();

        directionAngle = atan2(enemyPosY-yPos,enemyPosX-xPos);
    }

    sprite.setRotation(directionAngle*180/PI);

    //return projectile if in range
    return closestEnemy;

}
