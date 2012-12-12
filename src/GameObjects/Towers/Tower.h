/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Tower.cpp
 * Enhetsnamn: Tower
 * Typ:        implementering
 * Skriven av: M. Karlsson, C. Karlsson Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den generella funktionaltet som alla torn i spelet bör ha.
 *
 */
#ifndef  TOWER_H
#define TOWER_H

/**
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "../GameObject.h"
#include "../Enemies/Enemy.h"
#include "../Projectiles/Projectile.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>


class Tower : public GameObject
{
public:

    /**
     * Konstruktor
     * @param newX X-positionen
     * @param newY Y-positionen
     * @param newPrice Tornets pris
     * @param newDamage Vad tornet skadar
     * @param newRange Tornets räckvidd
     * @param newCounterMax Antalet iterationer som definierar hur ofta tornet får skjuta
     * @param textureReference En texturreferens
     */
    Tower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax, std::string textureReference);

    /**
     * Konstruktor för initiering via sparfil
     * @param parms Sträng för initiering från sparfil. Se getSaveString()
     * @param newCounterMax Antalet iterationer som definierar hur ofta tornet får skjuta
     * @param textureReference En texturreferens
     */
	Tower(std::string parms, int newCounterMax,  std::string textureReference);

    /**
     * Destruktor
     */
    ~Tower();

    /**
     * Returnerar tornets pris
     * @return int Tornets pris
     */
    int getPrice() const;

    /**
     * Sätter tornets pris
     * @param newPrice Den nya priset
     */
    void setPrice(int newPrice);

    /**
     * Returnerar priset för att uppgradera
     * @return int Priset för att uppgradera
     */
    int getUpgradePrice() const;

    /**
     * Returnerar uppgraderingens text.
     * @return std::string Uppgraderingens text
     */
    std::string getUpgradeText() const;

    /**
     * Returnerar vad tornet skadar
     * @return int Vad tornet skadar
     */
    int getDamage() const;

    /**
     * Sätter vad tornet ska skada
     * @param newDamage Vad tornet ska skada
     */
    void setDamage(int newDamage);

    /**
     * Returnerar tornets räckvidd
     * @return int Tornets räckvidd
     */
    int getRange() const;

    /**
     * Sätter tornets räckvidd
     * @param newRange Den nya räckvidden
     */
    void setRange(int newRange);

    /**
     * Returnerar en sträng som används vid sparande.
     * @return std::string Strängen
     */
    std::string getSaveString();

    /**
     * Uppdaterar tornet. Med detta menas att tornet söker efter den första fiende som också
     * är tillräckligt nära tornet för att skjutas på. Om tornet är reda att skjuta skapar den
     * den också en projektil och returnerar en pekare till den projektilen. Kan den inte skjuta
     * eller om det inte finns någon fiende inom räckvidden returnerar den NULL.
     * @param enemyVector En vektor innehållande alla nuvarande vektorer.
     * @return Projectile* En pekare till en Projectile om tornet kan skjuta samt det finns fiende
     *                     inom räckvidd. Returnerar annars NULL
     */
    virtual Projectile* update(std::vector<Enemy*>& enemyVector) = 0;

    /**
     * Uppgraderar tornet.
     */
    virtual void upgrade() = 0;

protected:

    /**
     * Returnerar en pekare till den fiende som är första fiende som är inom räckvidd. Dvs ordningen på
     * fienden spelar högre roll än distansen till den såvida den är inom räckhåll. Returnerar NULL om
     * det inte finns någon fiende inom räckhåll.
     * @param enemyVector En vektor med den nuvarande fienderna
     * @return Enemy* Pekare till en fiende om den är inom räckhåll(se över)
     *                NULL om ingen fiende finns inom räckhåll.
     */
    Enemy* getClosestEnemy(std::vector<Enemy*>& enemyVector);

    /**
     * Medlemsvariabler
     */
    sf::Sound* firingSound;
    int price;
    int upgradePrice;
    std::string upgradeText;
    int currentUpgradePack;
    int damage;
    int range;
    int counter;
    int counterMax;
    double directionAngle;
    std::string towerType;
};
#endif
