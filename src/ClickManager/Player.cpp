/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    MapMatrix.cpp
 * Enhetsnamn: MapMatrix
 * Typ:        implementering
 * Skriven av: C. Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar representationen av en spelare
 *
 */

#include "Player.h"
using namespace std;

Player::Player(int newMoney,int newLife) {
	life = newLife;
	money = newMoney;
}

Player::Player() { }

Player::~Player() {
}
bool Player::canAfford(int cost)
{
	return (cost <= money);
}
void Player::subractMoney(int cost)
{
	money = money - cost;
}
void Player::addMoney(int cost)
{
	money = money + cost;
}
int Player::getMoney()
{
	return money;
}
int Player::getLife()
{
	return life;
}
void Player::eraseLife()
{
	life = life - 1;
}

bool Player::isDead()
{
	return (life == 0);
}

