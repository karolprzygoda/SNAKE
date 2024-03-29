/**
* @file CountDown.h
* @brief Deklaracja klasy CountDown oraz jej składowych.
*/


#ifndef COUNTFOWN_H
#define COUNTDOWN_H

#include "dependencies.h"

/**
* @class CountDown
* @brief Klasa reprezentująca odliczanie przed rozpoczęciem rozgrywki.
*/
class CountDown {
private:
	/**< Wskaźnik do obiektu bitmapy Allegro 5 reprezentującego obrazek cyfry 3. */
	static ALLEGRO_BITMAP* three; 
	/**< Wskaźnik do obiektu bitmapy Allegro 5 reprezentującego obrazek cyfry 2. */
	static ALLEGRO_BITMAP* two; 
	/**< Wskaźnik do obiektu bitmapy Allegro 5 reprezentującego obrazek cyfry 1. */
	static ALLEGRO_BITMAP* one; 
	/**< Zmienna logiczna informująca czy odliczanie jest w trakcie. */
	static bool running; 
public:
	/** @brief wyswietla cyfry odliczajace przed rozpoczaeciem rozgrywki
	*
	* Glownym i jedynym zadaniem funkcji jest wysiwetlenie 3 bitmap w odstepie 1 sekundy przed rozpoczeciem rozgrywki. Odliczanie zawarte w funkcji ma poinformowac uzytkownika ze rozgrywka zaraz sie rozpocznie.
	*/
	static void displayCountDown();
};



#endif
