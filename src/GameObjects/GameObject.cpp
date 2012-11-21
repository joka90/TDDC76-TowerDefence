#include "GameObject.h"

using namespace std;

/*
*   konstruktor, skall det vara så här?
*/
GameObject::GameObject(int x, int y, TextureLoader& inTextures, string textureReference)
    : xPos(x), yPos(y), textures(inTextures), sprite()/*, sprite(inTextures.getTexture(textureReference))*/ //TODO, segfault here
{
    //sprite.setTexture(textures.getTexture(textureReference),true);//TODO, segfault here
    //sprite.setPosition(xPos, yPos);
    /*
    * NOOOOOOOOOOOOOOOOOOOOOOOO segfault if initialised in sub classes.
    */
}

GameObject::~GameObject()
{
    //dtor
}

/*
*   få fram X positionen
*/
int GameObject::getPosX()
{
    return xPos;
}

/*
*   få fram Y positionen
*/
int GameObject::getPosY()
{
    return yPos;
}

/*
*   ändrar XPositionen ändra för sprite ochså
*/
void GameObject::setPos(int newPosX, int newPosY)
{
    xPos = newPosX;
    yPos = newPosY;
    sprite.setPosition(xPos, yPos);

}

/*
*   ska mer göras?
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
