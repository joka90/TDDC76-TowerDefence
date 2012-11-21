#ifndef  ENEMY_H
#define ENEMY_H
#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class Enemy : public GameObject
{
public:
    Enemy(int newX, int newY, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader);
    virtual bool drawSprite(sf::RenderWindow& canvas);
private:

protected:

};
#endif //end ENEMY_H
