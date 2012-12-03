#include "Projectile.h"
#include <cmath>
Projectile::Projectile(int newX, int newY, int newDamage, int newSpeed, Enemy* newEnemy, std::string textureReference)
: GameObject(newX, newY, textureReference),
  damage(newDamage), speed(newSpeed), enemy(newEnemy)
{

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

void Projectile::move()//SFML's move fungerar som denna. använda den istället för setPosition?
{
    xPos = xPos + dirX;
    yPos = yPos +dirY;
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








