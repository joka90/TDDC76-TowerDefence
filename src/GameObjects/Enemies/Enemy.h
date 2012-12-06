#ifndef  ENEMY_H
#define ENEMY_H
#include "../GameObject.h"
#include "../../ClickManager/MapMatrix.h"
#include "../../ClickManager/Player.h"
#include <SFML/Graphics.hpp>
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

class Enemy : public GameObject
{
public:
    Enemy(int newLife, int newSpeed, int newValue, std::string textureReference);
    ~Enemy();
    Enemy(int newLife, int newSpeed, int newValue, std::string textureReference, unsigned int inSpriteWidth, unsigned int inSpriteHeight,
     unsigned int inNuberOfSprites = 0, unsigned int inFpf = 1);

    int getLife() const;
    void setLife(int newLife);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getValue() const;
    void setValue(int newValue);
    void hit(int damage);
    bool isDead();
    int getSteps();

    // Moves the enemy
    bool update(MapMatrix& map);
    virtual void onDeath();

private:

protected:
    void newDirection(MapMatrix& map);
    bool passedNextStep();

    int life;
    int speed;
    int value;
    int stepsMoved;
    int direction;
    int frames; // Antalet frames sedan enemyn påbörjat animering från senaste ruta

    std::pair<int, int> nextCoord;
};
#endif //end ENEMY_H
