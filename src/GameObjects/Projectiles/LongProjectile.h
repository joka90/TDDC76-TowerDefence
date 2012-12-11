/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    LongProjectile.h
 * Enhetsnamn: LongProjectile
 * Typ:        implementering
 * Skriven av: M. Karlsson, C. Karlsson Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar pil Projektilerna i spelet
 *
 */

#ifndef LONGPROJECTILE_H
#define LONGPROJECTILE_H

/**
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "../GameObject.h"
#include "Projectile.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>

#define PROJECTILESPEED 10

class LongProjectile : public Projectile
{
public:

    /**
     * Konstruktor.Siktar in fienden mot den fiende som anges bland parametrarna.
     * @param newX X-positionen
     * @param newY Y-positionen
     * @param newDamage Projektilens skada
     * @param lifetime Projektilens lifstid
     * @param newEnemy Den fiende projektilen siktar mot i början
     */
    LongProjectile(int newX, int newY, int newDamage, int lifetime, Enemy* newEnemy);

    /**
     * Destruktor
     */
    ~LongProjectile();
};

#endif // LONGPROJECTILE_H
