/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Enemy.h
 * Enhetsnamn: Enemy
 * Typ:        header
 * Skriven av: M. Karlsson, T. Norlund
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar representationen av en fiende i spelet
 *
 */
#ifndef  ENEMY_H
#define ENEMY_H

/**
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include <vector>
#include "../GameObject.h"
#include "../../ClickManager/MapMatrix.h"
#include "../../ClickManager/Player.h"
#include "../VisualEffects/VisualEffect.h"
#include <SFML/Graphics.hpp>


#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

class Enemy : public GameObject
{
public:
    /**
     * Konstruktor
     * @param newLife Fiendens liv
     * @param newSpeed Fiendens hastighet
     * @param newValue Fiendens v�rde
     * @param texturereference En texturereferens
     */
    Enemy(int newLife, int newSpeed, int newValue, std::string textureReference);

    /**
     * Konstruktor
     * @param newLife Fiendens liv
     * @param newSpeed Fiendens hastighet
     * @param newValue Fiendens v�rde
     * @param texturereference En texturereferens
     * @param inSpriteWidth Spritens bredd - Anv�nds till animationen
     * @param inSpriteHeight Spritens h�jd - Anv�nds till animationen
     * @param inNuberOfSprites Antalet sprites - Anv�nds till animationen
     * @param inFpf - Anv�nds till animationen
     */
    Enemy(int newLife, int newSpeed, int newValue, std::string textureReference, unsigned int inSpriteWidth, unsigned int inSpriteHeight,
     unsigned int inNuberOfSprites = 0, unsigned int inFpf = 1);

    /**
     * Destruktor
     */
    ~Enemy();

    /**
     * Returnerar fiendens liv
     * @return int Fienden liv.
     */
    int getLife() const;
    /**
     * S�tter fiendens liv
     * @param newLife Fiendens liv
     */
    void setLife(int newLife);

    /**
     * Returnerar fiendens hastighet
     * @return int Fiendens hastighet
     */
    int getSpeed() const;

    /**
     * S�tter fiendens hastighet
     * @param newSpeed Fiendens hastighet
     */
    void setSpeed(int newSpeed);

    /**
     * Returnerar fiendens v�rde
     * @return int Fienden v�rde
     */
    int getValue() const;

    /**
     * S�tter fiendens v�rde
     * @param newValue Fiendens v�rde
     */
    void setValue(int newValue);

    /**
     * Skadar fienden, dvs minskar livet med specificerad skada
     * @param damage Skadan
     */
    void hit(int damage);

    /**
     * Returnerar om fienden lever eller d�d.
     * @return bool TRUE om life <= 0, FALSE annars.
     */
    bool isDead();

    /**
     * Returnerar hur m�nga steg som fienden r�rt sig
     * @return int Antalet steg
     */
    int getSteps();

    /**
     * R�r fienden
     * @param map Banans MapMatrix
     * @return bool
     */
    bool update(MapMatrix& map);

    /**
     * Exekverar en del saker som ska g�ras d� en fiende d�r.
     * Detta inneb�r utm�lande av blodeffekter samt att ge spelaren pengar.
     * @param visualeffects En vektor f�r inl�ggning av ett VisualEffect-objekt som ska m�la ut
     *                      en effekt.
     * @param player Spelar-objektet
     */
    virtual void onDeath(std::vector<VisualEffect*>& visualeffects, Player& player);

protected:

    /**
     * S�tter vart fienden ska h�rn�st med hj�lp av map.
     * @param map Banans MapMatrix
     */
    void newDirection(MapMatrix& map);

    /**
     * Returnerar om fienden har passerat det "nuvarande" steget eller inte.
     * @return bool TRUE om fienden passerat nuvarande steg, FALSE annars.
     */
    bool passedNextStep();

    /**
     * Medlemsvariabler
     */
    int life;
    int speed;
    int value;
    int stepsMoved;
    int direction;
    int frames; // Antalet frames sedan enemyn p�b�rjat animering fr�n senaste ruta
    std::pair<int, int> nextCoord;
};
#endif
