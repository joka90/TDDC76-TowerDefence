#ifndef TEXTURELOADER
#define TEXTURELOADER

#include "Loader.h"
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <iostream>

class TextureLoader : public Loader
{
    public:
     TextureLoader();
     static void remove(const std::string& key);
     static void clear();
     static bool empty();
     static void load(const std::string& filename);
     static sf::Texture& getTexture(const std::string& key);
     static void print(); //debug
    private:
     static std::string directory;
     static std::map<std::string, sf::Texture> textures;
     static bool find(const std::string& key);
     static void insert(const std::string& key, sf::Texture& inTexture);
};

#endif

