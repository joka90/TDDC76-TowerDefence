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
<<<<<<< HEAD
            return new Enemy(100,2,50, "/Sprites/Badger/Gray/badger_01_small.png");
=======
            return new Enemy(50,2,500, "/Sprites/Badger/Gray/badger_01_smallani.png", 50, 50, 2, 5);
    }
    if(enemyTypeName == "RedBadger"){
            return new Enemy(15000,1,500, "/Sprites/Badger/Gray/badger_02_smallani.png", 50, 50, 2, 5);
>>>>>>> c6889b922f5b63a887dcc90a9ee182557417d833
    }
    return NULL;
}

