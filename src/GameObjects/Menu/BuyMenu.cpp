#include "BuyMenu.h"

#define BUYMENUSTARTX 100
#define BUYMENUSTARTY 500

#define TOWERDRAWSTARTX 40
#define TOWERDRAWSTARTY 40
#define TOWERWIDTH 100
#define TOWERHEIGHT 100
#define TOWERDRAWSPACEX 120
#define TOWERBUTTON "button.png"
#define CLICKSOUND "CLICK.WAW"

#define BASTORN "Sprites/Bunny/Blue(bunny_1.png"
#define ANNATTORN "Sprites/Bunny/TowenBunnie(tower_bunnies.png"

BuyMenu::BuyMenu(TextureLoader& textures, SoundLoader& sounds, FontLoader& fonts)
 : Menu(BUYMENUSTARTX, BUYMENUSTARTY, textures, "BuyMenu.png")
{
    //HÅRDKODAT VILKAT TORN SOM FINNS ATT KÖPA
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX, TOWERDRAWSTARTY, TOWERWIDTH, TOWERHEIGHT,
                      textures, sounds, fonts, TOWERBUTTON, CLICKSOUND, "", "ett billigt och bra torn"));
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX+TOWERDRAWSPACEX, TOWERDRAWSTARTY, TOWERWIDTH, TOWERHEIGHT,
                      textures, sounds, fonts, TOWERBUTTON, CLICKSOUND, "", "ett annat torn"));

    //lägg till låsatsknappar för utritandet
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX, TOWERDRAWSTARTY, 0, 0,
                      textures, sounds, fonts, BASTORN, "", "", ""));
    addButton(new Button(BUYMENUSTARTX, BUYMENUSTARTY, TOWERDRAWSTARTX+TOWERDRAWSPACEX, TOWERDRAWSTARTY, 0, 0,
                      textures, sounds, fonts, ANNATTORN, "", "", ""));
    buttons[3]->sleep();
    buttons[4]->sleep();
    // lägg till priserna på tornen
    priceVector.push_back(100);
    priceVector.push_back(300);
    //lägg till tornen i IDvector
    IDvector.push_back("BASIC");
    IDvector.push_back("OTHER");
}

BuyMenu::~BuyMenu()
{
    //dtor
}

bool BuyMenu::update()
{
    for(int i = 0; i < priceVector.size(); ++i)
    {
        if(buttons[i]->gotPressed())
        {
            state = IDvector[i];
            currentTowerCost = priceVector[i];
            return true;
        }
    }
}
