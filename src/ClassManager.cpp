#include "ClassManager.h"
#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Towers/Tower.h"
#include "GameObjects/Towers/LongTower.h"
#include "GameObjects/Towers/CannonTower.h"

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
    if(towerTypeName == "LONG")
    {
        return new LongTower(0, 0);
    }
    if(towerTypeName == "CANNON")
    {
        return new CannonTower(0,0);
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
            return new Enemy(10,1,20, "/Sprites/Badger/Gray/badger_01_smallani.png", 50, 50, 2, 5);
    }else if(enemyTypeName == "RedBadger"){
            return new Enemy(20,1,30, "/Sprites/Badger/Red/badger_02_smallani.png", 50, 50, 2, 5);
    }else if(enemyTypeName == "BlueBadger"){
            return new Enemy(30,2,50, "/Sprites/Badger/Blue/badger_01_smallani.png", 50, 50, 2, 5);
    }
    return NULL;
}

