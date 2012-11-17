#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#include "../GameObject.h"

class Button : public GameObject
{
    public:
        Button(int MenuX, int MenuY, int relativeX, int relativeY, int inWidthX, int inWidthY, class TextureLoader* textures, class SoundLoader* sounds, class FontLoader* fonts, std::string spriteKey, std::string soundKey, std::string buttonText, std::string inMouseOverText);
        Button& operator=(const Button& inButton);
        virtual ~Button();
        void drawButton(sf::RenderWindow& canvas, int menuCoordX, int menuCoordY);
        bool isPressed();
        bool gotPressed();
        bool gotClicked();
        bool hoovering();
        void mouseButtonPressedListener(sf::Event);
        void mouseButtonReleasedListener(sf::Event);
        void mouseMoveListener(sf::Event);
        void newIteration();
        void drawHooverText();
    protected:
    private:
        int relativePosX;
        int relativePosY;
        uint widthX;
        uint widthY;
        bool pressed;
        bool clicked;
        bool thisIterPressed;
        bool hoover;
        sf::Text mouseOverText;
        sf::Text buttonText;
        sf::Sound* clickSound;

        void drawText();
};

#endif // BUTTON_H
