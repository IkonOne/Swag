#include "pch.h"
#include "Player.h"
#include "allegro5/allegro_primitives.h"

#include "common.h"

Player::Player()
{
	x = 0;
	y = 0;
	color.r = 1.0;
	color.a = 1.0;
}

Player::~Player()
{

}

void Player::update()
{
	velY += gravity*DT;
	x += velX * DT;
	y += velY * DT;
}

void Player::draw()
{
		al_draw_filled_rectangle(x, y, x + width, y + height, color);
}
