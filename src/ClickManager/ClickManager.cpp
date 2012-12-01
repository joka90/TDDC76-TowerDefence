/*
 * ClickManager.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "ClickManager.h"
#include "../GameObjects/Towers/Tower.h"
#include "../GameObjects/Towers/LongTower.h"
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



ClickManager::ClickManager(vector<Tower*>& newTowervector, MapMatrix& newMapMatrix)
:    mapMatrix(newMapMatrix), towerVector(newTowervector), buyMenu(), markedTower(NULL)
{
}

ClickManager::~ClickManager()
{
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
        if(not mapMatrix.isTaken(x,y))
        {
            //L�gga s�tt towerX och towerY till x,y och l�gg till det i towerVector
        }
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
}
void ClickManager::createTower(int x, int y)
{

	if(! mapMatrix.isTaken(x,y))
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
}
