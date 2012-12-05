using namespace std;


#include "MapMatrix.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

MapMatrix::MapMatrix()
{
}
MapMatrix::MapMatrix(string value,int row, int col, string path)
{
    setMatrix(value,row,col, path);
}
void MapMatrix::setMatrix(string value, int row, int col, string pathString)
{

    //Fixar mapMatrix
    int numValue;
    istringstream matrixSs(value);
    // Sätter storleken row x col
    matrix.resize(row);
    for (int i = 0; i < row; ++i)
        matrix[i].resize(col);

    // Sätter in värden
    for (int r  = 0; r  < row; ++r )
    {
        for(int c = 0; c < col; ++c)
        {
            if(!matrixSs.good())
            {
                cout << "ERROR i MapMatrix " << endl;
            }
            matrixSs >> numValue;
            matrix[r][c] = numValue;
        }
    }
    /*
        Fixar path-vektorn
    */
    istringstream pathSs(pathString);
    int x,y,i(0);
    char deleteComma;
    while(pathSs.good())
    {
        cout << i++ << endl;
        pathSs >> x;
        pathSs >> deleteComma;
        pathSs >> y;
        path.push_back(make_pair(x,y));
    }
}

bool MapMatrix::isTaken(int pixelX, int pixelY)
{
    pair<int,int>matrixPixel = convertPixelToMatrix(pixelX,pixelY);
    if(matrixPixel.first < getWidth()  && matrixPixel.second < getHeight()
            && matrixPixel.first >= 0 && matrixPixel.second >= 0)
    {
        return !(matrix[matrixPixel.second][matrixPixel.first] == 0);
    }
    else
    {
        //cout << "ERROR: Outside MapMatrix" << endl;
        return true;//To make it inpossible to place tower there
    }
}

void MapMatrix::setTower(int pixelX, int pixelY)
{
    pair<int,int>matrixPixel = convertPixelToMatrix(pixelX ,pixelY );
    if(matrixPixel.first < getWidth()  && matrixPixel.second < getHeight()
            && matrixPixel.first >= 0 && matrixPixel.second >= 0)
    {
        matrix[matrixPixel.second][matrixPixel.first] = 2; //Tower = 2
    }
    else
    {
        cout << "ERROR: Outside MapMatrix" << endl;
    }
}

void MapMatrix::removeTower(int pixelX, int pixelY)
{
    pair<int,int>matrixPixel = convertPixelToMatrix(pixelX ,pixelY );
    if(matrixPixel.first < getWidth() && matrixPixel.second < getHeight()
            && matrixPixel.first >= 0 && matrixPixel.second >= 0)
    {
        matrix[matrixPixel.second][matrixPixel.first] = 0; //Tower = 2
    }
    else
    {
        cout << "ERROR: Outside MapMatrix" << endl;
    }
}

bool MapMatrix::isPath(int pixelX, int pixelY)
{
    pair<int,int>matrixPixel = convertPixelToMatrix(pixelX,pixelY);
    if(matrixPixel.first < getWidth() && matrixPixel.second < getHeight()
            && matrixPixel.first > 0 && matrixPixel.second > 0)
    {
        return (matrix[matrixPixel.first][matrixPixel.second] == 1);
    }
    else
    {
        //cout << "ERROR: Outside MapMatrix" << endl;
        return true;//To make it impossible to place tower there
    }
}

pair<int, int> MapMatrix::getCoord(int currentPathPosition)
{
    cout << currentPathPosition << endl;
    cout << path.size() << endl;
    if(currentPathPosition < (int) path.size())
    {
        int pixelX = ((path[currentPathPosition].first) * SIDE);
        int pixelY = ((path[currentPathPosition].second) * SIDE);
        return make_pair(pixelX,pixelY);
    }
    else
    {
        return make_pair(-1, -1); //Ta bort ett liv
    }
}
int MapMatrix::getHeight()
{
    return matrix.size();
}
int MapMatrix::getWidth()
{
    return matrix[0].size();
}
pair<int,int> MapMatrix::convertPixelToMatrix(int pixelX,int pixelY)
{
    int matrixX = pixelX/SIDE; //(pixelX * getWidth() / SIDE);
    int matrixY = pixelY/SIDE; //(pixelY * getHeight() / SIDE);
    return make_pair(matrixX,matrixY);
}

void MapMatrix::draw(sf::RenderWindow& canvas)
{
    int row = getHeight();
    int col = getWidth();
    for ( int i = 0; i < row; i++ )
    {
        for ( int j = 0; j < col; j++ )
        {
            if(matrix[i][j]==1)
            {
                sf::RectangleShape rectangle;
                rectangle.setFillColor(sf::Color::Green);
                rectangle.setSize(sf::Vector2f(SIDE, SIDE));
                rectangle.setOutlineColor(sf::Color::Black);
                rectangle.setOutlineThickness(5);
                rectangle.setPosition(j*SIDE, i*SIDE);
                canvas.draw(rectangle);
            }
            else if(matrix[i][j]==2)
            {
                sf::RectangleShape rectangle;
                rectangle.setFillColor(sf::Color::Red);
                rectangle.setSize(sf::Vector2f(SIDE, SIDE));
                rectangle.setOutlineColor(sf::Color::Black);
                rectangle.setOutlineThickness(5);
                rectangle.setPosition(j*SIDE, i*SIDE);
                canvas.draw(rectangle);
            }
            else if(matrix[i][j]==0)
            {
                sf::RectangleShape rectangle;
                rectangle.setFillColor(sf::Color::White);
                rectangle.setSize(sf::Vector2f(SIDE, SIDE));
                rectangle.setOutlineColor(sf::Color::Black);
                rectangle.setOutlineThickness(5);
                rectangle.setPosition(j*SIDE, i*SIDE);
                canvas.draw(rectangle);
            }
        }
    }

}

//Finns endast för felsökning
void MapMatrix::printMatrix()
{
    int row = matrix.size();
    int col = matrix[0].size();
    for ( int i = 0; i < row; i++ )
    {
        for ( int j = 0; j < col; j++ )
        {
            cout<< matrix[i][j] <<' ';
        }
        cout<<'\n';
    }
}
