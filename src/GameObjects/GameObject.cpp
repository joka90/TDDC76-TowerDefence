#include "GameObject.h"

using namespace std;

/*
*   konstruktor, skall det vara s� h�r?
*/
GameObject::GameObject(int x, int y, TextureLoader& inTextures, const string textureReference)
    : xPos(x), yPos(y), textures(inTextures)/*, sprite(inTextures.getTexture(textureReference))*/ //TODO, segfault here
{
    //sprite = AnimatedSprite();
    //sprite.setTextureAnimation(inTextures.getTexture(textureReference));
    //sprite.setTexture(textures.getTexture(textureReference),true);//TODO, segfault here
    //sprite.setPosition(xPos, yPos);
    /*
    * NOOOOOOOOOOOOOOOOOOOOOOOO segfault if initialised in sub classes.
    */
}
GameObject::GameObject(std::string parms, TextureLoader& inTextures, const string textureReference)
:textures(inTextures)
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
