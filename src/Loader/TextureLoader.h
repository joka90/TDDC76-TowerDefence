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
     void remove(const std::string& key);
     void clear();
     bool empty() const;
     void load(const std::string& directory, const std::string& filename);
     sf::Texture& getTexture(const std::string directory, const std::string& key);
     void print() const; //debug
    private:
     std::map<std::string, sf::Texture> textures;
     bool find(const std::string& key) const;
     void insert(const std::string& key, sf::Texture inTexture);
};

#endif

