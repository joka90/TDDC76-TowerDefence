#include "GameHandler.h"
#include <iostream>

GameHandler::GameHandler()

:music(), textures(), sounds(), fonts(), currentLevel(NULL), currentState(STARTMENU), canvas(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), WINDOWNAME), clickManager(), startMenu(textures, sounds, fonts), loadMenu(textures, sounds, fonts), trackMenu(textures, sounds, fonts)
{
    // init all loaders
    fonts.load(std::string("appleberry_with_cyrillic.ttf"));
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
    sf::Text text("Hello SFML", fonts.getFont("appleberry_with_cyrillic.ttf"), 50);
    text.move(20,20);
	sf::Clock frameTime;

    EventHandler::addListener(sf::Event::Closed, this);
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
			currentLevel->update();
			currentLevel->draw(canvas);
		  	break;
		case LOADMENU:
			if(loadMenu.update())
			{
				nextState=loadMenu.readState();
			}
			loadMenu.drawMenu(canvas);
			break;
		case TRACKMENU:
			if(trackMenu.update())
			{
				nextState=trackMenu.readState();
			}
			trackMenu.drawMenu(canvas);
			break;
		case STARTMENU:
			if(startMenu.update())
			{
				nextState=startMenu.readState();
			}
			startMenu.drawMenu(canvas);
			break;
		default:
			// Code
			break;
		}
		if(nextState=="TRACK")
		{
			currentState=TRACKMENU;
		}
		else if(nextState=="START")
		{
			currentState=STARTMENU;
		}
		else if(nextState=="LOAD")
		{
			currentState=LOADMENU;
		}
		else if(nextState=="QUIT")
		{
			canvas.close();//do some more?
		}
        // SHOW FPS
        std::stringstream ss;
        ss <<  1/renderTime.asSeconds() << " fps";
        text.setString(ss.str());
		// Update the canvas
		canvas.draw(text);
		canvas.display();

	}
	return;
}

