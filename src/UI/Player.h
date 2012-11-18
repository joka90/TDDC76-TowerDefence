/*
 * Player.h
 *
 *  Created on: 18 nov 2012
 *      Author: Calle
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
	public:
		Player(int life, int money);
		virtual ~Player();

		bool canAfford(int cost);
		void subractMoney(int cost);
		void addMoney(int cost);
		int getMoney();
		int getLife();
		void eraseLife();
		bool isDead();

	private:
		int money,life;
};

#endif /* PLAYER_H_ */
