/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    LongProjectile.cpp
 * Enhetsnamn: LongProjectile
 * Typ:        implementering
 * Skriven av: C. Schmidt M. Karlsson
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar pil Projektilerna i spelet
 *
 */

#include "LongProjectile.h"
#include <cmath>


// BESTÄMT ATT PROJEKTILEN HAR 15 I SPEED
LongProjectile::LongProjectile(int newX, int newY, int newDamage, int lifetime,
                               Enemy* newEnemy)
: Projectile(newX, newY, newDamage, lifetime, PROJECTILESPEED, newEnemy,"Sprites/arrow.png")
{

}

LongProjectile::~LongProjectile()
{

}
