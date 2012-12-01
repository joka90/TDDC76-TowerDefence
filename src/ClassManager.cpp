#include "ClassManager.h"
#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Towers/Tower.h"

using namespace std;

ClassManager::ClassManager()
{
    //ctor
}

ClassManager::~ClassManager()
{
    //dtor
}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
Tower* ClassManager::createTowerInstance(const string& towerTypeName)
{
    return NULL;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
Enemy* ClassManager::createEnemyInstance(const string& enemyTypeName)
{
    //switch(enemyTypeName){

        //case "MegaTower":
            //return new MegaTower();
        //default:
            //throw
    //}
    return NULL;
}

