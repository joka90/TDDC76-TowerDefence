#include "LongProjectile.h"


// BEST�MT ATT PROJEKTILEN HAR 15 I SPEED
LongProjectile::LongProjectile(int newX, int newY, int newDamage,
                               Enemy* newEnemy)
: Projectile(newX, newY, newDamage, 15, newEnemy,"Sprites/arrow.png")
{

}

LongProjectile::~LongProjectile()
{

}

//INTE F�RDIGT. OKLART VAD DENNA SKA G�RA
void LongProjectile::update(std::vector<Enemy*>& enemies)
{
}
