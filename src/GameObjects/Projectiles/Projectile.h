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
 * Denna modul hanterar den funktionalitet som alla projektiler i spelet b�r ha
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
     * Kontstruktor. Kontstruktorn k�r ocks� setDirection(Enemy* enemy) vilket
     * har till f�ljd av Projektilen ricktas in p� den fiende tornet har sagt �t
     * projektilen att sikta p�.
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
     * Flyttar projektilen, kollar om den har n�tt sin range eller om den prickat en
     * fiende. Ifall den prickat s� skadar den i s�dana fall fienden.
     * @param enemies Vektor som inneh�ller de nuvarande fienderna p� spelplanen
     * @param visualEffects Vektor f�r inl�ggning av effekter som ska utf�ras
     * @param player Spelar-objektet
     * @return bool TRUE om en fiende �r prickad eller om projektilen m�tt sin range,
     *              False annars.
     */
    virtual bool update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects,Player& player);

    /**
     * Returnerar projektilens skada
     * @return int Vad projektilen skadar
     */
    int getDamage() const;

    /**
     * S�tter projektilens skada
     * @param newDamage Den nya skadan
     */
    void setDamage(int newDamage);

    /**
     * Returnerar projektilens hastighet
     * @return int Projektilens hastighet
     */
    int getSpeed() const;

    /**
     * S�tter projektilens hastighet
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
     * S�tter projektilens hastighet i X- samt Y-led.
     * @param newDirX Den nya hastigheten i X-led.
     * @param newDirY Den nya hastigheten i Y-led.
     */
    void setDirection(int newDirX, int newDirY);

    /**
     * Riktar in projektilen i en linj�r bana mot Enemy* aim:s
     * nuvarande position.
     * @param aim En pekare p� en fiende
     */
    void setDirection(Enemy* aim);

    /**
     * Flyttar fienden ett steg
     */
    void move();

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
     * S�tter medlemsvariabeln enemy till att peka p� den fiende som �r n�rmast projektilen.
     * @param enemyVector En vektor som inneh�ller de nuvarande fienderna.
     */
    void setClosestEnemy(std::vector<Enemy*>& enemyVector);

};
#endif //end PROJECTILE_H
