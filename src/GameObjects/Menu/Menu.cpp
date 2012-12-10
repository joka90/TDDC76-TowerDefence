/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    LoadMenu.cpp
 * Enhetsnamn: LoadMenu
 * Typ:        implementering
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den funktionalitet som de flesta menyer bör ha, tillägg av knappar osv.
 *
 */

#include <SFML/Graphics.hpp>

#include "Menu.h"

using namespace std;
Menu::Menu(int x, int y, string textureReference)
    : GameObject(x, y, textureReference), state(""), buttons(), invisible(false)
{
    buttons.clear();
}

Menu::~Menu()
{
    for(unsigned int i = 0; i < buttons.size(); ++i)
    {
        delete(buttons[i]);
    }
}
string Menu::readState()
{
    string temp = state;
    state = "";
    return temp;
}
bool Menu::isButtonClicked(int buttonIndex)
{
    return buttons[buttonIndex]->gotClicked();
}

bool Menu::isButtonPressed(int buttonIndex)
{
    return buttons[buttonIndex]->isPressed();
}

bool Menu::buttonGotPressed(int buttonIndex)
{
    return buttons[buttonIndex]->gotPressed();

}

void Menu::drawMenu(sf::RenderWindow& canvas)
{
    if(invisible)
    {
        return;
    }
    this->drawSprite(canvas);
    for(int i = 0; i < (int)buttons.size(); ++i)
    {
        buttons[i]->drawButton(canvas, getPosX(), getPosY());
    }
    for(int i = 0; i < (int)buttons.size(); ++i)
    {
        buttons[i]->drawHooverText(canvas);
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
        buttons[i]->newIteration();
    }
    return;
}
void Menu::addButton(Button* newButton)
{
    buttons.push_back(newButton);
    return;
}

void Menu::removeButton(int index)
{
    delete(buttons[index]);
    buttons.erase(buttons.begin()+index);
    return;
}

void Menu::sleep()
{
    for(int i = 0; i < (int) buttons.size(); ++i)
    {
        buttons[i]->sleep();
    }
    return;
}

void Menu::activate()
{
    for(int i = 0; i < (int) buttons.size(); ++i)
    {
        buttons[i]->activate();
    }
    return;
}
