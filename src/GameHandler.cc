#include "GameHandler.h"
#include <string>
using namespace std;
/*
GameHandler::GameHandler()
:music("media/music/","VAD SKALL IN HÄR?"), textures("media/img/","VAD SKALL IN HÄR?"), sounds("media/sound/","VAD SKALL IN HÄR?"), fonts("media/font/","VAD SKALL IN HÄR?"), canvas(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), WINDOWNAME), clickManager(), startMenu(&textures, &sounds, &fonts), loadMenu(&textures, &sounds, &fonts), trackMenu(&textures, &sounds, &fonts), currentState(STARTMENU)
{

}
*/
GameHandler::GameHandler()
:canvas(sf::VideoMode(WINDOWWIDTH, WINDOWHEIGHT), WINDOWNAME), clickManager(), startMenu(&textures, &sounds, &fonts), loadMenu(&textures, &sounds, &fonts), trackMenu(&textures, &sounds, &fonts), currentState(STARTMENU)
{
    // init all loaders
    fonts.load(string("media/font/"), string("appleberry_with_cyrillic.ttf"));
}

GameHandler::~GameHandler()
{
	delete currentLevel;
}

void GameHandler::run()
{
    // Limit the framerate
    canvas.setFramerateLimit(FRAMERATE);

    // Create a graphical text to display
    sf::Text text("Hello SFML", fonts.getFont(string("media/font/"), string("appleberry_with_cyrillic.ttf")), 50);
    text.move(20,20);
	sf::Clock frameTime;

    // Start the game loop
    while (canvas.isOpen())
    {
		sf::Time renderTime = frameTime.getElapsedTime();
		frameTime.restart();
		EventHandler::poll(canvas);

        // Process events, until working EventHandler
        sf::Event event;
        while (canvas.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                canvas.close();
        }

        canvas.clear();

		switch(currentState){
		case LEVEL:
			currentLevel->update();
			currentLevel->draw(canvas);
		  	break;
		case LOADMENU:
			loadMenu.update();
			loadMenu.drawMenu(canvas);
			break;
		case TRACKMENU:
			trackMenu.update();
			trackMenu.drawMenu(canvas);
			break;
		case STARTMENU:
			startMenu.update();
			startMenu.drawMenu(canvas);
			break;
		default:
			// Code
			break;
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

