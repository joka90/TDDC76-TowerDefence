#ifndef LOADER
#define LOADER

#include <SFML/Graphics.hpp>

#include <map>
#include <string>
#include <iostream>



class Loader
{
 public:
  virtual void load(const std::string& directory, const std::string& filename) = 0;
  virtual void remove (const std::string& key) = 0;
  virtual void clear() = 0;
  virtual bool empty() const = 0;
protected:
  virtual bool find(const std::string& key) const = 0;
  //virtual void insert(const std::string& key, sf::Texture inTexture) = 0;
};

#endif


