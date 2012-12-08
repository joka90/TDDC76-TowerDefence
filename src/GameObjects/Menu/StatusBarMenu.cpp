#include "StatusBarMenu.h"
#define MENUSTARTX 0
#define MENUSTARTY 560
#define SAVEX 50
#define SAVEY 0
#define QUITX 160
#define QUITY 0
#define BUTTONWIDTH 100
#define BUTTONHEIGHT 40
#define CLICK "thozi_daClick.ogg"
#define BUTTON "statusbarButton.png"
#include <iostream>

using namespace std;

StatusBarMenu::StatusBarMenu()
 : Menu(MENUSTARTX,MENUSTARTY, "statusbar.png")
{
	playerMoney=sf::Text("test",FontLoader::getFont("appleberry_with_cyrillic.ttf"),30);
	playerLife=sf::Text("test",FontLoader::getFont("appleberry_with_cyrillic.ttf"),30);
	playerMoney.setPosition(300, 560);
	playerLife.setPosition(450, 560);
    sprite.setPosition(MENUSTARTX, MENUSTARTY);
    sprite.setScale(800,1);

    addButton(new Button(MENUSTARTX, MENUSTARTY, SAVEX, SAVEY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, "  Save", "Can not save during wave."));
    addButton(new Button(MENUSTARTX, MENUSTARTY, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, "  Quit", ""));
}

StatusBarMenu::~StatusBarMenu()
{

}
void StatusBarMenu::drawMenu(sf::RenderWindow& canvas, Player& player)
{
    canvas.draw(sprite);
    for(int i = 0; i < (int)buttons.size(); ++i)
    {
        buttons[i]->drawButton(canvas, getPosX(), getPosY());
    }
    stringstream moneyStr, lifeStr;
    moneyStr << "M: " << player.getMoney();
	playerMoney.setString(moneyStr.str());
	lifeStr <<  "L: " << player.getLife();
	playerLife.setString(lifeStr.str());
	canvas.draw(playerMoney);
	canvas.draw(playerLife);
    return;
}
bool StatusBarMenu::update(bool waveDone)
{
	if(waveDone)
	{
		buttons[0]->setButtonHoverText("");
		buttons[0]->setColor(sf::Color(255,255,255,255));
	}
	else
	{
		buttons[0]->setButtonHoverText("Can not save during wave.");
		buttons[0]->setColor(sf::Color(100,100,100,255));
	}
    if(buttons[0]->gotPressed())
    {
        state = "SAVE";
    	newIteration();
        return true;
    }
    if(buttons[1]->gotPressed())
    {
        state = "QUIT";
    	newIteration();
        return true;
    }
    newIteration();
    return false;
}
