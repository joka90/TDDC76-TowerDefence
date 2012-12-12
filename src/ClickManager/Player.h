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
        /**
          * Konstruktor
          */
		Player(int life, int money);
		virtual ~Player();
		/**
          * Har spelare råd med tornet de försöker köpa?
          */
		bool canAfford(int cost);
		/**
          * Ta bort pengar, spelaren har köpt nått
          */
		void subractMoney(int cost);
		/**
          * Öka saldot
          */
		void addMoney(int cost);
		int getMoney();
		int getLife();
		/**
          * Ta bort ett liv
          */
		void eraseLife();
		/**
          * Är liv = 0?
          */
		bool isDead();

	private:
		int money,life;
};

#endif /* PLAYER_H_ */
