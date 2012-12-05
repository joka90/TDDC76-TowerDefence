/*
 * Wave.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "Wave.h"
#include <string>
#include <vector>
#include <sstream>
#include "../ClassManager.h"
using namespace std;

Wave::Wave(string waveString) : nextIndex(0), finished(false) // str1 str2 str3 ..
{
    cout << waveString << endl;
    string w;
    int timeDelta;
    stringstream ss;

    ss << waveString;
    while(ss >> w)
    {
        ss >> timeDelta;
        enemies.push_back(make_pair(timeDelta, w));
    }
}

Wave::~Wave() {
}

Enemy* Wave::getEnemy(int timeDelta)
{
    // If the next enemy shall be placed
    if(enemies.size() <= nextIndex)
    {
        finished = true;
        return NULL;
    }
    if(enemies[nextIndex].first <= timeDelta){
        nextIndex++;
        return ClassManager::createEnemyInstance(enemies[nextIndex-1].second);
    }
    return NULL;
}

bool Wave::getFinished()
    {
        return finished;
    }
