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
	 * Sträng:
	 *"EnemyName1 antal waveNumber EnemyName2 ... "
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

void WaveHandler::startNextWave()
{
	//TODO
}
bool WaveHandler::isDone()
{
	return (waveNumber == (int) wavesVector.size());
}



void WaveHandler::createWaves(string newWavesString)
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


