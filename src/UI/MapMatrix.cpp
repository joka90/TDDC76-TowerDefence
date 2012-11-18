using namespace std;


#include "MapMatrix.h"
#include <string>


MapMatrix::MapMatrix(string value,int x, int y)
{
}

bool MapMatrix::isTaken(int x, int y)
{
	return (matrix[x][y] == 0);
}

void MapMatrix::setCoord(int x, int y, int value)
{
	matrix[x][y] = value;
}

bool MapMatrix::isPath(int x, int y)
{
	return (matrix[x][y] == 1);
}
