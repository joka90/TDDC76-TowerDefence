/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    FontLoader.cc
 * Enhetsnamn: FontLoader
 * Typ:        implementering
 * Skriven av: I. Junaeus
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar inladdning och lagring av fonts f�r senare anv�nding i programmet
 *
 */

#include "FontLoader.h"
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <iostream>

#define FONTS "media/font/"

using namespace std;
///Klass f�r att ladda in fonter

/**
* Tar in ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define FONTS "path till filen"
* En referens till en font kan sedan f�s ur map:en med funktionen getFont, ex
* FontLoader::getFont("apa.TTF")
* om filen inte finns inladdad s� laddas den in och om en fil som inte finns
* f�rs�ker laddas in s� s�tts det in en tom textur ist�llet.
*/
/*
* Konstruktor
*/

std::string FontLoader::directory = FONTS;
std::map<std::string, sf::Font> FontLoader::fonts;

FontLoader::FontLoader()
{
    directory = FONTS;
}

/*
* Laddar in en fil i map:en, tar in namnet p� filen.
*/
void FontLoader::load(const std::string& filename)
{
    if(find(filename))
    {
        return;
    }
    sf::Font font;
    if (!font.loadFromFile(directory+filename))
    {

        cout << "Loading of font failed, empty font inserted instead." << endl;
        insert(filename, font);
        return;
    }
    insert(filename, font);
    return;
}

/*
* Privat funktion, L�gger in fonten i map:en
*/
void FontLoader::insert(const std::string& key, sf::Font inFont)
{
    if(!find(key))
    {
      fonts[key]=inFont;
    }
  return;
}

/*
* Privat funktion, kollar om fonten finns i map:en
*/
bool FontLoader::find(const std::string& key)
{
    map<std::string, sf::Font>::const_iterator it  = fonts.find(key);
    return (it != fonts.end());
}

/*
* Tar bort en font fr�n map:en
*/
void FontLoader::remove(const std::string& key)
{
   if(!find(key))
    {
    cout << "Removal of font failed, font doesn't exist" << endl;
    }
  fonts.erase(key);
  return;
}

/*
* T�mmer map:en
*/
void FontLoader::clear()
{
    fonts.clear();
}

/*
* Kollar om map:en �r tom
*/
bool FontLoader::empty()
{
    return(fonts.empty());
}

/*
* Printar ut alla keys i map:en, kan vara bra till debug
*/
void FontLoader::print()
{
    map<std::string, sf::Font>::const_iterator pos;
    for(pos = fonts.begin(); pos != fonts.end(); ++pos)
        {
        cout << "Key: " << pos->first << endl;
        //cout << "Value:" << pos->second << endl;
        }
}

/*
* H�mtar ut en referens till en font i map:en
*/
sf::Font& FontLoader::getFont(const std::string& key)
{
    if(find(key))
    {
      return fonts[key];
    }
  load(key);
  return fonts[key];
}






