#ifndef  TOWER_H
#define TOWER_H
#include "../GameObject.h"

class Tower : public GameObject
{
public:
    Tower(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader class FontLoader* inFontLoader)
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:

}
