using namespace std;


#include "MapMatrix.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


MapMatrix::MapMatrix(string value,int row, int col)
{
	int numValue;
	std::istringstream ss(value);
	// Sätter storleken row x col
	matrix.resize(row);
	for (int i = 0; i < row; ++i)
		matrix[i].resize(col);

	// Sätter in värden
	for (int r  = 0; r  < row; ++r )
	{
		for(int c = 0; c < col; ++c)
		{
			if(!ss.good())
			{
				cout << "ERROR i MapMatrix " << endl;
			}
			ss >> numValue;
			matrix[r][c] = numValue;
		}
	}
}

bool MapMatrix::isTaken(int x, int y)
{
	return !(matrix[x][y] == 0);
}

void MapMatrix::setCoord(int x, int y, int value)
{
	matrix[x][y] = value;
}

bool MapMatrix::isPath(int x, int y)
{
	return (matrix[x][y] == 1);
}
//Finns endast för felsökning
void MapMatrix::printMatrix(){
	int row = matrix.size();
	int col = matrix[0].size();
    for ( int i = 0; i < row; i++ ) {
        for ( int j = 0; j < col; j++ )
            cout<< matrix[i][j] <<' ';
            cout<<'\n';
    }
}
