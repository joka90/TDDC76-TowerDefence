#include "MusicHandler.h"
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;

///Klass för att hantera musik

/*
* Spelar upp en sång genom att först 'fadea ut' den föregående
* och sedan spela upp den nya.
*/

/*
* initierar startvärden
*/
MusicHandler::MusicHandler()
{
    previousSong = NULL;
    currentSong = NULL;
    previousSongStatus = "stopped";
    currentSongStatus = "stopped";
    currentLife = NULL;
    nextLife = NULL;
    return;
}

/*
* möjlig status för en sång:
* playing, waitingToPlay, stopped, fading.
* Fadear ut sånger med statusen "fading" och börjar spela upp nästa sång när previousSång inte spelas längre
*/
void MusicHandler::update()
{
    if(currentSongStatus == "playing")
    {
        return;
    }
    if(previousSongStatus == "fading")
    {
        sf::Time timeStep = sf::seconds(0.0025);
        sf::Clock clock;
        while(clock.getElapsedTime() <= timeStep)
        {}
        previousSong->setVolume(previousSong->getVolume()-1);
        clock.restart();
        if(previousSong->getVolume() <= 1)
        {
            previousSong->stop();
            previousSongStatus = "stopped";
        }
    }
    if(previousSongStatus == "stopped")
    {
        if(currentSongStatus != "playing")
        {
            if(currentSong->getVolume() != 100)
            {
                currentSong->setVolume(100);
            }
            currentSong->setLoop(true);
            currentSong->play();
            currentSongStatus = "playing";
        }
    }
    return;
}

/*
* Sätter currentSong till den sång som ska spelas och gör så att update() kan fadea ut den gamla sången
*/
void MusicHandler::setCurrentSong(sf::Music* inSong)
{
    if(currentSong == inSong)
    {
        return;
    }
    previousSong = currentSong;
    currentSong = inSong;
    previousSongStatus = "fading";
    currentSongStatus = "waitingToPlay";
    return;
}

/*
* Spelar upp en sång med loop, används enbart för att starta den första sången
*/
void MusicHandler::playSong(sf::Music* inSong)
{
    currentSong = inSong;
    currentSongStatus = "playing";
    currentSong->setLoop(true);
    currentSong->play();
    return;
}

/*
* Stoppar en sång
*/
void MusicHandler::stopSong(sf::Music* inSong)
{
    inSong->stop();
    return;
}


/*
* Stoppar alla sånger
*/
void MusicHandler::stopAllSongs()
{
    previousSong->stop();
    currentSong->stop();
    return;
}

/*
* Kan ändra pitch på nuvarande sång om livet är lågt, används ev. inte
*/

void MusicHandler::increasePitch()
{
    currentSong->setPitch(currentSong->getPitch() + 0.01);
}



