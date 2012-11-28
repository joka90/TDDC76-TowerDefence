#include "LongProjectile.h"


// BESTÄMT ATT PROJEKTILEN HAR 15 I SPEED
LongProjectile::LongProjectile(int newX, int newY, int newDamage,
                               Enemy* newEnemy, TextureLoader& inTextureLoader,
                               SoundLoader& inSoundLoader)
: Projectile(newX, newY, newDamage, 15, newEnemy, inTextureLoader, inSoundLoader)
{

}

LongProjectile::~LongProjectile()
{

}

//INTE FÄRDIGT. OKLART VAD DENNA SKA GÖRA
void LongProjectile::update(std::vector<Enemy*>& enemies)
{
}
