/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    Level.cc
 * Enhetsnamn: Level
 * Typ:        implementering
 * Skriven av: T. Nordlund
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar en bana i spelet
 *
 */

#include "Level.h"

#define LOADFOLDER "saves/"

using namespace std;

Level::Level(string trackFile, int)
 : player(0,0), clickManager(towers, map, player), nextWaveMenu(), statusBarMenu(), state(""), songName("")
 {
     loadBase(trackFile, -1);
 }

void Level::loadBase(string trackFile, int index)
{
    done = false;
    trackName = trackFile;
    ifstream loadData;
    char stringBuffer[256];
    loadData.open(trackFile);
    loadData.getline(stringBuffer, 256, '\n');
    //ladda bakgrund
    background.setTextureAnimation(TextureLoader::getTexture(stringBuffer));
    background.setPosition(0,0);
    //namn på levelns musikfil
    loadData.getline(stringBuffer, 256, '\n');
    songName = stringBuffer;
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
    string path;
    loadData.getline(stringBuffer, 256, '\n');
    path = string(stringBuffer) + string(" ");
    map.setMatrix(MapMatrixData, row, col, path);
    //ladda waveHandler

    string waveHandlerData;
    while(loadData.good())
    {
        string temp;
        getline(loadData,temp);
        //loadData>>temp;
        waveHandlerData = waveHandlerData+temp + "\n";
    }
    //loadData.ignore();
    waves = new WaveHandler(waveHandlerData, index);
}

Level::~Level()
{
    delete(waves);
    for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        delete(*it);
    }
    for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
    {
        delete(*it);
    }
    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
    {
        delete(*it);
    }
    for(vector<VisualEffect*>::iterator it = visualEffects.begin(); it != visualEffects.end(); ++it)
    {
        delete(*it);
    }
}

Level::Level(string saveFile)
 : player(0,0), clickManager(towers, map, player), nextWaveMenu(),  statusBarMenu(), state(""), songName("")
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
				else if(subTypeStr=="CannonTower")
				{
					tmpPtr=new CannonTower(parmsStr);
				}
				//add tower if created
				if(tmpPtr!=NULL)
				{
					towers.push_back(tmpPtr);
				}
			}
			else if(typeStr=="Level")
			{
				sscanf(parms,"%i,%s",&tmpWave,tmpTrackFile);
				cout << "W: " << tmpWave << " L: " << tmpTrackFile <<endl;
			}
			else if(typeStr=="Player")
			{
				sscanf(parms,"%i,%i",&tmpMoney,&tmpLife);
			}
		}

		//Init Level and wave, load from file
		loadBase(string(tmpTrackFile),tmpWave);

		//init player after Level to overwrite life and money
		player=Player(tmpMoney, tmpLife);

		//load towers into map matrix
		// get pos from towers
		for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
		{
			map.setTower((*it)->getPosX(), (*it)->getPosY());
		}
		fclose(pFile);
	}
	else
	{
		cout << "error reading save file: " << saveFile << endl;
	}

}

