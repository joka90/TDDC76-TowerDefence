#ifndef CLASSMANAGER_H
#define CLASSMANAGER_H

#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Towers/Tower.h"

class ClassManager
{
    public:
        ClassManager();
        virtual ~ClassManager();

        static Enemy* createEnemyInstance(std::string enemyTypeName);

        static Tower* createTowerInstance(std::string towerTypeName);

};

#endif // CLASSMANAGER_H
