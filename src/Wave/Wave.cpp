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

Wave::Wave(string waveString) : nextIndex(0) // str1 str2 str3 ..
{
    string w;
    string t;
    stringstream ss;

    ss << waveString;
    while(ss >> w)
    {
        ss >> t;
        int timeDelta = atoi(t.c_str());
        enemies.push_back(make_pair(timeDelta, w));
        cout << "Enemy: " << w << " time: " << t << " enemies.size(): " << enemies.size() << endl;
    }
}

Wave::~Wave() {
}

Enemy* Wave::getEnemy(int timeDelta)
{
    // If the next enemy shall be placed
    cout << "Size: " << enemies.size() << " nextIndex: " << nextIndex << " timeDelta: " << timeDelta << endl;
    if(enemies[nextIndex].first <= timeDelta){
        nextIndex++;
        return ClassManager::createEnemyInstance(enemies[nextIndex-1].second);
    }
    return NULL;
}
