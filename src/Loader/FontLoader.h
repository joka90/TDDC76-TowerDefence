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
     FontLoader();
     static void remove(const std::string& key);
     static void clear();
     static bool empty();
     static void load(const std::string& filename);
     static sf::Font& getFont(const std::string& key);
     static void print(); //debug
    private:
     static std::string directory;
     static std::map<std::string, sf::Font> fonts;
     static bool find(const std::string& key);
     static void insert(const std::string& key, sf::Font inFont);
};

#endif

