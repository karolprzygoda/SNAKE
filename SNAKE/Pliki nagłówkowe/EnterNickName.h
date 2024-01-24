/**
* @file EnterNickName.h
* @brief Deklaracja klasy EnterNickName oraz jej sk³adowych.
*/
#ifndef ENTER_NICKNAME_H
#define ENTER_NICKNAME_H

#include "dependencies.h"
#include <string>

/**
 * @class EnterNickName
 * @brief Klasa reprezentuj¹ca interfejs u¿ytkownika do wprowadzania nazwy gracza przy u¿yciu Allegro 5.
 */
class EnterNickName {
private:
	/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego okno EnterNickName. */
	static ALLEGRO_BITMAP* window;
	/**< WskaŸnik do obiektu czcionki Allegro 5 do renderowania tekstu. */
	static ALLEGRO_FONT* font;
	/**< Stan klawiatury Allegro 5 do obs³ugi wejœcia. */
	static ALLEGRO_KEYBOARD_STATE keyboard;
	/**< Flaga wskazuj¹ca, czy okno EnterNickName jest wci¹¿ aktywne. */
	static bool running; 
public:
	/**< Zmienna przechowuj¹ca nazwê gracza. */
	static std::string username;  
	/**
	 * @brief Wyœwietla okno EnterNickName i przechwytuje wejœcie u¿ytkownika w celu wprowadzenia nazwy gracza.
	 * @param event_queue Kolejka zdarzeñ Allegro 5 do obs³ugi zdarzeñ klawiatury.
	 */
	static void displayEnterNickName(ALLEGRO_EVENT_QUEUE* event_queue);
};

#endif

#pragma once
