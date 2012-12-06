#ifndef CannonPROJECTILE_H
#define CannonPROJECTILE_H
#include "../GameObject.h"
#include "Projectile.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>
#include "../VisualEffects/VisualEffect.h"

/**
 * class CannonProjectile
 *
 * Beskrivning: Tanken �r att den skjuter l�ngt och m�ls�ker p� n�rmaste fiende.
 * Om s�kt fiende d�r s�ker den en ny.
 */
class CannonProjectile : public Projectile
{
public:
    CannonProjectile(int newX, int newY, int newDamage, Enemy* newEnemy);
    ~CannonProjectile();

    /**
     * Ganska oklart vad denna ska g�ra. Om vi inte anv�nder m�ls�kande b�r den endast
     * uppdatera dess position. On�digt att d� ha den i CannonProjecile. B�r ist�llet
     * kunna byggas i projectile.
     */

    bool update(std::vector<Enemy*>& enemies);
    bool isHit(std::vector<Enemy*>& enemyVector);


protected:
private:
};

#endif // CannonPROJECTILE_H

