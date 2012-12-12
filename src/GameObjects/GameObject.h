/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    GameObject.h
 * Enhetsnamn: GameObject
 * Typ:        implementering
 * Skriven av: M. Karlsson
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten för saker som skall ha koordinater och skall ritas ut på spelplanen
 *
 */

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

/**
 * REFERERADE BIBLIOTEK OCH MODULER
 */
#include "../AnimatedSprite.h"
#include "../Loader/MusicLoader.h"
#include "../Loader/TextureLoader.h"
#include "../Loader/SoundLoader.h"
#include "../Loader/FontLoader.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <stdio.h>

class GameObject
{
    public:

        /**
         * Konstruktor
         * @param x X-positionen
         * @param y Y-positonen
         * @param textureReference En texturereferens
         */
        GameObject(int x, int y, std::string textureReference);

        /**
         * Konstruktor
         * @param parms
         * @param textureReference
         */
        GameObject(std::string parms, std::string textureReference);

        /**
         * Destruktor
         */
        virtual ~GameObject();

        /**
         * Returnerar objektets x-position.
         * @return int Objektets x-position.
         */
        int getPosX();

        /**
         * Returnerar objektets y-position.
         * @return int Objektets y-position.
         */
        int getPosY();

        /**
         * Sets the objects x- & y-position samt sätter spritens position
         * till detsamma.
         * @param newPosX Den nya x-positionen.
         * @param newPosY Den nya y-positionen.
         */
        void setPos(int newPosX, int newPosY);

        /**
         * Spelar animationen.
         */
        void playAnimation();

        /**
         * Pausar animationen.
         */
        void pauseAnimation();

        /**
         * Sätter spritens position samt målar ut den.
         * @param canvas Canvasen spriten ska målas ut på.
         */
        virtual bool drawSprite(sf::RenderWindow& canvas);

        /**
         * Sätter färgen på spriten.
         * @param color Färgen.
         */
        void setColor(const sf::Color& color);

    protected:

        /**
         * Medlemsvariabler
         */
        bool isPlaying;
        int xPos;
        int yPos;
        AnimatedSprite sprite;


};

#endif // GAMEOBJECT_H
