#include "Tower.h"
#include <cmath>
#include <iostream>
using namespace std;
#define SIDE 50

//--------------- Public -----------------

Tower::Tower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax, std::string textureReference)
: GameObject(newX, newY, textureReference), //skall denna vara har, pure virtual senare?
  price(newPrice), damage(newDamage), range(newRange),counter(0), counterMax(newCounterMax)
{
	sprite.setOrigin(SIDE/2,SIDE/2);

    // Set counter
    counter = newCounterMax;

}

Tower::Tower(std::string parms, std::string textureReference)
:GameObject(parms, textureReference)
{
	int dummyInt;
	//How to scan parameters in towers an other stuff
	sscanf(parms.c_str(),"%i,%i,%i,%i,%i",&dummyInt,&dummyInt,&price,&damage,&range);
}

Tower::~Tower()
{

}

int Tower::getPrice() const
{
    return price;
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

    if(!enemyVector.empty())
    {
        closestEnemy = enemyVector[0];
        closestRange = sqrt(pow((enemyVector[0]->getPosX() - xPos),2) + pow((enemyVector[0]->getPosY() - yPos),2));
        for (unsigned int i = 1; i < enemyVector.size(); ++i)
        {
            rangeToEnemy = sqrt(pow((enemyVector[i]->getPosX() - xPos),2) + pow((enemyVector[i]->getPosY() - yPos),2));
            if (rangeToEnemy < closestRange)
            {
                closestRange = rangeToEnemy;
                closestEnemy = enemyVector[i];
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
    if((closestRange <= range) && (closestRange != 0))
    {
        return closestEnemy;
    }
    else
    {
        return NULL;
    }

}


Projectile* Tower::update(std::vector<Enemy*>& enemyVector)
{
   return NULL;//TODO
}


bool Tower::drawSprite(sf::RenderWindow& canvas) // Ärvs från GameObject ist.. /T
{
   sprite.setPosition(xPos,yPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
