#include "LongTower.h"
#include "../Projectiles/LongProjectile.h"



LongTower::LongTower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax,
           TextureLoader& inTextureLoader, SoundLoader& inSoundLoader
           , FontLoader& inFontLoader)
: Tower(newX, newY, newPrice, newDamage, newRange, newCounterMax,"Sprites/Bunny/tower_bunnies.png", inTextureLoader, inSoundLoader, inFontLoader)
{
	towerType="LongTower";
}

LongTower::LongTower(std::string parms, TextureLoader& inTextureLoader,
                     SoundLoader& inSoundLoader, FontLoader& inFontLoader)
: Tower(parms,"Sprites/Bunny/tower_bunnies.png", inTextureLoader, inSoundLoader, inFontLoader)
{
	towerType="LongTower";
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
