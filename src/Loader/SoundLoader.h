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
     void remove(const std::string& key);
     void clear();
     bool empty() const;
     void load(const std::string& filename);
     sf::SoundBuffer& getSoundBuffer(const std::string& key);
     void print() const; //debug*/
    private:
     std::map<std::string, sf::SoundBuffer> sounds;
     bool find(const std::string& key) const;
     void insert(const std::string& key, sf::SoundBuffer inSoundBuffer);
};

#endif
