/**
 * @file Window.h
 * @brief Deklaracja klasy Window oraz jej sk³adowych.
 */

#ifndef WINDOW_H
#define WINDOW_H


#include "dependencies.h"

 /**
  * @class Window
  * @brief Klasa reprezentuj¹ca okno gry.
  */
class Window {
private:
	/**< Szerokoœæ okna gry. */
	static const int width = 640;
	/**< Wysokoœæ okna gry. */
	static const int height = 480;
	/**< WskaŸnik do obiektu wyœwietlacza Allegro 5. */
	static ALLEGRO_DISPLAY* disp;
	/**< WskaŸnik do obiektu bitmapy Allegro 5 reprezentuj¹cego ikonê okna. */
	static ALLEGRO_BITMAP* ikona; 
public:
	/**
	 * @brief Tworzy okno gry o zdefiniowanej szerokoœci i wysokoœci.
	 */
	static void createWindow();
};

#endif  // WINDOW_H