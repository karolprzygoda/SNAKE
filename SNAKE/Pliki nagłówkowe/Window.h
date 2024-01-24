/**
 * @file Window.h
 * @brief Deklaracja klasy Window oraz jej sk�adowych.
 */

#ifndef WINDOW_H
#define WINDOW_H


#include "dependencies.h"

 /**
  * @class Window
  * @brief Klasa reprezentuj�ca okno gry.
  */
class Window {
private:
	/**< Szeroko�� okna gry. */
	static const int width = 640;
	/**< Wysoko�� okna gry. */
	static const int height = 480;
	/**< Wska�nik do obiektu wy�wietlacza Allegro 5. */
	static ALLEGRO_DISPLAY* disp;
	/**< Wska�nik do obiektu bitmapy Allegro 5 reprezentuj�cego ikon� okna. */
	static ALLEGRO_BITMAP* ikona; 
public:
	/**
	 * @brief Tworzy okno gry o zdefiniowanej szeroko�ci i wysoko�ci.
	 */
	static void createWindow();
};

#endif  // WINDOW_H