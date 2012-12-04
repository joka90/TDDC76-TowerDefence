#ifndef LONGPROJECTILE_H
#define LONGPROJECTILE_H
#include "../GameObject.h"
#include "Projectile.h"
#include "../Enemies/Enemy.h"
#include <SFML/Graphics.hpp>

/**
 * class LongProjectile
 *
 * Beskrivning: Tanken �r att den skjuter l�ngt och m�ls�ker p� n�rmaste fiende.
 * Om s�kt fiende d�r s�ker den en ny.
 */
class LongProjectile : public Projectile
{
public:
    LongProjectile(int newX, int newY, int newDamage, Enemy* newEnemy);
    ~LongProjectile();

    /**
     * Ganska oklart vad denna ska g�ra. Om vi inte anv�nder m�ls�kande b�r den endast
     * uppdatera dess position. On�digt att d� ha den i LongProjecile. B�r ist�llet
     * kunna byggas i projectile.
     */
    void update(std::vector<Enemy*>& enemies);

protected:
private:
};

#endif // LONGPROJECTILE_H
