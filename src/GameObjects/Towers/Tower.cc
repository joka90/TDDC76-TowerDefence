#include "Tower.h"
Tower::Tower(int newX, int newY, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader)
:GameObject(newX, newY, inTextureLoader, "ENFINBILD")//skall denna vara har, pure virtual senare?
{

}

bool Tower::drawSprite(sf::RenderWindow& canvas)
{
   sprite.move(xPos,xPos);
   canvas.draw(sprite);//game object always have a sprite
   return true;
}
