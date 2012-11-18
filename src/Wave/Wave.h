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
		Wave(int timeDelay, std::string enemyName);
		virtual ~Wave();

		//enemy* update(int xSpawn, int ySpawn)
	private:
		std::map<int,std::string> enemyMap;
};

#endif /* WAVE_H_ */
