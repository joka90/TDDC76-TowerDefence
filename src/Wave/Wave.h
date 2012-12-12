/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Wave.h
 * Enhetsnamn: Wave
 * Typ:        implementering
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten för saker som skall ha koordinater och skall ritas ut på spelplanen
 *
 */

#ifndef WAVE_H
#define WAVE_H
#include <string>
#include <vector>
#include <map>
#include "../GameObjects/Enemies/Enemy.h"
class Wave {
	public:

        // Constructs a wave with the enemies Ex. "GrayBadger 4"
		Wave(std::string waveString);

		~Wave();

        // Returns the enemy that should be placed to the track at the time given by timeDelta.
        //   timeDelta - the time (in ms) since the start of the wave.
		Enemy* getEnemy(int timeDelta);

		// Returnerar om vågen är färdig
		bool getFinished();

		// Sätter om vågen är färdig
		void setFinished();//needed if loading from savefile

	private:

        // Vektor med alla enemies
        std::vector<std::pair<int,std::string> > enemies;
        int nextIndex;
        bool finished;
};

#endif /* WAVE_H_ */
