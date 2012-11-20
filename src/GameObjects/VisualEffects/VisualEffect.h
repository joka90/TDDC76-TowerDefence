#ifndef  VISUALEFFECT_H
#define VISUALEFFECT_H
#include "../GameObject.h"

class VisualEffect : public GameObject
{
public:
    VisualEffect(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader class FontLoader* inFontLoader)
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:

}
