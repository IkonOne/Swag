#include "pch.h"

#include "allegro5/allegro.h"
#include "GameState.h"
#include "TileMap.h"

struct keyboard_s {
	bool up;
	bool left;
	bool right;
};

struct player_s {
	keyboard_s kbd;
};

struct player_s p1 = {
	{ false, false, false }
};

struct player_s p2 = {
	{ false, false, false }
};

TileMap tileMap;

GameState::GameState()
{
}


GameState::~GameState()
{
}

void GameState::update()
{
}

void GameState::draw()
{
	tileMap.draw();
}

void GameState::handleEvents(ALLEGRO_EVENT * event)
{
	switch (event->type) {
	case ALLEGRO_EVENT_KEY_DOWN:
		switch (event->keyboard.keycode) {
		case ALLEGRO_KEY_A:		p1.kbd.left = true; break;
		case ALLEGRO_KEY_D:		p1.kbd.right = true; break;
		case ALLEGRO_KEY_W:		p1.kbd.up = true; break;

		case ALLEGRO_KEY_UP:	p2.kbd.up = true; break;
		case ALLEGRO_KEY_LEFT:	p2.kbd.left = true; break;
		case ALLEGRO_KEY_RIGHT:	p2.kbd.right = true; break;
		}

		break;

	case ALLEGRO_EVENT_KEY_UP:
		switch (event->keyboard.keycode) {
		case ALLEGRO_KEY_A:		p1.kbd.left = false; break;
		case ALLEGRO_KEY_D:		p1.kbd.right = false; break;
		case ALLEGRO_KEY_W:		p1.kbd.up = false; break;

		case ALLEGRO_KEY_UP:	p2.kbd.up = false; break;
		case ALLEGRO_KEY_LEFT:	p2.kbd.left = false; break;
		case ALLEGRO_KEY_RIGHT:	p2.kbd.right = false; break;
		}

		break;

	}
}
