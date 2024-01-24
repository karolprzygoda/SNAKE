/**
* @file CountDown.h
* @brief Deklaracja klasy CountDown oraz jej sk�adowych.
*/


#ifndef COUNTFOWN_H
#define COUNTDOWN_H

#include "dependencies.h"

/**
* @class CountDown
* @brief Klasa reprezentuj�ca odliczanie przed rozpocz�ciem rozgrywki.
*/
class CountDown {
private:
	/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego obrazek cyfry 3. */
	static ALLEGRO_BITMAP* three; 
	/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego obrazek cyfry 2. */
	static ALLEGRO_BITMAP* two; 
	/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego obrazek cyfry 1. */
	static ALLEGRO_BITMAP* one; 
	/**< Zmienna logiczna informuj�ca czy odliczanie jest w trakcie. */
	static bool running; 
public:
	/** @brief wyswietla cyfry odliczajace przed rozpoczaeciem rozgrywki
	*
	* Glownym i jedynym zadaniem funkcji jest wysiwetlenie 3 bitmap w odstepie 1 sekundy przed rozpoczeciem rozgrywki. Odliczanie zawarte w funkcji ma poinformowac uzytkownika ze rozgrywka zaraz sie rozpocznie.
	*/
	static void displayCountDown();
};



#endif
