#include "GameObject.h"

using namespace std;

/*
*   konstruktor, skall det vara s� h�r?
*/
GameObject::GameObject(int x, int y, class TextureLoader* textures, string textureReference)
    : xPos(x), yPos(y)
{
    //sprite = AnimatedSprite(textures->getTexture(textureReference));
    //sprite.setPosition(xPos, yPos);
}

GameObject::~GameObject()
{
    //dtor
}

/*
*   f� fram X positionen
*/
int GameObject::getPosX()
{
    return xPos;
}

/*
*   f� fram Y positionen
*/
int GameObject::getPosY()
{
    return yPos;
}

/*
*   �ndrar XPositionen �ndra f�r sprite ochs�
*/
void GameObject::setPos(int newPosX, int newPosY)
{
    xPos = newPosX;
    yPos = newPosY;
    sprite.setPosition(xPos, yPos);

}

/*
*   ska mer g�ras?
*/
void GameObject::playAnimation()
{
    bool isPlaying = true;
    sprite.play();
    return;
}
void GameObject::pauseAnimation()
{
    bool isPlaying = false;
    sprite.pause();
    return;
}

bool GameObject::drawSprite(sf::RenderWindow& canvas)
{
    sprite.setPosition(xPos, yPos);
    canvas.draw(sprite);
    return true;
}