#include "LongProjectile.h"
#include <cmath>


// BEST�MT ATT PROJEKTILEN HAR 15 I SPEED
LongProjectile::LongProjectile(int newX, int newY, int newDamage, int lifetime,
                               Enemy* newEnemy)
: Projectile(newX, newY, newDamage, lifetime, PROJECTILESPEED, newEnemy,"Sprites/arrow.png")
{

}

LongProjectile::~LongProjectile()
{

}
