

/** @file CountDown.cpp
* @brief Implementacja klasy CountDown.
*/

#include "CountDown.h"
ALLEGRO_BITMAP* CountDown::three = nullptr;
ALLEGRO_BITMAP* CountDown::two = nullptr;
ALLEGRO_BITMAP* CountDown::one = nullptr;
bool CountDown::running = true;

void CountDown::displayCountDown()
{
     three = al_load_bitmap("Pliki zasobow/3.png");//wczytanie bitapy 3
     two = al_load_bitmap("Pliki zasobow/2.png");//wczytanie bitmapy 2
     one = al_load_bitmap("Pliki zasobow/1.png");//wczytanie bitmapy 1

    while(running)//petla wywolujaca bitmapy informaujace o odliczaniu do rozpoczecia rozgrywki
    {
        al_clear_to_color(al_map_rgb(0, 0, 0));//wyczyszczenie ekranu
        al_draw_bitmap(three,0,0,0);//wyswietlenie bitmapy 3
        al_flip_display();//odswiezenie ekranu
        al_rest(1);//zatrzymanie dzialania programu na sekunde
        al_draw_bitmap(two,0,0,0);//wyswietlenie bitmapy 2
        al_flip_display();//odswiezenie ekranu
        al_rest(1);//zatrzymanie dzialania programu na sekunde
        al_draw_bitmap(one,0,0,0);//wyswietlenie bitmapy 1
        al_flip_display();//odswiezenie ekranu
        al_rest(1);//zatrzymanie dzialania programu na sekunde
        running = false;//przerwanie petli
    }
    //funkcje sluszace do usuniecia wczesniej zadeklarowanych obiektow takich jak bitmapy dzwieki czy kolejki z pamieci
    al_destroy_bitmap(three);
    al_destroy_bitmap(two);
    al_destroy_bitmap(one);

}
