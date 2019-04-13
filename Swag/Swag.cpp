// Swag.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <memory>
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"

// this is what we use to draw!!!
#include "allegro5/allegro_primitives.h"

#include "common.h"
#include "State.h"

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *eventQueue;
ALLEGRO_TIMER *timer;

std::shared_ptr<State> state;

int init() {
	if (!al_init() ||
		!al_init_font_addon() ||
		!al_init_ttf_addon() ||
		!al_init_primitives_addon()
		)
	{
		return -1;
	}

	display = al_create_display(1280, 720);
	if (display == nullptr)
		return -1;

	timer = al_create_timer(DT);
	if (timer == nullptr)
		return -1;

	eventQueue = al_create_event_queue();
	if (eventQueue == nullptr)
		return -1;

	al_clear_to_color(al_map_rgb(0, 0, 255));
	al_flip_display();

	return 1;
}

void update() {
	if (state != nullptr)
		state->update();
}

void draw() {
	al_clear_to_color(al_map_rgb(0, 0, 255));

	if (state != nullptr)
		state->draw();

	al_flip_display();
}


int main()
{
	if (!init())
		return -1;

	while (true) {

	}
}
