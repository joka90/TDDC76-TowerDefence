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

    // Set counter
    counter = newCounterMax;

}

Tower::Tower(std::string parms, int newCounterMax, std::string textureReference)
:GameObject(parms, textureReference),counter(0), counterMax(newCounterMax), directionAngle(0)
{
	int dummyInt;
	//How to scan parameters in towers an other stuff
	sscanf(parms.c_str(),"%i,%i,%i,%i,%i",&dummyInt,&dummyInt,&price,&damage,&range);
    // Set counter
    counter = newCounterMax;
    sprite.setOrigin(SIDE/2,SIDE/2);
}

Tower::~Tower()
{

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
    saveString <<  "T " << towerType << " " << getPosX() << "," << getPosY() << "," << price << "," << damage << "," << range;
	return saveString.str();
}



// -------------- Protected .----------------

// Returnerar en pekare till den fiende som är närmast, fast endast om fienden
// ligger inom tornets range. Annars returnerar den NULL.
Enemy* Tower::getClosestEnemy(std::vector<Enemy*>& enemyVector)
{
    Enemy* closestEnemy = NULL;
    double closestRange = 0;
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


Projectile* Tower::update(std::vector<Enemy*>& enemyVector)
{
   return NULL;//TODO
}


bool Tower::drawSprite(sf::RenderWindow& canvas)
{
   sprite.setPosition(xPos,yPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}

