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
     MusicLoader(const std::string directory, const std::string filename);
     void remove(const std::string& key);
     void clear();
     bool empty() const;
     void load(const std::string& directory, const std::string& filename);
     sf::SoundBuffer& getSoundBuffer(const std::string directory, const std::string& key);
     void print() const; //debug*/
    private:
     std::map<std::string, sf::SoundBuffer> sounds;
     bool find(const std::string& key) const;
     void insert(const std::string& key, sf::SoundBuffer inSoundBuffer);
};

#endif
