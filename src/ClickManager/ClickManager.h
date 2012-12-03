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
#include "../GameObjects/Menu/BuyMenu.h"
#include "../GameObjects/Menu/UpgradeMenu.h"
#include <SFML/Graphics.hpp>
#include <vector>

class ClickManager : public MouseButtonPressedUser, public MouseButtonReleasedUser {
	public:
		ClickManager()=delete;
		ClickManager(std::vector<Tower*>& newTowervector, MapMatrix& newMapMatrixTextureLoader, Player& player);
		virtual ~ClickManager();
		void mouseButtonPressedListener(sf::Event event);
		void mouseButtonReleasedListener(sf::Event event);
		void update();
        void drawMenus(sf::RenderWindow& canvas);
		/*
		vector<tower*>& towerVector;
		void update(MapMatrix& matrix, vector<tower*>& towerVector);
		void drawMenu(RenderWindow& canvas);
		UpgradeMeny upgradeMenu;
		 */
	private:
		//void updateMenu()
		void createTower(int x, int y);

		MapMatrix& mapMatrix;
		std::vector<Tower*>& towerVector;
		Tower* markedTower;

		BuyMenu buyMenu;
        UpgradeMenu upgradeMenu;

};

#endif /* CLICKMANAGER_H_ */
