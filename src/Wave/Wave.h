/*
 * Wave.h
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */
//Include enemy.h
#ifndef WAVE_H
#define WAVE_H
#include <string>
#include <map>
class Wave {
	public:
		Wave();
		virtual ~Wave();

		//enemy* update(int xSpawn, int ySpawn)
		std::string getName();
		void insertEnemy(int timeDelay, std::string enemyName);

		std::map<int,std::string> enemyMap;

	private:
};

#endif /* WAVE_H_ */
