#ifndef CLASSMANAGER_H
#define CLASSMANAGER_H

#include "GameObjects/Enemies/Enemy.h"
#include "GameObjects/Towers/Tower.h"

class ClassManager
{
    public:
        ClassManager();
        virtual ~ClassManager();

        static Enemy* createEnemyInstance(const std::string& enemyTypeName);

        static Tower* createTowerInstance(const std::string& towerTypeName);

};

#endif // CLASSMANAGER_H
