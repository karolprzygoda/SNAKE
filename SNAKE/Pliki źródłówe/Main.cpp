/** @file Main.cpp
* @brief G³ówny plik gry.
*/


#include "dependencies.h"
#include "CountDown.h"
#include "Menu.h"
#include "GameMode.h"
#include "Snake.h"
#include "Window.h"
#include "Initialize.h"
#include "EnterNickName.h"


int main()
{

	int wynik = 0;

	Initialize::initialize();
	Window::createWindow();


	ALLEGRO_TIMER* updateTimer = al_create_timer(1.0 / 10); // Czêstotliwoœæ aktualizacji ruchu


	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

	ALLEGRO_SAMPLE* song = al_load_sample("Pliki zasobow/song.ogg");
	ALLEGRO_SAMPLE_INSTANCE* SongInstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(SongInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(SongInstance, al_get_default_mixer());


	ALLEGRO_BITMAP* background = al_load_bitmap("Pliki zasobow/background.png");//wczytanie bitmapy planszy
	ALLEGRO_FONT* font = al_create_builtin_font();

	al_register_event_source(queue, al_get_timer_event_source(updateTimer));

	ALLEGRO_EVENT event;

	Menu::displayMenu(queue);

	int random = GameMode::displayGameMode(queue);
	std::vector<Mushroom*> mushrooms;
	for (int i = 0; i < random; i++) {
		Mushroom* mushroom = new Mushroom();
		mushrooms.push_back(mushroom);
	}

	EnterNickName::displayEnterNickName(queue);

	Apple* apple = new Apple();

	apple->displayApple();

	for (auto mushroom : mushrooms) {
		while (apple->getX() == mushroom->getX() && apple->getY() == mushroom->getY())
			apple->randomize();
	}


	CountDown::displayCountDown();

	Snake* snake = new Snake();

	snake->nickName = EnterNickName::username;

	al_play_sample_instance(SongInstance);

	al_start_timer(updateTimer);

	double lastUpdateTime = al_get_time();

	while (1)
	{
		al_draw_textf(font, al_map_rgb(255, 255, 255), 10, 5, 0, "Your Score: %d", Snake::score);

		al_flip_display();
		al_wait_for_event(queue, &event);

		if (event.type == ALLEGRO_EVENT_TIMER) {

			double currentTime = al_get_time();
			double elapsedTime = currentTime - lastUpdateTime;

			snake->moveSnake(apple, mushrooms);
			lastUpdateTime = currentTime;
			if (al_is_event_queue_empty(queue))
			{

				al_draw_bitmap(background, 0, 0, 0);

				for (auto mushroom : mushrooms) {
					mushroom->displayMushroom();
				}

				apple->displayApple();
				snake->displaySnake();
			}

		}
	}
}