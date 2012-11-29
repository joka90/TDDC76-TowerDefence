#ifndef  ENEMY_H
#define ENEMY_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class Enemy : public GameObject
{
public:
    Enemy(int newX, int newY, int newLife, int newSpeed, int newValue, int newDirX, int newDirY, std::string textureReference, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader);

    ~Enemy();

    //virtual bool drawSprite(sf::RenderWindow& canvas); �rvs fr�n GameObject, beh�vs ej.. /T

    // - Enligt hur jag har f�reslagit hur path-findingen ska fungera i MapMatrix.h s� beh�vs ej dirX och dirY.
    // - Det �r oklart vad som �r skillnaden p� update() och move(), jag f�resl�r att move tas bort och att all
    // flyttning sker i update.

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

protected:
    int life;
    int speed;
    int value;
    int dirX;
    int dirY;
    SoundLoader& sounds;


};
#endif //end ENEMY_H
