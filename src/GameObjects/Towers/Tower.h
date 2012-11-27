#ifndef  TOWER_H
#define TOWER_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>
#include <stdio.h>

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


    virtual bool drawSprite(sf::RenderWindow& canvas);

    int getPrice() const;
    void setPrice(int newPrice);
    int getDamage() const;
    void setDamage(int newDamage);
    int getRange() const;
    void setRange(int newRange);

private:
    int price;
    int damage;
    int range;

protected:

};
#endif //end TOWER_H
