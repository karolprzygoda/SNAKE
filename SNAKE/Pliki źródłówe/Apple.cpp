/**
 * @file Apple.cpp
 * @brief Implementacja klasy Apple.
 */
#include "Apple.h"

Apple::Apple() {

	randomize();
	appleBmp = al_load_bitmap("Pliki zasobow/apple.png");
}
void Apple::displayApple() {

	al_draw_bitmap(appleBmp, x, y, 0);
}

void Apple::randomize() {
	x = (1 + rand() % (30)) * 20;
	y = (1 + rand() % (22)) * 20;
}

int Apple::getX() { return x; }
int Apple::getY() { return y; }