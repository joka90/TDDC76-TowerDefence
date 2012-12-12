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

    /**
     * Flyttar projektilen, kollar om den har nått sin range eller om den prickat en
     * fiende. Ifall den prickat så skadar den i sådana fall fienden.
     * @param enemies Vektor som innehåller de nuvarande fienderna på spelplanen
     * @param visualEffects Vektor för inläggning av effekter som ska utföras
     * @param player Spelar-objektet
     * @return bool TRUE om en fiende är prickad eller om projektilen mött sin range,
     *              False annars.
     */
    bool update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects,Player& player);

    /**
     * Kollar om projektilen har prickat en fiende eller inte. Om den har prickat en fiende så skadar den
     * fienden. Skulle det vara så att fienden dör så tas fienden bort, det målas ut blodeffekter samt
     * spelar ges pengar.
     * @param enemyVector Vektorn innehållande nuvarande fiender
     * @param visualeffects En vektor för inläggning av visuellaeffekter som ska målas ut på spelplanen
     * @param player Spelar-objektet
     */
    bool isHit(std::vector<Enemy*>& enemyVector, std::vector<VisualEffect*>& visualeffects,Player& player);


protected:

    // Radien som explosionen ska kunna skada inom
    int splashradius;
};

#endif
