#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <SFML/Graphics.hpp>

class AnimatedSprite : public sf::Sprite
{
public:
    AnimatedSprite();
    /**
    * AnimatedSprite
    * @param inTexture a texture.
    * @param inSpriteWidth the width of the partial image, inSpriteWidth*inNuberOfSprites = the total width of the image.
    * @param inNuberOfSprites the number of partial images in the big one.
    * @param inFpf number of frames(how often update() get called) the same image will show.
    * @param inPlaying start counting frames.
    */
    AnimatedSprite(const sf::Texture& inTexture, unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFpf = 1, bool inPlaying = false);
    ~AnimatedSprite();

    //void setTexture(const sf::Texture& texture, bool resetRect);// not working m_texture is private
	void setTextureAnimation(const sf::Texture& texture,unsigned int inSpriteWidth = 0, unsigned int inNuberOfSprites= 0, unsigned int inFpf = 1, bool inPlaying = false);
    /**
    * setFrame
    * @param inFrame set a specific frame.
    */
    bool setFrame(unsigned int inFrame);
    /**
    * setFrame
    * @param inFpf set the rate and start playing.
    */
    bool play(unsigned int inFpf);
    bool play();
    bool pause();
    /**
    * update
    * sets a new region of the loaded image to show based on the number of calls(fps)
    * @return true on sprite update, false if waiting or not playing
    */
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
