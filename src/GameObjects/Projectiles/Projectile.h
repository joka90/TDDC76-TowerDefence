/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Projectile.h
 * Enhetsnamn: Projectile
 * Typ:        implementering
 * Skriven av: M. Karlsson, C. Karlsson Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den funktionalitet som alla projektiler i spelet bör ha
 *
 */

#ifndef  PROJECTILE_H
#define PROJECTILE_H

/**
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "../GameObject.h"
#include "../VisualEffects/VisualEffect.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>
#define RADIE 30


class Projectile : public GameObject
{
public:

    /**
     * Kontstruktor. Kontstruktorn kör också setDirection(Enemy* enemy) vilket
     * har till följd av Projektilen ricktas in på den fiende tornet har sagt åt
     * projektilen att sikta på.
     * @param newX X-positionen
     * @param newY Y-positionen
     * @param newDamage Projektilens skada
     * @param newSpeed Projektilens hastighet
     * @param inLifetime
     * @param newEnemy Fienden projektilen siktar mot
     * @param textureReference En texturreferens
     */
    Projectile(int newX, int newY, int newDamage, int newSpeed, int inLifetime, Enemy* newEnemy, std::string textureReference);
    ~Projectile();

    /**
     * Flyttar projektilen, kollar om den har nått sin range eller om den prickat en
     * fiende. Ifall den prickat så skadar den i sådana fall fienden.
     * @param enemies Vektor som innehåller de nuvarande fienderna på spelplanen
     * @param visualEffects Vektor för inläggning av effekter som ska utföras
     * @param player Spelar-objektet
     * @return bool TRUE om en fiende är prickad eller om projektilen mött sin range,
     *              False annars.
     */
    virtual bool update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects,Player& player);

    /**
     * Returnerar projektilens skada
     * @return int Vad projektilen skadar
     */
    int getDamage() const;

    /**
     * Sätter projektilens skada
     * @param newDamage Den nya skadan
     */
    void setDamage(int newDamage);

    /**
     * Returnerar projektilens hastighet
     * @return int Projektilens hastighet
     */
    int getSpeed() const;

    /**
     * Sätter projektilens hastighet
     * @param newSpeed Den nya hastigheten
     */
    void setSpeed(int newSpeed);

    /**
     * Returnerar projektilens hastighet i X-led
     * @return int Hastigheten i X-led.
     */
    int getDirX() const;

    /**
     * Returnerar projektilens hastighet i Y-led
     * @return int Hastigheten i Y-led.
     */
    int getDirY() const;

    /**
     * Sätter projektilens hastighet i X- samt Y-led.
     * @param newDirX Den nya hastigheten i X-led.
     * @param newDirY Den nya hastigheten i Y-led.
     */
    void setDirection(int newDirX, int newDirY);

    /**
     * Riktar in projektilen i en linjör bana mot Enemy* aim:s
     * nuvarande position.
     * @param aim En pekare på en fiende
     */
    void setDirection(Enemy* aim);

    /**
     * Flyttar fienden ett steg
     */
    void move();

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
    /**
     * Medlemsvariabler
     */
    sf::Sound* onDeathSound;
    int damage;
    int speed;
    int dirX;
    int dirY;
    Enemy* enemy;
    int lifetime;

    /**
     * Sätter medlemsvariabeln enemy till att peka på den fiende som är närmast projektilen.
     * @param enemyVector En vektor som innehåller de nuvarande fienderna.
     */
    void setClosestEnemy(std::vector<Enemy*>& enemyVector);

};
#endif //end PROJECTILE_H
