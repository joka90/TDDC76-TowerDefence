#include "StatusBarMenu.h"
#define MENUSTARTX 0
#define MENUSTARTY 560
#define SAVEX 50
#define SAVEY 0
#define QUITX 160
#define QUITY 0
#define BUTTONWIDTH 100
#define BUTTONHEIGHT 40
#define CLICK "CLICK.WAV"
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


    addButton(new Button(MENUSTARTX, MENUSTARTY, SAVEX, SAVEY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, "  Save", ""));
    addButton(new Button(MENUSTARTX, MENUSTARTY, QUITX, QUITY, BUTTONWIDTH, BUTTONHEIGHT, BUTTON, CLICK, "  Quit", ""));
}

StatusBarMenu::~StatusBarMenu()
{

}
void StatusBarMenu::drawMenu(sf::RenderWindow& canvas, Player& player)
{
    sprite.setPosition(MENUSTARTX, MENUSTARTY);//Fult
    sprite.setScale(800,1);
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
bool StatusBarMenu::update()
{
    if(buttons[0]->gotPressed())
    {
        state = "SAVE";
        return true;
    }
    if(buttons[1]->gotPressed())
    {
        state = "QUIT";
        return true;
    }
    newIteration();//TODO
    return false;
}
