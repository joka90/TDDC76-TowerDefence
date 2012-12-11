/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    GameObject.cc
 * Enhetsnamn: GameObject
 * Typ:        implementering
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten för saker som skall ha koordinater och skall ritas ut på spelplanen
 *
 */

#include "GameObject.h"
#include <iostream>

using namespace std;
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
}

int GameObject::getPosX()
{
    return xPos;
}


int GameObject::getPosY()
{
    return yPos;
}


void GameObject::setPos(int newPosX, int newPosY)
{
    xPos = newPosX;
    yPos = newPosY;
    sprite.setPosition(xPos, yPos);

}

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

