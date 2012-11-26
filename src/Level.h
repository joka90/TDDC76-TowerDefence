#ifndef  LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include "Wave/Wave.h"
#include "Wave/WaveHandler.h"
#include "GameObjects/Towers/Tower.h"
#include "GameObjects/Projectiles/Projectile.h"

class Level
{
public:

    Level();

    string name;

    bool update();
    void draw(sf::RenderWindow& canvas);

private:

    //MapMatrix map;
    std::vector<Wave*> waves;
    std::vector<Tower*> towers;
    std::vector<Projectile*> projectiles;
    //WaveHandler* waves; ??

    void runWave();
    void saveMap();
};

#endif //end H
