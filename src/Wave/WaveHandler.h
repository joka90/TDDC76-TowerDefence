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
using namespace std;
class WaveHandler {
	public:
		WaveHandler(int spawnX, int spawnY,string newWavesString);
		virtual ~WaveHandler();

		void startNextWave();
		//enemy* update(int xSpawn, int ySpawn, int time)
		bool isDone();
	private:
		/*
		 * Tar en str�ng p� formen "enemyName number" waveNumber osv p� samma s�tt
		 * och skapar Waves som l�ggs i wavesVectorn
		 */
		void createWaves(string newWavesString);
		void printMatrix();
		int waveNumber;
		vector<Wave> currentWavesVector;
		vector<Wave> wavesVector; //Inneh�ller Waves
		int spawnX;
		int spawnY;
		int time;


};

#endif /* WAVEHANDLER_H_ */
