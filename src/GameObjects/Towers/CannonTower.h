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
#ifndef CannonTOWER_H
#define CannonTOWER_H
#include "../GameObject.h"
#include "Tower.h"
#include "../Enemies/Enemy.h"
#include "../Projectiles/Projectile.h"
#include "../Projectiles/CannonProjectile.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>

class CannonTower : public Tower
{
    public:
        /**
         * Konstruktor
         * @param newX X-positionen
         * @param newY Y-positionen
         * @param upgradePack Vilket upgrade den ska ha vid initiering
         */
        CannonTower(int newX, int newY, int upgradePack = 0);
        /**
        * Konstruktor
        * Anv�nds vid sparning
        * @param parms
        */
	    CannonTower(std::string parms);
        ~CannonTower();

        /**
         * Uppdaterar tornet. Med detta menas att tornet s�ker efter den f�rsta fiende som ocks�
         * �r tillr�ckligt n�ra tornet f�r att skjutas p�. Om tornet �r reda att skjuta skapar den
         * den ocks� en projektil och returnerar en pekare till den projektilen. Kan den inte skjuta
         * eller om det inte finns n�gon fiende inom r�ckvidden returnerar den NULL.
         * @param enemyVector En vektor inneh�llande alla nuvarande vektorer.
         * @return CannonProjectile* En pekare till en Projectile om tornet kan skjuta samt det finns fiende
         *                     inom r�ckvidd. Returnerar annars NULL
         */
        CannonProjectile* update(std::vector<Enemy*>& enemies);

        /**
        * Uppgraderar tornet genom att �ndra p� flertalet variabler genom att s�tta om t.ex. s�ljspris,
        * skada och r�ckvidd.
        */
        void upgrade();
    protected:
    private:
};

#endif // CannonTOWER_H
