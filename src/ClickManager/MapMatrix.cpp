using namespace std;


#include "MapMatrix.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#define SIDE 50
using namespace std;

MapMatrix::MapMatrix()
{
}
MapMatrix::MapMatrix(string value,int row, int col)
{
	setMatrix(value,row,col);
}
void MapMatrix::setMatrix(string value, int row, int col)
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
			if(numValue == 1)
			{
                path.push_back(make_pair(r,c));
			}
		}
	}
}

bool MapMatrix::isTaken(int pixelX, int pixelY)
{
    pair<int,int>matrixPixel = convertPixelToMatrix(pixelX,pixelY);
	return !(matrix[matrixPixel.first][matrixPixel.second] == 0);
}

void MapMatrix::setTower(int pixelX, int pixelY)
{
	matrix[pixelX][pixelY] = 2; //Tower = 2
}

bool MapMatrix::isPath(int pixelX, int pixelY)
{
    pair<int,int>matrixPixel = convertPixelToMatrix(pixelX,pixelY);
	return (matrix[matrixPixel.first][matrixPixel.second] == 1);
}

pair<int, int> MapMatrix::getNextCoord(int currentPathPosition)
{
    int x = ((path[currentPathPosition].first + 0.5) * SIDE);
    int y = ((path[currentPathPosition].second + 0.5) * SIDE);
    return make_pair(x,y);
}
int MapMatrix::getHeight()
{
    return matrix[0].size();
}
int MapMatrix::getWidth()
{
    return matrix.size();
}
pair<int,int> MapMatrix::convertPixelToMatrix(int pixelX,int pixelY)
{
    int matrixX = (pixelX * getWidth() / SIDE);
    int matrixY = (pixelY * getHeight() / SIDE);
    return make_pair(matrixX,matrixY);
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
