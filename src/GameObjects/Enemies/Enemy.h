#ifndef  ENEMY_H
#define ENEMY_H
#include "../GameObject.h"
#include "../../ClickManager/MapMatrix.h"
#include <SFML/Graphics.hpp>

class Enemy : public GameObject
{
public:
    Enemy(int newX, int newY, int newLife, int newSpeed, int newValue, std::string textureReference, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader);

    ~Enemy();

    int getLife() const;
    void setLife(int newLife);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getValue() const;
    void setValue(int newValue);

    void hit(int damage);

    // Moves the enemy
    void update(MapMatrix& map);

private:

protected:
    int life;
    int speed;
    int value;
    int stepsMoved;

    SoundLoader& sounds;
};
#endif //end ENEMY_H
