#ifndef  LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include "Wave/Wave.h"
#include "Wave/WaveHandler.h"
#include "ClickManager/Player.h"
#include "ClickManager/MapMatrix.h"
#include "GameObjects/Towers/Tower.h"
#include "GameObjects/Projectiles/Projectile.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

class Level
{
public:

    Level();
    Level(std::string saveFile, TextureLoader& inTextureLoader, SoundLoader& inSoundLoader, FontLoader& inFontLoader);

    std::string name;

    Player player;

    bool update();
    void draw(sf::RenderWindow& canvas);

private:

    MapMatrix map;
    std::vector<Enemy*> enemies;
    std::vector<Tower*> towers;
    std::vector<Projectile*> projectiles;
    WaveHandler* waves;

    void runWave();
    bool saveLevel(std::string saveFile);
};

#endif //end H
