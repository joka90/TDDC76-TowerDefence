#ifndef  PROJECTILE_H
#define PROJECTILE_H
#include "../GameObject.h"

class Projectile : public GameObject
{
public:
    Projectile(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader class FontLoader* inFontLoader)
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:

}
