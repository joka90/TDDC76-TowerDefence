#include "ClassManager.h"
#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Towers/Tower.h"
#include "GameObjects/Towers/LongTower.h"

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
    if(towerTypeName != "")
    {
        cout << towerTypeName << endl;
    }
    if(towerTypeName == "BASIC")
    {
        return new LongTower(0, 0, 80, 10, 90, 30);
    }
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

