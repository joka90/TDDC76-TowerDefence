#ifndef  PROJECTILE_H
#define PROJECTILE_H

#include "../GameObject.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>

class Projectile : public GameObject
{
public:
    Projectile(int newX, int newY, int newDamage, int newSpeed, Enemy* newEnemy, std::string textureReference, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader);

    //virtual bool drawSprite(sf::RenderWindow& canvas);  // �rvs fr�n GameObject, beh�vs inte.. /T

    virtual void update(std::vector<Enemy*>& enemies) = 0;

    // Fr�gest�llning: Hur/vart kollas om en viss fiende �r tr�ffad av en viss projektil? Hur tas fienden & projektilen bort?
    //                 Ska en projektil kunna tr�ffa flera fiender? Hur hanteras det is�fall?


    int getDamage() const;
    void setDamage(int newDamage);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getDirX() const;
    int getDirY() const;
    void setDirection(int newDirX, int newDirY);
    void move();

    //void hit() //Beh�vs denna? B�r detta sk�tas av den som ist�llet tar bort fienden&projektilen?


private:

protected:
    int damage;
    int speed;
    int dirX;
    int dirY;
    Enemy* enemy;
    SoundLoader& sounds;

};
#endif //end PROJECTILE_H
