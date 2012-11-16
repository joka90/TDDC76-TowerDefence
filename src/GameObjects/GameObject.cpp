#include "GameObject.h"


/*
*   konstruktor, skall det vara s� h�r?
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
*   f� fram X positionen
*/
int getPosX()
{
    return xPos;
}

/*
*   f� fram Y positionen
*/
int getPosY()
{
    return yPos;
}

/*
*   �ndrar XPositionen �ndra f�r sprite ochs�
*/
void setPos(int newPosX, int newPosY)
{
    xPos = newPosX;
    yPos = newPosY;
    sprite.setPosition(xPos, yPos);

}

/*
*   ska mer g�ras?
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
