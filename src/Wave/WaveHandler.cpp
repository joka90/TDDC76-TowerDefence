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


}


