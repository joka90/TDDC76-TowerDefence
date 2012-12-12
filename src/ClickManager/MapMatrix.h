/**
 * TDDC76 TowerDefence
 *
 * IDENTIFIERING
 *
 * Filnamn:    MapMatrix.h
 * Enhetsnamn: MapMatrix
 * Typ:        implementering
 * Skriven av: C. Karlsson Schmidt
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
		MapMatrix(std::string value, int row, int col, std::string pathString);
		/**
		 * En str�ng med uteendet "0 1 0 0 0 1 0 0" kan ge en 4x2 eller 2x4  - matris
		 * PathString inneh�ller koordinaterna f�r alla sv�ngar i banan, anv�nds f�r att hitta n�sta
		 * koordinat som fiende ska g� mot
		 */
		void setMatrix(std::string value, int row, int col, std::string);
		/**
         * Kollar om en koordinat i matrisen �r !0
         */
		bool isTaken(int x, int y);
        /**
         * S�tter koordinaten till 2 som representerar ett torn
         */
		void setTower(int x, int y);
		/**
         * S�tter koordinaten till 0
         */
		void removeTower(int x, int y);
		/**
         * Kollar om koordinaten �r 1 (= path)
         */
        bool isPath(int x, int y);
        /**
         * Returnerar pixelkoordinater baserat p� hur m�nga rutor fiender har g�tt
         */
		std::pair<int, int> getCoord(int currentPosition);
		/**
         * Omvandlar pixelkoordinator till matriskoordinater
         */
        std::pair<int,int> convertPixelToMatrix(int pixelX,int pixelY);


		/**
		 * Finns endast f�r fels�kning
		 */
		void draw(sf::RenderWindow& canvas);
		void printMatrix();

    private:
       /**
         * Returnerar h�jd och bredd p� matrisen
         */
        int getHeight();
		int getWidth();

		/**
		 * 1 = Path
		 * 2 = Tower
		 */
		 std::vector<std::vector<int> > matrix;
		 std::vector<std::pair<int,int> > path; // Beskriver v�gen i koordinater, f�r ex nedan s� blir v�gen: (0,1) , (1,1) , (2,1) , (2,2) , (3,2) osv..
                                               // Denna vector skulle kunna sparas i filen som beskriver varje level.

        /** Ex: 0 0 0 0 0 0 0
         *    1 1 1 0 1 1 1
         *     0 0 1 1 1 0 0
         */
};

#endif /* MAPMATRIX_H */
