/*
 * ClickManager.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
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
/*
 * Fler saker ska in in konstruktorn så fort den koden är klar!
 */
/*
 * Musens rörs, släpps, trycks ned.
 */



ClickManager::ClickManager(vector<Tower*>& newTowervector, MapMatrix& newMapMatrix, Player& player)
:    mapMatrix(newMapMatrix), towerVector(newTowervector), markedTower(NULL), buyMenu(player), upgradeMenu(player)
{
    EventHandler::addListener(sf::Event::MouseButtonPressed, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonPressedUser*>(this)));
    EventHandler::addListener(sf::Event::MouseButtonReleased, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonReleasedUser*>(this)));
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
        for (it = towerVector.begin() ; it != towerVector.end(); ++it)
        {
            if(((*it)->getPosX() == (x/SIDE)*SIDE) && ((*it)->getPosY() == (y/SIDE)*SIDE))
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
        cout << "test" << endl;
        if(!mapMatrix.isTaken(x,y))
        {
            if(buyMenu.purchase())
            {
                markedTower->setPos((x/SIDE)*SIDE ,(y/SIDE)*SIDE);
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
            cout << "occupied" << endl;
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
    buyMenu.drawMenu(canvas);
    upgradeMenu.drawMenu(canvas);
    if(markedTower != NULL)
    {
		sf::Vector2i pos=sf::Mouse::getPosition(canvas);
		markedTower->setPos((pos.x/SIDE)*SIDE ,(pos.y/SIDE)*SIDE);
		if(!mapMatrix.isTaken(pos.x,pos.y))
		{
			markedTower->setColor(sf::Color(255, 255, 255, 200));
		}
		else
		{
			markedTower->setColor(sf::Color(255, 100, 100, 200));
		}
		markedTower->drawSprite(canvas);
    }
}
