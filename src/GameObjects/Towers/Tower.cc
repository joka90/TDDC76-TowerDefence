#include "Tower.h"
Tower::Tower(int newX, int newY, int newPrice, int newDamage, int newRange,
              class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader,
               class FontLoader* inFontLoader)
    :GameObject(newX, newY, inTextureLoader, "ENFINBILD"), //skall denna vara har, pure virtual senare?
     price(newPrice), damage(newDamage), range(newRange)
{
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

bool Tower::drawSprite(sf::RenderWindow& canvas)
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
