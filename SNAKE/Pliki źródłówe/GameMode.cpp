/** @file GameMode.cpp
* @brief Implementacja klasy GameMode.
*/


#include "GameMode.h"

ALLEGRO_BITMAP* GameMode::gameModeBtm = nullptr;
ALLEGRO_KEYBOARD_STATE GameMode::keyboard;
bool GameMode::running = true;

int GameMode::displayGameMode(ALLEGRO_EVENT_QUEUE* event_queue)
{
	gameModeBtm = al_load_bitmap("Pliki zasobow/gameMode.png");
    running = true;

	while (running)
	{
		al_draw_bitmap(gameModeBtm, 0, 0, 0);
		al_flip_display();
		al_get_keyboard_state(&keyboard);
        if (al_key_down(&keyboard, ALLEGRO_KEY_1))
        {
            return 5 + rand() % 5;//przypisz zmiennej random liczbe calkowita z przedzialu [5,9]
            al_flush_event_queue(event_queue);
            running = false;
        }

        if (al_key_down(&keyboard, ALLEGRO_KEY_2))
        {
            return 10 + rand() % 5;//przypisz zmiennej random liczbe calkowita z przedzialu [10,14]
            al_flush_event_queue(event_queue);
            running = false;
        }

        if (al_key_down(&keyboard, ALLEGRO_KEY_3))
        {
            return  20 + rand() % 20;//przypisz zmiennej random liczbe calkowita z przedzialu [20,39]
            al_flush_event_queue(event_queue);
            running = false;
        }
	}
}
