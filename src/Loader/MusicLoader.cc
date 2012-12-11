/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    MusicLoader.cc
 * Enhetsnamn: MusicLoader
 * Typ:        implementering
 * Skriven av: I. Junaeus
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar inladdning och lagring av musik för senare använding i programmet
 *
 */

#include "MusicLoader.h"
#include <SFML/Audio.hpp>

#include <map>
#include <string>
#include <iostream>

#define MUSIC "media/music/"

std::string MusicLoader::directory = MUSIC;
std::map<std::string, sf::Music*> MusicLoader::songs;
using namespace std;
///Klass för att ladda in musik

/**
* Tar in ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define MUSIC "path till filen"
* En referens till en sång kan sedan fås ur map:en med funktionen getMusic, ex
* MusicLoader::getMusic("apa.WAV")
* om filen inte finns inladdad så laddas den in och om en fil som inte finns
* försöker laddas in så sätts det in en tom textur istället.
*/
/*
* Konstruktor
*/
MusicLoader::MusicLoader()
{
    directory = MUSIC;
}

/*
* Laddar in en pekare till musik i map:en, tar in namnet på filen.
*/
void MusicLoader::load(const std::string& filename)
{
    if(find(filename))
    {
        return;
    }
    sf::Music* song = new sf::Music();
    if (!song->openFromFile(directory+filename))
    {
        cout << "Loading of song failed, empty song inserted instead." << endl;
        insert(filename, song);
        return;
    }
    insert(filename, song);
    return;
}

/*
* Privat funktion, Lägger in pekare till en sång i map:en
*/
void MusicLoader::insert(const std::string& key, sf::Music* inMusic)
{
    if(!find(key))
    {
      songs[key]=inMusic;
    }
  return;
}
/*
* Privat funktion, kollar om sången finns i map:en
*/
bool MusicLoader::find(const std::string& key)
{
    map<std::string, sf::Music*>::const_iterator it  = songs.find(key);
    return (it != songs.end());
}
/*
* Tar bort en sång från map:en
*/
void MusicLoader::remove(const std::string& key)
{
   if(!find(key))
    {
    cout << "Removal of music failed, soundbuffer doesn't exist" << endl;
    }
  songs.erase(key);
  return;
}
/*
* Tömmer map:en
*/
void MusicLoader::clear()
{
    songs.clear();
}

/*
* Kollar om map:en är tom
*/
bool MusicLoader::empty()
{
    return(songs.empty());
}
/*
* Printar ut det alla keys i map:en, kan vara bra till debug
*/
void MusicLoader::print()
{
    map<std::string, sf::Music*>::const_iterator pos;
    for(pos = songs.begin(); pos != songs.end(); ++pos)
        {
        cout << "Key: " << pos->first << endl;
        //cout << "Value:" << pos->second << endl;
        }
}
/*
* Hämtar ut en referens till en soundbuffer i map:en
*/
sf::Music* MusicLoader::getMusic(const std::string& key)
{
    if(find(key))
    {
      return songs[key];
    }
  load(key);
  return songs[key];
}






