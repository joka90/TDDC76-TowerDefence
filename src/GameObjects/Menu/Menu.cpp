#include "Menu.h"

Menu::Menu(int x, int y, class TextureLoader* textures, string textureReference)
    :GameObject(x, y, textures, textureReference), state(""),
{
}

Menu::~Menu()
{
    //dtor
}
string readState()
{
    temp = state;
    state = "";
    return temp;
}
bool isButtonClicked(int buttonIndex)
{
    return buttons[buttonIndex].gotClicked();
}

bool isButtonPressed(int buttonIndex)
{
    return buttons[buttonIndex].isPressed();
}

bool buttonGotPressed(int buttonIndex)
{
    return buttons[buttonIndex].gotPressed();

}

void drawMenu(RenderWindow canvas)
{
    for(uint i = 0; i < buttons.size(); ++i)
    {
        buttons[i].drawButton(RenderWindow canvas);
    }
    this->drawSprite(RenderWindow canvas);
    return;
}
virtual bool update()
{
   newIter();
   return;
}

void newIteration()
{
    for(uint i = 0; i < buttons.size(); ++i)
    {
        buttons[i].newIteration();
    }
    return;
}
void addButton(Button newButton)
{
    buttons.push_back(newButton);
    return;
}
