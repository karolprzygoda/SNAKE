/**
 * @file Window.h
 * @brief Deklaracja klasy Window oraz jej składowych.
 */

#ifndef WINDOW_H
#define WINDOW_H


#include "dependencies.h"

 /**
  * @class Window
  * @brief Klasa reprezentująca okno gry.
  */
class Window {
private:
	/**< Szerokość okna gry. */
	static const int width = 640;
	/**< Wysokość okna gry. */
	static const int height = 480;
	/**< Wskaźnik do obiektu wyświetlacza Allegro 5. */
	static ALLEGRO_DISPLAY* disp;
	/**< Wskaźnik do obiektu bitmapy Allegro 5 reprezentującego ikonę okna. */
	static ALLEGRO_BITMAP* ikona; 
public:
	/**
	 * @brief Tworzy okno gry o zdefiniowanej szerokości i wysokości.
	 */
	static void createWindow();
};

#endif  // WINDOW_H