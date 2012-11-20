#ifndef  ENEMY_H
#define ENEMY_H
#include "../GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader class FontLoader* inFontLoader)
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:

}
