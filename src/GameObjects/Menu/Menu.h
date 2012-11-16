#ifndef MENU_H
#define MENU_H

#include <GameObject.h>


class Menu : public GameObject
{
    public:
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
    private:
};

#endif // MENU_H
