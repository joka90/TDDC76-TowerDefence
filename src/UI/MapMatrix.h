/*
 * MapMatrix.h
 *
 *  Created on: 17 nov 2012
 *      Author: Calle
 */

#ifndef MAPMATRIX_H
#define MAPMATRIX_H

#include <string>

class MapMatrix
{
    public:
		MapMatrix(std::string value, int x, int y);

		bool isTaken(int x, int y);
		void setCoord(int x, int y, int value);
		bool isPath(int x, int y);

    private:
		/*
		 * 1 = Path
		 * 2 = Tower
		 */
		int matrix[0][0];

};

#endif /* MAPMATRIX_H_ */
