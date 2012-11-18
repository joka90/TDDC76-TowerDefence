/*
 * WaveHandler.h
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#ifndef WAVEHANDLER_H
#define WAVEHANDLER_H
#include "Wave.h"
#include <vector>
class WaveHandler {
	public:
		WaveHandler(int spawnX, int spawnY);
		virtual ~WaveHandler();
	private:
		void createWaves();

		int waveNumber;
		std::vector<Wave> wavesVector;
		int spawnX;
		int spawnY;
		int time;


};

#endif /* WAVEHANDLER_H_ */
