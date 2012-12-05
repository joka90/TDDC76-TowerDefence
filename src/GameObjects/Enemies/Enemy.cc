#include "Enemy.h"

using namespace std;

Enemy::Enemy(int newLife, int newSpeed, int newValue, std::string textureReference)

 : GameObject(0, 0, textureReference), life(newLife), speed(newSpeed), value(newValue)
{
    sprite.setOrigin(SIDE/2, SIDE/2);
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

bool Enemy::update(MapMatrix& map){
    if(stepsMoved == 0)
    {
        nextCoord = map.getCoord(0);
        xPos = nextCoord.first+SIDE/2;
        yPos = nextCoord.second+SIDE/2;
        nextCoord = map.getCoord(1);
        ++stepsMoved;
        newDirection(map);
    }

    // If arrived at a coord, start walk to next
    // if(xPos == nextCoord.first && yPos == nextCoord.second){
    // har man passerat nästa nod
    if(passedNextStep())
    {
        cout << "hej då på dig" << endl;
        ++stepsMoved;
        newDirection(map);
        nextCoord = map.getCoord(stepsMoved);
    }
    if(nextCoord.first == -1 && nextCoord.second == -1)
    {
        return true;
    }
    if(direction == LEFT)
    {
        xPos -= speed;
    }
    else if(direction == RIGHT)
    {
        xPos += speed;
    }
    else if(direction == UP)
    {
        yPos -= speed;
    }
    else
    {
        yPos += speed;
    }
    return false;
}

bool Enemy::passedNextStep()
{
    if((direction == LEFT) && (xPos < nextCoord.first+SIDE/2))
    {
        xPos = nextCoord.first+SIDE/2;
        return true;
    }
    else if((direction == RIGHT) && (xPos > nextCoord.first+SIDE/2))
    {
        xPos = nextCoord.first+SIDE/2;
        return true;
    }
    else if((direction == UP) && (yPos < nextCoord.second+SIDE/2))
    {
        yPos = nextCoord.second+SIDE/2;
        return true;
    }
    else if((direction == DOWN) && (yPos > nextCoord.second+SIDE/2))
    {
        yPos = nextCoord.second+SIDE/2;
        return true;
    }
    return false;
}

void Enemy::newDirection(MapMatrix& map)
    {
        std::pair<int, int> last = map.getCoord(stepsMoved-1);
        std::pair<int, int> next = map.getCoord(stepsMoved);
        if(last.first < next.first)
        {
            direction = RIGHT;
            sprite.setRotation(0);
            return;
        }
        else if(last.first > next.first)
        {
            direction = LEFT;
            sprite.setRotation(180);
            return;
        }
        else if(last.second < next.second)
        {
            direction = DOWN;
            sprite.setRotation(90);
            return;
        }
        else
        {
            direction = UP;
            sprite.setRotation(270);
            return;
        }
    }

void Enemy::hit(int damage)
{
    life = life - damage;
    return;
}




