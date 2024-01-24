#include "Initialize.h"

void Initialize::initialize() {
	srand(time(NULL));
	al_init();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();
	al_init_image_addon();
	al_reserve_samples(3);
}