#ifndef LONGTOWER_H
#define LONGTOWER_H
#include "../GameObject.h"
#include "Tower.h"
#include "../Enemies/Enemy.h"
#include "../Projectiles/Projectile.h"
#include "../Projectiles/LongProjectile.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>


class LongTower : public Tower
{
public:
    LongTower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax,
        TextureLoader& inTextureLoader, SoundLoader& inSoundLoader
        , FontLoader& inFontLoader);

    LongTower(std::string parms, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader);

    ~LongTower();

    LongProjectile* update(std::vector<Enemy*>& enemies);

protected:



private:

};

#endif // LONGTOWER_H
