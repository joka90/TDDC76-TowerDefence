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
 * Denna modul hanterar den generella funktionaltet som alla torn i spelet b�r ha.
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
     * @param newRange Tornets r�ckvidd
     * @param newCounterMax Antalet iterationer som definierar hur ofta tornet f�r skjuta
     * @param textureReference En texturreferens
     */
    Tower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax, std::string textureReference);

    /**
     * Konstruktor f�r initiering via sparfil
     * @param parms Str�ng f�r initiering fr�n sparfil. Se getSaveString()
     * @param newCounterMax Antalet iterationer som definierar hur ofta tornet f�r skjuta
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
     * S�tter tornets pris
     * @param newPrice Den nya priset
     */
    void setPrice(int newPrice);

    /**
     * Returnerar priset f�r att uppgradera
     * @return int Priset f�r att uppgradera
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
     * S�tter vad tornet ska skada
     * @param newDamage Vad tornet ska skada
     */
    void setDamage(int newDamage);

    /**
     * Returnerar tornets r�ckvidd
     * @return int Tornets r�ckvidd
     */
    int getRange() const;

    /**
     * S�tter tornets r�ckvidd
     * @param newRange Den nya r�ckvidden
     */
    void setRange(int newRange);

    /**
     * Returnerar en str�ng som anv�nds vid sparande.
     * @return std::string Str�ngen
     */
    std::string getSaveString();

    /**
     * Uppdaterar tornet. Med detta menas att tornet s�ker efter den f�rsta fiende som ocks�
     * �r tillr�ckligt n�ra tornet f�r att skjutas p�. Om tornet �r reda att skjuta skapar den
     * den ocks� en projektil och returnerar en pekare till den projektilen. Kan den inte skjuta
     * eller om det inte finns n�gon fiende inom r�ckvidden returnerar den NULL.
     * @param enemyVector En vektor inneh�llande alla nuvarande vektorer.
     * @return Projectile* En pekare till en Projectile om tornet kan skjuta samt det finns fiende
     *                     inom r�ckvidd. Returnerar annars NULL
     */
    virtual Projectile* update(std::vector<Enemy*>& enemyVector) = 0;

    /**
     * Uppgraderar tornet.
     */
    virtual void upgrade() = 0;

protected:

    /**
     * Returnerar en pekare till den fiende som �r f�rsta fiende som �r inom r�ckvidd. Dvs ordningen p�
     * fienden spelar h�gre roll �n distansen till den s�vida den �r inom r�ckh�ll. Returnerar NULL om
     * det inte finns n�gon fiende inom r�ckh�ll.
     * @param enemyVector En vektor med den nuvarande fienderna
     * @return Enemy* Pekare till en fiende om den �r inom r�ckh�ll(se �ver)
     *                NULL om ingen fiende finns inom r�ckh�ll.
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
