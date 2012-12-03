#include "GameObject.h"
#include <iostream>

using namespace std;

/*
*   konstruktor, skall det vara s� h�r?
*/
GameObject::GameObject(int x, int y, const string textureReference)
    : isPlaying(true), xPos(x), yPos(y), sprite(TextureLoader::getTexture(textureReference))
{

}
GameObject::GameObject(std::string parms, const string textureReference)
:isPlaying(true), sprite(TextureLoader::getTexture(textureReference))
{
	char dummyStr[100];
	sscanf(parms.c_str(),"%i,%i,%s",&xPos,&yPos,dummyStr);
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
    isPlaying = true;
    sprite.play();
    return;
}
void GameObject::pauseAnimation()
{
    isPlaying = false;
    sprite.pause();
    return;
}

bool GameObject::drawSprite(sf::RenderWindow& canvas)
{
    sprite.setPosition(xPos, yPos);
    canvas.draw(sprite);
    return true;
}
void GameObject::setColor(const sf::Color& color)
{
	sprite.setColor(color);
}

