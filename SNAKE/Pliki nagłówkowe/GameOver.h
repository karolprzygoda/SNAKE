/**
 * @file GameOver.h
 * @brief Deklaracja klasy GameOver oraz jej sk³adowych.
 */

#ifndef GAMEOVER_H
#define GAMEOVER_H


#include "dependencies.h"
#include <fstream>


 /**
  * @class GameOver
  * @brief Klasa reprezentuj¹ca ekran koñca gry.
  */
class GameOver {

private:
	static ALLEGRO_SAMPLE* gameoverSound;/**< WskaŸnik do obiektu sampla Allegro 5 reprezentuj¹cego dŸwiêk "burp". */
	static ALLEGRO_BITMAP* gameover;/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego ekran koñca gry. */
	static ALLEGRO_KEYBOARD_STATE keyState;/**< Stan klawiatury Allegro 5 do obs³ugi wejœcia. */
public:
	/**
	 * @brief Wyœwietla ekran koñca gry oraz przechwytuje wejœcie u¿ytkownika.
	 * @param score Aktualny wynik gry.
	 * @param nickName Nick gracza.
	 */
	static void displayGameOver(int score, std::string nickName);
};

#endif  // GAMEOVER_H