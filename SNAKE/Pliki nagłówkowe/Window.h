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
	static const int width = 640;/**< Szerokość okna gry. */
	static const int height = 480;/**< Wysokość okna gry. */
	static ALLEGRO_DISPLAY* disp;/**< Wskaźnik do obiektu wyświetlacza Allegro 5. */
	static ALLEGRO_BITMAP* ikona; /**< Wskaźnik do obiektu bitmapy Allegro 5 reprezentującego ikonę okna. */
public:
	/**
	 * @brief Tworzy okno gry o zdefiniowanej szerokości i wysokości.
	 */
	static void createWindow();
};

#endif  // WINDOW_H