bool Level::update()
{
    if(!done)
        {
        // Update WaveHandler (place new enemy if one)
        Enemy* enemyToBePlaced = waves->update();
        if(enemyToBePlaced != NULL)
        {
            enemies.push_back(enemyToBePlaced);
        }

        //Update enemies
        vector<Enemy*> deleteEnemyVector;
        for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
        {
            if((*it)->update(map))
            {
                deleteEnemyVector.push_back(*it);
            }
        }
        while(!deleteEnemyVector.empty())
        {
            for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
            {
                if(deleteEnemyVector[0] == *it)
                {
                    delete(*it);
                    enemies.erase(it);
                    player.eraseLife();
                    deleteEnemyVector.erase(deleteEnemyVector.begin());
                    break;
                }
            }
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
        vector<Projectile*> deleteProjectileVector;
        for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
        {
            if((*it)->update(enemies, visualEffects, player))
            {
                deleteProjectileVector.push_back(*it);
            }

        }
        while(!deleteProjectileVector.empty())
        {
            for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
            {
                if(deleteProjectileVector[0] == *it)
                {
                    delete(*it);
                    projectiles.erase(it);
                    deleteProjectileVector.erase(deleteProjectileVector.begin());
                    break;
                }
            }
        }
        vector<VisualEffect*> deleteVisualEffectVector;

        for(vector<VisualEffect*>::iterator it = visualEffects.begin(); it != visualEffects.end(); ++it)
        {
            if((*it)->update())
            {
                deleteVisualEffectVector.push_back(*it);
            }

        }
        while(!deleteVisualEffectVector.empty())
        {
            for(vector<VisualEffect*>::iterator it = visualEffects.begin(); it != visualEffects.end(); ++it)
            {
                if(deleteVisualEffectVector[0] == *it)
                {
                    delete(*it);
                    visualEffects.erase(it);
                    deleteVisualEffectVector.erase(deleteVisualEffectVector.begin());
                    break;
                }
            }
        }


        // Update menus
        if(nextWaveMenu.update())
        {
            string message = nextWaveMenu.readState();
            if(message == "NEXTWAVE")
            {
                waves->startNextWave();
            }
        }

        if(player.getLife() <= 0)
        {
            visualEffects.push_back(new VisualEffect(300, 250, 0, 2, "gameover.png", 300, 300,
                                1, 100, false));
            done = true;
        }

        if(waves->waveDone() && enemies.empty())
        {
            if(waves->onLastWave() && waves->waveDone())
            {
                visualEffects.push_back(new VisualEffect(350, 350, 0, 2, "youwin.png", 250, 250,
                                1, 100, false));
                done = true;
            }
            else
            {
                visualEffects.push_back(new VisualEffect(500, 400, 0, 2, "wavedone.png", 300, 300,
                                1, 100, false));
            }
        }
    }
    nextWaveMenu.newIteration();
    if(statusBarMenu.update(waves->waveDone()&& enemies.empty()))
    {
        string message = statusBarMenu.readState();
        if(message == "SAVE")
        {
			if(waves->waveDone()&&enemies.empty())
			{
		        time_t secs;
		        struct tm * timeinfo;

		        time(&secs);//set time
		        timeinfo=localtime(&secs);//get time obj

		        std::stringstream fileName;
		        char timeString[80];
		    	fileName << LOADFOLDER << secs << ".sav";

		        saveLevel(fileName.str());


				strftime(timeString, 80, "%H:%M_%Y-%m-%d",timeinfo);
		        ofstream saveData;
				saveData.open(string(LOADFOLDER)+"/SaveData.dat", ios::app);
				if(saveData.is_open())
				{
					saveData << timeString << " " << secs << ".sav\n";
					saveData.close();
				}
				else
				{
					cout << "Error opening file." << endl;
				}

		        //state="START";//TODO visa att vi sparade
			}
			else
			{
				cout << "Can not save during wave." << endl;
			}
        }
        if(message == "QUIT")
        {
            cout << "Quiting" << endl;
            state="START";
        }
    }
    return true;
}

void Level::draw(sf::RenderWindow& canvas)
{
    canvas.draw(background);
	//map.draw(canvas);//For debuging
    // draw Tower
    for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
    {
        (*it)->drawSprite(canvas);
    }
    // draw Enemies
    for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
    {
        (*it)->drawSprite(canvas);
    }
    // draw projectiles
    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
    {
        (*it)->drawSprite(canvas);
    }
    for(vector<VisualEffect*>::iterator it = visualEffects.begin(); it != visualEffects.end(); ++it)
    {
        (*it)->drawSprite(canvas);
    }
    clickManager.update();
    clickManager.drawMenus(canvas);
    nextWaveMenu.drawMenu(canvas);
    statusBarMenu.drawMenu(canvas, player);
}

string Level::readState()
{
    string temp = state;
    state = "";
    return temp;
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
	cout << "Level" << " Level " << waves->getCurrentWaveIndex() << ","  << trackName << endl;
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

string Level::getSongName()
{
    return songName;
}

int Level::getCurrentLife()
{
    return player.getLife();
}
