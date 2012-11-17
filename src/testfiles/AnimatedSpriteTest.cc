#include "../AnimatedSprite.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <sstream>
#include <string>


//playing around
#include <math.h>
#define PI 3.14159265

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    //sf::IntRect v1(100,100,200,200);
    if (!texture.loadFromFile("../../media/img/test.png"))
        return EXIT_FAILURE;

    // Load a sprite to display
    sf::Texture texture2;
    if (!texture2.loadFromFile("../../media/img/sprite-sheet-mario.png"))
        return EXIT_FAILURE;
    //AnimatedSprite(const sf::Texture &inTexture, unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFpf = 1, bool inPlaying = false);
    AnimatedSprite sprite(texture2, 30, 20, 5, true);
    //sprite.move(400,400);
    sf::Sprite test(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("../../media/font/appleberry_with_cyrillic.ttf"))
        return EXIT_FAILURE;
    sf::Text text("Hello SFML", font, 50);
    text.move(200,200);

    int param=0;


    // Limit the framerate to 60 frames per second (this step is optional)
    window.setFramerateLimit(60);

    // Start the game loop
    while (window.isOpen())
    {
        param++;
        if(param>360)
        {
            param=1;
        }
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();
        //test.move((int)(400+50*cos(param*PI/180)), (int)(400+50*(sin(param*PI/180))));
        test.setColor(sf::Color(255, 255, 255, 255*pow(sin(param*PI/180),2)));
        //v1.left=v1.left+1;
        //test.setTextureRect(v1);
        window.draw(test);

        // Draw the sprite
        sprite.update();
        window.draw(sprite);
        // Draw the string
        std::stringstream ss;
        ss <<  sprite.currentFrame() << " frame";
        text.setString(ss.str());
        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}