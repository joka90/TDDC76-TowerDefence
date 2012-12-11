/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    CannonTower.cpp
 * Enhetsnamn: CannonTower
 * Typ:        implementering
 * Skriven av: M. Karlsson, C. Karlsson Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den de olika piltornen i spelet
 *
 */
#ifndef LONGTOWER_H
#define LONGTOWER_H

/**
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "../GameObject.h"
#include "Tower.h"
#include "../Enemies/Enemy.h"
#include "../Projectiles/Projectile.h"
#include "../Projectiles/LongProjectile.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>


class LongTower : public Tower
{
public:
    /**
     * Konstruktor
     * @param newX X-positionen
     * @param newY Y-positionen
     * @param upgradePack Vilket upgrade den ska ha vid initiering
     */
    LongTower(int newX, int newY, int upgradePack = 0);

    /**
     * Konstruktor
     * @param parms
     */
    LongTower(std::string parms);

    ~LongTower();

    /**
     * Uppdaterar tornet. Med detta menas att tornet söker efter den första fiende som också
     * är tillräckligt nära tornet för att skjutas på. Om tornet är reda att skjuta skapar den
     * den också en projektil och returnerar en pekare till den projektilen. Kan den inte skjuta
     * eller om det inte finns någon fiende inom räckvidden returnerar den NULL.
     * @param enemyVector En vektor innehållande alla nuvarande vektorer.
     * @return LongProjectile* En pekare till en Projectile om tornet kan skjuta samt det finns fiende
     *                     inom räckvidd. Returnerar annars NULL
     */
    LongProjectile* update(std::vector<Enemy*>& enemies);

    /**
     * Uppgraderar tornet genom att ändra på flertalet variabler genom att sätta om t.ex. säljspris,
     * skada och räckvidd.
     */
    void upgrade();

};

#endif
