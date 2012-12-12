/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Player.h
 * Enhetsnamn: Player
 * Typ:        header
 * Skriven av: C. Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar representationen av en spelare
 *
 */

#ifndef PLAYER_H_
#define PLAYER_H_

class Player {
	public:
        Player();
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
