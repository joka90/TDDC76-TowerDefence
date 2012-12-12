/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    GameHandler.cc
 * Enhetsnamn: GameHandler
 * Typ:        implementering
 * Skriven av: J. Källström
 *
 *
 * BESKRIVNING
 *
 * Denna modul delegerar alla uppgifter till andra klasser
 *
 */

#include "GameHandler.h"
#include <iostream>

using namespace std;

GameHandler::GameHandler()

:currentLevel(NULL), currentState(STARTMENU), canvas(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), WINDOWNAME), startMenu(), loadMenu(), trackMenu(), soundMenu()
{
    // init all loaders
    FontLoader::load(std::string("appleberry_with_cyrillic.ttf"));
    MusicLoader::load(std::string("menu.ogg"));
    MusicLoader::load(std::string("level_1.ogg"));
}


void GameHandler::closedListener(sf::Event)
{
    cout << "quit" << endl;
    canvas.close();
}

GameHandler::~GameHandler()
{
	if(currentLevel!=NULL)
	{
		delete currentLevel;
	}
}

void GameHandler::run()
{
    // Limit the framerate
    canvas.setFramerateLimit(FRAMERATE);
    // Create a graphical text to display


    // Create a graphical text to display
    sf::Text text("Hello SFML", FontLoader::getFont("appleberry_with_cyrillic.ttf"), 30);
    text.move(600,0);
	sf::Clock frameTime;

	//initiera musik (börjar med menymusik)
	musicHandler.playSong(MusicLoader::getMusic("menu.ogg"));

    EventHandler::addListener(sf::Event::Closed, this);
    //sleep all the inactive menus
        loadMenu.sleep();
        trackMenu.sleep();
    // Start the game loop
    while (canvas.isOpen())
    {
		sf::Time renderTime = frameTime.getElapsedTime();
		std::string nextState;
		frameTime.restart();
        canvas.clear();

        // Polls the EventHandler to handle eventual events
		EventHandler::poll(canvas);

        // handle current state
		switch(currentState){
		case LEVEL:
			if(currentLevel->update())
			{
				nextState=currentLevel->readState();
			}
			currentLevel->draw(canvas);
			if(nextState != "")
			{
			    delete(currentLevel);
			    currentLevel = NULL;
			}
		  	break;
		case LOADMENU:
			if(loadMenu.update())
			{
				nextState=loadMenu.readState();
				loadMenu.sleep();
			}
			loadMenu.drawMenu(canvas);
			break;
		case TRACKMENU:
			if(trackMenu.update())
			{
				nextState=trackMenu.readState();
				trackMenu.sleep();
			}
			trackMenu.drawMenu(canvas);
			break;
		case STARTMENU:
			if(startMenu.update())
			{
				nextState=startMenu.readState();
				startMenu.sleep();
			}
			startMenu.drawMenu(canvas);
			break;
		default:
			// Code
			break;
		}
		// handle events sent by menu
		if(nextState!="")
		{
			if(nextState=="TRACK")
			{
                musicHandler.setCurrentSong(MusicLoader::getMusic("menu.ogg"));
				currentState=TRACKMENU;
				trackMenu.activate();
			}
			else if(nextState=="START")
			{
                musicHandler.setCurrentSong(MusicLoader::getMusic("menu.ogg"));
				currentState=STARTMENU;
				startMenu.activate();
			}
			else if(nextState=="LOAD")
			{
                musicHandler.setCurrentSong(MusicLoader::getMusic("menu.ogg"));
				currentState=LOADMENU;
				loadMenu.loadSaveData();//load savedata and update buttons.
				loadMenu.activate();
			}
			else if(nextState=="QUIT")
			{
				canvas.close();//do some more?
			}
			else
			{
				if(currentState == LOADMENU && nextState != "")
				{
				    currentState=LEVEL;
				    currentLevel = new Level(nextState); // hur man nu laddar/initierar banor
                    musicHandler.setCurrentSong(MusicLoader::getMusic(currentLevel->getSongName()));
				}
				if(currentState == TRACKMENU && nextState != "")
				{
				    currentState=LEVEL;
				    currentLevel = new Level(nextState, 0);
				    musicHandler.setCurrentSong(MusicLoader::getMusic(currentLevel->getSongName()));

				}
			}
			nextState="";
		}
		//always show soundMenu
		soundMenu.update(musicHandler);
		soundMenu.drawMenu(canvas);
        // SHOW FPS
        std::stringstream ss;
        ss <<  1/renderTime.asSeconds() << " fps";
        text.setString(ss.str());
		// Update the canvas
		canvas.draw(text);
		canvas.display();
		//uppdatera musik
        if(currentLevel != NULL)
        {
            if(currentLevel->isDone() || currentLevel->getCurrentLife() == 0)
            {
                musicHandler.stopAllSongs();
            }
            if(currentLevel->getCurrentLife() == 1)
            {
                musicHandler.setCurrentSong(MusicLoader::getMusic("low_health.ogg"));
            }
        }
        musicHandler.update();
	}
	return;
}

