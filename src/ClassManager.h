/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    ClassManager.h
 * Enhetsnamn: ClassManager
 * Typ:        implementering
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten för saker som skall ha koordinater och skall ritas ut på spelplanen
 *
 */

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
    private:
};

#endif // CLASSMANAGER_H
