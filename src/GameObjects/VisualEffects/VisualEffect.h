#ifndef  VISUALEFFECT_H
#define VISUALEFFECT_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class VisualEffect : public GameObject
{
public:
    VisualEffect(int newX, int newY, int newSpeed, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader);
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:
    int timer;
    int speed;

};
#endif //end VISUALEFFECT_H
