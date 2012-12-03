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

/*
* Konstruktor
*/
MusicLoader::MusicLoader()
{
    directory = MUSIC;
}

/*
* Laddar in en pekare till musik i map:en, tar in ett directory och namnet p� filen.
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
        delete song;
        cout << "Loading of song failed" << endl;
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






