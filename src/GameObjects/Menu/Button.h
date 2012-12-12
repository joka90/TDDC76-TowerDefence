#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

#include "../GameObject.h"
#include "../../Loader/MusicLoader.h"
#include "../../Loader/TextureLoader.h"
#include "../../Loader/SoundLoader.h"
#include "../../Loader/FontLoader.h"
#include "../../EventUser.h"


class Button : public GameObject, public MouseButtonPressedUser, public MouseButtonReleasedUser, public MouseMovedUser
{
    public:
        /**
        * Konstruktor
        * @param MenuX x koord för menyn
        * @param MenuY y koord för menyn
        * @param relativeX x koord för knappen relativt menyn som äger den
        * @param relativeY y koord för knappen relativt menyn som äger den
        * @param inWidthX bredden för knappen
        * @param inWidthX höjden för knappen
        * @param spriteKey namnet på bildfilen
        * @param soundKey namn på clickljudsfilen
        * @param inButtonText texten som står på knappen
        * @param inMouseOverText texten som visas då man håller musen över knappen
        */
        Button(int MenuX, int MenuY, int relativeX, int relativeY, int inWidthX, int inWidthY, std::string spriteKey, std::string soundKey, std::string inButtonText, std::string inMouseOverText);
        /**
        * assignment behövdes för att ha vektorer av knappar men används ej nu
        */
        Button& operator=(const Button& inButton);
        /**
        * dtor
        */
        virtual ~Button();
        /**
        * ritar ut knappen
        * @param canvas spelfönstret som man ska rita på
        * @param menuCoordX x koordinaterna för menyn som man ska rita ut
        * @param menuCoordY y koordinaterna för menyn som man ska rita ut
        */
        void drawButton(sf::RenderWindow& canvas, int menuCoordX, int menuCoordY);
        /**
        * returnerar om knappen är nedtryckt
        */
        bool isPressed();
        /**
        * returnerar om knappen blev nedtryckt sedan senast newIteration kallades
        */
        bool gotPressed();
         /**
        * returnerar om knappen blev släpptes upp sedan senast newIteration kallades
        */
        bool gotClicked();
         /**
        * returnerar om musen är över kanppen
        */
        bool hoovering();
         /**
        * reagerar på nedtryckningar av knappen. ska köras av EventHandler
        */
        void mouseButtonPressedListener(sf::Event);
        /**
        * reagerar på om man slutar trycka på knappen. ska köras av EventHandler
        */
        void mouseButtonReleasedListener(sf::Event);
        /**
        * reagerar på om man har flyttat kanppen från knappen. ska köras av EventHandler
        */
        void mouseMoveListener(sf::Event);
        /**
        * ska köras varje iteration så att man kan kolla om knapparna har blivit nedtryckta nyligen
        */
        void newIteration();
        /**
        * ritar ut hooverText vid mouseover
        * @param canvas spelfönstret som man ska rita på
        */
        void drawHooverText(sf::RenderWindow& canvas);
        /**
        * avaktiverar uppdateringar av knappen, ska anvädas då man vet att knappen ej ska användas
        */
        void sleep();
        /**
        * aktiverar uppdateringar av knappen, då man har kallat på sleep och ska börja använda knappen igen
        */
        void activate();
        /**
        * ändrar texten på knappen
        * @param newText den nya texten
        */
        void setButtonText(std::string newText);
        /**
        * ändrar hoover texten på knappen
        * @param newText den nya texten
        */
		void setButtonHoverText(std::string newText);
    protected:
    private:
        bool sleeping;
        int relativePosX;
        int relativePosY;
        int widthX;
        int widthY;
        bool pressed;
        bool clicked;
        bool thisIterPressed;
        bool hoover;
        sf::Text mouseOverText;
        sf::Text buttonText;
        sf::Sound* clickSound;
        void drawText();
};

#endif // BUTTON_H
