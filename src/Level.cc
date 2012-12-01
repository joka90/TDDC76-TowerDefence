#include "Level.h"

using namespace std;

Level::Level(string trackFile, int)
 : player(0,0), clickManager(towers, map), nextWaveMenu()
 {
     loadBase(trackFile, 0);
 }

void Level::loadBase(string trackFile, int index)
{
    trackName = trackFile;
    ifstream loadData;
    char stringBuffer[256];
    loadData.open(trackFile);
    loadData.getline(stringBuffer, 256, '\n');
    //ladda bakgrund
    background.setTextureAnimation(TextureLoader::getTexture(stringBuffer));
    background.setPosition(0,0);
    //initiera spelaren
    int money, lives;
    loadData>>money;
    loadData>>lives;
    player = Player(money, lives);
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
    map.setMatrix(MapMatrixData, row, col);
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

Level::Level(string saveFile)
 : player(0,0), clickManager(towers, map), nextWaveMenu()
{
	char type[20];
	char subType[20];
	char parms[200];

	//Temp variabels to load into
	int tmpLife;
	int tmpMoney;
	int tmpWave;
	char tmpTrackFile[50];

	FILE * pFile;

	pFile = fopen(saveFile.c_str(),"r");
	if (pFile!=NULL)
	{
		while (!feof(pFile))
		{
			fscanf(pFile, "%s %s %s", type, subType, parms);
			string typeStr= string(type);
			string subTypeStr = string(subType);
			string parmsStr = string(parms);
			if(typeStr=="T")
			{
				Tower* tmpPtr=NULL;
				if(subTypeStr=="LongTower")
				{
					tmpPtr=new LongTower(parmsStr);
				}
				cout << "New tower " << subTypeStr <<  " parms: " << parmsStr << endl;
				//add tower if created
				if(tmpPtr!=NULL)
				{
					towers.push_back(tmpPtr);
				}
			}
			else if(typeStr=="Level")
			{
				sscanf(parms,"%i,%s",&tmpWave,tmpTrackFile);
			}
			else if(typeStr=="Player")
			{
				sscanf(parms,"%i,%i",&tmpMoney,&tmpLife);
			}
			//cout << "Type: " <<  type << "\tSubType: " <<  subType << "\tParameters: " << parms << endl;
		}

		//Init Level and wave, load from file
		loadBase(string(tmpTrackFile),tmpWave);
		cout << "Loading level " << tmpTrackFile <<  " wave: " << tmpWave << endl;

		//init player after Level to overwrite life and money
		player=Player(tmpMoney, tmpLife);
		cout << "Life " << tmpLife <<  " Money: " << tmpMoney << endl;

		//load towers into map matrix
		// get pos from towers
		for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
		{
			//map.setTower((*it)->getPosX(), (*it)->getPosY()); //TODO uncomment this when mapmatrix is working. Now it's just throwing a seg fault...
			cout << (*it)->getPosX() << " " << (*it)->getPosY() << endl;
		}
	}
	else
	{
		cout << "error reading save file: " << saveFile << endl;
	}
	fclose(pFile);
}

bool Level::update()
{
    // Update WaveHandler (place new enemy if one)
    Enemy* enemyToBePlaced = waves->update();
    if(enemyToBePlaced != NULL)
    {
        enemies.push_back(enemyToBePlaced);
    }

    //Update enemies
    for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        //(*it)->update(map);
    }

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
	if(nextWaveMenu.update())
    {
        string message = nextWaveMenu.readState();
        if(message == "NEXTWAVE")
        {
            waves->startNextWave();
        }
    }
    return true;
}

void Level::draw(sf::RenderWindow& canvas)
{
    canvas.draw(background);
	// Create a graphical text to display
	std::stringstream ss;
	ss << "Money:" << waves->getIsRunning() << " Life: " << enemies.size();
    sf::Text text(ss.str(), FontLoader::getFont("appleberry_with_cyrillic.ttf"), 50);
    text.move(300,20);

	// Update the canvas
	canvas.draw(text);
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
    clickManager.drawMenus(canvas);
    nextWaveMenu.drawMenu(canvas);
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
		cout << "Error opening save file" << endl;
		return false;
	}
	ostream os(&fb);

	//save level and waveHandler
	os << "Level" << " Level " << waves->getCurrentWaveIndex() << ","  << trackName << endl;
	//save player
	os << "Player" << " Player " << player.getMoney() << "," << player.getLife() << endl;

	//save all towers
	for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
	{
		os << (*it)->getSaveString() << endl;
	}

	fb.close();
	return true;
}
