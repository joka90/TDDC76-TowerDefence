#include "FontLoader.h"
#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <iostream>

#define FONTS "media/font/"

using namespace std;
///Klass för att ladda in fonter

/**
* Tillfällig konstruktor, tar in ett directory och ett filnamn och laddar sedan in
* filen i en map ex:
*
* #define FONTDIRECTORY "../media/fonts/"
* FontLoader* test = new FontLoader(FONTDIRECTORY,"arial.ttf")
* En referens till en font kan sedan fås ur map:en med funktionen getFont, ex
* test->getFont(FONTDIRECTORY,"arial.ttf")
* om filen inte finns inladdad så laddas den in
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
* Laddar in en fil i map:en, tar in ett directory och namnet på filen.
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

        cout << "Loading of font failed" << endl;
        return;
    }
    insert(filename, font);
    return;
}

/*
* Privat funktion, Lägger in fonten i map:en
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
* Tar bort en font från map:en
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
* Tömmer map:en
*/
void FontLoader::clear()
{
    fonts.clear();
}

/*
* Kollar om map:en är tom
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
* Hämtar ut en referens till en font i map:en
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






