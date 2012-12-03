#include "Button.h"
#include "../../EventHandler.h"
#include <iostream>
using namespace std;
Button::Button(int MenuX, int MenuY, int relativeX, int relativeY, int inWidthX, int inWidthY, string spriteKey, string soundKey, string inButtonText, string inMouseOverText)
    : GameObject(MenuX+relativeX, MenuY+relativeY, spriteKey), relativePosX(relativeX), relativePosY(relativeY), widthX(inWidthX), widthY(inWidthY), pressed(false), clicked(false), thisIterPressed(false), hoover(false)
{
    sleeping = false;
    if(soundKey != "")
    {
       // clickSound = new sf::Sound(sounds->getSoundBuffer(soundKey));
    }
	FontLoader::load("appleberry_with_cyrillic.ttf");
	buttonText=sf::Text(inButtonText,FontLoader::getFont("appleberry_with_cyrillic.ttf"),30);
	mouseOverText=sf::Text(inMouseOverText,FontLoader::getFont("appleberry_with_cyrillic.ttf"),20);
	EventHandler::addListener(sf::Event::MouseButtonPressed, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonPressedUser*>(this)));
    EventHandler::addListener(sf::Event::MouseButtonReleased, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonReleasedUser*>(this)));
    EventHandler::addListener(sf::Event::MouseMoved, dynamic_cast<EventUser*>(dynamic_cast<MouseMovedUser*>(this)));

}

/*
*  ta bort prenumerationen på events
*/
Button::~Button()
{
    EventHandler::removeListener(sf::Event::MouseButtonPressed, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonPressedUser*>(this)));
    EventHandler::removeListener(sf::Event::MouseButtonReleased, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonReleasedUser*>(this)));
    EventHandler::removeListener(sf::Event::MouseMoved, dynamic_cast<EventUser*>(dynamic_cast<MouseMovedUser*>(this)));
}

Button& Button::operator=(const Button& inButton)
{
    relativePosX = inButton.relativePosX;
    relativePosY = inButton.relativePosY;
    widthX = inButton.widthX;
    widthY = inButton.widthY;
    pressed = inButton.pressed;
    clicked = inButton.clicked;
    thisIterPressed = inButton.thisIterPressed;
    hoover = inButton.thisIterPressed;
    mouseOverText = inButton.mouseOverText;
    EventHandler::addListener(sf::Event::MouseButtonPressed, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonPressedUser*>(this)));
    EventHandler::addListener(sf::Event::MouseButtonReleased, dynamic_cast<EventUser*>(dynamic_cast<MouseButtonReleasedUser*>(this)));
    EventHandler::addListener(sf::Event::MouseMoved, dynamic_cast<EventUser*>(dynamic_cast<MouseMovedUser*>(this)));
    if(clickSound != NULL)
    {
        delete clickSound;
        // clickSound = new sf::Sound(*(inButton.clickSound)); TODO
    }
    return *this;
}

void Button::drawButton(sf::RenderWindow& canvas, int menuCoordX, int menuCoordY)
{
    setPos(menuCoordX+relativePosX, menuCoordY+relativePosY);
    if(hoover)
    {
    	sprite.setColor(sf::Color(200, 200, 255, 200));
    }
    else
    {
    	sprite.setColor(sf::Color(255, 255, 255, 255));
    }
    drawSprite(canvas);
	buttonText.setPosition(menuCoordX+relativePosX, menuCoordY+relativePosY);// fixed for now because looping away..
	canvas.draw(buttonText);
    return;
}

bool Button::isPressed()
{
    return pressed;
}
bool Button::gotPressed()
{
    return thisIterPressed;
}
bool Button::gotClicked()
{
    return clicked;
}
bool Button::hoovering()
{
    return hoover;
}
void Button::sleep()
{
    sleeping = true;
}

void Button::activate()
{
    sleeping = false;
}


void Button::mouseButtonPressedListener(sf::Event event)
{
    if(sleeping)
    {
        return;
    }
    if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(hoover)
            {
                if(pressed == false)
                {
                    thisIterPressed = true;
                    if(clickSound != NULL)
                    {
                       // clickSound->play(); TODO
                    }
                }
                pressed = true;
            }
        }
}

void Button::mouseButtonReleasedListener(sf::Event event)
{
    if(sleeping)
        {
            return;
        }
    if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(pressed)
            {
                clicked = true;
            }
            pressed = false;
        }
}

void Button::mouseMoveListener(sf::Event event)
{
    if(sleeping)
    {
        return;
    }
    if(event.mouseButton.button == sf::Mouse::Left)
        {
            if(!(((event.mouseMove.x > getPosX()) && (event.mouseMove.x < getPosX()+widthX)) && ((event.mouseMove.y > getPosY()) && (event.mouseMove.y < getPosY()+widthY))))
            {
                pressed = false;
                hoover = false;
            }
        }
    else if(((event.mouseMove.x > getPosX()) && (event.mouseMove.x < getPosX()+widthX)) && ((event.mouseMove.y > getPosY()) && (event.mouseMove.y < getPosY()+widthY)))
    {
        hoover = true;
    }
    else
    {
        hoover = false;
    }
}
/*
*   viktigt denna funktion kallas innan Sleep annars blir saker inte bra.
*/
void Button::newIteration()
{
    clicked = false;
    thisIterPressed = false;
    return;
}

void Button::drawHooverText(sf::RenderWindow& canvas)
{
    if(hoover)
    {
        sf::Vector2i pos=sf::Mouse::getPosition(canvas);
        mouseOverText.setPosition(pos.x+10,pos.y+10);
        canvas.draw(mouseOverText);
    }
    return; //TODO
}
