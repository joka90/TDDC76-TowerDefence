#ifndef  PROJECTILE_H
#define PROJECTILE_H

#include "../GameObject.h"
#include "../VisualEffects/VisualEffect.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>
#define RADIE 20
class Projectile : public GameObject
{
public:

    /**
     * Skapar en projektil. Kontstruktorn k�r ocks� setDirection(Enemy* enemy) vilket
     * har till f�ljd av Projektilen ricktas in p� den fiende tornet har sagt �t
     * projektilen att sikta p�.
     */
    Projectile(int newX, int newY, int newDamage, int newSpeed, int inLifetime, Enemy* newEnemy, std::string textureReference);
    ~Projectile();
    //virtual bool drawSprite(sf::RenderWindow& canvas);  // �rvs fr�n GameObject, beh�vs inte.. /T

    virtual bool update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects,Player& player);

    // Fr�gest�llning: Hur/vart kollas om en viss fiende �r tr�ffad av en viss projektil? Hur tas fienden & projektilen bort?
    //                 Ska en projektil kunna tr�ffa flera fiender? Hur hanteras det is�fall?


    int getDamage() const;
    void setDamage(int newDamage);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getDirX() const;
    int getDirY() const;
    void setDirection(int newDirX, int newDirY);

    /**
     * Riktar in projektilen i en linj�r bana mot Enemy* aim
     * nuvarande position. G�r detta genom trigformler nedan med fyra
     * fall beroende p� vilken kvadrant fienden bifinner sig i sett
     * fr�n projektilen.
     */
    void setDirection(Enemy* aim);
    void move();
    bool isHit(std::vector<Enemy*>& enemyVector, std::vector<VisualEffect*>& visualeffects,Player& player);


private:
protected:
    sf::Sound* onDeathSound;
    int damage;
    int speed;
    int dirX;
    int dirY;
    Enemy* enemy;
    int lifetime;

    /**
     * Denna kommer endast beh�vas om vi anv�nder m�ls�kande missiler
     * som riktar in sig p� en ny fiende om fienden den siktar p�
     * �r d�d.
     */
    void setClosestEnemy(std::vector<Enemy*>& enemyVector);

};
#endif //end PROJECTILE_H
