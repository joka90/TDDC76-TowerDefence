#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

#include "../GameObject.h"
#include "Button.h"

struct LoadPair
{
    std::string name;
    std::string file;
};

class Menu : public GameObject
{
    public:
        Menu(int x, int y, std::string textureReference);
        virtual ~Menu();
        std::string readState();
        bool isButtonClicked(int buttonIndex);
        bool isButtonPressed(int buttonIndex);
        bool buttonGotPressed(int buttonIndex);
        void drawMenu(sf::RenderWindow&);
        virtual bool update();
        void addButton(Button* newButton);
        void removeButton(int index);
        void newIteration();
        void sleep();
        void activate();
    protected:
        std::string state;
        std::vector<Button*> buttons;
        bool invisible;
    private:
};

#endif // MENU_H
