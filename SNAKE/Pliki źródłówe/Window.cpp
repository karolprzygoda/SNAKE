#include "Window.h"

ALLEGRO_DISPLAY* Window::disp = NULL;
ALLEGRO_BITMAP* Window::ikona = NULL;

void Window::createWindow() {

	ALLEGRO_BITMAP* ikona = al_load_bitmap("Pliki zasobow/ikona.png");

	HWND window;//stworzenie zmiennej window "uchwytu okna"
	AllocConsole();//procedura iniciujaca standardowe wejscia i wyjscia konsoli
	window = FindWindowA("ConsoleWindowClass", NULL);//przypisanie konsoli do zmiennej window
	ShowWindow(window, 0);//funkcja ukrywajaca konsole poprzez drugi argument

	disp = al_create_display(width, height);
	al_set_window_position(disp, 520, 200);
	al_set_window_title(disp, "snake_3ID14A");
	al_set_display_icon(disp, ikona);
}