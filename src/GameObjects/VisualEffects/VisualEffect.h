#ifndef  VISUALEFFECT_H
#define VISUALEFFECT_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class VisualEffect : public GameObject
{
public:
    VisualEffect(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader, class FontLoader* inFontLoader);
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:

};
#endif //end VISUALEFFECT_H
