#include "Level.h"

#define createObjectFromType(parm,type) if(parm==#type) {  \
tmpPtr=new type(); \
}

using namespace std;

Level::Level(string trackFile, int, TextureLoader& inTextures, SoundLoader& inSounds, MusicLoader& inMusic, FontLoader& inFonts)
 : textures(inTextures), sounds(inSounds), music(inMusic), fonts(inFonts), player(0,0)
 {
     loadBase(trackFile);
 }

void Level::loadBase(string trackFile, int index)
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
    //ladda mapMatrix
    string MapMatrixData;
    for(int i = 0; i < row; ++i)
    {
        loadData.getline(stringBuffer, 256, '\n');
        MapMatrixData = MapMatrixData + string(stringBuffer) + string(" ");
    }
    spawnX, spawnY;
    loadData>>spawnX;
    loadData>>spawnY;
    map.setMatrix(MapMatrixData, row, col, spawnX, spawnY);
    //ladda waveHandler

    string waveHandlerData;
    while(loadData.good())
    {
        char temp;
        loadData>>temp;
        waveHandlerData = waveHandlerData+temp;
    }
    loadData.ignore();
    waves = new WaveHandler(waveHandlerData, index);
}

Level::Level(string saveFile, TextureLoader& inTextures, SoundLoader& inSounds, MusicLoader& inMusic, FontLoader& inFonts)
 : textures(inTextures), sounds(inSounds), music(inMusic), fonts(inFonts), player(0,0)
{
	char type[20];
	char subType[20];
	char parms[100];

	FILE * pFile;

	pFile = fopen(saveFile.c_str(),"r");
	if (pFile!=NULL)
	{
		while (!feof(pFile))
		{
			fscanf(pFile, "%s %s %s", type, subType, parms);
			if(type=="T")
			{
				Tower* tmpPtr=NULL;
				//allot of elsifs for all difftent subtypes //TODO
				// new Tower(parms, textureLoader, soundLoader, fontLoader)
				if(tmpPtr!=NULL)
				{
					//towers.push_back(tmpPtr);
				}
			}
			else if(type=="Level")
			{
				//Init Level, load from file
			}
			else if(type=="Wave")
			{
				//Init waves
			}
			else if(type=="Player")
			{
				//Init Player
			}
			//cout << "Type: " <<  type << "\tSubType: " <<  subType << "\tParameters: " << parms << endl;
		}
	}
	else
	{
		cout << "error reading file: " << saveFile << endl;
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

bool Level::saveLevel(string saveFile)
{
	filebuf fb;
	fb.open(saveFile,ios::out);
	if (!fb.is_open())
	{
		cout << "Error opening file" << endl;
		return false;
	}
	ostream os(&fb);
	//save all towers
	for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
	{
		std::cout << (*it)->getSaveString() << endl;
	}

	fb.close();
	return true;
}
