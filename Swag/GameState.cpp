#include "pch.h"

#include <string>
#include "allegro5/allegro.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "common.h"
#include "GameState.h"
#include "TileMap.h"
#include "Player.h"

#define PLR_SPEED	50
#define PLR_JUMP	100
#define PLR_BOUNCE	0.2
#define PLR_GRAV	10
#define PLR_HEAD	5

ALLEGRO_FONT * font;

struct keyboard_s {
	bool up;
	bool left;
	bool right;
};

Player p1;
struct keyboard_s p1kbd = { false, false, false };
bool p1Grounded = false;

Player p2;
struct keyboard_s p2kbd = { false, false, false };
bool p2Grounded = false;

bool gameOver = false;
std::string gameOverMsg;

TileMap tileMap;

GameState::GameState()
{
	// init players
	p1.x = 10;
	p1.y = 200;
	p1.gravity = PLR_GRAV;

	p2.x = 600;
	p2.y = 200;
	p2.gravity = PLR_GRAV;

	p1.width = p2.width = 64;
	p1.height = p2.height = 64;

	// load assets
	font = al_load_ttf_font("Pixellari.ttf", 64, 0);
}


GameState::~GameState()
{
}

void GameState::update()
{
	// handle input
	if (p1kbd.left) {
		p1.velX = -PLR_SPEED;
	}
	else if (p1kbd.right) {
		p1.velX = PLR_SPEED;
	}
	else {
		p1.velX = 0;
	}

	if (p1Grounded && p1kbd.up) {
		p1.velY = -PLR_JUMP;
		p1Grounded = false;
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

	if (p2Grounded && p2kbd.up) {
		p2.velY = -PLR_JUMP;
		p2Grounded = false;
	}

	p1.update();
	p2.update();

	// handle collision
	// collide players
	if ( checkOvLp(
			p1.x, p1.x + p1.width, p1.y, p1.y + p1.height,
			p2.x, p2.x + p2.width, p2.y, p2.y + p2.height)
		)
	{
		p1.x -= p1.velX * PLR_BOUNCE;
		p1.y -= p1.velY * PLR_BOUNCE;
		p2.x -= p2.velX * PLR_BOUNCE;
		p2.y -= p2.velY * PLR_BOUNCE;

		// p1 head stomp swag
		if (p1.y - p2.y <= PLR_HEAD) {
			gameOver = true;
			gameOverMsg = "p1 dabbed on p2";
		}

		// p2 head stomp dab	<o/
		if (p2.y - p1.y <= PLR_HEAD) {
			gameOver = true;
			gameOverMsg = "p2 dabbed on p1";
		}
	}

	// collide ground
	if (p1.y + p1.height >= 640) {
		p1.velY = 0;
		p1.y = 640 - p1.height;
		p1Grounded = true;
	}

	if (p2.y + p2.height >= 640) {
		p2.velY = 0;
		p2.y = 640 - p2.height;
		p2Grounded = true;
	}
}

void GameState::draw()
{
	p1.draw();
	p2.draw();
	tileMap.draw();

	if(gameOver)
		al_draw_text(font, al_map_rgb(0, 255, 0), 0, 0, 0, gameOverMsg.c_str());
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
