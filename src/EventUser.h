/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    EventUser.h
 * Enhetsnamn: EventUser
 * Typ:        implementering
 * Skriven av: D. Molin
 *
 *
 * BESKRIVNING
 *
 * Denna modul implementerar basfunktionaliteten för saker som skall ha koordinater och skall ritas ut på spelplanen
 *
 */
#ifndef EVENTUSER_H
#define EVENTUSER_H

#include <SFML/Graphics.hpp>

class EventUser
{
};

class MouseButtonPressedUser : public EventUser
{
    public:
        virtual void mouseButtonPressedListener(sf::Event) = 0;
};

class MouseButtonReleasedUser : public EventUser
{
    public:
        virtual void mouseButtonReleasedListener(sf::Event) = 0;
};

class MouseMovedUser : public EventUser
{
    public:
        virtual void mouseMoveListener(sf::Event) = 0;
};

class ClosedUser : public EventUser
{
    public:
        virtual void closedListener(sf::Event) = 0;
};

class KeyPressedUser : public EventUser
{
    public:
        virtual void keyPressedListener(sf::Event);
};

class KeyReleasedUser : public EventUser
{
    public:
        virtual void keyReleasedListener(sf::Event) = 0;
};

#endif // EVENTUSER_H
