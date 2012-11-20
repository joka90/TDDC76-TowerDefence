#ifndef  LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>

class Level
{
public:
    Level();
    bool update();
    void draw(sf::RenderWindow& canvas);
private:
};

#endif //end H
