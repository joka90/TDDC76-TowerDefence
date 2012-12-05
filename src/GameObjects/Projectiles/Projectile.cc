#include "Projectile.h"
#include <cmath>
#define RADIE 50
using namespace std;
Projectile::Projectile(int newX, int newY, int newDamage, int newSpeed, Enemy* newEnemy, std::string textureReference)
: GameObject(newX, newY, textureReference),
  damage(newDamage), speed(newSpeed), enemy(newEnemy)
{
    sprite.setOrigin(5,21);
    setDirection(enemy);
}

/*bool Projectile::drawSprite(sf::RenderWindow& canvas) // Är redan implementerad i GameObject /T
{
   sprite.setPosition(xPos,xPos);
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


void Projectile::setDirection(Enemy* aim)
{
    int enemyPosX;
    int enemyPosY;
    double directionAngle = 0;
    double PI = 3.1415;

    if((enemy != NULL))
    {
        enemyPosX = enemy->getPosX();
        enemyPosY = enemy->getPosY();

        directionAngle = atan2(enemyPosY-yPos,enemyPosX-xPos);
        dirX = speed * cos(directionAngle) + 0.5;
        dirY = speed * sin(directionAngle) + 0.5;

    }

    sprite.setRotation(directionAngle * 180 / PI);
    return;
}


void Projectile::move()//SFML's move fungerar som denna. använda den istället för setPosition?
{
    xPos = xPos + dirX;
    yPos = yPos + dirY;
    return;
}


void Projectile::setClosestEnemy(std::vector<Enemy*>& enemyVector)
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

    enemy = closestEnemy;

    return;
}
bool Projectile::isHit(std::vector<Enemy*>& enemyVector)
{
    bool hit = false;
    int x,y;
    vector<Enemy*> deleteVector;
    for(vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); ++it)
	{
		x = (*it)->getPosX();
		y = (*it)->getPosY();
		if( (pow(getPosX() - x , 2) + pow(getPosY() - y,2)) < RADIE )
		{
            deleteVector.push_back(*it);
            hit = true;
            cout << "TRÄFF" << endl;
		}
	}
	while(!deleteVector.empty())
    {
        for(vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); ++it)
        {
            if(deleteVector[0] == *it)
            {
               // (*it)->onDeath();
                delete(*it);
                enemyVector.erase(it);
                deleteVector.erase(deleteVector.begin());
                break;
            }
        }
    }
    return hit;
}







