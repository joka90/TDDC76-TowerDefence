/*
 * MapMatrix.h
 *
 *  Created on: 17 nov 2012
 *      Author: Calle
 */

#ifndef MAPMATRIX_H
#define MAPMATRIX_H
#define SIDE 50

#include <string>
#include <vector>

class MapMatrix
{
    public:
		MapMatrix();
		MapMatrix(std::string value, int row, int col);
		void setMatrix(std::string value, int row, int col);
		bool isTaken(int x, int y);
		void setTower(int x, int y);
		bool isPath(int x, int y);
		std::pair<int, int> getNextCoord(int currentPosition);  //Pixelkoordinater mitt i rutan
                                                                //Tex. (0.0) -> (25.25) med 50px-rutor

		/*
		 * Finns endast f�r fels�kning
		 */

		void printMatrix();

    private:
        int getHeight();
		int getWidth();
		std::pair<int,int> convertPixelToMatrix(int pixelX,int pixelY);
		/*
		 * 1 = Path
		 * 2 = Tower
		 */
		 std::vector<std::vector<int> > matrix;
		 std::vector<std::pair<int,int> > path; // Beskriver v�gen i koordinater, f�r ex nedan s� blir v�gen: (0,1) , (1,1) , (2,1) , (2,2) , (3,2) osv..
                                               // Denna vector skulle kunna sparas i filen som beskriver varje level.

         // Ex: 0 0 0 0 0 0 0
         //     1 1 1 0 1 1 1
         //     0 0 1 1 1 0 0

};

#endif /* MAPMATRIX_H */
