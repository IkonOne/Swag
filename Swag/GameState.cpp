#include "pch.h"

#include "allegro5/allegro.h"
#include "GameState.h"
#include "TileMap.h"
#include "Player.h"

#define PLR_SPEED 50

struct keyboard_s {
	bool up;
	bool left;
	bool right;
};


Player p1;
struct keyboard_s p1kbd = { false, false, false };

Player p2;
struct keyboard_s p2kbd = { false, false, false };

TileMap tileMap;

GameState::GameState()
{
	p1.x = 10;
	p1.y = 200;

	p2.x = 600;
	p2.y = 200;

	p1.width = p2.width = 64;
	p1.height = p2.height = 64;

}


GameState::~GameState()
{
}

void GameState::update()
{
	if (p1kbd.left) {
		p1.velX = -PLR_SPEED;
	}
	else if (p1kbd.right) {
		p1.velX = PLR_SPEED;
	}
	else {
		p1.velX = 0;
	}

	if (p2kbd.left) {
		p2.velX = -PLR_SPEED;
	}
	else if (p2kbd.right) {
		p2.velX = PLR_SPEED;
	}
	else {
		p2.velX = 0;
	}

	p1.update();
	p2.update();
}

void GameState::draw()
{
	p1.draw();
	p2.draw();
	tileMap.draw();
}

void GameState::handleEvents(ALLEGRO_EVENT * event)
{
	switch (event->type) {
	case ALLEGRO_EVENT_KEY_DOWN:
		switch (event->keyboard.keycode) {
		case ALLEGRO_KEY_A:		p1kbd.left = true; break;
		case ALLEGRO_KEY_D:		p1kbd.right = true; break;
		case ALLEGRO_KEY_W:		p1kbd.up = true; break;

		case ALLEGRO_KEY_UP:	p2kbd.up = true; break;
		case ALLEGRO_KEY_LEFT:	p2kbd.left = true; break;
		case ALLEGRO_KEY_RIGHT:	p2kbd.right = true; break;
		}

		break;

	case ALLEGRO_EVENT_KEY_UP:
		switch (event->keyboard.keycode) {
		case ALLEGRO_KEY_A:		p1kbd.left = false; break;
		case ALLEGRO_KEY_D:		p1kbd.right = false; break;
		case ALLEGRO_KEY_W:		p1kbd.up = false; break;

		case ALLEGRO_KEY_UP:	p2kbd.up = false; break;
		case ALLEGRO_KEY_LEFT:	p2kbd.left = false; break;
		case ALLEGRO_KEY_RIGHT:	p2kbd.right = false; break;
		}

		break;

	}
}
