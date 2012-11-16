#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class GameObject
{
    public:
        GameObject(int x, int y, class TextureLoader* textures, sting textureReference);
        virtual ~GameObject();
        int getPosX();
        int getPosY();
        void setPos(int newPosX, int newPosY);
        void playAnimation();
        void pauseAnimation();
        virtual bool drawSprite(RenderWindow& canvas);
    protected:
    private:
        int xPos;
        int yPos;
        AnimatedSprite sprite;
};

#endif // GAMEOBJECT_H
