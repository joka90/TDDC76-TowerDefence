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
    Tower(int newX, int newY, int newPrice, int newDamage, int newRange,
           TextureLoader& inTextureLoader, SoundLoader& inSoundLoader
           , FontLoader& inFontLoader);
	Tower(std::string parms, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader);

    ~Tower();

    virtual Projectile* update(std::vector<Enemy*>) = 0;
    //virtual bool drawSprite(sf::RenderWindow& canvas); //Ärvs från GameObject ist.. /T

    int getPrice() const;
    void setPrice(int newPrice);
    int getDamage() const;
    void setDamage(int newDamage);
    int getRange() const;
    void setRange(int newRange);
    std::string getSaveString();

private:
    int price;
    int damage;
    int range;
    std::string towerType;

protected:

};
#endif //end TOWER_H
