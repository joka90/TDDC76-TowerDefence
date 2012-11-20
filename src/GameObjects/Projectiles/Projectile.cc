#include "Projectile.h"
Projectile::Projectile(int newX, int newY, class TextureLoader* inTextureLoader, class SoundLoader* inSoundLoader class FontLoader* inFontLoader)
{

}

bool Projectile::drawSprite(sf::RenderWindow& canvas)
{
   sprite.move(x,y);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
