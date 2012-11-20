#include "GameHandler.h"

GameHandler::GameHandler()
:music("media/music/","VAD SKALL IN HÄR?"), textures("media/img/","VAD SKALL IN HÄR?"), sounds("media/sound/","VAD SKALL IN HÄR?"), fonts("media/font/","VAD SKALL IN HÄR?"), canvas(sf::VideoMode(WINDOWHEIGHT, WINDOWWIDTH), WINDOWNAME), clickManager(), startMenu(*textures, *sounds, *fonts), loadMenu(*textures, *sounds, *fonts), trackMenu(*textures, *sounds, *fonts), currentState(STARTMENU)
{

}

GameHandler::~GameHandler()
{
	delete currentLevel;
}

void GameHandler::run()
{
    // Limit the framerate
    canvas.setFramerateLimit(FRAMERATE);

    // Start the game loop
    while (canvas.isOpen())
    {
		EventHandeler::poll(canvas);

		switch(currentState){
		case LEVEL:
			currentLevel->update();
			currentLevel->draw(canvas);
		  	break;
		case LOADMENU:
			loadMenu.update();
			loadMenu.draw(canvas);
			break;
		case TRACKMENU:
			trackMenu.update();
			trackMenu.draw(canvas);
			break;
		case STARTMENU:
			startMenu.update();
			startMenu.draw(canvas);
			break;
		default:
			// Code
			break;
		}

	}
	return;
}

