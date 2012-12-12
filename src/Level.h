#ifndef  LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include "Wave/Wave.h"
#include "Wave/WaveHandler.h"
#include "ClickManager/MapMatrix.h"
#include "GameObjects/Towers/Tower.h"
#include "GameObjects/Towers/LongTower.h"
#include "GameObjects/Towers/CannonTower.h"
#include "GameObjects/Projectiles/Projectile.h"
#include "GameObjects/VisualEffects/VisualEffect.h"
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
#include <sstream>
#include <fstream>
#include <time.h>

class Level
{
public:

    Level() = delete;
    Level(std::string saveFile);
    Level(std::string trackName, int);

    ~Level();

    std::string trackName;

    bool update();
    bool isDone();
    void draw(sf::RenderWindow& canvas);
    std::string readState();

    std::string getSongName();

    int getCurrentLife();

private:
    WaveHandler* waves;
    MapMatrix map;
    Player player;
    ClickManager clickManager;

    std::vector<Enemy*> enemies;
    std::vector<Tower*> towers;
    std::vector<Projectile*> projectiles;
    std::vector<VisualEffect*> visualEffects;

    bool saveLevel(std::string saveFile);
	void loadBase(std::string trackFile, int index = 0);
	bool done;

	AnimatedSprite background;

    NextWaveMenu nextWaveMenu;
    StatusBarMenu statusBarMenu;

    std::string state;

    std::string songName;

    sf::Sound* victorySound;
};

#endif //end H
