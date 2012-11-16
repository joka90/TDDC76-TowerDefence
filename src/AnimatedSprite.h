#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <Sprite.hpp>

class AnimatedSprite : public sf:Sprite
{
public:
    AnimatedSprite();
    AnimatedSprite(const Texture &inTexture, unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFps = 0, bool inPlaying = false);
    AnimatedSprite(const Texture &inTexture, const IntRect &inRectangle,  unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFps = 0, bool inPlaying = false);
    ~AnimatedSprite();

    Sprite getFrame(unsigned int inFrame);
    Sprite getCurrentFrame();
    bool play(unsigned int inFps);
    bool play();
    bool paus();
    bool update();
    unsigned int currentFrame();
    unsigned int currentFps();

private:
    unsigned int spriteWidth;
    unsigned int nuberOfSprites;
    unsigned int fps;
    bool playing;

};

#endif
