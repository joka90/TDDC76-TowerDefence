#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#include "../GameObject.h"
#include "../../Loader/MusicLoader.h"
#include "../../Loader/TextureLoader.h"
#include "../../Loader/SoundLoader.h"
#include "../../Loader/FontLoader.h"
#include "../../EventUser.h"


class Button : public GameObject, public MouseButtonPressedUser, public MouseButtonReleasedUser, public MouseMovedUser
{
    public:
        Button(int MenuX, int MenuY, int relativeX, int relativeY, int inWidthX, int inWidthY, TextureLoader& inTextures, SoundLoader& inSounds, FontLoader& inFonts, std::string spriteKey, std::string soundKey, std::string inButtonText, std::string inMouseOverText);
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
        int widthX;
        int widthY;
        bool pressed;
        bool clicked;
        bool thisIterPressed;
        bool hoover;
        sf::Text mouseOverText;
        sf::Text buttonText;
        sf::Sound* clickSound;
        FontLoader& fonts;
        TextureLoader& textures;
        SoundLoader& sounds;
        void drawText();
};

#endif // BUTTON_H
