#include "AnimatedSprite.h"


//onödig atm ty vi ej kan ändra animationsinställningar
AnimatedSprite::AnimatedSprite()
:sf::Sprite(), spriteWidth(1), nuberOfSprites(1), fpf(1), fpfCounter(0), frame(0), playing(false), animationMask(0,0,1,1)
{

}

AnimatedSprite::AnimatedSprite(const sf::Texture &inTexture, unsigned int inSpriteWidth, unsigned int inNuberOfSprites, unsigned int inFpf, bool inPlaying)
:sf::Sprite(inTexture), spriteWidth(inSpriteWidth), nuberOfSprites(inNuberOfSprites), fpf(inFpf), fpfCounter(0), frame(0), playing(inPlaying), animationMask(0,0,1,1)
{
    imgSize = inTexture.getSize();//get full image size
    if(inSpriteWidth!=0||inNuberOfSprites!=0)
    {
        animationMask.width=inSpriteWidth;//set mask size
        animationMask.height=imgSize.y;
        setTextureRect(animationMask);
    }
    else
    {
        animationMask.height=imgSize.y;
        animationMask.width=imgSize.x;
        setTextureRect(animationMask);
    }

}
/* NOT WORKING, m_texture is private
////////////////////////////////////////////////////////////
void AnimatedSprite::setTexture(const sf::Texture& texture, bool resetRect)
{
    animationMask.height=texture.getSize().y;
    animationMask.width=texture.getSize().x;
    setTextureRect(sf::IntRect(0, 0, texture.getSize().x, texture.getSize().y));

    // Assign the new texture
    m_texture = &texture;
}*/

AnimatedSprite::~AnimatedSprite()
//:sf::~Sprite()//not needed?
{

}

bool AnimatedSprite::setFrame(unsigned int inFrame)
{
    if(inFrame<=nuberOfSprites)
    {
        frame=inFrame;
        animationMask.left=frame*spriteWidth;
        setTextureRect(animationMask);
        return true;
    }
    else
    {
        return false;
    }
}

bool AnimatedSprite::play(unsigned int inFpf)
{
    fpf=inFpf;
    return true;
}

bool AnimatedSprite::play()
{
    playing=true;
    return true;
}

bool AnimatedSprite::pause()
{
    playing=false;
    return true;
}

/**
* AnimatedSprite::update()
* returns true on sprite update, false if waiting or not playing
*/
bool AnimatedSprite::update()
{
    if(playing)
    {
        fpfCounter++;
        if(fpfCounter==fpf)
        {
            fpfCounter=0;//reset counter
            frame++;
            if(frame>nuberOfSprites)
            {
                frame=0;
            }
            animationMask.left=frame*spriteWidth;
            setTextureRect(animationMask);
            return true;
        }
        return false;
    }
    else
    {
        return false;
    }
}

unsigned int AnimatedSprite::currentFrame()
{
    return frame;
}

unsigned int AnimatedSprite::getFpf()
{
    return fpf;
}
bool AnimatedSprite::setFpf(unsigned int inFpf)
{
    fpf=inFpf;
    return true;
}

