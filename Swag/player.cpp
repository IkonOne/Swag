#include "pch.h"
#include "Player.h"
#include "allegro5/allegro_primitives.h"

#include "common.h"

player::player()
{
	x = 0;
	y = 0;
}

player::~player()
{

}

void player::update()
{
	gravity += gravity*DT;
	x += velX;
	y += velY + gravity;
}

void player::draw()
{
		al_draw_filled_rectangle(x, y, x + 64, y + 64, al_map_rgb(255, 0, 0));
}