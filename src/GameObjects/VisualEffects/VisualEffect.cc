#include "VisualEffect.h"
VisualEffect::VisualEffect(int newX, int newY, int newSpeed, std::string textureReference)
: GameObject(newX, newY, textureReference), //skall denna vara har, pure virtual senare?
  timer(0), speed(newSpeed)
{
}

bool VisualEffect::drawSprite()
{
   sprite.setPosition(xPos,xPos);
   return true;
}
