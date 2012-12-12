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
        * @param MenuX x koord f�r menyn
        * @param MenuY y koord f�r menyn
        * @param relativeX x koord f�r knappen relativt menyn som �ger den
        * @param relativeY y koord f�r knappen relativt menyn som �ger den
        * @param inWidthX bredden f�r knappen
        * @param inWidthX h�jden f�r knappen
        * @param spriteKey namnet p� bildfilen
        * @param soundKey namn p� clickljudsfilen
        * @param inButtonText texten som st�r p� knappen
        * @param inMouseOverText texten som visas d� man h�ller musen �ver knappen
        */
        Button(int MenuX, int MenuY, int relativeX, int relativeY, int inWidthX, int inWidthY, std::string spriteKey, std::string soundKey, std::string inButtonText, std::string inMouseOverText);
        /**
        * assignment beh�vdes f�r att ha vektorer av knappar men anv�nds ej nu
        */
        Button& operator=(const Button& inButton);
        /**
        * dtor
        */
        virtual ~Button();
        /**
        * ritar ut knappen
        * @param canvas spelf�nstret som man ska rita p�
        * @param menuCoordX x koordinaterna f�r menyn som man ska rita ut
        * @param menuCoordY y koordinaterna f�r menyn som man ska rita ut
        */
        void drawButton(sf::RenderWindow& canvas, int menuCoordX, int menuCoordY);
        /**
        * returnerar om knappen �r nedtryckt
        */
        bool isPressed();
        /**
        * returnerar om knappen blev nedtryckt sedan senast newIteration kallades
        */
        bool gotPressed();
         /**
        * returnerar om knappen blev sl�pptes upp sedan senast newIteration kallades
        */
        bool gotClicked();
         /**
        * returnerar om musen �r �ver kanppen
        */
        bool hoovering();
         /**
        * reagerar p� nedtryckningar av knappen. ska k�ras av EventHandler
        */
        void mouseButtonPressedListener(sf::Event);
        /**
        * reagerar p� om man slutar trycka p� knappen. ska k�ras av EventHandler
        */
        void mouseButtonReleasedListener(sf::Event);
        /**
        * reagerar p� om man har flyttat kanppen fr�n knappen. ska k�ras av EventHandler
        */
        void mouseMoveListener(sf::Event);
        /**
        * ska k�ras varje iteration s� att man kan kolla om knapparna har blivit nedtryckta nyligen
        */
        void newIteration();
        /**
        * ritar ut hooverText vid mouseover
        * @param canvas spelf�nstret som man ska rita p�
        */
        void drawHooverText(sf::RenderWindow& canvas);
        /**
        * avaktiverar uppdateringar av knappen, ska anv�das d� man vet att knappen ej ska anv�ndas
        */
        void sleep();
        /**
        * aktiverar uppdateringar av knappen, d� man har kallat p� sleep och ska b�rja anv�nda knappen igen
        */
        void activate();
        /**
        * �ndrar texten p� knappen
        * @param newText den nya texten
        */
        void setButtonText(std::string newText);
        /**
        * �ndrar hoover texten p� knappen
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
