#include "Level.h"

#define createObjectFromType(parm,type) if(parm==#type) {  \
tmpPtr=new type(); \
}

using namespace std;

Level::Level()
{

}

Level::Level(string filename)
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

void createObject(std::string type, std::string subType, std::string parms)
{
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


}

bool Level::update()
{
    /*
    // Update Tower
    for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
    {
        (*it).update();
    }
    // Update projectiles
    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
    {
        (*it).update();
    }
    */

}

void Level::draw(sf::RenderWindow& canvas)
{
    /*
    // draw Tower
    for(vector<Tower*>::iterator it = towers.begin(); it != towers.end(); ++it)
    {
        (*it).drawSprite(canvas);
    }
    // draw projectiles
    for(vector<Projectile*>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
    {
        (*it).drawSprite(canvas);
    }
    */
}

void Level::runWave()
{

}

void Level::saveMap()
{


}
