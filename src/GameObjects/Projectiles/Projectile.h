#ifndef  PROJECTILE_H
#define PROJECTILE_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class Projectile : public GameObject
{
public:
    Projectile(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader, class FontLoader* inFontLoader);
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:

};
#endif //end PROJECTILE_H
