#include "Enemy.h"
Enemy::Enemy(int newX, int newY,int newLife, int newSpeed, int newValue,
          int newDirX, int newDirY, TextureLoader& inTextureLoader,
          SoundLoader& inSoundLoader, FontLoader& inFontLoader)
    : GameObject(newX, newY, inTextureLoader, "ENFINBILD"), //skall denna vara har, pure virtual senare?
      life(newLife), speed(newSpeed), value(newValue), dirX(newDirX), dirY(newDirY)
{

}

Enemy::~Enemy()
{
}

bool Enemy::drawSprite(sf::RenderWindow& canvas)
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}



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

// LITE OKLART MED ARV
void Enemy::move()
{
    //setPos(getPosX + dirX, getPosY() + dirY);
    return;
}


