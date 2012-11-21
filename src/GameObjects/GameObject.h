#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../AnimatedSprite.h"
#include "../Loader/MusicLoader.h"
#include "../Loader/TextureLoader.h"
#include "../Loader/SoundLoader.h"
#include "../Loader/FontLoader.h"

#include <SFML/Graphics.hpp>
#include <string>

class GameObject
{
    public:
        GameObject(int x, int y, TextureLoader& textures, std::string textureReference);
        virtual ~GameObject();
        int getPosX();
        int getPosY();
        void setPos(int newPosX, int newPosY);
        void playAnimation();
        void pauseAnimation();
        virtual bool drawSprite(sf::RenderWindow& canvas);
    protected:
        AnimatedSprite sprite;
        int xPos;
        int yPos;
    private:

};

#endif // GAMEOBJECT_H
