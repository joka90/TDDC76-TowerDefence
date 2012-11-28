#include "VisualEffect.h"
VisualEffect::VisualEffect(int newX, int newY, int newSpeed, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader)
: GameObject(newX, newY, inTextureLoader, "ENFINBILD"), //skall denna vara har, pure virtual senare?
  timer(0), speed(newSpeed)
{

}

bool VisualEffect::drawSprite(sf::RenderWindow& canvas)
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
