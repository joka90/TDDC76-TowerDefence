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

WaveHandler::WaveHandler(string wavesString)
{
    string w, waveString;
    stringstream ss;

    ss << wavesString;

    while(std::getline(ss, waveString)){
        wavesVector.push_back(Wave(waveString));
    }
}

WaveHandler::~WaveHandler(){
}

WaveHandler::WaveHandler(string wavesString, int startIndex)
{
    string w, waveString;
    stringstream ss;

    ss << wavesString;

    while(std::getline(ss, waveString)){
        wavesVector.push_back(Wave(waveString));
    }

    currentWaveIndex = startIndex +1;
}

void WaveHandler::startNextWave()
{
	//TODO
}


bool WaveHandler::isDone()
{
	return (currentWaveIndex == (int) wavesVector.size());
}

void WaveHandler::createWaves(string newWavesString)
{


}

int WaveHandler::getCurrentWaveIndex(){
    return currentWaveIndex;
}

