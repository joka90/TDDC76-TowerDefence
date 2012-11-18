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
 * Fler saker ska in in konstruktorn så fort den koden är klar!
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
			//TODO Skapa torn, lägga det i vectorn, placera ut det på kartan
	}
	else
	{
		//Ge nått visuellt att det inte går att placera tornet på given plats?
	}
}


