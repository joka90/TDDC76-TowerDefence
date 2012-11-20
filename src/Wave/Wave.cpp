/*
 * Wave.cpp
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#include "Wave.h"
#include <string>
using namespace std;

Wave::Wave()
{

}

Wave::~Wave() {
}

string Wave::getName()
{
	return enemyMap.find(1)->second;
}
void Wave::insertEnemy(int timeDelay, string enemyName)
{
	enemyMap.insert(pair<int,string>(timeDelay,enemyName));
}
/*
enemy* Wave::update(int xSpawn, int ySpawn, int time)
{
	Kolla time = timeDelay för Skapa fiende
	time++
	return fiende
}
*/
