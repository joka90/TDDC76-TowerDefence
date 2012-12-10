/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    AnimatedSprite.cc
 * Enhetsnamn: AnimatedSprite
 * Typ:        implementering
 * Skriven av: J. Källström
 *
 *
 * BESKRIVNING
 *
 * Denna modul hanterar animationer av bilder
 *
 */

#include "AnimatedSprite.h"
/**
* @author Johan Källström
* Date November-December 2012 
* 
*/

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

void AnimatedSprite::setTextureAnimation(const sf::Texture& texture, unsigned int inSpriteWidth, unsigned int inNuberOfSprites, unsigned int inFpf, bool inPlaying)
{
    setTexture(texture);
    imgSize = texture.getSize();//get full image size
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
    fpf=inFpf;
    playing=inPlaying;
    nuberOfSprites=inNuberOfSprites;
    spriteWidth=inSpriteWidth;
}
void AnimatedSprite::setAnimationProps(unsigned int inSpriteWidth, unsigned int inSpriteHeight, unsigned int inNuberOfSprites, unsigned int inFpf, bool inPlaying)
{
    animationMask.width=inSpriteWidth;//set mask size
    animationMask.height=inSpriteHeight;
    setTextureRect(animationMask);
    fpf=inFpf;
    playing=inPlaying;
    nuberOfSprites=inNuberOfSprites;
    spriteWidth=inSpriteWidth;
}

AnimatedSprite::~AnimatedSprite()
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

