#include "Enemy.h"

using namespace std;

Enemy::Enemy(int newLife, int newSpeed, int newValue, std::string textureReference)

 : GameObject(0, 0, textureReference), life(newLife), speed(newSpeed), value(newValue)
{
    nextCoord = make_pair(0,0);
    stepsMoved = 0;
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


void Enemy::update(MapMatrix& map){
    /*if(stepsMoved == 0){
        nextCoord = map.getCoord(0);
        xPos = nextCoord.first;
        yPos = nextCoord.second;
    }*/

    // If arrived at a coord, start walk to next
    //if(xPos == nextCoord.first && yPos == nextCoord.second){
    if(frames % speed == 0){
        frames = 0;

        nextCoord = map.getCoord(stepsMoved);
        xPos = nextCoord.first;
        yPos = nextCoord.second;

        stepsMoved = stepsMoved +1;
    }
    // if we should move this iteration
    /*if(frames % speed == 0){
        if(xPos != nextCoord.first){
            xPos = (nextCoord.first > xPos)? xPos + 1: xPos - 1;
        }
        if(yPos != nextCoord.second){
            yPos = (nextCoord.second > yPos)? yPos + 1: yPos - 1;
        }
    }*/
    ++frames;
}

void Enemy::hit(int damage)
{
    life = life - damage;
    return;
}




