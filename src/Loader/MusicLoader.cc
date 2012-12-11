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
 * Denna modul hanterar inladdning och lagring av musik f�r senare anv�nding i programmet
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
///Klass f�r att ladda in musik

/**
* Tar in ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define MUSIC "path till filen"
* En referens till en s�ng kan sedan f�s ur map:en med funktionen getMusic, ex
* MusicLoader::getMusic("apa.WAV")
* om filen inte finns inladdad s� laddas den in och om en fil som inte finns
* f�rs�ker laddas in s� s�tts det in en tom textur ist�llet.
*/
/*
* Konstruktor
*/
MusicLoader::MusicLoader()
{
    directory = MUSIC;
}

/*
* Laddar in en pekare till musik i map:en, tar in namnet p� filen.
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
* Privat funktion, L�gger in pekare till en s�ng i map:en
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
* Privat funktion, kollar om s�ngen finns i map:en
*/
bool MusicLoader::find(const std::string& key)
{
    map<std::string, sf::Music*>::const_iterator it  = songs.find(key);
    return (it != songs.end());
}
/*
* Tar bort en s�ng fr�n map:en
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
* T�mmer map:en
*/
void MusicLoader::clear()
{
    songs.clear();
}

/*
* Kollar om map:en �r tom
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
* H�mtar ut en referens till en soundbuffer i map:en
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






