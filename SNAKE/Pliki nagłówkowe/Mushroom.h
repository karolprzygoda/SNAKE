/**
 * @file Mushroom.h
 * @brief Deklaracja klasy Mushroom oraz jej sk³adowych.
 */

#ifndef MUSHROOM_H
#define MUSHROOM_H



#include "dependencies.h"

 /**
  * @class Mushroom
  * @brief Klasa reprezentuj¹ca obiekt grzyba w grze.
  */
class Mushroom {
private:
	int x;/**< Wspó³rzêdna X po³o¿enia grzyba. */
	int y;/**< Wspó³rzêdna Y po³o¿enia grzyba. */
	ALLEGRO_BITMAP* mushroom;/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego grzyba. */
public:

	/**
	 * @brief Zwraca wspó³rzêdn¹ X po³o¿enia grzyba.
	 * @return Wspó³rzêdna X po³o¿enia grzyba.
	 */
	int getX();
	/**
	 * @brief Zwraca wspó³rzêdn¹ Y po³o¿enia grzyba.
	 * @return Wspó³rzêdna Y po³o¿enia grzyba.
	 */
	int getY();
	/**
	 * @brief Konstruktor klasy Mushroom.
	 *        Inicjalizuje po³o¿enie grzyba.
	 */
	Mushroom();
	/**
	 * @brief Wyœwietla obraz grzyba na ekranie.
	 */
	void displayMushroom();
};

#endif  // MUSHROOM_H