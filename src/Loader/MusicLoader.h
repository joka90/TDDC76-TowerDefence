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
     // Konstruktor. Behövs ej då denna klass är statisk
     MusicLoader();

     // Tar bort en låt
     static void remove(const std::string& key);

     // Tar bort alla låtar
     static void clear();

     // Returnerar om denna loader är tom
     static bool empty();

     // Laddar in en ny låt med det givna filnamnet
     static void load(const std::string& filename);

     // Returnerar en inladdad SFML-låt med en given nyckel
     static sf::Music* getMusic(const std::string& key);

     // DEBUG
     static void print();
    private:

     // Medlemsfunktioner.
     static std::string directory;
     static std::map<std::string, sf::Music*> songs;
     static bool find(const std::string& key);
     static void insert(const std::string& key, sf::Music* inMusic);
};

#endif
