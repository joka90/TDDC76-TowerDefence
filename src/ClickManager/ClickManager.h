/*
 * ClickManager.h
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#ifndef CLICKMANAGER_H_
#define CLICKMANAGER_H_

#include "MapMatrix.h"

#include <string>
#include "../EventUser.h"
#include "../GameObjects/Towers/Tower.h"
#include <SFML/Graphics.hpp>
#include <vector>

class ClickManager : public MouseButtonPressedUser {
	public:
		ClickManager()=default;
		ClickManager(std::vector<Tower*>* newTowervector, MapMatrix* newMapMatrix);
		virtual ~ClickManager();
		void mouseButtonPressedListener(sf::Event event);
		void mouseButtonReleasedListener(sf::Event event);
		void update();

		/*
		vector<tower*>& towerVector;
		void update(MapMatrix& matrix, vector<tower*>& towerVector);
		void drawMenu(RenderWindow& canvas);
		BuyMenu buyMenu;
		UpgradeMeny upgradeMenu;
		 */
	private:
		//void updateMenu()
		std::vector<Tower*>* towerVector;
		Tower* markedTower;
		void createTower(int x, int y);
		MapMatrix* mapMatrix;


};

#endif /* CLICKMANAGER_H_ */
