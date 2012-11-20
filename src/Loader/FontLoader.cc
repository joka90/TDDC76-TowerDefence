#include "FontLoader.h"
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <iostream>

using namespace std;
///Klass för att ladda in texturer

/**
* Tillfällig konstruktor, tar in ett directory och ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define IMAGEDIRECTORY "../media/img/"
* FontLoader* test = new FontLoader(IMAGEDIRECTORY,"apa.JPG")
* En referens till en textur kan sedan fås ur map:en med funktionen getTexture, ex
* test->getTexture(IMAGEDIRECTORY,"apa.JPG")
* om filen inte finns inladdad så laddas den in
*/
/*
* Konstruktor
*/
FontLoader::FontLoader(const std::string directory, const std::string filename)
{
     load(directory, filename);
}

/*
* Laddar in en fil i map:en, tar in ett directory och namnet på filen.
*/
void FontLoader::load(const std::string& directory, const std::string& filename)
{
    if(find(filename))
    {
        return;
    }
    sf::Texture texture;
    if (!texture.loadFromFile(directory+filename))
    {
        cout << "Loading of texture failed" << endl;
        return;
    }
    insert(filename, texture);
    return;
}

/*
* Privat funktion, Lägger in texturen i map:en
*/
void FontLoader::insert(const std::string& key, sf::Texture inTexture)
{
    if(!find(key))
    {
      textures[key]=inTexture;
    }
  return;
}

/*
* Privat funktion, kollar om texturen finns i map:en
*/
bool FontLoader::find(const std::string& key) const
{
    map<std::string, sf::Texture>::const_iterator it  = textures.find(key);
    return (it != textures.end());
}

/*
* Tar bort en textur från map:en
*/
void FontLoader::remove(const std::string& key)
{
   if(!find(key))
    {
    cout << "Removal of texture failed, texture doesn't exist" << endl;
    }
  textures.erase(key);
  return;
}

/*
* Tömmer map:en
*/
void FontLoader::clear()
{
    textures.clear();
}

/*
* Kollar om map:en är tom
*/
bool FontLoader::empty() const
{
    return(textures.empty());
}

/*
* Printar ut det alla keys i map:en, kan vara bra till debug
*/
void FontLoader::print() const
{
    map<std::string, sf::Texture>::const_iterator pos;
    for(pos = textures.begin(); pos != textures.end(); ++pos)
        {
        cout << "Key: " << pos->first << endl;
        //cout << "Value:" << pos->second << endl;
        }
}

/*
* Hämtar ut en referens till en textur i map:en
*/
sf::Texture& FontLoader::getTexture(const std::string directory, const std::string& key)
{
    if(find(key))
    {
      return textures[key];
    }
  load(directory, key);
  return textures[key];
}






