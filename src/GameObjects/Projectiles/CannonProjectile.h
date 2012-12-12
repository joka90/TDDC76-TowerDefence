/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    CanonProjectile.h
 * Enhetsnamn: CanonProjectile
 * Typ:        implementering
 * Skriven av: C. Karlsson Schmidt, D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar kanonProjektilerna i spelet
 *
 */

#ifndef CannonPROJECTILE_H
#define CannonPROJECTILE_H

/**
 * REFERERADE BIBLIOTEK OCH MODULER
 */
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

    bool update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects,Player& player);
    bool isHit(std::vector<Enemy*>& enemyVector, std::vector<VisualEffect*>& visualeffects,Player& player);


protected:
    int splashradius;
};

#endif
