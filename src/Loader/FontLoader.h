/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    FontLoader.cc
 * Enhetsnamn: FontLoader
 * Typ:        implementering
 * Skriven av: I. Junaeus
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar inladdning och lagring av fonts för senare använding i programmet
 *
 */

#ifndef FONTLOADER
#define FONTLOADER

#include "Loader.h"
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <iostream>

class FontLoader : public Loader
{
    public:
     // Konstruktor. Behövs ej då denna klass är statisk
     FontLoader();

     // Tar bort en font
     static void remove(const std::string& key);

     // Tar bort alla laddade fonter
     static void clear();

     // Returnerar om denna loader är tom
     static bool empty();

     // Laddar in en ny font med det givna filnamnet
     static void load(const std::string& filename);

     // Returnerar en inladdad SFML-font med en given nyckel
     static sf::Font& getFont(const std::string& key);

     // DEBUG
     static void print();

    private:

     // Medlemsfunktioner.
     static std::string directory;
     static std::map<std::string, sf::Font> fonts;
     static bool find(const std::string& key);
     static void insert(const std::string& key, sf::Font inFont);
};

#endif

