#include <iostream>
#include <fstream>

#include "LoadMenu.h"


#define CLICK "CLICK.WAW"

#define MENULOADX 0
#define MENULOADY 0

#define LOADDRAWS 4

#define ARROWWIDTH 20
#define ARROWHEIGHT 40
#define ARROWUPX 300
#define ARROWUPY 300
#define ARROWDOWNX 300
#define ARROWDOWNY 400
#define ARROWUP "ARROWUP.BMP"
#define ARROWDOWN "ARROWDOWN.BMP"

#define BACKX 100
#define BACKY 400
#define BACKWIDTH 70
#define BACKHEIGHT 30
#define BACKIMG "BACKBUTTON.BMP"
#define LOADFOLDER "../../../saves"
using namespace std;
LoadMenu::LoadMenu(class TextureLoader* textures, class SoundLoader* sounds, class FontLoader* fonts)
:Menu(MENULOADX, MENULOADY, textures, "LOADMENU.BMP")
{
    //Ladda in vilka sparfiler som finns
    ifstream loadData;
    char stringBuffer[256];
    string loadDataPath = string(LOADFOLDER) + string("SaveData");
    loadData.open(loadDataPath.c_str(), ifstream::in);
    while(loadData.good())
    {
        LoadPair tempLoadPair;
        loadData.getline(stringBuffer, 256, ' ');
        tempLoadPair.name = stringBuffer;
        loadData.getline(stringBuffer, 256, '\n');
        tempLoadPair.file = stringBuffer;
        loadVectorData.push_back(tempLoadPair);
    }
    //lägg till knappar
    addButton(Button(MENULOADX, MENULOADY, ARROWUPX, ARROWUPY, ARROWWIDTH, ARROWHEIGHT,
                      textures, sounds, fonts, ARROWUP, CLICK, "", ""));
    addButton(Button(MENULOADX, MENULOADY, ARROWDOWNX, ARROWDOWNY, ARROWWIDTH, ARROWHEIGHT,
                      textures, sounds, fonts, ARROWDOWN, CLICK, "", ""));
    addButton(Button(MENULOADX, MENULOADY, BACKX, BACKY, BACKWIDTH, BACKHEIGHT,
                      textures, sounds, fonts, BACKIMG, CLICK, "", ""));
}

LoadMenu::~LoadMenu()
{
    //dtor
}

bool LoadMenu::update()
{
    if(buttons[0].gotPressed())
    {
        scrollLenght -= 1;
        if(scrollLenght < 0)
            {
                scrollLenght = 0;
            }
        newIteration();
        return false;
    }
    else if(buttons[1].gotPressed())
    {
        if(scrollLenght < (int) loadVectorData.size()-LOADDRAWS)
            {
                scrollLenght += 1;
            }
        newIteration();
        return false;
    }
    else if(buttons[2].gotPressed())
    {
        state = "BACK";
        newIteration();
        return true;
    }
    else
    {
        newIteration();
        return false;
    }
}

void LoadMenu::draw(sf::RenderWindow& canvas)
{

}

