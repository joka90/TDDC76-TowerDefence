#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{

}

AnimatedSprite::AnimatedSprite(const sf::Texture &inTexture, unsigned int inSpriteWidth, unsigned int inNuberOfSprites, unsigned int inFps, bool inPlaying)
:sf::Sprite(inTexture)
{
    spriteWidth=inSpriteWidth;
    nuberOfSprites=inNuberOfSprites;
    fps=inFps;
    playing=inPlaying;
}

AnimatedSprite::AnimatedSprite(const sf::Texture &inTexture, const sf::IntRect &inRectangle,  unsigned int inSpriteWidth, unsigned int inNuberOfSprites, unsigned int inFps, bool inPlaying)
:sf::Sprite(inTexture, inRectangle)
{
    spriteWidth=inSpriteWidth;
    nuberOfSprites=inNuberOfSprites;
    fps=inFps;
    playing=inPlaying;
}

AnimatedSprite::~AnimatedSprite()
//:sf::~Sprite()//not needed?
{

}


sf::Sprite AnimatedSprite::getFrame(unsigned int inFrame)
{
    frame=inFrame;
}

sf::Sprite AnimatedSprite::getCurrentFrame()
{

}

bool AnimatedSprite::play(unsigned int inFps)
{
    fps=inFps;
}

bool AnimatedSprite::play()
{
    playing=true;
}

bool AnimatedSprite::paus()
{
    playing=false;
}

bool AnimatedSprite::update()
{

}

unsigned int AnimatedSprite::currentFrame()
{

}

unsigned int AnimatedSprite::currentFps()
{

}

