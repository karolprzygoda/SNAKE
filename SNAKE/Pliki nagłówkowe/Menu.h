/**
 * @file Menu.h
 * @brief Deklaracja klasy Menu oraz jej sk³adowych.
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
  * @brief Klasa reprezentuj¹ca menu g³ówne gry.
  */
class Menu {
private:
	static ALLEGRO_BITMAP* menu;/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego menu g³ówne. */
	static ALLEGRO_BITMAP* leaderboard;/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego tablicê wyników. */
	static ALLEGRO_BITMAP* authors;/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego informacje o autorach. */
	static ALLEGRO_BITMAP* rules;/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego zasady gry. */
	static ALLEGRO_FONT* font;/**< WskaŸnik do obiektu czcionki Allegro 5 do renderowania tekstu. */
	static std::ifstream plik;/**< Strumieñ wejœciowy do odczytu danych z pliku. */
	static ALLEGRO_KEYBOARD_STATE keyboard;/**< Stan klawiatury Allegro 5 do obs³ugi wejœcia. */
	static bool running;/**< Flaga wskazuj¹ca, czy menu jest wci¹¿ aktywne. */
	std::vector<int> wynik;/**< Wektor przechowuj¹cy wyniki. */
public:
	/**
	* @brief Wyœwietla menu g³ówne gry i obs³uguje wejœcie u¿ytkownika.
	* @param event_queue Kolejka zdarzeñ Allegro 5 do obs³ugi zdarzeñ klawiatury.
	*/
	static void displayMenu(ALLEGRO_EVENT_QUEUE *event_queue);
};

#endif

