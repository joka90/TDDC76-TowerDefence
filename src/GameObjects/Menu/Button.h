#ifndef BUTTON_H
#define BUTTON_H


class Button : public GameObject
{
    public:
        Button(int MenuX, int MenuY, int relativeX, int relativeY, int inWidthX, int inWidthY, class TextureLoader* textures, class SoundLoader* sounds, class FontLoader* fonts, string spriteKey, string soundKey, string inMouseOverText);
        virtual ~Button();
        void drawButton(RenderWindow& canvas, int menuCoordX, int menuCoordY);
        bool isPressed();
        bool gotPressed();
        bool gotClicked();
        bool hoovering();
        void mouseButtonPressedListener(sf::event::MouseButtonPressed);
        void mouseButtonReleasedListener(sf::event::MouseButtonReleased);
        void mouseMoveListener(sf::event::MouseMoved);
    protected:
    private:
        const int realtivePosX;
        const int realtivePosY;
        uint widthX;
        uint widthY;
        bool pressed;
        bool clicked;
        bool gotPressed;
        string mouseOverText;
        bool hoover;
        sf:sound clickSound;

        void drawText();
};

#endif // BUTTON_H
