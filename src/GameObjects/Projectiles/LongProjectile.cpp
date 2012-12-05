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
}
