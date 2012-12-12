/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    StartMenu.h
 * Enhetsnamn: StartMenu
 * Typ:        defninition
 * Skriven av: J. Källström
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar menyn längst ned på skärmen med spara, avsluta knappar samt ritar ut spelarens liv och pengar
 *
 */

#ifndef STATUSBARMENU_H
#define STATUSBARMENU_H

#include <SFML/Graphics.hpp>
#include <sstream>

#include "Menu.h"
#include "../../Loader/FontLoader.h"
#include "../../ClickManager/Player.h"

class StatusBarMenu : public Menu
{
    public:
        StatusBarMenu();
        virtual ~StatusBarMenu();
		/**
		* drawMenu
		* @param sf::RenderWindow& fönstret som skall ritas på.
		* @param Player& spelaren som information skall visas för
		*/
        void drawMenu(sf::RenderWindow&, Player&);
       	/**
		* update
		* @param update Sätts till true om det ska vara möjligt att trycka på sparknappen.
		*/
        bool update(bool update);
    protected:
    private:
    sf::Text playerMoney;
	sf::Text playerLife;
};

#endif // STATUSBARMENU_H
