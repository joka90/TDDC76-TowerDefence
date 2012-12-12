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
 * Denna modul hanterar inladdning och lagring av musik f�r senare anv�nding i programmet
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
     // Konstruktor. Beh�vs ej d� denna klass �r statisk
     MusicLoader();

     // Tar bort en l�t
     static void remove(const std::string& key);

     // Tar bort alla l�tar
     static void clear();

     // Returnerar om denna loader �r tom
     static bool empty();

     // Laddar in en ny l�t med det givna filnamnet
     static void load(const std::string& filename);

     // Returnerar en inladdad SFML-l�t med en given nyckel
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
