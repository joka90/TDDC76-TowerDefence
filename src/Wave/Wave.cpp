/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Wave.cpp
 * Enhetsnamn: Wave
 * Typ:        implementering
 * Skriven av: C. Schmidt & T. Norlund
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar representationen av en fiendevåg i spelet
 *
 */

#include "Wave.h"
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "../ClassManager.h"
using namespace std;

Wave::Wave(string waveString) : nextIndex(0), finished(false) // str1 str2 str3 ..
{
    string w;
    int timeDelta, number;
    stringstream ss;

    ss << waveString;
    while(ss >> w)
    {
        timeDelta = 0;
        ss >> number;
        //Gör så att djur på samma tid kommer förskjutas 400ms vilket gör att
        // de inte hamnar på varandra
        for(vector<std::pair<int,std::string> >::iterator it = enemies.begin(); it != enemies.end(); ++it)
        {

            if((*it).second == "Badger")
            {
                timeDelta = timeDelta + 800;
            }
            else if((*it).second == "RedBadger")
            {
                timeDelta = timeDelta + 800;
            }
            else if((*it).second == "BlueBadger")
            {
                timeDelta = timeDelta + 400;
            }
            else if((*it).second == "GreenBadger")
            {
                timeDelta = timeDelta + 800;
            }

        }
        for(int i = 0; i < number; i++)
        {
            enemies.push_back(make_pair(timeDelta, w));

            if(w == "Badger")
            {
                timeDelta = timeDelta + 800;
            }
            else if(w == "RedBadger")
            {
                timeDelta = timeDelta + 800;
            }
            else if(w == "BlueBadger")
            {
                timeDelta = timeDelta + 400;
            }
            else if(w == "GreenBadger")
            {
                timeDelta = timeDelta + 800;
            }

        }

    }
}

Wave::~Wave()
{
}

Enemy* Wave::getEnemy(int timeDelta)
{
    // If the next enemy shall be placed
    if(enemies.size() <= nextIndex)
    {
        finished = true;
        return NULL;
    }
    if(enemies[nextIndex].first <= timeDelta)
    {
        nextIndex++;
        return ClassManager::createEnemyInstance(enemies[nextIndex-1].second);
    }
    return NULL;
}

bool Wave::getFinished()
{
    return finished;
}

void Wave::setFinished()//needed if loading from savefile
{
    finished=true;
}
