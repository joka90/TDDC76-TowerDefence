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

class ClickManager {
	public:
		ClickManager()=default;
		ClickManager(std::string value, int row, int col);
		virtual ~ClickManager();
		/*
		void update(MapMatrix& matrix, vector<tower*>& towerVector);
		void drawMenu(RenderWindow& canvas);
		BuyMenu buyMeny;
		UpgradeMeny upgradeMenu;
		Tower* towerBuffer;
		string towerPlaceName;
		 */
	private:
		//void updateMenu()
		void createTower(int x, int y);
		MapMatrix mapMatrix;

};

#endif /* CLICKMANAGER_H_ */
