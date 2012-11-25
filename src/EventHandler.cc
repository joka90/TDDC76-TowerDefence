#include "EventHandler.h"
#include <iostream>

using namespace std;
EventHandler::EventHandler()
{

}

    static std::vector<ClosedUser*> closedHandlers;
    static std::vector<KeyPressedUser*> keyPressedHandlers;
    static std::vector<KeyReleasedUser*> keyReleasedHandlers;
    static std::vector<MouseButtonPressedUser*> mouseButtonPressedHandlers;
    static std::vector<MouseButtonReleasedUser*> mouseButtonReleasedHandlers;
std::vector<MouseMovedUser*> mouseMovedHandlers;

std::vector<ClosedUser*> EventHandler::closedHandlers;
std::vector<KeyPressedUser*> EventHandler::keyPressedHandlers;
std::vector<KeyReleasedUser*> EventHandler::keyReleasedHandlers;
std::vector<MouseButtonPressedUser*> EventHandler::mouseButtonPressedHandlers;
std::vector<MouseButtonReleasedUser*> EventHandler::mouseButtonReleasedHandlers;
std::vector<MouseMovedUser*> EventHandler::mouseMovedHandlers;

void EventHandler::poll(sf::RenderWindow& canvas)
{
    sf::Event event;
    while(canvas.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            for(vector<ClosedUser*>::iterator it = closedHandlers.begin(); it != closedHandlers.end(); ++it)
                {
                    (*it)->closedListener(event);
                }
                canvas.close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            for(vector<KeyPressedUser*>::iterator it = keyPressedHandlers.begin(); it != keyPressedHandlers.end(); ++it)
                {
                    (*it)->keyPressedListener(event);
                }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            for(vector<KeyReleasedUser*>::iterator it = keyReleasedHandlers.begin(); it != keyReleasedHandlers.end(); ++it)
                {
                    (*it)->keyReleasedListener(event);
                }
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            for(vector<MouseButtonPressedUser*>::iterator it = mouseButtonPressedHandlers.begin(); it != mouseButtonPressedHandlers.end(); ++it)
                {
                    (*it)->mouseButtonPressedListener(event);
                }
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            for(vector<MouseButtonReleasedUser*>::iterator it = mouseButtonReleasedHandlers.begin(); it != mouseButtonReleasedHandlers.end(); ++it)
                {
                    (*it)->mouseButtonReleasedListener(event);
                }
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            for(vector<MouseMovedUser*>::iterator it = mouseMovedHandlers.begin(); it != mouseMovedHandlers.end(); ++it)
                {
                    (*it)->mouseMoveListener(event);
                }
        }
    }

}

void EventHandler::addListener(sf::Event::EventType type, EventUser* inObj)
{

    if (type == sf::Event::Closed)
    {
        closedHandlers.push_back((ClosedUser*)inObj);
    }
    else if (type == sf::Event::KeyPressed)
    {
        keyPressedHandlers.push_back((KeyPressedUser*)inObj);
    }
    else if (type == sf::Event::KeyReleased)
    {
        keyReleasedHandlers.push_back((KeyReleasedUser*)inObj);
    }
    else if (type == sf::Event::MouseButtonPressed)
    {
        mouseButtonPressedHandlers.push_back((MouseButtonPressedUser*)inObj);
        cout << mouseButtonPressedHandlers.size() << "add" << endl;
    }
    else if (type == sf::Event::MouseButtonReleased)
    {
        mouseButtonReleasedHandlers.push_back((MouseButtonReleasedUser*)inObj);
    }
    else if (type == sf::Event::MouseMoved)
    {
        mouseMovedHandlers.push_back((MouseMovedUser*)inObj);
    }
}

bool EventHandler::removeListener(sf::Event::EventType type, EventUser* removeObj)
{
    if (type == sf::Event::Closed)
    {
        for(vector<ClosedUser*>::iterator it = closedHandlers.begin(); it != closedHandlers.end(); ++it)
        {
            if((*it) == removeObj)
            {
                closedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::KeyPressed)
    {
        for(vector<KeyPressedUser*>::iterator it = keyPressedHandlers.begin(); it != keyPressedHandlers.end(); ++it)
        {
            if((*it) == removeObj)
            {
                keyPressedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::KeyReleased)
    {
        for(vector<KeyReleasedUser*>::iterator it = keyReleasedHandlers.begin(); it != keyReleasedHandlers.end(); ++it)
        {
            if((*it) == removeObj)
            {
                keyReleasedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::MouseButtonPressed)
    {
        for(vector<MouseButtonPressedUser*>::iterator it = mouseButtonPressedHandlers.begin(); it != mouseButtonPressedHandlers.end(); ++it)
        {
            if((*it) == removeObj)
            {
                mouseButtonPressedHandlers.erase(it);
                cout << mouseButtonPressedHandlers.size() << "remove" << endl;
                break;
            }
        }
    }
    else if (type == sf::Event::MouseButtonReleased)
    {
        for(vector<MouseButtonReleasedUser*>::iterator it = mouseButtonReleasedHandlers.begin(); it != mouseButtonReleasedHandlers.end(); ++it)
        {
            if((*it) == removeObj)
            {
                mouseButtonReleasedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::MouseMoved)
    {
        for(vector<MouseMovedUser*>::iterator it = mouseMovedHandlers.begin(); it != mouseMovedHandlers.end(); ++it)
        {
            if((*it) == removeObj)
            {
                mouseMovedHandlers.erase(it);
                break;
            }
        }
    }else{
        return false;
    }
    return true;
}
