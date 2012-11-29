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

        // Starts the next wave
        void startNextWave();

        // If a new enemy should be placed, it is returned
		Enemy* update();

		int getCurrentWaveIndex();
        bool getIsRunning();

	private:
		void printMatrix();

		int currentWaveIndex;
		bool isRunning;
		sf::Clock clock;
		std::vector<Wave> wavesVector; //Innehåller Waves

};

#endif /* WAVEHANDLER_H_ */
