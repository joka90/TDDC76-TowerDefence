#include "Tower.h"
Tower::Tower(int newX, int newY, int newPrice, int newDamage, int newRange,
              TextureLoader& inTextureLoader, SoundLoader& inSoundLoader,
               FontLoader& inFontLoader)
    :GameObject(newX, newY, inTextureLoader, "ENFINBILD"), //skall denna vara har, pure virtual senare?
     price(newPrice), damage(newDamage), range(newRange), towerType("SubType")
{

}

Tower::Tower(std::string parms, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader)
:GameObject(parms, inTextureLoader, "ENFINBILD"), towerType("SubType")
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

/*bool Tower::drawSprite(sf::RenderWindow& canvas) // Ärvs från GameObject ist.. /T
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}*/
