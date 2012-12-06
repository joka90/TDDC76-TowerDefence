#ifndef  VISUALEFFECT_H
#define VISUALEFFECT_H
#include "../GameObject.h"
#include "../../AnimatedSprite.h"
#include <SFML/Graphics.hpp>

class VisualEffect : public GameObject
{
public:
    VisualEffect(int newX, int newY, int newSpeed,  std::string textureReference);
    virtual bool drawSprite();
private:

protected:
    int timer;
    int speed;

};
#endif //end VISUALEFFECT_H
