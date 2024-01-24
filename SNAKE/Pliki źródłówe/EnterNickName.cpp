/** @file EnterNickName.cpp
* @brief Implementacja klasy EnterNickName.
*/


#include "EnterNickName.h"

ALLEGRO_BITMAP* EnterNickName::window = nullptr;
ALLEGRO_KEYBOARD_STATE EnterNickName::keyboard;
ALLEGRO_FONT* EnterNickName::font = nullptr;
std::string EnterNickName::username = "";
bool EnterNickName::running = true;

void EnterNickName::displayEnterNickName(ALLEGRO_EVENT_QUEUE* event_queue)
{
    window = al_load_bitmap("Pliki zasobow/enterNickName.png");
    font = al_create_builtin_font();
    running = true;

    while (running)
    {
        ALLEGRO_EVENT ev;
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_wait_for_event(event_queue, &ev);
        al_draw_bitmap(window, 0, 0, 0);

        al_flip_display();

        if (ev.type == ALLEGRO_EVENT_KEY_CHAR)
        {
            if (ev.keyboard.unichar >= 32 && ev.keyboard.unichar < 127)
            {
                username += static_cast<char>(ev.keyboard.unichar);
            }
            else if (ev.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && username.length() > 0)
            {
                username.pop_back();
            }
            else if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
            {
                running = false;
                al_flush_event_queue(event_queue);
            }
        }

        al_draw_text(font, al_map_rgb(255, 255, 255), (640 / 2) , (480 / 2) , ALLEGRO_ALIGN_CENTER, username.c_str());

        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
    }
}

  
