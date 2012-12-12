/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    MapMatrix.h
 * Enhetsnamn: MapMatrix
 * Typ:        implementering
 * Skriven av: C. Schmidt
 *
 *
 * BESKRIVNING
 *
 * Denna modul �r en abstraktion av representationen av vad som finns p� de olika kartkoordninaterna
 *
 */
#include <SFML/Graphics.hpp>

#ifndef MAPMATRIX_H
#define MAPMATRIX_H
#define SIDE 50

#include <string>
#include <vector>

class MapMatrix
{
    public:
		MapMatrix();
		MapMatrix(std::string value, int row, int col, std::string);
		void setMatrix(std::string value, int row, int col, std::string);
		bool isTaken(int x, int y);
		void setTower(int x, int y);
		void removeTower(int x, int y);
		bool isPath(int x, int y);
		std::pair<int, int> getCoord(int currentPosition);  //Pixelkoordinater mitt i rutan
                                                                //Tex. (0.0) -> (25.25) med 50px-rutor
        std::pair<int,int> convertPixelToMatrix(int pixelX,int pixelY);


		/*
		 * Finns endast f�r fels�kning
		 */
		void draw(sf::RenderWindow& canvas);
		void printMatrix();

    private:
        int getHeight();
		int getWidth();

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
