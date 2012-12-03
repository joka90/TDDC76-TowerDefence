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

