#include "Tower.h"
#include <cmath>

#define SIDE 50

//--------------- Public -----------------

Tower::Tower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax, std::string textureReference)
: GameObject(newX, newY, textureReference), //skall denna vara har, pure virtual senare?
  price(newPrice), damage(newDamage), range(newRange),counter(0), counterMax(newCounterMax)
{
	sprite.setOrigin(SIDE/2,SIDE/2);
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
        Enemy* closestEnemy = enemyVector[0];
        closestRange = sqrt(((enemyVector[0]->getPosX() - xPos)^2) + ((enemyVector[0]->getPosY() - yPos)^2));

        for (unsigned int i = 1; i < enemyVector.size(); ++i)
        {
            rangeToEnemy = sqrt(((enemyVector[i]->getPosX() - xPos)^2) + ((enemyVector[i]->getPosY() - yPos)^2));
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
    double directionRatio;
    double PI = 3.14159265;
    if((closestEnemy != NULL))
    {
        enemyPosX = closestEnemy->getPosX();
        enemyPosY = closestEnemy->getPosY();
        directionRatio = (enemyPosY - yPos)/(enemyPosX - xPos);

        // Om fiende i projektils första kvadrant
        //Om fiende i projektils fjarde kvadrant
        if (directionRatio >= 0)
        {
            directionAngle = atan(directionRatio);
        }
        // Om fiende i projektils tredje kvadrant
        //Om fiende i projektils andra kvadrant
        else if(directionRatio < 0)
        {
            directionAngle = atan(directionRatio) + PI/2; // Atan -> vinkel i fjarde kvadranten, adderar därför Pi/2
        }
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
   sprite.setPosition(xPos-SIDE/2,yPos-SIDE/2);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
