#include <SFML/Graphics.hpp>

#include "Menu.h"

using namespace std;
Menu::Menu(int x, int y, TextureLoader& textures, string textureReference)
    : GameObject(x, y, textures, textureReference), state("")
{
    sprite.setTexture(textures.getTexture(textureReference));
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

void Menu::drawMenu(sf::RenderWindow& canvas)
{
    this->drawSprite(canvas);
    for(int i = 0; i < (int)buttons.size(); ++i)
    {
        buttons[i].drawButton(canvas, getPosX(), getPosY());
    }
    return;
}
bool Menu::update()
{
   newIteration();
   return false;
}

void Menu::newIteration()
{
    for(int i = 0; i < (int) buttons.size(); ++i)
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

void Menu::removeButton(int index)
{
    buttons.erase(buttons.begin()+index);
    return;
}
