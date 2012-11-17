
#include <SFML/Graphics.hpp>

#include "Menu.h"

using namespace std;
Menu::Menu(int x, int y, class TextureLoader* textures, string textureReference)
    : GameObject(x, y, textures, textureReference), state("")
{
}

Menu::~Menu()
{
    //dtor
}
string Menu::readState()
{
    string temp = state;
    state = "";
    return temp;
}
bool Menu::isButtonClicked(int buttonIndex)
{
    return buttons[buttonIndex].gotClicked();
}

bool Menu::isButtonPressed(int buttonIndex)
{
    return buttons[buttonIndex].isPressed();
}

bool Menu::buttonGotPressed(int buttonIndex)
{
    return buttons[buttonIndex].gotPressed();

}

void Menu::drawMenu(sf::RenderWindow canvas)
{
    for(uint i = 0; i < buttons.size(); ++i)
    {
        buttons[i].drawButton(canvas, getPosX(), getPosY());
    }
    this->drawSprite(canvas);
    return;
}
bool Menu::update()
{
   newIteration();
   return false;
}

void Menu::newIteration()
{
    for(uint i = 0; i < buttons.size(); ++i)
    {
        buttons[i].newIteration();
    }
    return;
}
void Menu::addButton(Button newButton)
{
    buttons.push_back(newButton);
    return;
}