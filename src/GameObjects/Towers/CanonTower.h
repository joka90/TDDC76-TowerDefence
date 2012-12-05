#ifndef CANONTOWER_H
#define CANONTOWER_H
#include "../GameObject.h"
#include "Tower.h"
#include "../Enemies/Enemy.h"
#include "../Projectiles/Projectile.h"
#include "../Projectiles/LongProjectile.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>

class CanonTower : public Tower
{
    public:
        CanonTower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax);
        ~CanonTower();
        LongProjectile* update(std::vector<Enemy*>& enemies);

    protected:
    private:
};

#endif // CANONTOWER_H
