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

    /**
     * Ganska oklart vad denna ska göra. Om vi inte använder målsökande bör den endast
     * uppdatera dess position. Onödigt att då ha den i LongProjecile. Bör istället
     * kunna byggas i projectile.
     */
    void update(std::vector<Enemy*>& enemies);

protected:
private:
};

#endif // LONGPROJECTILE_H
