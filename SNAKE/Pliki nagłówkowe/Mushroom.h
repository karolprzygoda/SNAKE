/**
 * @file Mushroom.h
 * @brief Deklaracja klasy Mushroom oraz jej sk�adowych.
 */

#ifndef MUSHROOM_H
#define MUSHROOM_H



#include "dependencies.h"

 /**
  * @class Mushroom
  * @brief Klasa reprezentuj�ca obiekt grzyba w grze.
  */
class Mushroom {
private:
	/**< Wsp�rz�dna X po�o�enia grzyba. */
	int x;
	/**< Wsp�rz�dna Y po�o�enia grzyba. */
	int y;
	/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego grzyba. */
	ALLEGRO_BITMAP* mushroom;
public:

	/**
	 * @brief Zwraca wsp�rz�dn� X po�o�enia grzyba.
	 * @return Wsp�rz�dna X po�o�enia grzyba.
	 */
	int getX();
	/**
	 * @brief Zwraca wsp�rz�dn� Y po�o�enia grzyba.
	 * @return Wsp�rz�dna Y po�o�enia grzyba.
	 */
	int getY();
	/**
	 * @brief Konstruktor klasy Mushroom.
	 *        Inicjalizuje po�o�enie grzyba.
	 */
	Mushroom();
	/**
	 * @brief Wy�wietla obraz grzyba na ekranie.
	 */
	void displayMushroom();
};

#endif  // MUSHROOM_H