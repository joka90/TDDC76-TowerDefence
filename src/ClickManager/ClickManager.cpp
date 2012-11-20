/*
 * ClickManager.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "ClickManager.h"
#include "MapMatrix.h"
#include <string>

using namespace std;
/*
 * Fler saker ska in in konstruktorn s� fort den koden �r klar!
 */
ClickManager::ClickManager(string value, int row, int col)
{
	mapMatrix.setMatrix(value,row,col);
}

ClickManager::~ClickManager()
{
}

void ClickManager::createTower(int x, int y)
{

	if(! mapMatrix.isTaken(x,y))
	{
			mapMatrix.setTower(x,y);
			//TODO Skapa torn, l�gga det i vectorn, placera ut det p� kartan
	}
	else
	{
		//Ge n�tt visuellt att det inte g�r att placera tornet p� given plats?
	}
}


