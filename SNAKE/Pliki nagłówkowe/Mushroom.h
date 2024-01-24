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
	int x;/**< Wsp�rz�dna X po�o�enia grzyba. */
	int y;/**< Wsp�rz�dna Y po�o�enia grzyba. */
	ALLEGRO_BITMAP* mushroom;/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego grzyba. */
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