#include "Projectile.h"
Projectile::Projectile(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader, class FontLoader* inFontLoader)
:GameObject(newX, newY, inTextureLoader, "ENFINBILD")//skall denna vara har, pure virtual senare?
{

}

bool Projectile::drawSprite(sf::RenderWindow& canvas)
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
