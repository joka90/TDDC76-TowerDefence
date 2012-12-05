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
    cout << waveString << endl;
    string w;
    int timeDelta;
    stringstream ss;

    ss << waveString;
    while(ss >> w)
    {
        ss >> timeDelta;
        enemies.push_back(make_pair(timeDelta, w));
        cout << "Enemy: " << w << " time: " << timeDelta << " enemies.size(): " << enemies.size() << endl;
    }
}

Wave::~Wave() {
}

Enemy* Wave::getEnemy(int timeDelta)
{
    // If the next enemy shall be placed
    cout << "Size: " << enemies.size() << " nextIndex: " << enemies[nextIndex].first << " timeDelta: " << timeDelta << endl;
    if(enemies[nextIndex].first <= timeDelta){
        cout << "hej"  <<endl;
        nextIndex++;
        return ClassManager::createEnemyInstance(enemies[nextIndex-1].second);
    }
    return NULL;
}
