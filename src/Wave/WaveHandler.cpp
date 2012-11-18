/*
 * WaveHandler.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "WaveHandler.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

WaveHandler::WaveHandler(int newSpawnX, int newSpawnY, string newWavesString)
{
	//Hur ska WaveHandler initieras?
	/*
	 * Förslag:
	 * Matris:
	 *(EnemyName1 antal waveNumber
	 * EnemyName2 	-
	 * EnemyName1 	-
	 * NULL			-)
	 * -> Först skapas antal EN1 med 1 timedelay mellan varje i våg nr waveNumber
	 * -> sen antal EN2 med 1 timedelay mellan varje osv.
	 * -> NULL för att få lite hopp i tiden
	 *
	 */

	spawnX = newSpawnX;
	spawnY = newSpawnY;
	time = 0;
	waveNumber = 0;
	createWaves(newWavesString);

}

WaveHandler::~WaveHandler() {
}

void WaveHandler::createWaves( string newWavesString)
{
	string enemyName;
	int number, waveNumber(0), timeDelay(0), oldWaveNumber(0);
	stringstream ss(newWavesString);
	while(ss.good())
	{
		ss >> enemyName;
		ss >> number;
		ss >> waveNumber;
		if(oldWaveNumber != waveNumber)
		{
			timeDelay = 0;
		}
		oldWaveNumber = waveNumber;
		wavesVector.resize(waveNumber + 1);
		for(int i = 0; i < number; i++)
		{
			wavesVector[waveNumber].insertEnemy(timeDelay+i, enemyName);
		}
		timeDelay = timeDelay + number;
	}

}


