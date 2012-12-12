/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    WaveHandler.h
 * Enhetsnamn: WaveHandler
 * Typ:        implementering
 * Skriven av: T. Norlund
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten för saker som skall ha koordinater och skall ritas ut på spelplanen
 *
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
