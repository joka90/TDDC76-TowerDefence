#ifndef CannonTOWER_H
#define CannonTOWER_H
#include "../GameObject.h"
#include "Tower.h"
#include "../Enemies/Enemy.h"
#include "../Projectiles/Projectile.h"
#include "../Projectiles/CannonProjectile.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>

class CannonTower : public Tower
{
    public:
        CannonTower(int newX, int newY, int upgradePack = 0);
        ~CannonTower();
        CannonProjectile* update(std::vector<Enemy*>& enemies);
        void upgrade();
    protected:
    private:
};

#endif // CannonTOWER_H
