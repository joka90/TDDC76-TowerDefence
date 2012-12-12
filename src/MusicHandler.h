/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    MusicHandler.cc
 * Enhetsnamn: MusicHandler
 * Typ:        implementering
 * Skriven av: I. Junaeus
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar uppspelning av musik osv.
 *
 */
#ifndef MUSICHANDLER
#define MUSICHANDLER

#include <SFML/Audio.hpp>

class MusicHandler
{
 public:
  MusicHandler();
  void update();
  void playSong(sf::Music* inSong);
  void stopSong(sf::Music* inSong);
  void stopAllSongs();
  void setCurrentSong(sf::Music* inSong);
  void increasePitch();
 private:
  sf::Music* currentSong;
  sf::Music* previousSong;
  std::string currentSongStatus;
  std::string previousSongStatus;
};

#endif



