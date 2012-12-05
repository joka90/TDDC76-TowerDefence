#include "TrackMenu.h"
#include <iostream>
#include <fstream>


#define CLICK "CLICK.WAV"

#define MENULOADX 0
#define MENULOADY 0

#define TRACKLEVELIMG "TRACKLEVELIMG.png"
#define LEVELDRAWS 4
#define LEVELSTARTX 100
#define LEVELSTARTY 100
#define LEVELGAPY 50
#define LEVELWIDTHX 300
#define LEVELWIDTHY 40

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
#define BACKIMG "StartButton_BG.png"
#define LEVELFOLDER "levels/"
using namespace std;
TrackMenu::TrackMenu()
:Menu(MENULOADX, MENULOADY, "Track_BG.png"), scrollLenght(0)
{
    //Ladda in vilka sparfiler som finns
    ifstream loadData;
    char stringBuffer[256];
    string loadDataPath = string(LEVELFOLDER) + string("LevelData.dat");
    loadData.open(loadDataPath.c_str(), ifstream::in);
    while(loadData.good())
    {
        LoadPair tempLoadPair;
        loadData.getline(stringBuffer, 256, ' ');
        tempLoadPair.name = stringBuffer;
        loadData.getline(stringBuffer, 256, '\n');
        tempLoadPair.file = stringBuffer;
        trackVectorData.push_back(tempLoadPair);
    }
    //lägg till knappar
    addButton(new Button(MENULOADX, MENULOADY, ARROWUPX, ARROWUPY, ARROWWIDTH, ARROWHEIGHT,
                      ARROWUP, CLICK, "", ""));
    addButton(new Button(MENULOADX, MENULOADY, ARROWDOWNX, ARROWDOWNY, ARROWWIDTH, ARROWHEIGHT,
                       ARROWDOWN, CLICK, "", ""));
    addButton(new Button(MENULOADX, MENULOADY, BACKX, BACKY, BACKWIDTH, BACKHEIGHT,
                       BACKIMG, CLICK, "Back", ""));
    updateLoadButtons();
}

TrackMenu::~TrackMenu()
{
    //dtor
}

void TrackMenu::updateLoadButtons()
{
    while(buttons.size() > 3)
    {
        removeButton(3);
    }
    for(int i = 0; i < LEVELDRAWS; ++i)
        {
            if(i+scrollLenght < (int) trackVectorData.size() -1)
            {
                addButton(new Button(MENULOADX, MENULOADY, LEVELSTARTX, LEVELSTARTY+LEVELGAPY*i, LEVELWIDTHX, LEVELWIDTHY,
                      TRACKLEVELIMG, CLICK, (trackVectorData[scrollLenght+i]).name, ""));
            }
        }
}

bool TrackMenu::update()
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
        if(scrollLenght < (int) trackVectorData.size()-LEVELDRAWS-1)
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
    for(int i = 0; i < LEVELDRAWS; ++i)
    {
        if(buttons[i+3]->gotPressed())
        {
            state = ((trackVectorData[scrollLenght+i]).file).c_str();
            newIteration();
            return true;
        }
    }
    newIteration();
    return false;
}
