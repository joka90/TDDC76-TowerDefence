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
     * Skapar en projektil. Kontstruktorn kör också setDirection(Enemy* enemy) vilket
     * har till följd av Projektilen ricktas in på den fiende tornet har sagt åt
     * projektilen att sikta på.
     */
    Projectile(int newX, int newY, int newDamage, int newSpeed, int inLifetime, Enemy* newEnemy, std::string textureReference);
    ~Projectile();
    //virtual bool drawSprite(sf::RenderWindow& canvas);  // Ärvs från GameObject, behövs inte.. /T

    virtual bool update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects,Player& player);

    // Frågeställning: Hur/vart kollas om en viss fiende är träffad av en viss projektil? Hur tas fienden & projektilen bort?
    //                 Ska en projektil kunna träffa flera fiender? Hur hanteras det isåfall?


    int getDamage() const;
    void setDamage(int newDamage);
    int getSpeed() const;
    void setSpeed(int newSpeed);
    int getDirX() const;
    int getDirY() const;
    void setDirection(int newDirX, int newDirY);

    /**
     * Riktar in projektilen i en linjör bana mot Enemy* aim
     * nuvarande position. Gör detta genom trigformler nedan med fyra
     * fall beroende på vilken kvadrant fienden bifinner sig i sett
     * från projektilen.
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
     * Denna kommer endast behövas om vi använder målsökande missiler
     * som riktar in sig på en ny fiende om fienden den siktar på
     * är död.
     */
    void setClosestEnemy(std::vector<Enemy*>& enemyVector);

};
#endif //end PROJECTILE_H
