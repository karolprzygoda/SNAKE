/** @file Menu.cpp
* @brief Implementacja klasy Menu.
*/


#include "Menu.h"
#include "CountDown.h"

ALLEGRO_BITMAP* Menu::rules = nullptr;
ALLEGRO_BITMAP* Menu::menu = nullptr;
ALLEGRO_BITMAP* Menu::leaderboard = nullptr;
ALLEGRO_BITMAP* Menu::authors = nullptr;
ALLEGRO_FONT* Menu::font = nullptr;
ALLEGRO_KEYBOARD_STATE Menu::keyboard;
bool Menu::running = true;

void Menu::displayMenu(ALLEGRO_EVENT_QUEUE* event_queue)
{
     rules = al_load_bitmap("Pliki zasobow/rules.png");
     menu = al_load_bitmap("Pliki zasobow/menu.png");
     leaderboard = al_load_bitmap("Pliki zasobow/leaderboard.png");
     authors = al_load_bitmap("Pliki zasobow/authors.png");
     font = al_create_builtin_font();

     std::vector<std::pair<int, std::string>> wyniki;

     std::ifstream plik("Pliki zasobow/wyniki.txt");

      if (plik.is_open()) 
      {
          int liczba;
          std::string nick;
          while ((plik >> liczba >> nick))
          {
              wyniki.push_back(std::make_pair(liczba, nick));
          }
          plik.close();
      }
      else 
      {
        std::cerr << "Nie mo¿na otworzyæ pliku." << std::endl;
        plik.close();
        exit(1);
      }

      sort(wyniki.begin(), wyniki.end(), std::greater<std::pair<int, std::string>>());


    while(running)
    {
        al_get_keyboard_state(&keyboard);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(menu,0,0,0);
        al_flip_display();

        if(al_key_down(&keyboard,ALLEGRO_KEY_1))
        {
            al_flush_event_queue(event_queue);
            al_rest(0.2);
            break;
        }

        if(al_key_down(&keyboard,ALLEGRO_KEY_2))
        {
            while(!al_key_down(&keyboard,ALLEGRO_KEY_ESCAPE))
            {
                al_get_keyboard_state(&keyboard);
                al_draw_bitmap(leaderboard,0,0,0);
      
                int wysokosc = 201;// zmienna ktora okresla polozenie w pionie dla najelpeszych wynikow

                for(int i=0;i<6;++i)//wyswietlenie najlepszych 5 wynikow
                {
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 280, wysokosc, 0, "%d", wyniki[i].first);
                    al_draw_textf(font, al_map_rgb(255, 255, 255), 480, wysokosc, 0, "%s", wyniki[i].second.c_str());
                    wysokosc = wysokosc + 50;//zwiekszenie wysokosci lepszego wyniku o 50 pixeli
                }
                al_flip_display();
            }
            al_flush_event_queue(event_queue);
        }

        if(al_key_down(&keyboard,ALLEGRO_KEY_3))
        {
            while(!al_key_down(&keyboard,ALLEGRO_KEY_ESCAPE))
            {
                al_get_keyboard_state(&keyboard);
                al_draw_bitmap(authors,0,0,0);
                al_flip_display();
            }
            al_flush_event_queue(event_queue);
        }

        if(al_key_down(&keyboard,ALLEGRO_KEY_4))
        {
            while(!al_key_down(&keyboard,ALLEGRO_KEY_ESCAPE))
            {
                al_get_keyboard_state(&keyboard);
                al_draw_bitmap(rules,0,0,0);
                al_flip_display();
            }
            al_flush_event_queue(event_queue);
        }

        if(al_key_down(&keyboard,ALLEGRO_KEY_5))
        {
            al_flush_event_queue(event_queue);
            al_destroy_bitmap(rules);
            al_destroy_bitmap(leaderboard);
            al_destroy_bitmap(authors);
            al_destroy_bitmap(menu);
            exit(0);
        }
    }

    al_destroy_bitmap(rules);
    al_destroy_bitmap(leaderboard);
    al_destroy_bitmap(authors);
    al_destroy_bitmap(menu);
}
