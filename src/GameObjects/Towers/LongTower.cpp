#include "LongTower.h"
#include "../Projectiles/LongProjectile.h"



LongTower::LongTower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax,
           TextureLoader& inTextureLoader, SoundLoader& inSoundLoader
           , FontLoader& inFontLoader)
: Tower(newX, newY, newPrice, newDamage, newRange, newCounterMax, inTextureLoader, inSoundLoader, inFontLoader)
{
}

LongTower::LongTower(std::string parms, TextureLoader& inTextureLoader,
                     SoundLoader& inSoundLoader, FontLoader& inFontLoader)
: Tower(parms, inTextureLoader, inSoundLoader, inFontLoader)
{
}


LongTower::~LongTower()
{
}



LongProjectile* LongTower::update(std::vector<Enemy*>& enemies)
{
    if(counter >= counterMax)
    {
        Enemy* enemy = getClosestEnemy(enemies);
        if(!(enemy == NULL))
        {
            counter = 0;
            LongProjectile* longProjectile = new LongProjectile(xPos, yPos, damage, enemy, textures, sounds);

            return longProjectile;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}
