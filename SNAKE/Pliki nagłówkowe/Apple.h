/**
 * @file Apple.h
 * @brief Deklaracja klasy Apple oraz jej funkcji sk�adowych.
 */

#ifndef APPLE_H
#define APPLE_H

#include "dependencies.h"


/**
 * @class Apple
 * @brief Reprezentuje obiekt jab�ka w grze.
 */
class Apple {
private:
	int x;/**< Wsp�rz�dna X pozycji jab�ka. */
	int y;/**< Wsp�rz�dna Y pozycji jab�ka. */
	ALLEGRO_BITMAP* appleBmp;/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego obrazek jab�ka. */
	public:
		/**
		* @brief Losuje now� pozycj� jab�ka w obr�bie siatki gry.
		*/
		void randomize();
		/**
		 * @brief Funkcja getter dla wsp�rz�dnej X jab�ka.
		 * @return Wsp�rz�dna X jab�ka.
		 */
		int getX(); 
		/**
	   * @brief Funkcja getter dla wsp�rz�dnej Y jab�ka.
	   * @return Wsp�rz�dna Y jab�ka.
	   */
		int getY(); 
		Apple();
		/**
		* @brief Wy�wietla jab�ko na ekranie przy u�yciu funkcji Allegro 5.
		*/
		void displayApple();
};

#endif  // APPLE_H