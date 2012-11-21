#ifndef  EVENTHANDLER_H
#define EVENTHANDLER_H
#include <SFML/Graphics.hpp>
#include <vector>
typedef void (*eventHandlerFunction)(sf::Event);


class EventHandler
{
public:
    EventHandler();
    static void poll(sf::RenderWindow& canvas);
    static void addListener(sf::Event::EventType, eventHandlerFunction);
    static bool removeListener(sf::Event::EventType, eventHandlerFunction);

private:
    static std::vector<eventHandlerFunction> closedHandlers;
    static std::vector<eventHandlerFunction> keyPressedHandlers;
    static std::vector<eventHandlerFunction> keyReleasedHandlers;
    static std::vector<eventHandlerFunction> mouseButtonPressedHandlers;
    static std::vector<eventHandlerFunction> mouseButtonReleasedHandlers;
    static std::vector<eventHandlerFunction> mouseMovedHandlers;
};

#endif //end EVENTHANDLER_H
