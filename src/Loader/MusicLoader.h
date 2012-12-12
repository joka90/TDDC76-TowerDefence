/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    MusicLoader.cc
 * Enhetsnamn: MusicLoader
 * Typ:        implementering
 * Skriven av: I. Junaeus
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar inladdning och lagring av musik för senare använding i programmet
 *
 */

#ifndef MUSICLOADER_H
#define MUSICLOADER_H

#include "Loader.h"
#include <SFML/Audio.hpp>

#include <map>
#include <string>
#include <iostream>

class MusicLoader : public Loader
{
    public:
     MusicLoader();
     static void remove(const std::string& key);
     static void clear();
     static bool empty();
     static void load(const std::string& filename);
     static sf::Music* getMusic(const std::string& key);
     static void print(); //debug*/
    private:
     static std::string directory;
     static std::map<std::string, sf::Music*> songs;
     static bool find(const std::string& key);
     static void insert(const std::string& key, sf::Music* inMusic);
};

#endif
