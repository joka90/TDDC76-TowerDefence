#include "Projectile.h"
#include <cmath>
Projectile::Projectile(int newX, int newY, int newDamage, int newSpeed, Enemy* newEnemy, std::string textureReference)
: GameObject(newX, newY, textureReference),
  damage(newDamage), speed(newSpeed), enemy(newEnemy)
{
    setDirection(enemy);
}

/*bool Projectile::drawSprite(sf::RenderWindow& canvas) // �r redan implementerad i GameObject /T
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
    //double directionRatio;
    double directionAngle;
    //double PI = 3.14159265;

    if((enemy != NULL))
    {
        enemyPosX = enemy->getPosX();
        enemyPosY = enemy->getPosY();

        directionAngle = atan2(enemyPosX- xPos, enemyPosY-yPos);
        dirX = speed * cos(directionAngle) + 0.5;
        dirY = speed * sin(directionAngle) + 0.5;


        // Utkommenterat f�r att man borde kunna anv�nda atan2 som �ver.
        // Plus att detta skjuter �t fel h�ll... =)
        /**
        directionRatio = (enemyPosY - yPos)/(enemyPosX - xPos);
        // Om fiende i projektils f�rsta kvadrant
        if ((directionRatio >= 0) && (enemyPosY >= yPos))
        {
            directionAngle = atan(directionRatio);
            dirX = speed * cos(directionAngle) + 0.5; // +0.5 F�r korrekt avrundning
            dirY = speed * sin(directionAngle) + 0.5; // +0.5 F�r korrekt avrundning
        }
        // Om fiende i projektils tredje kvadrant
        else if ((directionRatio >= 0) && (enemyPosY <= 0))
        {
            directionAngle = atan(directionRatio) + PI/2; // Atan -> vinkel i fjarde kvadranten, adderar d�rf�r Pi/2
            dirX = speed * cos(directionAngle) + 0.5; // +0.5 F�r korrekt avrundning
            dirY = speed * sin(directionAngle) + 0.5; // +0.5 F�r korrekt avrundning
        }
        //Om fiende i projektils andra kvadrant
        else if((directionRatio < 0) && (enemyPosY >= yPos))
        {
            directionAngle = atan(directionRatio) + PI/2; // Atan -> vinkel i fjarde kvadranten, adderar d�rf�r Pi/2
            dirX = speed * cos(directionAngle) + 0.5; // +0.5 F�r korrekt avrundning
            dirY = speed * sin(directionAngle) + 0.5; // +0.5 F�r korrekt avrundning
        }
        //Om fiende i projektils fjarde kvadrant
        else if((directionRatio < 0) && (enemyPosY <= yPos))
        {
            directionAngle = atan(directionRatio);
            dirX = speed * cos(directionAngle) + 0.5; // +0.5 F�r korrekt avrundning
            dirY = speed * sin(directionAngle) + 0.5; // +0.5 F�r korrekt avrundning
        }
        */
    }
    return;
}


void Projectile::move()//SFML's move fungerar som denna. anv�nda den ist�llet f�r setPosition?
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








