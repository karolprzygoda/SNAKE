#include "Snake.h"

int Snake::score = 0;

Snake::Snake() {
	dir = DOWN;
	bodyBmp = al_load_bitmap("Pliki zasobow/body.png");
	eatingSound = al_load_sample("Pliki zasobow/chew.wav");
	headBmp = al_load_bitmap("Pliki zasobow/head.png");
	initializeSnake();
}

void Snake::displaySnake() {

	float centerX = al_get_bitmap_width(headBmp) / 2.0f;
	float centerY = al_get_bitmap_height(headBmp) / 2.0f;

	al_draw_scaled_rotated_bitmap(headBmp, centerX, centerY,
		body.front().x + centerX, body.front().y + centerY,
		1.0, 1.0, angle, 0);

	// Wyœwietl resztê cia³a wê¿a
	for (size_t i = 1; i < body.size(); ++i) {
		al_draw_bitmap(bodyBmp, body[i].x, body[i].y, 0);
	}
}


void Snake::moveSnake(Apple* apple, std::vector<Mushroom*> mushrooms) {

	keyAssignment();

	Point newHead = body.front();
	Point newSegment;

	angle = 0.0f;

	switch (dir) {
	case UP:
		newHead.y = newHead.y - 20; // Przesuniêcie g³owy wê¿a w górê
		newSegment = { newHead.x, newHead.y + 20 }; // Dodanie nowego segmentu za g³ow¹ wê¿a
		angle = ALLEGRO_PI / 2;
		break;
	case DOWN:
		newHead.y = newHead.y + 20; // Przesuniêcie g³owy wê¿a w dó³
		newSegment = { newHead.x, newHead.y - 20 }; // Dodanie nowego segmentu za g³ow¹ wê¿a
		angle = -ALLEGRO_PI / 2;
		break;
	case LEFT:
		newHead.x = newHead.x - 20; // Przesuniêcie g³owy wê¿a w lewo
		newSegment = { newHead.x + 20, newHead.y }; // Dodanie nowego segmentu za g³ow¹ wê¿a
		angle = 0.0f;
		break;
	case RIGHT:
		newHead.x = newHead.x + 20; // Przesuniêcie g³owy wê¿a w prawo
		newSegment = { newHead.x - 20, newHead.y }; // Dodanie nowego segmentu za g³ow¹ wê¿a
		angle = ALLEGRO_PI;
		break;
	}

	body.insert(body.begin(), newHead); // Dodanie nowej g³owy
	checkCollisionWithApple(apple,newSegment, newHead);
	chceckCollisionWithWall(newHead);
	chceckCollisionWithItself(newHead);
	checkCollisionWithMushroom(mushrooms, newHead);
	body.pop_back(); // Usuniêcie ostatniego segmentu wê¿a
}

void Snake::checkCollisionWithApple(Apple* apple, Point newSegment, Point newHead)
{

	if (newHead.x == apple->getX() && newHead.y == apple->getY())
	{
		al_play_sample(eatingSound, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
		body.insert(body.begin() + 1, newSegment);
		apple->randomize();
		score++;
	}
}

void Snake::chceckCollisionWithWall(Point newHead)
{	
	if (newHead.x == 0 || newHead.x == 620 || newHead.y == 0 || newHead.y == 460)
	{
		GameOver::displayGameOver(Snake::score, nickName);
	}
}

void Snake::chceckCollisionWithItself(Point newHead)
{
	for (int i = 1; i < body.size(); i++)
	{
		if (newHead.x == body[i].x && newHead.y == body[i].y)
		{
			GameOver::displayGameOver(Snake::score, nickName);
		}
	}
}

void Snake::checkCollisionWithMushroom(std::vector<Mushroom*> mushrooms, Point newHead)
{
	for (auto mushroom : mushrooms) {
		if (newHead.x == mushroom->getX() && newHead.y == mushroom->getY())
		{
			GameOver::displayGameOver(Snake::score, nickName);
		}
	}
}

void Snake::keyAssignment() {

	al_get_keyboard_state(&keyboard);

	if (al_key_down(&keyboard, ALLEGRO_KEY_RIGHT) && dir != LEFT)//implementacja ruchu w prawo
		dir = RIGHT;

	if (al_key_down(&keyboard, ALLEGRO_KEY_LEFT) && dir != RIGHT)//implementacja ruchu w lewo
		dir = LEFT;

	if (al_key_down(&keyboard, ALLEGRO_KEY_DOWN) && dir != UP)//implementacja ruchu w dol
		dir = DOWN;

	if (al_key_down(&keyboard, ALLEGRO_KEY_UP) && dir != DOWN)//implementacja ruchu w gore
		dir = UP;
}

void Snake::initializeSnake() {
	// Ustawienie pocz¹tkowej pozycji wê¿a
	Point start;
	start.x = (1 + rand() % (27)) * 20;  // Ustawienie startowej wspó³rzêdnej x
	start.y = (1 + rand() % (18)) * 20;  // Ustawienie startowej wspó³rzêdnej y

	// Dodanie pierwszego segmentu do wê¿a
	body.push_back(start);
}

float Snake::lerp(float a, float b, float t) {
	return a + t * (b - a);
}
