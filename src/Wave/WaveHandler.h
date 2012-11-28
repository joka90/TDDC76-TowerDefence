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
#include <string>

class WaveHandler {
	public:
		WaveHandler(std::string wavesString);
        WaveHandler(std::string wavesString, int startIndex);
		virtual ~WaveHandler();

		void startNextWave();
		int getCurrentWaveIndex();

		Enemy* update(int time);

		bool isDone();

	private:
		/*
		 * Tar en sträng på formen "enemyName number" waveNumber osv på samma sätt
		 * och skapar Waves som läggs i wavesVectorn
		 */
		void createWaves(std::string newWavesString);
		void printMatrix();

		int currentWaveIndex;
		int time;
		std::vector<Wave> wavesVector; //Innehåller Waves

};

#endif /* WAVEHANDLER_H_ */
