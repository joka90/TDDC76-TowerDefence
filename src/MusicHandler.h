#ifndef MUSICHANDLER
#define MUSICHANDLER

#include <SFML/Audio.hpp>

class MusicHandler
{
 public:
  void playSong(sf::Music* inSong);
  void stopSong(sf::Music* inSong);
  bool isSongPlaying(const sf::Music* inSong) const;
  void stopAllSongs();
 private:
  void fadeInSong(sf::Music* inSong);
  void fadeOutSong(sf::Music* inSong);
  sf::Music* currentSong;
  sf::Music* previousSong;
};

#endif



