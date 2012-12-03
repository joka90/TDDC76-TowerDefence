#ifndef  ENEMY_H
#define ENEMY_H
#include "../GameObject.h"
#include "../../ClickManager/MapMatrix.h"
#include <SFML/Graphics.hpp>

class Enemy : public GameObject
{
public:

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
    Enemy(int newLife, int newSpeed, int newValue, std::string textureReference);

    int life;
    int speed; // Ex: speed = 10: flyttar 1 pixel var 10:e frame
    int value;
    int stepsMoved;
    int frames; // Antalet frames sedan enemyn påbörjat animering från senaste ruta

    std::pair<int, int> nextCoord;
};
#endif //end ENEMY_H
