#ifndef  PROJECTILE_H
#define PROJECTILE_H
#include "../GameObject.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>

class Projectile : public GameObject
{
public:
    Projectile(int newX, int newY, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader);

    //virtual bool drawSprite(sf::RenderWindow& canvas);  // �rvs fr�n GameObject, beh�vs inte.. /T

    virtual void update(std::vector<Enemy*>& enemies) = 0;

    // Fr�gest�llning: Hur/vart kollas om en viss fiende �r tr�ffad av en viss projektil? Hur tas fienden & projektilen bort?
    //                 Ska en projektil kunna tr�ffa flera fiender? Hur hanteras det is�fall?

private:

protected:

};
#endif //end PROJECTILE_H
