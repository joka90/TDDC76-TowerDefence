#include "Menu.h"

Menu::Menu(int x, int y, class TextureLoader*, string textureReference)
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

Menu(int x, int y, class TextureLoader*, string textureReference);
        virtual ~Menu();
        string readState()
        bool isButtonClicked(int buttonIndex)
        void drawSprite(RenderWindow)
        virtual bool update()
        void addButton(Button newButton);
    protected:
        sprite menuBackGround;
        string state;
        vector<Button> buttons;
