/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    EventHandler.h
 * Enhetsnamn: EventHandler
 * Typ:        implementering
 * Skriven av: D. Molin, T. Norlund
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten f�r saker som skall ha koordinater och skall ritas ut p� spelplanen
 *
 */

#ifndef  EVENTHANDLER_H
#define EVENTHANDLER_H
#include <SFML/Graphics.hpp>
#include "EventUser.h"
#include <vector>
typedef void (*eventHandlerFunction)(sf::Event);


class EventHandler
{
public:
    EventHandler();
    static void poll(sf::RenderWindow& canvas);
    static void addListener(sf::Event::EventType, EventUser*);
    static bool removeListener(sf::Event::EventType, EventUser*);

private:
    static std::vector<ClosedUser*> closedHandlers;
    static std::vector<KeyPressedUser*> keyPressedHandlers;
    static std::vector<KeyReleasedUser*> keyReleasedHandlers;
    static std::vector<MouseButtonPressedUser*> mouseButtonPressedHandlers;
    static std::vector<MouseButtonReleasedUser*> mouseButtonReleasedHandlers;
    static std::vector<MouseMovedUser*> mouseMovedHandlers;
};

#endif //end EVENTHANDLER_H
