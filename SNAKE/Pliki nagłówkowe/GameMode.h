/**
 * @file GameMode.h
 * @brief Deklaracja klasy GameMode oraz jej sk�adowych.
 */

#ifndef GAMEMODE_H
#define GAMEMODE_H


#include "dependencies.h"

 /**
  * @class GameMode
  * @brief Klasa reprezentuj�ca tryb gry.
  */
class GameMode {
private:
	/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego tryb gry. */
	static ALLEGRO_BITMAP* gameModeBtm;
	/**< Stan klawiatury Allegro 5 do obs�ugi wej�cia. */
	static ALLEGRO_KEYBOARD_STATE keyboard;
	/**< Flaga wskazuj�ca, czy tryb gry jest wci�� aktywny. */
	static bool running;
public:
	/**
	 * @brief Wy�wietla tryb gry i przechwytuje wej�cie u�ytkownika w celu wyboru trybu.
	 * @param event_queue Kolejka zdarze� Allegro 5 do obs�ugi zdarze� klawiatury.
	 * @return Wybrany tryb gry (np. warto�� reprezentuj�ca r�ne tryby gry).
	 */
	static int displayGameMode(ALLEGRO_EVENT_QUEUE *event_queue);
};

#endif  // GAMEMODE_H