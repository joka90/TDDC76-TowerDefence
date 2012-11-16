#include "../AnimatedSprite.h"
 #include <SFML/Audio.hpp>
 #include <SFML/Graphics.hpp>
 
 int main()
 {
     // Create the main window
     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
 
     // Load a sprite to display
     sf::Texture texture;
     if (!texture.loadFromFile("../../media/img/test.png"))
         return EXIT_FAILURE;
     AnimatedSprite sprite(texture);
 
     // Create a graphical text to display
     sf::Font font;
     if (!font.loadFromFile("../../media/font/appleberry_with_cyrillic.ttf"))
         return EXIT_FAILURE;
     sf::Text text("Hello SFML", font, 50);

     // Limit the framerate to 60 frames per second (this step is optional)
     window.setFramerateLimit(60);
 
     // Start the game loop
     while (window.isOpen())
     {
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
 
         // Draw the sprite
         window.draw(sprite);
 
         // Draw the string
         window.draw(text);
 
         // Update the window
         window.display();
     }
 
     return EXIT_SUCCESS;
 }
