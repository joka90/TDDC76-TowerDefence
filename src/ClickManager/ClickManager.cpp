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
 * Fler saker ska in in konstruktorn så fort den koden är klar!
 */
/*
Musens rörs, släpps, trycks ned.


*/


ClickManager::ClickManager(vector<Tower*>& newTowervector, MapMatrix& newMapMatrix, TextureLoader& textures, SoundLoader& sounds, FontLoader& fonts)
:    mapMatrix(newMapMatrix), towerVector(newTowervector), buyMenu(textures, sounds, fonts)
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
    for (it = towerVector.begin() ; it != towerVector.end(); ++it)
    {
        //Gå igenom tornvektor för träffar på dessa koordinater
        //Sätt träffen till markedTower
    }



}
void ClickManager::mouseButtonReleasedListener(sf::Event event)
{

    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    if(markedTower != NULL)
    {
        if(not mapMatrix.isTaken(x,y))
        {
            //
        }
    }
    //Kolla om torn ska placeras ut


}
void ClickManager::update()
{
    /*
    string ETTBRANAMN;
    if(buyMenu.update())
    {
        ETTBRANAMN = buyMenu.readState();
        markedTower = Skapa ett torn
    }
    //Kör update på menyer
    //Om TRUE, kör readState
    */
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

void ClickManager::drawMenus(sf::RenderWindow& canvas)
{
    buyMenu.drawMenu(canvas);
}
