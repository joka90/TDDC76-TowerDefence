#include "Tower.h"
#include <cmath>


//--------------- Public -----------------

Tower::Tower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax,
              TextureLoader& inTextureLoader, SoundLoader& inSoundLoader,
               FontLoader& inFontLoader)
    :GameObject(newX, newY, inTextureLoader, "ENFINBILD"), //skall denna vara har, pure virtual senare?
     price(newPrice), damage(newDamage), range(newRange), counter(0), counterMax(newCounterMax)
{

}

Tower::Tower(std::string parms, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader)
:GameObject(parms, inTextureLoader, "ENFINBILD")
{
		int dummyInt;
		//How to scan parameters in towers an other stuff
		//sscanf (parms,"%i,%i,%i,%i,%i",&dummyInt,&dummyInt,&price,&damage,&range);
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

/*
//SKA VARA VIRTUAL. SJÄLVA KODEN SKA NER I ARVET.
Projectile* Tower::update(std::vector<Enemy*> enemyVector)
{
    if(counter >= counterMax)
    {
        Enemy* enemy = getClosestEnemy(enemyVector);
        if(!(enemy == NULL))
        {
            counter = 0;
            // SKAPA PEKARE TILL PROJEKTIL
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
*/


// -------------- Protected .----------------

// Returnerar en pekare till den fiende som är närmast, fast endast om fienden
// ligger inom tornets range. Annars returnerar den NULL.
Enemy* Tower::getClosestEnemy(std::vector<Enemy*> enemyVector)
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

    if((closestRange <= range) & (closestRange != 0))
    {
        return closestEnemy;
    }
    else
    {
        return NULL;
    }
}






/*bool Tower::drawSprite(sf::RenderWindow& canvas) // Ärvs från GameObject ist.. /T
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}*/
