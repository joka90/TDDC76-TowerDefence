/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    main.cc
 * Enhetsnamn: main
 * Typ:        implementering
 * Skriven av: T. Nordlund
 *
 *
 * BESKRIVNING
 *
 * Denna modul skapar en GameHandler och startar spelloopen
 *
 */

#include "src/AnimatedSprite.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "src/GameHandler.h"
#include <iostream>
#include <sstream>
#include <string>

#include <math.h>
#define PI 3.14159265

#include "src/EventHandler.h"
#include "src/ClickManager/MapMatrix.h"

int main()
{
	GameHandler currentGame;
	currentGame.run();
    return 0;

}
