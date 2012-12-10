/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    SoundLoader.cc
 * Enhetsnamn: SoundLoader
 * Typ:        implementering
 * Skriven av: I. Junaeus
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar inladdning och lagring av ljudeffekter f�r senare anv�nding i programmet
 *
 */

#include "SoundLoader.h"
#include <SFML/Audio.hpp>

#include <map>
#include <string>
#include <iostream>

#define SOUND "media/sound/"

std::string SoundLoader::directory = SOUND;
std::map<std::string, sf::SoundBuffer> SoundLoader::sounds;

using namespace std;
///Statisk klass f�r att ladda in sounds

/**
* Tar in ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define SOUND "path till filen"
* En referens till en soundbuffer kan sedan f�s ur map:en med funktionen getSoundBuffer, ex
* SoundLoader::getSoundBuffer("apa.WAV")
* om filen inte finns inladdad s� laddas den in och om en fil som inte finns
* f�rs�ker laddas in s� s�tts det in en tom textur ist�llet.
*/
/*
* Konstruktor
*/
SoundLoader::SoundLoader()
{
    directory = SOUND;
}

/*
* Laddar in en fil i map:en, tar in namnet p� filen.
*/
void SoundLoader::load(const std::string& filename)
{
    if(find(filename))
    {
        return;
    }
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile(directory+filename))
    {
        cout << "Loading of Soundbuffer failed, empty soundbuffer inserted instead." << endl;
        insert(filename, buffer);
        return;
    }
    insert(filename, buffer);
    return;
}

/*
* Privat funktion, L�gger in soundbuffer i map:en
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
bool SoundLoader::find(const std::string& key)
{
    map<std::string, sf::SoundBuffer>::const_iterator it  = sounds.find(key);
    return (it != sounds.end());
}
/*
* Tar bort en soundbuffer fr�n map:en
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
* T�mmer map:en
*/
void SoundLoader::clear()
{
    sounds.clear();
}

/*
* Kollar om map:en �r tom
*/
bool SoundLoader::empty()
{
    return(sounds.empty());
}
/*
* Printar ut det alla keys i map:en, kan vara bra till debug
*/
void SoundLoader::print()
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
sf::SoundBuffer& SoundLoader::getSoundBuffer(const std::string& key)
{
    if(find(key))
    {
      return sounds[key];
    }
  load(key);
  return sounds[key];
}






