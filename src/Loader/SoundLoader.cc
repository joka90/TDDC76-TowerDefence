#include "SoundLoader.h"
#include <SFML/Audio.hpp>

#include <map>
#include <string>
#include <iostream>

using namespace std;
///Klass för att ladda in sounds

/**
* Tillfällig konstruktor, tar in ett directory och ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define SOUNDDIRECTORY "../media/sounds/"
* SoundLoader* test = new SoundLoader(SOUNDDIRECTORY,"poff.WAV")
* En referens till en Soundbuffer kan sedan fås ur map:en med funktionen getSoundBuffer, ex
* test->getSoundBuffer(SOUNDDIRECTORY,"poff.WAV")
* om filen inte finns inladdad så laddas den in
*/
/*
* Konstruktor
*/
SoundLoader::SoundLoader(const std::string directory, const std::string filename)
{
    load(directory, filename);
}

/*
* Laddar in en fil i map:en, tar in ett directory och namnet på filen.
*/
void SoundLoader::load(const std::string& directory, const std::string& filename)
{
    if(find(filename))
    {
        return;
    }
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(directory+filename))
    {
        cout << "Loading of Soundbuffer failed" << endl;
        return;
    }
    insert(filename, buffer);
    return;
}

/*
* Privat funktion, Lägger in soundbuffer i map:en
*/
void SoundLoader::insert(const std::string& key, sf::SoundBuffer inSoundBuffer)
{
    if(!find(key))
    {
      sounds[key]=inSoundBuffer;
    }
  return;
}
/*
* Privat funktion, kollar om soundbuffern finns i map:en
*/
bool SoundLoader::find(const std::string& key) const
{
    map<std::string, sf::SoundBuffer>::const_iterator it  = sounds.find(key);
    return (it != sounds.end());
}
/*
* Tar bort en soundbuffer från map:en
*/
void SoundLoader::remove(const std::string& key)
{
   if(!find(key))
    {
    cout << "Removal of soundbuffer failed, soundbuffer doesn't exist" << endl;
    }
  sounds.erase(key);
  return;
}
/*
* Tömmer map:en
*/
void SoundLoader::clear()
{
    sounds.clear();
}

/*
* Kollar om map:en är tom
*/
bool SoundLoader::empty() const
{
    return(sounds.empty());
}
/*
* Printar ut det alla keys i map:en, kan vara bra till debug
*/
void SoundLoader::print() const
{
    map<std::string, sf::SoundBuffer>::const_iterator pos;
    for(pos = sounds.begin(); pos != sounds.end(); ++pos)
        {
        cout << "Key: " << pos->first << endl;
        //cout << "Value:" << pos->second << endl;
        }
}
/*
* Hämtar ut en referens till en soundbuffer i map:en
*/
sf::SoundBuffer& SoundLoader::getSoundBuffer(const std::string directory, const std::string& key)
{
    if(find(key))
    {
      return sounds[key];
    }
  load(directory, key);
  return sounds[key];
}






