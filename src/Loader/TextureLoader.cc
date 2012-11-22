#include "TextureLoader.h"
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <iostream>

#define IMG "media/img/"

using namespace std;
///Klass f�r att ladda in texturer

/**
* Tillf�llig konstruktor, tar in ett directory och ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define IMAGEDIRECTORY "../media/img/"
* TextureLoader* test = new TextureLoader(IMAGEDIRECTORY,"apa.JPG")
* En referens till en textur kan sedan f�s ur map:en med funktionen getTexture, ex
* test->getTexture(IMAGEDIRECTORY,"apa.JPG")
* om filen inte finns inladdad s� laddas den in
*/
/*
* Konstruktor
*/
TextureLoader::TextureLoader()
{
    directory = IMG;
}

/*
* Laddar in en fil i map:en, tar in ett directory och namnet p� filen.
*/
void TextureLoader::load(const std::string& filename)
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
* Privat funktion, L�gger in texturen i map:en
*/
void TextureLoader::insert(const std::string& key, sf::Texture& inTexture)
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
bool TextureLoader::find(const std::string& key) const
{
    map<std::string, sf::Texture>::const_iterator it  = textures.find(key);
    return (it != textures.end());
}

/*
* Tar bort en textur fr�n map:en
*/
void TextureLoader::remove(const std::string& key)
{
   if(!find(key))
    {
    cout << "Removal of texture failed, texture doesn't exist" << endl;
    }
  textures.erase(key);
  return;
}

/*
* T�mmer map:en
*/
void TextureLoader::clear()
{
    textures.clear(); // fixa med pekare ist�llet blir det stora minnesl�ckor
}

/*
* Kollar om map:en �r tom
*/
bool TextureLoader::empty() const
{
    return(textures.empty());
}

/*
* Printar ut det alla keys i map:en, kan vara bra till debug
*/
void TextureLoader::print() const
{
    map<std::string, sf::Texture>::const_iterator pos;
    for(pos = textures.begin(); pos != textures.end(); ++pos)
        {
        cout << "Key: " << pos->first << endl;
        //cout << "Value:" << pos->second << endl;
        }
}

/*
* H�mtar ut en referens till en textur i map:en
*/
sf::Texture& TextureLoader::getTexture(const std::string& key)
{
    if(find(key))
    {
      return textures[key];
    }
  load(key);
  return textures[key];
}






