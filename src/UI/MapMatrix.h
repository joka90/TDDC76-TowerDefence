/*
 * MapMatrix.h
 *
 *  Created on: 17 nov 2012
 *      Author: Calle
 */

#ifndef MAPMATRIX_H
#define MAPMATRIX_H

#include <string>
#include <vector>
class MapMatrix
{
    public:
		MapMatrix(std::string value, int row, int col);

		bool isTaken(int x, int y);
		void setCoord(int x, int y, int value);
		bool isPath(int x, int y);

		/*
		 * Finns endast f�r fels�kning
		 */
		void printMatrix();

    private:
		/*
		 * 1 = Path
		 * 2 = Tower
		 */
		 std::vector<std::vector<int> > matrix;


};

#endif /* MAPMATRIX_H */
