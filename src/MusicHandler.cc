#include "MusicHandler.h"
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;

///Klass f�r att hantera musik

/*
* Spelar upp en s�ng genom att f�rst 'fadea ut' den f�reg�ende
* och sedan spela upp den nya.
*/

/*
* initierar startv�rden
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
* m�jlig status f�r en s�ng:
* playing, waitingToPlay, stopped, fading.
* Fadear ut s�nger med statusen "fading" och b�rjar spela upp n�sta s�ng n�r previousS�ng inte spelas l�ngre
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
* S�tter currentSong till den s�ng som ska spelas och g�r s� att update() kan fadea ut den gamla s�ngen
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
* Spelar upp en s�ng med loop, anv�nds enbart f�r att starta den f�rsta s�ngen
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
* Stoppar en s�ng
*/
void MusicHandler::stopSong(sf::Music* inSong)
{
    inSong->stop();
    return;
}


/*
* Stoppar alla s�nger
*/
void MusicHandler::stopAllSongs()
{
    previousSong->stop();
    currentSong->stop();
    return;
}

/*
* Kan �ndra pitch p� nuvarande s�ng om livet �r l�gt, anv�nds ev. inte
*/

void MusicHandler::increasePitch()
{
    currentSong->setPitch(currentSong->getPitch() + 0.01);
}



