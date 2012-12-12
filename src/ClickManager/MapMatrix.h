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
 * Denna modul är en abstraktion av representationen av vad som finns på de olika kartkoordninaterna
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
		 * En sträng med uteendet "0 1 0 0 0 1 0 0" kan ge en 4x2 eller 2x4  - matris
		 * PathString innehåller koordinaterna för alla svängar i banan, används för att hitta nästa
		 * koordinat som fiende ska gå mot
		 */
		void setMatrix(std::string value, int row, int col, std::string);
		/**
         * Kollar om en koordinat i matrisen är !0
         */
		bool isTaken(int x, int y);
        /**
         * Sätter koordinaten till 2 som representerar ett torn
         */
		void setTower(int x, int y);
		/**
         * Sätter koordinaten till 0
         */
		void removeTower(int x, int y);
		/**
         * Kollar om koordinaten är 1 (= path)
         */
        bool isPath(int x, int y);
        /**
         * Returnerar pixelkoordinater baserat på hur många rutor fiender har gått
         */
		std::pair<int, int> getCoord(int currentPosition);
		/**
         * Omvandlar pixelkoordinator till matriskoordinater
         */
        std::pair<int,int> convertPixelToMatrix(int pixelX,int pixelY);


		/**
		 * Finns endast för felsökning
		 */
		void draw(sf::RenderWindow& canvas);
		void printMatrix();

    private:
       /**
         * Returnerar höjd och bredd på matrisen
         */
        int getHeight();
		int getWidth();

		/**
		 * 1 = Path
		 * 2 = Tower
		 */
		 std::vector<std::vector<int> > matrix;
		 std::vector<std::pair<int,int> > path; // Beskriver vägen i koordinater, för ex nedan så blir vägen: (0,1) , (1,1) , (2,1) , (2,2) , (3,2) osv..
                                               // Denna vector skulle kunna sparas i filen som beskriver varje level.

        /** Ex: 0 0 0 0 0 0 0
         *    1 1 1 0 1 1 1
         *     0 0 1 1 1 0 0
         */
};

#endif /* MAPMATRIX_H */
