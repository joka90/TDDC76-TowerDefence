#include "Projectile.h"
Projectile::Projectile(int newX, int newY, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader)
:GameObject(newX, newY, inTextureLoader, "ENFINBILD")//skall denna vara har, pure virtual senare?
{

}

/*bool Projectile::drawSprite(sf::RenderWindow& canvas) // Är redan implementerad i GameObject /T
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}*/
