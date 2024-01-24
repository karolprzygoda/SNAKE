/**
* @file EnterNickName.h
* @brief Deklaracja klasy EnterNickName oraz jej sk�adowych.
*/
#ifndef ENTER_NICKNAME_H
#define ENTER_NICKNAME_H

#include "dependencies.h"
#include <string>

/**
 * @class EnterNickName
 * @brief Klasa reprezentuj�ca interfejs u�ytkownika do wprowadzania nazwy gracza przy u�yciu Allegro 5.
 */
class EnterNickName {
private:
	static ALLEGRO_BITMAP* window;/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego okno EnterNickName. */
	static ALLEGRO_FONT* font;  /**< Wska�nik do obiektu czcionki Allegro 5 do renderowania tekstu. */
	static ALLEGRO_KEYBOARD_STATE keyboard; /**< Stan klawiatury Allegro 5 do obs�ugi wej�cia. */
	static bool running;  /**< Flaga wskazuj�ca, czy okno EnterNickName jest wci�� aktywne. */
public:
	static std::string username;  /**< Zmienna przechowuj�ca nazw� gracza. */
	/**
	 * @brief Wy�wietla okno EnterNickName i przechwytuje wej�cie u�ytkownika w celu wprowadzenia nazwy gracza.
	 * @param event_queue Kolejka zdarze� Allegro 5 do obs�ugi zdarze� klawiatury.
	 */
	static void displayEnterNickName(ALLEGRO_EVENT_QUEUE* event_queue);
};

#endif

#pragma once
