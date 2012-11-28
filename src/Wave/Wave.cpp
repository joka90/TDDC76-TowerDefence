/*
 * Wave.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "Wave.h"
#include <string>
#include <sstream>
using namespace std;

Wave::Wave(string waveString) // str1 str2 str3 ..
{
    string w;
    stringstream ss;

    ss << waveString;
    while(ss >> w)
    {
        int timeDelta = atoi(w.c_str());
        //w?
    }
}

Wave::~Wave() {
}

/*
enemy* Wave::update(int xSpawn, int ySpawn, int time)
{
	Kolla time = timeDelay för Skapa fiende
	time++
	return fiende
}
*/
