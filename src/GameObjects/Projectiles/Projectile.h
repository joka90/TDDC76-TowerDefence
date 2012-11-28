#ifndef  PROJECTILE_H
#define PROJECTILE_H
#include "../GameObject.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>

class Projectile : public GameObject
{
public:
    Projectile(int newX, int newY, int newDamage, int newSpeed, Enemy* newEnemy, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader);

    //virtual bool drawSprite(sf::RenderWindow& canvas);  // Ärvs från GameObject, behövs inte.. /T

    virtual void update(std::vector<Enemy*>& enemies) = 0;

    // Frågeställning: Hur/vart kollas om en viss fiende är träffad av en viss projektil? Hur tas fienden & projektilen bort?
    //                 Ska en projektil kunna träffa flera fiender? Hur hanteras det isåfall?


    int getDamage() const;
    void setDamage(int newDamage);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getDirX() const;
    int getDirY() const;
    void setDirection(int newDirX, int newDirY);
    void move();
    //bool closeEnough() const;
    //void hit() //Behövs denna? Bör detta skötas av den som istället tar bort fienden&projektilen?


private:

protected:
    int damage;
    int speed;
    int dirX;
    int dirY;
    Enemy* enemy;

};
#endif //end PROJECTILE_H
