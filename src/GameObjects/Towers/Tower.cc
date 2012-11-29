#include "Tower.h"
#include <cmath>


//--------------- Public -----------------

Tower::Tower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax, std::string textureReference,
              TextureLoader& inTextureLoader, SoundLoader& inSoundLoader,
               FontLoader& inFontLoader)
: GameObject(newX, newY, inTextureLoader, textureReference), //skall denna vara har, pure virtual senare?
  price(newPrice), damage(newDamage), range(newRange),counter(0), counterMax(newCounterMax),
  textures(inTextureLoader), sounds(inSoundLoader), fonts(inFontLoader)
{

}

Tower::Tower(std::string parms, std::string textureReference, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader)
:GameObject(parms, inTextureLoader, textureReference), textures(inTextureLoader), sounds(inSoundLoader), fonts(inFontLoader)
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

    if((closestRange <= range) & (closestRange != 0))
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


/*bool Tower::drawSprite(sf::RenderWindow& canvas) // Ärvs från GameObject ist.. /T
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}*/
