/*
 * WaveHandler.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "WaveHandler.h"

WaveHandler::WaveHandler(int newSpawnX, int newSpawnY)
{
	spawnX = newSpawnX;
	spawnY = newSpawnY;
	time = 0;
	waveNumber = 0;
	createWaves();
}

WaveHandler::~WaveHandler() {
}

void WaveHandler::createWaves()
{

}

