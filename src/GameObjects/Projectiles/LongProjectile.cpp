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
}
