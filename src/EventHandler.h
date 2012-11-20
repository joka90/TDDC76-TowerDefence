#ifndef  EVENTHANDLER_H
#define EVENTHANDLER_H
#include <SFML/Graphics.hpp>

class EventHandler
{
public:
    EventHandler();
    static void poll(sf::RenderWindow& canvas);
private:
};

#endif //end EVENTHANDLER_H
