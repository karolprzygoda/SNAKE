/**
 * @file GameOver.h
 * @brief Deklaracja klasy GameOver oraz jej sk�adowych.
 */

#ifndef GAMEOVER_H
#define GAMEOVER_H


#include "dependencies.h"
#include <fstream>


 /**
  * @class GameOver
  * @brief Klasa reprezentuj�ca ekran ko�ca gry.
  */
class GameOver {

private:
	static ALLEGRO_SAMPLE* gameoverSound;/**< Wska�nik do obiektu sampla Allegro 5 reprezentuj�cego d�wi�k "burp". */
	static ALLEGRO_BITMAP* gameover;/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego ekran ko�ca gry. */
	static ALLEGRO_KEYBOARD_STATE keyState;/**< Stan klawiatury Allegro 5 do obs�ugi wej�cia. */
public:
	/**
	 * @brief Wy�wietla ekran ko�ca gry oraz przechwytuje wej�cie u�ytkownika.
	 * @param score Aktualny wynik gry.
	 * @param nickName Nick gracza.
	 */
	static void displayGameOver(int score, std::string nickName);
};

#endif  // GAMEOVER_H