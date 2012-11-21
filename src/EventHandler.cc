#include "EventHandler.h"

using namespace std;
EventHandler::EventHandler()
{

}


std::vector<eventHandlerFunction> EventHandler::closedHandlers;
std::vector<eventHandlerFunction> EventHandler::keyPressedHandlers;
std::vector<eventHandlerFunction> EventHandler::keyReleasedHandlers;
std::vector<eventHandlerFunction> EventHandler::mouseButtonPressedHandlers;
std::vector<eventHandlerFunction> EventHandler::mouseButtonReleasedHandlers;
std::vector<eventHandlerFunction> EventHandler::mouseMovedHandlers;

void EventHandler::poll(sf::RenderWindow& canvas)
{
    sf::Event event;
    while(canvas.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            for(vector<eventHandlerFunction>::iterator it = closedHandlers.begin(); it != closedHandlers.end(); ++it)
                {
                    (*it)(event);
                }
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            for(vector<eventHandlerFunction>::iterator it = keyPressedHandlers.begin(); it != keyPressedHandlers.end(); ++it)
                {
                    (*it)(event);
                }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            for(vector<eventHandlerFunction>::iterator it = keyReleasedHandlers.begin(); it != keyReleasedHandlers.end(); ++it)
                {
                    (*it)(event);
                }
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            for(vector<eventHandlerFunction>::iterator it = mouseButtonPressedHandlers.begin(); it != mouseButtonPressedHandlers.end(); ++it)
                {
                    (*it)(event);
                }
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            for(vector<eventHandlerFunction>::iterator it = mouseButtonReleasedHandlers.begin(); it != mouseButtonReleasedHandlers.end(); ++it)
                {
                    (*it)(event);
                }
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            for(vector<eventHandlerFunction>::iterator it = mouseMovedHandlers.begin(); it != mouseMovedHandlers.end(); ++it)
                {
                    (*it)(event);
                }
        }
    }

}

void EventHandler::addListener(sf::Event::EventType type, eventHandlerFunction inFunc)
{
    if (type == sf::Event::Closed)
    {
        closedHandlers.push_back(inFunc);
    }
    else if (type == sf::Event::KeyPressed)
    {
        keyPressedHandlers.push_back(inFunc);
    }
    else if (type == sf::Event::KeyReleased)
    {
        keyReleasedHandlers.push_back(inFunc);
    }
    else if (type == sf::Event::MouseButtonPressed)
    {
        mouseButtonPressedHandlers.push_back(inFunc);
    }
    else if (type == sf::Event::MouseButtonReleased)
    {
        mouseButtonReleasedHandlers.push_back(inFunc);
    }
    else if (type == sf::Event::MouseMoved)
    {
        mouseMovedHandlers.push_back(inFunc);
    }
}

bool EventHandler::removeListener(sf::Event::EventType type, eventHandlerFunction deleteFunc)
{
    if (type == sf::Event::Closed)
    {
        for(vector<eventHandlerFunction>::iterator it = closedHandlers.begin(); it != closedHandlers.end(); ++it)
        {
            if((*it) == deleteFunc)
            {
                closedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::KeyPressed)
    {
        for(vector<eventHandlerFunction>::iterator it = keyPressedHandlers.begin(); it != keyPressedHandlers.end(); ++it)
        {
            if((*it) == deleteFunc)
            {
                keyPressedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::KeyReleased)
    {
        for(vector<eventHandlerFunction>::iterator it = keyReleasedHandlers.begin(); it != keyReleasedHandlers.end(); ++it)
        {
            if((*it) == deleteFunc)
            {
                keyReleasedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::MouseButtonPressed)
    {
        for(vector<eventHandlerFunction>::iterator it = mouseButtonPressedHandlers.begin(); it != mouseButtonPressedHandlers.end(); ++it)
        {
            if((*it) == deleteFunc)
            {
                mouseButtonPressedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::MouseButtonReleased)
    {
        for(vector<eventHandlerFunction>::iterator it = mouseButtonReleasedHandlers.begin(); it != mouseButtonReleasedHandlers.end(); ++it)
        {
            if((*it) == deleteFunc)
            {
                mouseButtonReleasedHandlers.erase(it);
                break;
            }
        }
    }
    else if (type == sf::Event::MouseMoved)
    {
        for(vector<eventHandlerFunction>::iterator it = mouseMovedHandlers.begin(); it != mouseMovedHandlers.end(); ++it)
        {
            if((*it) == deleteFunc)
            {
                mouseMovedHandlers.erase(it);
                break;
            }
        }
    }
}
