/**
 * @file GameMode.h
 * @brief Deklaracja klasy GameMode oraz jej sk³adowych.
 */

#ifndef GAMEMODE_H
#define GAMEMODE_H


#include "dependencies.h"

 /**
  * @class GameMode
  * @brief Klasa reprezentuj¹ca tryb gry.
  */
class GameMode {
private:
	/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego tryb gry. */
	static ALLEGRO_BITMAP* gameModeBtm;
	/**< Stan klawiatury Allegro 5 do obs³ugi wejœcia. */
	static ALLEGRO_KEYBOARD_STATE keyboard;
	/**< Flaga wskazuj¹ca, czy tryb gry jest wci¹¿ aktywny. */
	static bool running;
public:
	/**
	 * @brief Wyœwietla tryb gry i przechwytuje wejœcie u¿ytkownika w celu wyboru trybu.
	 * @param event_queue Kolejka zdarzeñ Allegro 5 do obs³ugi zdarzeñ klawiatury.
	 * @return Wybrany tryb gry (np. wartoœæ reprezentuj¹ca ró¿ne tryby gry).
	 */
	static int displayGameMode(ALLEGRO_EVENT_QUEUE *event_queue);
};

#endif  // GAMEMODE_H