#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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
        GameObject(int x, int y, TextureLoader& inTextures, std::string textureReference);
        GameObject(std::string parms, TextureLoader& inTextures, std::string textureReference);
        virtual ~GameObject();
        int getPosX();
        int getPosY();
        void setPos(int newPosX, int newPosY);
        void playAnimation();
        void pauseAnimation();
        virtual bool drawSprite(sf::RenderWindow& canvas);

    protected:
        int xPos;
        int yPos;
        TextureLoader& textures;
        AnimatedSprite sprite;


};

#endif // GAMEOBJECT_H
