/**
 * @file Apple.h
 * @brief Deklaracja klasy Apple oraz jej funkcji sk³adowych.
 */

#ifndef APPLE_H
#define APPLE_H

#include "dependencies.h"


/**
 * @class Apple
 * @brief Reprezentuje obiekt jab³ka w grze.
 */
class Apple {
private:
	int x;/**< Wspó³rzêdna X pozycji jab³ka. */
	int y;/**< Wspó³rzêdna Y pozycji jab³ka. */
	ALLEGRO_BITMAP* appleBmp;/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego obrazek jab³ka. */
	public:
		/**
		* @brief Losuje now¹ pozycjê jab³ka w obrêbie siatki gry.
		*/
		void randomize();
		/**
		 * @brief Funkcja getter dla wspó³rzêdnej X jab³ka.
		 * @return Wspó³rzêdna X jab³ka.
		 */
		int getX(); 
		/**
	   * @brief Funkcja getter dla wspó³rzêdnej Y jab³ka.
	   * @return Wspó³rzêdna Y jab³ka.
	   */
		int getY(); 
		Apple();
		/**
		* @brief Wyœwietla jab³ko na ekranie przy u¿yciu funkcji Allegro 5.
		*/
		void displayApple();
};

#endif  // APPLE_H