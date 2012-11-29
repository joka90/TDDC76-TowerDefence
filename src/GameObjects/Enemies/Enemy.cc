#include "Enemy.h"
Enemy::Enemy(int newX, int newY,int newLife, int newSpeed, int newValue, std::string textureReference, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader)

 : GameObject(newX, newY, inTextureLoader, textureReference), life(newLife), speed(newSpeed), value(newValue), sounds(inSoundLoader)
{

}

Enemy::~Enemy()
{
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


void update(MapMatrix& map){

}

void Enemy::hit(int damage)
{
    life = life - damage;
    return;
}




