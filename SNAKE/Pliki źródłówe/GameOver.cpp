#include "GameOver.h"

ALLEGRO_SAMPLE* GameOver::gameoverSound = NULL;
ALLEGRO_BITMAP* GameOver::gameover = NULL;
ALLEGRO_KEYBOARD_STATE GameOver::keyState;

void GameOver::displayGameOver(int score, std::string nickName) {

	gameoverSound = al_load_sample("Pliki zasobow/burp.wav");
	gameover = al_load_bitmap("Pliki zasobow/gameover.png");
	ALLEGRO_FONT* font = al_create_builtin_font();

	al_play_sample(gameoverSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	while (!al_key_down(&keyState, ALLEGRO_KEY_ESCAPE)) 
	{
		al_get_keyboard_state(&keyState);
		al_draw_bitmap(gameover, 0, 200, 0);
		al_draw_textf(font, al_map_rgb(255, 255, 255), 250, 250, 0, "your score: %d", score);
		al_draw_textf(font, al_map_rgb(255, 255, 255), 250, 270, 0, "press ESC to leave...");
		al_flip_display();
	}

	std::ofstream outFile("Pliki zasobow/wyniki.txt", std::ios::app);

	if (outFile.is_open()) {
		outFile << score << " " << nickName << std::endl;
		outFile.close();
	}
	al_destroy_bitmap(gameover);
	al_destroy_sample(gameoverSound);
	exit(0);
}