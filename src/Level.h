/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Level.h
 * Enhetsnamn: Level
 * Typ:        implementering
 * Skriven av: Alla
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten för saker som skall ha koordinater och skall ritas ut på spelplanen
 *
 */

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
    // Konstruktor för att ladda en bana från en befintlig sparning
    Level(std::string saveFile);
    Level(std::string trackName, int);

    ~Level();

    // Unikt namn för varje bana
    std::string trackName;

    // Uppdaterar banan, körs varje frame
    bool update();
    // Returnerar om banan är klar (om man dött eller klarat banan)
    bool isDone();
    // Ritar ut banan på den canavs som skickas med, körs varje frame
    void draw(sf::RenderWindow& canvas);
    // Läser aktuellt tillstånd (används vid navigering)
    std::string readState();
    // Returnerar aktuell sång
    std::string getSongName();
    // Returnerar aktuellt antal liv
    int getCurrentLife();

private:
    // WaveHandler för att hantera banans vågor
    WaveHandler* waves;
    // MapMatrix för att representera banans karta
    MapMatrix map;
    // Player för att representera spelaren
    Player player;
    // ClickManager för att hantera klick
    ClickManager clickManager;

    // Innehåller alla enemies som lever just nu
    std::vector<Enemy*> enemies;
    // Innehåller alla torn som finns utplacerade just nu
    std::vector<Tower*> towers;
    // Innehåller alla existerande projektiler just nu
    std::vector<Projectile*> projectiles;
     // Innehåller alla VisualEffects som visas just nu
    std::vector<VisualEffect*> visualEffects;


    // Sparar banan  dess aktuella tillstånd
    bool saveLevel(std::string saveFile);
    // Laddar en bana från en given sparfil
	void loadBase(std::string trackFile, int index = 0);
	bool done;

    // Banans bakgrund
	AnimatedSprite background;

    // Meny för att starta en ny wave
    NextWaveMenu nextWaveMenu;
    // Meny för att spara, avsluta, ändra volym
    StatusBarMenu statusBarMenu;

    // Innehålelr aktuellt tillstånd
    std::string state;

    // Banans musik
    std::string songName;
    // Segermusik
    sf::Sound* victorySound;
    sf::Sound* gameOverSound;
};

#endif //end H
