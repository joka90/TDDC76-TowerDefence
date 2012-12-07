#include <random>
#include "../../ClickManager/MapMatrix.h"
#include "VisualEffect.h"
VisualEffect::VisualEffect(int newX, int newY, int newSpeed, int inTimer, std::string textureReference,
                           unsigned int inSpriteWidth, unsigned int inSpriteHeight,
                            unsigned int inNuberOfSprites, unsigned int inFpf, bool rotate)
: GameObject(newX, newY, textureReference), timer(inTimer), speed(newSpeed)
{
    sprite.setOrigin(SIDE/2, SIDE/2);
    sprite.setAnimationProps(inSpriteWidth,inSpriteHeight,inNuberOfSprites,inFpf,true);
    if(rotate)
    {
        sprite.rotate(std::rand()%360);
    }
}

bool VisualEffect::update()
{
    sprite.update();
    --timer;
    if(timer<0)
    {
        return true;
    }
    return false;
}
