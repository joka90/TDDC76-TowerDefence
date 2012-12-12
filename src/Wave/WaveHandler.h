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
        // Konstruktor, tar in sträng med vågor, vågorna är radseparerade
		WaveHandler(std::string wavesString);
		// Konstruktor, tar in sträng med vågor, vågorna är radseparerade, med startIndex
        WaveHandler(std::string wavesString, int startIndex);
		virtual ~WaveHandler();

        // Starts the next wave
        void startNextWave();

        // If a new enemy should be placed, it is returned
		Enemy* update();

        // Returnerar aktuellt vågindex
		int getCurrentWaveIndex();


        bool getIsRunning();
        bool waveDone();
        bool onLastWave();

	private:
		void printMatrix();

		int currentWaveIndex;
		bool isRunning;
		sf::Clock clock;
		std::vector<Wave*> wavesVector; //Innehåller Waves

};

#endif /* WAVEHANDLER_H_ */
