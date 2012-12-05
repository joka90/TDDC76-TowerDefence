#ifndef CannonTOWER_H
#define CannonTOWER_H
#include "../GameObject.h"
#include "Tower.h"
#include "../Enemies/Enemy.h"
#include "../Projectiles/Projectile.h"
#include "../Projectiles/LongProjectile.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>

class CannonTower : public Tower
{
    public:
        CannonTower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax);
        ~CannonTower();
        LongProjectile* update(std::vector<Enemy*>& enemies);

    protected:
    private:
};

#endif // CannonTOWER_H
