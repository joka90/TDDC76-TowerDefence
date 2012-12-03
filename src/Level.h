#ifndef  LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include "Wave/Wave.h"
#include "Wave/WaveHandler.h"
#include "ClickManager/MapMatrix.h"
#include "GameObjects/Towers/Tower.h"
#include "GameObjects/Towers/LongTower.h"
#include "GameObjects/Projectiles/Projectile.h"
#include "GameObjects/Menu/NextWaveMenu.h"
#include "GameObjects/Menu/StatusBarMenu.h"
#include "AnimatedSprite.h"
#include "Loader/MusicLoader.h"
#include "Loader/TextureLoader.h"
#include "Loader/SoundLoader.h"
#include "Loader/FontLoader.h"
#include "ClickManager/Player.h"
#include "ClickManager/ClickManager.h"

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <fstream>

class Level
{
public:

    Level() = delete;
    Level(std::string saveFile);
    Level(std::string trackName, int);

    std::string name;

    bool update();
    void draw(sf::RenderWindow& canvas);
    std::string readState();

private:
    WaveHandler* waves;
    MapMatrix map;
    Player player;
    ClickManager clickManager;

    std::string trackName;

    std::vector<Enemy*> enemies;
    std::vector<Tower*> towers;
    std::vector<Projectile*> projectiles;

    void runWave();
    bool saveLevel(std::string saveFile);
	void loadBase(std::string trackFile, int index = 0);

	AnimatedSprite background;

    NextWaveMenu nextWaveMenu;
    StatusBarMenu statusBarMenu;

    std::string state;
};

#endif //end H
