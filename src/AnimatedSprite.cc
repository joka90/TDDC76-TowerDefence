#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite()
{

}

AnimatedSprite::AnimatedSprite(const Texture &inTexture, unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFps = 0, bool inPlaying = false)
:sf::Sprite(const Texture &inTexture)
{
    spriteWidth=inSpriteWidth;
    nuberOfSprites=inNuberOfSprites;
    fps=inFps;
    playing=inPlaying;
}

AnimatedSprite::AnimatedSprite(const Texture &inTexture, const IntRect &inRectangle,  unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFps = 0, bool inPlaying = false)
:sf::Sprite(const Texture &inTexture, const IntRect &inRectangle)
{
    spriteWidth=inSpriteWidth;
    nuberOfSprites=inNuberOfSprites;
    fps=inFps;
    playing=inPlaying;
}

AnimatedSprite::~AnimatedSprite()
:sf::~Sprite()
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

