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
     // Konstruktor. Behövs ej då denna klass är statisk
     TextureLoader();

     // Tar bort en font
     static void remove(const std::string& key);

     // Tar bort alla laddade fonter
     static void clear();

     // Returnerar om denna loader är tom
     static bool empty();

     // Laddar in en ny font med det givna filnamnet
     static void load(const std::string& filename);

     // Returnerar en inladdad SFML-font med en given nyckel
     static sf::Texture& getTexture(const std::string& key);

     static void print(); //debug
    private:

     // Medlemsfunktioner.
     static std::string directory;
     static std::map<std::string, sf::Texture> textures;
     static bool find(const std::string& key);
     static void insert(const std::string& key, sf::Texture& inTexture);
};

#endif

