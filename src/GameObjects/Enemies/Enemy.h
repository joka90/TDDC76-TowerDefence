#ifndef  ENEMY_H
#define ENEMY_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class Enemy : public GameObject
{
public:
    Enemy(int newX, int newY, int newLife, int newSpeed, int newValue, int newDirX, int newDirY, std::string textureReference, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader);

    ~Enemy();

    //virtual bool drawSprite(sf::RenderWindow& canvas); Ärvs från GameObject, behövs ej.. /T

    // - Enligt hur jag har föreslagit hur path-findingen ska fungera i MapMatrix.h så behövs ej dirX och dirY.
    // - Det är oklart vad som är skillnaden på update() och move(), jag föreslår att move tas bort och att all
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
