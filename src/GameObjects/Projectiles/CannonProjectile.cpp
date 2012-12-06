#include "CannonProjectile.h"
#include <cmath>
#include <vector>

using namespace std;

// BESTÄMT ATT PROJEKTILEN HAR 15 I SPEED
CannonProjectile::CannonProjectile(int newX, int newY, int newDamage, int lifetime, int inSplashradius, Enemy* newEnemy)
: Projectile(newX, newY, newDamage, lifetime, CANONPROJECTILESPEED, newEnemy,"Sprites/cannon.png"), splashradius(inSplashradius)
{
}

CannonProjectile::~CannonProjectile()
{

}


bool CannonProjectile::update(std::vector<Enemy*>& enemies, std::vector<VisualEffect*>& visualeffects)
{
    bool hit = false;
    move();
    --lifetime;
    if(lifetime<0)
    {
        return true;
    }
    if(isHit(enemies, visualeffects))
    {
        int x,y;
        vector<Enemy*> deleteVector;
        for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
        {
            x = (*it)->getPosX();
            y = (*it)->getPosY();
            if( sqrt((pow(getPosX() - x , 2) + pow(getPosY() - y,2))) < splashradius)
            {
                (*it)->hit(damage);
                if((*it)->isDead())
                {
                    deleteVector.push_back(*it);
                }
            }
        }
        while(!deleteVector.empty())
        {
            for(vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); ++it)
            {
                if(deleteVector[0] == *it)
                {
                (*it)->onDeath(visualeffects);
                delete(*it);
                enemies.erase(it);
                deleteVector.erase(deleteVector.begin());
                break;
                }
            }
        }
         visualeffects.push_back(new VisualEffect(getPosX(), getPosY(), 0, 75, "Explosion.png",
                           55, 60, 15, 5, true));
        return true;
    }
    return false;

}

bool CannonProjectile::isHit(std::vector<Enemy*>& enemyVector, std::vector<VisualEffect*>& visualeffects)
{
    bool hit = false;
    int x,y;
    for(vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); ++it)
	{
		x = (*it)->getPosX();
		y = (*it)->getPosY();
		if( sqrt((pow(getPosX() - x , 2) + pow(getPosY() - y,2))) < RADIE )
		{
		    return true;
		}
	}
	return false;
}
