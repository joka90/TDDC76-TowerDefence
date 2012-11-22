#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H
#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>

#include "Level.h"

#include "GameObjects/Menu/StartMenu.h"
#include "GameObjects/Menu/LoadMenu.h"
#include "GameObjects/Menu/TrackMenu.h"

#include "ClickManager/ClickManager.h"
#include "EventHandler.h"

#include "Loader/MusicLoader.h"
#include "Loader/TextureLoader.h"
#include "Loader/SoundLoader.h"
#include "Loader/FontLoader.h"

#define WINDOWWIDTH 800
#define WINDOWHEIGHT 600
#define WINDOWNAME "Tower Defence"
#define FRAMERATE 60
//defines for switchcase int currentState
#define STARTMENU 	0
#define LOADMENU 	1
#define TRACKMENU 	2
#define LEVEL 		3

struct funcTest {
    void operator()(sf::Event e) {
    }
};

class GameHandler
{
public:
    GameHandler();
    ~GameHandler();

    void run();

protected:
	MusicLoader music;
	TextureLoader textures;
	SoundLoader sounds;
	FontLoader fonts;
	void quitListen(sf::Event);

	Level* currentLevel;

	int currentState;

	StartMenu startMenu;
	LoadMenu loadMenu;
	TrackMenu trackMenu;

	ClickManager clickManager;
	sf::RenderWindow canvas;

};

#endif
