#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Sprite
{
public:
    AnimatedSprite();
    AnimatedSprite(const sf::Texture &inTexture, unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFpf = 1, bool inPlaying = false);
    ~AnimatedSprite();

    bool setFrame(unsigned int inFrame);
    bool play(unsigned int inFpf);
    bool play();
    bool pause();
    bool update();
    unsigned int currentFrame();
    unsigned int getFpf();
    bool setFpf(unsigned int  inFpf);

private:
    unsigned int spriteWidth;
    unsigned int nuberOfSprites;
    unsigned int fpf;
	unsigned int fpfCounter;
    unsigned int frame;
    bool playing;
    sf::IntRect animationMask;
    sf::Vector2u imgSize;

};

#endif
