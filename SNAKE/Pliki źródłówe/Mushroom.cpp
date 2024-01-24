/** @file Mushroom.cpp
* @brief Implementacja klasy Mushroom.
*/


#include "Mushroom.h"

Mushroom::Mushroom()
{
	mushroom = al_load_bitmap("Pliki zasobow/mushroom.png");
	x = (1 + rand() % (30)) * 20;
	y = (1 + rand() % (22)) * 20;
}

void Mushroom::displayMushroom()
{
	
	al_draw_bitmap(mushroom, x, y, 0);
}

int Mushroom::getX()
{
	return x;
}

int Mushroom::getY()
{
	return y;
}