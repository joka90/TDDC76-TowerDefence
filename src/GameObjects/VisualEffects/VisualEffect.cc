#include "VisualEffect.h"
VisualEffect::VisualEffect(int newX, int newY, int newSpeed, std::string textureReference, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader)
: GameObject(newX, newY, inTextureLoader, textureReference), //skall denna vara har, pure virtual senare?
  timer(0), speed(newSpeed), sounds(inSoundLoader)
{
}

bool VisualEffect::drawSprite(sf::RenderWindow& canvas)
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
