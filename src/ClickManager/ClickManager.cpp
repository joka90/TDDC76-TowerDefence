/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    ClickManager.cpp
 * Enhetsnamn: ClickManager
 * Typ:        implementering
 * Skriven av: C. Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul har hanterar knapptryck på spelplanen då man spelar en level
 *
 */

#include "ClickManager.h"
#include "../GameObjects/Towers/Tower.h"
#include "../GameObjects/Towers/LongTower.h"
#include "../ClassManager.h"
#include "../EventHandler.h"
#include "MapMatrix.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

ClickManager::ClickManager(vector<Tower*>& newTowervector, MapMatrix& newMapMatrix, Player& player)
:    mapMatrix(newMapMatrix), towerVector(newTowervector), markedTower(NULL), buyMenu(player), upgradeMenu(player)
{
    EventHandler::addListener(sf::Event::MouseButtonPressed, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonPressedUser*>(this)));
    EventHandler::addListener(sf::Event::MouseButtonReleased, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonReleasedUser*>(this)));
	towerMarker.setSize(sf::Vector2f(SIDE, SIDE));
}

ClickManager::~ClickManager()
{
    EventHandler::removeListener(sf::Event::MouseButtonPressed, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonPressedUser*>(this)));
    EventHandler::removeListener(sf::Event::MouseButtonReleased, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonReleasedUser*>(this)));
}
void ClickManager::mouseButtonPressedListener(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    vector<Tower*>::iterator it;
    if(mapMatrix.isTaken(x,y))
    {
        for (it = towerVector.begin(); it != towerVector.end(); ++it)
        {
            if(((*it)->getPosX() == (x/SIDE)*SIDE+SIDE/2) && ((*it)->getPosY() == (y/SIDE)*SIDE+SIDE/2))
            {
                upgradeMenu.selectTower(*it);
                break;
            }
        }
    }
    if(event.mouseButton.button == sf::Mouse::Right)
    {
        upgradeMenu.deselectTower();
    }

}
void ClickManager::mouseButtonReleasedListener(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    if(markedTower != NULL)
    {
        if(!mapMatrix.isTaken(x,y))
        {
            if(buyMenu.purchase())
            {
                markedTower->setPos((x/SIDE)*SIDE+SIDE/2, (y/SIDE)*SIDE+SIDE/2);
                markedTower->setColor(sf::Color(255, 255, 255, 255));//reset color
                mapMatrix.setTower(x, y);
                towerVector.push_back(markedTower);
            }
            else
            {
                delete(markedTower);
            }
        }
        else
        {
            delete(markedTower);
        }
        markedTower = NULL;

    }
    //Kolla om torn ska placeras ut


}
void ClickManager::update()
{
    string buyMenuState,upgradeMenuState;
    if(upgradeMenu.update())
    {
        upgradeMenuState = upgradeMenu.readState();
        if(upgradeMenuState == "SELL")
        {
            Tower* removeTower = upgradeMenu.getSelected();
            for (vector<Tower*>::iterator it = towerVector.begin() ; it != towerVector.end(); ++it)
            {
                if((*it) == removeTower)
                {
                    towerVector.erase(it);
                    upgradeMenu.deselectTower();
                    mapMatrix.removeTower(removeTower->getPosX(), removeTower->getPosY());
                    delete(removeTower);
                    break;
                }
            }
        }
    }
    if(buyMenu.update())
    {
    	buyMenuState = buyMenu.readState();
    }
    if(ClassManager::createTowerInstance(buyMenuState) != NULL)
    {
        markedTower = ClassManager::createTowerInstance(buyMenuState);
    }
}
void ClickManager::createTower(int x, int y)
{

	if(!mapMatrix.isTaken(x,y))
	{
			mapMatrix.setTower(x,y);
	}
	else
	{
		//Ge nått visuellt att det inte går att placera tornet på given plats?
	}
}

void ClickManager::drawMenus(sf::RenderWindow& canvas)
{
 	sf::Color badPlacmentColor(255, 0, 0, 180); // red
 	sf::Color okPlacmentColor(0, 255, 0, 180); // green
    buyMenu.drawMenu(canvas);
    upgradeMenu.drawMenu(canvas);
    if(markedTower != NULL)
    {
		sf::Vector2i pos=sf::Mouse::getPosition(canvas);
		towerMarker.setPosition((pos.x/SIDE)*SIDE, (pos.y/SIDE)*SIDE);
		markedTower->setPos(pos.x, pos.y);
		if(!mapMatrix.isTaken(pos.x,pos.y))
		{
			markedTower->setColor(sf::Color(255, 255, 255, 200));
			towerMarker.setFillColor(okPlacmentColor);
		}
		else
		{
			markedTower->setColor(sf::Color(255, 100, 100, 200));
			towerMarker.setFillColor(badPlacmentColor);
		}
		canvas.draw(towerMarker);
		markedTower->drawSprite(canvas);
    }
}
