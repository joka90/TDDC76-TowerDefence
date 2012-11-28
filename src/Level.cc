#include "Level.h"
#include <string>
#include <iostream>
#include <fstream>

#define TRACKFOLDER "levels/"

#define createObjectFromType(parm,type) if(parm==#type) {  \
tmpPtr=new type(); \
}

using namespace std;

Level::Level(string trackFile, int, TextureLoader& inTextures, SoundLoader& inSounds, MusicLoader& inMusic, FontLoader& inFonts)
 : textures(inTextures), sounds(inSounds), music(inMusic), fonts(inFonts), player(0,0)
{
    loadBase(trackFile);
}

void Level::loadBase(string trackFile)
{
    trackName = trackFile;
    ifstream loadData;
    char stringBuffer[256];
    loadData.open(trackFile);
    loadData.getline(stringBuffer, 256, '\n');
    //ladda bakgrund
    background.setTextureAnimation(textures.getTexture(stringBuffer));
    background.setPosition(0,0);
    //initiera spelaren
    int money, lives;
    loadData>>money;
    loadData>>lives;
    Player(money, lives);
    //ladda mapMatrix
    int row, col;
    loadData>>row;
    loadData>>col;
    loadData.ignore();
    string MapMatrixData;
    for(int i = 0; i < row; ++i)
    {
        loadData.getline(stringBuffer, 256, '\n');
        MapMatrixData = MapMatrixData + string(stringBuffer) + string(" ");
    }
    map.setMatrix(MapMatrixData, row, col);
    //ladda waveHandler
    //ladda mapMatrix
    int spawnX, spawnY;
    loadData>>spawnX;
    loadData>>spawnY;
    string waveHandlerData;
    while(loadData.good())
    {
        char temp;
        loadData>>temp;
        waveHandlerData = waveHandlerData+temp;
    }
    loadData.ignore();
    waves = new WaveHandler(spawnX, spawnY, waveHandlerData);
}

Level::Level(string filename, TextureLoader& inTextures, SoundLoader& inSounds, MusicLoader& inMusic, FontLoader& inFonts)
 : textures(inTextures), sounds(inSounds), music(inMusic), fonts(inFonts), player(0,0)
{
	char type[20];
	char subType[20];
	char parms[100];

	FILE * pFile;

	pFile = fopen(filename.c_str(),"r");
	if (pFile!=NULL)
  	{
  		while (!feof(pFile))
  		{
			fscanf(pFile, "%s %s %s", type, subType, parms);
            if(type=="T")
            {
                Tower* tmpPtr=NULL;
                //allot of elsifs for all difftent subtypes //TODO
                //createObjectFromType(subType,MegaTower) //macro
                // new Tower(parms, textureLoader, soundLoader, fontLoader)
                if(tmpPtr!=NULL)
                {
                    //towers.push_back(tmpPtr);
                }
            }
        /*	else if(type=="E")
            {
                Tower* tmpPtr=NULL;
                //allot of elsifs for all difftent subtypes
                if(tmpPtr!=NULL)
                {
                    towers.push_back(tmpPtr);
                }
            }*/
            else  if(type=="P")
            {
                Projectile* tmpPtr=NULL;
                //allot of elsifs for all difftent subtypes
                if(tmpPtr!=NULL)
                {
                    //towers.push_back(tmpPtr);
                }
            }
            else if(type=="Player")
            {

            }
			//createObject(string(type), string(subType), string(parms)); //TODO
			//cout << "Type: " <<  type << "\tSubType: " <<  subType << "\tParameters: " << parms << endl;
		}
	}
	else
	{
		cout << "error reading file: " << filename << endl;
	}
	fclose(pFile);
}

bool Level::update()
{

    // Update towers
    for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
    {
        Projectile* p = (*it)->update(enemies);
        if(p != NULL){
            projectiles.push_back(p);
        }

    }
    // Update projectiles
    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
    {
        (*it)->update(enemies);
    }


}

void Level::draw(sf::RenderWindow& canvas)
{
    canvas.draw(background);
    // draw Tower
    for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
    {
        (*it)->drawSprite(canvas);
    }
    // draw projectiles
    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
    {
        (*it)->drawSprite(canvas);
    }

}

void Level::runWave()
{

}

void Level::saveMap()
{


}
