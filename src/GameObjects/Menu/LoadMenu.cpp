#include <iostream>
#include <fstream>

#include "LoadMenu.h"


#define CLICK "CLICK.WAW"

#define MENULOADX 0
#define MENULOADY 0

#define LOADIMG "LOADIMG.png"
#define LOADDRAWS 4
#define LOADSTARTX 100
#define LOADSTARTY 100
#define LOADGAPY 50
#define LOADWIDTHX 300
#define LOADWIDTHY 40

#define ARROWWIDTH 40
#define ARROWHEIGHT 80
#define ARROWUPX 600
#define ARROWUPY 100
#define ARROWDOWNX 600
#define ARROWDOWNY 200
#define ARROWUP "ARROWUP.png"
#define ARROWDOWN "ARROWDOWN.png"
#define LOADBUTTON "LOADBUTTON.png"

#define BACKX 100
#define BACKY 500
#define BACKWIDTH 70
#define BACKHEIGHT 70
#define BACKIMG "BACKBUTTON.png"
#define LOADFOLDER "saves/"
using namespace std;
LoadMenu::LoadMenu()
:Menu(MENULOADX, MENULOADY, "StartMenu.png"), scrollLenght(0)
{
    //Ladda in vilka sparfiler som finns
    ifstream loadData;
    char stringBuffer[256];
    string loadDataPath = string(LOADFOLDER) + string("SaveData.dat");
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
    loadData.close();
    //lägg till knappar
    addButton(new Button(MENULOADX, MENULOADY, ARROWUPX, ARROWUPY, ARROWWIDTH, ARROWHEIGHT,
                      ARROWUP, CLICK, "", ""));
    addButton(new Button(MENULOADX, MENULOADY, ARROWDOWNX, ARROWDOWNY, ARROWWIDTH, ARROWHEIGHT,
                      ARROWDOWN, CLICK, "", ""));
    addButton(new Button(MENULOADX, MENULOADY, BACKX, BACKY, BACKWIDTH, BACKHEIGHT,
                      BACKIMG, CLICK, "", ""));
    updateLoadButtons();
}

LoadMenu::~LoadMenu()
{

}

void LoadMenu::updateLoadButtons()
{
    while(buttons.size() > 3)
    {
        removeButton(3);
    }
    for(int i = 0; i < LOADDRAWS; ++i)
        {
            if(i+scrollLenght < (int) loadVectorData.size()-1)
            {
                addButton(new Button(MENULOADX, MENULOADY, LOADSTARTX, LOADSTARTY+LOADGAPY*i, LOADWIDTHX, LOADWIDTHY,
                      LOADIMG, CLICK, (loadVectorData[scrollLenght+i]).name, ""));
            }
        }
}

bool LoadMenu::update()
{
    if(buttons[0]->gotPressed())
    {
        scrollLenght -= 1;
        if(scrollLenght < 0)
            {
                scrollLenght = 0;
            }
        updateLoadButtons();
        newIteration();
        return false;
    }
    else if(buttons[1]->gotPressed())
    {
        if(scrollLenght < (int) loadVectorData.size()-LOADDRAWS-1)
            {
                scrollLenght += 1;
                updateLoadButtons();
            }
        newIteration();
        return false;
    }
    else if(buttons[2]->gotPressed())
    {
        state = "START";
        newIteration();
        return true;
    }
    for(int i = 0; i < LOADDRAWS; ++i)
    {
        if(buttons[i+3]->gotPressed())
        {
            state =  string(LOADFOLDER) + ((loadVectorData[scrollLenght+i]).file).c_str();
            newIteration();
            return true;
        }

    }
    newIteration();
    return false;
}
