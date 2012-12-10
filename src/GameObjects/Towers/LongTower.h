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
    LongTower(int newX, int newY, int upgradePack = 0);

    LongTower(std::string parms);

    ~LongTower();

    /**
     * update(std::vector<Enemy*>& enemies>
     *
     * Returnerar en LongProjectile* om det finns en fiende tillräckligt nära tornet.
     * Annars returnerar den NULL.
     */
    LongProjectile* update(std::vector<Enemy*>& enemies);

    void upgrade();

protected:



private:
};

#endif // LONGTOWER_H
