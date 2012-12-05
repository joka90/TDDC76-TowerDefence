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
        return new LongTower(0, 0);
    }
    return NULL;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
Enemy* ClassManager::createEnemyInstance(const string& enemyTypeName)
{
    if(enemyTypeName == "Badger"){
            return new Enemy(100,2,500, "/Sprites/Badger/Gray/badger_01_small.png");
    }
    return NULL;
}

