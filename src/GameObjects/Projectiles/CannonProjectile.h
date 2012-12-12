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
 * Beskrivning: Tanken �r att den skjuter l�ngt och m�ls�ker p� n�rmaste fiende.
 * Om s�kt fiende d�r s�ker den en ny.
 */
class CannonProjectile : public Projectile
{
public:
    CannonProjectile(int newX, int newY, int newDamage, int lifetime, int splashradius, Enemy* newEnemy);
    ~CannonProjectile();

    /**
     * Flyttar projektilen, kollar om den har n�tt sin range eller om den prickat en
     * fiende. Ifall den prickat s� skadar den i s�dana fall fienden.
     * @param enemies Vektor som inneh�ller de nuvarande fienderna p� spelplanen
     * @param visualEffects Vektor f�r inl�ggning av effekter som ska utf�ras
     * @param player Spelar-objektet
     * @return bool TRUE om en fiende �r prickad eller om projektilen m�tt sin range,
     *              False annars.
     */
    bool update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects,Player& player);

    /**
     * Kollar om projektilen har prickat en fiende eller inte. Om den har prickat en fiende s� skadar den
     * fienden. Skulle det vara s� att fienden d�r s� tas fienden bort, det m�las ut blodeffekter samt
     * spelar ges pengar.
     * @param enemyVector Vektorn inneh�llande nuvarande fiender
     * @param visualeffects En vektor f�r inl�ggning av visuellaeffekter som ska m�las ut p� spelplanen
     * @param player Spelar-objektet
     */
    bool isHit(std::vector<Enemy*>& enemyVector, std::vector<VisualEffect*>& visualeffects,Player& player);


protected:

    // Radien som explosionen ska kunna skada inom
    int splashradius;
};

#endif
