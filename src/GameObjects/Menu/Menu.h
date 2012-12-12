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
 * Denna modul hanterar den funktionalitet som de flesta menyer bör ha, tillägg av knappar osv.
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
        * @param x x-koord för menyns vänstra hörn
        * @param y y-koord för menyns övre hörn
        * @param textureReference bildfilens namn för bakgrunden av menyn
        */
        Menu(int x, int y, std::string textureReference);
        /**
        * dtor
        */
        virtual ~Menu();
        /**
        * returnerar state och sätter sedan state till ""
        */
        std::string readState();
        /**
        * returnerar om knapp n är clickad (se button)
        */
        bool isButtonClicked(int buttonIndex);
        /**
        * returnerar om knapp n är nedtryckt
        * @param n index
        */
        bool isButtonPressed(int buttonIndex);
        /**
        * returnerar om knapp n är blev nedtryckt (se button)
        * @param n index
        */
        bool buttonGotPressed(int buttonIndex);
        /**
        * ritar ut menyn
        * @param canvas fönstret som man skall rita ut på
        */
        void drawMenu(sf::RenderWindow& canvas);
        /**
        * updaterar menyn, returnerar true om state har ändrats
        */
        virtual bool update();
        /**
        * lägger till en knapp i menyn sist
        * @param newButton knappen som läggs till
        */
        void addButton(Button* newButton);
        /**
        * tar bort knappen på givet index
        * @param index sökt index
        */
        void removeButton(int index);
        /**
        * kör new iteration på alla knappar, skall helst köras i update innan den returnerar
        */
        void newIteration();
        /**
        * inaktiverar menyn så att den ej reagerar på knapptryck
        */
        void sleep();
        /**
        * aktiverar menyn så att den reagerar på knapptryck igen
        */
        void activate();
    protected:
        std::string state;
        std::vector<Button*> buttons;
        bool invisible;
    private:
};

#endif // MENU_H
