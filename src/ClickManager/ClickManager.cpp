/*
 * ClickManager.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "ClickManager.h"
#include "../GameObjects/Towers/Tower.h"
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
Musens r�rs, sl�pps, trycks ned.


*/


ClickManager::ClickManager(int row, int col, vector<Tower*>* newTowervector, MapMatrix* newMapMatrix)
{
    towerVector = newTowervector;
    mapMatrix = newMapMatrix;
}

ClickManager::~ClickManager()
{
}
void ClickManager::mouseButtonPressedListener(sf::Event event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    vector<Tower*>::iterator it;
    for (it = towerVector->begin() ; it != towerVector->end(); ++it)
    {
        //G� igenom tornvektor f�r tr�ffar p� dessa koordinater
        //S�tt tr�ffen till markedTower
    }



}
void ClickManager::mouseButtonReleasedListener(sf::Event event)
{

    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    if(markedTower != NULL)
    {        if(not mapMatrix->isTaken(x,y))
        {
            //
        }
    }
    //Kolla om torn ska placeras ut


}
void ClickManager::update()
{
    vector<Tower*>::iterator it;
    for (it = towerVector->begin() ; it != towerVector->end(); ++it)
    {
        it->update();
    }
    /*
    string ETTBRANAMN;
    if(buyMenu.update())
    {
        ETTBRANAMN = buyMenu.readState();
        g�r ett torn av ETTBRANAMN;
        markedTower = createTower;
    }
    //K�r update p� menyer
    //Om TRUE, k�r readState
    */
}
void ClickManager::createTower(int x, int y)
{

	if(! mapMatrix->isTaken(x,y))
	{
			mapMatrix->setTower(x,y);
			//TODO Skapa torn, l�gga det i vectorn, placera ut det p� kartan
	}
	else
	{
		//Ge n�tt visuellt att det inte g�r att placera tornet p� given plats?
	}
}

