#include "Projectile.h"
Projectile::Projectile(int newX, int newY, int newDamage, int newSpeed, Enemy* newEnemy, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader)
: GameObject(newX, newY, inTextureLoader, "ENFINBILD"), //skall denna vara har, pure virtual senare?
  damage(newDamage), speed(newSpeed), enemy(newEnemy)
{

}

/*bool Projectile::drawSprite(sf::RenderWindow& canvas) // Är redan implementerad i GameObject /T
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}*/


int Projectile::getDamage() const
{
    return damage;
}

void Projectile::setDamage(int newDamage)
{
    damage = newDamage;
    return;
}

int Projectile::getSpeed() const
{
    return speed;
}

void Projectile::setSpeed(int newSpeed)
{
    speed = newSpeed;
    return;
}

int Projectile::getDirX() const
{
    return dirX;
}

int Projectile::getDirY() const
{
    return dirY;
}

void Projectile::setDirection(int newDirX, int newDirY)
{
    dirX = newDirX;
    dirY = newDirY;
    return;
}

void Projectile::move()
{
    xPos = xPos + dirX;
    yPos = yPos +dirY;
    return;
}
