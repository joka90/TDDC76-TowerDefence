#ifndef  PROJECTILE_H
#define PROJECTILE_H
#include "../GameObject.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>

class Projectile : public GameObject
{
public:
    Projectile(int newX, int newY, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader);

    //virtual bool drawSprite(sf::RenderWindow& canvas);  // Ärvs från GameObject, behövs inte.. /T

    virtual void update(std::vector<Enemy*>& enemies) = 0;

    // Frågeställning: Hur/vart kollas om en viss fiende är träffad av en viss projektil? Hur tas fienden & projektilen bort?
    //                 Ska en projektil kunna träffa flera fiender? Hur hanteras det isåfall?

private:

protected:

};
#endif //end PROJECTILE_H
