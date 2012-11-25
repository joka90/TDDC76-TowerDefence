#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "../GameObject.h"
#include "Button.h"


class Menu : public GameObject
{
    public:
        Menu(int x, int y, TextureLoader&, std::string textureReference);
        virtual ~Menu();
        std::string readState();
        bool isButtonClicked(int buttonIndex);
        bool isButtonPressed(int buttonIndex);
        bool buttonGotPressed(int buttonIndex);
        void drawMenu(sf::RenderWindow&);
        virtual bool update();
        void addButton(Button newButton);
        void removeButton(int index);
        void newIteration();
    protected:
        std::string state;
        std::vector<Button> buttons;
    private:
};

#endif // MENU_H
