#ifndef  TOWER_H
#define TOWER_H
#include "../GameObject.h"
#include "../Enemies/Enemy.h"
#include "../Projectiles/Projectile.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>

/**
 * @author Mikael Karlsson
 * Date    2012-11-21
 */
class Tower : public GameObject
{
public:
    Tower(int newX, int newY, int newPrice, int newDamage, int newRange, int newCounterMax,  std::string textureReference);

	Tower(std::string parms,  std::string textureReference);

    ~Tower();

    //virtual Projectile* update(std::vector<Enemy*>) = 0;//fix to compile TODO
    bool drawSprite(sf::RenderWindow& canvas);
	double directionAngle;//sprite angle

    int getPrice() const;
    void setPrice(int newPrice);
    int getDamage() const;
    void setDamage(int newDamage);
    int getRange() const;
    void setRange(int newRange);
    std::string getSaveString();

    Projectile* update(std::vector<Enemy*>& enemyVector);

private:


protected:
    int price;
    int damage;
    int range;
    int counter;
    int counterMax; //Om counter > counterMax, SKJUT(dvs skapa Projectile*)
    Enemy* getClosestEnemy(std::vector<Enemy*>& enemyVector);
    std::string towerType;

};
#endif //end TOWER_H
