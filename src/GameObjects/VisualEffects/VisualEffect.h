#ifndef  VISUALEFFECT_H
#define VISUALEFFECT_H
#include "../GameObject.h"
#include "../../AnimatedSprite.h"
#include <SFML/Graphics.hpp>


class VisualEffect : public GameObject
{
public:
    // Konstruktor
    VisualEffect(int newX, int newY, int newSpeed, int timer, std::string textureReference,
                    unsigned int inSpriteWidth, unsigned int inSpriteHeight,
                    unsigned int inNuberOfSprites, unsigned int inFpf, bool rotate);

    // Updaterar effekten (byter bild i animationen)
    bool update();
private:

protected:
    int timer;
    int speed;

};
#endif //end VISUALEFFECT_H
