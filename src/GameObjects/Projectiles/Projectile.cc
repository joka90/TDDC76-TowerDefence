/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Projectile.cc
 * Enhetsnamn: Projectile
 * Typ:        implementering
 * Skriven av: M. Karlsson, C. Karlsson Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den funktionalitet som alla projektiler i spelet bör ha
 *
 */

#include "Projectile.h"
#include <cmath>

using namespace std;
Projectile::Projectile(int newX, int newY, int newDamage, int inLifetime, int newSpeed, Enemy* newEnemy, std::string textureReference)
: GameObject(newX, newY, textureReference), damage(newDamage), speed(newSpeed), enemy(newEnemy), lifetime(inLifetime)
{
    sprite.setOrigin(5,21);
    setDirection(enemy);
}

Projectile::~Projectile()
{
}

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


void Projectile::move()
{
    xPos = xPos + dirX;
    yPos = yPos + dirY;
    return;
}

bool Projectile::isHit(std::vector<Enemy*>& enemyVector, std::vector<VisualEffect*>& visualeffects, Player& player)
{
    bool hit = false;
    int x,y;
    vector<Enemy*> deleteVector;
    for(vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); ++it)
	{
		x = (*it)->getPosX();
		y = (*it)->getPosY();
		if( sqrt((pow(getPosX() - x , 2) + pow(getPosY() - y,2))) < RADIE )
		{
		    (*it)->hit(damage);
		    if((*it)->isDead())
		    {
		        deleteVector.push_back(*it);
		    }
            hit = true;
            break;
		}
	}
	while(!deleteVector.empty())
    {
        for(vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); ++it)
        {
            if(deleteVector[0] == *it)
            {
                (*it)->onDeath(visualeffects, player);
                delete(*it);
                enemyVector.erase(it);
                deleteVector.erase(deleteVector.begin());
                break;
            }
        }
    }
    return hit;
}

bool Projectile::update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects, Player& player)
{
    move();
    --lifetime;
    if(lifetime<0)
    {
        return true;
    }
    return isHit(enemies, visualeffects, player);
}




