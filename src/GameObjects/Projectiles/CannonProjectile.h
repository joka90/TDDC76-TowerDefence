#ifndef CannonPROJECTILE_H
#define CannonPROJECTILE_H
#include "../GameObject.h"
#include "Projectile.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>
#include "../VisualEffects/VisualEffect.h"

#define CANONPROJECTILESPEED 15

/**
 * class CannonProjectile
 *
 * Beskrivning: Tanken är att den skjuter långt och målsöker på närmaste fiende.
 * Om sökt fiende dör söker den en ny.
 */
class CannonProjectile : public Projectile
{
public:
    CannonProjectile(int newX, int newY, int newDamage, int lifetime, int splashradius, Enemy* newEnemy);
    ~CannonProjectile();

    /**
     * Ganska oklart vad denna ska göra. Om vi inte använder målsökande bör den endast
     * uppdatera dess position. Onödigt att då ha den i CannonProjecile. Bör istället
     * kunna byggas i projectile.
     */

    bool update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects);
    bool isHit(std::vector<Enemy*>& enemyVector, std::vector<VisualEffect*>& visualeffects);


protected:
    int splashradius;
private:
    sf::Sound* onDeathSound;
};

#endif // CannonPROJECTILE_H

