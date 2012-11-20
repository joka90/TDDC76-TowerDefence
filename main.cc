#include "src/AnimatedSprite.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>

#include <math.h>
#define PI 3.14159265

int main()
{

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return EXIT_SUCCESS;
}
