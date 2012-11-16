#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Sprite
{
public:
    AnimatedSprite();
    AnimatedSprite(const sf::Texture &inTexture, unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFps = 0, bool inPlaying = false);
    AnimatedSprite(const sf::Texture &inTexture, const sf::IntRect &inRectangle,  unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFps = 0, bool inPlaying = false);
    ~AnimatedSprite();

    sf::Sprite getFrame(unsigned int inFrame);
    sf::Sprite getCurrentFrame();
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
    unsigned int frame;
    bool playing;

};

#endif
