#include "CannonProjectile.h"
#include <cmath>
#include <vector>

using namespace std;

// BESTÄMT ATT PROJEKTILEN HAR 15 I SPEED
CannonProjectile::CannonProjectile(int newX, int newY, int newDamage,
                               Enemy* newEnemy)
: Projectile(newX, newY, newDamage, 15, newEnemy,"Sprites/cannon.png")
{

}

CannonProjectile::~CannonProjectile()
{

}


bool CannonProjectile::update(std::vector<Enemy*>& enemies)
{
    bool hit = false;
    move();
    hit = isHit(enemies);
    if(hit)
    {

    }

}

bool CannonProjectile::isHit(std::vector<Enemy*>& enemyVector)
{
    bool hit = false;
    int x,y;
    vector<Enemy*> deleteVector;
    for(vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); ++it)
	{
		x = (*it)->getPosX();
		y = (*it)->getPosY();
		if( sqrt((pow(getPosX() - x , 2) + pow(getPosY() - y,2))) < RADIE )
		{
		    (*it)->hit(damage);
		    if((*it)->isDead())
		    {
		        deleteVector.push_back(*it);
		    }
            hit = true;
		}
	}
	while(!deleteVector.empty())
    {
        for(vector<Enemy*>::iterator it = enemyVector.begin(); it != enemyVector.end(); ++it)
        {
            if(deleteVector[0] == *it)
            {
               // (*it)->onDeath();
                delete(*it);
                enemyVector.erase(it);
                deleteVector.erase(deleteVector.begin());
                break;
            }
        }
    }
    VisualEffect hej(xPos, yPos, 10,  "Sprites/explo.png");
    hej.drawSprite();
    return hit;
}
