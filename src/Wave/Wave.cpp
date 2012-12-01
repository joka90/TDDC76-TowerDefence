/*
 * Wave.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "Wave.h"
#include <string>
#include <sstream>
#include "../ClassManager.h"
using namespace std;

Wave::Wave(string waveString) : nextIndex(0) // str1 str2 str3 ..
{
    string w;
    stringstream ss;

    ss << waveString;
    while(ss >> w)
    {
        int timeDelta = atoi(w.c_str());
        enemies.push_back(pair<int,string>(timeDelta, w));
    }
}

Wave::~Wave() {
}

Enemy* Wave::getEnemy(int timeDelta)
{
    // If the next enemy shall be placed
    return NULL;
    cout << enemies.size() << endl;
    if(enemies[nextIndex].first <= timeDelta){
        nextIndex++;
        return ClassManager::createEnemyInstance(enemies[nextIndex-1].second);
    }
    return NULL;
}
