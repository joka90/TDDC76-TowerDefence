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
     void remove(const std::string& key);
     void clear();
     bool empty() const;
     void load(const std::string& filename);
     sf::Font& getFont(const std::string& key);
     void print() const; //debug
    private:
     std::map<std::string, sf::Font> fonts;
     bool find(const std::string& key) const;
     void insert(const std::string& key, sf::Font inFont);
};

#endif

