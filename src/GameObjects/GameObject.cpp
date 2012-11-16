#include "GameObject.h"


/*
*   konstruktor, skall det vara så här?
*/
GameObject::GameObject(int x, int y, class TextureLoader* textures, sting textureReference)
    : xPos(x), yPos(y)
{
    sprite = AnimatedSprite(textures->getTexture(textureReference))
    sprite.setPosition(xPos, yPos);
}

GameObject::~GameObject()
{
    //dtor
}

/*
*   få fram X positionen
*/
int getPosX()
{
    return xPos;
}

/*
*   få fram Y positionen
*/
int getPosY()
{
    return yPos;
}

/*
*   ändrar XPositionen ändra för sprite ochså
*/
void setPos(int newPosX, int newPosY)
{
    xPos = newPosX;
    yPos = newPosY;
    sprite.setPosition(xPos, yPos);

}

/*
*   ska mer göras?
*/
void playAnimation()
{
    bool isPlaying = true;
    sprite.play();
    return;
}
void pauseAnimation()
{
    bool isPlaying = false;
    sprite.pause();
    return;
}

virtual bool drawSprite(RenderWindow& canvas)
{
    sprite.setPosition(xPos, yPos);
    canvas.draw(sprite);
    return true;
}
