#ifndef SOUNDLOADER
#define SOUNDLOADER

#include "Loader.h"
#include <SFML/Audio.hpp>

#include <map>
#include <string>
#include <iostream>

class SoundLoader : public Loader
{
    public:
     SoundLoader();
     static void remove(const std::string& key);
     static void clear();
     static bool empty();
     static void load(const std::string& filename);
     static sf::SoundBuffer& getSoundBuffer(const std::string& key);
     static void print(); //debug*/
    private:
     static std::string directory;
     static std::map<std::string, sf::SoundBuffer> sounds;
     static bool find(const std::string& key);
     static void insert(const std::string& key, sf::SoundBuffer inSoundBuffer);
};

#endif
