#include "LongProjectile.h"
#include <cmath>


// BEST�MT ATT PROJEKTILEN HAR 15 I SPEED
LongProjectile::LongProjectile(int newX, int newY, int newDamage,
                               Enemy* newEnemy)
: Projectile(newX, newY, newDamage, 15, newEnemy,"Sprites/arrow.png")
{

}

LongProjectile::~LongProjectile()
{

}

//Inte f�rdig. Oklart vad denna ska g�ra.
//Forts�tt med olika directions beroende p� kvadrant.
bool LongProjectile::update(std::vector<Enemy*>& enemies)
{
    move();
    return isHit(enemies);



    /*
    int enemyPosX;
    int enemyPosY;
    double directionRatio;
    double directionAngle;
    double PI = 3.14159265

    if((enemy == NULL) && (enemies.empty()))
    {
    }
    else
    {
        if(enemy == NULL)
        {
            setClosestEnemy();
        }
        enemyPosX = enemy->getPosX();
        enemyPosY = enemy->getPosY();
        directionRatio = (enemyPosY - yPos)/(enemyPosX - xPos);


        // Om fiende i projektils f�rsta kvadrant
        if ((directionRatio > 0) && ((enemyPosY - yPos) > 0))
        {
            directionAngle = atan(directionRatio);
            dirX = speed * cos(directionAngle) + 0.5;
            dirY = speed * sin(direectionAngle) + 0.5;
        }
        // Om fiende i projektils tredje kvadrant
        else if ((directionRatio > 0) && ((enemyPosY - yPos) < 0))
        {
            directionAngle = atan(directionRatio) + PI/2;
            dirX = speed * cos(directionAngle) + 0.5;
            dirY = speed * sin(directionAngle) + 0.5;
        }


    }
    */

}
