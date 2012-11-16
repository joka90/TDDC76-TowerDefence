#include "Button.h"
#include <Mouse.hpp>
#include <Vector2.hpp>
Button::Button(int MenuX, int MenuY, int relativeX, int relativeY, int inWidthX, int inWidthY, class TextureLoader* textures, class SoundLoader* sounds, class FontLoader* fonts, string spriteKey, string soundKey, string inMouseOverText)
    : realtivePosX(relativeX), realtivePosY(relativeY), widthX(inWidthX), widthY(inWidthY), isPressed(false), clicked(false), gotPressed(false), hoover(false) GameObject(MenuX+relativeX, MenuY+relativeY, textures, sounds, fonts)
{
    clicksound = Sound(sounds->getSoundBuffer(soundKey));
    sprite = Sprite(textures->getTexture(spriteKey)); //fel fixa fler argument
    mouseOverText = Text(inMouseOverText, fonts.)
}

/*
*  ta bort prenumerationen på events
*/
Button::~Button()
{
    //dtor
}
void drawButton(RenderWindow& canvas, int menuCoordX, int menuCoordY)
{
    setPosX(menuCoordX+relativeCoordX);
    setPosY(menuCoordY+relativeCoordY);
    drawSprite(canvas);
    if(hoover)
    {
        drawText();
    }
}

bool isPressed()
{
    return pressed;
}
bool gotPressed()
{
    return gotPressed;
}
bool gotClicked()
{
    return gotPressed;
}
bool hoovering()
{
    return hoover;
}

void mouseButtonPressedListener(sf::event::MouseButtonPressed)
{
    sf::vector2i pos = Mouse::sf::Mouse::getPosition();
    if(Mouse::sf::isButtonPressed(sf::Mouse::left) &&  )
        {
            if((pos.x > getPosX()) && (pos.x < getPosX()+widthX) && (pos.y > getPosY()) && (pos.y < getPosY()+widthY))
            {
                if(pressed = false)
                {
                    gotPressed = true;
                    clickSound.Play();
                }
                pressed = true;
            }
        }
}

void mouseButtonReleasedListener(sf::event::MouseButtonReleased)
{
    sf::vector2i pos = Mouse::sf::Mouse::getPosition();
    if(Mouse::sf::isButtonPressed(sf::Mouse::left) &&  )
        {
            if(pressed)
            {
                clicked = true;
            }
            pressed = false
        }
}

void mouseMoveListener(sf::event::MouseMoved)
{
    sf::vector2i pos = Mouse::sf::Mouse::getPosition();
    if(Mouse::sf::isButtonPressed(sf::Mouse::left) &&  )
        {
            if(!((pos.x > getPosX()) && (pos.x < getPosX()+widthX) && (pos.y > getPosY()) && (pos.y < getPosY()+widthY)))
            {
                pressed = false;
            }
        }
    else if((pos.x > getPosX()) && (pos.x < getPosX()+widthX) && (pos.y > getPosY()) && (pos.y < getPosY()+widthY))
    {
        hoover = true;
    }
    else
    {
        hoover = false;
    }
}
