#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H
#include <SFML/Graphics.hpp>

#include "Level.h"

#include "GameObject/Menu/StartMenu.h"
#include "GameObject/Menu/LoadMenu.h"
#include "GameObject/Menu/TrackMenu.h"

#include "ClickManager/ClickManager.h"
#include "EventHandler.h"

#include "Loader/MusicLoader.h"
#include "Loader/TextureLoader.h"
#include "Loader/SoundLoader.h"
#include "Loader/FontLoader.h"

#define WINDOWWIDTH 800
#define WINDOWHEIGHT 600
#define WINDOWNAME "Tower Devence"
#define FRAMERATE 60
//defines for switchcase int currentState
#define STARTMENU 	0
#define LOADMENU 	1
#define TRACKMENU 	2
#define LEVEL 		3

class GameHandler
{
public:
    GameHandler();
    ~GameHandler();

    void run();

protected:
	Level* currentLevel;

	int currentState;

	StartMenu startMenu;
	LoadMenu loadMenu;
	TrackMenu trackMenu;

	ClickManager clickManager;
	sf::RenderWindow canvas;

	MusicLoader music;
	TextureLoader textures;
	SoundLoader sounds;
	FontLoader fonts;

};

#endif
