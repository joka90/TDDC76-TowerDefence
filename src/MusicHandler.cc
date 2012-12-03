#include "MusicHandler.h"
#include <SFML/Audio.hpp>

#define totalFadeTime 3

using namespace std;

///Klass för att hantera musik

/*
* Spelar upp en sång genom att först 'fadea ut' den föregående
* och sedan 'fadea in' den nya, tar in en pekare från getMusic.
*/
void MusicHandler::playSong(sf::Music* inSong)
{
    if(isSongPlaying(inSong))
    {
        return;
    }
    previousSong = currentSong;
    currentSong = inSong;
    fadeOutSong(previousSong);
    fadeInSong(currentSong);
    return;
}

/*
* Stoppar en sång(utan fade)
*/
void MusicHandler::stopSong(sf::Music* inSong)
{
    inSong->stop();
    return;
}

/*
* Kollar om en sång spelas upp
*/
bool MusicHandler::isSongPlaying(const sf::Music* inSong) const
{
    if(inSong->getStatus() == sf::SoundSource::Playing)
    {
        return true;
    }
    return false;
}

/*
* Stoppar alla sånger(utan fade)
*/
void MusicHandler::stopAllSongs()
{
    previousSong->stop();
    currentSong->stop();
    return;
}

/* Ökar volymen på en sång från 0 till 100 under ett tidsintervall
* som bestäms av timeStep*100
*/
void MusicHandler::fadeInSong(sf::Music* inSong)
{
    if((inSong == NULL) || (isSongPlaying(inSong)))
    {
        return;
    }
    inSong->setVolume(0);
    inSong->play();
    inSong->setLoop(true);
    int currentVolume = inSong->getVolume();
    sf::Time timeStep = sf::seconds(0.03);
    sf::Clock clock;
    while(currentVolume < 100)
    {
        if(clock.getElapsedTime() >= timeStep)
        {
            inSong->setVolume(currentVolume+1);
            clock.restart();
        }
    }
     return;
}

/*
* Minskar volymen på en sång från 100 till 0 under ett tidsintervall
* som bestäms av timeStep*100
*/
void MusicHandler::fadeOutSong(sf::Music* inSong)
{
    if((inSong == NULL) || (!isSongPlaying(inSong)))
    {
        return;
    }
    int currentVolume = inSong->getVolume();
    sf::Time timeStep = sf::seconds(0.03);
    sf::Clock clock;
    while(currentVolume > 0)
    {
        if(clock.getElapsedTime() >= timeStep)
        {
            inSong->setVolume(currentVolume-1);
            clock.restart();
        }
    }
    inSong->stop();
    return;
}

