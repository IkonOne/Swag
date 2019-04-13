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
#include "TestBlocks.h"
#include "TestBullet.h"
#include "TestPlayer.h"
#include "TestTilemap.h"

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

	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	al_clear_to_color(al_map_rgb(0, 0, 255));
	al_flip_display();

	// state = std::make_shared<TestBlocks>();
	// state = std::make_shared<TestBullet>();
	// state = std::make_shared<TestTilemap>();
	 state = std::make_shared<TestPlayer>();

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

	ALLEGRO_EVENT ev;
	ALLEGRO_TIMEOUT timeout;
	al_init_timeout(&timeout, DT);

	while (true) {
		bool updateAndDraw = false;
		int getEvent = al_wait_for_event_until(eventQueue, &ev, &timeout);
		if (getEvent) {
			switch (ev.type) {
			case ALLEGRO_EVENT_TIMER:
				updateAndDraw = true;
				break;
				
			default:
				break;
			}
		}

		//if (updateAndDraw) {
			update();
			draw();
		//}
	}
}
