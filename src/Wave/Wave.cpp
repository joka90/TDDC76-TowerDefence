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

Wave::Wave(string waveString) // str1 str2 str3 ..
{
    string w;
    stringstream ss;

    ss << waveString;
    while(ss >> w)
    {
        int timeDelta = atoi(w.c_str());
        enemyMap.insert(pair<int,string>(timeDelta, w));
    }
}

Wave::~Wave() {
}

Enemy* Wave::getEnemy(int timeDelta){
    return ClassManager::createEnemyInstance(enemyMap[timeDelta]);
}
