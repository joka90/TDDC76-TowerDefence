#ifndef  ENEMY_H
#define ENEMY_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class Enemy : public GameObject
{
public:
    Enemy(int newX, int newY, int newLife, int newSpeed, int newValue,
          int newDirX, int newDirY, class TextureLoader* inTextureLoader,
          class SoundLoader* inSoundLoader, class FontLoader* inFontLoader);

    ~Enemy();

    virtual bool drawSprite(sf::RenderWindow& canvas);

    int getLife() const;
    void setLife(int newLife);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getValue() const;
    void setValue(int newValue);
    int getDirX() const;
    void setDirX(int newDirX);
    int getDirY() const;
    void setDirY(int newDirY);

    void hit(int damage);

    void move();


private:
    int life;
    int speed;
    int value;
    int dirX;
    int dirY;
protected:

};
#endif //end ENEMY_H
