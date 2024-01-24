/**
 * @file Menu.h
 * @brief Deklaracja klasy Menu oraz jej sk�adowych.
 */

#ifndef MENU_H
#define MENU_H

#include "dependencies.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>  

 /**
  * @class Menu
  * @brief Klasa reprezentuj�ca menu g��wne gry.
  */
class Menu {
private:
	static ALLEGRO_BITMAP* menu;/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego menu g��wne. */
	static ALLEGRO_BITMAP* leaderboard;/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego tablic� wynik�w. */
	static ALLEGRO_BITMAP* authors;/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego informacje o autorach. */
	static ALLEGRO_BITMAP* rules;/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego zasady gry. */
	static ALLEGRO_FONT* font;/**< Wska�nik do obiektu czcionki Allegro 5 do renderowania tekstu. */
	static std::ifstream plik;/**< Strumie� wej�ciowy do odczytu danych z pliku. */
	static ALLEGRO_KEYBOARD_STATE keyboard;/**< Stan klawiatury Allegro 5 do obs�ugi wej�cia. */
	static bool running;/**< Flaga wskazuj�ca, czy menu jest wci�� aktywne. */
	std::vector<int> wynik;/**< Wektor przechowuj�cy wyniki. */
public:
	/**
	* @brief Wy�wietla menu g��wne gry i obs�uguje wej�cie u�ytkownika.
	* @param event_queue Kolejka zdarze� Allegro 5 do obs�ugi zdarze� klawiatury.
	*/
	static void displayMenu(ALLEGRO_EVENT_QUEUE *event_queue);
};

#endif

