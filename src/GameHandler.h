#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H
#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>

#include "Level.h"

#include "GameObjects/Menu/StartMenu.h"
/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    GameHandler.h
 * Enhetsnamn: GameHandler
 * Typ:        implementering
 * Skriven av: J. Källström
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten för saker som skall ha koordinater och skall ritas ut på spelplanen
 *
 */


#include "GameObjects/Menu/LoadMenu.h"
#include "GameObjects/Menu/TrackMenu.h"
#include "GameObjects/Menu/SoundMenu.h"

#include "ClickManager/ClickManager.h"
#include "EventHandler.h"

#include "Loader/MusicLoader.h"
#include "Loader/TextureLoader.h"
#include "Loader/SoundLoader.h"
#include "Loader/FontLoader.h"
#include "MusicHandler.h"

#define WINDOWWIDTH 800
#define WINDOWHEIGHT 600
#define WINDOWNAME "Tower Defence"
#define FRAMERATE 60
//defines for switchcase int currentState
#define STARTMENU 	0
#define LOADMENU 	1
#define TRACKMENU 	2
#define LEVEL 		3

class GameHandler : ClosedUser
{
public:
    GameHandler();
    ~GameHandler();

    void run();

protected:
    void closedListener(sf::Event);

	Level* currentLevel;

	int currentState;

	sf::RenderWindow canvas;

	StartMenu startMenu;
	LoadMenu loadMenu;
	TrackMenu trackMenu;
	SoundMenu soundMenu;

private:
    MusicHandler musicHandler;

};

#endif
