/*
 * Wave.h
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */
//Include enemy.h
#ifndef WAVE_H
#define WAVE_H
#include <string>
#include <vector>
#include <map>
#include "../GameObjects/Enemies/Enemy.h"
class Wave {
	public:

        // Constructs a wave with the enemies and their insertion times (offset from wave start) described as:
        //  "EnemyName 0 EnemyName 100"
        // Remark: Only ONE enemy can be placed at a certain time
		Wave(std::string waveString);

		~Wave();

        // Returns the enemy that should be placed to the track at the time given by timeDelta.
        //   timeDelta - the time (in ms) since the start of the wave.
		Enemy* getEnemy(int timeDelta);
		bool getFinished();

	private:
        std::vector<std::pair<int,std::string> > enemies;
        int nextIndex;
        bool finished;
};

#endif /* WAVE_H_ */
