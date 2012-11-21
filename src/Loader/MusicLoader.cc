#include "MusicLoader.h"
#include <SFML/Audio.hpp>

#include <map>
#include <string>
#include <iostream>

#define MUSIC "media/music/"

using namespace std;
///Klass f�r att ladda in sounds

/**
* Tillf�llig konstruktor, tar in ett directory och ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define SOUNDDIRECTORY "../media/sounds/"
* MusicLoader* test = new MusicLoader(SOUNDDIRECTORY,"poff.WAV")
* En referens till en Soundbuffer kan sedan f�s ur map:en med funktionen getSoundBuffer, ex
* test->getSoundBuffer(SOUNDDIRECTORY,"poff.WAV")
* om filen inte finns inladdad s� laddas den in
*/
/*
* Konstruktor
*/
MusicLoader::MusicLoader()
{
    directory = MUSIC;
}

/*
* Laddar in en fil i map:en, tar in ett directory och namnet p� filen.
*/
void MusicLoader::load(const std::string& filename)
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
* Privat funktion, L�gger in soundbuffer i map:en
*/
void MusicLoader::insert(const std::string& key, sf::SoundBuffer inSoundBuffer)
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
bool MusicLoader::find(const std::string& key) const
{
    map<std::string, sf::SoundBuffer>::const_iterator it  = sounds.find(key);
    return (it != sounds.end());
}
/*
* Tar bort en soundbuffer fr�n map:en
*/
void MusicLoader::remove(const std::string& key)
{
   if(!find(key))
    {
    cout << "Removal of soundbuffer failed, soundbuffer doesn't exist" << endl;
    }
  sounds.erase(key);
  return;
}
/*
* T�mmer map:en
*/
void MusicLoader::clear()
{
    sounds.clear();
}

/*
* Kollar om map:en �r tom
*/
bool MusicLoader::empty() const
{
    return(sounds.empty());
}
/*
* Printar ut det alla keys i map:en, kan vara bra till debug
*/
void MusicLoader::print() const
{
    map<std::string, sf::SoundBuffer>::const_iterator pos;
    for(pos = sounds.begin(); pos != sounds.end(); ++pos)
        {
        cout << "Key: " << pos->first << endl;
        //cout << "Value:" << pos->second << endl;
        }
}
/*
* H�mtar ut en referens till en soundbuffer i map:en
*/
sf::SoundBuffer& MusicLoader::getSoundBuffer(const std::string& key)
{
    if(find(key))
    {
      return sounds[key];
    }
  load(key);
  return sounds[key];
}






