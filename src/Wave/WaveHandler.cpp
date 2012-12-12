/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    WaveHandler.cpp
 * Enhetsnamn: WaveHandler
 * Typ:        implementering
 * Skriven av: T. Norlund
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar representationen av alla fiendev�gor f�r en bana
 *
 */

#include "WaveHandler.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

WaveHandler::WaveHandler(string wavesString) : isRunning(false), currentWaveIndex(-1)
{
    string w, waveString;
    stringstream ss;

    ss << wavesString;

    while(std::getline(ss, waveString)){
        wavesVector.push_back(new Wave(waveString));
    }
}

WaveHandler::WaveHandler(string wavesString, int startIndex) : isRunning(false)
{
    string w, waveString;
    stringstream ss;

    ss << wavesString;

    while(std::getline(ss, waveString)){
        wavesVector.push_back(new Wave(waveString));
    }
    currentWaveIndex = startIndex;
	if(currentWaveIndex != -1)
	{
		wavesVector[currentWaveIndex]->setFinished();
	}
}

WaveHandler::~WaveHandler(){
}


/* Starts a new wave
 *
 */
void WaveHandler::startNextWave()
{
    if(currentWaveIndex < (int) wavesVector.size()-1)
    {
        if(currentWaveIndex == -1)
        {
            clock.restart();
            isRunning = true;
            ++currentWaveIndex;
        }
        if(wavesVector[currentWaveIndex]->getFinished())
        {
            clock.restart();
            isRunning = true;
            ++currentWaveIndex;
        }
    }
    return;
}

/* Returns the Enemy that should be placed at this time
 */
Enemy* WaveHandler::update(){
    if(isRunning)
    {
        if(wavesVector[currentWaveIndex]->getFinished())
        {
            isRunning = false;
        }
        return wavesVector[currentWaveIndex]->getEnemy(clock.getElapsedTime().asMilliseconds());
    }
    return NULL;
}

int WaveHandler::getCurrentWaveIndex(){
    return currentWaveIndex;
}

bool WaveHandler::getIsRunning(){
    return isRunning;
}

bool WaveHandler::waveDone(){
    if(currentWaveIndex == -1)
    {
        return false;
    }
    return wavesVector[currentWaveIndex]->getFinished();
}

bool WaveHandler::onLastWave(){
    return currentWaveIndex == (int) wavesVector.size()-1;
}
