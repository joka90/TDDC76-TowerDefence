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
 * Fler saker ska in in konstruktorn s� fort den koden �r klar!
 */
/*
 * Musens r�rs, sl�pps, trycks ned.
 */



ClickManager::ClickManager(vector<Tower*>& newTowervector, MapMatrix& newMapMatrix, Player& player)
:    mapMatrix(newMapMatrix), towerVector(newTowervector), markedTower(NULL), buyMenu(player)
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
    /*
    for (it = towerVector.begin ; it != towerVector.end(); ++it)
    {
        //G� igenom tornvektor f�r tr�ffar p� dessa koordinater
        //S�tt tr�ffen till markedTower
    }
    */
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
		//Ge n�tt visuellt att det inte g�r att placera tornet p� given plats?
	}
}

void ClickManager::drawMenus(sf::RenderWindow& canvas)
{
    buyMenu.drawMenu(canvas);
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
