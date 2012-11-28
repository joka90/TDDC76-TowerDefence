#ifndef  LEVEL_H
#define LEVEL_H
#include <SFML/Graphics.hpp>
#include "Wave/Wave.h"
#include "Wave/WaveHandler.h"
#include "ClickManager/MapMatrix.h"
#include "GameObjects/Towers/Tower.h"
#include "GameObjects/Projectiles/Projectile.h"
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
    Level(std::string saveFile, TextureLoader& textures, SoundLoader& sounds, MusicLoader& music, FontLoader& fonts);
    Level(std::string trackName, int, TextureLoader& textures, SoundLoader& sounds, MusicLoader& music, FontLoader& fonts);

    std::string name;

    bool update();
    void draw(sf::RenderWindow& canvas);

private:
    TextureLoader& textures;
    SoundLoader& sounds;
    FontLoader& fonts;
    MusicLoader& music;
    AnimatedSprite background;
    MapMatrix map;
    std::vector<Enemy*> enemies;
    std::vector<Tower*> towers;
    std::vector<Projectile*> projectiles;
    WaveHandler* waves;
    Player player;
    std::string trackName;
    void runWave();
    bool saveLevel(std::string saveFile);
	void loadBase(std::string trackFile, int index = 0);
	ClickManager clickManager;
};

#endif //end H
