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
 * Denna modul implementerar basfunktionaliteten f�r saker som skall ha koordinater och skall ritas ut p� spelplanen
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
    // Konstruktor f�r att ladda en bana fr�n en befintlig sparning
    Level(std::string saveFile);
    Level(std::string trackName, int);

    ~Level();

    // Unikt namn f�r varje bana
    std::string trackName;

    // Uppdaterar banan, k�rs varje frame
    bool update();
    // Returnerar om banan �r klar (om man d�tt eller klarat banan)
    bool isDone();
    // Ritar ut banan p� den canavs som skickas med, k�rs varje frame
    void draw(sf::RenderWindow& canvas);
    // L�ser aktuellt tillst�nd (anv�nds vid navigering)
    std::string readState();
    // Returnerar aktuell s�ng
    std::string getSongName();
    // Returnerar aktuellt antal liv
    int getCurrentLife();

private:
    // WaveHandler f�r att hantera banans v�gor
    WaveHandler* waves;
    // MapMatrix f�r att representera banans karta
    MapMatrix map;
    // Player f�r att representera spelaren
    Player player;
    // ClickManager f�r att hantera klick
    ClickManager clickManager;

    // Inneh�ller alla enemies som lever just nu
    std::vector<Enemy*> enemies;
    // Inneh�ller alla torn som finns utplacerade just nu
    std::vector<Tower*> towers;
    // Inneh�ller alla existerande projektiler just nu
    std::vector<Projectile*> projectiles;
     // Inneh�ller alla VisualEffects som visas just nu
    std::vector<VisualEffect*> visualEffects;


    // Sparar banan  dess aktuella tillst�nd
    bool saveLevel(std::string saveFile);
    // Laddar en bana fr�n en given sparfil
	void loadBase(std::string trackFile, int index = 0);
	bool done;

    // Banans bakgrund
	AnimatedSprite background;

    // Meny f�r att starta en ny wave
    NextWaveMenu nextWaveMenu;
    // Meny f�r att spara, avsluta, �ndra volym
    StatusBarMenu statusBarMenu;

    // Inneh�lelr aktuellt tillst�nd
    std::string state;

    // Banans musik
    std::string songName;
    // Segermusik
    sf::Sound* victorySound;
    sf::Sound* gameOverSound;
};

#endif //end H
