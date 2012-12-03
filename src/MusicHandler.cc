#include "MusicHandler.h"
#include <SFML/Audio.hpp>

#define totalFadeTime 3

using namespace std;

///Klass f�r att hantera musik

/*
* Spelar upp en s�ng genom att f�rst 'fadea ut' den f�reg�ende
* och sedan 'fadea in' den nya, tar in en pekare fr�n getMusic.
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
* Stoppar en s�ng(utan fade)
*/
void MusicHandler::stopSong(sf::Music* inSong)
{
    inSong->stop();
    return;
}

/*
* Kollar om en s�ng spelas upp
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
* Stoppar alla s�nger(utan fade)
*/
void MusicHandler::stopAllSongs()
{
    previousSong->stop();
    currentSong->stop();
    return;
}

/* �kar volymen p� en s�ng fr�n 0 till 100 under ett tidsintervall
* som best�ms av timeStep*100
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
* Minskar volymen p� en s�ng fr�n 100 till 0 under ett tidsintervall
* som best�ms av timeStep*100
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

