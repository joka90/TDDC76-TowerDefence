/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    LongProjectile.cpp
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

#include "LongProjectile.h"
#include <cmath>


LongProjectile::LongProjectile(int newX, int newY, int newDamage, int lifetime,
                               Enemy* newEnemy)
: Projectile(newX, newY, newDamage, lifetime, PROJECTILESPEED, newEnemy,"Sprites/arrow.png")
{

}

LongProjectile::~LongProjectile()
{

}
