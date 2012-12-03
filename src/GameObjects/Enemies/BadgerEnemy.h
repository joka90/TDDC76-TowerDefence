#ifndef BADGERENEMY_H
#define BADGERENEMY_H

#include "Enemy.h"

class BadgerEnemy : public Enemy
{
    public:
        BadgerEnemy(int newLife, int newSpeed, int newValue, std::string textureReference);
        virtual ~BadgerEnemy();


    protected:
    private:
};

#endif // BADGERENEMY_H
