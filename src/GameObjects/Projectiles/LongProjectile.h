#ifndef LONGPROJECTILE_H
#define LONGPROJECTILE_H
#include "../GameObject.h"
#include "Projectile.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>

/**
 * class LongProjectile
 *
 * Beskrivning: Tanken är att den skjuter långt och målsöker på närmaste fiende.
 * Om sökt fiende dör söker den en ny.
 */
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
