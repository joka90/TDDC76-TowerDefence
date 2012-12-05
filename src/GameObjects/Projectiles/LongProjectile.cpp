#include "LongProjectile.h"
#include <cmath>


// BESTÄMT ATT PROJEKTILEN HAR 15 I SPEED
LongProjectile::LongProjectile(int newX, int newY, int newDamage,
                               Enemy* newEnemy)
: Projectile(newX, newY, newDamage, 15, newEnemy,"Sprites/arrow.png")
{

}

LongProjectile::~LongProjectile()
{

}

//Inte färdig. Oklart vad denna ska göra.
//Fortsätt med olika directions beroende på kvadrant.
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


        // Om fiende i projektils första kvadrant
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
