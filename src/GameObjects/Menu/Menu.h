/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    LoadMenu.h
 * Enhetsnamn: LoadMenu
 * Typ:        definition
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar den funktionalitet som de flesta menyer b�r ha, till�gg av knappar osv.
 *
 */

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
        /**
        * Konstruktor
        * @param x x-koord f�r menyns v�nstra h�rn
        * @param y y-koord f�r menyns �vre h�rn
        * @param textureReference bildfilens namn f�r bakgrunden av menyn
        */
        Menu(int x, int y, std::string textureReference);
        /**
        * dtor
        */
        virtual ~Menu();
        /**
        * returnerar state och s�tter sedan state till ""
        */
        std::string readState();
        /**
        * returnerar om knapp n �r clickad (se button)
        */
        bool isButtonClicked(int buttonIndex);
        /**
        * returnerar om knapp n �r nedtryckt
        * @param n index
        */
        bool isButtonPressed(int buttonIndex);
        /**
        * returnerar om knapp n �r blev nedtryckt (se button)
        * @param n index
        */
        bool buttonGotPressed(int buttonIndex);
        /**
        * ritar ut menyn
        * @param canvas f�nstret som man skall rita ut p�
        */
        void drawMenu(sf::RenderWindow& canvas);
        /**
        * updaterar menyn, returnerar true om state har �ndrats
        */
        virtual bool update();
        /**
        * l�gger till en knapp i menyn sist
        * @param newButton knappen som l�ggs till
        */
        void addButton(Button* newButton);
        /**
        * tar bort knappen p� givet index
        * @param index s�kt index
        */
        void removeButton(int index);
        /**
        * k�r new iteration p� alla knappar, skall helst k�ras i update innan den returnerar
        */
        void newIteration();
        /**
        * inaktiverar menyn s� att den ej reagerar p� knapptryck
        */
        void sleep();
        /**
        * aktiverar menyn s� att den reagerar p� knapptryck igen
        */
        void activate();
    protected:
        std::string state;
        std::vector<Button*> buttons;
        bool invisible;
    private:
};

#endif // MENU_H
