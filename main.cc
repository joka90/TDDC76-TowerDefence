#include "src/AnimatedSprite.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "src/GameHandler.h"

#include <sstream>
#include <string>

#include <math.h>
#define PI 3.14159265

#include "src/EventHandler.h"

void quitListen(sf::Event)
{
    throw;
}

int main()
{
    EventHandler::addListener(sf::Event::Closed, quitListen);
	GameHandler currentGame;
	currentGame.run();
    return 0;
}
