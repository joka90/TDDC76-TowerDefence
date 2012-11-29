#include "Enemy.h"
Enemy::Enemy(int newX, int newY,int newLife, int newSpeed, int newValue, int newDirX, int newDirY, std::string textureReference, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader)
 : GameObject(newX, newY, inTextureLoader, textureReference), life(newLife), speed(newSpeed), value(newValue), dirX(newDirX), dirY(newDirY), sounds(inSoundLoader)
{

}

Enemy::~Enemy()
{
}

/*bool Enemy::drawSprite(sf::RenderWindow& canvas) // Ärvs från GameObject, behövs ej.. /T
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}*/



int Enemy::getLife() const
{
    return life;
}

void Enemy::setLife(int newLife)
{
    life = newLife;
    return;
}

int Enemy::getSpeed() const
{
    return speed;
}
void Enemy::setSpeed(int newSpeed)
{
    speed = newSpeed;
    return;
}

int Enemy::getValue() const
{
    return value;
}

void Enemy::setValue(int newValue)
{
    value = newValue;
    return;
}

int Enemy::getDirX() const
{
    return dirX;
}

void Enemy::setDirX(int newDirX)
{
    dirX = newDirX;
    return;
}

int Enemy::getDirY() const
{
    return dirY;
}

void Enemy::setDirY(int newDirY)
{
    dirY = newDirY;
    return;
}

void Enemy::hit(int damage)
{
    life = life - damage;
    return;
}


void Enemy::move()
{
    xPos = xPos + dirX;
    yPos = yPos + dirY;
    return;
}


