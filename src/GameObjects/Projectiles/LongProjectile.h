#ifndef LONGPROJECTILE_H
#define LONGPROJECTILE_H
#include "../GameObject.h"
#include "Projectile.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>


class LongProjectile : public Projectile
{
public:
    LongProjectile(int newX, int newY, int newDamage, Enemy* newEnemy);
    ~LongProjectile();

    void update(std::vector<Enemy*>& enemies);

protected:
private:
};

#endif // LONGPROJECTILE_H
