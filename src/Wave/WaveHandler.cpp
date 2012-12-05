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

WaveHandler::WaveHandler(string wavesString) : isRunning(false), currentWaveIndex(0)
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
}

WaveHandler::~WaveHandler(){
}


/* Starts a new wave
 *
 */
void WaveHandler::startNextWave()
{
	clock.restart();
	isRunning = true;
}

/* Returns the Enemy that should be placed at this time
 */
Enemy* WaveHandler::update(){
    if(isRunning)
    {
        cout << wavesVector.size() << endl;
        cout << "aaa" << endl;
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

